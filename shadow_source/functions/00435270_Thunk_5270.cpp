// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00435270
// Canonical corpus name: Thunk_5270
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_5270_00435270.c

void UnknownObject::Thunk_5270()
{
    // Parameterless thunk: calls BooleanToIntConversion with the address of sub_435280 as its single integer argument, then returns the result. Reads the code global sub_435280 (read-only). No fields, locals, guards, or extra callees.
    // CALL: Pass the address of sub_435280 (as an int) to BooleanToIntConversion. [global:0x00435280, callee:0x00587B3E, source:raw]
    // RETURN: Return the BooleanToIntConversion result. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_5270()
    //   {
    //     return BooleanToIntConversion((int)sub_435280);
    //   }
    // UNRESOLVED: Passing a function address as a boolean/int argument is unusual; sub_435280 may be treated as a flag/tag rather than a callable target in this context.
    // UNRESOLVED: Purpose of the converted result and the caller context are not established; the packet carries no callers.
    // UNRESOLVED: Legacy ABI name Thunk_435270 contributes identity only, no semantics.
}
