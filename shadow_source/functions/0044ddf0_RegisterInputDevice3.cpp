// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DDF0
// Canonical corpus name: RegisterInputDevice3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RegisterInputDevice3_0044ddf0.c

void UnknownObject::RegisterInputDevice3()
{
    // Trivial thunk: reads the nullsub_158 function pointer at 0x0044DE00, casts it to int, and passes it to BooleanToIntConversion (0x00587B3E), returning the boolean-to-int result directly. The canonical/abi name RegisterInputDevice3 suggests an input-device registration hook, but the wrapped target is an empty stub whose body carries no registration logic. No arguments, branches, or fields.
    // CALL: Read the nullsub_158 function pointer at 0x0044DE00, cast it to an int, and pass it as the argument to BooleanToIntConversion (0x00587B3E). [source:raw, global:0x0044DE00, callee:0x00587B3E]
    // RETURN: Return the integer produced by BooleanToIntConversion directly. [source:raw]

    // Conservative worker pseudocode:
    //   int RegisterInputDevice3() {
    //     return BooleanToIntConversion((int)nullsub_158);
    //   }
    // UNRESOLVED: nullsub_158 is an empty stub (its target contains no executable body); the input-device registration it would perform is unrecoverable from this packet.
    // UNRESOLVED: The RegisterInputDevice3 intent is carried only by the canonical/abi name (LEGACY trust); no caller, field, or global-writer evidence grounds what device slot is registered.
}
