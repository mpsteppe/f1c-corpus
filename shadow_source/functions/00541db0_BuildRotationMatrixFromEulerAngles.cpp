// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541DB0
// Canonical corpus name: RandomRotationMatrixFromEulerAngles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomRotationMatrixFromEulerAngles_00541db0.c

void UnknownObject::BuildRotationMatrixFromEulerAngles()
{
    // Builds a 3x3 rotation matrix from three Euler angles (a2, a3, a4) using sin/cos, stores the raw angles at this+0x30/0x34/0x38, writes the matrix to this+0x15C..0x188 (with zeros at 0x168/0x178/0x188 and 1.0f at 0x198), then transforms the orientation vector read from this+0x24/0x28/0x2C by the new matrix into the result vector at this+0x18C/0x190/0x194. Each Euler angle is first passed through InterruptDispatch. Returns 0.
    // CALL: InterruptDispatch(a2), InterruptDispatch(a3), InterruptDispatch(a4) normalize or validate each Euler angle before use. [callee:0x0058957A]
    // ASSIGNMENT: Store the Euler angles: this+0x30 = a2, this+0x34 = a3, this+0x38 = a4. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038]
    // CALCULATION: Compute sin/cos products of the three angles (sinA2, cosA2, sinA3, cosA3, sinA4, cosA4 and their pairwise products) used to fill the matrix. [source:raw]
    // ASSIGNMENT: Write the 3x3 rotation matrix rows: this+0x15C/0x160/0x164 (row 0), this+0x16C/0x170/0x174 (row 1), this+0x17C/0x180/0x184 (row 2); the 4th column entries at 0x168, 0x178, 0x188 are zeroed; 1.0f (literal 1065353216) is written at 0x198. [field:this:0x0000015C, field:this:0x00000160, field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000174, field:this:0x00000178, field:this:0x0000017C, field:this:0x00000180, field:this:0x00000184, field:this:0x00000188, field:this:0x00000198]
    // CALCULATION: Transform the orientation vector at this+0x24/0x28/0x2C by the new matrix: result at this+0x18C is matrix row0 dot vector, this+0x190 is row1 dot vector, this+0x194 is row2 dot vector. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x0000018C, field:this:0x00000190, field:this:0x00000194]
    // RETURN: Return 0 (fixed result). [source:raw]

    // Conservative worker pseudocode:
    //   InterruptDispatch(a2); InterruptDispatch(a3); InterruptDispatch(a4);
    //   this[0x30] = a2; this[0x34] = a3; this[0x38] = a4;
    //   sx=sin(a2); cx=cos(a2); sy=sin(a3); cy=cos(a3); sz=sin(a4); cz=cos(a4);
    //   this[0x15C] = cz*cy - sz*sy*sx; this[0x16C] = -(sz*cx); this[0x17C] = cz*sy*sx + cy*sz;
    //   this[0x160] = -sy*cx; this[0x170] = sx; this[0x180] = cz*cx;
    //   this[0x164] = cy*sz*sx + cz*sy; this[0x174] = cy*cx; this[0x184] = sz*sy - cz*cy*sx;
    //   this[0x168] = this[0x178] = this[0x188] = 0; this[0x198] = 1.0f;
    //   this[0x18C] = this[0x15C]*this[0x24] + this[0x17C]*this[0x2C] + this[0x28]*this[0x16C];
    //   this[0x190] = this[0x28]*this[0x184] + this[0x2C]*this[0x170] + this[0x24]*this[0x160];
    //   this[0x194] = this[0x174]*this[0x28] + this[0x2C]*this[0x180] + this[0x24]*this[0x164];
    //   return 0;
    // UNRESOLVED: Global dbl_5B8960 is absent from the raw source text; it may back the sin/cos constants or another helper and cannot be tied to a specific operation here.
    // UNRESOLVED: The exact rotation convention (axis order and handedness) of the matrix entries is not proven without an independent math check.
    // UNRESOLVED: InterruptDispatch's effect on the angle values (normalization? clamping?) is not documented in this function.
}
