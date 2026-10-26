// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2300
// Canonical corpus name: DualListDestructionWithDeepCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualListDestructionWithDeepCleanup_004c2300.c

void UnknownObject::DualListDestructionWithDeepCleanup()
{
    // Destroys two intrusive singly-linked lists stored in this. List A (head at this[0]): walks nodes (next pointer at node+4), and for each node whose byte flag at node+8 is non-zero it runs PitStopMemoryCleanup on the payload (node+0) and frees the payload with FreeWrapper_7bcf, then always frees the node. List B (head at this[4]): walks nodes (next at node+4); for each node with a non-zero flag it frees the nested allocations of the payload (payload+8 and payload+0), frees the payload object, then frees the node. Afterwards every dword of this from offset 0x0 through 0x8C is zeroed except this[27] (offset 0x6C), which is set to 1, and this[32] (offset 0x80), which receives the value of dword_7D0A24.
    // ASSIGNMENT: Load list-A head: v2 = this[0]. [field:this:0x00000000, source:raw]
    // LOOP: Iterate list A while the current node pointer v2 is non-zero. [source:raw]
    // ASSIGNMENT: Save the current node as v3 = v2. [source:raw]
    // GUARD: First-list deep-cleanup guard: when the node byte flag at obj+0x8 equals 0, skip the PitStopMemoryCleanup and payload free for this node. [guard:0, field:obj:0x00000008, source:raw]
    // ASSIGNMENT: Advance to the next node: v2 = *(_DWORD *)(node + 4). [field:*(obj+0x4):0x00000004, source:raw]
    // ASSIGNMENT: When the flag is non-zero, load the payload pointer v9 = *v3 (node+0). [field:obj:0x00000000, source:raw]
    // CALL: If the payload is non-null, run PitStopMemoryCleanup(payload). [callee:0x004C0B10, source:raw]
    // CALL: Free the list-A payload with FreeWrapper_7bcf(payload). [callee:0x00587BCF, source:raw]
    // CALL: Free the list-A node itself with FreeWrapper_7bcf(node). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Load list-B head: v5 = this[4]. [field:this:0x00000010, source:raw]
    // LOOP: Iterate list B while the current node pointer v5 is non-zero. [source:raw]
    // GUARD: Second-list deep-cleanup guard: when the node byte flag (extracted as base this, offset 0x18) equals 0, skip the nested cleanup for this node. [guard:1, field:*(this+0x10):0x00000008, source:raw]
    // ASSIGNMENT: Advance to the next node: v5 = *(_DWORD *)(node + 4). [field:*(this+0x14):0x00000004, source:raw]
    // ASSIGNMENT: Load the list-B payload pointer v7 = *v6 (node+0). [field:*(this+0x10):0x00000000, source:raw]
    // CALL: If the payload is non-null and payload+8 (payload[2]) is non-null, free payload[2] with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: If the payload is non-null and *payload is non-null, free *payload with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: Free the list-B payload object with FreeWrapper_7bcf(payload). [callee:0x00587BCF, source:raw]
    // CALL: Free the list-B node with FreeWrapper_7bcf(node). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero list-A metadata: this[0], this[1], this[2], this[3] (offsets 0x0 through 0xC). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero list-B metadata: this[4] through this[7] (offsets 0x10 through 0x1C). [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zero state block this[8] through this[26] (offsets 0x20 through 0x68). [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, source:raw]
    // ASSIGNMENT: Zero state block this[28] through this[31] (offsets 0x70 through 0x7C). [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Set the byte at this+0x6C (this[27]) to 1; this is the one non-zero field in the cleared block. [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Zero this[33], this[34], this[35] (offsets 0x84 through 0x8C) and store v8 = dword_7D0A24 into this[32] (offset 0x80), restoring a UI/option value. [field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000080, global:0x007D0A24, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C2300(_DWORD *this) {
    //     _DWORD *node = (_DWORD *)this[0];
    //     while (node) {
    //       int flag = *((_BYTE *)node + 8) == 0;
    //       _DWORD *next = (_DWORD *)node[1];
    //       if (!flag) {
    //         _DWORD *payload = (_DWORD *)node[0];
    //         if (payload) { PitStopMemoryCleanup(payload); FreeWrapper_7bcf(payload); }
    //       }
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     _DWORD *node2 = (_DWORD *)this[4];
    //     while (node2) {
    //       int flag2 = *((_BYTE *)node2 + 8) == 0;
    //       _DWORD *next2 = (_DWORD *)node2[1];
    //       if (!flag2) {
    //         _DWORD *payload2 = (_DWORD *)node2[0];
    //         if (payload2) {
    //           if (payload2[2]) FreeWrapper_7bcf(payload2[2]);
    //           if (payload2[0]) FreeWrapper_7bcf(payload2[0]);
    //           FreeWrapper_7bcf(payload2);
    //         }
    //       }
    //       FreeWrapper_7bcf(node2);
    //       node2 = next2;
    //     }
    //     for (int i = 8; i <= 26; ++i) this[i] = 0;
    //     for (int i = 28; i <= 31; ++i) this[i] = 0;
    //     *((_BYTE *)this + 108) = 1;
    //     int v8 = dword_7D0A24;
    //     this[33] = 0; this[34] = 0; this[35] = 0;
    //     this[32] = v8;
    //   }
    // UNRESOLVED: The field bases *(this+0x10) and *(this+0x14) are IDB extraction labels for the second list's node payload/next accesses; the two list heads may be aliased across iterations.
    // UNRESOLVED: dword_7D0A24 (0x007D0A24) is read and stored to this[32] as a restored value; its meaning is unknown.
    // UNRESOLVED: The byte set at this+0x6C is a validity/ready flag (init literal 1) whose semantics are not otherwise evidenced.
    // UNRESOLVED: FreeWrapper_7bcf and PitStopMemoryCleanup are callees without further packet evidence; freeing is assumed to route through the CRT heap wrapper.
    // UNRESOLVED: this[27] (offset 0x6C) is the only dword index in the cleared range that is not zeroed.
}
