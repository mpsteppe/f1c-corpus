// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494DE0
// Canonical corpus name: CollisionNodeAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNodeAllocator_00494de0.c

void UnknownObject::CollisionNodeAllocator()
{
    // Allocates and appends a 12-byte collision linked-list node (data pointer at +0, next pointer at +4, flag byte at +8) to a global list. Calls sub_53CFE0 first as a duplicate/lookup guard and returns its result; only when it returns zero and the data pointer a1 is non-null does it allocate via OperatorNewNhMallocWrapper(12), initialize the node, and append it, updating the head (dword_7CDDF0), iterator (dword_7CDDF8), tail (dword_7CDDF4) and incrementing the counter dword_7CDDFC.
    // CALL: v1 = sub_53CFE0(&a1, a1, 67585) looks up an existing entry and returns non-zero when a duplicate exists, preventing a second allocation. [callee:0x0053CFE0]
    // GUARD: If v1 (the lookup result) is zero, proceed with node allocation; otherwise return v1 unchanged. [source:raw]
    // GUARD: If the data pointer a1 is non-null, allocate a new node; the empty-parameter case is skipped entirely. [source:raw]
    // CALL: v3 = OperatorNewNhMallocWrapper(12) allocates a 12-byte collision node. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the node: node[0] = a1 (data pointer), node[4] = 0 (next pointer), node[8] = 0 (flag byte); v3 is 0 when the allocation fails. [source:raw]
    // GUARD: If the list head dword_7CDDF0 is non-null, append the node to the tail by writing v3 into (dword_7CDDF4 + 4). [global:0x007CDDF0, global:0x007CDDF4]
    // ASSIGNMENT: Otherwise this is the first node: set head dword_7CDDF0 = v3 and iterator dword_7CDDF8 = v3. [global:0x007CDDF0, global:0x007CDDF8]
    // ASSIGNMENT: Update the tail pointer dword_7CDDF4 = v3 and increment the node counter dword_7CDDFC. [global:0x007CDDF4, global:0x007CDDFC]
    // RETURN: Return v1 (the sub_53CFE0 lookup result), which is zero when a node was appended and non-zero when a duplicate was found. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionNodeAllocator(int a1) {
    //     int v1 = sub_53CFE0(&a1, a1, 67585);
    //     if (!v1 && a1) {
    //       int v3 = OperatorNewNhMallocWrapper(12);
    //       if (v3) {
    //         *(int*)v3 = a1;
    //         *(int*)(v3 + 4) = 0;
    //         *(byte*)(v3 + 8) = 0;
    //       } else { v3 = 0; }
    //       if (dword_7CDDF0) { *(int*)(dword_7CDDF4 + 4) = v3; }
    //       else { dword_7CDDF0 = v3; dword_7CDDF8 = v3; }
    //       dword_7CDDF4 = v3;
    //       ++dword_7CDDFC;
    //     }
    //     return v1;
    //   }
    // UNRESOLVED: The roles of the four global list pointers (head/iterator/tail) are DERIVED names from legacy analysis; the exact list semantics are unproven.
    // UNRESOLVED: The constant 67585 passed to sub_53CFE0 is an opaque lookup key; its meaning is unknown.
    // UNRESOLVED: dword_8AFE64 appears only in legacy analysis as a race-time delta; it has no raw-source grounding in this function.
    // UNRESOLVED: The owner of the global collision list (dword_7CDDF0 region) is unknown.
}
