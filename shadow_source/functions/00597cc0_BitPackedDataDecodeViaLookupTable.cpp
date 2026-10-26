// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597CC0
// Canonical corpus name: BitPackedDataDecodeViaLookupTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitPackedDataDecodeViaLookupTable_00597cc0.c

void UnknownObject::BitPackedDataDecodeViaLookupTable()
{
    // Scales a packed 96-bit value in a1 by a table-driven factor derived from the exponent a2. Uses a positive-exponent lookup table rooted at dword_5E9C38 (base - 96 bytes) for a2 > 0 and a negative-exponent table rooted at unk_5E9D98 (base - 96 bytes) after negating a2 when a2 < 0. Consumes the exponent 3 bits (one octal digit) per iteration, advances the table cursor by 84 bytes per digit, selects a 12-byte packed entry by digit, and multiplies the accumulator via sub_597AA0. If a3 is zero, the output *a1 is initialized to zero first. Returns void with the result in a1.
    // ASSIGNMENT: Select the default lookup-table base for positive exponents: v3 = (char *)&dword_5E9C38[-24], i.e. dword_5E9C38 minus 96 bytes. [global:0x005E9C38, source:raw]
    // GUARD: Early-out when a2 is zero: nothing is written to a1 and the function returns. [source:raw]
    // GUARD: When a2 < 0, negate a2 and switch the table base to unk_5E9D98 - 96 (reciprocal-power table). [global:0x005E9D98, source:raw]
    // ASSIGNMENT: When a3 is zero, initialize the output *a1 to 0 before the decoding loop. [field:this:0x00000000, source:raw]
    // LOOP: Iterate while a2 != 0, consuming 3 bits per iteration: a2 >>= 3 and digit v5 = v4 & 7 where v4 is the low byte of a2. [source:raw]
    // CALCULATION: Advance the table cursor by one section per octal digit: v3 += 84. [source:raw]
    // GUARD: Only non-zero digits are processed; a zero digit (v5 == 0) skips the table lookup and multiply for this step. [source:raw]
    // CALCULATION: Select the 12-byte packed entry for the digit: v6 = &v3[12 * v5]. [source:raw]
    // GUARD: When the first word of the entry is >= 0x8000 the entry is in an extended form: expand 12 bytes into a local 96-bit value (8-byte v8 plus 4-byte v9) and decrement one middle dword. [source:raw]
    // CALL: Multiply the accumulated packed value in a1 by the selected table entry via sub_597AA0 for this digit. [callee:0x00597AA0, field:this:0x00000000, source:raw]
    // RETURN: Void return; the scaled packed result is delivered in a1. [source:raw]
    // CALL: Called by sub_596245 and sub_5976E8 as a packed-value scaling step on the frame path. [caller:0x00596245, caller:0x005976E8, source:raw]

    // Conservative worker pseudocode:
    //   void sub_597CC0(unsigned short *out, int exponent, int initFlag) {
    //     char *table = (char *)&dword_5E9C38[-24];
    //     if (exponent) {
    //       if (exponent < 0) { exponent = -exponent; table = (char *)&unk_5E9D98 - 96; }
    //       if (!initFlag) *out = 0;
    //       while (exponent) {
    //         int digit = exponent & 7;
    //         table += 84;
    //         exponent >>= 3;
    //         if (digit) {
    //           char *entry = table + 12 * digit;
    //           if (*(unsigned short *)entry >= 0x8000) {
    //             __int64 v8 = *(__int64 *)entry;
    //             int v9 = *(int *)(entry + 12);
    //             *((unsigned int *)&v8 + 1) -= 1;
    //             entry = (char *)&v8;
    //           }
    //           sub_597AA0((int)out, (int)entry);
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: Exact numeric transform encoded by the two tables is not evidenced here; scaling of a packed 96-bit operand is inferred from the multiply helper sub_597AA0.
    // UNRESOLVED: Meaning of the extended-encoding path (first word >= 0x8000) and the mid-value decrement is unclear.
    // UNRESOLVED: Caller contract for a3 (whether the output should be zero-initialized) is unconfirmed.
}
