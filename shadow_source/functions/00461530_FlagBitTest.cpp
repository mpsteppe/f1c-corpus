// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461530
// Canonical corpus name: FlagBitTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagBitTest_00461530.c

void UnknownObject::FlagBitTest()
{
    // Bitmask test on a flag byte: ANDs the incoming mask a2 with the byte at offset 0x88 of this and returns non-zero if any bit of the mask is set. Read-only, no side effects. Called from net-comm message dispatch, input dispatch, session synchronizer, player-slot sync and championship-standings paths.
    // CALCULATION: Compute the bitwise AND of the incoming mask a2 with the byte at offset 0x88 of this, keeping only the bits set in both. [field:this:0x00000088, source:raw]
    // RETURN: Return whether the AND result is non-zero, i.e. whether any bit from the a2 mask is set in the 0x88 flag byte. [field:this:0x00000088, function:0x00461530, source:raw]

    // Conservative worker pseudocode:
    //   return (a2 & this[136]) != 0;
    // UNRESOLVED: The meaning of the individual bits in the 0x88 flag byte and the identity of the owning object are unknown from this packet.
    // UNRESOLVED: The callers span net-comm dispatch, input dispatch, session sync and championship-standings paths; which flag semantics each relies on is not established.
}
