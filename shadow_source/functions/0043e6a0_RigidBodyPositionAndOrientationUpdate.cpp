// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E6A0
// Canonical corpus name: RigidBodyTransformUpdate
// Owner: RigidBodyTransformUpdate [DERIVED]
// Raw source: functions/RigidBodyTransformUpdate_0043e6a0.c

void RigidBodyTransformUpdate::RigidBodyPositionAndOrientationUpdate()
{
    // Updates a rigid body's world position by adding a caller-supplied delta vector, then extracts two Euler angles from the body's orientation matrix with atan2 (with a dedicated branch for the gimbal-lock case where the pitch cosine magnitude is 1.0), and applies the transform through sub_56F100. Wraps the computation in an FPU control-word save/restore and routes the restore-mismatch path through an empty stub.
    // CALL: Save the FPU control word precision mask with FPUControlWordMaskExtract, comparing against the constant 512. [callee:0x00567740]
    // ASSIGNMENT: Load the rigid body state pointer from this + 0x15F0. [field:this:0x000015F0]
    // ASSIGNMENT: Add the incoming delta vector components to the body's stored position (fields this + 0x15F4, +0x15FC, +0x1604). [field:this:0x000015F4, field:this:0x000015FC, field:this:0x00001604]
    // CALCULATION: Read the pitch-related component at this + 0x1634, negate it, and pass it through FloatConvertWrapper. [callee:0x00588570, field:this:0x00001634]
    // GUARD: Detect the gimbal-lock case: the absolute value of the this + 0x1634 component equals the 1.0 constant global. [global:0x0059E420, field:this:0x00001634]
    // CALCULATION: Gimbal-lock branch: first Euler angle from atan2 of the negated this + 0x163C component over this + 0x160C, with the second angle fixed to zero. [field:this:0x0000163C, field:this:0x0000160C]
    // CALCULATION: General branch: extract two Euler angles with atan2 of this + 0x161C over this + 0x164C and this + 0x1624 over this + 0x162C. [field:this:0x0000161C, field:this:0x0000164C, field:this:0x00001624, field:this:0x0000162C]
    // CALL: Apply the accumulated position and computed orientation to the rigid body via sub_56F100. [callee:0x0056F100]
    // GUARD: When the restored FPU control word no longer equals 512, divert through EmptyStub_7780 instead of returning the result. [callee:0x00567780]
    // RETURN: Return sub_56F100's result on the matching-control-word path, otherwise the empty stub result. [source:raw]

    // Conservative worker pseudocode:
    //   int RigidBodyPositionAndOrientationUpdate(RigidBody *body, const double *delta) {
    //     int fpu = FPUControlWordMaskExtract(512);
    //     char *rb = (char *)body->state;            // this + 0x15F0
    //     double pos[3];
    //     pos[0] = *(double *)(rb + 4) + delta[0];
    //     pos[1] = *(double *)(rb + 12) + delta[1];
    //     pos[2] = *(double *)(rb + 20) + delta[2];
    //     double pitch = *(double *)(rb + 68);      // this + 0x1634
    //     FloatConvertWrapper();
    //     double neg = -pitch;
    //     double a1, a2;
    //     if (fabs(*(double *)(rb + 68)) == 1.0) {
    //       a2 = 0.0;
    //       a1 = atan2(-*(double *)(rb + 76), *(double *)(rb + 28));
    //     } else {
    //       a1 = atan2(*(double *)(rb + 44), *(double *)(rb + 92));
    //       a2 = atan2(*(double *)(rb + 52), *(double *)(rb + 60));
    //     }
    //     int result = sub_56F100(rb, pos, &neg, 0);
    //     if (fpu != 512) return EmptyStub_7780(fpu);
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of the atan2 pairs (rotation matrix elements versus quaternion components) and the roles of the intermediate this + 0x15F4..+0x164C double fields are read from the raw arithmetic only.
    // UNRESOLVED: Whether the delta vector a2 is a world-space velocity, offset, or acceleration is caller-defined and not visible here.
    // UNRESOLVED: The 512 constant and the EmptyStub_7780 diversion on control-word mismatch are FPU-state hygiene whose game-specific intent is unknown.
}
