// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A34A0
// Canonical corpus name: PerElementConditionalActionDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerElementConditionalActionDispatcher_004a34a0.c

void UnknownObject::PerElementConditionalActionDispatcher()
{
    // Walks the element array at this+0x10 (count this+0x0C, 120-byte stride) and flips a Bit12 flag on each element's target object. In conditional mode (a2 == 0) the flag is cleared when the element's completion predicate (signed +112 > 0 and the float reached through +116 == 99999.0) matches the pending byte at +2, and set when they disagree. In clear-all mode (a2 != 0) every element with a valid object at +100 has its flag cleared unconditionally. Called per-frame by PitStopOperationTimer (004a6340) and PitStopProgress (004a68b0).
    // GUARD: a2 == 0 selects the conditional per-element mode; a non-zero a2 forces the clear-all mode that skips the conditional branch entirely [source:raw]
    // LOOP: Iterates the element array at this+0x10 with a 120-byte stride, once per element of the count stored at this+0x0C, stopping when the counter reaches the count [field:this:0x00000010, field:this:0x0000000C, source:raw]
    // GUARD: Per-element skip: elements whose dword at +72 equals -1, or whose target pointer at +100 is null, are skipped without any flag change [source:raw]
    // STATE_TRANSITION: Conditional flag decision: BitClear is applied to the object at +100 when the completion predicate (int +112 > 0 and float pointed by +116 == 99999.0) equals the pending byte at +2, otherwise Bit12FlagSet is applied [callee:0x0054C190, callee:0x0054C1A0, source:raw]
    // LOOP: Clear-all mode walks the same array and unconditionally BitClear-s the object at +100 for every element whose +72 dword is not -1 and whose target pointer is non-null [callee:0x0054C190, field:this:0x00000010, field:this:0x0000000C, source:raw]
    // RETURN: Returns the final element count read from this+0x0C [field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0x0C/4];
    //   if (a2 == 0) {
    //       for (i = 0; i < count; i += 120) {
    //           elem = this[0x10/4] + i;
    //           if (*(elem+72) == -1 || *(elem+100) == 0) continue;
    //           predicate = (*(elem+112) > 0) && (**(elem+116) == 99999.0);
    //           if (predicate == *(elem+2)) BitClear(*(elem+100));
    //           else Bit12FlagSet(*(elem+100));
    //       }
    //   } else {
    //       for (i = 0; i < count; i += 120) {
    //           elem = this[0x10/4] + i;
    //           if (*(elem+72) != -1 && *(elem+100) != 0) BitClear(*(elem+100));
    //       }
    //   }
    // UNRESOLVED: The float constant 99999.0 appears as a literal in the raw source while the packet facts also flag the read-only global flt_59E928 as compared here; the relationship between the literal and the global is not established by this packet
    // UNRESOLVED: The meaning of the flag manipulated by BitClear/Bit12FlagSet (bit 12, activation/enable) and the purpose of the 120-byte element layout come from the prior fill and remain DERIVED
    // UNRESOLVED: The exact semantics of the fields at element+72 (index/state) and +2 (pending byte) are not established by this packet alone
}
