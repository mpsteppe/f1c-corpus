"""
IDA Pro headless COMPREHENSIVE export for F1 Challenge 99-02.

v2 — extracts EVERYTHING useful from the binary:
  1. functions        — addr, size, name, flags, calling convention, type signature
  2. vtables          — scan .data/.rdata for code pointer arrays
  3. code xrefs       — call/jump edges between functions
  4. data xrefs       — which functions read/write which global addresses
  5. strings          — all detected strings
  6. imports          — DLL imports
  7. segments         — PE section table
  8. switch tables    — jump table targets per function
  9. stack frames     — local variables and parameters per function
 10. exception info   — SEH handlers and try/catch scopes
 11. byte patterns    — raw bytes at uncovered .text gaps (no function)
 12. decompile        — Hex-Rays output for ALL IDA-only functions

First run (creates DB + full analysis):
    idat.exe -c -A -B -S"C:\\path\\ida_export_all.py" "F1 Challenge Online.exe"

Subsequent runs (reuse existing DB):
    idat.exe -A -B -S"C:\\path\\ida_export_all.py" "F1 Challenge Online.exe"

Outputs written to same directory as this script (tools/):
    ida_functions.csv
    ida_vtables.csv
    ida_xrefs.csv
    ida_data_xrefs.csv      (NEW)
    ida_strings.csv
    ida_imports.csv
    ida_segments.csv
    ida_switches.csv         (NEW)
    ida_stack_frames.csv     (NEW)
    ida_exceptions.csv       (NEW)
    ida_gaps.csv             (NEW)
    decompiled/ *.c          (NEW — Hex-Rays output for IDA-only functions)
"""

import csv
import os
import sys
import traceback

# Write errors to log file so we can debug headless failures
ERROR_LOG = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ida_export_errors.log")

def log_error(msg):
    print(msg)
    with open(ERROR_LOG, "a", encoding="utf-8") as f:
        f.write(msg + "\n")

# Clear error log
try:
    with open(ERROR_LOG, "w") as f:
        f.write("")
except:
    pass

# Core IDA imports (required)
try:
    import idc
    import idaapi
    import idautils
    import ida_funcs
    import ida_segment
    import ida_bytes
    import ida_nalt
    import ida_xref
    import ida_name
except ImportError as e:
    print(f"ERROR: core IDA import failed: {e}")
    sys.exit(1)

# Optional IDA imports (may differ across IDA versions)
ida_frame = None
ida_struct = None
ida_typeinf = None
ida_auto = None

for mod_name in ["ida_frame", "ida_struct", "ida_typeinf", "ida_auto"]:
    try:
        globals()[mod_name] = __import__(mod_name)
    except ImportError:
        log_error(f"WARNING: {mod_name} not available in this IDA version — some exports will be skipped")

OUT_DIR = os.path.dirname(os.path.abspath(__file__))
DECOMPILE_DIR = os.path.join(OUT_DIR, "decompiled_ida")
BADADDR = idc.BADADDR

# Game code range
GAME_START = 0x00401000
GAME_END   = 0x005e0000

# Ghidra function addresses — loaded from existing CSV to identify IDA-only functions
GHIDRA_CSV = os.path.join(os.path.dirname(OUT_DIR), "work", "function_sizes.csv")


def addr_str(ea):
    return f"0x{ea:08x}"


def func_source(name):
    if not name:
        return "sub"
    if name.startswith("sub_") or name.startswith("loc_"):
        return "sub"
    if name.startswith("j_") or name.startswith("nullsub_"):
        return "thunk"
    if name.startswith("??") or name.startswith("_ZN"):
        return "rtti"
    if name.startswith("__") or name.startswith("_"):
        return "flirt"
    return "named"


def load_ghidra_addrs():
    addrs = set()
    if not os.path.exists(GHIDRA_CSV):
        print(f"  WARNING: {GHIDRA_CSV} not found — will decompile nothing")
        return addrs
    with open(GHIDRA_CSV, encoding="utf-8") as f:
        for row in csv.DictReader(f):
            a = row.get("address", row.get("addr", "")).strip().lower()
            if a.startswith("0x"):
                addrs.add(int(a, 16))
            elif a:
                try:
                    addrs.add(int(a, 16))
                except ValueError:
                    pass
    return addrs


