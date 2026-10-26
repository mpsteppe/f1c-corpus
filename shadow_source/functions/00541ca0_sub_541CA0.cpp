// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541CA0
// Canonical corpus name: sub_541CA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_541CA0_00541ca0.c

void UnknownObject::sub_541CA0()
{
    // __thiscall flag-setter that sets or clears bit 3 (value 0x8) of the dword field at this+0x80 based on the boolean parameter a2, stores the updated value back, and returns it. When a2 is non-zero bit 3 is set via OR 0x8; otherwise it is cleared via AND 0xFFFFFFF7.
    // CALCULATION: Load the current dword value v2 at this[32] (offset 0x80). [field:this:0x00000080, source:raw]
    // GUARD: Branch on parameter a2: if non-zero set bit 3 via result = v2 | 0x8; if zero clear bit 3 via result = v2 & 0xFFFFFFF7. [source:raw]
    // ASSIGNMENT: Store the updated value back into this[32] (offset 0x80). [field:this:0x00000080, source:raw]
    // RETURN: Return the updated field value (result). [source:raw]
    // CALL: Invoked on the per-frame path by ConditionalSubsystemCallWithParameter (0x00408DE0), ConditionalRenderPipelineDispatch (0x00409970), StateInitializerWithFlagCheck (0x00466300), CUBESceneLoaderEntry (0x0048E8D0) and sub_548AD0 (0x00548AD0). [caller:0x00408DE0, caller:0x00409970, caller:0x00466300, caller:0x0048E8D0, caller:0x00548AD0]

    // Conservative worker pseudocode:
    //   unsigned int sub_541CA0(unsigned int* this, int enable) {
    //     unsigned int flags = this[32];
    //     if (enable) flags |= 0x8;
    //     else flags &= 0xFFFFFFF7;
    //     this[32] = flags;
    //     return flags;
    //   }
    // UNRESOLVED: Semantic meaning of bit 3 in the dword field at this+0x80 is unknown; callers spanning render, scene-loading and subsystem-init paths suggest a shared enable/state flag.
    // UNRESOLVED: Object type holding the 0x80 flag field is unknown.
}
