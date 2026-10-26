// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544EF0
// Canonical corpus name: SceneGraphTreeDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneGraphTreeDestructor_00544ef0.c

void UnknownObject::SceneGraphTreeDestructor()
{
    // Recursive scene-graph tree destructor. Unconditionally recurses into the child node at a1+0x1B0 when non-null, recurses into the child node at a1+0x1B8 only when both a1+0x1AC and a1+0x1B8 are non-null, then removes a1 from its doubly linked list via DoublyLinkedListNodeRemoval_5090, invokes two cleanup stubs, and frees a1 with FreeWrapper_7bcf. Called by ResourceCleanupDestructionForDirectXObjects (00543BF0) as part of render-side teardown.
    // GUARD: If the child node pointer at a1+0x1B0 is non-null, recursively call SceneGraphTreeDestructor on it [field:this:0x000001B0, callee:0x00544EF0, source:raw]
    // GUARD: If both a1+0x1AC and a1+0x1B8 are non-null, recursively call SceneGraphTreeDestructor on the child at a1+0x1B8 [field:this:0x000001AC, field:this:0x000001B8, callee:0x00544EF0, source:raw]
    // CALL: Invoke the EmptyStub_0170 cleanup stub with no arguments [callee:0x004B0170, source:raw]
    // CALL: Remove the node from its doubly linked list via DoublyLinkedListNodeRemoval_5090(a1) [callee:0x00545090, source:raw]
    // CALL: Invoke the EmptyStub_7470 cleanup stub with a1 as its argument [callee:0x00557470, source:raw]
    // CALL: Free the node memory via FreeWrapper_7bcf(a1) [callee:0x00587BCF, source:raw]
    // RETURN: Return 0 after teardown [function:0x00544EF0, source:raw]
    // CALL: Invoked by ResourceCleanupDestructionForDirectXObjects (00543BF0) during render resource destruction [caller:0x00543BF0, source:raw]

    // Conservative worker pseudocode:
    //   if (a1[108]) SceneGraphTreeDestructor(a1[108]);
    //   if (a1[107] && a1[110]) SceneGraphTreeDestructor(a1[110]);
    //   EmptyStub_0170();
    //   DoublyLinkedListNodeRemoval_5090(a1);
    //   EmptyStub_7470(a1);
    //   FreeWrapper_7bcf(a1);
    //   return 0;
    // UNRESOLVED: The owner class is unknown; the node layout (child slots at 0x1B0 and 0x1B8 plus a guard at 0x1AC, list links maintained by DoublyLinkedListNodeRemoval_5090) is only visible structurally
    // UNRESOLVED: Why the second child recursion is gated on a1+0x1AC while the first is not is not determinable from this packet
    // UNRESOLVED: The roles of EmptyStub_0170 and EmptyStub_7470 in the teardown sequence are not documented
}
