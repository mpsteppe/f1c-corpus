// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3130
// Canonical corpus name: MultiFieldCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldCleanup_004c3130.c

void UnknownObject::MultiFieldCleanup()
{
    // Destructor-style cleanup that releases every pointer field on the object. First walks and frees a singly linked list whose head is stored at this+0x3D4: for each node it frees the payload at node+0x8, calls ShortComputation_4370 on the node, then frees the node itself, advancing via the next pointer at node+0x10. Afterwards it individually null-guards and frees the fields at this+0x3D8, this+0x3CC, this+0x20, this+0x18, this+0x10, this+0x8, and this+0x0.
    // GUARD: Guard: enter the list cleanup only if the head pointer at this+0x3D4 is non-null. [field:this:0x000003D4, source:raw]
    // LOOP: do-while walk over the linked list, reading the next node pointer at node+0x10 to advance and to terminate the loop when it becomes null. [field:*(this+0x3D4):0x00000010, source:raw]
    // GUARD: Guard: the current node pointer is null-checked before being touched. [source:raw]
    // GUARD: Guard: the node payload pointer at node+0x8 is freed only if non-null. [field:*(this+0x3D4):0x00000008, source:raw]
    // CALL: Call FreeWrapper_7bcf on the node payload at node+0x8 to deallocate it. [callee:0x00587BCF, field:*(this+0x3D4):0x00000008, source:raw]
    // CALL: Call ShortComputation_4370 on the current list node to release its internal resources. [callee:0x00414370, source:raw]
    // CALL: Call FreeWrapper_7bcf on the current list node to deallocate the node itself. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Advance the list head at this+0x3D4 to the next node (saved before the node was freed). [field:this:0x000003D4, field:*(this+0x3D4):0x00000010, source:raw]
    // GUARD: Guard: the pointer field at this+0x3D8 is freed only if non-null. [field:this:0x000003D8, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x3D8. [callee:0x00587BCF, field:this:0x000003D8, source:raw]
    // GUARD: Guard: the pointer field at this+0x3CC is freed only if non-null. [field:this:0x000003CC, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x3CC. [callee:0x00587BCF, field:this:0x000003CC, source:raw]
    // GUARD: Guard: the pointer field at this+0x20 is freed only if non-null. [field:this:0x00000020, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x20. [callee:0x00587BCF, field:this:0x00000020, source:raw]
    // GUARD: Guard: the pointer field at this+0x18 is freed only if non-null. [field:this:0x00000018, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x18. [callee:0x00587BCF, field:this:0x00000018, source:raw]
    // GUARD: Guard: the pointer field at this+0x10 is freed only if non-null. [field:this:0x00000010, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x10. [callee:0x00587BCF, field:this:0x00000010, source:raw]
    // GUARD: Guard: the pointer field at this+0x8 is freed only if non-null. [field:this:0x00000008, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer field at this+0x8 and carry its return value as the result. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // GUARD: Guard: the primary pointer field at this+0x0 is freed only if non-null. [field:this:0x00000000, source:raw]
    // RETURN: Free the pointer field at this+0x0 and return its result, or return the earlier FreeWrapper_7bcf result when this+0x0 is null. [callee:0x00587BCF, field:this:0x00000000, function:0x004C3130, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C3130(void *this) {
    //     if (*(int*)((char*)this + 0x3D4)) {
    //       int next = *(int*)(*(int*)((char*)this + 0x3D4) + 0x10);
    //       do {
    //         LPVOID *node = *(LPVOID**)((char*)this + 0x3D4);
    //         if (node) { if (node[2]) FreeWrapper_7bcf(node[2]); ShortComputation_4370(node); FreeWrapper_7bcf(node); }
    //         *(int*)((char*)this + 0x3D4) = next;
    //       } while (next);
    //     }
    //     if (*(int*)((char*)this + 0x3D8)) FreeWrapper_7bcf(*(void**)((char*)this + 0x3D8));
    //     if (*(int*)((char*)this + 0x3CC)) FreeWrapper_7bcf(*(void**)((char*)this + 0x3CC));
    //     if (*(int*)((char*)this + 0x20)) FreeWrapper_7bcf(*(void**)((char*)this + 0x20));
    //     if (*(int*)((char*)this + 0x18)) FreeWrapper_7bcf(*(void**)((char*)this + 0x18));
    //     if (*(int*)((char*)this + 0x10)) FreeWrapper_7bcf(*(void**)((char*)this + 0x10));
    //     int r = *(int*)((char*)this + 0x8);
    //     if (r) r = FreeWrapper_7bcf(*(void**)((char*)this + 0x8));
    //     void *p = *(void**)this;
    //     if (p) return FreeWrapper_7bcf(p);
    //     return r;
    //   }
    // UNRESOLVED: Owner object identity is unknown; callers sub_4C2FC0, VehicleFileLoader, and VehicleDataLoader all invoke this cleanup but its containing type is not established.
    // UNRESOLVED: Semantics of ShortComputation_4370 (what the per-node release does) are not recoverable from this function alone.
    // UNRESOLVED: Meaning of the freed pointer fields (payload, node, and the seven direct fields) depends on the owner class layout.
}
