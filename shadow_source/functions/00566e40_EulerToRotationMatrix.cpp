// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566E40
// Canonical corpus name: EulerToRotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EulerToRotationMatrix_00566e40.c

void UnknownObject::EulerToRotationMatrix()
{
    // Converts three Euler angles in a1[0..2] into a 3x3 rotation matrix written row-major into a2[0..8]. Pure trigonometric computation with no side effects and no callees.
    // CALCULATION: Compute v2 = sin(a1[0]) and v3 = cos(a1[0]). [source:raw]
    // CALCULATION: Compute v4 = sin(a1[1]) and v7 = cos(a1[1]). [source:raw]
    // CALCULATION: Compute v5 = sin(a1[2]) and v6 = cos(a1[2]). [source:raw]
    // CALCULATION: Compute intermediate products v9 = v6 * v7 and v8 = v5 * v7. [source:raw]
    // ASSIGNMENT: Write row 0 column 0 of the output matrix: a2[0] = v4 * v2 * v5 + v9. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write row 0 column 1: a2[1] = v4 * v2 * v6 - v8. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write row 0 column 2: a2[2] = v4 * v3. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write row 1 column 0: a2[3] = v5 * v3. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write row 1 column 1: a2[4] = v6 * v3. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write row 1 column 2: a2[5] = -v2. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write row 2 column 0: a2[6] = v8 * v2 - v6 * v4. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write row 2 column 1: a2[7] = v5 * v4 + v9 * v2. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Write row 2 column 2: a2[8] = v7 * v3. [field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   float s0 = sin(a1[0]), c0 = cos(a1[0]);
    //   float s1 = sin(a1[1]), c1 = cos(a1[1]);
    //   float s2 = sin(a1[2]), c2 = cos(a1[2]);
    //   float c2c1 = c2 * c1, s2c1 = s2 * c1;
    //   a2[0] = s1 * s0 * s2 + c2c1;
    //   a2[1] = s1 * s0 * c2 - s2c1;
    //   a2[2] = s1 * c0;
    //   a2[3] = s2 * c0;
    //   a2[4] = c2 * c0;
    //   a2[5] = -s0;
    //   a2[6] = s2c1 * s0 - c2 * s1;
    //   a2[7] = s2 * s1 + c2c1 * s0;
    //   a2[8] = c1 * c0;
    // UNRESOLVED: Input angles a1[0..2] are read via pointer arithmetic, not via the this-based field evidence list; the packet carries only output matrix field refs.
}
