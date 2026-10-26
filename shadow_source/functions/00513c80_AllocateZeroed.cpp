// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513C80
// Canonical corpus name: sub_513C80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_513C80_00513c80.c

void UnknownObject::AllocateZeroed()
{
    // __cdecl zero-filled allocation: computes a byte count v3 = a3 * a2, allocates it via sub_517E92(a1, v3), and zeroes the entire buffer with memset. When the size exceeds 0x8000 the zeroing is split into two memset calls to handle a large region, still covering the whole allocation. Returns the allocated pointer, or NULL (0) when the allocation fails.
    // CALCULATION: Compute the total byte count: v3 = a3 * a2. [source:raw]
    // CALL: Allocate v3 bytes through sub_517E92(a1, a3 * a2); the allocation request uses a3 and a2 separately even though the size is the product. [callee:0x00517E92, source:raw]
    // GUARD: Guard: only proceed when the allocation returned a non-null pointer. [source:raw]
    // GUARD: Guard on the size: when v3 <= 0x8000 zero the whole buffer in one pass, otherwise split into a 0x8000-byte memset plus the remainder. [source:raw]
    // CALL: Zero memory: memset(v4, 0, 0x8000) for the first chunk when large, then memset(v6, 0, v7) for the remainder (v7 = v3 - 0x8000, v6 = v4 + 0x8000), or memset(v4, 0, v3) when small. [source:raw]
    // RETURN: Return the zeroed allocation pointer on success, or NULL on allocation failure. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_513C80(int a1, int a2, int a3) {
    //     unsigned int n = a3 * a2;
    //     char *p = (char *)sub_517E92(a1, a3 * a2);
    //     if (p) {
    //       if (n <= 0x8000) {
    //         memset(p, 0, n);
    //       } else {
    //         memset(p, 0, 0x8000);
    //         memset(p + 0x8000, 0, n - 0x8000);
    //       }
    //       return p;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Purpose of a1 (passed to the allocator but not otherwise used) is unknown; it may be an allocator context or tag.
    // UNRESOLVED: Semantics of sub_517E92 are unknown; it is assumed to be a heap/memory allocator from the caller pattern but not proven.
    // UNRESOLVED: The 0x8000 split is an optimization for large allocations; no semantic difference for the returned buffer.
    // UNRESOLVED: Caller sub_518AAA is unknown, so the buffer's element layout and the roles of a2/a3 (dimensions vs count) are unresolved.
}
