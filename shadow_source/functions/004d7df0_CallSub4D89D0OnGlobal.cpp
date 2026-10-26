// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7DF0
// Canonical corpus name: sub_4D7DF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D7DF0_004d7df0.c

void UnknownObject::CallSub4D89D0OnGlobal()
{
    // Thin wrapper that calls sub_4D89D0 with the address of global dword_8AD298 and returns its int result unchanged. Reads dword_8AD298 only for its address. Identical in body to 004D7DD0, suggesting a duplicated wrapper or a distinct caller-dispatched thunk, but no link between the two is recorded.
    // CALL: Call sub_4D89D0 with the address of global dword_8AD298; dword_8AD298 is read for its address [function:0x004D7DF0, global:0x008AD298, source:raw]
    // RETURN: Return the int result produced by sub_4D89D0 [source:raw]

    // Conservative worker pseudocode:
    //   int CallSub4D89D0OnGlobal() {
    //       return sub_4D89D0(&dword_8AD298);
    //   }
    // UNRESOLVED: sub_4D89D0's behavior and the purpose of global dword_8AD298 are not recorded in this packet
    // UNRESOLVED: Body is identical to 004D7DD0; whether these are duplicate wrappers or distinct thunks is unresolved
    // UNRESOLVED: No static callers are recorded, so the context in which this wrapper runs is unknown
}
