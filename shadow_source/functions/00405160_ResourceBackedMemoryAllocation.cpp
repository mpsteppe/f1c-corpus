// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405160
// Canonical corpus name: MemoryAllocation_5160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_5160_00405160.c

void UnknownObject::ResourceBackedMemoryAllocation()
{
    // Resource-backed allocation/reallocation router. Maps the mode parameter a3 (0, 1, or 2) to an internal flag v4, then looks up the resource node by ID through the resource manager singleton (with linked-list fallbacks) to obtain a base size and offset. Finally calls sub_58C724 with mode-dependent size arguments and normalizes its result: a non-1 return is decremented by the base size before being returned.
    // GUARD: Map the mode parameter a3 to internal flag v4: 0 -> 0, 1 -> 1, 2 -> 2; any other value maps to 0. [source:raw]
    // CALL: Ensure the static resource-manager singleton is initialized via OneTimeInitializationWithAtexitStyleRegistration. [callee:0x00404FE0, source:raw]
    // CALL: Look up the resource node by string or numeric ID via ResourceNodeLookupByStringOrID(singleton, 0, a1). [callee:0x00407E40, source:raw]
    // ASSIGNMENT: On a hit, read the node's size from offset +40 into a3 and its offset from offset +36 into v11. [source:raw]
    // CALL: On a node-lookup miss, search the linked list by ID via LinkedListSearchByID(a1); if not found, fall through to sub_58C724(a1, a2, v4) immediately. [callee:0x00407FB0, source:raw]
    // CALL: On a linked-list miss, perform the ID operation lookup LinkedListNodeSearchByIDOperation(a1, &a3, &v11) that outputs size and offset; if it fails, return sub_58C724(a1, a2, v4) directly. [callee:0x00408050, source:raw]
    // GUARD: Mode 2 with a2 == 0 takes a dedicated path: sub_58C724(a1, size + offset, 0). [source:raw]
    // CALL: Perform the allocation with mode-adjusted parameters through sub_58C724: mode 1 uses raw a2; mode 0 adds the node size to a2; mode 2 with a2 == 0 uses size plus offset. [callee:0x0058C724, source:raw]
    // RETURN: Return the sub_58C724 result when it is 1; otherwise return the result minus the node base size. [source:raw]

    // Conservative worker pseudocode:
    //   int MemoryAllocation_5160(int a1, LONG a2, int a3) {
    //     int v4 = (a3 >= 1 && a3 <= 2) ? a3 : 0;
    //     int v11 = 0;
    //     int a3 = 0;
    //     void *mgr = OneTimeInitializationWithAtexitStyleRegistration();
    //     int node = ResourceNodeLookupByStringOrID(mgr, 0, a1);
    //     if (node) {
    //       a3 = *(int*)(node + 40);
    //       v11 = *(int*)(node + 36);
    //     } else {
    //       OneTimeInitializationWithAtexitStyleRegistration();
    //       if (!LinkedListSearchByID(a1)) return sub_58C724(a1, a2, v4);
    //       OneTimeInitializationWithAtexitStyleRegistration();
    //       if (!LinkedListNodeSearchByIDOperation(a1, &a3, &v11)) return sub_58C724(a1, a2, v4);
    //     }
    //     int r;
    //     if (v4 == 2 && !a2) r = sub_58C724(a1, a3 + v11, 0);
    //     else if (v4 == 1) r = sub_58C724(a1, a2, 1);
    //     else r = sub_58C724(a1, a2 + a3, 0);
    //     return (r == 1) ? r : r - a3;
    //   }
    // UNRESOLVED: Semantics of sub_58C724's return value (1 as the success sentinel, and why the returned value is decremented by the node size) are not grounded by the raw source.
    // UNRESOLVED: The meaning of the node fields at offsets +36 and +40 is DERIVED from allocation usage, not proven.
    // UNRESOLVED: The special mode-2/a2==0 path and its interaction with the caller's allocation intent are not fully explained.
    // UNRESOLVED: The resource manager singleton handle passed to the lookup and the string-vs-ID interpretation of a1 are outside this function's evidence.
}