# ---------------------------------------------------------------------------
# 1. functions — comprehensive metadata
# ---------------------------------------------------------------------------

def export_functions():
    path = os.path.join(OUT_DIR, "ida_functions.csv")
    rows = []
    for ea in idautils.Functions():
        fn = ida_funcs.get_func(ea)
        if fn is None:
            continue
        name = idc.get_func_name(ea) or f"sub_{ea:x}"
        try:
            demangled = idc.demangle_name(name, idc.get_inf_attr(idc.INF_SHORT_DN)) or ""
        except Exception:
            demangled = ""

        # Function flags
        flags = fn.flags
        flag_strs = []
        if flags & idaapi.FUNC_NORET:
            flag_strs.append("noreturn")
        if flags & idaapi.FUNC_LIB:
            flag_strs.append("library")
        if flags & idaapi.FUNC_THUNK:
            flag_strs.append("thunk")
        if flags & idaapi.FUNC_FRAME:
            flag_strs.append("bp_frame")

        # Type info / calling convention
        type_str = ""
        cc_str = ""
        if ida_typeinf:
            try:
                tinfo = ida_typeinf.tinfo_t()
                if ida_nalt.get_tinfo(tinfo, ea):
                    type_str = str(tinfo)
                    fi = ida_typeinf.func_type_data_t()
                    if tinfo.get_func_details(fi):
                        cc_map = {
                            ida_typeinf.CM_CC_CDECL: "cdecl",
                            ida_typeinf.CM_CC_STDCALL: "stdcall",
                            ida_typeinf.CM_CC_THISCALL: "thiscall",
                            ida_typeinf.CM_CC_FASTCALL: "fastcall",
                            ida_typeinf.CM_CC_PASCAL: "pascal",
                        }
                        cc_str = cc_map.get(fi.cc & ida_typeinf.CM_CC_MASK, f"cc_{fi.cc & ida_typeinf.CM_CC_MASK}")
            except Exception:
                pass

        rows.append({
            "addr":      addr_str(ea),
            "end_addr":  addr_str(ea + fn.size()),
            "size":      fn.size(),
            "name":      name,
            "demangled": demangled,
            "source":    func_source(name),
            "flags":     "|".join(flag_strs) if flag_strs else "",
            "cc":        cc_str,
            "type":      type_str,
        })

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr","end_addr","size","name","demangled","source","flags","cc","type"])
        w.writeheader()
        w.writerows(rows)
    print(f"[01/12] functions: {len(rows)} -> {os.path.basename(path)}")
    return rows


# ---------------------------------------------------------------------------
# 2. vtables — scan .data/.rdata for arrays of 2+ consecutive code pointers
# ---------------------------------------------------------------------------

