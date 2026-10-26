// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D97E
// Canonical corpus name: IndirectCallViaGlobalPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectCallViaGlobalPointer_0050d97e.c

void UnknownObject::IndirectCallViaGlobalPointer()
{
    // Dispatch thunk. Ensures the shared version-adaptive function table is initialized by calling sub_50FEA7(1u), then tail-calls the function pointer stored in the global dispatch slot off_5D786C, forwarding a1 (int), a2 (float) and a3, a4, a5 (ints) unchanged and returning its result directly. The canonical name IndirectCallViaGlobalPointer is the IDA label; it describes the thunk's indirect-call shape, not the dispatched implementation's purpose.
    // CALL: Call sub_50FEA7(1u) before dispatch; lazily initializes the shared function table on first call (enable flag 1u). [callee:0x0050FEA7, source:raw]
    // CALL: Tail-call the function pointer loaded from the global dispatch slot off_5D786C, forwarding a1, a2, a3, a4, a5 unchanged. [global:0x005D786C, function:0x0050D97E, source:raw]
    // RETURN: Return the value produced by the indirect call through off_5D786C. [function:0x0050D97E, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D97E(int a1, float a2, int a3, int a4, int a5) {
    //     sub_50FEA7(1u);                        // ensure function table initialized
    //     return off_5D786C(a1, a2, a3, a4, a5); // tail-call dispatch slot
    //   }
    // UNRESOLVED: The indirect dispatch target off_5D786C is a slot of a shared function table installed by sub_50FEA7; the concrete implementation it resolves to on this build is not identified by this packet.
    // UNRESOLVED: The callee entry callee:0x0050D97E lists the function's own address (a self-loop artifact of the dispatch slot), not a genuine recursive call.
    // UNRESOLVED: The canonical/ABI name IndirectCallViaGlobalPointer is the IDA label; it describes the thunk's dispatch shape, not the purpose of the implementation behind the slot.
}
