// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005649D0
// Canonical corpus name: CallChainWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallChainWrapper_005649d0.c

void UnknownObject::CallChainWrapper()
{
    // Fastcall wrapper that first dispatches through an indirect function pointer (IndirectCallViaFunctionPointer, 0x00564890) with a1 and a3, discarding its result, then returns the result of AlignedMemoryCopyFromStructBuffer (0x00564960) applied to a1, a2, a3. Appears on the AI subsystem path and is invoked by FunctionPointerCallWithErrorHandling (0x00564780).
    // CALL: Call IndirectCallViaFunctionPointer(0x00564890) with a1 and a3; its return value is discarded. [callee:0x00564890, source:raw]
    // CALL: Call AlignedMemoryCopyFromStructBuffer(0x00564960) with a1, a2 and a3; its result becomes the function return value. [callee:0x00564960, source:raw]
    // RETURN: Return the AlignedMemoryCopyFromStructBuffer result as the wrapper's unsigned return value. [function:0x005649D0, source:raw]
    // CALL: Invoked by FunctionPointerCallWithErrorHandling (0x00564780) as the AI-chain entry point. [caller:0x00564780, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_5649D0(int a1, const void *a2, int a3) {
    //     IndirectCallViaFunctionPointer(a1, a3);
    //     return AlignedMemoryCopyFromStructBuffer(a1, a2, a3);
    //   }
    // UNRESOLVED: The meaning of a3 (consumed by both helpers, likely a count or selector) is caller-supplied and not resolved here.
    // UNRESOLVED: Why IndirectCallViaFunctionPointer's result is discarded while AlignedMemoryCopyFromStructBuffer's is returned is not established.
}
