// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411840
// Canonical corpus name: FontRenderingPrep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FontRenderingPrep_00411840.c

void UnknownObject::FontRenderingPrep()
{
    // Font/event render dispatch prepper. Resolves a generation index and two sub-indices from *a1 via three helper lookups, returning 0 on any sentinel (-1) or negative result. A one-time init block (guarded by byte_5EA5E0 bit 0) resets the track-load state block and sentinels. Every call re-primes the path buffer through StringCopyWithBufferRealloc and dispatches in sequence through CharacterCodeMapper, RaceEventMessageDispatcher, FontCharacterRenderDispatcher and SoundEventDispatcher, advancing a 20-byte slot offset per successful dispatch and decrementing counters. Returns the count of successful dispatches (0-2). Called by TextOverlayDisplayTimer (004186F0).
    // CALCULATION: Resolve generation: v5 = ShortComputation_19d0(*a1); return 0 when it equals -1 [callee:0x004119D0, field:this:0x00000000, source:raw]
    // CALCULATION: Resolve sub-indices: v9 = ShortComputation_1a00(*a1, v5) and v8 = ShortComputation_1a50(*a1); return 0 when either is negative [callee:0x00411A00, callee:0x00411A50, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: One-time initialization when byte_5EA5E0 bit 0 is clear: set bit 0, dword_5EA5D0 = 0, dword_5EA5D4 = -1, StringCopyWithBufferRealloc(&byte_5EA438), dword_5EA5D8 = -1, dword_5EA5DC = -1, then BooleanToIntConversion(sub_4119B0) [source:raw, global:0x005EA5E0, global:0x005EA5D0, global:0x005EA5D4, global:0x005EA5D8, global:0x005EA5DC, global:0x005EA438, callee:0x00566650, callee:0x00587B3E, global:0x004119B0]
    // ASSIGNMENT: Per-call re-prime: StringCopyWithBufferRealloc(&byte_5EA438) then reset dword_5EA5D8 = -1 and dword_5EA5DC = -1 [callee:0x00566650, global:0x005EA438, global:0x005EA5D8, global:0x005EA5DC, source:raw]
    // CALL: CharacterCodeMapper(v9 + v8, v5, &dword_5EA5D0, *a1): on nonzero return 0 [callee:0x00411B50, global:0x005EA5D0, field:this:0x00000000, source:raw]
    // CALL: RaceEventMessageDispatcher(v5, &dword_5EA5D0, a1, a2) == 1 triggers DecrementCounterWithFloorAtZero(a2) and v3 = 1 [callee:0x00411BF0, callee:0x00414140, global:0x005EA5D0, source:raw]
    // CALL: FontCharacterRenderDispatcher(v5, &dword_5EA5D0, a1, a2 + 20 * v3, *a1) == 1: increment v3, then SoundEventDispatcher(v5, &dword_5EA5D0, a1, a2 + 20 * v3) == 1 triggers DecrementCounterWithFloorAtZero on that slot and another increment; return the final count, else return 0 [source:raw, callee:0x00411DB0, callee:0x00411E90, callee:0x00414140, global:0x005EA5D0, field:this:0x00000000]
    // CALL: Invoked by TextOverlayDisplayTimer (004186F0) during text-overlay display [caller:0x004186F0, function:0x00411840]

    // Conservative worker pseudocode:
    //   v3 = 0;
    //   v5 = ShortComputation_19d0(*a1);
    //   if (v5 == -1) return 0;
    //   v9 = ShortComputation_1a00(*a1, v5);
    //   v8 = ShortComputation_1a50(*a1);
    //   if (v9 < 0 || v8 < 0) return 0;
    //   if ((byte_5EA5E0 & 1) == 0) {
    //     byte_5EA5E0 |= 1;
    //     dword_5EA5D0 = 0;
    //     dword_5EA5D4 = -1;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     dword_5EA5D8 = -1;
    //     dword_5EA5DC = -1;
    //     BooleanToIntConversion(sub_4119B0);
    //   }
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   dword_5EA5D8 = -1; dword_5EA5DC = -1;
    //   if (CharacterCodeMapper(v9 + v8, v5, &dword_5EA5D0, *a1)) return 0;
    //   if (RaceEventMessageDispatcher(v5, &dword_5EA5D0, a1, a2) == 1) { DecrementCounterWithFloorAtZero(a2); v3 = 1; }
    //   if (FontCharacterRenderDispatcher(v5, &dword_5EA5D0, a1, a2 + 20 * v3, *a1) == 1) {
    //     ++v3;
    //     if (SoundEventDispatcher(v5, &dword_5EA5D0, a1, a2 + 20 * v3) == 1) {
    //       DecrementCounterWithFloorAtZero(a2 + 20 * v3);
    //       ++v3;
    //     }
    //     return v3;
    //   }
    //   return 0;
    // UNRESOLVED: The meaning of the 20-byte slot stride and the exact overlay resource it addresses are not documented by this packet
    // UNRESOLVED: sub_4119B0 is referenced only as an argument to BooleanToIntConversion during one-time init; its role in the state block is unverified
}
