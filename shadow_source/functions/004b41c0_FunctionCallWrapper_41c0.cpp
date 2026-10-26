// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B41C0
// Canonical corpus name: FunctionCallWrapper_41c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_41c0_004b41c0.c

void UnknownObject::FunctionCallWrapper_41c0()
{
    // Trivial forwarder: reads the code address of sub_4B41D0 (0x004B41D0) and passes it to BooleanToIntConversion (0x00587B3E), returning the callee's integer result. The ABI label describes this as forwarding a call to another function with no additional work.
    // CALL: Pass the address of sub_4B41D0 (0x004B41D0), read as a global function pointer, as the argument to BooleanToIntConversion (0x00587B3E). [callee:0x00587B3E, global:0x004B41D0, source:raw]
    // RETURN: Return the integer produced by BooleanToIntConversion. [callee:0x00587B3E, function:0x004B41C0, source:raw]

    // Conservative worker pseudocode:
    //   int FunctionCallWrapper_41c0() {
    //     return BooleanToIntConversion((int)sub_4B41D0);
    //   }
    // UNRESOLVED: The identity and behavior of sub_4B41D0 are not established by this packet; it is only referenced here as a code address.
    // UNRESOLVED: The purpose of BooleanToIntConversion (0x00587B3E) is not established by this packet.
}
