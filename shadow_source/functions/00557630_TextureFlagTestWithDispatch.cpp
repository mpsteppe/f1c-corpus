// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557630
// Canonical corpus name: TextureFlagTestWithDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureFlagTestWithDispatch_00557630.c

void UnknownObject::TextureFlagTestWithDispatch()
{
    // Conditional flag-clear dispatch on the flag DWORD at this+0x20. Reads the flag word, and depending on bit 8 selects between two teardown-style helpers (Return0Stub at 0047ABB0 when bit 8 set, ResourceTeardownWithStateArrayReset at 00558990 otherwise); both paths first require bit 0x400 to be set or the function returns 0. Any nonzero helper result returns -1. On success clears bit 0x400 from this+0x20 and returns 0. Structural twin of FlagCheckWithConditionalPathDispatch (005575f0).
    // ASSIGNMENT: v2 = this[8], reading the flag DWORD at this+0x20 [field:this:0x00000020, source:raw]
    // GUARD: Branch on bit 8 of v2: if (v2 & 8) != 0 select Return0Stub, else select ResourceTeardownWithStateArrayReset [source:raw]
    // GUARD: In both branches, if (v2 & 0x400) == 0 return 0 immediately without running the selected helper [source:raw]
    // CALL: v3 = Return0Stub() invoked when bit 8 of the flag is set [callee:0x0047ABB0, source:raw]
    // CALL: v3 = ResourceTeardownWithStateArrayReset(this) invoked when bit 8 of the flag is clear [callee:0x00558990, source:raw]
    // GUARD: If v3 is nonzero, return -1 (failure propagation) [source:raw]
    // ASSIGNMENT: this[8] &= ~0x400, clearing bit 0x400 of the flag DWORD at this+0x20 [field:this:0x00000020, source:raw]
    // RETURN: Return 0 on the success path after clearing the flag bit [source:raw]
    // CALL: Invoked by AudioNetworkStreamCleanup (00544AF0) and by sub_5574B0 (005574B0) [caller:0x00544AF0, caller:0x005574B0]

    // Conservative worker pseudocode:
    //   v2 = this[8];
    //   if ((v2 & 8) != 0) {
    //     if ((v2 & 0x400) == 0) return 0;
    //     v3 = Return0Stub();
    //   } else {
    //     if ((v2 & 0x400) == 0) return 0;
    //     v3 = ResourceTeardownWithStateArrayReset(this);
    //   }
    //   if (v3) return -1;
    //   this[8] &= ~0x400;
    //   return 0;
    // UNRESOLVED: Semantics of bit 8 and bit 0x400 of the flag DWORD at this+0x20 are not documented; the caller distinction is inferred from the prelabel cluster twin note only
    // UNRESOLVED: Return0Stub (0047ABB0) returns 0 unconditionally per its packet name, making its dispatch branch a no-op fallthrough; this is a name-level reading, not proven
}
