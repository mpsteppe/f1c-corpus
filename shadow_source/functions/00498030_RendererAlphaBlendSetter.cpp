// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498030
// Canonical corpus name: RendererAlphaBlendSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RendererAlphaBlendSetter_00498030.c

void UnknownObject::RendererAlphaBlendSetter()
{
    // Alpha-blend state configuration. When the renderer object a1 is non-null, copies the DSP transform parameter flt_7CF2CC into the working value dword_5CC9E0, clamps it to [0.0, 1.0] via the fixed literal 1065353216 as the upper bound, zeroes a 12-byte scratch array, and dispatches the vtable entry at offset 4 of a1 with arguments (1, v2, v2, dword_5CC9E0, 1065353216, 1). Called from TimedAnimationTrigger and UILargeRender. The null-a1 path returns an uninitialized value.
    // GUARD: Skip all processing when the renderer object a1 is null [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Seed the working value: dword_5CC9E0 = LODWORD(flt_7CF2CC) [global:0x005CC9E0, global:0x007CF2CC]
    // CALCULATION: Zero the 12-byte scratch array v2 via memset before passing it to the vtable method [source:raw]
    // GUARD: When flt_7CF2CC <= 1.0, clamp a negative working value up to 0: if dword_5CC9E0 < 0.0 then dword_5CC9E0 = 0 [global:0x007CF2CC, global:0x005CC9E0, source:raw]
    // ASSIGNMENT: In the overflow branch (flt_7CF2CC > 1.0), cap the working value: dword_5CC9E0 = 1065353216 [global:0x005CC9E0, source:raw]
    // CALL: Dispatch stdcall vtable entry 4 of a1 with arguments (1, v2, v2, dword_5CC9E0, 1065353216, 1); reached from the TimedAnimationTrigger and UILargeRender call paths [field:this:0x00000000, global:0x005CC9E0, function:0x00498030, caller:0x00486730, caller:0x00496930, source:raw]
    // RETURN: The non-null path returns the vtable method's result; the null-a1 path returns the uninitialized result variable [function:0x00498030, source:raw]

    // Conservative worker pseudocode:
    //   if (a1) {
    //     dword_5CC9E0 = LODWORD(flt_7CF2CC);
    //     memset(v2, 0, sizeof(v2));
    //     if (flt_7CF2CC <= 1.0) {
    //       if (*(float*)&dword_5CC9E0 < 0.0) dword_5CC9E0 = 0;
    //     } else {
    //       dword_5CC9E0 = 1065353216;
    //     }
    //     return (*(vtable(a1)[4]))(1, v2, v2, dword_5CC9E0, 1065353216, 1);
    //   }
    //   return result;
    // UNRESOLVED: The null-a1 path returns an uninitialized value; that is raw decompiler output, not a meaningful contract
    // UNRESOLVED: Semantics of the fixed literal 1065353216 used both as the clamp cap and as a dispatch argument are not asserted
    // UNRESOLVED: The renderer object type behind vtable entry 4 and the meaning of the v2/dword_5CC9E0 parameters are unknown
}
