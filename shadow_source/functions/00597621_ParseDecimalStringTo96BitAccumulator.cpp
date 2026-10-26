// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597621
// Canonical corpus name: sub_597621
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_597621_00597621.c

void UnknownObject::ParseDecimalStringTo96BitAccumulator()
{
    // Reads a2 ASCII digits from a1 into a 96-bit fixed-point accumulator at a3 (multiply-by-10, add-digit per character via CRTAdd12 and F_96BitLeftShiftBy1), then normalizes: shifts out leading zero 16-bit words and bits while adjusting the exponent accumulator v11, stores the final exponent word at a3+10 and returns it. Called from sub_596245.
    // ASSIGNMENT: Initialize the exponent accumulator v11 to 16462 (0x404E) and zero the 12-byte 96-bit accumulator at a3. [source:raw]
    // GUARD: Parse digits only when the digit count a2 is non-zero. [source:raw]
    // LOOP: For each digit: shift the 96-bit accumulator left by 2 (F_96BitLeftShiftBy1), add the saved previous value (CRTAdd12), shift left by 1 more, then add the digit byte from a1 (CRTAdd12); advance the string pointer. [callee:0x00597568, callee:0x005975C6, caller:0x00596245, source:raw]
    // LOOP: Normalization: while the high DWORD of the 96-bit accumulator is zero, shift the value left by 16 bits and add 65520 (0xFFF0) to the exponent accumulator v11. [source:raw]
    // LOOP: Normalization: while the mantissa's top bit (0x8000) is clear, shift the 96-bit value left by 1 (F_96BitLeftShiftBy1) and add 65535 (0xFFFF) to v11. [callee:0x005975C6, source:raw]
    // ASSIGNMENT: Store the final exponent word v11 at a3+10 and return it as the __int16 result. [source:raw]

    // Conservative worker pseudocode:
    //   v11 = 16462;
    //   zero96(a3);
    //   if (a2) {
    //     for (i = 0; i < a2; i++) {
    //       saved = read96(a3);
    //       shift96left(a3, 2);    /* F_96BitLeftShiftBy1 x2 * /
    //       add96(a3, &saved);     /* CRTAdd12: *=5, then shift gives *=10 * /
    //       shift96left(a3, 1);
    //       add96(a3, a1);         /* add digit * /
    //       a1++;
    //     }
    //   }
    //   while (high dword == 0) {
    //     shift96left(a3, 16); v11 += 65520;
    //   }
    //   while ((high word & 0x8000) == 0) {
    //     shift96left(a3, 1); v11 += 65535;
    //   }
    //   *(WORD*)(a3 + 10) = v11;
    //   return v11;
    // UNRESOLVED: Output format: the 96-bit mantissa plus exponent word at a3+10 form a custom fixed-point representation whose scale and consumer are not established from packet evidence.
    // UNRESOLVED: Packet field evidence_ref 'field:this:0x00000000' uses base 'this' on a __cdecl function; it likely corresponds to the low DWORD of the accumulator at a3 but the base naming is inconsistent.
    // UNRESOLVED: Prelabel cluster attribution (structural twin of MultiFieldPointerFree) conflicts with the observed digit-parse semantics and was not adopted.
}
