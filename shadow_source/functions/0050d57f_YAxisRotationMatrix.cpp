// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D57F
// Canonical corpus name: YAxisRotationMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/YAxisRotationMatrix_0050d57f.c

void UnknownObject::YAxisRotationMatrix()
{
    // Fills a 4x4 matrix at a1 with a rotation built from the angle a2, returning a1. Element 0 (byte offset 0x0) is set to 1.0 and element 15 (byte offset 0x3C) to 1.0; a 2x2 rotation block is placed at elements (1,1), (1,2), (2,1), (2,2) (byte offsets 0x14, 0x18, 0x24, 0x28) using cos(a2) and sin(a2), with -sin(a2) at the (2,1) element; every other element is zeroed. Under a standard row-major layout this pattern places the rotation block on the middle rows/columns, which corresponds to rotation about the first (X) axis rather than the Y axis the canonical and legacy ABI names suggest; the axis labeling cannot be resolved from this packet alone.
    // CALCULATION: Evaluate v3 = cos(a2) and v4 = sin(a2) before filling the matrix. [source:raw]
    // ASSIGNMENT: Matrix row 0: store 1.0 at byte offset 0x0 and zero floats at byte offsets 0x4, 0x8, 0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Matrix row 1: store 0.0 at byte offset 0x10, cos(a2) at byte offset 0x14, sin(a2) at byte offset 0x18, and 0.0 at byte offset 0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Matrix row 2: store 0.0 at byte offset 0x20, -sin(a2) at byte offset 0x24, cos(a2) at byte offset 0x28, and 0.0 at byte offset 0x2C. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Matrix row 3: store 0.0 at byte offsets 0x30, 0x34, 0x38 and 1.0 at byte offset 0x3C (homogeneous element). [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Return the original a1 pointer unchanged. [function:0x0050D57F, source:raw]

    // Conservative worker pseudocode:
    //   float* YAxisRotationMatrix(float* m, float angle) {
    //     float c = cos(angle), s = sin(angle);
    //     m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f; m[3] = 0.0f;
    //     m[4] = 0.0f; m[5] = c;    m[6] = s;    m[7] = 0.0f;
    //     m[8] = 0.0f; m[9] = -s;   m[10] = c;   m[11] = 0.0f;
    //     m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
    //     return m;
    //   }
    // UNRESOLVED: The element pattern (1.0 on element 0, rotation block on the middle rows/columns 1-2) matches a rotation about the first axis under standard row-major convention, while the canonical name YAxisRotationMatrix and legacy ABI name Y_Axis_Rotation_Matrix label it a Y-axis rotation; the game's axis-naming or storage convention resolves this and is not available in this packet.
    // UNRESOLVED: The sign convention (sin at element (1,2), -sin at element (2,1)) is the transpose/negative-angle form of a canonical rotation; which handedness the game expects is unverified.
    // UNRESOLVED: cos and sin have no callee entries in the packet, so the concrete math library routine is not identified.
    // UNRESOLVED: No callers are recorded in the packet, so the matrix's role (e.g. which transform or object it feeds) is unverified.
}
