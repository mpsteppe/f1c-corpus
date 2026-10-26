// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448DE0
// Canonical corpus name: PhysicsTreeMassPropagation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsTreeMassPropagation_00448de0.c

void UnknownObject::PhysicsTreeMassPropagation()
{
    // Propagates a mass-related double across a collision-tree chain. For each node, blends the stored double at this+0x10 halfway toward the value at this+0x4 using the 0.5 constant (dbl_59E880), then iterates four consecutive child-pointer slots starting at this+0x4C recursing into every non-null child, and finally follows the sibling link at this+0x5C until it is null. Called by CollisionContactResponse (00449700).
    // CALCULATION: Blend toward the target: *(this+0x10) = (*(this+0x4) + *(this+0x10)) * 0.5, where 0.5 is the read-only double constant at dbl_59E880 [field:this:0x00000004, field:this:0x00000010, global:0x0059E880, source:raw]
    // LOOP: Inner loop: walk the four consecutive child-pointer slots beginning at this+0x4C (cursor v2, count v3=4) [field:this:0x0000004C, source:raw]
    // GUARD: For each non-null child slot, recursively call PhysicsTreeMassPropagation on that child [callee:0x00448DE0, field:this:0x0000004C, source:raw]
    // LOOP: Outer loop: advance this to the sibling node at this+0x5C and repeat while the sibling link is non-null [field:this:0x0000005C, source:raw]
    // RETURN: Return the result of the last child recursion once the sibling chain terminates [function:0x00448DE0, source:raw]
    // CALL: Invoked by CollisionContactResponse (00449700) during collision handling [caller:0x00449700, source:raw]

    // Conservative worker pseudocode:
    //   do {
    //     v2 = (int*)(this + 76);
    //     v3 = 4;
    //     *(double*)(this + 16) = (*(double*)(this + 4) + *(double*)(this + 16)) * 0.5;
    //     do {
    //       if (*v2) result = PhysicsTreeMassPropagation();
    //       ++v2; --v3;
    //     } while (v3);
    //     this = *(int*)(this + 92);
    //   } while (this);
    //   return result;
    // UNRESOLVED: The owner class is unknown; the tree-node shape is only visible structurally
    // UNRESOLVED: The recursive call in the raw decompilation shows no argument, so the exact child argument passed to the recursion (the child pointer from this+0x4C) is inferred rather than proven
    // UNRESOLVED: The physical meaning of the blended double (mass vs. a related collision property) and why children are visited before the sibling link are not determinable from this packet
}
