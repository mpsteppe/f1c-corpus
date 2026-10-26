// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546370
// Canonical corpus name: ArrayCleanupWithDualFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayCleanupWithDualFree_00546370.c

void UnknownObject::ArrayCleanupWithDualFree()
{
    // Array cleanup: when this+0xA8 (array block pointer) is non-null, frees per-element resources, then frees the whole block. For each of this+0xA4 elements (stride 148 bytes): if element+76 is non-null it is freed via FreeWrapper_7bcf; if element+144 is non-null, EmptyStub_7470 is called on it first and then it is freed. The block carries a count prefix at array_ptr-4; every 148-byte slot is visited backwards via EmptyStub_7470, then FreeWrapper_7bcf frees the block starting at array_ptr-4. Finally this+0xA8 is nulled and 0 is returned.
    // GUARD: Outer guard: entire cleanup runs only when this+0xA8 (array block pointer) is non-null. [field:this:0x000000A8, function:0x00546370, source:raw]
    // GUARD: Per-element guard: guard:0 checks this+0xA4 (element count) > 0 before running the element loop. [guard:0, field:this:0x000000A4, function:0x00546370, source:raw]
    // LOOP: do-while loop over this+0xA4 elements, walking the array with 148-byte stride. [field:this:0x000000A4, function:0x00546370, source:raw]
    // GUARD: For each element, guard on element+76 being non-null before freeing it. [function:0x00546370, source:raw]
    // CALL: Free element+76 via FreeWrapper_7bcf when it is non-null. [callee:0x00587BCF, function:0x00546370, source:raw]
    // GUARD: For each element, guard on element+144 being non-null before teardown. [function:0x00546370, source:raw]
    // CALL: Call EmptyStub_7470 on element+144 as a per-element teardown step. [callee:0x00557470, function:0x00546370, source:raw]
    // CALL: Free element+144 via FreeWrapper_7bcf after the stub call. [callee:0x00587BCF, function:0x00546370, source:raw]
    // CALCULATION: Advance element base by the 148-byte stride each iteration. [function:0x00546370, source:raw]
    // CALCULATION: Read the element count from the allocator header at array_ptr-4 and compute the end pointer array_ptr + 148 * count. [field:this:0x000000A8, function:0x00546370, source:raw]
    // LOOP: Backward loop over the block: call EmptyStub_7470 on each 148-byte slot from the last down to the first. [callee:0x00557470, function:0x00546370, source:raw]
    // CALL: Free the whole block via FreeWrapper_7bcf starting at array_ptr-4 (header plus slots). [callee:0x00587BCF, function:0x00546370, source:raw]
    // ASSIGNMENT: Null this+0xA8 (array block pointer) once cleanup finishes. [field:this:0x000000A8, function:0x00546370, source:raw]
    // RETURN: Return 0. [function:0x00546370, source:raw]

    // Conservative worker pseudocode:
    //   int sub_546370(_DWORD* this) {
    //     if (!this[42]) return 0;
    //     if (this[41] > 0) {
    //       for (int i = 0, p = 0; i < this[41]; ++i, p += 148) {
    //         if (*(_DWORD*)(p + this[42] + 76))
    //           FreeWrapper_7bcf(*(LPVOID*)(p + this[42] + 76));
    //         void* s = *(void**)(p + this[42] + 144);
    //         if (s) { EmptyStub_7470((int)s); FreeWrapper_7bcf(s); }
    //       }
    //     }
    //     if (this[42]) {
    //       int count = *(_DWORD*)(this[42] - 4);
    //       int end = this[42] + 148 * count;
    //       if (count - 1 >= 0)
    //         do { end -= 148; EmptyStub_7470(end); } while (--count);
    //       FreeWrapper_7bcf((void*)(this[42] - 4));
    //     }
    //     this[42] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Internal layout of a 148-byte element (meaning of element+76 and element+144) is unknown.
    // UNRESOLVED: EmptyStub_7470's actual behavior is unknown from the packet; it is called before each element/block free.
    // UNRESOLVED: The count prefix at array_ptr-4 implies a custom allocator that records element count; its identity is unknown.
    // UNRESOLVED: Object owning fields this+0xA4 and this+0xA8 is unknown; owner kept UNKNOWN.
}
