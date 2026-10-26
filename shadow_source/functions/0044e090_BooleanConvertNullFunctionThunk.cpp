// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E090
// Canonical corpus name: Thunk_e090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_e090_0044e090.c

void UnknownObject::BooleanConvertNullFunctionThunk()
{
    // Thunk that calls BooleanToIntConversion with the address of the null stub nullsub_165 (0x0044E0A0) as its argument and returns the integer conversion result.
    // CALL: Call BooleanToIntConversion with the address of nullsub_165 as the argument. [callee:0x00587B3E, global:0x0044E0A0, function:0x0044E090, source:raw]
    // RETURN: Return the int result of the BooleanToIntConversion call. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   int sub_44E090() {
    //     return BooleanToIntConversion((int)nullsub_165);
    //   }
    // UNRESOLVED: The purpose of passing the address of the empty stub nullsub_165 to BooleanToIntConversion is not grounded by the raw source.
    // UNRESOLVED: Whether this is an atexit-style registration or a boolean coercion of the function pointer is ungrounded.
    // UNRESOLVED: nullsub_165 itself has no body evidence; its role as a callback is unknown.
}
