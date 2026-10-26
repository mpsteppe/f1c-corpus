// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D615
// Canonical corpus name: RotationMatrixYAxis
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixYAxis_0050d615.c

void UnknownObject::RotationMatrixYAxis()
{
    // Fills a 4x4 matrix at a1 with a rotation about the Y axis by the angle a2, returning a1. Row-major element layout: cos(a2) at element (0,0) (byte offset 0x0), -sin(a2) at element (0,2) (byte offset 0x8), 1.0 at element (1,1) (byte offset 0x14), sin(a2) at element (2,0) (byte offset 0x20), cos(a2) at element (2,2) (byte offset 0x28), 1.0 at element (3,3) (byte offset 0x3C), and zeros at every remaining element. The layout matches the canonical and legacy ABI Y-axis rotation naming (the identity diagonal element stays on the middle row/column).
    // CALCULATION: Evaluate v4 = cos(a2) and v3 = sin(a2) before filling the matrix. [source:raw]
    // ASSIGNMENT: Matrix row 0: store cos(a2) at byte offset 0x0, 0.0 at byte offsets 0x4 and 0xC, and -sin(a2) at byte offset 0x8. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Matrix row 1: store 0.0 at byte offsets 0x10, 0x18, 0x1C and 1.0 at byte offset 0x14 (identity element on the Y diagonal). [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Matrix row 2: store sin(a2) at byte offset 0x20, 0.0 at byte offsets 0x24 and 0x2C, and cos(a2) at byte offset 0x28. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Matrix row 3: store 0.0 at byte offsets 0x30, 0x34, 0x38 and 1.0 at byte offset 0x3C (homogeneous element). [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Return the original a1 pointer unchanged. [function:0x0050D615, source:raw]

    // Conservative worker pseudocode:
    //   float* RotationMatrixYAxis(float* m, float angle) {
    //     float c = cos(angle), s = sin(angle);
    //     m[0] = c;  m[1] = 0.0f; m[2] = -s; m[3] = 0.0f;
    //     m[4] = 0.0f; m[5] = 1.0f; m[6] = 0.0f; m[7] = 0.0f;
    //     m[8] = s;  m[9] = 0.0f; m[10] = c; m[11] = 0.0f;
    //     m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
    //     return m;
    //   }
    // UNRESOLVED: The sign pattern (-sin at element (0,2), sin at element (2,0)) is the transpose/negative-angle form of the standard right-handed Y rotation; which handedness the game expects is unverified.
    // UNRESOLVED: cos and sin have no callee entries in the packet, so the concrete math library routine is not identified.
    // UNRESOLVED: No callers are recorded in the packet, so the matrix's role (e.g. which transform or object it feeds) is unverified.
    // UNRESOLVED: The relationship to the near-identical rotation constructor 0050d57f (YAxisRotationMatrix) is not established; 0050d57f places its rotation block on the middle rows/columns rather than the outer X-Z plane and may use a different axis convention.
}
