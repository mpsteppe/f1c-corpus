// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF7C0
// Canonical corpus name: AIVehiclePathPositionTracking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIVehiclePathPositionTracking_004ef7c0.c

void UnknownObject::AIVehiclePathPositionTracking()
{
    // Per-frame AI vehicle path-position tracking: copies the input orientation into the object, converts it to a 3x3 rotation matrix, computes a ride-height delta, rotates it into a position-offset error, accumulates the correction against the target path position, and re-solves the rigid body constraint when its pointer is null.
    // ASSIGNMENT: Copy the three input orientation values (a3[0..2]) into orientation fields this+0x34E0..0x34E8. [function:0x004EF7C0, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, source:raw]
    // CALL: EulerToRotationMatrix converts the stored orientation into the 3x3 rotation matrix written to this+0x34B0..0x34D0. [callee:0x00566E40, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0]
    // CALL: RideHeightDelta computes the vehicle ride-height delta into a local vector. [callee:0x004EF680]
    // CALCULATION: Multiply the ride-height delta by the stored rotation matrix to derive the position-offset error, subtract the target path position a2 to obtain the correction delta, and accumulate it into this+0x34D4/0x34D8/0x34DC. [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC]
    // ASSIGNMENT: Reset the constraint-solve counter this+0x3A9C to 0 for this frame. [field:this:0x00003A9C]
    // CALL: F_3x3MatrixTransformWithTranslation transforms the accumulated offset vector at this+0x34D4..0x34DC. [callee:0x004E9BD0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC]
    // GUARD: When the rigid body constraint pointer this+0x32BC is null, call RigidBodyConstraintSolve with global dbl_7C7428, the accumulated offset this+0x34D4..0x34DC, and the local target vector. [field:this:0x000032BC, callee:0x0043E4B0, global:0x007C7428, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC]
    // RETURN: Return the rigid-body solve result when re-solved, otherwise the existing constraint pointer this+0x32BC. [callee:0x0043E4B0, field:this:0x000032BC]

    // Conservative worker pseudocode:
    //   orientation[0..2] = a3[0..2];
    //   EulerToRotationMatrix(orientation, this->rotationMatrix3x3);
    //   RideHeightDelta(this, &delta);
    //   offset = this->rotationMatrix3x3 * delta;
    //   correction = a2 - offset;
    //   this->offsetError[0..2] += correction;
    //   this->constraintSolveCounter = 0;
    //   F_3x3MatrixTransformWithTranslation(&offset);
    //   if (this->rigidBodyConstraint == 0)
    //       return RigidBodyConstraintSolve(&dbl_7C7428, this->offsetError, &delta);
    // UNRESOLVED: F_3x3MatrixTransformWithTranslation is called with v11, which is never assigned earlier in the decompiled body.
    // UNRESOLVED: Exact roles of the target vector a2 and the accumulated error fields are inferred from caller context (AI path-following) rather than confirmed by the packet.
}
