// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005575F0
// Canonical corpus name: FlagCheckWithConditionalPathDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagCheckWithConditionalPathDispatch_005575f0.c

void UnknownObject::FlagCheckWithConditionalPathDispatch()
{
    // Guard-and-init dispatcher over the flags dword at this+0x20. Loads the flags, and on both paths returns 0 immediately when bit 0x400 is set (already initialized). Otherwise bit 0x8 selects the path: set -> call Return0Stub, clear -> call sub_558310(this). If the selected call returns non-zero the function returns -1 (failure); on success bit 0x400 is OR-ed into the flags and 0 is returned.
    // ASSIGNMENT: Load the flags dword from this+0x20 into a local for bit testing [field:this:0x00000020, source:raw]
    // GUARD: Path selector: bit 0x8 of the flags at this+0x20 set -> take the Return0Stub path, clear -> take the sub_558310 path [field:this:0x00000020, source:raw]
    // GUARD: Init-done guard on both paths: bit 0x400 of the flags at this+0x20 set -> return 0 immediately without calling anything [field:this:0x00000020, source:raw]
    // CALL: Return0Stub called on the bit-0x8-set path; returns 0 unconditionally [callee:0x0047ABB0, source:raw]
    // CALL: sub_558310(this) called on the bit-0x8-clear path; init function returning 0 on success and non-zero on failure [callee:0x00558310, source:raw]
    // GUARD: Failure check: if the selected path call returned non-zero, return -1 [source:raw]
    // ASSIGNMENT: OR bit 0x400 into the flags dword at this+0x20 to mark initialization done [field:this:0x00000020, source:raw]
    // RETURN: Return 0 on the success path [function:0x005575F0, source:raw]

    // Conservative worker pseudocode:
    //   int FlagCheckWithConditionalPathDispatch(_DWORD *this) {
    //     int v2 = this[8];
    //     if ((v2 & 8) != 0) {
    //       if ((v2 & 0x400) != 0) return 0;
    //       v3 = Return0Stub();
    //     } else {
    //       if ((v2 & 0x400) != 0) return 0;
    //       v3 = sub_558310(this);
    //     }
    //     if (v3) return -1;
    //     this[8] |= 0x400;
    //     return 0;
    //   }
    // UNRESOLVED: The owning object and the meaning of flag bits 0x8 and 0x400 at this+0x20 are unknown; the init-done semantics are inferred from the control flow only
    // UNRESOLVED: Why the bit-0x8-set path performs no real initialization (Return0Stub) is not explained from this packet alone
    // UNRESOLVED: The failure semantics of sub_558310 (what a non-zero return means) are not visible here
}
