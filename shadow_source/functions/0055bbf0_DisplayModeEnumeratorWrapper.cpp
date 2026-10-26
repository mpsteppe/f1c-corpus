// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BBF0
// Canonical corpus name: DisplayModeEnumeratorWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayModeEnumeratorWrapper_0055bbf0.c

void UnknownObject::DisplayModeEnumeratorWrapper()
{
    // Thin forwarding wrapper: reads the global object pointer dword_8B78A0, passes it together with the incoming this pointer and a literal zero into sub_53DB90, and returns that callee's result. No local state is touched.
    // CALL: Invoke sub_53DB90 with the global dword_8B78A0 as the first argument, this as the second argument, and 0 as the third. [global:0x008B78A0, callee:0x0053DB90]
    // RETURN: Return whatever sub_53DB90 produced. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BBF0(unsigned int* this) {
    //     return sub_53DB90((int)dword_8B78A0, this, 0);
    //   }
    // UNRESOLVED: The semantics of sub_53DB90 (the actual enumerator) and the meaning of its three arguments are unknown from this function alone.
    // UNRESOLVED: dword_8B78A0 is read as a plain integer global here; whether it is an object pointer or a handle is not established.
    // UNRESOLVED: Why the caller sub_55BE80 needs this wrapper instead of calling sub_53DB90 directly is unclear.
}
