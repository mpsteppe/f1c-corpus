// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3A90
// Canonical corpus name: ArithmeticComparison_3a90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_3a90_004b3a90.c

void UnknownObject::ArithmeticComparison_3a90()
{
    // __thiscall that copies a variable-length data blob from source a2 into destination this, then copies one dword at offset 0x1AC from source to destination and returns this. Blob byte count is derived from a 10-bit size field in bits 8-17 of the source's first dword, plus 8 header bytes.
    // CALCULATION: Compute the copy byte count as ((*a2 >> 8) & 0x3FF) + 8: a 10-bit size field extracted from bits 8-17 of the source's first dword, plus 8 bytes. [source:raw]
    // GUARD: Guard on the computed size being greater than 0 before performing the copy. For a non-negative 10-bit field plus 8 this is always true, so it never actually blocks the copy. [source:raw]
    // CALL: Perform a byte copy (qmemcpy) of the computed size from source a2 into destination this when the guard passes; the copy helper is not present in the packet's callee evidence. [function:0x004B3A90, source:raw]
    // ASSIGNMENT: Copy the dword at a2[107] (source offset 0x1AC) into this[107] (destination offset 0x1AC). [field:this:0x000001AC, source:raw]
    // RETURN: Return the destination pointer this. [source:raw]
    // CALL: Invoked on the per-frame path by NetCommSessionMessageDispatcher (0x0045D890), FloatComputation (0x00464B40), sub_465300 (0x00465300), AdvanceRingBuffer (0x004B3AF0), CollisionObjectInsertion (0x004B48E0), FloatComparisonListIteration (0x004B5380), sub_4B6360 (0x004B6360), TimedAudioEventPlayback (0x004B9510), ZoneThresholdComparisonWithConditionalAction (0x004FFFB0), CollisionStateUpdate (0x00500010) and CollisionTestWithThreshold (0x00500560). [caller:0x0045D890, caller:0x00464B40, caller:0x00465300, caller:0x004B3AF0, caller:0x004B48E0, caller:0x004B5380, caller:0x004B6360, caller:0x004B9510, caller:0x004FFFB0, caller:0x00500010, caller:0x00500560]

    // Conservative worker pseudocode:
    //   void* sub_4B3A90(void* this, const void* a2) {
    //     int size = ((*(unsigned int*)a2 >> 8) & 0x3FF) + 8;
    //     if (size > 0) memcpy(this, a2, size);
    //     ((unsigned int*)this)[107] = ((unsigned int*)a2)[107];
    //     return this;
    //   }
    // UNRESOLVED: The 'size > 0' guard is always true for a non-negative 10-bit size field plus 8, so the copy is effectively unconditional; it is likely a defensive or decompiler artifact check.
    // UNRESOLVED: Semantic role of the copied byte blob and of its 8-byte prefix is unknown.
    // UNRESOLVED: Purpose of the destination field at this+0x1AC is unknown.
}
