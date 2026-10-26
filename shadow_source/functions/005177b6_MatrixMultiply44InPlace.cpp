// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005177B6
// Canonical corpus name: F_44MatrixMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_44MatrixMultiply_005177b6.c

void UnknownObject::MatrixMultiply44InPlace()
{
    // 4x4 matrix multiply with output-alias handling (stdcall, three _BYTE pointers: a1 output, a2 first operand, a3 second operand). When the second operand a3 aliases the output a1 and the first operand does not, a specialized in-place path computes and writes rows directly; when the first operand a2 also aliases the output, a3 is copied to a stack buffer first. The general path multiplies rows of a2 by columns of a3 using x87 dot products and returns a1.
    // GUARD: Guard on a3 == a1: the second operand aliases the output, entering the alias-handling path. [source:raw]
    // GUARD: Guard on a2 != a1: within the alias case, take the specialized in-place path (no stack copy). [source:raw]
    // LOOP: Specialized path outer loop over rows (EDI from -4 to 0, 4 iterations), reading column elements of a3 (edx) and advancing the output row v4 by 4 bytes. [source:raw]
    // LOOP: Specialized path inner loop (ESI from -16 to 0, 4 iterations) computing one output element per iteration. [source:raw]
    // CALCULATION: x87 accumulation: four fld/fmul products summed on the stack and stored as a float into the output row (v4[4*ESI+64] = _ET1). [source:raw]
    // CALL: qmemcpy copies 64 bytes of a3 into the stack buffer v16 when a2 also aliases the output (a2 == a1). [source:raw]
    // ASSIGNMENT: a3 = v16: the general path reads the second operand from the stack copy instead of the live output. [source:raw]
    // LOOP: General path outer loop over rows (v13 from -4 to 0, 4 iterations), advancing the operand row pointer ECX and output pointer v10 by 16 bytes each. [source:raw]
    // LOOP: General path inner loop (ESI from -4 to 0, 4 iterations) computing one output element per iteration. [source:raw]
    // CALCULATION: x87 dot-product accumulation: products of the a2 row (ecx) with a3 column elements (edx+esi*4+10h..40h) are summed and stored as a float (v10[4*ESI+16] = _ET1). [source:raw]
    // RETURN: Return a1 (the output pointer). [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *sub_5177B6(_BYTE *a1, _BYTE *a2, _BYTE *a3) {
    //     _BYTE *result = a1;
    //     if (a3 == a1) {
    //       if (a2 != a1) {
    //         /* specialized in-place path: rows of a2 x columns of a3 (== a1) * /
    //         ...;
    //         return result;
    //       }
    //       qmemcpy(v16, a3, 64);
    //       a3 = v16;
    //     }
    //     /* general path: C = A * B, A = a2, B = a3, C = a1 * /
    //     ...;
    //     return result;
    //   }
    // UNRESOLVED: The specialized path (a3 == a1, a2 != a1) reads column elements of a3 from the output buffer while writing rows in place; its arithmetic is assumed equivalent to the general path but not proven.
    // UNRESOLVED: Canonical name F_44MatrixMultiply indicates a 4x4 matrix multiply; operand order (C = a2 * a3) and the row/column convention are DERIVED from the canonical name, not the raw source alone.
}
