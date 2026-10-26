import idaapi, idautils, idc, ida_segment, ida_bytes
idaapi.auto_wait()
lines = []
lines.append("auto_is_ok: %s" % idaapi.auto_is_ok())
lines.append("imagebase: %s" % hex(idaapi.get_imagebase()))
eps = list(idautils.Entries())
lines.append("entries: %s" % str(eps))
for seg_ea in idautils.Segments():
    seg = ida_segment.getseg(seg_ea)
    name = ida_segment.get_segm_name(seg)
    lines.append("seg %s %s %s type %s" % (name, hex(seg.start_ea), hex(seg.end_ea), seg.type))
funcs = list(idautils.Functions())
lines.append("func count: %d" % len(funcs))
t = ida_segment.get_segm_by_name(".text")
if t:
    ea = t.start_ea
    lines.append(".text start %s flags %s" % (hex(ea), hex(ida_bytes.get_full_flags(ea))))
    lines.append("is_code: %s" % ida_bytes.is_code(ida_bytes.get_full_flags(ea)))
    # count code vs unknown bytes in first 0x10000 of .text
    code_c = unk_c = data_c = 0
    p = ea
    end = min(ea + 0x20000, t.end_ea)
    while p < end:
        fl = ida_bytes.get_full_flags(p)
        if ida_bytes.is_code(fl): code_c += 1
        elif ida_bytes.is_unknown(fl): unk_c += 1
        elif ida_bytes.is_data(fl): data_c += 1
        p += 1
    lines.append("first 0x20000 of .text: code=%d unk=%d data=%d" % (code_c, unk_c, data_c))
with open(r"%USERPROFILE%/Desktop/nt2004_ida_decompile/diag_result.txt", "w") as f:
    f.write("\n".join(lines))
idaapi.qexit(0)
