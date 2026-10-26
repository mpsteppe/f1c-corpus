// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2FF0
// Canonical corpus name: CallbackRegistration_2ff0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackRegistration_2ff0_004c2ff0.c

void UnknownObject::CallbackRegistration_2ff0()
{
    // Registration thunk: passes the address of the callback at 0x004C3000 into BooleanToIntConversion (0x00587B3E) and returns the conversion result. The callback pointer is read (R) from the global at 0x004C3000.
    // CALL: Calls BooleanToIntConversion at 0x00587B3E with a single argument: the address of the function at 0x004C3000 (read from that global), cast to int. [callee:0x00587B3E, global:0x004C3000, source:raw]
    // RETURN: Returns the int value produced by BooleanToIntConversion. [function:0x004C2FF0, source:raw]

    // Conservative worker pseudocode:
    //   int CallbackRegistration_2ff0() {
    //     return BooleanToIntConversion((int)sub_4C3000);
    //   }
}
