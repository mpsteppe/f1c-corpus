// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D47D
// Canonical corpus name: TransformInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TransformInit_0050d47d.c

void UnknownObject::TransformInit()
{
    // Initializes a 4x4 matrix at a1 to a diagonal form. Row-major elements: (0,0) = a2, (1,1) = a3, (2,2) = a4, (3,3) = 1.0, with every other element zeroed as a float. Writes occur at byte offsets 0x0..0x3C (element stride 4 bytes). Returns the original a1 pointer. Structurally a twin of F_4x4MatrixMultiply (0050cbb6) per the cluster prelabel.
    // ASSIGNMENT: Matrix row 0: store a2 as the DWORD at offset 0x0 and zero floats at offsets 0x4, 0x8, 0xC, 0x10. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Matrix row 1: store a3 as the DWORD at offset 0x14 and zero floats at offsets 0x18, 0x1C, 0x20, 0x24. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Matrix row 2: store a4 as the DWORD at offset 0x28 and zero floats at offsets 0x2C, 0x30, 0x34, 0x38. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // ASSIGNMENT: Matrix row 3: store the constant 1.0 at offset 0x3C (homogeneous diagonal element). [field:this:0x0000003C, source:raw]
    // RETURN: Return the original a1 pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D47D(float* m, int s0, int s1, int s2) {
    //     m[0]  = (float)s0; m[1] = 0.0f; m[2] = 0.0f; m[3] = 0.0f;
    //     m[4]  = 0.0f;      m[5] = (float)s1; m[6] = 0.0f; m[7] = 0.0f;
    //     m[8]  = 0.0f;      m[9] = 0.0f;      m[10] = (float)s2; m[11] = 0.0f;
    //     m[12] = 0.0f;      m[13] = 0.0f;     m[14] = 0.0f;      m[15] = 1.0f;
    //     return (int)m;
    //   }
    // UNRESOLVED: Whether a2/a3/a4 are per-axis scale factors, translation components, or another diagonal interpretation depends on the caller's use of the matrix and is not known here.
    // UNRESOLVED: No callers are recorded in the packet, so the matrix's semantic role is unverified.
}
