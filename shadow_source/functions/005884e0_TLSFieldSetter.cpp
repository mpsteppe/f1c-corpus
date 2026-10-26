// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005884E0
// Canonical corpus name: TLSFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TLSFieldSetter_005884e0.c

void UnknownObject::TLSFieldSetter()
{
    // Retrieves the per-thread TLS storage block via TLSValueRetrievalWithInit, writes the caller-provided value a1 into the dword at offset +20 of that block, and returns the block base pointer. Likely part of a thread-local configuration/state accessor pattern.
    // CALL: Calls TLSValueRetrievalWithInit() to obtain (and initialize if needed) the thread-local storage block base pointer. [callee:0x0058E0C7, source:raw, function:0x005884E0]
    // ASSIGNMENT: Writes a1 into the dword at TLS block offset +20 (*(result + 20) = a1). [source:raw, function:0x005884E0]
    // RETURN: Returns the TLS storage block base pointer (the value returned by TLSValueRetrievalWithInit). [source:raw, function:0x005884E0]

    // Conservative worker pseudocode:
    //   int TLSFieldSetter(int a1)
    //   {
    //     int tls = TLSValueRetrievalWithInit();
    //     *(_DWORD *)(tls + 20) = a1;
    //     return tls;
    //   }
    // UNRESOLVED: The semantic role of the dword field at TLS block offset +20 is unknown; only its offset and write behavior are evidenced.
}
