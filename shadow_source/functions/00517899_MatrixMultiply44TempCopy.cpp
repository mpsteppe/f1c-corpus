// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517899
// Canonical corpus name: F_44MatrixMultiply_7899
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_44MatrixMultiply_7899_00517899.c

void UnknownObject::MatrixMultiply44TempCopy()
{
    // 4x4 matrix multiply with output-alias handling (stdcall, three char pointers: a1 output, a2 first operand, a3 second operand). If either input aliases the output, the product is computed into a stack temp buffer; otherwise it is written directly. On completion, if the temp buffer was used, 64 bytes (0x40) are copied back into a1. Returns a1.
    // GUARD: Guard on (a1 == a2 || a1 == a3): if either input aliases the output, compute into a stack temp buffer instead of writing in place. [source:raw]
    // ASSIGNMENT: v3 = &v11 (stack temp buffer); v12 = v3 records which destination was actually used. [source:raw]
    // LOOP: Outer row loop (v6 from -4 to 0, 4 iterations); the first operand row pointer ECX advances by 16 bytes per row. [source:raw]
    // LOOP: Inner loop (ESI from -4 to 0, 4 iterations) computing one output element per iteration. [source:raw]
    // CALCULATION: x87 dot-product accumulation: four fld/fmul products of the a2 row (ecx) with a3 column elements (edx+esi*4+10h..40h) are summed and stored as a float at v8 (= v3[4*v6+16]). [source:raw]
    // GUARD: Guard on v12 != a1: the result was written to the temp buffer and must be copied back. [source:raw]
    // CALL: qmemcpy copies 0x40 (64) bytes from the temp buffer (v12) into the output a1. [source:raw]
    // RETURN: Return a1 (the output pointer). [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_517899(char *a1, char *a2, char *a3) {
    //     char *dst = a1;
    //     if (a1 == a2 || a1 == a3) dst = &v11;
    //     char *used = dst;
    //     for (int row = 0; row < 4; ++row) {
    //       for (int col = 0; col < 4; ++col) {
    //         ((float *)&dst[row * 16 + col * 4])[0] = dot(row of a2, col of a3);
    //       }
    //     }
    //     if (used != a1) qmemcpy(a1, used, 0x40);
    //     return a1;
    //   }
    // UNRESOLVED: Canonical name F_44MatrixMultiply_7899 indicates a 4x4 matrix multiply; operand order and row/column convention are DERIVED from the canonical name.
    // UNRESOLVED: Whether this routine is a distinct function or a compiler-generated duplicate of another 4x4 multiply is unknown; the packet lists no callers.
}
