# skeleton_extract.py — Extract DETERMINISTIC per-function facts from the IDB.
# Headless: idat.exe -A -S"skeleton_extract.py" "F1 Challenge Online.exe.i64"
#
# Authoritative (IDA's own analysis, NOT text regex):
#   globals   : data xrefs FROM the function  -> {addr, name, rw}
#   callees   : code xrefs FROM the function to func starts -> {addr, name}
# Best-effort (Hex-Rays ctree, ties offsets to the resolved `this`/arg1 var):
#   fields    : struct accesses -> {base, off_hex, rw, init_literal, init_float}
#   guards    : branch comparisons on this-relative fields -> {base,off,op,value}
#
# Output: skeleton_facts.json  { "<addr8>": {name, globals, callees, fields, guards} }
# Frequency / persistence / callers are merged later from callgraph.json.
#
# Section-12 refinements over the original:
#   #1 Deeper indirection: generalized alias/dataflow. Tracks lvars assigned ANY
#      this-derived pointer (this+N, &this->f, *this, **this loads, pointer chains),
#      not just the single `*this` alias. Deeper accesses are reported relative to a
#      symbolic root, e.g. base "*(this+0x40)" for **this.
#   #2 cot_idx element size: read the pointed/array element size instead of always 4.
#   #3 R/W over-marking: LHS excluded from the read pass; compound assigns (+=, |=…)
#      correctly marked RW.
#   #4 Guard extraction (NEW): deterministic pull of ==,!=,<,>,<=,>= comparisons
#      between a this-relative field and an integer literal.
import idaapi, idautils, idc, ida_hexrays, ida_bytes, ida_funcs
import json, struct, os

# OUT / target set overridable from the environment so the whole DB can be run
# without editing this file:  SKEL_ALL=1  -> every function;  SKEL_OUT=path.
OUT = os.environ.get("SKEL_OUT",
                     r"%USERPROFILE%/Desktop/f1c_ida_decompiled/skeleton_facts.json")

# Test batch (the 10). Set TARGETS = None (or env SKEL_ALL=1) to run the whole DB.
TARGETS = [0x00429470, 0x00424790, 0x00424e70, 0x004a5d10, 0x004bc0e0,
           0x004d82d0, 0x004dbac3, 0x004a0fd0, 0x00464600, 0x004a6db0]
if os.environ.get("SKEL_ALL"):
    TARGETS = None
elif os.environ.get("SKEL_TARGETS"):        # comma-separated hex addresses
    TARGETS = [int(x, 16) for x in os.environ["SKEL_TARGETS"].split(",") if x.strip()]

ida_hexrays.init_hexrays_plugin()

# --- ctree op sets (resolved via getattr so a missing constant never crashes) --
_ASG_NAMES = ['cot_asg', 'cot_asgbor', 'cot_asgxor', 'cot_asgband', 'cot_asgadd',
              'cot_asgsub', 'cot_asgmul', 'cot_asgsshr', 'cot_asgushr', 'cot_asgshl',
              'cot_asgsdiv', 'cot_asgudiv', 'cot_asgsmod', 'cot_asgumod']
ASG_OPS = {getattr(ida_hexrays, n) for n in _ASG_NAMES if hasattr(ida_hexrays, n)}
COMPOUND_ASG = ASG_OPS - {ida_hexrays.cot_asg}

# comparison op -> symbol (signed/unsigned collapse to the same symbol)
_CMP_NAMES = {'cot_eq': '==', 'cot_ne': '!=',
              'cot_slt': '<', 'cot_ult': '<', 'cot_sle': '<=', 'cot_ule': '<=',
              'cot_sgt': '>', 'cot_ugt': '>', 'cot_sge': '>=', 'cot_uge': '>='}
CMP_OPS = {getattr(ida_hexrays, n): s for n, s in _CMP_NAMES.items()
           if hasattr(ida_hexrays, n)}
# when the literal is on the LEFT (`3 < x`), flip to normalize to (field op value)
FLIP = {'<': '>', '>': '<', '<=': '>=', '>=': '<=', '==': '==', '!=': '!='}

# symbolic root for arg1 (`this`); loads are ('load', inner_root, byte_off)
THIS = ('this',)


def i2f(v):
    return struct.unpack("<f", struct.pack("<I", v & 0xFFFFFFFF))[0]


def root_str(root):
    """Human/downstream label for a symbolic base root.
    THIS -> 'this'; one load of *this -> 'obj' (legacy label); deeper -> *(..)."""
    if root == THIS:
        return 'this'
    _, inner, off = root
    if inner == THIS and off == 0:
        return 'obj'
    return "*(%s+0x%X)" % (root_str(inner), off)


