// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EFB20
// Canonical corpus name: F_3DTransformWithMatrixMultiplication
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DTransformWithMatrixMultiplication_004efb20.c

void UnknownObject::TransformPointByMatrix()
{
    // Transforms a point by a 3x3 matrix plus translation, then copies a 3-dword result. First calls RideHeightDelta on the this object to fill the three component locals v7/v8/v9. It then computes the dot product of those three components against each of the three matrix coefficient groups (at this+13488/13492/13496, this+13500/13504/13508, this+13512/13516/13520), adds the translation components (this+13524/13528/13532), and writes the three results into a2. Finally it copies the three dwords at this+13536/13540/13544 into a3 and returns the second of those dwords. Called from eleven sites including AIRacingLine, VehicleMainPhysicsUpdate, SessionStateTransition and VehicleYawRotationRecoveryController.
    // CALL: Call RideHeightDelta with (this, &v7) to fill the three local components v7/v8/v9. [callee:0x004EF680, source:raw]
    // CALCULATION: Compute a2[0] = v9 * (this+13496) + v8 * (this+13492) + v7 * (this+13488). [source:raw]
    // CALCULATION: Compute a2[1] = v9 * (this+13508) + v7 * (this+13500) + v8 * (this+13504). [source:raw]
    // CALCULATION: Compute a2[2] = v9 * (this+13520) + v7 * (this+13512) + v8 * (this+13516). [source:raw]
    // CALCULATION: Add the translation components to the results: a2[0] += this+13524, a2[1] += this+13528, a2[2] += this+13532. [source:raw]
    // ASSIGNMENT: Copy the dwords at this+13536, this+13540 and this+13544 into a3[0], a3[1], a3[2]. [source:raw]
    // RETURN: Return the copied dword a3[1] (this+13540). [function:0x004EFB20, source:raw]

    // Conservative worker pseudocode:
    //   RideHeightDelta(this, &v7);
    //   a2[0] = v7 * this[13488] + v8 * this[13492] + v9 * this[13496] + this[13524];
    //   a2[1] = v7 * this[13500] + v8 * this[13504] + v9 * this[13508] + this[13528];
    //   a2[2] = v7 * this[13512] + v8 * this[13516] + v9 * this[13520] + this[13532];
    //   a3[0] = this[13536]; a3[1] = this[13540]; a3[2] = this[13544];
    //   return a3[1];
    // UNRESOLVED: Whether the nine coefficients at this+13488..13520 form a row-major or column-major 3x3 matrix is ambiguous from the raw source alone.
    // UNRESOLVED: The semantics of the 3-dword copy into a3 (direction vector, basis, or per-object identifier) are not recoverable from this packet.
    // UNRESOLVED: Meaning of the returned dword a3[1] is unknown.
    // UNRESOLVED: The transformation performed inside RideHeightDelta is not described by this packet.
    // UNRESOLVED: Owner object is unconfirmed; the this pointer is passed as float* with no owning class identified.
}
