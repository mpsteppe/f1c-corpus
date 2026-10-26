// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB150
// Canonical corpus name: ListAppendWithSubListGeneration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListAppendWithSubListGeneration_004bb150.c

void UnknownObject::ListAppendWithSubListGeneration()
{
    // Appends a caller-supplied payload (a2) as a 12-byte node to a first linked list managed by this, then generates a parallel sub-list of 32 or 64 nodes whose data values are the first dword of a2 plus a 12-byte stride. Both lists share the head/tail/cursor/count layout: list 1 at this+0x0/+0x4/+0x8/+0xC and list 2 at this+0x10/+0x14/+0x18/+0x1C. All node allocation goes through OperatorNewNhMallocWrapper.
    // GUARD: List-1 append only runs when a2 is non-null; a 12-byte node is allocated for the entry [source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates the list-1 node; on allocation failure v5 is forced to 0 [callee:0x00587C03, source:raw]
    // ASSIGNMENT: List-1 node initialized: data = a2 (offset 0), next = 0 (offset 4), flag byte = 1 (offset 8) [source:raw]
    // GUARD: List-1 append: when the head at this+0x0 is non-null the old tail (this+0x4) is linked to the new node; otherwise the head (this+0x0) and the cursor reference (this+0x8) are set to the new node [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Tail (this+0x4) set to the new node and the list-1 count at this+0xC incremented [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALCULATION: Sub-list data value v7 = v6 + *a2, where v6 walks the node memory in 12-byte steps from 0 and *a2 is re-read each iteration; iteration count is 64 when a3 is non-zero, otherwise 32 [source:raw]
    // GUARD: A sub-list node is only allocated when the computed data value v7 is non-zero [source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates each sub-list node; initialized with data = v7, next = 0, flag byte = 0 [callee:0x00587C03, source:raw]
    // GUARD: List-2 append: when the tail at this+0x10 is non-null the new node is linked to it; otherwise the head (this+0x14) and the cursor reference (this+0x18) are set to the new node [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Tail (this+0x10) set to the new sub-list node and the list-2 count at this+0x1C incremented [field:this:0x00000010, field:this:0x0000001C, source:raw]
    // LOOP: Iterate the sub-list generation 32 or 64 times, advancing v6 by 12 and breaking when the remaining counter reaches 0 [source:raw]
    // RETURN: Return the exhausted loop counter (0 after the final iteration) [function:0x004BB150, source:raw]
    // CALL: Invoked by CarPhysicsStateInitializer (004B57F0) and sub_4B7860 to seed the per-car list structure [caller:0x004B57F0, caller:0x004B7860, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 != 0) {
    //     node = OperatorNewNhMallocWrapper(12);
    //     if (node) { node->data = a2; node->next = 0; node->flag = 1; }
    //     if (*(this+0x0)) *(this+0x4)->next = node;  /* old tail linked * /
    //     else { *(this+0x0) = node; *(this+0x8) = node; }  /* head + cursor * /
    //     *(this+0x4) = node;  /* tail * /
    //     ++*(this+0xC);  /* count * /
    //   }
    //   n = (a3 != 0) ? 64 : 32;
    //   for (v6 = 0; ; v6 += 12) {
    //     data = v6 + *a2;
    //     if (data != 0) {
    //       node = OperatorNewNhMallocWrapper(12);
    //       if (node) { node->data = data; node->next = 0; node->flag = 0; }
    //       if (*(this+0x10)) node->next = *(this+0x10);  /* old tail linked * /
    //       else { *(this+0x14) = node; *(this+0x18) = node; }  /* head + cursor * /
    //       *(this+0x10) = node;  /* tail * /
    //       ++*(this+0x1C);  /* count * /
    //     }
    //     if (--n == 0) break;
    //   }
    //   return 0;
    // UNRESOLVED: The semantic meaning of the generated sub-list (data = base + 12*i, 32 vs 64 entries chosen by a3) is not documented in this function
    // UNRESOLVED: The role of the cursor reference written at this+0x8 and this+0x18 (set only when the respective list was empty) is not documented
    // UNRESOLVED: Node flag byte semantics (1 for list-1 entries, 0 for sub-list entries) are inferred from the initializer literals only
    // UNRESOLVED: Whether a2 is a single node whose first dword is a base pointer, or the head of an array of node pointers, is unresolved
}
