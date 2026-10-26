// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566CF0
// Canonical corpus name: ResourceLookupWithDualPath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceLookupWithDualPath_00566cf0.c

void UnknownObject::ResourceLookupWithDualPath()
{
    // Small dual-path dispatcher on the selector at this+0x10 (DWORD index 4). When it is non-zero, StringLengthDispatch is called with the pointer stored at this+0x0 and the input string, returning true when the result differs from -1. Otherwise StringWriteToFile is called with the input string and the value at this+0x0, again returning true when the result differs from -1. Structural twin of ConditionalDispatch_6bd0 (00566bd0).
    // GUARD: Branches on the selector at this+0x10 (DWORD index 4): non-zero takes the string-length dispatch path, zero takes the file-write path [field:this:0x00000010, source:raw]
    // CALL: StringLengthDispatch called with the pointer stored at this+0x0 and the input string; success is a result other than -1 [field:this:0x00000000, callee:0x005352B0, source:raw]
    // CALL: StringWriteToFile called with the input string and the value stored at this+0x0; success is a result other than -1 [field:this:0x00000000, callee:0x0058BABB, source:raw]
    // RETURN: Returns true when the selected path produced a result other than -1, false otherwise [source:raw]
    // CALL: Used as a lookup/write helper by four callers: LinkedListDispatchWithVTableCalls, FileStreamCleanup, SettingsIniFileWriter and PlayerOpponentStateWriter [caller:0x004A1D50, caller:0x004A1F10, caller:0x004C0690, caller:0x004C0CC0, source:raw]

    // Conservative worker pseudocode:
    //   // if (this[0x10/4])
    //   //   return StringLengthDispatch(*this, a2) != -1;
    //   // else
    //   //   return StringWriteToFile(a2, *this) != -1;
    // UNRESOLVED: The meaning of the selector at this+0x10 (interpreted as an existence test selecting lookup versus write) is inferred from the two call paths, not proven
    // UNRESOLVED: Whether the value at this+0x0 is a string pointer, a stream handle or an internal buffer is not determined by this packet
    // UNRESOLVED: The cluster-copy note identifies the structural twin ConditionalDispatch_6bd0, but the semantic labels StringLengthDispatch and StringWriteToFile come from the packet ABI and are not independently confirmed
}
