// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548D40
// Canonical corpus name: LinkedListNodeAppenderWithLazyAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeAppenderWithLazyAllocation_00548d40.c

void UnknownObject::LinkedListNodeAppenderWithLazyAllocation()
{
    // Appends a new node to a singly-linked list stored as head this[92] (offset 0x170). On the first append (head null) lazily allocates and installs the head; otherwise walks the chain through the next pointer at node offset 0x18 to the tail. A 28-byte node is allocated via OperatorNewNhMallocWrapper, initialized via ArithmeticComparison_8aa0, linked at the tail's next pointer (or stored as the new head), and populated via sub_548AD0(v6, a2, a3). A non-zero return from sub_548AD0 yields -1; on success the node counter this[91] (offset 0x16C) is incremented and 0 is returned.
    // ASSIGNMENT: v4 = this[92] (offset 0x170): read the list head pointer; selects the allocate-first path versus the walk-and-append path. [field:this:0x00000170, source:raw]
    // GUARD: If this[92] (offset 0x170) is non-zero the list already exists; otherwise this is the first append and the head must be lazily allocated. [field:this:0x00000170, source:raw]
    // LOOP: Walk the singly-linked list via the next pointer at node offset 0x18 until a zero next pointer (the tail) is reached. [field:*(*(this+0x188)+0x18):0x00000018, source:raw]
    // CALL: OperatorNewNhMallocWrapper(28): heap-allocate a 28-byte node. [callee:0x00587C03, source:raw]
    // CALL: ArithmeticComparison_8aa0(newNode): initialize the newly allocated 28-byte block as a list node. [callee:0x00548AA0, source:raw]
    // ASSIGNMENT: Link the new node: on an existing list set the tail's next pointer (offset 0x18) to the new node; on first append store it as the list head at this[92] (offset 0x170). [field:*(*(this+0x188)+0x18):0x00000018, field:this:0x00000170, source:raw]
    // GUARD: If OperatorNewNhMallocWrapper returns NULL, v6 and the head this[92] (offset 0x170) remain zero on the first-append path. [callee:0x00587C03, field:this:0x00000170, source:raw]
    // CALL: sub_548AD0(v6, a2, a3): populate the new node; a non-zero return aborts the append. [callee:0x00548AD0, source:raw]
    // RETURN: Return -1 when sub_548AD0 reported failure. [callee:0x00548AD0, source:raw]
    // CALCULATION: ++this[91] (offset 0x16C): increment the node counter on a successful append. [field:this:0x0000016C, source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_548D40(DWORD *this, int a2, int a3) {
    //     int v4 = this[92];
    //     if (v4) {
    //       for (int i = *(DWORD *)(v4 + 24); i; i = *(DWORD *)(i + 24)) v4 = i;
    //       DWORD *v8 = OperatorNewNhMallocWrapper(28);
    //       int *v6 = v8 ? ArithmeticComparison_8aa0(v8) : 0;
    //       *(DWORD *)(v4 + 24) = v6;
    //     } else {
    //       DWORD *v5 = OperatorNewNhMallocWrapper(28);
    //       if (v5) { this[92] = ArithmeticComparison_8aa0(v5); } else { this[92] = 0; }
    //     }
    //     if (sub_548AD0(v6, a2, a3)) return -1;
    //     ++this[91];
    //     return 0;
    //   }
    // UNRESOLVED: Field this:0x188 (container pointer) is listed as a read field but never referenced in the raw source text; its relationship to the list (base of the node next-pointer base expression) is unresolved.
    // UNRESOLVED: The owning object type and the meaning of a2/a3 passed to sub_548AD0 are unknown.
    // UNRESOLVED: Interpreting sub_548AD0's non-zero return as failure (yielding -1) is derived from the -1 return path, not confirmed.
}
