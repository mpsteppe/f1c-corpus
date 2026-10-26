// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DCCC
// Canonical corpus name: sub_58DCCC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58DCCC_0058dccc.c

void UnknownObject::RoundingModeSelectFromStatus()
{
    // Float-conversion rounding helper. Given a status word a1 and an in-register float result, conditionally applies a +1.0 compensation when the 0x80000 status bit is clear; returns the value unchanged when the bit is set. The legacy ABI label identifies it as a rounding-mode select driven by the x87 status word, consistent with the bit test.
    // GUARD: Test the status bit: when (a1 & 0x80000) == 0 the compensated value is returned, otherwise the input value is returned unchanged. [source:raw]
    // CALCULATION: Compute the compensated value result + 1.0; the packet global dbl_5B8E00 is read and is the source of the 1.0 literal folded into this expression. [global:0x005B8E00, source:raw]
    // RETURN: Return result + 1.0 when the 0x80000 status bit is clear. [source:raw]
    // RETURN: Return result unchanged when the 0x80000 status bit is set. [source:raw]
    // CALL: Invoked by sub_58858D (0x0058858D) and sub_5894BD (0x005894BD) as a rounding-mode/float-conversion helper on the frame path. [caller:0x0058858D, caller:0x005894BD, source:raw]

    // Conservative worker pseudocode:
    //   double sub_58DCCC(int a1, double result) {
    //     if ((a1 & 0x80000) == 0)
    //       return result + 1.0;
    //     return result;
    //   }
    // UNRESOLVED: The mapping of global dbl_5B8E00 to the +1.0 literal is inferred from the read flag and the expression; the literal itself appears inline in the raw source.
    // UNRESOLVED: The exact status-word semantics of the 0x80000 bit (and how callers derive a1) are caller context, not documented in this function.
}
