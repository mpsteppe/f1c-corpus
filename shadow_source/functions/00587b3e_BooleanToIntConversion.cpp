// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587B3E
// Canonical corpus name: BooleanToIntConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BooleanToIntConversion_00587b3e.c

void UnknownObject::BooleanToIntConversion()
{
    // One-argument conversion helper: evaluates sub_587AC0(a1), converts the boolean result to an integer by subtracting 1. A true (non-zero) sub_587AC0 result maps to 0; a false (zero) result maps to -1. The result is returned directly. The helper is reused by a very large set of registration/thunk callers across many subsystems.
    // CALL: Evaluate sub_587AC0(a1) and test its return value for non-zero. [source:raw, callee:0x00587AC0]
    // CALCULATION: Normalize the boolean: (sub_587AC0(a1) != 0) yields 1 when true, 0 when false. [source:raw, function:0x00587B3E]
    // CALCULATION: Subtract 1 from the normalized boolean so true maps to 0 and false maps to -1. [source:raw, abi:lead]
    // RETURN: Return the converted integer value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_587B3E(int a1) {
    //     return (sub_587AC0(a1) != 0) - 1;
    //   }
    // UNRESOLVED: The identity and purpose of sub_587AC0 are unknown from this packet; the true-to-0 / false-to--1 mapping is DERIVED from the literal arithmetic, not named by any packet evidence.
    // UNRESOLVED: The function is referenced by over a hundred registration and thunk callers; the reuse pattern suggests a generic callback/conversion helper, but no caller intent is grounded here.
}
