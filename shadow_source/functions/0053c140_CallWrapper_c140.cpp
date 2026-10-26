// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C140
// Canonical corpus name: CallWrapper_c140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallWrapper_c140_0053c140.c

void UnknownObject::CallWrapper_c140()
{
    // Trivial forwarding wrapper: calls the function whose canonical ABI name is Call_FUN_00556220 (sub_556220 in the raw source) with the address of global unk_8B6BD0 (0x008B6BD0) as its single argument, and returns the callee's int result unchanged.
    // CALL: Call sub_556220 passing the address of global unk_8B6BD0 (0x008B6BD0) as the single argument. [global:0x008B6BD0, source:raw]
    // RETURN: Return the int result of the callee unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   return sub_556220((int)&unk_8B6BD0);
    // UNRESOLVED: The callee sub_556220 is not resolved in this packet; its identity, arguments, and side effects are unknown here.
    // UNRESOLVED: The content and role of global unk_8B6BD0 (0x008B6BD0) are unknown.
}