def func_globals_callees(ea):
    """Authoritative: walk instructions, use IDA's xref engine."""
    f = ida_funcs.get_func(ea)
    globals_, callees = {}, {}
    if not f:
        return [], []
    for head in idautils.Heads(f.start_ea, f.end_ea):
        # DATA xrefs -> globals, with R/W from xref type
        for xr in idautils.XrefsFrom(head, 0):
            t = xr.type
            if t in (idaapi.dr_R, idaapi.dr_W, idaapi.dr_O):
                nm = idc.get_name(xr.to) or ("byte_%X" % xr.to)
                if not nm:
                    continue
                rw = globals_.get(xr.to, {}).get('rw', '')
                cur = 'W' if t == idaapi.dr_W else 'R'
                rw = ''.join(sorted(set(rw) | set(cur)))
                globals_[xr.to] = {'addr': "%08x" % xr.to, 'name': nm, 'rw': rw}
            elif t in (idaapi.fl_CN, idaapi.fl_CF):
                tgt = xr.to
                if ida_funcs.get_func(tgt) and ida_funcs.get_func(tgt).start_ea == tgt:
                    callees[tgt] = {'addr': "%08x" % tgt, 'name': idc.get_name(tgt) or ("sub_%X" % tgt)}
    # keep only real globals (in a data segment / named), drop stack & locals
    gl = [g for g in globals_.values()]
    return sorted(gl, key=lambda x: x['addr']), sorted(callees.values(), key=lambda x: x['addr'])


def _scale(e):
    """Byte scale for pointer arithmetic on base expr `e`.
    C pointer/array `+N` and `[N]` step by the pointed element size:
      _DWORD* -> 4, _BYTE*/char* -> 1, etc.  A bare int used as an address
    (IDA's common `int this` idiom, e.g. `*this + 2100`) is NOT a pointer, so
    its `+N` is already in bytes -> scale 1.  Defaulting to 1 (not 4) avoids the
    4x over-scaling of byte offsets when the type is unknown."""
    try:
        t = e.type
        if t.is_ptr():
            sz = t.get_pointed_object().get_size()
        elif t.is_array():
            sz = t.get_array_element().get_size()
        else:
            return 1
        if sz and sz != idaapi.BADSIZE:
            return sz
    except Exception:
        pass
    return 1


