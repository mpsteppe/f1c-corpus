// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491CB0
// Canonical corpus name: ShortComputation_1cb0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1cb0_00491cb0.c

void UnknownObject::CollisionQueryDispatch()
{
    // Short dispatch routine: reads *this (offset 0x0) and forms a base pointer at *this + 28, allocates a resource-pool node via ResourcePoolNodeAllocDealloc(a2, a3, a4, a5), dispatches sub_491280 with the base pointer and the new node, prepends the node to a linked list via LinkedListNodePrepend, and returns the dispatch result char. Structural twin of 00491C70 (which uses a +12 base and CollisionBroadphaseTraversal).
    // CALCULATION: v5 = *this + 28 (pointer field at offset 0x0 advanced by 28 bytes) [field:this:0x00000000, source:raw]
    // CALL: Allocate a node: v6 = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5) [callee:0x00490940, source:raw]
    // CALL: Dispatch v7 = sub_491280(v5, v6) against the +28 base pointer and the new node [callee:0x00491280, source:raw]
    // CALL: Prepend the node: LinkedListNodePrepend(v6) [callee:0x00490AA0, source:raw]
    // RETURN: Return v7, the dispatch result char [function:0x00491CB0, source:raw]

    // Conservative worker pseudocode:
    //   v5 = *this + 28;
    //   v6 = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5);
    //   v7 = sub_491280(v5, (int)v6);
    //   LinkedListNodePrepend(v6);
    //   return v7;
    // UNRESOLVED: The object at *this (offset 0x0) and the meaning of the +28 byte displacement are unidentified
    // UNRESOLVED: The identity and contract of sub_491280 are not established by this body
    // UNRESOLVED: The a2..a5 arguments are opaque to this body; their semantics depend on the allocator contract
}
