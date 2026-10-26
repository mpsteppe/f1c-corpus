// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005511A0
// Canonical corpus name: ObjectDestructorWithArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectDestructorWithArrayCleanup_005511a0.c

void UnknownObject::ObjectDestructorWithArrayCleanup()
{
    // Object-and-array destructor: frees the single allocated object stored at this+0x0 (through the EmptyStub/FreeWrapper free pair), zeroes the pointer, then destroys a counted array of 136-byte elements whose base is stored at this+0x18 and whose element count is read from the header word at base-4. Array elements are destroyed in reverse order via EmptyStub_7470, the whole buffer is freed via FreeWrapper_7bcf, and the this+0x18 pointer is zeroed.
    // GUARD: Guard on this+0x0 (v2 = *this) being non-null before the single-object free path. [field:this:0x00000000, source:raw]
    // CALL: Call EmptyStub_7470(*this) on the single object before freeing it. [callee:0x00557470, field:this:0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf(v2) to deallocate the single object. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero this+0x0 after the single-object free. [field:this:0x00000000, source:raw]
    // GUARD: Guard on v3 = this[6] (this+0x18) being non-null before the array cleanup; when null the array path is skipped. [field:this:0x00000018, source:raw]
    // CALCULATION: Read the element count v4 = *(v3 - 4) from the header located 4 bytes before the array buffer; compute end pointer v6 = v3 + 136 * v4 and countdown v7 = v4 - 1. [field:this:0x00000018, source:raw]
    // LOOP: Reverse iteration over the array: step v6 backward by 136 bytes per element and call EmptyStub_7470 on each element, looping v4 times. [callee:0x00557470, field:this:0x00000018, source:raw]
    // CALL: Call FreeWrapper_7bcf(v5) on the array buffer header (base-4) to deallocate the whole array. [callee:0x00587BCF, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero this[6] (this+0x18) after the array free. [field:this:0x00000018, source:raw]
    // CALL: Call EmptyStub_0170 at function end (stub call present in the raw source but absent from the callee evidence table). [source:raw]
    // CALL: Called by QueueResourceCleanup (0x0054C410) to tear down a queued resource object and its element array. [caller:0x0054C410, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5511A0(void **this) {
    //     void *obj = this[0];
    //     if (obj) { EmptyStub_7470(obj); FreeWrapper_7bcf(obj); }
    //     this[0] = 0;
    //     char *arr = this[6];
    //     if (arr) {
    //       int n = *(int *)(arr - 4);
    //       char *p = arr + 136 * n;
    //       for (int i = n; i > 0; i--) { p -= 136; EmptyStub_7470(p); }
    //       FreeWrapper_7bcf(arr - 4);
    //     }
    //     this[6] = 0;
    //     EmptyStub_0170();
    //   }
    // UNRESOLVED: EmptyStub_0170 is called in the raw source but has no callee evidence entry or address in the packet; its purpose is unknown.
    // UNRESOLVED: The array allocation header layout (element count at buffer-4) is read directly and is not a declared packet field.
    // UNRESOLVED: The type and meaning of the 136-byte array elements are unknown.
}
