// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DA30
// Canonical corpus name: Thunk_da30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_da30_0044da30.c

void UnknownObject::Thunk_da30()
{
    // Trivial thunk: reads the nullsub_148 function pointer at 0x0044DA40, casts it to int, and passes it to BooleanToIntConversion (0x00587B3E), returning the boolean-to-int result directly. Acts as a registration adapter that surfaces a function pointer through the shared conversion helper rather than executing it. No arguments, branches, or fields.
    // CALL: Read the nullsub_148 function pointer at 0x0044DA40, cast it to an int, and pass it as the argument to BooleanToIntConversion (0x00587B3E). [source:raw, global:0x0044DA40, callee:0x00587B3E]
    // RETURN: Return the integer produced by BooleanToIntConversion directly. [source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_da30() {
    //     return BooleanToIntConversion((int)nullsub_148);
    //   }
    // UNRESOLVED: nullsub_148 is an empty stub (its target contains no executable body); its intended registration behavior is unrecoverable from this packet.
    // UNRESOLVED: The canonical name Thunk_da30 and abi name Thunk_44da30 are mechanical and carry no domain hint for what is being registered.
}
