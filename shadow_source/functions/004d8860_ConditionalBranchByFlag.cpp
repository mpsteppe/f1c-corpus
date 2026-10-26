// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8860
// Canonical corpus name: ConditionalBranchByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalBranchByFlag_004d8860.c

void UnknownObject::ConditionalBranchByFlag()
{
    // Flag dispatcher on the frame path (per-frame tick). When a2 (the flag) is non-zero, returns IndexValidationSetter(0). When a2 is zero, resets this[2] (dword field at byte offset 0x8) to -1 and returns 0. Invoked by FloatClampWithEventDispatch, StructInitWithConditionalNotify, CameraModeViewportUpdate and MainCameraDirectorUpdate.
    // ASSIGNMENT: result = a2: preserve the flag as the default return value. [source:raw]
    // GUARD: Branch on a2: a non-zero flag takes the dispatch path; a zero flag takes the index-reset path. [source:raw]
    // CALL: Dispatch: return IndexValidationSetter(0) when the flag is set. [source:raw]
    // STATE_TRANSITION: When the flag is clear, reset this[2] (dword at byte offset 0x8) to -1, treated as a sentinel/invalid index. [field:this:0x00000008, source:raw]
    // RETURN: Return result (0) on the flag-clear path. [function:0x004D8860, source:raw]
    // CALL: Invoked by FloatClampWithEventDispatch (004082B0), StructInitWithConditionalNotify (004083E0), CameraModeViewportUpdate (00409A00) and MainCameraDirectorUpdate (0040CA30). [caller:0x004082B0, caller:0x004083E0, caller:0x00409A00, caller:0x0040CA30]

    // Conservative worker pseudocode:
    //   char result = a2;
    //   if (a2) {
    //     return IndexValidationSetter(0);
    //   }
    //   this[2] = -1; /* dword at byte offset 0x8 * /
    //   return result;
    // UNRESOLVED: IndexValidationSetter is invoked with argument 0 but is absent from the packet's callee list; its address, behavior and return value are not verifiable from this packet.
    // UNRESOLVED: The meaning of the this[2] = -1 reset (an index/state field) is inferred from prior analysis only; exact semantics are unknown.
}
