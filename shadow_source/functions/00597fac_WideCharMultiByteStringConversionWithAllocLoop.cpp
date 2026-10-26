// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597FAC
// Canonical corpus name: WideCharMultiByteStringConversionWithAllocLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WideCharMultiByteStringConversionWithAllocLoop_00597fac.c

void UnknownObject::WideCharMultiByteStringConversionWithAllocLoop()
{
    // Iterates over a null-terminated array of wide-character string pointers rooted at dword_8D3E98. For each entry it measures the multibyte length with WideCharToMultiByte, allocates a buffer via MallocWrapperForNhMalloc, converts the string into that buffer, and hands it to sub_598323. Returns 0 when the list is empty or fully processed; returns -1 when measurement, allocation, or conversion fails.
    // ASSIGNMENT: Load the list base and head pointer: v0 = dword_8D3E98, v1 = *(const WCHAR **)dword_8D3E98. [source:raw, global:0x008D3E98]
    // GUARD: Guard: if the head pointer *(DWORD *)dword_8D3E98 is NULL, return 0 (empty list). [source:raw, global:0x008D3E98]
    // LOOP: Loop over the wide-string entries until a NULL next pointer terminates the iteration. [source:raw]
    // CALL: Call WideCharToMultiByte with a NULL output buffer to measure the required multibyte length of the current wide string. [source:raw, global:0x0059E228]
    // GUARD: Guard: if the measurement call returns 0, break the loop and fall through to the failure return. [source:raw]
    // CALL: Allocate a multibyte buffer of the measured length via MallocWrapperForNhMalloc. [source:raw, callee:0x0058A935]
    // GUARD: Guard: if allocation returns NULL or the conversion call fails, break the loop and fall through to the failure return. [source:raw]
    // CALL: Convert the current wide string into the allocated buffer via WideCharToMultiByte. [source:raw, global:0x0059E228]
    // CALL: Store the converted buffer by calling sub_598323 with the buffer and a zero second argument. [source:raw, callee:0x00598323]
    // CALCULATION: Advance to the next entry: v1 = *(const WCHAR **)(v0 + 4), then v0 += 4. [source:raw]
    // GUARD: Guard: if the next pointer is NULL, return 0 (list fully processed). [source:raw]
    // RETURN: Return -1 on any measurement, allocation, or conversion failure path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_597FAC() {
    //     int base = dword_8D3E98;
    //     const WCHAR *p = *(const WCHAR **)dword_8D3E98;
    //     if (!p) return 0;
    //     for (;;) {
    //       int len = WideCharToMultiByte(1, 0, p, -1, 0, 0, 0, 0);
    //       if (!len) break;
    //       CHAR *buf = (CHAR *)MallocWrapperForNhMalloc(len);
    //       if (!buf || !WideCharToMultiByte(1, 0, *(const WCHAR **)base, -1, buf, len, 0, 0)) break;
    //       sub_598323(buf, 0);
    //       p = *(const WCHAR **)(base + 4);
    //       base += 4;
    //       if (!p) return 0;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: dword_8D3E98 is walked as a flat array of WCHAR pointers (v0 += 4) with a NULL sentinel; the existing analysis also calls it a linked list, so the container shape is ambiguous.
    // UNRESOLVED: abi:lead is marked LEGACY (name WideChar, null prototype); the exact ABI of this function's lead is unresolved.
    // UNRESOLVED: The second argument 0 passed to sub_598323 identifies the storage target, whose structure is unknown here.
    // UNRESOLVED: The WideCharToMultiByte first argument 1 (code page) is taken from the raw source; its constancy across the two calls is observed but its provenance is unresolved.
}
