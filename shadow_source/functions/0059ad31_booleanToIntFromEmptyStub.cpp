// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AD31
// Canonical corpus name: Thunk_ad31
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_ad31_0059ad31.c

void UnknownObject::booleanToIntFromEmptyStub()
{
    // Short straight-line thunk that reads global EmptyStub_aa60, passes it cast to int into BooleanToIntConversion, and returns the conversion result.
    // CALL: Call BooleanToIntConversion, passing the int-cast value read from global EmptyStub_aa60 as its argument [callee:0x00587B3E, global:0x0047AA60]
    // RETURN: Return the result of the BooleanToIntConversion call [function:0x0059AD31, source:raw]

    // Conservative worker pseudocode:
    //   int booleanToIntFromEmptyStub(void) {
    //       return BooleanToIntConversion((int)EmptyStub_aa60);
    //   }
    // UNRESOLVED: Semantics of global EmptyStub_aa60 are unknown; the read value is only observed as an int argument to BooleanToIntConversion.
}
