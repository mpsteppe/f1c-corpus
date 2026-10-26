// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517EE1
// Canonical corpus name: MemoryCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryCopy_00517ee1.c

void UnknownObject::MemoryCopy()
{
    // Minimal memory copy wrapper: copies a4 bytes from source a3 into destination a2 and returns the destination pointer a2. The first parameter a1 is not referenced by the raw source and is unused. A plain qmemcpy (inlined memcpy) of arbitrary byte count with the destination as the return value.
    // CALL: qmemcpy(a2, a3, a4): copy a4 bytes from the source buffer a3 into the destination buffer a2. [source:raw]
    // RETURN: Return a2, the destination buffer pointer. [function:0x00517EE1, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_517EE1(int unused, void *dst, const void *src, unsigned int size) {
    //     qmemcpy(dst, src, size);
    //     return dst;
    //   }
    // UNRESOLVED: The first parameter a1 is accepted but never used in the raw source; it may be a stale or reserved argument kept for ABI compatibility.
    // UNRESOLVED: The source and destination buffer types and the meaning of the copied data are caller-supplied (single caller sub_511B7C) and unknown here.
}
