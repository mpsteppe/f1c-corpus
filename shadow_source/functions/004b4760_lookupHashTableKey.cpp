// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4760
// Canonical corpus name: ArithmeticComparison_4760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_4760_004b4760.c

void UnknownObject::lookupHashTableKey()
{
    // Validated hash-table lookup gate (__stdcall). Rejects immediately when the caller context a1 is nonzero, when the candidate dword a2 has any of the 0xFC0000 bits set, or when the low byte of a2 is 0x68 (104) or greater. Otherwise looks the low byte up in the HashTableLookup table seeded with 0 and writes the result slot to a1; returns 1 only when the lookup hits (HashTableLookup returns nonzero). Called by CollisionObjectInsertion, consistent with a type-key validity check before an object-insertion hash query.
    // GUARD: Guard: if a1 is nonzero the function returns 0 immediately, refusing the lookup. [source:raw, function:0x004B4760]
    // GUARD: Guard: if (*a2 & 0xFC0000) != 0 the function returns 0; the mask 0xFC0000 selects the upper six bits of the key dword. [source:raw]
    // GUARD: Guard: if the low byte of *a2 is >= 0x68 (104) the function returns 0, bounding the lookup key below 0x68, i.e. to the key space 0..103. [source:raw]
    // CALL: Calls HashTableLookup(0, (unsigned char)*a2, &a1): the low byte of the key is the hash key and a1 receives the lookup result slot. v2 records whether the returned value equals 0. [callee:0x004B4840, source:raw]
    // RETURN: Returns the constant 1 only when the lookup did not return 0 (a hit); all rejection paths return 0. [source:raw, function:0x004B4760]

    // Conservative worker pseudocode:
    //   if (a1) return 0;
    //   if (*a2 & 0xFC0000) return 0;
    //   if ((unsigned char)*a2 >= 0x68) return 0;
    //   return HashTableLookup(0, (unsigned char)*a2, &a1) != 0;
    // UNRESOLVED: HashTableLookup's table contents and the meaning of the 0..103 key space are outside this packet; the hit value written to a1 is consumed by the caller and not described here.
    // UNRESOLVED: The 0xFC0000 mask test's exact role (rejecting flag bits vs high bits of an extended key) is not determinable from this function alone.
    // UNRESOLVED: The owning class is unknown; the caller name CollisionObjectInsertion is the only owner signal and is itself DERIVED.
}
