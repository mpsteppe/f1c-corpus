// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405670
// Canonical corpus name: sub_405670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_405670_00405670.c

void UnknownObject::memCopyReturnEnd()
{
    // Memory copy helper (stdcall): copies a3 bytes from source a2 into destination a1 via a raw block copy and returns the one-past-the-end pointer a1 + a3. Legacy ABI name Memory_Copy; used by the memory allocation path.
    // ASSIGNMENT: Copy a3 bytes from a2 to a1 with an inline qmemcpy block copy. [source:raw]
    // RETURN: Return the one-past-the-end destination pointer a1 + a3, suitable for chained writes. [source:raw]
    // CALL: Invoked by MemoryAllocation_56a0 (0x004056A0) as part of its allocation/copy path. [caller:0x004056A0, abi:lead]

    // Conservative worker pseudocode:
    //   char *__stdcall memCopyReturnEnd(char *dst, const void *src, unsigned int n) {
    //     qmemcpy(dst, src, n);
    //     return &dst[n];
    //   }
    // UNRESOLVED: Overlap behaviour between src and dst is unspecified; qmemcpy implies an ordered forward block copy.
}
