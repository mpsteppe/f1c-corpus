// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D728
// Canonical corpus name: LockFunctionPointerCall_d728
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LockFunctionPointerCall_d728_0050d728.c

void UnknownObject::LockFunctionPointerCall_d728()
{
    // Dispatch thunk. Ensures the shared version-adaptive function table is initialized by calling sub_50FEA7(1u), then tail-calls the function pointer stored in the global dispatch slot off_5D7870, forwarding a1 (int), a2 (int) and a3 (float) unchanged and returning its result directly. The canonical name LockFunctionPointerCall_d728 is the IDA label; it names the thunk's role, not the dispatched implementation's purpose.
    // CALL: Call sub_50FEA7(1u) before dispatch; lazily initializes the shared function table on first call (enable flag 1u). [callee:0x0050FEA7, source:raw]
    // CALL: Tail-call the function pointer loaded from the global dispatch slot off_5D7870, forwarding a1, a2, a3 unchanged. [global:0x005D7870, function:0x0050D728, source:raw]
    // RETURN: Return the value produced by the indirect call through off_5D7870. [function:0x0050D728, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D728(int a1, int a2, float a3) {
    //     sub_50FEA7(1u);                        // ensure function table initialized
    //     return off_5D7870(a1, a2, a3);         // tail-call dispatch slot
    //   }
    // UNRESOLVED: The indirect dispatch target off_5D7870 is a slot of a shared function table installed by sub_50FEA7; the concrete implementation it resolves to on this build is not identified by this packet.
    // UNRESOLVED: The callee entry callee:0x0050D728 lists the function's own address (a self-loop artifact of the dispatch slot), not a genuine recursive call.
    // UNRESOLVED: The canonical/ABI name LockFunctionPointerCall_d728 is the IDA label; it describes the thunk's dispatch shape, not the purpose of the implementation behind the slot.
}
