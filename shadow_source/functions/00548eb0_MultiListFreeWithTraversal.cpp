// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548EB0
// Canonical corpus name: MultiListFreeWithTraversal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiListFreeWithTraversal_00548eb0.c

void UnknownObject::MultiListFreeWithTraversal()
{
    // Frees five linked lists rooted in the object: this[58], this[60], this[62] and this[63] (byte offsets 232, 240, 248 and 252) are traversed through a next pointer at node byte offset 20 and every node released via EmptyStub_0170 plus FreeWrapper_7bcf; the root at this[59] (byte offset 236) is traversed through a next pointer at node byte offset 76 and released via sub_549110. After each list is drained the root pointer is written back to 0. The five read-only fields at byte offsets 268, 272, 292 and 312 listed in the packet are not touched by this function.
    // GUARD: If the first list root at field this+0xE8 is non-null, enter its release path. [field:this:0x000000E8, source:raw]
    // LOOP: Traverse the first list following the next pointer stored at node byte offset 20 (node index 5). [field:this:0x000000E8, source:raw]
    // CALL: For the first list, call EmptyStub_0170 and then FreeWrapper_7bcf on every node, including the final node, to release it. [callee:0x004B0170, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Write 0 back to the first list root at field this+0xE8. [field:this:0x000000E8, source:raw]
    // GUARD: If the second list root at field this+0xF0 is non-null, enter its release path. [field:this:0x000000F0, source:raw]
    // LOOP: Traverse the second list following the next pointer stored at node byte offset 52 (node index 13). [field:this:0x000000F0, source:raw]
    // CALL: For the second list, call EmptyStub_0170 and then FreeWrapper_7bcf on every node, including the final node, to release it. [callee:0x004B0170, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Write 0 back to the second list root at field this+0xF0. [field:this:0x000000F0, source:raw]
    // GUARD: If the third list root at field this+0xF8 is non-null, enter its release path. [field:this:0x000000F8, source:raw]
    // LOOP: Traverse the third list following the next pointer stored at node byte offset 20 (node index 5). [field:this:0x000000F8, source:raw]
    // CALL: For the third list, call EmptyStub_0170 and then FreeWrapper_7bcf on every node, including the final node, to release it. [callee:0x004B0170, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Write 0 back to the third list root at field this+0xF8. [field:this:0x000000F8, source:raw]
    // GUARD: If the fourth list root at field this+0xFC is non-null, enter its release path. [field:this:0x000000FC, source:raw]
    // LOOP: Traverse the fourth list following the next pointer stored at node byte offset 20 (node index 5). [field:this:0x000000FC, source:raw]
    // CALL: For the fourth list, call EmptyStub_0170 and then FreeWrapper_7bcf on every node, including the final node, to release it. [callee:0x004B0170, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Write 0 back to the fourth list root at field this+0xFC. [field:this:0x000000FC, source:raw]
    // GUARD: If the fifth list root at field this+0xEC is non-null, enter its release path. [field:this:0x000000EC, source:raw]
    // LOOP: Traverse the fifth list following the next pointer stored at node byte offset 76. [field:this:0x000000EC, source:raw]
    // CALL: For the fifth list, call sub_549110 on every node, including the final node, to release it. [callee:0x00549110, source:raw]
    // ASSIGNMENT: Write 0 back to the fifth list root at field this+0xEC. [field:this:0x000000EC, source:raw]

    // Conservative worker pseudocode:
    //   void sub_548EB0(_DWORD* this) {
    //     _DWORD* p = (_DWORD*)this[58];
    //     while (p) { _DWORD* next = (_DWORD*)p[5]; EmptyStub_0170(); FreeWrapper_7bcf(p); p = next; }
    //     this[58] = 0;
    //     p = (_DWORD*)this[60];
    //     while (p) { _DWORD* next = (_DWORD*)p[13]; EmptyStub_0170(); FreeWrapper_7bcf(p); p = next; }
    //     this[60] = 0;
    //     p = (_DWORD*)this[62];
    //     while (p) { _DWORD* next = (_DWORD*)p[5]; EmptyStub_0170(); FreeWrapper_7bcf(p); p = next; }
    //     this[62] = 0;
    //     p = (_DWORD*)this[63];
    //     while (p) { _DWORD* next = (_DWORD*)p[5]; EmptyStub_0170(); FreeWrapper_7bcf(p); p = next; }
    //     this[63] = 0;
    //     int q = this[59];
    //     while (q) { int next = *(int*)(q + 76); sub_549110(q); q = next; }
    //     this[59] = 0;
    //   }
    // UNRESOLVED: The read-only fields at byte offsets 268 (this+0x10C), 272 (this+0x110), 292 (this+0x124) and 312 (this+0x138) are listed in the packet but are not accessed by this function's raw source; their role is unresolved.
    // UNRESOLVED: The purpose of the EmptyStub_0170 no-op call before each FreeWrapper_7bcf is unexplained (debug or validation hook).
    // UNRESOLVED: The fifth list (this+0xEC) uses a different release routine (sub_549110) and a different next-pointer offset (76) than the other four lists; the allocation-scheme difference is unresolved.
    // UNRESOLVED: Node layouts (only next pointers at offsets 20 and 76 are observed) are otherwise unknown.
}
