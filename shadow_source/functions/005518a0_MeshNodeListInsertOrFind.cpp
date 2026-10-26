// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005518A0
// Canonical corpus name: sub_5518A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5518A0_005518a0.c

void UnknownObject::MeshNodeListInsertOrFind()
{
    // Loads mesh/resource data into a freshly allocated 52-byte node by name, then inserts it into a linked list owned by the caller. If force-insert is requested or the list is empty the node is appended to the tail; otherwise the list is walked by name string and, on a match, the new node is discarded and the existing node returned. Returns 0 on insert, -2 on duplicate found, -1 on load failure.
    // ASSIGNMENT: Allocate a 52-byte node via OperatorNewNhMallocWrapper and initialize it with a unit-vector default via StructZeroInitWithUnitVector; allocation failure yields a null node pointer. [callee:0x00587C03, callee:0x00550870]
    // GUARD: If sub_5508A0(node, a3) returns non-zero the mesh load failed and the failure path is taken. [callee:0x005508A0]
    // CALL: Load the resource named by a3 into the new node via sub_5508A0; a non-zero return signals load failure. [callee:0x005508A0]
    // CALL: On load failure, invoke EmptyStub_7470 on the node then FreeWrapper_7bcf to release its memory, null *a2, and return -1. [callee:0x00557470, callee:0x00587BCF]
    // RETURN: Return -1 when the mesh load failed (out-parameter set to null). [source:raw]
    // GUARD: Insert path is taken when the low bit of flag a4 is set (force insert) or when the list head at this+0x118 is null. [field:this:0x00000118]
    // CALCULATION: Append operation: if the head at this+0x118 is non-null, walk next pointers at node+0x30 to the tail and link the new node there; otherwise set this+0x118 to the new node. [field:this:0x00000118, field:*(*(this+0x148)+0x30):0x00000030]
    // ASSIGNMENT: Link the new node: node[11] (previous) = prior tail, node[12] (next) = 0, and output the new node via *a2; the function returns 0 on success. [source:raw]
    // RETURN: Return 0 when the node was inserted into the list. [source:raw]
    // LOOP: Deduplication walk: compare the node name string (node+28) with strcmp, advancing through next pointers at node+48 until a name match or the end of the list; hitting the end falls through to the append path. [source:raw]
    // CALL: On a name match, call CallWrapperReturning0, free the newly allocated duplicate via EmptyStub_7470 and FreeWrapper_7bcf, output the existing node via *a2, and return -2. [callee:0x00550AC0, callee:0x00557470, callee:0x00587BCF]
    // RETURN: Return -2 when a duplicate-name node already existed (the existing node is reused). [source:raw]

    // Conservative worker pseudocode:
    //   void *node = StructZeroInitWithUnitVector(OperatorNewNhMallocWrapper(52));
    //   if (!node) node = 0;
    //   if (sub_5508A0(node, a3)) {
    //       if (node) { EmptyStub_7470(node); FreeWrapper_7bcf(node); }
    //       if (a2) *a2 = 0;
    //       return -1;
    //   }
    //   int prev = 0;
    //   if ((a4 & 1) != 0 || (prev = this[70]) == 0) goto append;
    //   int cur = this[70];
    //   while (strcmp((char *)cur + 28, (char *)node + 28)) {
    //       cur = *(int *)(cur + 48);
    //       if (!cur) goto append;
    //   }
    //   CallWrapperReturning0();
    //   if (node) { EmptyStub_7470(node); FreeWrapper_7bcf(node); }
    //   if (a2) *a2 = cur;
    //   return -2;
    //   append: {
    //       int head = this[70];
    //       if (head) {
    //           int last = head;
    //           for (int n = *(int *)(last + 48); n; n = *(int *)(n + 48)) last = n;
    //           *(int *)(last + 48) = node;
    //           prev = last;
    //       } else {
    //           this[70] = node;
    //       }
    //       ((int *)node)[11] = prev;
    //       ((int *)node)[12] = 0;
    //       if (a2) *a2 = node;
    //       return 0;
    //   }
    // UNRESOLVED: Deterministic field facts record a deep traversal path through this+0x148 (fields 0x30 at two levels). The pseudocode walks the head list at this+0x118 directly; the relationship between the two lists is not established.
    // UNRESOLVED: The purpose of EmptyStub_7470 (called before every free) and the meaning of flag a4 beyond its low force-insert bit are unknown.
    // UNRESOLVED: The node type loaded by sub_5508A0 and the meaning of the name string stored at node+28 are unknown.
}
