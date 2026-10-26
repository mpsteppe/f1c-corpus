// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005883E5
// Canonical corpus name: FloatRoundednessCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatRoundednessCheck_005883e5.c

void UnknownObject::FloatRoundednessCheck()
{
    // Double precision roundedness check operating on an x87 stack value (a1 arriving in st0). The value is preserved to _ST6 and rounded in place with frndint; if the rounded result equals the original a1 (a1 is already an integer), the value is scaled by the global double dbl_5E63B0 (0x005E63B0) and rounded again. No observed persistent field is written; the result stays in x87 state. Called on the frame path by sub_588212 (0x00588212).
    // ASSIGNMENT: Save the input double a1 (passed in x87 st0) into _ST6. [source:raw]
    // CALCULATION: frndint: round the x87 stack value in place to the nearest integer. [source:raw]
    // GUARD: Compare _ST6 (the saved original a1) with the rounded value; equality indicates a1 is already an integer. [source:raw]
    // CALCULATION: When a1 is integral, multiply it by the global double dbl_5E63B0 (0x005E63B0). [source:raw, global:0x005E63B0]
    // CALCULATION: frndint: round the scaled value to the nearest integer. [source:raw]
    // CALL: Invoked by sub_588212 (0x00588212) on the frame path. [caller:0x00588212, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5883E5(double a1) {        // a1 arrives in x87 st0
    //     _ST6 = a1;                        // save original
    //     __asm { frndint }                 // round st0 to integer
    //     if (_ST6 == a1) {                 // original a1 already integral
    //       _ST6 = a1 * dbl_5E63B0;         // scale by global at 0x005E63B0
    //       __asm { frndint }               // round scaled value
    //     }
    //   }
    // UNRESOLVED: The value and purpose of the multiplier dbl_5E63B0 (0x005E63B0) are unknown from this packet.
    // UNRESOLVED: No persistent field is written, so the consumer of the rounded result (left in x87 state) is not visible here.
    // UNRESOLVED: The role of caller sub_588212 (0x00588212) for this helper is unresolved.
}
