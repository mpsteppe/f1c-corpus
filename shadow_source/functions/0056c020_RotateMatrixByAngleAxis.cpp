// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C020
// Canonical corpus name: sub_56C020
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56C020_0056c020.c

void UnknownObject::RotateMatrixByAngleAxis()
{
    // Right-multiplies the 3x3 rotation matrix at `this` (nine doubles, offsets 0x0..0x40) by the Rodrigues rotation matrix built from the axis-angle vector a2. Computes the axis norm, normalizes a2, derives sin/cos of the rotation angle and the axis products that form the rotation matrix, then composes each of the three matrix rows from the prior row entries. When the axis squared norm is not greater than 0.0 the function does nothing (identity). Per-frame path; called from vehicle orientation integration and two helper transforms.
    // CALCULATION: Compute v2 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2], the squared length of the axis-angle vector, and v18 = sqrt(v2) as the rotation angle magnitude. [function:0x0056C020, source:raw]
    // GUARD: If v2 (the axis squared norm) is greater than 0.0, perform the rotation; otherwise leave `this` untouched, which acts as an identity compose. [function:0x0056C020, source:raw]
    // CALCULATION: Normalize a2 into unit axis components v3, v4, v5 using the reciprocal magnitude (1.0 / v18) and the constant factor 1.0, then form the Rodrigues terms: sin(v18) and cos(v18) components, the one-minus-cosine factor, and the axis-product entries v26..v29, v20, v24 that make up the rotation matrix. [global:0x0059E420, global:0x0059E430, function:0x0056C020, source:raw]
    // ASSIGNMENT: Compose the first matrix row: write new this[0], this[3], this[6] (offsets 0x0, 0x18, 0x30) from the prior row values v11, v12, v13 and the Rodrigues terms. [field:this:0x00000000, field:this:0x00000018, field:this:0x00000030, function:0x0056C020, source:raw]
    // ASSIGNMENT: Compose the second matrix row: write new this[1], this[4], this[7] (offsets 0x8, 0x20, 0x38) from the prior row values v14, v15, v16 and the Rodrigues terms. [field:this:0x00000008, field:this:0x00000020, field:this:0x00000038, function:0x0056C020, source:raw]
    // ASSIGNMENT: Compose the third matrix row: write new this[2], this[5], this[8] (offsets 0x10, 0x28, 0x40) from the prior row values v23, v21, v17 and the Rodrigues terms. [field:this:0x00000010, field:this:0x00000028, field:this:0x00000040, function:0x0056C020, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2];
    //   if (v2 > 0.0) {
    //     invLen = 1.0 / sqrt(v2);
    //     ux = invLen * a2[0]; uy = invLen * a2[1]; uz = invLen * a2[2];
    //     s = sin(sqrt(v2)); c = cos(sqrt(v2));
    //     // build Rodrigues rotation R from ux/uy/uz, s, c;
    //     // right-multiply: this = this * R for all nine entries.
    //   }
    // UNRESOLVED: The `this` object is a 3x3 double rotation matrix (nine doubles at offsets 0x0..0x40), but the owning class is not evidenced in the packet.
    // UNRESOLVED: dbl_59E420 / dbl_59E430 (0x0059E420 / 0x0059E430) are read as constant factors per IDB facts but are constant-folded in the raw source; exact double values are not in the packet (existing analysis DERIVEs dbl_59E420 = 1.0).
    // UNRESOLVED: Callers (vehicle orientation integration and two helper transforms) invoke this per frame, but the exact call cadence is not grounded in the packet.
}
