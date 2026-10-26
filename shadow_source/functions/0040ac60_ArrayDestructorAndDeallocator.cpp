// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040AC60
// Canonical corpus name: ArrayDestructorAndDeallocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayDestructorAndDeallocator_0040ac60.c

void UnknownObject::ArrayDestructorAndDeallocator()
{
    // Array deletion helper (scalar-deleting-destructor-shaped). a2 is a flag word: bit 2 (a2 & 2) selects the array path, bit 0 (a2 & 1) selects whether the backing allocation is freed. On the array path the element count is read from the allocation header at this[-1]; the helper walks the elements in reverse (stride 40 dwords = 160 bytes each), calling the per-element destructor ShortComputation_62a0 on each, optionally frees the allocation base at this[-1] via FreeWrapper_7bcf, and returns the base pointer. On the non-array path it runs the destructor once on this and returns it.
    // GUARD: Dispatch on the array flag: when (a2 & 2) != 0 take the array-deletion path, otherwise run the single-element path. [source:raw]
    // CALCULATION: Read the element count v3 = *(this - 1) from the allocation header immediately before the array. [source:raw]
    // CALCULATION: Compute the allocation base v4 = (char *)(this - 1) and the starting walk pointer v5 = (char *)&this[40 * v3], i.e. one stride (40 dwords = 160 bytes) past the last element. [source:raw]
    // GUARD: Guard the iteration on v6 = v3 - 1 >= 0; with an empty array (v3 == 0) the destructor loop is skipped entirely. [source:raw]
    // LOOP: do-while loop over v3 iterations seeded from v7 = v6 + 1, walking the elements in reverse: v5 -= 160, destructor call, --v7 until v7 is zero. [source:raw]
    // CALL: Call the per-element destructor ShortComputation_62a0(v5) for each element during the reverse walk. [callee:0x004562A0, source:raw]
    // GUARD: Guard the free on the free flag: only when (a2 & 1) != 0. [source:raw]
    // CALL: Free the allocation via FreeWrapper_7bcf(v4), where v4 is the allocation base (this - 1). [callee:0x00587BCF, source:raw]
    // RETURN: Return v4, the allocation base pointer, on the array path. [source:raw]
    // CALL: Single-element path: run the destructor ShortComputation_62a0(this) once on the object itself. [callee:0x004562A0, source:raw]
    // GUARD: Single-element path free guard: when (a2 & 1) != 0, free the object via FreeWrapper_7bcf(this). [callee:0x00587BCF, source:raw]
    // RETURN: Return this on the single-element path. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_40AC60(_DWORD *this, char flags) {
    //     if ((flags & 2) != 0) {
    //       int count = *(this - 1);
    //       char *base = (char *)(this - 1);
    //       char *p = (char *)&this[40 * count];
    //       int i = count - 1;
    //       if (i >= 0) {
    //         int n = i + 1;
    //         do { p -= 160; ShortComputation_62a0(p); --n; } while (n);
    //       }
    //       if ((flags & 1) != 0) FreeWrapper_7bcf(base);
    //       return base;
    //     } else {
    //       ShortComputation_62a0(this);
    //       if ((flags & 1) != 0) FreeWrapper_7bcf(this);
    //       return (char *)this;
    //     }
    //   }
    // UNRESOLVED: The identity and purpose of the per-element destructor ShortComputation_62a0 is not established by the packet; it is treated as the element destructor from control flow only.
    // UNRESOLVED: The layout of the element type (40 dwords, 160-byte stride) and the header word this[-1] are inferred from the pointer arithmetic in the raw source; the object type owning the array is unknown.
    // UNRESOLVED: The a2 bit meanings (bit 1 = array, bit 0 = free) are read directly from the bit tests in the source but are not named by the packet.
    // UNRESOLVED: The legacy ABI label 'Array_Destructor_and_Deallocator' (abi:lead) is carried at LEGACY trust only and does not independently establish ownership.
}
