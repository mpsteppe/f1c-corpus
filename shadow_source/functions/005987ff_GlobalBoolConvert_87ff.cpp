// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005987FF
// Canonical corpus name: CallbackRegistration_87ff
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackRegistration_87ff_005987ff.c

void UnknownObject::GlobalBoolConvert_87ff()
{
    // One-line delegation stub: reads the global PhysicsThunk (0x0059880B), casts its value to int, passes it to BooleanToIntConversion (sub_587B3E), and returns the result unchanged. The corpus name CallbackRegistration_87ff and the LEGACY ABI lead Callback_Registration_5987ff describe the same behavior: a registration-style wrapper whose single argument is the value read from a global. The owner and the identity of the global object are unconfirmed.
    // CALL: Read the value of global PhysicsThunk (0x0059880B) as the argument, cast it to int, and call BooleanToIntConversion (sub_587B3E) with it; the function computes no other argument from locals or state. [global:0x0059880B, callee:0x00587B3E, source:raw]
    // RETURN: Return the callee's result directly; the function performs no other work. [source:raw, abi:lead, function:0x005987FF]

    // Conservative worker pseudocode:
    //   int GlobalBoolConvert_87ff() {
    //     return BooleanToIntConversion((int)PhysicsThunk);
    //   }
    // UNRESOLVED: The identity of the object or value that global PhysicsThunk (0x0059880B) points to is not documented by the packet; the thunk name suggests a physics entry point but its role here is unresolved.
    // UNRESOLVED: The exact meaning of the BooleanToIntConversion result (boolean-to-int normalization) and why a dedicated wrapper entry point exists are unconfirmed.
    // UNRESOLVED: The owner object is unknown; no fields, guards, or callers are present in the packet.
}