class FieldVisitor(ida_hexrays.ctree_visitor_t):
    """Collect struct accesses & guards relative to arg1 (`this`) and any
    this-derived pointer aliases (deeper indirection)."""
    def __init__(self, cfunc):
        ida_hexrays.ctree_visitor_t.__init__(self, ida_hexrays.CV_FAST)
        self.cfunc = cfunc
        # index of the first argument lvar == `this` for thiscall / arg1
        self.this_idx = None
        for i, lv in enumerate(cfunc.lvars):
            if lv.is_arg_var:
                self.this_idx = i
                break
        self.fields = {}          # (root, off) -> {'rw':set, 'init':literal|None}
        self.guards = []          # list of (root, off, op, value)
        self._guard_seen = set()
        self._lhs_ids = set()
        self.alias = {}           # lvar idx -> (root, off): pointer-valued alias

    # -- expression classification -------------------------------------------
    def _strip(self, e):
        while e is not None and e.op == ida_hexrays.cot_cast:
            e = e.x
        return e

    def _base(self, e):
        """Resolve e's POINTER VALUE to (root, off) with address = root + off.
        None if not rooted at `this` or a this-derived alias."""
        if e is None:
            return None
        op = e.op
        if op == ida_hexrays.cot_var:
            if self.this_idx is not None and e.v.idx == self.this_idx:
                return (THIS, 0)
            return self.alias.get(e.v.idx)          # None if not a tracked alias
        if op == ida_hexrays.cot_cast:
            return self._base(e.x)
        if op == ida_hexrays.cot_ref:               # &lvalue -> address of it
            return self._deref(e.x)
        if op == ida_hexrays.cot_ptr:               # *p used as a base -> deeper load
            b = self._base(e.x)
            return None if b is None else (('load', b[0], b[1]), 0)
        if op == ida_hexrays.cot_add and e.y.op == ida_hexrays.cot_num:
            b = self._base(e.x)
            return None if b is None else (b[0], b[1] + e.y.numval() * _scale(e.x))
        if op == ida_hexrays.cot_add and e.x.op == ida_hexrays.cot_num:   # num + ptr
            b = self._base(e.y)
            return None if b is None else (b[0], b[1] + e.x.numval() * _scale(e.y))
        if op == ida_hexrays.cot_idx and e.y.op == ida_hexrays.cot_num:
            b = self._base(e.x)
            return None if b is None else (b[0], b[1] + e.y.numval() * _scale(e.x))
        return None

    def _deref(self, e):
        """(root, off) of a memory-access LVALUE (the field location), else None."""
        if e is None:
            return None
        if e.op == ida_hexrays.cot_ptr:                 # *(T*)(base + N)
            return self._base(e.x)
        if e.op == ida_hexrays.cot_idx:                 # base[N]
            return self._base(e)
        if e.op == ida_hexrays.cot_memptr:              # base->field
            b = self._base(e.x)
            return None if b is None else (b[0], b[1] + e.m)
        return None

    def _field_of(self, e):
        """Field key of e after stripping casts (used for guard operands)."""
        return self._deref(self._strip(e))

    # -- recording -----------------------------------------------------------
    def _mark(self, key, rw, init=None):
        d = self.fields.setdefault(key, {'rw': set(), 'init': None})
        d['rw'].add(rw)
        if init is not None:
            d['init'] = init

    def _record_guard(self, e):
        op = CMP_OPS[e.op]
        x, y = self._strip(e.x), self._strip(e.y)
        fld = num = symbol = None
        if y.op == ida_hexrays.cot_num:
            fld, num, symbol = self._field_of(x), y.numval(), op
        elif x.op == ida_hexrays.cot_num:
            fld, num, symbol = self._field_of(y), x.numval(), FLIP[op]
        if fld is None or num is None:
            return
        sig = (fld[0], fld[1], symbol, num)
        if sig not in self._guard_seen:
            self._guard_seen.add(sig)
            self.guards.append(sig)

    def visit_expr(self, e):
        op = e.op
        # comparisons -> deterministic guards
        if op in CMP_OPS:
            self._record_guard(e)
        # assignments (plain + compound)
        if op in ASG_OPS:
            # alias: vN = <this-derived pointer expr>.  No lvar-type guard — IDA
            # frequently types object pointers as int (e.g. `v1 = *this`). A false
            # alias is harmless: a phantom field only materializes if vN is later
            # actually dereferenced, which real integer values are not.
            if op == ida_hexrays.cot_asg and e.x.op == ida_hexrays.cot_var:
                b = self._base(e.y)
                if b is not None:
                    self.alias[e.x.v.idx] = b
            k = self._deref(e.x)
            if k is not None:
                self._lhs_ids.add(id(e.x))
                self._mark(k, 'W')
                if op in COMPOUND_ASG:                 # read-modify-write
                    self._mark(k, 'R')
                elif e.y.op == ida_hexrays.cot_num:    # plain asg with literal RHS
                    self._mark(k, 'W', e.y.numval())
        # generic reads (skip anything already counted as an LHS write)
        if op in (ida_hexrays.cot_ptr, ida_hexrays.cot_idx, ida_hexrays.cot_memptr):
            if id(e) not in self._lhs_ids:
                k = self._deref(e)
                if k is not None:
                    self._mark(k, 'R')
        return 0


def func_fields(ea):
    try:
        cfunc = ida_hexrays.decompile(ea)
        if not cfunc:
            return [], []
        v = FieldVisitor(cfunc)
        v.apply_to(cfunc.body, None)
        out = []
        for (root, off), d in sorted(v.fields.items(),
                                     key=lambda kv: (root_str(kv[0][0]), kv[0][1])):
            row = {'base': root_str(root), 'off_hex': "0x%X" % off,
                   'rw': ''.join(sorted(d['rw']))}
            if d['init'] is not None:
                row['init_literal'] = d['init']
                fv = i2f(d['init'])
                if 1e-6 < abs(fv) < 1e12:
                    row['init_float'] = round(fv, 4)
            out.append(row)
        guards = []
        for (root, off, op, val) in sorted(
                v.guards, key=lambda g: (root_str(g[0]), g[1], g[2])):
            g = {'base': root_str(root), 'off_hex': "0x%X" % off,
                 'op': op, 'value': int(val), 'value_hex': "0x%X" % (val & 0xFFFFFFFF)}
            fv = i2f(val)
            if 1e-6 < abs(fv) < 1e12:
                g['value_float'] = round(fv, 4)
            guards.append(g)
        return out, guards
    except Exception as ex:
        return [{'error': str(ex)}], []


def run():
    targets = TARGETS if TARGETS else list(idautils.Functions())
    out = {}
    for ea in targets:
        gl, ce = func_globals_callees(ea)
        fields, guards = func_fields(ea)
        out["%08x" % ea] = {
            'name': idc.get_func_name(ea) or ("sub_%X" % ea),
            'globals': gl,
            'callees': ce,
            'fields': fields,
            'guards': guards,
        }
    json.dump(out, open(OUT, 'w', encoding='utf-8'), indent=1)
    print("[skeleton] %d funcs -> %s" % (len(out), OUT))


run()
qexit(0)
