# extract_strings.py — Extract EVERY string literal + its xrefs from the IDB.
# Headless: idat.exe -A -L"strings.log" -S"extract_strings.py" "F1 Challenge Online.exe.i64"
#
# WHY this exists: skeleton_facts_all.json carries globals/callees/fields/guards
# but NO string literals. In a 2002 game binary, strings are the highest-yield
# deterministic naming signal there is (error text, file names, and above all the
# CONFIG-FILE TOKEN NAMES the game's own parsers compare against). A token string
# sitting next to the offset it writes is the game naming its own field — two
# independent sources, i.e. CONFIRMED tier, with zero LLM guessing.
#
# Everything here is IDA's own analysis (Strings() + XrefsTo). No text regex, no
# inference. Trust tier of the output = extraction, same as skeleton_facts_all.
#
# Output: strings_index.json
#   _meta            : counts, binary, timestamp
#   strings["<ea8>"] : {s, kind, len, code_xrefs[], data_xrefs[]}
#       code_xrefs   : [{ea, func, func_name}]  - instruction referencing it
#       data_xrefs   : [{ea, name, readers[]}]  - a DATA slot holding the pointer
#                      (a parser token table); readers = functions touching that
#                      slot or the item containing it. This is the parser oracle.
#   by_function["<addr8>"] : [{ea, s}]          - strings reachable from a function
#   orphans          : strings with no xref at all (still useful: table payloads)
import idaapi, idautils, idc, ida_bytes, ida_funcs, ida_nalt, ida_name
import json, os, time

OUT = os.environ.get(
    "STR_OUT",
    r"%USERPROFILE%/Desktop/f1c_ida_decompiled/strings_index.json")

# Minimum length: 4 is IDA's default; 3 keeps short config tokens ("RPM", "AIW").
MIN_LEN = int(os.environ.get("STR_MINLEN", "3"))

# Two hard filters, both needed. Without them the run yields 52k "strings" of
# which 37k are x86 instruction bytes ("D$$", "9\\$", "_^][") that IDA's
# ignore_instructions flag does not actually exclude:
#   1. the string must live in a DATA segment, never in .text;
#   2. it must be printable ASCII/latin text, not stray bytes.
def in_code_segment(ea):
    seg = idaapi.getseg(ea)
    if seg is None:
        return True
    return seg.type == idaapi.SEG_CODE or ida_bytes.is_code(ida_bytes.get_flags(ea))


def is_texty(s):
    if not s:
        return False
    printable = sum(1 for c in s if 32 <= ord(c) < 127 or ord(c) in (9, 10, 13))
    return printable == len(s)


def h8(ea):
    return "%08x" % ea


def func_of(ea):
    f = ida_funcs.get_func(ea)
    return f.start_ea if f else None


def item_head_of(ea):
    """The head of the data item containing ea (a pointer inside a table)."""
    return ida_bytes.get_item_head(ea)


def collect():
    idaapi.auto_wait()

    # Rebuild the string list rather than trusting whatever the IDB last cached:
    # C and Unicode both, so wide-char UI strings are not silently dropped.
    sc = idautils.Strings()
    sc.setup(strtypes=[ida_nalt.STRTYPE_C, ida_nalt.STRTYPE_C_16],
             minlen=MIN_LEN, ignore_instructions=True)
    sc.refresh()

    strings = {}
    by_function = {}
    orphans = []
    n_code = n_data = n_rejected = 0

    for si in sc:
        try:
            raw = str(si)
        except Exception:
            continue
        if not raw:
            continue
        ea = si.ea
        if in_code_segment(ea) or not is_texty(raw):
            n_rejected += 1
            continue
        kind = "unicode" if si.strtype == ida_nalt.STRTYPE_C_16 else "c"

        code_xrefs = []
        data_xrefs = []

        for xr in idautils.XrefsTo(ea, 0):
            frm = xr.frm
            fn = func_of(frm)
            if fn is not None:
                code_xrefs.append({
                    "ea": h8(frm),
                    "func": h8(fn),
                    "func_name": ida_funcs.get_func_name(fn) or "",
                })
                by_function.setdefault(h8(fn), []).append({"ea": h8(ea), "s": raw})
                n_code += 1
            else:
                # Pointer stored in DATA -> almost always a token/dispatch table.
                # Record who reads that slot (and the item containing it), which
                # is the function that parses this token.
                head = item_head_of(frm)
                readers = []
                seen = set()
                for probe in (frm, head):
                    for xr2 in idautils.XrefsTo(probe, 0):
                        rf = func_of(xr2.frm)
                        if rf is None or rf in seen:
                            continue
                        seen.add(rf)
                        readers.append({
                            "func": h8(rf),
                            "func_name": ida_funcs.get_func_name(rf) or "",
                        })
                data_xrefs.append({
                    "ea": h8(frm),
                    "name": ida_name.get_name(head) or "",
                    "readers": readers,
                })
                n_data += 1

        # The IDA symbol ("aMass" for "Mass") is what the decompiled .c actually
        # shows, so without it strings_index cannot be joined to functions/*.c.
        rec = {"s": raw, "kind": kind, "len": si.length,
               "sym": ida_name.get_name(ea) or ""}
        if code_xrefs:
            rec["code_xrefs"] = code_xrefs
        if data_xrefs:
            rec["data_xrefs"] = data_xrefs
        if not code_xrefs and not data_xrefs:
            orphans.append(h8(ea))
        strings[h8(ea)] = rec

    # Deterministic ordering so a re-run diffs cleanly in git.
    for k in by_function:
        by_function[k].sort(key=lambda d: d["ea"])

    out = {
        "_meta": {
            "binary": idaapi.get_root_filename(),
            "image_base": h8(idaapi.get_imagebase()),
            "generated": time.strftime("%Y-%m-%dT%H:%M:%S"),
            "min_len": MIN_LEN,
            "n_strings": len(strings),
            "n_code_xrefs": n_code,
            "n_data_xrefs": n_data,
            "n_orphans": len(orphans),
            "n_rejected_nontext_or_code": n_rejected,
            "n_functions_with_strings": len(by_function),
            "tier": "extraction",
        },
        "strings": strings,
        "by_function": by_function,
        "orphans": orphans,
    }
    with open(OUT, "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1, ensure_ascii=False, sort_keys=True)
    print("[strings] %d strings (%d rejected), %d code xrefs, %d data xrefs, "
          "%d orphans, %d functions -> %s" % (len(strings), n_rejected, n_code,
          n_data, len(orphans), len(by_function), OUT))


try:
    collect()
except Exception as e:
    import traceback
    traceback.print_exc()
    print("[strings] FAILED: %s" % e)

# MUST be last: without qexit the batch loop hangs forever, looking exactly like
# slow autoanalysis (see tools/README.md headless gotchas).
import ida_pro
ida_pro.qexit(0)
