// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E1FD0
// Canonical corpus name: F_3DTransformPointByMatrixAndTranslation
// Owner: CameraTransform [DERIVED]
// Raw source: functions/F_3DTransformPointByMatrixAndTranslation_004e1fd0.c

void CameraTransform::PointTransformByMatrixWithTranslation()
{
    // Pure 3D math helper with no callees, globals or guards. Multiplies the 3x3 rotation matrix stored at this+0x20..0x40 (rows this[8..10], this[11..13], this[14..16]) by the vector at this+0x8E8/0x8EC/0x8F0, adds a translation offset read just before the matrix (this+0x08..0x10 in the raw source, not present in the packet field list) into output a2, and copies the three floats at this+0x14/0x18/0x1C into output a3. Returns a3.
    // CALCULATION: Compute output x: this+0x28 * this+0x8F0 + this+0x24 * this+0x8EC + this+0x8E8 * this+0x20 (matrix row 0 dotted with the this+0x8E8 vector). [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x000008E8, field:this:0x000008EC, field:this:0x000008F0]
    // CALCULATION: Compute output y: this+0x34 * this+0x8F0 + this+0x30 * this+0x8EC + this+0x2C * this+0x8E8 (matrix row 1 dotted with the this+0x8E8 vector). [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x000008E8, field:this:0x000008EC, field:this:0x000008F0]
    // CALCULATION: Compute output z: this+0x40 * this+0x8F0 + this+0x3C * this+0x8EC + this+0x38 * this+0x8E8 (matrix row 2 dotted with the this+0x8E8 vector). [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x000008E8, field:this:0x000008EC, field:this:0x000008F0]
    // CALCULATION: Add the translation offset to each output component; in the raw source the addend reads float slots this+0x08, this+0x0C, this+0x10 (v4 - 3, v4 - 2, v4 - 1) which are not present in the packet field list. [source:raw]
    // ASSIGNMENT: Copy the three floats at this+0x14, this+0x18, this+0x1C into the output a3 as three _DWORDs. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // RETURN: Return the a3 output pointer. [function:0x004E1FD0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_4E1FD0(float* this, float* out, _DWORD* out2) {
    //     out[0] = this[0x28] * this[0x8F0] + this[0x24] * this[0x8EC] + this[0x8E8] * this[0x20] + this[0x08];
    //     out[1] = this[0x34] * this[0x8F0] + this[0x30] * this[0x8EC] + this[0x2C] * this[0x8E8] + this[0x0C];
    //     out[2] = this[0x40] * this[0x8F0] + this[0x3C] * this[0x8EC] + this[0x38] * this[0x8E8] + this[0x10];
    //     out2[0] = *(int*)&this[0x14]; out2[1] = *(int*)&this[0x18]; out2[2] = *(int*)&this[0x1C];
    //     return out2;
    //   }
    // UNRESOLVED: The translation addend is read at this+0x08/0x0C/0x10 in the raw source, but the packet field list only covers this+0x14..0x40 and this+0x8E8..0x8F0; the addend offsets have no packet evidence reference.
    // UNRESOLVED: The existing analysis labels this+0x38..0x40 as a quaternion and this+0x14..0x1C as matrix row 0, but the raw source copies this+0x14..0x1C into a3 and uses this+0x20..0x40 as the 3x3 matrix; the two labelings disagree.
    // UNRESOLVED: Semantic role of the output a3 copy (this+0x14..0x1C) is not characterized by other evidence.
}
