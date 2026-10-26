// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BC00
// Canonical corpus name: sub_55BC00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55BC00_0055bc00.c

void UnknownObject::ListNodeAllocOrDuplicateCheck()
{
    // Linked-list node management: searches the list whose head is this[72] (this+0x120) for a node whose four fields (node[2], node[3], node[5], node[6]) match the arguments a2..a5; a match returns -3 as a duplicate marker. Otherwise a 36-byte node is allocated via OperatorNewNhMallocWrapper(36), initialized by SmallStructInit_baf0, appended to the tail (or installed as the new head), and populated by F_6FieldStructSetter with the caller's six arguments plus a stride value v15 selected by a switch on a4 (6/5 -> 16, 7 -> 24, default 32 unless a4==8 which keeps a5). The node counter this[71] (this+0x11C) is incremented and 0 is returned. Called from sub_53DB90 (0x0053DB90).
    // ASSIGNMENT: Read the linked-list head from this[72] (this+0x120) into v6. [field:this:0x00000120, source:raw]
    // GUARD: Walk the list only when the head v6 is non-null and its next pointer (node[8]) is non-null; otherwise jump to the append path. [field:this:0x00000120, field:this:0x00000140, source:raw]
    // LOOP: Traverse the list following node next pointers (node[8], evidenced as this+0x140), comparing node[2] (this+0x128) with a2, node[3] (this+0x12C) with a3, node[5] (this+0x134) with a4 and node[6] (this+0x138) with a5. [field:this:0x00000140, field:this:0x00000128, field:this:0x0000012C, field:this:0x00000134, field:this:0x00000138, source:raw]
    // RETURN: Return -3 when a node matching all four keys a2..a5 is found (duplicate entry). [source:raw]
    // LOOP: Append path: walk to the tail node by following node next pointers (node[8]) until the last node is reached. [field:this:0x00000140, source:raw]
    // CALL: Allocate a 36-byte node via OperatorNewNhMallocWrapper(36). [callee:0x00587C03, source:raw]
    // CALL: Initialize the new node with SmallStructInit_baf0; the init zeroes node fields including the status field evidenced as this+0x19C (init literal 0). [callee:0x0055BAF0, field:this:0x0000019C, source:raw]
    // ASSIGNMENT: Append: link the old tail's next pointer (node[8]) to the new node and set the new node's back pointer (node[7], evidenced as this+0x180) to the old tail. [field:this:0x00000180, source:raw]
    // ASSIGNMENT: First-node path: install the new node as the list head this[72] (this+0x120) and zero its back pointer (node[7]). [field:this:0x00000120, field:this:0x00000180, source:raw]
    // ASSIGNMENT: Allocation-failure path: reset the head this[72] (this+0x120) to 0 and zero an unknown MEMORY[0x1C] location. [field:this:0x00000120, source:raw]
    // CALCULATION: Select v15 by switch on a4: a4==6 or a4==5 yields 16, a4==7 yields 24, otherwise 32 unless a4==8 which leaves v15 equal to a5. [source:raw]
    // CALL: Call F_6FieldStructSetter(newNode, this[71] (this+0x11C), a2, a3, v15, a4, a5) to populate the node's six fields. [callee:0x0055BB20, field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Increment the node counter this[71] (this+0x11C). [field:this:0x0000011C, source:raw]
    // RETURN: Return 0 on successful append. [source:raw]
    // CALL: Invoked by sub_53DB90 (0x0053DB90). [caller:0x0053DB90, source:raw]

    // Conservative worker pseudocode:
    //   int ListNodeAllocOrDuplicateCheck(int* this, int a2, int a3, int a4, int a5) {
    //     v6 = this[72];
    //     if (v6 && v6[8]) {
    //       v7 = v6;
    //       while (v7[2] != a2 || v7[3] != a3 || v7[5] != a4 || v7[6] != a5) {
    //         v7 = v7[8];
    //         if (!v7[8]) goto append;
    //       }
    //       return -3;
    //     }
    //   append:
    //     if (v6) {
    //       while (v6[8]) v6 = v6[8];
    //       node = OperatorNewNhMallocWrapper(36);
    //       node = node ? SmallStructInit_baf0(node) : 0;
    //       v6[8] = node;
    //       node[7] = v6;
    //     } else {
    //       node = OperatorNewNhMallocWrapper(36);
    //       if (node) { node = SmallStructInit_baf0(node); this[72] = node; node[7] = 0; }
    //       else { this[72] = 0; }
    //     }
    //     switch (a4) { case 6: case 5: v15 = 16; break; case 7: v15 = 24; break;
    //       default: v15 = 32; if (a4 != 8) v15 = a5; }
    //     F_6FieldStructSetter(node, this[71], a2, a3, v15, a4, a5);
    //     ++this[71];
    //     return 0;
    //   }
    // UNRESOLVED: The write *(v16 + 32) = 0 uses v16 which the decompiler leaves uninitialized; its destination is not evidenced in the packet.
    // UNRESOLVED: The MEMORY[0x1C] = 0 write in the allocation-failure path references a location whose identity is not evidenced in the packet.
    // UNRESOLVED: The comparison keys a2..a5 and the stride value v15 are call-supplied; their semantic meaning (key/value fields of the node) is not established by the packet alone.
    // UNRESOLVED: The packet presents the node fields [2],[3],[5],[6],[7],[8] as this-relative offsets 0x128..0x140 and 0x180, but the node object is heap-allocated; the exact node-layout mapping is not confirmed by the packet alone.
}
