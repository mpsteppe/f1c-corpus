// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401340
// Canonical corpus name: VehicleSuspensionForceCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSuspensionForceCalculation_00401340.c

void UnknownObject::VehicleSuspensionForceCalculation()
{
    // Per-strut suspension contact solver. Iterates the vehicle suspension strut array (this+0x134, stride 316) for a count derived from this+0x130 (all struts) or 1 (single-strut mode when a2 is non-zero). For each strut with a live linked node (+268) and contact feature (+272), queries the spatial grid, extracts the collision normal, builds a contact frame, applies gravity compensation, and runs ray-sphere intersection tests to write penetration depth and contact force at strut offsets +112/+116/+120/+124/+128.
    // GUARD: Iteration count = (a2 != 0) ? 1 : this+0x130; the whole loop body only runs while the count is greater than 0 [field:this:0x00000130, source:raw]
    // LOOP: Walk the suspension strut array whose base is this+0x134, stepping 316 bytes per strut; in single-strut mode the selector a2 supplies the strut pointer directly [field:this:0x00000134, field:this:0x00000130, source:raw]
    // ASSIGNMENT: Reset per-strut contact state: strut+112 and +116 set to 0, strut+120 set to 0, strut+124 set to a negative literal, strut+128 set to 0 [source:raw]
    // GUARD: Per-strut processing only proceeds when both the linked node at strut+268 and the contact feature pointer at strut+272 are non-zero [source:raw]
    // CALL: SpatialGridQuery on the feature position read at node+148/+152/+156, filling the query struct that drives contact lookup [callee:0x0044C4C0, source:raw]
    // CALL: CollisionNormalFromFeature extracts the collision surface normal into the v33 buffer when the grid query hits [callee:0x0044C550, source:raw]
    // CALL: Second SpatialGridQuery on the strut wheel position (strut+148/+152/+156) to locate the strut-side contact feature [callee:0x0044C4C0, source:raw]
    // CALCULATION: Displacement vector between the strut wheel position and the feature position; the frame construction is guarded on its norm being non-zero [source:raw]
    // CALCULATION: Cross products of the normal axis pairs and normalization build the contact frame axes (basis constants 0, 1, 2 encoded in the query struct) [source:raw]
    // CALCULATION: Gravity compensation: dot products of the contact frame axes with the gravity vector (-9.8100004) are folded into the three contact force components [source:raw]
    // CALL: RaySphereQuadraticIntersectionTest run twice with the frame-projected parameters; results become the penetration depths written to strut+112 and strut+116, with sign corrections applied after [callee:0x00401180, source:raw]
    // ASSIGNMENT: Write the gravity-compensated contact force components back to the strut at +120/+124/+128 and the penetration depths to +112/+116 [source:raw]
    // LOOP: Decrement the remaining count and advance the byte stride by 316 for the next strut, continuing until the count reaches zero [field:this:0x00000134, source:raw]
    // RETURN: Return the final loop counter value; the function is invoked per strut by SweptSuspensionCollisionDetection (00401910) and PhysicsNodePropagationWithDistanceFalloff (00401C90) [function:0x00401340, caller:0x00401910, caller:0x00401C90, source:raw]

    // Conservative worker pseudocode:
    //   count = (a2 != 0) ? 1 : this[0x130/4];
    //   for (idx = 0; idx < count; ++idx) {
    //     strut = a2 ? a2 : (this[0x134/4] + idx*316);
    //     node = *(strut + 268); feature = *(strut + 272);
    //     *(strut+112) = *(strut+116) = *(strut+120) = *(strut+128) = 0;
    //     *(strut+124) = negative literal;
    //     if (feature && node) {
    //       if (SpatialGridQuery(query(node->pos))) {
    //         if (CollisionNormalFromFeature(query, &normal)) {
    //           if (SpatialGridQuery(query(strut->pos))) {
    //             build contact frame from normal + displacement;
    //             apply gravity (-9.8100004) into frame components;
    //             write force to strut+120/+124/+128;
    //             penetration1 = RaySphereQuadraticIntersectionTest(...);
    //             penetration2 = RaySphereQuadraticIntersectionTest(...);
    //             strut+112 = penetration1 (sign-fixed);
    //             strut+116 = penetration2 (sign-fixed);
    //           }
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: The purpose of the a2 single-strut selector relative to the full-grid callers is not documented in this function
    // UNRESOLVED: Four read-only globals (flt_59E438, flt_59E43C, flt_59E440, dbl_7C9360) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them NormalizationHalf, a physics constant, a zero threshold and an unknown struct, all unverifiable from this packet
}
