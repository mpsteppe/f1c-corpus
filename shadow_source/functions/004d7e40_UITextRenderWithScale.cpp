// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7E40
// Canonical corpus name: UITextRenderWithScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextRenderWithScale_004d7e40.c

void UnknownObject::UITextRenderWithScale()
{
    // Renders UI text with independent horizontal (a7) and vertical (a8) scale factors. Looks up the render context via SwitchBasedGlobalLookup(a6), temporarily scales two of its fields (at +92 and +96), applies a field setter at offset 0x48, divides the text position by the scale factors (truncated via CRTFtol), computes the aligned position using SizeComputationWithSubtraction (left, a5==1) or CenteredPosition (center, a5==2), draws through sub_553070 to the render device global dword_8B8DC8, then restores the context fields.
    // CALL: result = SwitchBasedGlobalLookup(a6): looks up the render context/font structure by id; returns null when absent. [callee:0x004D7FA0]
    // GUARD: If the looked-up context is null, return the null result immediately. [callee:0x004D7FA0]
    // CALCULATION: Save original context fields: v10 = *(float*)(context+92), v11 = *(int*)(context+96); then scale them in place: +92 = a7 * old, +96 = a8 * old. [source:raw]
    // CALL: FieldSetterAt0x48(a4): sets a field at offset 0x48 in a UI/render structure. [callee:0x00552FC0]
    // CALCULATION: v13 = CRTFtol(a2 / a7); a2 = v13; a3 = CRTFtol(a3 / a8): divide position by the scale factors, truncating to integer. [callee:0x00587BDC]
    // GUARD: If a5 == 1, SizeComputationWithSubtraction(a1, v13, &a2, a6): computes left-aligned text position. [callee:0x004D7F60]
    // GUARD: Else if a5 == 2, CenteredPosition(a1, v13, &a2, a6): computes centered text position. [callee:0x004D7F20]
    // ASSIGNMENT: v13 = a2: adopt the alignment-adjusted horizontal position for rendering. [source:raw]
    // CALL: result = sub_553070(a1, v13, a3, dword_8B8DC8): draws the text to the render device. [callee:0x00553070, global:0x008B8DC8]
    // ASSIGNMENT: Restore the original context fields: +92 = v14 (saved float), +96 = v15 (saved int). [source:raw]
    // RETURN: Return the render result. [function:0x004D7E40]

    // Conservative worker pseudocode:
    //   ctx = SwitchBasedGlobalLookup(a6); if !ctx: return 0
    //   save ctx[+92], ctx[+96]; ctx[+92] *= a7; ctx[+96] *= a8
    //   FieldSetterAt0x48(a4)
    //   x = (int)(a2 / a7); y = (int)(a3 / a8)
    //   if a5 == 1: SizeComputationWithSubtraction(a1, x, &x, a6)
    //   else if a5 == 2: CenteredPosition(a1, x, &x, a6)
    //   result = sub_553070(a1, x, y, dword_8B8DC8)
    //   ctx[+92] = saved_float; ctx[+96] = saved_int
    //   return result
    // UNRESOLVED: Context fields at +92 and +96 (scale factors) have no packet field evidence entries; their byte offsets are read from the raw source only.
    // UNRESOLVED: Roles of a1, a4 and a6 (text object, field-setter argument, context id) are inferred from helper names and call sites.
    // UNRESOLVED: The 21 callers are listed as evidence only; none is analyzed here.
}
