// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593DD3
// Canonical corpus name: sub_593DD3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593DD3_00593dd3.c

void UnknownObject::MsvcrtHeapInit()
{
    // Initializes the msvcrt CRT heap sub-allocator: allocates a 0x140-byte block from the private heap hHeap, records the returned base pointer, resets the free-list and block counters to 0, stores the caller-supplied maximum allocation size, and sets the initial realloc capacity to 16. Returns 1 on success, or the NULL HeapAlloc result when the allocation fails.
    // CALL: Call HeapAlloc(hHeap, 0, 0x140) to allocate a 320-byte block from the private heap. [global:0x0059E1C0, global:0x008D4904, source:raw]
    // ASSIGNMENT: Store the returned allocation pointer into lpMem (0x008D48FC). [global:0x008D48FC, source:raw]
    // GUARD: Guard: proceed only when the allocation result is non-NULL; otherwise fall through and return the NULL result. [source:raw]
    // ASSIGNMENT: Reset dword_8D48F4 (free-list count) to 0. [global:0x008D48F4, source:raw]
    // ASSIGNMENT: Reset dword_8D48F8 (block counter) to 0. [global:0x008D48F8, source:raw]
    // ASSIGNMENT: Set dword_8D48F0 (cursor/base of the allocated region) to the allocation result. [global:0x008D48F0, source:raw]
    // ASSIGNMENT: Set dword_8D4900 to the caller's parameter a1 (maximum allocation size). [global:0x008D4900, source:raw]
    // ASSIGNMENT: Set dword_8D48E8 (initial realloc capacity) to 16. [global:0x008D48E8, source:raw]
    // RETURN: Return 1 on successful initialization, or the NULL HeapAlloc result when the allocation failed. [source:raw]
    // CALL: Called by sub_59325D (0x0059325D) during msvcrt heap sub-allocator setup. [caller:0x0059325D, source:raw]

    // Conservative worker pseudocode:
    //   int sub_593DD3(int maxSize) {
    //     void* block = HeapAlloc(hHeap, 0, 0x140);
    //     lpMem = block;
    //     if (block) {
    //       dword_8D48F4 = 0;
    //       dword_8D48F8 = 0;
    //       dword_8D48F0 = (int)block;
    //       dword_8D4900 = maxSize;
    //       dword_8D48E8 = 16;
    //       return 1;
    //     }
    //     return (int)block;
    //   }
    // UNRESOLVED: The named roles (free-list count, block counter, cursor, max allocation size, realloc capacity) for the dword_8D48xx globals are DERIVED from the raw source's init pattern and are not proven by independent evidence.
    // UNRESOLVED: The caller's intended use of the stored maximum allocation size a1 and the exact heap-global layout remain unverified.
}
