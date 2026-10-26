// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059978A
// Canonical corpus name: Thunk_978a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_978a_0059978a.c

void UnknownObject::Thunk_978a()
{
    // Trivial thunk that converts the address/value of the global EmptyStub_9796 to an integer via BooleanToIntConversion and returns the result.
    // CALL: Call BooleanToIntConversion((int)EmptyStub_9796), passing the global at 0x00599796 as the input. [function:0x0059978A, callee:0x00587B3E, global:0x00599796]
    // RETURN: Return the integer produced by BooleanToIntConversion. [source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_978a() {
    //       return BooleanToIntConversion((int)EmptyStub_9796);
    //   }
    // UNRESOLVED: EmptyStub_9796 (0x00599796) is read as an integer/address; whether it is a function pointer or data is unknown.
    // UNRESOLVED: BooleanToIntConversion (0x00587B3E) semantics and prototype are not defined in the packet evidence.
}