def export_vtables():
    path = os.path.join(OUT_DIR, "ida_vtables.csv")
    rows = []

    text_start = None
    text_end = None
    for seg_ea in idautils.Segments():
        sname = idc.get_segm_name(seg_ea)
        if sname in (".text", "CODE", "seg000"):
            seg = ida_segment.getseg(seg_ea)
            if seg:
                text_start = seg.start_ea
                text_end = seg.end_ea
                break

    if text_start is None:
        print("[02/12] vtables: could not find .text segment, skipping")
        return

    def is_code_ptr(val):
        return val != BADADDR and val != 0 and text_start <= val < text_end

    vtable_starts = set()

    for ea, name in idautils.Names():
        nl = name.lower()
        if "vtable" in nl or "vtbl" in nl or name.startswith("??_7") or name.startswith("off_"):
            try:
                first = idc.get_dword(ea)
                if is_code_ptr(first):
                    vtable_starts.add(ea)
            except Exception:
                pass

    for seg_ea in idautils.Segments():
        seg = ida_segment.getseg(seg_ea)
        if seg is None:
            continue
        sname = idc.get_segm_name(seg_ea)
        if sname not in (".data", ".rdata", "DATA", "CONST", "data", "rdata"):
            continue
        ea = seg.start_ea
        end = seg.end_ea
        while ea < end - 8:
            try:
                p0 = idc.get_dword(ea)
                p1 = idc.get_dword(ea + 4)
            except Exception:
                ea += 4
                continue
            if is_code_ptr(p0) and is_code_ptr(p1):
                vtable_starts.add(ea)
                ea += 4
            else:
                ea += 4

    seen_pairs = set()
    for vt_ea in sorted(vtable_starts):
        slot = 0
        cur = vt_ea
        while slot < 256:
            try:
                ptr = idc.get_dword(cur)
            except Exception:
                break
            if not is_code_ptr(ptr):
                break
            fn_name = idc.get_func_name(ptr) or idc.get_name(ptr) or ""
            key = (vt_ea, slot)
            if key not in seen_pairs:
                seen_pairs.add(key)
                rows.append({
                    "vtable_addr": addr_str(vt_ea),
                    "slot":        slot,
                    "func_addr":   addr_str(ptr),
                    "func_name":   fn_name,
                })
            slot += 1
            cur += 4

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["vtable_addr","slot","func_addr","func_name"])
        w.writeheader()
        w.writerows(rows)
    print(f"[02/12] vtables: {len(vtable_starts)} candidates, {len(rows)} slots -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 3. code xrefs — call/jump edges
# ---------------------------------------------------------------------------

def export_xrefs():
    path = os.path.join(OUT_DIR, "ida_xrefs.csv")
    rows = []
    seen = set()

    for func_ea in idautils.Functions():
        try:
            items = list(idautils.FuncItems(func_ea))
        except Exception:
            continue
        for insn_ea in items:
            try:
                for ref in idautils.CodeRefsFrom(insn_ea, False):
                    target_fn = ida_funcs.get_func(ref)
                    if target_fn is None:
                        continue
                    if target_fn.start_ea != ref:
                        continue
                    key = (func_ea, ref)
                    if key in seen:
                        continue
                    seen.add(key)
                    xtype = "call"
                    xr = ida_xref.xrefblk_t()
                    if xr.first_from(insn_ea, ida_xref.XREF_ALL):
                        if xr.type in (ida_xref.fl_JN, ida_xref.fl_JF):
                            xtype = "jump"
                    rows.append({
                        "from_func": addr_str(func_ea),
                        "to_func":   addr_str(ref),
                        "xref_type": xtype,
                    })
            except Exception:
                continue

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["from_func","to_func","xref_type"])
        w.writeheader()
        w.writerows(rows)
    print(f"[03/12] xrefs: {len(rows)} call edges -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 4. data xrefs — which functions read/write which global addresses
# ---------------------------------------------------------------------------

def export_data_xrefs():
    path = os.path.join(OUT_DIR, "ida_data_xrefs.csv")
    rows = []

    # Find data segments
    data_ranges = []
    for seg_ea in idautils.Segments():
        seg = ida_segment.getseg(seg_ea)
        if seg is None:
            continue
        sname = idc.get_segm_name(seg_ea)
        if sname in (".data", ".rdata", ".bss", "DATA", "BSS"):
            data_ranges.append((seg.start_ea, seg.end_ea, sname))

    # Also include known global range even if not in a named data segment
    # F1C globals: 0x005c0000 - 0x008f0000
    GLOBAL_START = 0x005c0000
    GLOBAL_END   = 0x008f0000

    print(f"  data segments: {len(data_ranges)}")
    print(f"  scanning global range: 0x{GLOBAL_START:08x}-0x{GLOBAL_END:08x}")

    seen = set()

    for func_ea in idautils.Functions():
        try:
            items = list(idautils.FuncItems(func_ea))
        except Exception:
            continue

        for insn_ea in items:
            try:
                # Check data references from this instruction
                for ref in idautils.DataRefsFrom(insn_ea):
                    if ref == BADADDR:
                        continue
                    # Only track references to data/global addresses
                    in_range = GLOBAL_START <= ref < GLOBAL_END
                    if not in_range:
                        for ds, de, _ in data_ranges:
                            if ds <= ref < de:
                                in_range = True
                                break
                    if not in_range:
                        continue

                    key = (func_ea, ref)
                    if key in seen:
                        continue
                    seen.add(key)

                    # Determine access type from xref type
                    access = "read"
                    xr = ida_xref.xrefblk_t()
                    if xr.first_from(insn_ea, ida_xref.XREF_DATA):
                        if xr.type == ida_xref.dr_W:
                            access = "write"
                        elif xr.type == ida_xref.dr_R:
                            access = "read"
                        elif xr.type == ida_xref.dr_O:
                            access = "offset"

                    global_name = idc.get_name(ref) or ""
                    rows.append({
                        "func_addr":   addr_str(func_ea),
                        "global_addr": addr_str(ref),
                        "global_name": global_name,
                        "access":      access,
                    })
            except Exception:
                continue

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["func_addr","global_addr","global_name","access"])
        w.writeheader()
        w.writerows(rows)
    print(f"[04/12] data_xrefs: {len(rows)} global references -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 5. strings
# ---------------------------------------------------------------------------

def export_strings():
    path = os.path.join(OUT_DIR, "ida_strings.csv")
    rows = []
    try:
        sc = idautils.Strings()
        sc.setup(strtypes=[ida_nalt.STRTYPE_C, ida_nalt.STRTYPE_C_16])
        for s in sc:
            try:
                value = str(s)
            except Exception:
                value = "<error>"

            # Find which function references this string
            ref_funcs = []
            for ref in idautils.DataRefsTo(s.ea):
                fn = ida_funcs.get_func(ref)
                if fn:
                    ref_funcs.append(addr_str(fn.start_ea))

            rows.append({
                "addr":      addr_str(s.ea),
                "length":    s.length,
                "encoding":  "utf-16" if s.strtype == ida_nalt.STRTYPE_C_16 else "ascii",
                "value":     value[:500],
                "ref_funcs": "|".join(ref_funcs[:20]),
            })
    except Exception as e:
        print(f"  [strings] error: {e}")

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr","length","encoding","value","ref_funcs"])
        w.writeheader()
        w.writerows(rows)
    print(f"[05/12] strings: {len(rows)} -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 6. imports
# ---------------------------------------------------------------------------

def export_imports():
    path = os.path.join(OUT_DIR, "ida_imports.csv")
    rows = []
    try:
        nimps = idaapi.get_import_module_qty()
        for i in range(nimps):
            dll = idaapi.get_import_module_name(i) or ""

            def cb(ea, name, ordinal):
                # Find which functions call this import
                callers = []
                for ref in idautils.CodeRefsTo(ea, False):
                    fn = ida_funcs.get_func(ref)
                    if fn:
                        callers.append(addr_str(fn.start_ea))

                rows.append({
                    "addr":    addr_str(ea),
                    "name":    name or f"ord_{ordinal}",
                    "dll":     dll,
                    "callers": "|".join(callers[:30]),
                })
                return True

            idaapi.enum_import_names(i, cb)
    except Exception as e:
        print(f"  [imports] error: {e}")

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr","name","dll","callers"])
        w.writeheader()
        w.writerows(rows)
    print(f"[06/12] imports: {len(rows)} -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 7. segments
# ---------------------------------------------------------------------------

def export_segments():
    path = os.path.join(OUT_DIR, "ida_segments.csv")
    rows = []
    for seg_ea in idautils.Segments():
        seg = ida_segment.getseg(seg_ea)
        if not seg:
            continue

        perm_str = ""
        if seg.perm & 1:
            perm_str += "R"
        if seg.perm & 2:
            perm_str += "W"
        if seg.perm & 4:
            perm_str += "X"

        rows.append({
            "name":  idc.get_segm_name(seg_ea),
            "start": addr_str(seg.start_ea),
            "end":   addr_str(seg.end_ea),
            "size":  seg.size(),
            "perm":  perm_str,
            "type":  seg.type,
            "align": seg.align,
        })

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["name","start","end","size","perm","type","align"])
        w.writeheader()
        w.writerows(rows)
    print(f"[07/12] segments: {len(rows)} -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 8. switch tables — jump table targets
# ---------------------------------------------------------------------------

def export_switches():
    path = os.path.join(OUT_DIR, "ida_switches.csv")
    rows = []

    for func_ea in idautils.Functions():
        try:
            items = list(idautils.FuncItems(func_ea))
        except Exception:
            continue

        for insn_ea in items:
            try:
                si = idaapi.get_switch_info(insn_ea)
                if si is None:
                    continue

                # Extract jump table entries
                ncases = si.get_jtable_size()
                jt_addr = si.jumps

                targets = []
                for i in range(ncases):
                    try:
                        if si.get_jtable_element_size() == 4:
                            target = idc.get_dword(jt_addr + i * 4)
                        elif si.get_jtable_element_size() == 2:
                            target = idc.get_word(jt_addr + i * 2)
                        elif si.get_jtable_element_size() == 1:
                            target = idc.get_byte(jt_addr + i)
                        else:
                            target = idc.get_dword(jt_addr + i * 4)

                        if target != BADADDR and target != 0:
                            targets.append(addr_str(target))
                    except Exception:
                        pass

                rows.append({
                    "func_addr":   addr_str(func_ea),
                    "switch_addr": addr_str(insn_ea),
                    "jtable_addr": addr_str(jt_addr),
                    "ncases":      ncases,
                    "elem_size":   si.get_jtable_element_size(),
                    "targets":     "|".join(targets[:64]),
                    "default":     addr_str(si.defjump) if si.defjump != BADADDR else "",
                })
            except Exception:
                continue

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["func_addr","switch_addr","jtable_addr","ncases","elem_size","targets","default"])
        w.writeheader()
        w.writerows(rows)
    print(f"[08/12] switches: {len(rows)} jump tables -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 9. stack frames — local variables and parameters
# ---------------------------------------------------------------------------

def export_stack_frames():
    path = os.path.join(OUT_DIR, "ida_stack_frames.csv")
    rows = []

    if not ida_frame or not ida_struct:
        print("[09/12] stack_frames: ida_frame/ida_struct not available — skipping")
        with open(path, "w", newline="", encoding="utf-8") as f:
            f.write("func_addr,frame_size,num_members,members\n")
        return

    for func_ea in idautils.Functions():
        fn = ida_funcs.get_func(func_ea)
        if fn is None:
            continue

        try:
            frame = ida_frame.get_frame(func_ea)
        except Exception:
            continue
        if frame is None:
            continue

        frame_size = idc.get_func_attr(func_ea, idc.FUNCATTR_FRSIZE)

        members = []
        try:
            for i in range(frame.memqty):
                member = frame.get_member(i)
                if member is None:
                    continue
                mname = ida_struct.get_member_name(member.id) or ""
                moff = member.soff
                msize = ida_struct.get_member_size(member)

                mtype = ""
                if ida_typeinf:
                    try:
                        tif = ida_typeinf.tinfo_t()
                        if ida_struct.get_member_tinfo(tif, member):
                            mtype = str(tif)
                    except Exception:
                        pass

                members.append(f"{mname}@{moff}:{msize}:{mtype}")
        except Exception:
            continue

        if members:
            rows.append({
                "func_addr":   addr_str(func_ea),
                "frame_size":  frame_size,
                "num_members": len(members),
                "members":     "|".join(members[:50]),
            })

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["func_addr","frame_size","num_members","members"])
        w.writeheader()
        w.writerows(rows)
    print(f"[09/12] stack_frames: {len(rows)} functions with frame info -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 10. exception handlers — SEH and try/catch
# ---------------------------------------------------------------------------

def export_exceptions():
    path = os.path.join(OUT_DIR, "ida_exceptions.csv")
    rows = []

    for func_ea in idautils.Functions():
        fn = ida_funcs.get_func(func_ea)
        if fn is None:
            continue

        # Check if function has SEH (indicated by frame members)
        has_seh = False
        if ida_frame and ida_struct:
            try:
                frame = ida_frame.get_frame(func_ea)
                if frame:
                    for i in range(frame.memqty):
                        member = frame.get_member(i)
                        if member:
                            mname = ida_struct.get_member_name(member.id) or ""
                            if "SEH" in mname.upper() or "exception" in mname.lower() or mname == " s":
                                has_seh = True
                                break
            except Exception:
                pass

        # Check for __CxxFrameHandler references
        has_cxx_eh = False
        try:
            items = list(idautils.FuncItems(func_ea))
            for insn_ea in items:
                for ref in idautils.CodeRefsFrom(insn_ea, False):
                    ref_name = idc.get_func_name(ref) or ""
                    if "CxxFrameHandler" in ref_name or "except_handler" in ref_name:
                        has_cxx_eh = True
                        break
                if has_cxx_eh:
                    break
        except Exception:
            pass

        if has_seh or has_cxx_eh:
            rows.append({
                "func_addr": addr_str(func_ea),
                "func_name": idc.get_func_name(func_ea) or "",
                "seh":       "yes" if has_seh else "no",
                "cxx_eh":    "yes" if has_cxx_eh else "no",
            })

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["func_addr","func_name","seh","cxx_eh"])
        w.writeheader()
        w.writerows(rows)
    print(f"[10/12] exceptions: {len(rows)} functions with exception handling -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 11. byte patterns at uncovered .text gaps
# ---------------------------------------------------------------------------

def export_gaps():
    path = os.path.join(OUT_DIR, "ida_gaps.csv")
    rows = []

    # Find .text segment
    text_start = None
    text_end = None
    for seg_ea in idautils.Segments():
        sname = idc.get_segm_name(seg_ea)
        if sname in (".text", "CODE", "seg000"):
            seg = ida_segment.getseg(seg_ea)
            if seg:
                text_start = seg.start_ea
                text_end = seg.end_ea
                break

    if text_start is None:
        print("[11/12] gaps: no .text segment")
        return

    # Collect all function ranges
    func_ranges = []
    for ea in idautils.Functions():
        fn = ida_funcs.get_func(ea)
        if fn:
            func_ranges.append((fn.start_ea, fn.start_ea + fn.size()))
    func_ranges.sort()

    # Find gaps between functions within .text
    prev_end = text_start
    for fstart, fend in func_ranges:
        if fstart < text_start:
            continue
        if fstart > text_end:
            break
        if fstart > prev_end:
            gap_size = fstart - prev_end
            if gap_size >= 4:  # skip tiny alignment
                # Read first 64 bytes
                hex_bytes = ""
                try:
                    raw = ida_bytes.get_bytes(prev_end, min(gap_size, 64))
                    if raw:
                        hex_bytes = raw.hex()
                except Exception:
                    pass

                # Classify gap
                classification = "unknown"
                if raw:
                    if all(b == 0xCC for b in raw[:min(gap_size, 64)]):
                        classification = "int3_padding"
                    elif all(b == 0x90 for b in raw[:min(gap_size, 64)]):
                        classification = "nop_padding"
                    elif all(b == 0x00 for b in raw[:min(gap_size, 64)]):
                        classification = "zero_fill"
                    elif gap_size >= 16:
                        classification = "possible_code_or_data"

                rows.append({
                    "start":          addr_str(prev_end),
                    "end":            addr_str(fstart),
                    "size":           gap_size,
                    "classification": classification,
                    "hex_head":       hex_bytes[:128],
                })
        prev_end = max(prev_end, fend)

    # Check gap after last function to end of .text
    if prev_end < text_end:
        gap_size = text_end - prev_end
        if gap_size >= 4:
            hex_bytes = ""
            try:
                raw = ida_bytes.get_bytes(prev_end, min(gap_size, 64))
                if raw:
                    hex_bytes = raw.hex()
            except Exception:
                pass

            classification = "tail_gap"
            rows.append({
                "start":          addr_str(prev_end),
                "end":            addr_str(text_end),
                "size":           gap_size,
                "classification": classification,
                "hex_head":       hex_bytes[:128],
            })

    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["start","end","size","classification","hex_head"])
        w.writeheader()
        w.writerows(rows)

    total_gap = sum(r["size"] for r in rows if isinstance(r["size"], int))
    code_gaps = [r for r in rows if r["classification"] == "possible_code_or_data"]
    print(f"[11/12] gaps: {len(rows)} gaps, {total_gap} bytes total, {len(code_gaps)} possible code/data -> {os.path.basename(path)}")


# ---------------------------------------------------------------------------
# 12. decompile ALL IDA-only functions via Hex-Rays
# ---------------------------------------------------------------------------

def decompile_all_ida_only():
    try:
        import ida_hexrays
        if not ida_hexrays.init_hexrays_plugin():
            print("[12/12] decompile: Hex-Rays not available — skipping")
            return
    except Exception as e:
        print(f"[12/12] decompile: Hex-Rays import failed: {e}")
        return

    os.makedirs(DECOMPILE_DIR, exist_ok=True)

    ghidra_addrs = load_ghidra_addrs()
    print(f"  Ghidra knows {len(ghidra_addrs)} functions")

    # Find IDA-only functions in game code range with size >= 8
    ida_only = []
    for ea in idautils.Functions():
        if ea in ghidra_addrs:
            continue
        if ea < GAME_START or ea >= GAME_END:
            continue
        fn = ida_funcs.get_func(ea)
        if fn is None:
            continue
        if fn.size() < 8:
            continue
        ida_only.append((ea, fn))

    print(f"  IDA-only in game range (>=8B): {len(ida_only)} functions to decompile")

    ok = 0
    fail = 0
    for ea, fn in ida_only:
        name = idc.get_func_name(ea) or f"FUN_{ea:08x}"

        # Normalize name for filename
        safe_name = name.replace("?", "_").replace("@", "_").replace(":", "_")
        fname = f"0x{ea:08x}__{safe_name}.c"
        out_path = os.path.join(DECOMPILE_DIR, fname)

        # Skip if already decompiled
        if os.path.exists(out_path):
            ok += 1
            continue

        try:
            cfunc = ida_hexrays.decompile(ea)
        except Exception as e:
            fail += 1
            continue
        if cfunc is None:
            fail += 1
            continue

        code = str(cfunc)

        # Get type info
        type_str = ""
        if ida_typeinf:
            try:
                tinfo = ida_typeinf.tinfo_t()
                if ida_nalt.get_tinfo(tinfo, ea):
                    type_str = str(tinfo)
            except Exception:
                pass

        with open(out_path, "w", encoding="utf-8") as f:
            f.write(f"// Address: 0x{ea:08x}\n")
            f.write(f"// Size: {fn.size()} bytes\n")
            f.write(f"// Name: {name}\n")
            if type_str:
                f.write(f"// Type: {type_str}\n")
            f.write(f"// Source: IDA Hex-Rays decompilation\n")
            f.write(f"\n")
            f.write(code)

        ok += 1

    # Also decompile the known giant gap addresses
    GIANT_GAPS = [0x0056fa96, 0x00575bbd, 0x00578f76, 0x00579ccf]
    ANALYZED_DIR = os.path.join(os.path.dirname(OUT_DIR), "analysis_pipeline", "analyzed")

    for ea in GIANT_GAPS:
        fn = ida_funcs.get_func(ea)
        if fn is None:
            continue
        name = idc.get_func_name(ea) or f"FUN_{ea:08x}"
        fname = f"0x{ea:08x}__FUN_{ea:08x}.c"

        for target_dir in [DECOMPILE_DIR, ANALYZED_DIR]:
            out = os.path.join(target_dir, fname)
            if os.path.exists(out):
                continue
            try:
                cfunc = ida_hexrays.decompile(ea)
                if cfunc:
                    code = str(cfunc)
                    with open(out, "w", encoding="utf-8") as f:
                        f.write(f"// Address: 0x{ea:08x}\n// Size: {fn.size()} bytes\n// Name: {name}\n\n")
                        f.write(code)
                    ok += 1
            except Exception:
                fail += 1

    print(f"[12/12] decompile: {ok} OK, {fail} failed -> {os.path.basename(DECOMPILE_DIR)}/")


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

print("=" * 70)
print("IDA COMPREHENSIVE EXPORT v2")
print(f"Output dir: {OUT_DIR}")
print(f"Decompile dir: {DECOMPILE_DIR}")
print("=" * 70)

idaapi.auto_wait()

for label, fn in [
    ("functions",    export_functions),
    ("vtables",      export_vtables),
    ("code_xrefs",   export_xrefs),
    ("data_xrefs",   export_data_xrefs),
    ("strings",      export_strings),
    ("imports",      export_imports),
    ("segments",     export_segments),
    ("switches",     export_switches),
    ("stack_frames", export_stack_frames),
    ("exceptions",   export_exceptions),
    ("gaps",         export_gaps),
    ("decompile",    decompile_all_ida_only),
]:
    try:
        fn()
    except Exception:
        msg = f"ERROR in {label}:\n{traceback.format_exc()}"
        print(msg)
        log_error(msg)

print("=" * 70)
print("Export complete.")
print("=" * 70)
log_error("Export complete.")

idaapi.qexit(0)
