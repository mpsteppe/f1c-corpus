// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2A00
// Canonical corpus name: SceneGraphChildVelocityScaling
// Owner: SceneGraphNode [GUESS]
// Raw source: functions/SceneGraphChildVelocityScaling_004e2a00.c

void SceneGraphNode::SceneGraphChildVelocityScaling()
{
    // Scales two per-child floats at +244 and +248 by factor a2 across the children of a scene-graph node, then optionally climbs the parent chain (parent pointer at +76) and repeats while the node is non-null. Child enumeration uses SceneGraphChildCount and LinkedListIndexedAccessor_c230.
    // CALL: Call SceneGraphChildCount(node) to obtain the number of children; the count is stored as v5 and also as the return value when no child accessor runs. [callee:0x0054C210, source:raw]
    // LOOP: Iterate i from 0 to v5-1, fetching each child node via LinkedListIndexedAccessor_c230(i) for the current node's children. [callee:0x0054C230, source:raw]
    // CALCULATION: Scale the float at child +244 by a2 (child[+244] = a2 * child[+244]) for each child. [source:raw]
    // CALCULATION: Scale the float at child +248 by a2 (child[+248] = a2 * child[+248]) for each child, performed as the loop increment on the last accessed child. [source:raw]
    // GUARD: If a3 is zero, break out of the outer loop after processing the current node's children (no parent-chain climb). [source:raw]
    // GUARD: If a3 is non-zero, read the parent pointer at node +76 (0x4C) and repeat the child-scaling loop for the parent; the outer do-while continues while the parent pointer is non-null, climbing toward the root. [field:this:0x0000004C, source:raw]
    // RETURN: Return the last value held in result, which is either the child count of the last processed node or the last child node returned by LinkedListIndexedAccessor_c230; no caller-visible contract for it is evidenced. [abi:lead, function:0x004E2A00, source:raw]

    // Conservative worker pseudocode:
    //   node = a1;
    //   do {
    //     child_count = SceneGraphChildCount(node);
    //     for (i = 0; i < child_count; i++) {
    //       child = LinkedListIndexedAccessor_c230(i);
    //       *(float *)(child + 244) = a2 * *(float *)(child + 244);
    //       *(float *)(child + 248) = a2 * *(float *)(child + 248);
    //     }
    //     if (!a3) break;
    //     node = *(_DWORD *)(node + 76);
    //   } while (node);
    //   return result;
    // UNRESOLVED: The exact meaning of the scaled floats at +244 and +248 (presumed velocity components) rests on the DERIVED canonical name only; the packet provides no field evidence for those offsets.
    // UNRESOLVED: Return value is an incidental byproduct (child count or last accessed child) and no consuming contract is evidenced.
    // UNRESOLVED: Whether the parent pointer at +76 can be invalid for some nodes (making the climb end early) is not evidenced; the loop simply terminates on a null pointer.
}
