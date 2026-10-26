// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005987A1
// Canonical corpus name: CallbackRegistration_87a1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackRegistration_87a1_005987a1.c

void UnknownObject::GlobalBoolConvert_87a1()
{
    // One-line delegation stub: reads the global PhysicsStateUnkInit (0x005987AD), casts its value to int, passes it to BooleanToIntConversion (sub_587B3E), and returns the result unchanged. The corpus name CallbackRegistration_87a1 and the LEGACY ABI lead Callback_Registration_5987a1 describe the same behavior: a registration-style wrapper whose single argument is the value read from a global. The owner and the identity of the global object are unconfirmed.
    // CALL: Read the value of global PhysicsStateUnkInit (0x005987AD) as the argument, cast it to int, and call BooleanToIntConversion (sub_587B3E) with it; the function computes no other argument from locals or state. [global:0x005987AD, callee:0x00587B3E, source:raw]
    // RETURN: Return the callee's result directly; the function performs no other work. [source:raw, abi:lead, function:0x005987A1]

    // Conservative worker pseudocode:
    //   int GlobalBoolConvert_87a1() {
    //     return BooleanToIntConversion((int)PhysicsStateUnkInit);
    //   }
    // UNRESOLVED: The identity of the object or value that global PhysicsStateUnkInit (0x005987AD) points to is not documented by the packet.
    // UNRESOLVED: The exact meaning of the BooleanToIntConversion result (boolean-to-int normalization) and why a dedicated wrapper entry point exists are unconfirmed.
    // UNRESOLVED: The owner object is unknown; no fields, guards, or callers are present in the packet.
}
