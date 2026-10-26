// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004527E0
// Canonical corpus name: StructInitWithSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithSubCall_004527e0.c

void UnknownObject::StructInitWithSubCall()
{
    // Initializes a small collision-property structure: zeroes the state field at this+0x0, calls SwapAndReinit(this+1, a2, a3) which reinitializes the node-property pair starting at this+0x4 with forwarded values, then zeroes the two trailing dwords at this+0x1C and this+0x20. Returns the result produced by SwapAndReinit. Called by ShortComputation_30a0 (004530A0).
    // ASSIGNMENT: Zero the dword state/guard field at this+0x0 [field:this:0x00000000, source:raw]
    // CALL: Call SwapAndReinit(this+1, a2, a3) to swap stored values and reinitialize the collision node property pair starting at this+0x4 [callee:0x00452740, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x20 (source expression this[8]) [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x1C (source expression this[7]) [field:this:0x0000001C, source:raw]
    // RETURN: Return the value produced by SwapAndReinit [function:0x004527E0, source:raw]
    // CALL: Invoked by ShortComputation_30a0 (004530A0) to perform the initialization [caller:0x004530A0, source:raw]

    // Conservative worker pseudocode:
    //   *this = 0;
    //   result = SwapAndReinit(this + 1, a2, a3);
    //   this[8] = 0;
    //   this[7] = 0;
    //   return result;
    // UNRESOLVED: The exact semantics of SwapAndReinit's swap-and-reinit on the pair at this+0x4 are not documented at this call site
    // UNRESOLVED: The purpose of the two forwarded arguments a2 and a3 is not evidenced here
    // UNRESOLVED: The role of the two trailing zeroed fields at this+0x1C and this+0x20 (associated collision values) is inferred, not confirmed
}
