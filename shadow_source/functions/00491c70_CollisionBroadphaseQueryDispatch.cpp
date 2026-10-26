// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491C70
// Canonical corpus name: ShortComputation_1c70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1c70_00491c70.c

void UnknownObject::CollisionBroadphaseQueryDispatch()
{
    // Short dispatch routine: reads *this (offset 0x0) and forms a base pointer at *this + 12, allocates a resource-pool node via ResourcePoolNodeAllocDealloc(a2, a3, a4, a5), runs CollisionBroadphaseTraversal on the base pointer and the new node, prepends the node to a linked list via LinkedListNodePrepend, and returns the traversal result char. Structural twin of 00491CB0 (which uses a +28 base and sub_491280).
    // CALCULATION: v5 = *this + 12 (pointer field at offset 0x0 advanced by 12 bytes) [field:this:0x00000000, source:raw]
    // CALL: Allocate a node: v6 = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5) [callee:0x00490940, source:raw]
    // CALL: Run v7 = CollisionBroadphaseTraversal(v5, v6) against the +12 base pointer and the new node [callee:0x00491170, source:raw]
    // CALL: Prepend the node: LinkedListNodePrepend(v6) [callee:0x00490AA0, source:raw]
    // RETURN: Return v7, the collision traversal result char [function:0x00491C70, source:raw]

    // Conservative worker pseudocode:
    //   v5 = *this + 12;
    //   v6 = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5);
    //   v7 = CollisionBroadphaseTraversal(v5, (int)v6);
    //   LinkedListNodePrepend(v6);
    //   return v7;
    // UNRESOLVED: The object at *this (offset 0x0) and the meaning of the +12 byte displacement are unidentified
    // UNRESOLVED: The a2..a5 arguments are opaque to this body; their semantics depend on the allocator contract
    // UNRESOLVED: Whether CollisionBroadphaseTraversal stores into or only reads the allocated node is not shown here
}
