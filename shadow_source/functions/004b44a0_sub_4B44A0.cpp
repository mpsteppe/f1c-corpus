// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B44A0
// Canonical corpus name: sub_4B44A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B44A0_004b44a0.c

void UnknownObject::sub_4B44A0()
{
    // Resolves a resource handle from argument a2 via ResourceLookupDispatcher and stores the result in this[1] (byte offset 0x04), then writes the object through FileWriteWithBackendDispatch: the first four dword-bytes via FileWriteWithBackendDispatch(this, 4) and the following two dword-bytes via FileWriteWithBackendDispatch(this + 2, 2). Always returns 1. Structurally a twin of FileHandleCloseRegistration (004b4470) per cluster copy, and the legacy ABI labels it a file open/write operation.
    // CALL: Store the result of ResourceLookupDispatcher(a2) into this[1] (dword at byte offset 0x04), recording the resolved resource identity. [callee:0x00566E20, field:this:0x00000004]
    // CALL: FileWriteWithBackendDispatch(this, 4): write the first four dword-bytes of the object. [callee:0x00566C00]
    // CALL: FileWriteWithBackendDispatch(this + 2, 2): write the next two dword-bytes of the object. [callee:0x00566C00]
    // RETURN: Return 1 to signal success. [source:raw]

    // Conservative worker pseudocode:
    //   this[1] = ResourceLookupDispatcher(a2);
    //   FileWriteWithBackendDispatch(this, 4);
    //   FileWriteWithBackendDispatch(this + 2, 2);
    //   return 1;
    // UNRESOLVED: Meaning of the two write lengths (4 then 2 dword-bytes) is unresolved; they likely target two adjacent record fields.
    // UNRESOLVED: What the value stored at this+0x04 represents and how the backend dispatcher routes the write is unproven.
    // UNRESOLVED: The cluster-copy relationship to 004b4470 is DERIVED and not independently verified.
}
