// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D130
// Canonical corpus name: Thunk_d130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_d130_0044d130.c

void UnknownObject::Thunk_d130()
{
    // Single-call thunk: invokes BooleanToIntConversion (0x00587B3E) with the address of the no-op function nullsub_62 (0x0044D140) cast to int as the sole argument, and returns its int result. No guards, no fields, no further control flow.
    // CALL: Call BooleanToIntConversion (0x00587B3E), passing the address of the function nullsub_62 (0x0044D140) converted to int. [callee:0x00587B3E, global:0x0044D140, source:raw]
    // RETURN: Return the int result produced by BooleanToIntConversion. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_d130(void) {
    //     return BooleanToIntConversion((int)nullsub_62);
    //   }
    // UNRESOLVED: Semantic purpose of passing the address of no-op function nullsub_62 (0x0044D140) to BooleanToIntConversion is not established; pattern is consistent with a CRT registration/atexit-style trampoline.
    // UNRESOLVED: Behavior of BooleanToIntConversion (0x00587B3E) is not described in the packet; name suggests bool-to-int conversion, possibly after invoking the supplied function pointer.
    // UNRESOLVED: No callers listed in the packet; invocation path unknown (on_frame_path false).
    // UNRESOLVED: Owner identity unknown; global nullsub_62 is a data-resident no-op function, so the thunk itself performs no stateful work.
}
