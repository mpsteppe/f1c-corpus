// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464670
// Canonical corpus name: ConditionalObjectCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalObjectCleanup_00464670.c

void UnknownObject::ConditionalObjectCleanup()
{
    // Conditional two-part cleanup of network-object state on game exit. First clears the object pointer at obj+0x3FB8 (vtable call with the stored argument at +0x417C, then pointer validation, then zeroing) when that pointer is nonzero. Second resets a flag block at this+0x1B790 and, when the pointer at obj+0x1B79C is nonzero, runs network cleanup on it and zeroes it. Invoked from GameExit (0042DB20).
    // CALCULATION: Dereferences this to obtain the object base pointer v5 = *this, then reads the first cleanup candidate v6 = *(v5 + 0x3FB8) [field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // GUARD: If the pointer at obj+0x3FB8 is nonzero, perform the vtable call, pointer check, and clear; otherwise skip that block entirely [field:obj:0x00003FB8, source:raw]
    // CALL: VTableCallViaOffset0x7c(v6, *(v5 + 0x417C)): calls the virtual method at vtable offset 0x7C on the object at obj+0x3FB8, passing the stored argument from obj+0x417C [callee:0x0057A8B0, field:obj:0x00003FB8, field:obj:0x0000417C]
    // CALL: PointerCheckWithFallback(this + 0x3FB8): validates the pointer being cleared, with fallback handling [callee:0x0057AB20, field:obj:0x00003FB8]
    // ASSIGNMENT: Clears the first pointer slot to 0: *(obj + 0x3FB8) = 0 [field:obj:0x00003FB8]
    // CALCULATION: Computes the flag block base v1 = this + 112528 (0x1B790), where the secondary object pointer lives at v1 + 12 (obj + 0x1B79C) [field:obj:0x0001B79C, source:raw]
    // CALL: BooleanFlagResetWithSideEffects(v1): resets a flag at the start of the block this+0x1B790, returning a value carried as result [source:raw]
    // GUARD: If the pointer at obj+0x1B79C is nonzero, run network cleanup and clear it; otherwise leave it untouched [field:obj:0x0001B79C, source:raw]
    // CALL: NetworkCleanup(v3): tears down the secondary network object pointed to by obj+0x1B79C [field:obj:0x0001B79C, source:raw]
    // ASSIGNMENT: Clears the secondary pointer slot to 0: *(obj + 0x1B79C) = 0 [field:obj:0x0001B79C]
    // RETURN: Returns result (the flag-reset side-effect value, or the network-cleanup result when the second block ran) [function:0x00464670, source:raw]
    // CALL: Invoked from GameExit (0042DB20) to perform network-object cleanup during game shutdown [caller:0x0042DB20]

    // Conservative worker pseudocode:
    //   v5 = *this;
    //   v6 = *(v5 + 0x3FB8);
    //   if (v6) {
    //     VTableCallViaOffset0x7c(v6, *(v5 + 0x417C));
    //     PointerCheckWithFallback(v5 + 0x3FB8);
    //     *(v5 + 0x3FB8) = 0;
    //   }
    //   v1 = *this + 0x1B790;
    //   result = BooleanFlagResetWithSideEffects(v1);
    //   v3 = *(v1 + 12);
    //   if (v3) {
    //     result = NetworkCleanup(v3);
    //     *(v1 + 12) = 0;
    //   }
    //   return result;
    // UNRESOLVED: The identity of the NetworkCleanup routine is not present in the packet callee list (only VTableCallViaOffset0x7c and PointerCheckWithFallback are listed), so its target address is unknown
    // UNRESOLVED: The class of the object behind this and the meaning of the flag reset at this+0x1B790 are not evidenced
}
