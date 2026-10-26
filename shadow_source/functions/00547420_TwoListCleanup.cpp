// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547420
// Canonical corpus name: TwoListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoListCleanup_00547420.c

void UnknownObject::TwoListCleanup()
{
    // Resource-manager bulk cleanup of two independently owned linked lists. First list rooted at this[9] (offset 0x24): walks nodes via the next pointer at node index 48, and for each node calls ArrayCleanupWithDualFree on the pointer at node +188 (0xBC), optionally calls EmptyStub_7470 and frees node[47] (0xBC) when it is non-null, then clears node[47]; after the walk the trailing node is passed to ArrayCleanupWithDualFree, EmptyStub_7470 and FreeWrapper_7bcf. Second list rooted at this[11] (offset 0x2C): walks nodes via the next pointer at +20, and for each node calls SingleFieldFree and frees the pointer at +16 when non-null; after the walk the trailing node is freed with SingleFieldFree then FreeWrapper_7bcf. Returns 0. Each list cleanup is guarded on its root being non-null.
    // ASSIGNMENT: Load first-list root v2 = this[9] (offset 0x24). [source:raw, field:this:0x00000024]
    // GUARD: Guard: first list is cleaned only if v2 is non-null. [source:raw]
    // LOOP: Walk first list: i = node next pointer at v2[48] (node offset 0xC0); the loop advances to that pointer each iteration. [source:raw]
    // CALL: For each node, call ArrayCleanupWithDualFree on the pointer at node +188. [source:raw, callee:0x00546370]
    // ASSIGNMENT: v4 = node[47] (offset 0xBC) payload pointer. [source:raw]
    // GUARD: Guard: call EmptyStub_7470 and free the payload only when node[47] is non-null. [source:raw]
    // CALL: Call EmptyStub_7470 on node[47] and FreeWrapper_7bcf on v4. [source:raw, callee:0x00557470, callee:0x00587BCF]
    // ASSIGNMENT: Clear node[47] to 0 after cleanup. [source:raw]
    // CALL: After the walk, call ArrayCleanupWithDualFree(v2), EmptyStub_7470(v2) and FreeWrapper_7bcf(v2) on the trailing node. [source:raw, callee:0x00546370, callee:0x00557470, callee:0x00587BCF]
    // ASSIGNMENT: Load second-list root v5 = this[11] (offset 0x2C). [source:raw, field:this:0x0000002C]
    // GUARD: Guard: second list is cleaned only if v5 is non-null. [source:raw]
    // LOOP: Walk second list: j = next pointer at v5 + 20; the loop advances to that pointer each iteration. [source:raw]
    // ASSIGNMENT: v7 = pointer at node +16. [source:raw]
    // GUARD: Guard: call SingleFieldFree and free the +16 pointer only when v7 is non-null. [source:raw]
    // CALL: Call SingleFieldFree on the node +16 pointer and FreeWrapper_7bcf on v7. [source:raw, callee:0x0053AB70, callee:0x00587BCF]
    // CALL: After the walk, free the trailing node: SingleFieldFree(v5) then FreeWrapper_7bcf(v5). [source:raw, callee:0x0053AB70, callee:0x00587BCF]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_547420(_DWORD *this) {
    //     _DWORD *a = (_DWORD*)this[9];
    //     if (a) {
    //       for (int i = a[48]; i; i = a[48]) { a = (_DWORD*)i; ArrayCleanupWithDualFree(*(_DWORD**)(i + 188)); void *p = (void*)a[47]; if (p) { EmptyStub_7470(a[47]); FreeWrapper_7bcf(p); } a[47] = 0; }
    //       ArrayCleanupWithDualFree(a); EmptyStub_7470(a); FreeWrapper_7bcf(a);
    //     }
    //     int b = this[11];
    //     if (b) {
    //       for (int j = *(int*)(b + 20); j; j = *(int*)(b + 20)) { b = j; void *p = *(void**)(j + 16); if (p) { SingleFieldFree(*(LPVOID**)(j + 16)); FreeWrapper_7bcf(p); } }
    //       SingleFieldFree((LPVOID*)b); FreeWrapper_7bcf((LPVOID)b);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Packet fields this+0x40, *(this+0x40)+0x10, this+0xE4 and this+0x1A0 are listed in the evidence but do not appear in the visible raw source; their roles could not be mapped to an operation.
    // UNRESOLVED: The class owning the two lists and the payload types cleaned by SingleFieldFree / ArrayCleanupWithDualFree are unknown.
    // UNRESOLVED: EmptyStub_7470 is a stub; its real cleanup behavior (if any) is unconfirmed.
}
