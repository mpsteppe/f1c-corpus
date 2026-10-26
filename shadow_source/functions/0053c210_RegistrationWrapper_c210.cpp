// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C210
// Canonical corpus name: RegistrationWrapper_c210
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RegistrationWrapper_c210_0053c210.c

void UnknownObject::RegistrationWrapper_c210()
{
    // Thin zero-argument wrapper: casts the code address of sub_53C220 (0x0053C220) to int and forwards it to the shared helper BooleanToIntConversion (0x00587B3E), returning that helper's integer result unchanged. The ABI lead labels the helper call as registering an address, matching the same shape as the adjacent sibling thunk. No local state, arguments, or guards.
    // CALL: Call BooleanToIntConversion (0x00587B3E) with the address of sub_53C220 (0x0053C220) cast to int as its single argument. [callee:0x00587B3E, global:0x0053C220, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion unchanged. [function:0x0053C210, source:raw]

    // Conservative worker pseudocode:
    //   int RegistrationWrapper_c210() {
    //     return BooleanToIntConversion((int)sub_53C220);
    //   }
    // UNRESOLVED: BooleanToIntConversion (0x00587B3E) is decompiler-named; whether it registers, stores, or merely converts the forwarded address is not evidenced.
    // UNRESOLVED: sub_53C220 is read here only as a code address; the one-time initialization it performs is outside this packet.
}
