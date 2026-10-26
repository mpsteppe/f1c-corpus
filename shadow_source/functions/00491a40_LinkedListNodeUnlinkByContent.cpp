// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491A40
// Canonical corpus name: LinkedListNodeUnlinkByContent
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeUnlinkByContent_00491a40.c

void UnknownObject::LinkedListNodeUnlinkByContent()
{
    // Unlinks a node whose content value matches the value held by the reference node at struct offset 16. Reads the tail/reference node, reparents its content with LinkedListNodePrepend, then walks the list rooted at *this + 12 comparing node values, relinks the matched node's predecessor/successor (updating the tail at +16 and the current marker at +20), decrements the count at +24, and frees the node (and its value when the +8 flags byte is set). Returns 1 when the reference node exists and the walk completes, 0 otherwise.
    // ASSIGNMENT: v2 = *this loads the struct base pointer; v3 = *(void***)(v2 + 16) reads the tail/reference node pointer. [field:this:0x00000000, field:obj:0x00000010, source:raw]
    // ASSIGNMENT: *((v2) + 20) = v3 copies the reference node into the current/tail marker at +20. [field:obj:0x00000014, source:raw]
    // GUARD: Proceed only when v3 is non-null and its content value *v3 is non-null. [field:*(obj+0x10):0x00000000, source:raw]
    // CALL: LinkedListNodePrepend(*v3) reparents the reference node's content into another list. [callee:0x00490AA0, source:raw]
    // LOOP: Walk the list at *(this) + 12 from the head: v7 = *(v2 + 12), then while *(void**)v7 != v5 (node value differs from the reference content) track predecessor v9 and advance v7 = *(v7 + 4); if the walk reaches null, return 1. [field:obj:0x0000000C, field:*(*(obj+0xC)+0x4):0x00000000, field:*(*(obj+0xC)+0x4):0x00000004, field:*(obj+0x10):0x00000000, source:raw]
    // ASSIGNMENT: If the matched node v7 is the tail (v8[2]), set v8[2] = *(v7 + 4) so the tail follows the unlinked node's successor. [field:obj:0x00000010, source:raw]
    // ASSIGNMENT: Relink around the matched node: v10 = *(v7 + 4); if a predecessor v9 exists set *(v9 + 4) = v10, else set the head *v8 = v10; if the current marker v8[1] == v7 set v8[1] = v9. [field:*(obj+0xC):0x00000004, field:obj:0x0000000C, field:obj:0x00000014, source:raw]
    // STATE_TRANSITION: Decrement the node count --v8[3]. [field:obj:0x00000018, source:raw]
    // CALL: If the matched node's +8 flags byte is set and its value *v7 is non-null, FreeWrapper_7bcf(*v7) frees the value. [field:*(*(obj+0xC)+0x4):0x00000008, callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf(v7) frees the unlinked node itself. [callee:0x00587BCF, source:raw]
    // RETURN: Returns 1 when the reference node exists (both when a matching node was unlinked and when the walk ended without a match); returns 0 when the reference node or its content was null. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_491A40(int* this) {
    //     int base = *this;
    //     void** ref = *(void***)(base + 16);
    //     *(DWORD*)(base + 20) = ref;
    //     if (ref) {
    //       void* content = *ref;
    //       if (content) {
    //         LinkedListNodePrepend(*ref);
    //         int v7 = *(DWORD*)(*this + 12);
    //         DWORD* list = (DWORD*)(*this + 12);
    //         int prev = 0;
    //         if (v7) {
    //           while (*(void**)v7 != content) { prev = v7; v7 = *(DWORD*)(v7 + 4); if (!v7) return 1; }
    //           if (v7 == list[2]) list[2] = *(DWORD*)(v7 + 4);
    //           int next = *(DWORD*)(v7 + 4);
    //           if (prev) *(DWORD*)(prev + 4) = next; else *list = next;
    //           if (list[1] == v7) list[1] = prev;
    //           --list[3];
    //           if (*(BYTE*)(v7 + 8) && *(DWORD*)v7) FreeWrapper_7bcf(*(LPVOID*)v7);
    //           FreeWrapper_7bcf((LPVOID)v7);
    //         }
    //         return 1;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact role of the +8 flags byte (when set it gates freeing the node's value) is inferred from the free guard, not externally confirmed.
    // UNRESOLVED: The identity of the list that receives the reparented content via LinkedListNodePrepend is unknown.
    // UNRESOLVED: The distinct second-node field evidence refs (value / next / flags at *(*(obj+0xC)+0x4)) describe the node the walk lands on; the IDB resolved them to that node path.
    // UNRESOLVED: Recorded caller sub_496E90 (00496e90); frame-path membership is NOT_FOUND.
}
