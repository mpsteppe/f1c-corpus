// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D2D0
// Canonical corpus name: sub_56D2D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56D2D0_0056d2d0.c

void UnknownObject::ComputeConstraintAnchorOffset()
{
    // Constraint solver anchor-offset computation. Transforms the local anchor offset of each rigid body through its rotation matrix (Matrix3x3VectorMultiply), adds the body position to obtain world anchor points, subtracts the two world anchors to get the difference vector, and normalizes it to unit length. The normalized vector is copied back into both body anchor buffers. Used during rigid-body joint/constraint setup by four callers.
    // CALL: First Matrix3x3VectorMultiply: rotate body A's local anchor offset (vector at *(this+8)+0x18) through the rotation matrix at *(this+4)+28 and write the transformed anchor back to *(this+8)+0x18 [callee:0x00435E00, field:*(this+0x8):0x00000018, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: Second Matrix3x3VectorMultiply: rotate body B's local anchor offset (vector at *(this+0x10)+0x18) through the rotation matrix at *(this+0xC)+28 and write the transformed anchor back to *(this+0x10)+0x18 [callee:0x00435E00, field:*(this+0x10):0x00000018, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: World anchor B: transformed local anchor components of *(this+0x10) at 0x18/0x20/0x28 added to the body B position components of *(this+0xC) at 0x4/0xC/0x14 [field:*(this+0x10):0x00000018, field:*(this+0x10):0x00000020, field:*(this+0x10):0x00000028, field:*(this+0xC):0x00000004, field:*(this+0xC):0x0000000C, field:*(this+0xC):0x00000014, source:raw]
    // CALCULATION: World anchor A: transformed local anchor components of *(this+8) at 0x18/0x20/0x28 added to the body A position components of *(this+4) at 0x4/0xC/0x14 [field:*(this+0x8):0x00000018, field:*(this+0x8):0x00000020, field:*(this+0x8):0x00000028, field:*(this+0x4):0x00000004, field:*(this+0x4):0x0000000C, field:*(this+0x4):0x00000014, source:raw]
    // CALCULATION: Difference vector v13 = world anchor A - world anchor B, component-wise, computed in the v13 buffer [source:raw]
    // CALCULATION: Normalization: v11 = 1.0 / sqrt(dot(v13, v13)); each component of v13 scaled by v11 into the v12 buffer [source:raw]
    // ASSIGNMENT: Write the normalized 0x18-byte vector to *(this+8)+64 and to *(this+0x10)+64, giving both rigid bodies a unit-length anchor separation direction [field:this:0x00000008, field:this:0x00000010, source:raw]
    // RETURN: Return pointer to the body A position (*(this+4)+4). Invoked on the physics frame path by VehiclePhysicsInitializer (00439210), ConstraintForceSolver (0043BA20), VehiclePhysicsJointSystemLoader (0056D930) and BatchProcessingLoop3Passes (0056EC00) [function:0x0056D2D0, field:this:0x00000004, caller:0x00439210, caller:0x0043BA20, caller:0x0056D930, caller:0x0056EC00, source:raw]

    // Conservative worker pseudocode:
    //   Matrix3x3VectorMultiply(bodyA.rotation, bodyA.localAnchor, bodyA.localAnchorWorld);
    //   Matrix3x3VectorMultiply(bodyB.rotation, bodyB.localAnchor, bodyB.localAnchorWorld);
    //   worldB = bodyB.localAnchorWorld + bodyB.position;
    //   worldA = bodyA.localAnchorWorld + bodyA.position;
    //   diff = worldA - worldB;
    //   if (len2(diff) != 0) diff /= sqrt(len2(diff));
    //   copy(diff, bodyA.anchorDir, 24); copy(diff, bodyB.anchorDir, 24);
    //   return &bodyA.position;
    // UNRESOLVED: Fact packet lists a read of global dbl_59E420 (0x0059E420) but it appears nowhere in the raw decompiled source; its role here cannot be verified from this packet
}
