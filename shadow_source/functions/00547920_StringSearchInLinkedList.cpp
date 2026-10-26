// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547920
// Canonical corpus name: StringSearchInLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringSearchInLinkedList_00547920.c

void UnknownObject::StringSearchInLinkedList()
{
    // Searches a linked list of strings (head at this[10], i.e. this+0x28) for the key a2, returning the matching node pointer or 0. Copies and normalizes the key via sub_589901 and records via StringDotFinder whether the key carries a dot extension. For single-string nodes (count at node+76 == 1) compares node+4; for multi-entry nodes (count > 1) iterates 96-byte-stride sub-entries. Each candidate string is normalized with sub_589901 (and StringDotFinder when the key has a dot) before a strcmp against the normalized key. Node chain is followed through the next pointer at node+92.
    // CALL: Copy the search key a2 into the local SrcStr buffer with strcpy, then normalize it via sub_589901. [source:raw, callee:0x00589901]
    // CALCULATION: v14 = (StringDotFinder(SrcStr) != 0): record whether the normalized key contains a dot extension. [source:raw, callee:0x00547AF0]
    // GUARD: Load the linked-list head from this[10] (this+0x28); if null, return 0 immediately. [field:this:0x00000028]
    // LOOP: Traverse the node chain by following the next-node pointer at node+92 (field:*(this+0x84)+0x5C) until it is null. [field:*(this+0x84):0x0000005C]
    // GUARD: Read the entry count at node+76 (field:*(this+0x84)+0x4C); if count == 1 take the single-string comparison path, otherwise break to the multi-entry path. [field:*(this+0x84):0x0000004C]
    // LOOP: Single-entry path: copy the string at node+4 (field:*(this+0x84)+0x4) into the local buffer, normalize with sub_589901, and if v14 apply StringDotFinder. [field:*(this+0x84):0x00000004, callee:0x00589901, callee:0x00547AF0]
    // GUARD: If strcmp(normalized candidate, SrcStr) == 0, return the current node pointer. [source:raw]
    // LOOP: Multi-entry path: iterate the 96-byte-stride sub-entries starting at node+4, normalizing each string with sub_589901 (and StringDotFinder when v14), returning node + 96*v8 on a match. [field:*(this+0x84):0x00000004, callee:0x00589901, callee:0x00547AF0]
    // RETURN: Return 0 when the chain ends (next pointer at node+92 is null) or the sub-entry count is exhausted. [field:*(this+0x84):0x0000005C]

    // Conservative worker pseudocode:
    //   strcpy(SrcStr, a2); sub_589901(SrcStr);
    //   has_dot = StringDotFinder(SrcStr) != 0;
    //   for (node = this->head /* this[10] * /; node; node = node->next /* node+92 * /) {
    //       count = node->count;                                // node+76
    //       if (count == 1) {
    //           copy_node_string(v15, node + 4); sub_589901(v15);
    //           if (has_dot) StringDotFinder(v15);
    //           if (strcmp(v15, SrcStr) == 0) return node;
    //       } else {
    //           for (i = 0; i < count; i++) {                   // 96-byte stride
    //               copy_subentry_string(v15, node + 4 + 96*i);
    //               sub_589901(v15);
    //               if (has_dot) StringDotFinder(v15);
    //               if (strcmp(v15, SrcStr) == 0) return node + 96*i;
    //           }
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: Packet fields this+0x2C, this+0x74, and this+0x84 are listed but no explicit dereference of them appears in the raw body; the field extractor attributes the node layout to base *(this+0x84). No direct role asserted.
    // UNRESOLVED: The 96-byte stride of the multi-entry sub-array is an in-source constant not backed by a packet field evidence ref.
}
