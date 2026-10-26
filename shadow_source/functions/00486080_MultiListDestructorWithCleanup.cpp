// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486080
// Canonical corpus name: MultiListDestructorWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiListDestructorWithCleanup_00486080.c

void UnknownObject::MultiListDestructorWithCleanup()
{
    // Destructor-style cleanup of several heterogeneous container lists on one object (this-call, no return value). Walks and frees four singly-linked node lists whose heads live at this+0xCC, this+0xD0, this+0xD4 and this+0xD8, each node freed with DualConditionalFree followed by FreeWrapper_7bcf and advanced via node[6]. Then drains a singly-linked list of vtable objects headed at this+0x90: each iteration stores StructFieldAccessor(head) back into this+0x90 and invokes the first vtable entry on the object with a single argument of 1 (release/shutdown); the head is then zeroed. Finally walks a list of owned-data nodes headed at this+0x54: reads the node's data pointer and a byte flag at node+8 and a next pointer at node+4, frees owned data chains via FreeWrapper_7bcf when the flag is set, frees each node, and zeroes this+0x54 through this+0x60. Called by sub_485EB0.
    // LOOP: Walk the DualConditionalFree-managed node list headed at this+0xCC, advancing through the next pointer at node[6]. [field:this:0x000000CC, field:this:0x000000FC]
    // CALL: Free each node of the this+0xCC list: DualConditionalFree(node) then FreeWrapper_7bcf(node). [callee:0x0049A5A0, callee:0x00587BCF, field:this:0x000000CC]
    // LOOP: Walk the DualConditionalFree-managed node list headed at this+0xD0, advancing through the next pointer at node[6]. [field:this:0x000000D0, field:this:0x00000100]
    // CALL: Free each node of the this+0xD0 list: DualConditionalFree(node) then FreeWrapper_7bcf(node). [callee:0x0049A5A0, callee:0x00587BCF, field:this:0x000000D0]
    // LOOP: Walk the DualConditionalFree-managed node list headed at this+0xD4, advancing through the next pointer at node[6]. [field:this:0x000000D4, field:this:0x00000104]
    // CALL: Free each node of the this+0xD4 list: DualConditionalFree(node) then FreeWrapper_7bcf(node). [callee:0x0049A5A0, callee:0x00587BCF, field:this:0x000000D4]
    // LOOP: Walk the DualConditionalFree-managed node list headed at this+0xD8, advancing through the next pointer at node[6]. [field:this:0x000000D8, field:this:0x00000108]
    // CALL: Free each node of the this+0xD8 list: DualConditionalFree(node) then FreeWrapper_7bcf(node). [callee:0x0049A5A0, callee:0x00587BCF, field:this:0x000000D8]
    // LOOP: Drain the vtable-object list headed at this+0x90; iterate while the head is non-null. [field:this:0x00000090]
    // CALL: Advance the list by calling StructFieldAccessor(head) and writing the result back into this+0x90. [callee:0x00486320, field:this:0x00000090]
    // CALL: Invoke the first vtable entry of the object (field *(this+0x90) offset 0x0) as a __thiscall with a single argument of 1. [field:*(this+0x90):0x00000000, field:this:0x00000090]
    // ASSIGNMENT: Zero the vtable-object list head this+0x90 after the drain. [field:this:0x00000090]
    // LOOP: Walk the owned-data node list headed at this+0x54, reading the node data pointer (field *(this+0x54) offset 0x0), a byte flag at node+8, and the next pointer at node+4 (field *(this+0x58) offset 0x4). [field:this:0x00000054, field:*(this+0x54):0x00000000, field:*(this+0x58):0x00000004]
    // GUARD: If the node's flag byte is non-zero, free the owned data chain: free *data and the data wrapper with FreeWrapper_7bcf when the pointer chain is non-null. [callee:0x00587BCF, field:*(this+0x54):0x00000000]
    // CALL: Free each owned-data node itself with FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000054]
    // ASSIGNMENT: Zero the four owned-data list fields this+0x54, this+0x58, this+0x5C, this+0x60 after the walk. [field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060]

    // Conservative worker pseudocode:
    //   void sub_486080(_DWORD *this) {
    //     for (_DWORD *n = (_DWORD *)this[51]; n; n = (_DWORD *)n[6]) { DualConditionalFree(n); FreeWrapper_7bcf(n); }
    //     for (_DWORD *n = (_DWORD *)this[52]; n; n = (_DWORD *)n[6]) { DualConditionalFree(n); FreeWrapper_7bcf(n); }
    //     for (_DWORD *n = (_DWORD *)this[53]; n; n = (_DWORD *)n[6]) { DualConditionalFree(n); FreeWrapper_7bcf(n); }
    //     for (_DWORD *n = (_DWORD *)this[54]; n; n = (_DWORD *)n[6]) { DualConditionalFree(n); FreeWrapper_7bcf(n); }
    //     while (this[36]) { this[36] = StructFieldAccessor(this[36]); (**(void (__thiscall ***)(_DWORD,int))this[36])(this[36], 1); }
    //     this[36] = 0;
    //     for (int v11 = this[21]; v11; v11 = *(_DWORD *)(v11 + 4)) {
    //       LPVOID **v12 = (LPVOID **)v11;
    //       char v13 = *(_BYTE *)(v11 + 8);
    //       if (v13) { LPVOID *v14 = *v12; if (*v12) { if (*v14) FreeWrapper_7bcf(*v14); FreeWrapper_7bcf(v14); } }
    //       FreeWrapper_7bcf(v12);
    //     }
    //     this[21] = 0; this[22] = 0; this[23] = 0; this[24] = 0;
    //   }
    // UNRESOLVED: Identity of the owning class is unknown; it is only known that sub_485EB0 calls this function.
    // UNRESOLVED: Semantics of node[6] as the next pointer rest on decompiler field attribution (evidence refs on base this); the true node layout is not independently confirmed.
    // UNRESOLVED: The first vtable call passes an integer argument of 1; whether this is a Release, Shutdown or other lifecycle call is not stated by the packet.
    // UNRESOLVED: Whether this is a true destructor or a partial cleanup helper is not stated by the packet.
}
