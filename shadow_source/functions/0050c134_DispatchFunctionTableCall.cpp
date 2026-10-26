// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C134
// Canonical corpus name: sub_50C134
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50C134_0050c134.c

void UnknownObject::DispatchFunctionTableCall()
{
    // Delegation stub: calls sub_50FEA7 with the constant argument 1 (an enable/enter step), then tail-delegates all six arguments (a1..a5 plus float a6) through the function pointer stored at 0x005D7884 and returns that indirect call's result. No guards and no other work; the actual behavior is defined by the current slot in the 0x005D7884 dispatch table.
    // CALL: Call sub_50FEA7 with the constant argument 1 (enable/enter step) before delegating. [callee:0x0050FEA7, source:raw]
    // CALL: Load the function pointer off_5D7884 from 0x005D7884 and call it with a1, a2, a3, a4, a5, a6 passed through unchanged. [global:0x005D7884, source:raw]
    // RETURN: Return the result of the off_5D7884 indirect call. [function:0x0050C134, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50C134(int a1, int a2, int a3, int a4, int a5, float a6) {
    //     sub_50FEA7(1);
    //     return off_5D7884(a1, a2, a3, a4, a5, a6);
    //   }
    // UNRESOLVED: callee:0x0050C134 is a self-reference from static call analysis; the raw source contains no recursive call to sub_50C134.
    // UNRESOLVED: The function pointer target at 0x005D7884 and the purpose of the sub_50FEA7(1) call are not resolved by this packet.
}
