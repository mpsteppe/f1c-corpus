// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517AC5
// Canonical corpus name: sub_517AC5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517AC5_00517ac5.c

void UnknownObject::ForwardToSub5179E0WithConstantMode()
{
    // Thin forwarding wrapper. Calls sub_5179E0(a1, 15, a2, a3), inserting the literal constant 15 as the second argument and passing the remaining arguments a2 and a3 through unchanged, then returns sub_5179E0's result. The constant 15 likely selects a mode/parameter consumed by sub_5179E0, but neither function's semantics are recoverable from this packet.
    // CALL: sub_5179E0(a1, 15, a2, a3) is invoked with the forwarded arguments and the literal constant 15 in the second slot. [callee:0x005179E0, source:raw]
    // RETURN: Return the result of sub_5179E0 directly. [function:0x00517AC5, source:raw]

    // Conservative worker pseudocode:
    //   int ForwardToSub5179E0WithConstantMode(_DWORD *a1, _BYTE *a2, int a3) {
    //       return sub_5179E0(a1, 15, a2, a3);
    //   }
    // UNRESOLVED: The meaning of the literal constant 15 (likely a mode/type selector) is not determinable from this packet.
    // UNRESOLVED: The semantics of sub_5179E0 and the roles of a1/a2/a3 are not visible from this packet.
}
