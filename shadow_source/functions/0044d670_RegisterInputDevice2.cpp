// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D670
// Canonical corpus name: RegisterInputDevice2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RegisterInputDevice2_0044d670.c

void UnknownObject::RegisterInputDevice2()
{
    // Trivial thunk: reads the nullsub_138 function-pointer slot at 0x0044D680, casts it to int, passes it to BooleanToIntConversion, and returns the conversion result.
    // CALCULATION: Read global nullsub_138 at 0x0044D680 (function-pointer slot) and cast it to int as the BooleanToIntConversion argument. [global:0x0044D680, source:raw]
    // CALL: Invoke BooleanToIntConversion with the int-cast value of nullsub_138. [callee:0x00587B3E, global:0x0044D680]
    // RETURN: Return the int result of BooleanToIntConversion. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   int RegisterInputDevice2() { return BooleanToIntConversion((int)nullsub_138); }
    // UNRESOLVED: Purpose of applying BooleanToIntConversion to the nullsub_138 function-pointer value is unclear; nullsub_138 has no body evidence here, so the input-device registration semantics of this name cannot be confirmed from this thunk alone.
}
