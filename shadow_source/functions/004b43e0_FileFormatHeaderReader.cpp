// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B43E0
// Canonical corpus name: FileFormatHeaderReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileFormatHeaderReader_004b43e0.c

void UnknownObject::FileFormatHeaderReader()
{
    // Reads a 4-byte header word into a local buffer via FileWriteWithBackendDispatch (0x00566C00), extracts a 10-bit operation id from bits 8-17, and validates the header: bits 29-31 must equal 0x20000000 and bits 17-22 must be zero. A valid header dispatches NetworkOperationDispatchByFlag (0x00566DF0) with the operation id plus 1; an invalid header dispatches it with the raw operation id. Returns the dispatch result on both paths. Called from ModelSceneFileLoader (0x004B6C90).
    // CALL: Read 4 bytes into the local buffer v2 via FileWriteWithBackendDispatch (0x00566C00), filling v2[0] with the header dword. [callee:0x00566C00, source:raw]
    // GUARD: Header validity test: take the valid branch when (v2[0] & 0xE0000000) == 0x20000000 AND (v2[0] & 0xFC0000) == 0; otherwise take the invalid branch. [source:raw]
    // CALCULATION: Extract the 10-bit operation id from the header: op = (v2[0] >> 8) & 0x3FF. [source:raw]
    // CALL: Invalid-header path: call NetworkOperationDispatchByFlag(op) (0x00566DF0) with the raw operation id. [callee:0x00566DF0, source:raw]
    // RETURN: Return the NetworkOperationDispatchByFlag result from the invalid-header path. [source:raw, function:0x004B43E0]
    // CALL: Valid-header path: call NetworkOperationDispatchByFlag(op + 1) (0x00566DF0) with the operation id incremented. [callee:0x00566DF0, source:raw]
    // RETURN: Return the NetworkOperationDispatchByFlag result from the valid-header path. [source:raw, function:0x004B43E0]

    // Conservative worker pseudocode:
    //   FileWriteWithBackendDispatch(v2, 4);
    //   op = (v2[0] >> 8) & 0x3FF;
    //   if ((v2[0] & 0xE0000000) != 0x20000000 || (v2[0] & 0xFC0000) != 0)
    //       return NetworkOperationDispatchByFlag(op);
    //   return NetworkOperationDispatchByFlag(op + 1);
    // UNRESOLVED: The argument a1 is present in the signature but never referenced in the body.
    // UNRESOLVED: The local buffer v2 is declared as 108 dwords but only v2[0] is read by this function.
    // UNRESOLVED: The exact meaning of the header bit fields (0x20000000 tag, 0xFC0000 clear-mask, 0x3FF operation id) is inferred from the masks; the format family is unknown.
    // UNRESOLVED: NetworkOperationDispatchByFlag target behavior and the op-versus-op+1 distinction are not established by the packet.
}
