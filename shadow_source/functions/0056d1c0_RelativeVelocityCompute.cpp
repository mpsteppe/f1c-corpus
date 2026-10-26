// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D1C0
// Canonical corpus name: RelativeVelocityCompute
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RelativeVelocityCompute_0056d1c0.c

void UnknownObject::RelativeVelocityCompute()
{
    // Computes the relative-velocity magnitude between two bodies in the vehicle physics pipeline. Each body's local velocity (3 doubles) is transformed into world space through its 3x3 rotation matrix plus translation, then the Euclidean norm of the world-space velocity difference is computed with sqrt. The result magnitude is written to both bodies' velocity buffers at +56. Called by VehiclePhysicsInitializer and ConstraintForceSolver.
    // CALCULATION: Transform body A local velocity into world space: v10 = row0(matrixA) dot velA + transA.x (elements this 0x28/0x30/0x38), v4 = row1 dot velA + transA.y (elements this 0x50/0x58/0x60), v5 = row2 dot velA + transA.z (element this 0x68 and block elements +84/+92). Translation components are read at transform-block offsets +4/+12/+20 through the body A transform pointer (this 0x4); body A velocity is read through this 0x8. [field:this:0x00000004, field:this:0x00000008, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000050, field:this:0x00000058, field:this:0x00000060, field:this:0x00000068, source:raw]
    // CALCULATION: Transform body B local velocity into world space: v11 = row0(matrixB) dot velB + transB.x, v7 = row1(matrixB) dot velB, v12 = row2(matrixB) dot velB. Matrix rows reuse the same rotation-element fields as body A (this 0x28..0x68); matrix B is read through the body B transform pointer (this 0xC) and body B velocity through this 0x10. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000050, field:this:0x00000058, field:this:0x00000060, field:this:0x00000068, source:raw]
    // CALCULATION: Compute relative velocity magnitude: v8 = sqrt((v5 - (v12 + transB.z))^2 + (v4 - (v7 + transB.y))^2 + (v10 - v11)^2), the Euclidean norm of the component-wise world-space velocity difference (transB.y and transB.z are added from the body B transform block during the differences). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write v8 (relative velocity magnitude) into body A velocity buffer element 7 (double index 7, offset +56; this-relative write target 0x40). [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Write v8 (relative velocity magnitude) into body B velocity buffer at offset +56 (this-relative write target 0x48, reached through result pointer this 0x10). [field:this:0x00000048, field:this:0x00000010, source:raw]
    // RETURN: Return the body B velocity / result buffer pointer (this[4], this-relative 0x10). [field:this:0x00000010, function:0x0056D1C0]

    // Conservative worker pseudocode:
    //   // Relative velocity magnitude between two bodies.
    //   worldA = rotA * velA + transA;      // v10, v4, v5
    //   worldB = rotB * velB + transB;      // v11, v7, v12 (transB.y/z added below)
    //   rel = sqrt((worldA.x - worldB.x)^2
    //            + (worldA.y - worldB.y)^2
    //            + (worldA.z - worldB.z)^2);
    //   velA[7] = rel;
    //   velB[7] = rel;   /* velB == this[4] == result * /
    //   return velB;
    // UNRESOLVED: Header/padding fields this 0x18 and 0x20 are read but map to no arithmetic in the raw source; their attribution to the transform block header comes from existing analysis only.
    // UNRESOLVED: Translation components (transform-block offsets +4/+12/+20) and matrix row 2 y/z elements (block offsets +84/+92) have no dedicated packet field evidence refs; they are implied by the raw source arithmetic only.
    // UNRESOLVED: Both bodies receive the same relative speed at offset +56 of their velocity buffers; whether this is a shared field across bodies is not independently evidenced.
}
