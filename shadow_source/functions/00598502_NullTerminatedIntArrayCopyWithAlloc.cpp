// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598502
// Canonical corpus name: NullTerminatedIntArrayCopyWithAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NullTerminatedIntArrayCopyWithAlloc_00598502.c

void UnknownObject::NullTerminatedIntArrayCopyWithAlloc()
{
    // Deep-copies a null-terminated array of string pointers. Walks the input array counting elements until a null terminator, allocates 4 * (count + 1) bytes, aborts via CRTAmsgExit(9) if allocation fails, then copies each entry through StringAllocCopy and null-terminates the new array. Returns the newly allocated array, or 0 when the input pointer is null.
    // ASSIGNMENT: Initialize the element counter to 0. [source:raw]
    // GUARD: If the input array pointer a1 is null, return 0 immediately. [source:raw]
    // LOOP: Walk a1 + 1 through the array elements (starting at the element after the first, i.e. the int at offset 4) until a null entry is found, counting entries as they are read; the first element read comes from field at offset 0. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: Allocate 4 * count + 4 bytes for the copy array via MallocWrapperForNhMalloc. [callee:0x0058A935, source:raw]
    // GUARD: If the allocation returned null, terminate the process via CRTAmsgExit(9). [callee:0x0058A2A6, source:raw]
    // LOOP: While the current source element is non-null, deep-copy it through StringAllocCopy into the destination and advance both the source element pointer and the destination pointer. [callee:0x00598600, field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write a null terminator after the last copied entry. [source:raw]
    // RETURN: Return the base pointer of the newly allocated copied array. [source:raw]

    // Conservative worker pseudocode:
    //   int** NullTerminatedIntArrayCopyWithAlloc(int** src) {
    //     if (!src) return 0;
    //     int count = 0;
    //     int* p = (int*)src + 1;
    //     if (*src) { do { int cur = *p; ++count; ++p; } while (cur); }
    //     int** out = MallocWrapperForNhMalloc(4 * count + 4);
    //     if (!out) CRTAmsgExit(9);
    //     int** base = out;
    //     int** cur = src;
    //     while (*cur) { *out = StringAllocCopy(*cur); ++cur; ++out; }
    //     *out = 0;
    //     return base;
    //   }
    // UNRESOLVED: Structure of the objects returned by StringAllocCopy is unknown; only the containing null-terminated array is reconstructed.
    // UNRESOLVED: Meaning of the CRTAmsgExit(9) exit code 9 is unresolved.
    // UNRESOLVED: The field offsets 0 and 4 are the first two int slots of the walked array, but their per-entry semantics are caller-defined.
}
