// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005987F0
// Canonical corpus name: LocaleFunctionCallWrapper_87f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleFunctionCallWrapper_87f0_005987f0.c

void UnknownObject::LocaleFunctionCallWrapper_87f0()
{
    // One-line delegation stub: calls LocaleStreamObjectConstructSimplified (sub_598A41) with the fixed constant arguments 0 and 1 and returns its result unchanged. The corpus name LocaleFunctionCallWrapper_87f0 and the LEGACY ABI lead Locale_Function_Call_Wrapper_5987f0 describe the same behavior: a locale-related wrapper that forwards two constants to the stream constructor. The owner and object identity are unconfirmed.
    // CALL: Call LocaleStreamObjectConstructSimplified (sub_598A41) with fixed constant arguments 0 and 1; no arguments are computed from locals or state. [callee:0x00598A41, source:raw]
    // RETURN: Return the callee's result directly; the function performs no other work. [source:raw, abi:lead, function:0x005987F0]

    // Conservative worker pseudocode:
    //   int LocaleFunctionCallWrapper_87f0() {
    //     return LocaleStreamObjectConstructSimplified(0, 1);
    //   }
    // UNRESOLVED: The packet facts report a read of global dword_8D4210 (DERIVED: ExceptionTypeDesc), but the raw source shows only the constant-argument call; the global access does not appear in the decompiled body and its role here is unresolved.
    // UNRESOLVED: The meaning of the fixed arguments 0 and 1 (constructor flags or indices) is not documented by the packet.
    // UNRESOLVED: The exact locale object constructed and the reason for a dedicated wrapper entry point are unconfirmed.
}
