// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B07A
// Canonical corpus name: SingleFunctionCallWrapper_b07a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_b07a_0059b07a.c

void UnknownObject::SingleFunctionCallWrapper_b07a()
{
    // Trivial wrapper: passes the value of global EmptyStub_aa60 (0x0047AA60) to BooleanToIntConversion (0x00587B3E) and returns its result.
    // CALL: Read global EmptyStub_aa60 (0x0047AA60) and pass it to BooleanToIntConversion (0x00587B3E). [callee:0x00587B3E, global:0x0047AA60]
    // RETURN: Return the int result produced by BooleanToIntConversion. [source:raw]

    // Conservative worker pseudocode:
    //   int SingleFunctionCallWrapper_b07a()
    //   {
    //     return BooleanToIntConversion((int)EmptyStub_aa60);
    //   }
    // UNRESOLVED: Meaning of global EmptyStub_aa60 (0x0047AA60) is unknown; it is read-only from this function.
    // UNRESOLVED: BooleanToIntConversion (0x00587B3E) semantics are not evidenced in this packet.
}
