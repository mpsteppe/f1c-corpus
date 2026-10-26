// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401910
// Canonical corpus name: SweptSuspensionCollisionDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SweptSuspensionCollisionDetection_00401910.c

void UnknownObject::SweptSuspensionCollisionDetection()
{
    // Swept-strut contact solver on the vehicle physics node. First advances each strut position (strut+148/+152/+156) with a velocity-scaled Euler step over the strut array (this+0x134, stride 316, count this+0x130). Then, for struts with both a linked node (+268) and a contact feature (+272), sweeps the travel axis over a small window, calling VehicleSuspensionForceCalculation and TireForceSolver at the strut, its linked node and its feature, and commits the sample position that maximizes contact force. Called by PhysicsNodePropagationWithDistanceFalloff (00401C90).
    // GUARD: Both per-strut loops are gated on the strut count this+0x130 being greater than 0 (packet guard) [guard:0, field:this:0x00000130, source:raw]
    // LOOP: First loop walks the strut array at base this+0x134 with byte stride 316, once per strut in this+0x130 [field:this:0x00000134, field:this:0x00000130, source:raw]
    // CALCULATION: Euler position advance: reads the travel scale at strut+24 and per-strut velocity terms, then writes the new position to strut+148/+152/+156 as scaled sums [source:raw]
    // LOOP: Second loop walks the same strut array; each strut is processed only when its linked node (strut+268) and contact feature (strut+272) pointers are both non-zero [field:this:0x00000134, field:this:0x00000130, source:raw]
    // CALL: VehicleSuspensionForceCalculation run for the strut, its linked node and its contact feature, each followed by TireForceSolver on the contact state at +112/+116/+120 [callee:0x00401340, callee:0x004E8CE0, source:raw]
    // LOOP: Sweep loop: steps the travel position from strut+24 minus 0.045000002 upward by 0.0099999998 while strut+24 plus 0.050000001 is still above it, re-running the suspension and tire solvers at every sample [source:raw]
    // CALCULATION: Tracks the minimum and maximum contact force across sweep samples and keeps the travel value that produced the maximum force [source:raw]
    // ASSIGNMENT: Commits the chosen sweep position by writing the final sample position to strut+148/+152/+156 [source:raw]
    // CALL: Invoked by PhysicsNodePropagationWithDistanceFalloff (00401C90) as the first stage of the per-frame collision pass [caller:0x00401C90, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0x130/4];
    //   for (idx = 0; idx < count; ++idx) {
    //     strut = this[0x134/4] + idx*316;
    //     scale = *(strut + 24);
    //     strut+148 = scale * *(strut+148-116) + *(strut+148-148);
    //     strut+152 = scale * *(strut+148-108) + *(strut+148-144);
    //     strut+156 = scale * *(strut+148-112) + *(strut+148-140);
    //   }
    //   for (idx = 0; idx < count; ++idx) {
    //     strut = this[0x134/4] + idx*316;
    //     node = *(strut + 268); feature = *(strut + 272);
    //     if (node && feature) {
    //       VehicleSuspensionForceCalculation(this, strut);
    //       TireForceSolver(*(strut+116), strut+120, *(strut+112), 16.0);
    //       VehicleSuspensionForceCalculation(this, node);
    //       TireForceSolver(*(node+116), node+120, *(node+112), 16.0);
    //       VehicleSuspensionForceCalculation(this, feature);
    //       TireForceSolver(*(feature+116), feature+120, *(feature+112), 16.0);
    //       best = contact force at strut+24;
    //       for (t = strut+24 - 0.045000002; strut+24 + 0.050000001 > t; t += 0.0099999998) {
    //         sample position = strut + t * velocity;
    //         re-run the three suspension/tire evaluations;
    //         best = max(best, sample force);
    //       }
    //       write chosen sample position to strut+148/+152/+156;
    //     }
    //   }
    // UNRESOLVED: The velocity and travel terms read from the strut are reached by relative offsets only; the strut element layout (stride 316) is not defined here
    // UNRESOLVED: Three read-only globals (flt_59E444, flt_59E448, flt_59E44C) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them FrameDelta, TileSteppingMultiplier and a collision tolerance, all unverifiable from this packet
    // UNRESOLVED: Field this+0x138 is flagged as read/written by packet facts but never appears in the raw decompiled source
}
