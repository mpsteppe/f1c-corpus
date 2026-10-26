// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005987C1
// Canonical corpus name: FactoryWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FactoryWrapper_005987c1.c

void UnknownObject::FactoryWrapper()
{
    // One-line delegation stub: calls LocaleStreamObjectConstructSimplified (sub_598A41) with the fixed constant arguments 0 and 1 and returns its result unchanged. The corpus name FactoryWrapper and the LEGACY ABI lead Factory_Wrapper describe the same behavior: a wrapper that forwards two constants to the locale-stream constructor, consistent with a factory entry point. The owner and the identity of the produced object are unconfirmed.
    // CALL: Call LocaleStreamObjectConstructSimplified (sub_598A41) with fixed constant arguments 0 and 1; no arguments are computed from locals or state. [callee:0x00598A41, source:raw]
    // RETURN: Return the callee's result directly; the function performs no other work. [source:raw, abi:lead, function:0x005987C1]

    // Conservative worker pseudocode:
    //   int FactoryWrapper() {
    //     return LocaleStreamObjectConstructSimplified(0, 1);
    //   }
    // UNRESOLVED: The packet facts report a read of global dword_8D43C8 (DERIVED: LocaleManagementStruct), but the raw source shows only the constant-argument call; the global access does not appear in the decompiled body and its role here is unresolved.
    // UNRESOLVED: The meaning of the fixed arguments 0 and 1 (constructor flags or indices) is not documented by the packet.
    // UNRESOLVED: Whether this wrapper is the canonical factory for the locale stream object or a secondary entry point is unconfirmed.
}
