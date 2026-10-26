// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596BF3
// Canonical corpus name: Base10NegativeSpecialCase
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Base10NegativeSpecialCase_00596bf3.c

void UnknownObject::Base10NegativeSpecialCase()
{
    // Integer-to-string conversion dispatch with a special case for signed base-10 output. When the requested base a3 is 10 and the value a1 is negative, calls UintToStringConversion(a1, a2, 10, 1); otherwise calls UintToStringConversion(a1, a2, a3, 0). The final argument toggles the signed/negative-handling mode (1 for signed base-10, 0 otherwise). Returns a2 unchanged, which is the destination buffer passed to the conversion. Called by sub_58FD90 (0x0058FD90), the shared number-formatting caller.
    // GUARD: Test a3 == 10 && a1 < 0; only base-10 formatting of a negative value takes the signed path. [source:raw]
    // CALL: Signed base-10 path: UintToStringConversion(a1, a2, 10, 1). [callee:0x00596C20, source:raw]
    // CALL: Fallback path for any other base or non-negative value: UintToStringConversion(a1, a2, a3, 0). [callee:0x00596C20, source:raw]
    // RETURN: Return a2 (the destination buffer) after conversion. [source:raw]
    // CALL: Invoked by sub_58FD90 (0x0058FD90), the shared number-formatting caller. [caller:0x0058FD90]

    // Conservative worker pseudocode:
    //   int sub_596BF3(int value, int buffer, int base) {
    //     if (base == 10 && value < 0)
    //       UintToStringConversion(value, buffer, 10, 1);
    //     else
    //       UintToStringConversion(value, buffer, base, 0);
    //     return buffer;
    //   }
    // UNRESOLVED: UintToStringConversion (0x00596C20) is not defined in this packet; its exact signature and the meaning of its last (mode) argument are inferred from the two call sites.
    // UNRESOLVED: a2 is assumed to be an output buffer pointer because it is returned unchanged; the underlying type is unproven.
    // UNRESOLVED: Why base-10 negatives need a distinct signed mode while other bases never do is caller/domain knowledge outside this packet.
}
