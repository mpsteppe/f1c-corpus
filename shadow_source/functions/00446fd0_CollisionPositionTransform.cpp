// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00446FD0
// Canonical corpus name: CollisionPositionTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionPositionTransform_00446fd0.c

void UnknownObject::CollisionPositionTransform()
{
    // Transforms a collision contact position from a per-part local frame into the vehicle's world frame and then into the vehicle-relative frame, then applies two 3x3 matrix multiplications. Reads the per-part source vector from the part entry at 1124*a2 + this + 1000 (dereferenced at +4), rotates it by the rigid-body rotation matrix at *(this+0x15F0)+4 through F_3DVectorTransformBy33Matrix into a3, subtracts the vehicle's world position (three consecutive doubles at this+0x15FC / 0x1604 / 0x160C) from a3, then calls F_33MatrixMultiply with a4 and returns F_33MatrixMultiply with a5.
    // CALL: F_3DVectorTransformBy33Matrix: rotate the part-local contact vector (at *(1124*a2 + this + 1000) + 4) by the rigid-body rotation matrix (at *(this+0x15F0) + 4), writing the result to a3 and a scratch destination at *(this+0x15F0) + 28. [callee:0x004361D0, field:this:0x000015F0, source:raw]
    // ASSIGNMENT: a3[0] = a3[0] - *(double*)(this + 0x15FC): subtract the vehicle world position X, converting the rotated point to vehicle-relative coordinates. [field:this:0x000015FC, source:raw]
    // ASSIGNMENT: a3[1] = a3[1] - *(double*)(this + 0x1604): subtract the vehicle world position Y. [field:this:0x00001604, source:raw]
    // ASSIGNMENT: a3[2] = a3[2] - *(double*)(this + 0x160C): subtract the vehicle world position Z. [field:this:0x0000160C, source:raw]
    // CALL: F_33MatrixMultiply(a4): apply the first 3x3 matrix multiplication to a4. [callee:0x0056C740, source:raw]
    // RETURN: return F_33MatrixMultiply(a5): apply the second 3x3 matrix multiplication to a5 and return its result. [callee:0x0056C740, function:0x00446FD0, source:raw]
    // CALL: Invoked by sub_4F0430 during vehicle collision geometry processing. [caller:0x004F0430]

    // Conservative worker pseudocode:
    //   F_3DVectorTransformBy33Matrix(*(this+0x15F0)+28, *(this+0x15F0)+4, *(1124*a2 + this + 1000)+4, a3);
    //   a3[0] -= *(double*)(this + 0x15FC);
    //   a3[1] -= *(double*)(this + 0x1604);
    //   a3[2] -= *(double*)(this + 0x160C);
    //   F_33MatrixMultiply(a4);
    //   return F_33MatrixMultiply(a5);
    // UNRESOLVED: The per-part entry stride of 1124 bytes at this + 1000 (1124*a2 + this + 1000) is a computed offset with no field evidence ref; +4 is the source vector location.
    // UNRESOLVED: The rigid-body sub-offsets (rotation matrix at +4, scratch destination at +28) are offsets inside an indirect object pointed to by this+0x15F0 and have no field evidence refs.
    // UNRESOLVED: The meanings of the a4 and a5 matrix arguments are not established by the packet; only the calls and the returned value are evidenced.
    // UNRESOLVED: The fill's field labels for this+0x15FC / 0x1604 ('rigid body state field') and this+0x160C ('vehicle position X') conflict with the raw source, which reads all three as consecutive position doubles subtracted from the transformed point; the X/Y/Z reading adopted here is derived from raw source order.
    // UNRESOLVED: The legacy ABI label 'CollisionPositionTransform' (abi:lead) matches the canonical name and is adopted as proposed_name, but its trust is LEGACY, not independently confirmed.
}
