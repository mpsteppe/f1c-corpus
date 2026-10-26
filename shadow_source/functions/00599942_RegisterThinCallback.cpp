// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599942
// Canonical corpus name: CallbackRegistration_9942
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackRegistration_9942_00599942.c

void UnknownObject::RegisterThinCallback()
{
    // Thin forwarding wrapper that takes the code address ThinForwardingWrapper (global at 0x0059994E), casts it to int, feeds it to BooleanToIntConversion (0x00587B3E) and returns that result. ABI name suggests it registers a callback at the thunk address; the boolean conversion of a code address is opaque without the callee's contract.
    // CALCULATION: Cast the ThinForwardingWrapper code address (global at 0x0059994E) to int. [global:0x0059994E, source:raw]
    // CALL: Call BooleanToIntConversion (0x00587B3E) with the cast thunk address as its argument. [callee:0x00587B3E, source:raw]
    // RETURN: Return the value produced by BooleanToIntConversion. [source:raw]

    // Conservative worker pseudocode:
    //   int CallbackRegistration_9942() {
    //     return BooleanToIntConversion((int)ThinForwardingWrapper);
    //   }
    // UNRESOLVED: Why a code address is converted through a boolean conversion routine is unknown; the callee contract at 0x00587B3E is not available in this packet.
    // UNRESOLVED: ThinForwardingWrapper at 0x0059994E points at a thunk whose target function is unknown here.
}
