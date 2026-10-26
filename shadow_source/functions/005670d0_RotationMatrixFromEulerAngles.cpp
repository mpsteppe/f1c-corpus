// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005670D0
// Canonical corpus name: F_33RotationMatrixFromEulerAngles
// Owner: Matrix3x3Util [DERIVED]
// Raw source: functions/F_33RotationMatrixFromEulerAngles_005670d0.c

void Matrix3x3Util::RotationMatrixFromEulerAngles()
{
    // Fills a 3x3 rotation matrix (nine float components at this+0 through this+0x20) from two Euler-angle arguments a2 and a3: it computes the sine and cosine of each angle and writes the eight nonzero entries of the standard rotation matrix, with the middle entry this[5] forced to zero.
    // CALCULATION: Computes sin(a2), cos(a2), sin(a3) and cos(a3) from the two Euler-angle arguments. [source:raw]
    // ASSIGNMENT: Writes the first row of the rotation matrix: this[0] = cos(a3)*cos(a2), this[1] = -(sin(a3)*cos(a2)), this[2] = sin(a2). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Writes the second row of the rotation matrix: this[3] = sin(a3), this[4] = cos(a3), this[5] = 0.0. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Writes the third row of the rotation matrix: this[6] = -(cos(a3)*sin(a2)), this[7] = sin(a3)*sin(a2), this[8] = cos(a2). [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]

    // Conservative worker pseudocode:
    //   s1 = sin(a2); c1 = cos(a2);
    //   s2 = sin(a3); c2 = cos(a3);
    //   this[0] = c2 * c1;
    //   this[1] = -(s2 * c1);
    //   this[2] = s1;
    //   this[3] = s2;
    //   this[4] = c2;
    //   this[5] = 0.0;
    //   this[6] = -(c2 * s1);
    //   this[7] = s2 * s1;
    //   this[8] = c1;
    // UNRESOLVED: The exact Euler-angle convention (rotation order and axis meaning) is not proven; the function is a structural twin of EulerToRotationMatrix (00566e40) per the cluster_copy prelabel.
    // UNRESOLVED: Owner type is DERIVED: the function is a plain matrix fill with no class-identity evidence, used by SuspensionParamUpdate and WheelSuspensionTireStateInit.
}
