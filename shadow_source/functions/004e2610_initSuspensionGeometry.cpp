// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2610
// Canonical corpus name: SuspensionGeometryInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SuspensionGeometryInitializer_004e2610.c

void UnknownObject::initSuspensionGeometry()
{
    // Initializes suspension geometry for a single wheel slot: computes the wheel offset vector from the chassis local origin, copies the suspension orientation matrix and the upright orientation matrix into per-wheel geometry storage, and extracts Euler angles from both matrices with gimbal-lock handling.
    // CALCULATION: Compute wheel offset vector by subtracting the chassis local origin (this+0x48/0x4C/0x50 = X/Y/Z) from the input position a3, and store the three components into the wheel offset vector (v8[0..2]). [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, function:0x004E2610, source:raw]
    // ASSIGNMENT: Mirror the same three offset components into the geometry block at v5+184/+188/+192. [source:raw]
    // CALL: Copy the suspension orientation matrix (0x24 bytes, 3x3 floats) from a4 into per-wheel geometry storage at v6. [source:raw]
    // CALCULATION: Load an element of the copied suspension orientation matrix (this[74*a2+93]), pass it through FloatConvertWrapper, negate it, and store the result at v5+128. [callee:0x00588570, source:raw]
    // GUARD: Gimbal-lock check on the suspension matrix: if fabs of a matrix element equals 1.0 (the constant 1.0 at 0x0059E420), take the alternate atan2 branch and force the second angle to 0. [global:0x0059E420, source:raw]
    // CALCULATION: Extract the first Euler angle from the suspension matrix via atan2(v6[2], v6[8]) when not in gimbal lock. [source:raw]
    // CALCULATION: Extract the second Euler angle from the suspension matrix via atan2(v6[3], v6[4]) when not in gimbal lock. [source:raw]
    // CALL: Copy the upright orientation matrix (0x24 bytes, 3x3 floats) from a5 into the geometry block at v5+208. [source:raw]
    // CALCULATION: Load an element of the copied upright matrix (v5+228), pass it through FloatConvertWrapper, negate it, and store at v5+196. [callee:0x00588570, source:raw]
    // GUARD: Second gimbal-lock check: if fabs of the upright matrix element (v5+228) equals 1.0, use the alternate atan2 formula and force the second angle to 0. [source:raw]
    // CALCULATION: Extract the first Euler angle from the upright matrix via atan2(v5+216, v5+240) when not in gimbal lock. [source:raw]
    // CALCULATION: Extract the second Euler angle from the upright matrix via atan2(v5+220, v5+224) when not in gimbal lock. [source:raw]

    // Conservative worker pseudocode:
    //   vec3 offset = inputPos - chassisOrigin;
    //   wheelOffsetVec = offset;
    //   copy(suspensionMatrix, srcA4, 24);
    //   euler0 = FloatConvertWrapper(-suspensionMatrix.z);
    //   if (fabs(suspensionMatrix[5]) == 1.0) { angleY = atan2(-suspensionMatrix[6], suspensionMatrix[0]); angleZ = 0; }
    //   else { angleY = atan2(suspensionMatrix[2], suspensionMatrix[8]); angleZ = atan2(suspensionMatrix[3], suspensionMatrix[4]); }
    //   copy(uprightMatrix, srcA5, 24);
    //   if (fabs(uprightMatrix[5]) == 1.0) { angleY = atan2(-uprightMatrix[7], uprightMatrix[0]); angleZ = 0; }
    //   else { angleY = atan2(uprightMatrix[2], uprightMatrix[8]); angleZ = atan2(uprightMatrix[3], uprightMatrix[4]); }
    // UNRESOLVED: FloatConvertWrapper (0x00588570) semantics not established; assumed double/float conversion helper.
    // UNRESOLVED: atan2 argument order and the exact Euler angle rotation convention (order of Y/Z axes) not proven.
    // UNRESOLVED: Whether the 0x24-byte matrices are row-major or column-major not determined.
    // UNRESOLVED: Field at v5+128 (negated suspension element) role beyond Euler extraction not confirmed.
}
