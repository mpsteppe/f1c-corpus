// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D507
// Canonical corpus name: F_44IdentityMatrixWithTranslation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_44IdentityMatrixWithTranslation_0050d507.c

void UnknownObject::IdentityMatrixWithTranslation()
{
    // Fills a 4x4 matrix at a1 with the identity and places a translation in the last column. Row-major element layout: diagonal elements (0,0), (1,1), (2,2) are 1.0 and (3,3) is 1.0; the last-column elements at byte offsets 0x30, 0x34, 0x38 receive the raw DWORD arguments a2, a3, a4; every other element is zeroed as a float. Returns the original a1 pointer. The canonical name labels this an identity matrix with translation, consistent with the observed element pattern.
    // ASSIGNMENT: Matrix row 0: store 1.0 at byte offset 0x0 and zero floats at byte offsets 0x4, 0x8, 0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Matrix row 1: zero floats at byte offsets 0x10, 0x18, 0x1C and store 1.0 at byte offset 0x14. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Matrix row 2: zero floats at byte offsets 0x20, 0x24, 0x2C and store 1.0 at byte offset 0x28. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Matrix row 3 (last column): store the raw arguments a2, a3, a4 at byte offsets 0x30, 0x34, 0x38 respectively, and store 1.0 at byte offset 0x3C (homogeneous element). [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Return the original a1 pointer unchanged. [function:0x0050D507, source:raw]

    // Conservative worker pseudocode:
    //   float* IdentityMatrixWithTranslation(float* m, int a2, int a3, int a4) {
    //     m[0] = 1.0f;  m[1] = 0.0f;  m[2] = 0.0f;  m[3] = 0.0f;
    //     m[4] = 0.0f;  m[5] = 1.0f;  m[6] = 0.0f;  m[7] = 0.0f;
    //     m[8] = 0.0f;  m[9] = 0.0f;  m[10] = 1.0f; m[11] = 0.0f;
    //     m[12] = (float)a2; m[13] = (float)a3; m[14] = (float)a4; m[15] = 1.0f;
    //     return m;
    //   }
    // UNRESOLVED: The decompiler types a2/a3/a4 as int and stores them with a raw _DWORD write while the surrounding elements are float writes; whether the caller supplies floats via a different ABI view is not known here.
    // UNRESOLVED: Whether the matrix is consumed as row-major or column-major by callers is not established; the translation-in-last-column interpretation follows the canonical name.
    // UNRESOLVED: No callers are recorded in the packet, so the translation components' axis mapping is unverified.
}
