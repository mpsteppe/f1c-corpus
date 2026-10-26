// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494FE0
// Canonical corpus name: ConditionalFieldClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFieldClear_00494fe0.c

void UnknownObject::ConditionalFieldClear()
{
    // Conditional field clear helper. Calls sub_53CBC0 passing a2 as an output dword pointer and a1 as an argument; when the callee returns non-zero, clears the dword pointed to by a2, and returns the callee's result unchanged. Called by BitmapLoader (0x004979F0), consistent with a post-decode validation step that invalidates an output field on failure.
    // CALL: Evaluates sub_53CBC0(a2, a1), passing the dword pointer a2 and forwarding a1 [callee:0x0053CBC0, source:raw]
    // GUARD: The callee result is tested; the field clear only runs when it is non-zero [source:raw]
    // ASSIGNMENT: When the guard holds, the dword pointed to by a2 is cleared to 0 [source:raw]
    // RETURN: Returns the callee result (zero on failure, non-zero on success) unchanged [source:raw]
    // CALL: Invoked by BitmapLoader (0x004979F0) as part of a load/decode path [caller:0x004979F0, source:raw]

    // Conservative worker pseudocode:
    //   result = sub_53CBC0(a2, a1);
    //   if (result)
    //       *a2 = 0;
    //   return result;
    // UNRESOLVED: Read-only global dword_8AFE64 (0x008AFE64) is flagged by deterministic facts but never appears in the raw decompiled source; its role here is unverified
    // UNRESOLVED: The meaning of the a1 argument and the identity of the object behind a2 are not established from this packet alone
}
