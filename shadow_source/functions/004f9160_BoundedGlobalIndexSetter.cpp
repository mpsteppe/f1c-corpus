// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9160
// Canonical corpus name: UtilityFunction_9160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_9160_004f9160.c

void UnknownObject::BoundedGlobalIndexSetter()
{
    // Bounded global index/value setter. Reads an upper bound by passing dword_8AFE64 to SimpleFieldGetter_bfc0, then, when the requested index a1 is below that bound, stores a1 into dword_8AFE6C and stores the value retrieved for that index via BoundedArrayAccessor_bfd0 into dword_8AFE68. Returns the bound when the guard fails, otherwise the retrieved value.
    // CALL: Read the upper bound by passing dword_8AFE64 to SimpleFieldGetter_bfc0. [callee:0x0055BFC0, global:0x008AFE64]
    // GUARD: Guard on the requested index a1: it must be strictly less than the bound retrieved from dword_8AFE64 for the writes to occur. [source:raw]
    // ASSIGNMENT: Store the requested index a1 into dword_8AFE6C. [global:0x008AFE6C]
    // CALL: Read the value at index a1 through BoundedArrayAccessor_bfd0. [callee:0x0055BFD0]
    // ASSIGNMENT: Store the value retrieved for the index into dword_8AFE68. [global:0x008AFE68]
    // RETURN: Return the retrieved value on success, or the bound when the index was out of range. [function:0x004F9160]

    // Conservative worker pseudocode:
    //   bound = SimpleFieldGetter_bfc0(dword_8AFE64);
    //   if (a1 < bound) {
    //     dword_8AFE6C = a1;
    //     result = BoundedArrayAccessor_bfd0(a1);
    //     dword_8AFE68 = result;
    //   }
    //   return result;
    // UNRESOLVED: Semantic role of the three globals (bound source, current index, cached value) and the backing array layout are not established by this packet; the particle-related naming in prior prose is speculative.
    // UNRESOLVED: What dword_8AFE64 represents and how its bound is derived is not established here.
}
