// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597AA0
// Canonical corpus name: sub_597AA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_597AA0_00597aa0.c

void UnknownObject::Packed96BitMultiply()
{
    // Multiplies two packed 96-bit floating-point-like values. Sign bits are XORed from the packed WORD at +0xA, low 15-bit exponents are added, and the 96-bit mantissas (dwords at +0/+4/+8) are multiplied through a 6-term cross-multiplication loop with overflow-checked carries, then normalized and rounded via shift helpers. The result mantissa is written back into a1 and the new exponent is returned in EAX.
    // CALCULATION: Read packed sign/exponent WORDs at a1+0xA and a2+0xA; compute sign as XOR of the two high bits (v6 & 0x8000) and each operand exponent as the low 15 bits. [field:this:0x0000000A, source:raw]
    // CALCULATION: Add the two exponents (v10 = v8 + result) and classify the result against bounds 0x3FBF and 0xBFFD to select the output path. [source:raw]
    // GUARD: If either exponent is at the 0x7FFF cap or the exponent sum exceeds 0xBFFD, the result is out of range and the output mantissa is zeroed. [source:raw]
    // ASSIGNMENT: Zero the output mantissa dwords at a1+0, a1+4 and a1+8 (quick zero-result path). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Zero-exponent special case: when an operand mantissa (dwords at +8/+4/+0 of a1 or a2) is entirely zero, take the fast zero-result path. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // LOOP: Five-iteration outer loop over mantissa words; an inner do-while multiplies the six cross-terms of the two mantissas, propagating carries between the three product dwords. [callee:0x00597547, field:this:0x00000000, field:this:0x00000002, field:this:0x00000004, field:this:0x00000006, field:this:0x00000008, source:raw]
    // CALL: OverflowCheckedUnsignedAddition performs unsigned addition with overflow detection for the mantissa cross-term products and carry propagation. [callee:0x00597547]
    // CALL: F_96BitLeftShiftBy1 left-shifts the 96-bit product by one bit for exponent normalization. [callee:0x005975C6]
    // CALL: F_96BitRightShift right-shifts the 96-bit product for denormalization and rounding with the guard bit. [callee:0x005975F4]
    // RETURN: Returns the newly computed exponent of the product in EAX; the packed result (mantissa dwords + sign/exponent WORD) is written back into a1. [field:this:0x0000000A, function:0x00597AA0, source:raw]

    // Conservative worker pseudocode:
    //   sign = (WORD(a1+0x0A) ^ WORD(a2+0x0A)) & 0x8000;
    //   sum = (WORD(a1+0x0A) & 0x7FFF) + (WORD(a2+0x0A) & 0x7FFF);
    //   if (exponents capped or sum exceeds 0xBFFD) { zero mantissa dwords; return; }
    //   product = 0;
    //   for each of 5 word positions: for each cross-term: OverflowCheckedUnsignedAddition(product, word_a * word_b);
    //   normalize product with F_96BitLeftShiftBy1 / F_96BitRightShift; round on guard bit;
    //   pack sign/exponent into a1+0x0A; store mantissa into a1+0/+4/+8; return exponent;
    // UNRESOLVED: The truncation of the raw source hides part of the normalization/rounding branch; the shift-helper sequence is inferred from the callee list and the existing analysis fill.
}
