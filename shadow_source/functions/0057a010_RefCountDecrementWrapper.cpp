// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A010
// Canonical corpus name: sub_57A010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57A010_0057a010.c

void UnknownObject::RefCountDecrementWrapper()
{
    // Argumentless thunk that forwards to RefCountDecrementWithCheck and returns the callee's result unchanged. It reads no packet field and performs no local transformation; the global 0x008D3BF0 flagged by packet facts is not referenced in the decompiled body.
    // CALL: Forward immediately to RefCountDecrementWithCheck with no arguments. [source:raw]
    // RETURN: Return the callee's result as a char pointer without modification. [source:raw, function:0x0057A010]

    // Conservative worker pseudocode:
    //   char *sub_57A010(void) {
    //     return RefCountDecrementWithCheck();
    //   }
    // UNRESOLVED: Global 0x008D3BF0 is flagged read-only by packet facts but is absent from the decompiled body; its read likely happens inside RefCountDecrementWithCheck.
    // UNRESOLVED: Semantics of the ref-count decrement/check and what condition it signals depend on the callee, which is not in this packet's callees.
}
