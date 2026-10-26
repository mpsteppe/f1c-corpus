// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DCE5
// Canonical corpus name: FloadWithFBFloatLoadWithNaNCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloadWithFBFloatLoadWithNaNCheck_0058dce5.c

void UnknownObject::FloadWithFBFloatLoadWithNaNCheck()
{
    // Loads an 8-byte double from the pointer argument a2 (fields at this + 0x0 and this + 0x4). If the exponent bits of the upper dword (a2[1] masked by 0x7FF00000) are not all set, the value is a finite double and is returned unchanged. When the exponent is all-ones (Inf/NaN), the 64-bit bit pattern is left-shifted by 11 and returned as the result double. Called on the frame path by sub_588212 (0x00588212).
    // GUARD: Test a2[1] (upper dword, this + 0x4) against the exponent mask 0x7FF00000; unequal means the double is finite (not Inf/NaN). [source:raw, field:this:0x00000004]
    // RETURN: Return the 64-bit value at a2 (this + 0x0 / this + 0x4) interpreted as a double when it is finite. [source:raw, field:this:0x00000000, field:this:0x00000004]
    // CALCULATION: When the exponent is all-ones (Inf/NaN), left-shift the 64-bit double bit pattern at a2 by 11 bits. [source:raw, field:this:0x00000000, field:this:0x00000004]
    // ASSIGNMENT: Store the shifted bit pattern into the double result. [source:raw]
    // RETURN: Return the transformed double for the Inf/NaN case. [source:raw]
    // CALL: Called by sub_588212 (0x00588212) on the frame path. [caller:0x00588212, source:raw]

    // Conservative worker pseudocode:
    //   double sub_58DCE5(int a1, _DWORD *a2) {
    //     if ((a2[1] & 0x7FF00000) != 0x7FF00000)
    //       return *(double *)a2;
    //     *(_QWORD *)&result = *(_QWORD *)a2 << 11;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the left-shift-by-11 transform for Inf/NaN inputs is unknown; it may normalize a NaN/Inf payload but the consumer is not visible here.
    // UNRESOLVED: The a1 argument is unused by the body; its role for the caller sub_588212 (0x00588212) is unresolved.
    // UNRESOLVED: The 'this' field base is an alias for the pointer argument a2, not evidence of a distinct class instance.
}
