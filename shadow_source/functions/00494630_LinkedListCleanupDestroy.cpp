// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494630
// Canonical corpus name: LinkedListCleanupDestroy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListCleanupDestroy_00494630.c

void UnknownObject::LinkedListCleanupDestroy()
{
    // Destroys a singly-linked list anchored at dword_7CDDF0: iterates nodes while the head pointer is non-null, calls EmptyStub_7470 and frees the payload when the ownership flag byte at node+8 is non-zero, frees each node, then zeroes the four list globals dword_7CDDF0 through dword_7CDDFC.
    // ASSIGNMENT: List teardown entry (ABI tag LinkedListCleanupDestroy); the iteration starts from the anchored head dword_7CDDF0. [function:0x00494630, abi:lead, global:0x007CDDF0]
    // LOOP: for-loop over the linked list: iterate while the node pointer i (seeded from dword_7CDDF0) is non-null. [global:0x007CDDF0, source:raw]
    // ASSIGNMENT: Read current node into v1, capture the ownership flag v2 = (byte at node+8 == 0), then advance i to the next pointer at node+4. [source:raw]
    // GUARD: If the ownership flag byte at node+8 is non-zero: read payload v3 = *node; if the payload is non-null, call EmptyStub_7470(payload) then free it with FreeWrapper_7bcf. [callee:0x00557470, callee:0x00587BCF, source:raw]
    // CALL: Free each node with FreeWrapper_7bcf(v1) as the loop's iteration step. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list globals dword_7CDDF0, dword_7CDDF4, dword_7CDDF8 and dword_7CDDFC. [global:0x007CDDF0, global:0x007CDDF4, global:0x007CDDF8, global:0x007CDDFC, source:raw]
    // RETURN: Return the loop's final result value. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListCleanupDestroy() {
    //     int node = dword_7CDDF0;
    //     for (; node; node = *(int*)(node + 4)) {
    //       int payload = *(int*)node;
    //       bool owned = *(char*)(node + 8) != 0;
    //       if (owned && payload) {
    //         EmptyStub_7470(payload);
    //         FreeWrapper_7bcf(payload);
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     dword_7CDDF0 = 0; dword_7CDDF4 = 0;
    //     dword_7CDDF8 = 0; dword_7CDDFC = 0;
    //     return last_node;
    //   }
    // UNRESOLVED: Node layout (payload at node+0, next at node+4, ownership flag byte at node+8) is inferred from the raw source, not a named struct.
    // UNRESOLVED: What dword_7CDDF4/7CDDF8/7CDDFC track (tail/counters per prior analysis) is unproven.
}
