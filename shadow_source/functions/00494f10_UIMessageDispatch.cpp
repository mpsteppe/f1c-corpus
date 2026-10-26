// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494F10
// Canonical corpus name: UIMessageDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIMessageDispatch_00494f10.c

void UnknownObject::UIMessageDispatch()
{
    // Dispatches a UI message via sub_53D2E0. When the a6 flag is set, first looks up a2 in the binary string table byte_5EC4C0 via BinarySearchInStringTable; if found, copies a2 (or empties the buffer when a2 is null) into byte_5EC4CC and dispatches the buffered string instead.
    // GUARD: if ( a6 == 0 ) bypass the string-table lookup entirely and dispatch the original message directly. [source:raw]
    // CALL: Dispatch path without lookup: return sub_53D2E0(a1, a2, a3, a4, a5). [callee:0x0053D2E0, source:raw]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) to look up a2 against the string table at 0x005EC4C0, using the buffer at 0x005EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // GUARD: if the lookup returns nonzero (match found) update the byte_5EC4CC buffer with the message string. [source:raw]
    // ASSIGNMENT: if ( a2 ) strcpy(byte_5EC4CC, a2), else byte_5EC4CC[0] = 0 (empty the buffer). [global:0x005EC4CC, source:raw]
    // CALL: Dispatch the buffered string: return sub_53D2E0(a1, byte_5EC4CC, a3, a4, a5). [callee:0x0053D2E0, global:0x005EC4CC, source:raw]
    // RETURN: return the result of the final sub_53D2E0 dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   int UIMessageDispatch(int a1, const char *a2, int a3, int a4, int a5, char a6) {
    //     if ( !a6 )
    //       return sub_53D2E0(a1, a2, a3, a4, a5);
    //     if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) ) {
    //       if ( a2 )
    //         strcpy(byte_5EC4CC, a2);
    //       else
    //         byte_5EC4CC[0] = 0;
    //     }
    //     return sub_53D2E0(a1, byte_5EC4CC, a3, a4, a5);
    //   }
    // UNRESOLVED: Global dword_8AFE64 (0x008AFE64) does not appear in the raw function source; its role in or near this function is unknown.
    // UNRESOLVED: Whether byte_5EC4CC is a translation/localization buffer and how BinarySearchInStringTable fills it is unknown.
    // UNRESOLVED: Meaning of the sub_53D2E0 parameters (a3, a4, a5) is unknown.
}
