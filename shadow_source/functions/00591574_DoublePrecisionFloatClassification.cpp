// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591574
// Canonical corpus name: DoublePrecisionFloatClassification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublePrecisionFloatClassification_00591574.c

void UnknownObject::DoublePrecisionFloatClassification()
{
    // Double-precision float classification routine operating on the x87 stack (a1@st1, a2@st0). Stores the two doubles into locals, then inspects a2's exponent bits in its high word. If the exponent field (mask 0x7FFF0000) is non-zero the function immediately calls FloatingPointRemainder with mode 0. Otherwise it ORs a2's low words into a candidate result; when a2 is non-zero it scales the inputs by the read-only constant dbl_5E7514 (with a1 additionally scaled when a1's exponent field is <= 0x7FBE, selecting mode 3 instead of mode 2) and calls FloatingPointRemainder with the chosen mode. A zero a2 returns the low-word combination directly.
    // ASSIGNMENT: Copy the two stack doubles into locals: a1 into v6 and a2 into v4. [source:raw]
    // GUARD: Classify a2: test (high-word DWORD at v4+6) & 0x7FFF0000; non-zero exponent field selects the special-value path. [source:raw]
    // CALL: Call FloatingPointRemainder with mode 0 on the special-value path. [callee:0x0059136E]
    // CALCULATION: Combine a2's low words (v4[4] | v4[0]) into the candidate result used when a2 is zero. [source:raw]
    // GUARD: Branch on a2 != 0.0; a zero a2 returns the combined low-word result directly. [source:raw]
    // CALCULATION: Select default mode 2 and scale a2 by the read-only double constant dbl_5E7514. [global:0x005E7514, source:raw]
    // GUARD: When a1's exponent field ((WORD4(v6)) & 0x7FFFu) is <= 0x7FBE, promote the mode to 3 and scale a1 by dbl_5E7514. [global:0x005E7514, source:raw]
    // CALL: Call FloatingPointRemainder with the selected mode (2 or 3) and the scaled operands. [callee:0x0059136E]
    // RETURN: Return the combined low-word result when a2 is zero (no remainder call). [source:raw]

    // Conservative worker pseudocode:
    //   int DoublePrecisionFloatClassification(double a1, double a2) {
    //     double a1l = a1;
    //     double a2l = a2;
    //     if ((high32(a2l) & 0x7FFF0000) != 0)
    //       return FloatingPointRemainder(0, a2l, 0, a1l);
    //     int result = low32_high(a2l) | low32_low(a2l);
    //     if (a2l != 0.0) {
    //       int mode = 2;
    //       if ((exponent_field(a1l) & 0x7FFFu) <= 0x7FBE) {
    //         mode = 3;
    //         a1l = a1l * dbl_5E7514;
    //       }
    //       a2l = a2l * dbl_5E7514;
    //       return FloatingPointRemainder(mode, a2l, 0, a1l);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Exact semantics of FloatingPointRemainder's extra packed arguments (the __int128/word slices) are not recoverable from this function alone.
    // UNRESOLVED: Value of dbl_5E7514 is not in the packet; it acts as a scaling constant for the classification path.
    // UNRESOLVED: Bit field layout (high/low words) of the two doubles is implied by the pointer casts but not independently verified.
}
