// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C40
// Canonical corpus name: sub_4C7C40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C7C40_004c7c40.c

void UnknownObject::Callback_Unregistration_4c7c40()
{
    // Unregistration thunk: passes the address of PhysicsVectorGetter (0x004C7C50) into BooleanToIntConversion (0x00587B3E) and returns the conversion result. The callback pointer is read (R) from the global at 0x004C7C50.
    // CALL: Calls BooleanToIntConversion at 0x00587B3E with a single argument: the address of PhysicsVectorGetter at 0x004C7C50 (read from that global), cast to int. [callee:0x00587B3E, global:0x004C7C50, source:raw]
    // RETURN: Returns the int value produced by BooleanToIntConversion. [function:0x004C7C40, source:raw]

    // Conservative worker pseudocode:
    //   int Callback_Unregistration_4c7c40() {
    //     return BooleanToIntConversion((int)PhysicsVectorGetter);
    //   }
}
