// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499E90
// Canonical corpus name: SingleFunctionCallWrapper_9e90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_9e90_00499e90.c

void UnknownObject::StringCopyWithBufferReallocWrapper_9e90()
{
    // Thin stdcall forwarding wrapper with no state of its own: takes a single argument a1, forwards it unchanged to the string copy helper StringCopyWithBufferRealloc, and returns that helper's result. Called by sub_493060 (0x00493060). The legacy ABI label Single_Function_Call_Wrapper_499e90 hints at a single-call delegation role, but that is not established by the raw source.
    // CALL: Forwards argument a1 to StringCopyWithBufferRealloc (the raw source body is exactly this single call) [source:raw]
    // RETURN: Returns the result of StringCopyWithBufferRealloc(a1) unchanged [function:0x00499E90, source:raw]
    // CALL: Invoked by sub_493060 (0x00493060), which is the only caller recorded in this packet [caller:0x00493060]

    // Conservative worker pseudocode:
    //   int StringCopyWithBufferReallocWrapper_9e90(int a1) {
    //     return StringCopyWithBufferRealloc(a1);
    //   }
    // UNRESOLVED: The callee StringCopyWithBufferRealloc appears in the raw source but has no entry in this packet's callee list, so its address and owner are unknown.
    // UNRESOLVED: The meaning of the forwarded argument a1 and the caller's (sub_493060, 0x00493060) intent are not established from this packet.
    // UNRESOLVED: The legacy ABI label Single_Function_Call_Wrapper_499e90 suggests a single-call delegation role but carries no supporting evidence.
}
