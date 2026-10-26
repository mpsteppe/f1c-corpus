// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491BD0
// Canonical corpus name: SubListWalkDestruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubListWalkDestruction_00491bd0.c

void UnknownObject::SubListWalkDestruction()
{
    // Destroys an embedded linked list rooted at *this + 12. First reparents each node's value by prepending it to another list (LinkedListNodePrepend), walking the current marker at +20 and following +4 next pointers until the value becomes null. Then walks the list a second time freeing every node with FreeWrapper_7bcf, conditionally freeing each node's value when its +8 flags byte is set and the value pointer is non-null. Finally zeros the four DWORD list sentinels at offsets 12, 16, 20 and 24 (head, tail, current marker, count).
    // ASSIGNMENT: v2 = *this loads the struct base; v3 = *(void***)(*this + 12) reads the embedded sub-list head; result = v2 + 12. [field:this:0x00000000, field:obj:0x0000000C, source:raw]
    // ASSIGNMENT: *((v2) + 20) = v3 sets the current marker at +20 to the sub-list head. [field:obj:0x00000014, source:raw]
    // GUARD: Proceed to the reparent walk only when the head v3 and its first value *v3 are both non-null. [field:*(obj+0xC):0x00000000, source:raw]
    // LOOP: Reparent walk: do { LinkedListNodePrepend(v5); if (current = *(v2+20)) *(v2+20) = *(current+4); v5 = *(*(v2+12)+8); } while (*result); each node's value is prepended to another list before the marker advances. [callee:0x00490AA0, field:*(obj+0x14):0x00000000, field:*(obj+0x14):0x00000004, field:*(obj+0xC):0x00000000, source:raw]
    // LOOP: Destruction walk: v9 = *(v8+12); for (i = v8+12; v9; result = FreeWrapper_7bcf(v11)) { v11 = v9; v12 = *(v9+8); v9 = *(v9+4); if (v12 && *v11) FreeWrapper_7bcf(*v11); } frees each node in turn. [callee:0x00587BCF, field:*(*(obj+0xC)+0x4):0x00000004, field:*(obj+0xC):0x00000008, field:obj:0x0000000C, source:raw]
    // CALL: FreeWrapper_7bcf(*v11) frees the node's value when the +8 flags byte is set and the value is non-null. [callee:0x00587BCF, field:*(obj+0xC):0x00000008, source:raw]
    // ASSIGNMENT: Zero the four DWORD list sentinels after destruction: *i = 0 (head), i[1] = 0 (tail), i[2] = 0 (current), i[3] = 0 (count). [field:obj:0x0000000C, field:obj:0x00000010, field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // RETURN: Returns the last value of result (the null that terminated the destruction walk). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_491BD0(int* this) {
    //     int base = *this;
    //     void** head = *(void***)(base + 12);
    //     *(DWORD*)(base + 20) = head;
    //     if (head) {
    //       void* val = *head;
    //       if (val) {
    //         do {
    //           LinkedListNodePrepend(val);
    //           int cur = *(DWORD*)(*this + 20);
    //           if (cur) *(DWORD*)(*this + 20) = *(DWORD*)(cur + 4);
    //           result = *(DWORD*)(*this + 20);
    //           if (!result) break;
    //           val = *(void**)result;
    //         } while (*(DWORD*)result);
    //       }
    //     }
    //     int node = *(DWORD*)(*this + 12);
    //     for (DWORD* list = (DWORD*)(*this + 12); node; result = FreeWrapper_7bcf(v11)) {
    //       v11 = (LPVOID*)node;
    //       char flags = *(BYTE*)(node + 8);
    //       node = *(DWORD*)(node + 4);
    //       if (flags && *v11) FreeWrapper_7bcf(*v11);
    //     }
    //     *list = 0; list[1] = 0; list[2] = 0; list[3] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The destination list receiving the reparented values via LinkedListNodePrepend is not identified.
    // UNRESOLVED: The +8 flags byte semantics (value-ownership marker gating the value free) are inferred from the free guard, not externally confirmed.
    // UNRESOLVED: The meaning of the returned result value and whether callers observe it is unknown.
    // UNRESOLVED: Recorded caller sub_496E90 (00496e90); frame-path membership is NOT_FOUND.
}
