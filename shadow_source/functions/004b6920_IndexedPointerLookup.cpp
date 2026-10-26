// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B6920
// Canonical corpus name: IndexedPointerLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedPointerLookup_004b6920.c

void UnknownObject::IndexedPointerLookup()
{
    // __thiscall indexed pointer lookup. Returns this[620] + 176 * a2, i.e. a base pointer stored at this+0x9B0 plus an index (a2) scaled by a 176-byte element stride. Semantics: address of the a2-th element of an array whose base pointer lives at this+0x9B0. Caller is PitStallProximityCheck (0x004B5DA0).
    // ASSIGNMENT: Load the base pointer from this[620], the field at this+0x9B0. [field:this:0x000009B0, source:raw]
    // CALCULATION: Compute 176 * a2, scaling the index by the per-element stride of 176 bytes. [source:raw]
    // RETURN: Return base + 176 * a2: a pointer to the a2-th element of the stride-176 array anchored at this+0x9B0. [field:this:0x000009B0, source:raw]
    // CALL: Consumed by caller PitStallProximityCheck (0x004B5DA0), consistent with fetching a pit-stall object by index. [caller:0x004B5DA0, function:0x004B6920, source:raw]

    // Conservative worker pseudocode:
    //   int IndexedPointerLookup(DWORD *this, int a2) {
    //     return this[620] + 176 * a2;
    //   }
    // UNRESOLVED: The 176-byte element type and whether a2 is an index or byte offset are not confirmed by packet evidence beyond the scaling.
    // UNRESOLVED: The owner class and the kind of objects the array holds are unknown.
    // UNRESOLVED: The caller name PitStallProximityCheck suggests a pit context but is not independent evidence for the element type.
}
