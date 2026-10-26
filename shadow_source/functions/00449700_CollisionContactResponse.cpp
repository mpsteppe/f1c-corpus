// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449700
// Canonical corpus name: CollisionContactResponse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionContactResponse_00449700.c

void UnknownObject::CollisionContactResponse()
{
    // Processes collision contact pairs after broad-phase detection. Traverses two collision tree roots (shadow volume extrusion), blends mass properties across each contact pair using the 0.5 factor from global 0x0059E880, propagates the blended mass through the physics tree, then performs weighted-average interpolation on each contact's vertex/node pairs.
    // GUARD: If this[3] (field this+0xC) is non-null, traverse the first collision tree via CollisionTreeTraversal. [field:this:0x0000000C, callee:0x00448DA0, source:raw]
    // GUARD: If this[4] (field this+0x10) is non-null, traverse the second collision tree via CollisionTreeTraversal. [field:this:0x00000010, callee:0x00448DA0, source:raw]
    // GUARD: Guard on contact pair count this[0] (field this+0x0) > 0; the pair-processing loops only run when at least one pair exists. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: First loop over the contact pair array at this[2] (field this+0x8), striding 32 bytes per pair. [field:this:0x00000008, source:raw]
    // CALCULATION: Blend mass between pair nodes: read the mass double at +16 of the two paired node objects, sum them and scale by 0.5 (global dbl_59E880), then store the blended value at the +4 offset of each node object. [global:0x0059E880, field:this:0x00000008, source:raw]
    // CALL: Propagate the blended mass values through the physics tree via PhysicsTreeMassPropagation on the second tree root this[4] (field this+0x10). [callee:0x00448DE0, field:this:0x00000010, source:raw]
    // LOOP: Second loop over the same contact pair array at this[2] (field this+0x8), again 32 bytes per pair. [field:this:0x00000008, source:raw]
    // CALL: For each pair call WeightedAverageInterpolation on three node triples (node at +4 blended with pair at +0/+8, node at +12 blended with +8/+16, node at +20 blended with +16/+0). [callee:0x00448480, field:this:0x00000008, source:raw]
    // RETURN: Return the contact pair count stored at this[0] (field this+0x0). [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionContactResponse(int *this) {
    //     if (this[3]) CollisionTreeTraversal(this[3]);
    //     if (this[4]) CollisionTreeTraversal(this[4]);
    //     for (int i = 0; i < *this; ++i) {
    //       char *pair = (char *)this[2] + 32 * i;
    //       *(double *)(*(int *)(pair + 4) + 4) = (*(double *)(*(int *)(pair + 16) + 16) + *(double *)(*(int *)(pair + 8) + 16)) * 0.5;
    //       *(double *)(*(int *)(pair + 12) + 4) = (*(double *)(*(int *)(pair + 16) + 16) + *(double *)(*(int *)(pair + 0) + 16)) * 0.5;
    //       *(double *)(*(int *)(pair + 20) + 4) = (*(double *)(*(int *)(pair + 16) + 16) + *(double *)(*(int *)(pair + 0) + 16)) * 0.5;
    //     }
    //     if (this[4]) PhysicsTreeMassPropagation(this[4]);
    //     for (int j = 0; j < *this; ++j) {
    //       char *pair = (char *)this[2] + 32 * j;
    //       WeightedAverageInterpolation(*(char **)(pair + 4), *(int *)(pair + 0), *(int *)(pair + 8));
    //       WeightedAverageInterpolation(*(char **)(pair + 12), *(int *)(pair + 8), *(int *)(pair + 16));
    //       WeightedAverageInterpolation(*(char **)(pair + 20), *(int *)(pair + 16), *(int *)pair);
    //     }
    //     return *this;
    //   }
    // UNRESOLVED: Exact meaning of the +16/+4 double offsets on the per-node objects depends on the unknown collision/physics node layout.
    // UNRESOLVED: The 0.5 blend constant is sourced from global 0x0059E880 but its unit (mass vs other scalar) is not determinable here.
    // UNRESOLVED: Owner object of this method is unknown; no caller-side type evidence distinguishes the collision contact container class.
}
