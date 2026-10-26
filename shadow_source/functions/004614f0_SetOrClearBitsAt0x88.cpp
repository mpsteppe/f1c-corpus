// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004614F0
// Canonical corpus name: BitfieldSetClearAt0x88
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldSetClearAt0x88_004614f0.c

void UnknownObject::SetOrClearBitsAt0x88()
{
    // Sets or clears bits in a byte bitfield at this+0x88 based on a boolean control argument. When a3 is non-zero the a2 bits are ORed into the field (set); otherwise the a2 bits are cleared by ANDing with the complement. Returns a2 on the set path and the updated field byte on the clear path.
    // GUARD: If a3 is non-zero the function sets bits; otherwise it clears bits. No caller-internal guard precedes the branch. [source:raw]
    // ASSIGNMENT: Set path: OR the a2 bits into the bitfield byte at this+0x88 (this[136]). [field:this:0x00000088, source:raw]
    // ASSIGNMENT: Clear path: AND the complement of a2 into the bitfield byte at this+0x88, removing the selected bits. [field:this:0x00000088, source:raw]
    // RETURN: Returns the a2 mask on the set path and the resulting bitfield byte on the clear path. [source:raw]

    // Conservative worker pseudocode:
    //   if (a3) {
    //     result = a2;
    //     this[136] |= a2;
    //   } else {
    //     result = ~a2 & this[136];
    //     this[136] = result;
    //   }
    //   return result;
    // UNRESOLVED: Meaning of the individual bit flags stored at this+0x88 is unresolved; callers NetComm_SetSelfAsReady and ConditionalRenderStateUpdate suggest a network-readiness or render-state bitfield role, but this is not evidenced.
}
