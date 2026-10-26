// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401C90
// Canonical corpus name: PhysicsNodePropagationWithDistanceFalloff
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsNodePropagationWithDistanceFalloff_00401c90.c

void UnknownObject::PhysicsNodePropagationWithDistanceFalloff()
{
    // Per-frame force propagation over the vehicle physics node. Runs SweptSuspensionCollisionDetection then VehicleSuspensionForceCalculation, applies TireForceSolver per strut, propagates tire and grip forces along each strut's linked node chain (+268) with distance-based falloff into +136/+140, computes a maximum propagated force into this+0x148, then applies a grip-multiplier pass (sub_4FB260) and a per-strut finalization pass (sub_4FAF60). All loops iterate this+0x130 struts over the array base this+0x134 with stride 316. Called by CollisionWrapperWithLock (004E4910).
    // CALL: First stage: SweptSuspensionCollisionDetection(a1, a2, a3) advances struts and resolves swept contacts [callee:0x00401910, source:raw]
    // CALL: VehicleSuspensionForceCalculation(a1, 0) runs the full-grid suspension solver across all struts [callee:0x00401340, source:raw]
    // GUARD: Every loop in the function is gated on the strut count this+0x130 being greater than 0 (packet guard) [guard:0, field:this:0x00000130, source:raw]
    // LOOP: Per-strut loop over the array base this+0x134 with byte stride 316: TireForceSolver on the strut contact state (+112/+116/+120) and stores the resulting force at strut+136 [field:this:0x00000130, field:this:0x00000134, callee:0x004E8CE0, source:raw]
    // LOOP: Tire-force propagation: follows the linked chain from strut+268 while each link points back at the current node (link+272 == strut), applying TireForce per link [callee:0x004E9100, source:raw]
    // CALCULATION: Distance falloff: distance between the strut center (+148/+152/+156) and the link feature (+148/+152/+156 relative to the link), then attenuation a2 = a2 * (distance / i[34]) * 0.5 + i[34]; the attenuated force is written to link+136 and the walk continues while it stays positive and below the link's stored force [source:raw]
    // LOOP: Copy pass: for each strut, store strut+136 into strut+140 [field:this:0x00000134, source:raw]
    // LOOP: Grip-force propagation: walks the same linked chain with TireGripLateralForceCalculation, applying the same distance-falloff attenuation and writing the result to link+140 [callee:0x004E9300, source:raw]
    // ASSIGNMENT: Initialization pass: each strut's +144 slot is set to the literal -1082130432 (bit pattern for -1.0f) [source:raw]
    // LOOP: Maximum-force accumulation: this+0x148 is reset to 0.0, then for each chain link a candidate force at link+144 is computed (falloff-scaled or travel-scaled depending on the strut+72 versus link+18 comparison) and this+0x148 is raised when the link force exceeds it and the link's +300 guard is clear [field:this:0x00000148, source:raw]
    // CALCULATION: Grip multiplier: v53 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5 [global:0x008AFEE8, global:0x008AFEEC, source:raw]
    // CALL: Grip-multiplier pass: sub_4FB260(v53) called once per strut with the computed multiplier [callee:0x004FB260, source:raw]
    // CALL: Finalization pass: sub_4FAF60(strut base) called once per strut [callee:0x004FAF60, source:raw]
    // RETURN: Returns the strut count (this+0x130); the function is invoked by CollisionWrapperWithLock (004E4910) [field:this:0x00000130, function:0x00401C90, caller:0x004E4910, source:raw]

    // Conservative worker pseudocode:
    //   SweptSuspensionCollisionDetection(a1, a2, a3);
    //   VehicleSuspensionForceCalculation(a1, 0);
    //   count = this[0x130/4]; base = this[0x134/4];
    //   for (idx = 0; idx < count; ++idx) {
    //     strut = base + idx*316;
    //     TireForceSolver(*(strut+116), strut+120, *(strut+112), 16.0);
    //     *(strut+136) = a2;
    //   }
    //   for (idx = 0; idx < count; ++idx) {
    //     strut = base + idx*316;
    //     for (link = *(strut+268); link && *(link+272) == strut; link = *(link+268)) {
    //       TireForce(strut+136, *(link+116), link+120, *(link+112));
    //       if (strut+136 <= 0.0) break;
    //       dist = distance(strut+148..156, link+148..156);
    //       a2 = a2 * (dist / strut+136) * 0.5 + strut+136;
    //       if (a2 <= 0.0 || a2 > *(link+136)) break;
    //       *(link+136) = max(a2, 0.0); strut = link;
    //     }
    //   }
    //   copy strut+136 -> strut+140;
    //   grip walk with TireGripLateralForceCalculation, writing link+140;
    //   initialize strut+144 = -1082130432;
    //   max-walk: this[0x148/4] = 0.0; update to largest link+144 while guard clean;
    //   v53 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5;
    //   for (idx = 0; idx < count; ++idx) sub_4FB260(v53);
    //   for (idx = 0; idx < count; ++idx) sub_4FAF60(base + idx*316);
    //   return count;
    // UNRESOLVED: The strut element layout (stride 316, offsets +72/+136/+140/+144/+148/+300 relative to a strut) is accessed by raw offsets and is not defined in this function
    // UNRESOLVED: Three read-only globals (flt_59E43C, flt_59E440, flt_59E450) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them a physics constant, a zero threshold and a degrees-to-radians value, all unverifiable from this packet
    // UNRESOLVED: The role of the a3 argument beyond being forwarded to SweptSuspensionCollisionDetection is unknown
}
