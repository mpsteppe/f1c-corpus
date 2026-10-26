// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588570
// Canonical corpus name: FloatConvertWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatConvertWrapper_00588570.c

void UnknownObject::FloatConvertWrapper()
{
    // Wrapper that forwards a float80 (extended-precision) operand: passes the 64-bit view of the ST0 value to FloatExponentExtractWithNaNGuard, then returns the result of the adjacent helper sub_58858D, whose outputs are produced through the __usercall register/stack convention. The legacy ABI label identifies the chain as a float80-to-double conversion with a two-step call pattern.
    // CALL: Call FloatExponentExtractWithNaNGuard(a1, HIDWORD(a1)) on the 64-bit representation of the operand to extract the exponent and guard against NaN. [callee:0x0058DD28, source:raw]
    // CALL: Call sub_58858D(v2, v3) passing the two stack slots left by the prior call's register/stack side effects. [callee:0x0058858D, source:raw]
    // RETURN: Return sub_58858D's result in EAX. [source:raw]

    // Conservative worker pseudocode:
    //   FloatExponentExtractWithNaNGuard(a1, HIDWORD(a1));
    //   return sub_58858D(v2, v3);
    // UNRESOLVED: v2 and v3 are uninitialized in the decompiled view; they are populated by FloatExponentExtractWithNaNGuard through the __usercall register/stack convention that Hex-Rays cannot track as an explicit output.
    // UNRESOLVED: The actual float80-to-double conversion steps live in sub_58858D and 0x0058DD28, outside this function body.
}
