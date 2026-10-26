// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545850
// Canonical corpus name: ClearBuffersLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClearBuffersLoop_00545850.c

void UnknownObject::ClearBuffersLoop()
{
    // Walks two linked lists of scene-graph nodes and clears a scene-graph flag on every node. The first walk follows the node chain starting at this+0x100 via each node's +0x104 forward link, descending into each node's sub-node list (head at +0xEC) via its +0x4C forward links. The second walk follows the chain starting at this+0x108 via +0x4C forward links. Every visited node gets BitmaskClear(0, 32, 0) followed by SceneGraphFlagPropagation(0, 0x10000000, 0); the last propagation result is returned.
    // LOOP: First list walk: iterate from the list head at this+0x100, following each node's +0x104 forward link while non-null. [field:this:0x00000100, field:*(this+0x204):0x00000104]
    // LOOP: Inner sub-node walk: for each node from the first list, iterate from its sub-node list head at +0xEC, following each sub-node's +0x4C forward link while non-null. [field:*(this+0x204):0x000000EC, field:*(*(*(this+0x204)+0xEC)+0x4C):0x0000004C]
    // CALL: Per inner sub-node: call BitmaskClear(0, 32, 0) to clear a 32-bit bitmask. [callee:0x0054B330]
    // CALL: Per inner sub-node: call SceneGraphFlagPropagation(0, 0x10000000, 0) to clear scene-graph flag 0x10000000; its result is stored and eventually returned. [callee:0x0054B2C0]
    // LOOP: Second list walk: iterate from the list head at this+0x108, following each node's +0x4C forward link while non-null. [field:this:0x00000108, field:*(this+0x154):0x0000004C]
    // CALL: Per node in the second list: call BitmaskClear(0, 32, 0) to clear a 32-bit bitmask. [callee:0x0054B330]
    // CALL: Per node in the second list: call SceneGraphFlagPropagation(0, 0x10000000, 0) to clear scene-graph flag 0x10000000; its result is stored. [callee:0x0054B2C0]
    // RETURN: Return the result of the last SceneGraphFlagPropagation call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_545850(_DWORD* this) {
    //     int result;
    //     for (int i = this[64]; i; i = *(int*)(i + 0x104)) {
    //       for (int j = *(int*)(i + 0xEC); j; j = *(int*)(j + 0x4C)) {
    //         BitmaskClear(0, 32, 0);
    //         result = SceneGraphFlagPropagation(0, 0x10000000, 0);
    //       }
    //     }
    //     for (int k = this[66]; k; k = *(int*)(k + 0x4C)) {
    //       BitmaskClear(0, 32, 0);
    //       result = SceneGraphFlagPropagation(0, 0x10000000, 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Node and sub-node object types are unnamed; this+0x100 and this+0x108 are treated as list heads on a container whose identity is unknown.
    // UNRESOLVED: Semantics of the cleared flag 0x10000000 and the constants passed to BitmaskClear are not established.
}
