// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DD28
// Canonical corpus name: FloatExponentExtractWithNaNGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatExponentExtractWithNaNGuard_0058dd28.c

void UnknownObject::FloatExponentExtractWithNaNGuard()
{
    // Extracts the IEEE-754 exponent field from a float/double bit pattern. Given a2 as the raw bit pattern, returns the exponent mask value a2 & 0x7FF00000, except when the exponent field is all ones (a2 & 0x7FF00000 == 0x7FF00000, i.e. NaN/Infinity), in which case it returns the full pattern a2 unchanged. The first parameter a1 is unused. Used by float conversion/pass-through paths.
    // ASSIGNMENT: Mask the exponent field: result = a2 & 0x7FF00000. [source:raw]
    // GUARD: Guard on the exponent field being all ones: (a2 & 0x7FF00000) == 0x7FF00000, which identifies NaN/Infinity bit patterns. [source:raw]
    // RETURN: When the exponent field is all ones, return the full pattern a2 unchanged. [source:raw]
    // RETURN: Otherwise return the masked exponent field result. [source:raw]
    // CALL: Invoked by FloatConvertWrapper (0x00588570) and FloatFunctionPassThrough (0x005894A0) to extract or pass through the exponent bits of a float. [caller:0x00588570, caller:0x005894A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58DD28(int a1, int a2) {
    //     int result = a2 & 0x7FF00000;
    //     if ((a2 & 0x7FF00000) == 0x7FF00000) return a2;
    //     return result;
    //   }
    // UNRESOLVED: Role of the unused first parameter a1 is unknown.
    // UNRESOLVED: Whether a2 encodes a 32-bit float or 64-bit double mantissa is not resolvable from this function alone; only the exponent-mask width 0x7FF00000 is known.
    // UNRESOLVED: Downstream use of the extracted exponent by the callers is not visible here.
}
