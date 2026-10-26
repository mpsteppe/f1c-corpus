// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BCD0
// Canonical corpus name: sub_49BCD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BCD0_0049bcd0.c

void UnknownObject::SecondaryStringTableLookupAndCopyToOutput()
{
    // Secondary string-table lookup variant of the message-buffer copy pattern. Looks up a string via BinarySearchInStringTable against the secondary table pointer off_5CCBCC[0]. On match, copies the table string into the global message buffer byte_5EC4CC, null-terminating it if the source pointer is null. Then copies up to a2-1 bytes from the message buffer into the caller-supplied output buffer a1 via sub_587DD0, null-terminates the output at a2-1+a1, and returns 0.
    // ASSIGNMENT: Cache the secondary table entry pointer: v2 = off_5CCBCC[0]. [global:0x005CCBCC, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, off_5CCBCC[0], byte_5EC4CC): search the secondary string table for a key; non-zero return means a match. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBCC, global:0x005EC4CC]
    // GUARD: Only copy into the message buffer when the table search reports a match. [source:raw]
    // ASSIGNMENT: When v2 is non-null, strcpy(byte_5EC4CC, v2): copy the matched string into the global message buffer. [global:0x005EC4CC, source:raw]
    // ASSIGNMENT: When v2 is null, clear the message buffer: byte_5EC4CC[0] = 0. [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(a1, byte_5EC4CC, a2 - 1): copy or concatenate the message buffer into the caller output buffer a1 up to a2-1 bytes. [callee:0x00587DD0, global:0x005EC4CC]
    // ASSIGNMENT: Null-terminate the output buffer at a2-1+a1. [source:raw]
    // RETURN: Return 0 unconditionally after filling the output buffer. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49BCD0(char *out, int out_len) {
    //     const char *v2 = off_5CCBCC[0];
    //     if (BinarySearchInStringTable(byte_5EC4C0, off_5CCBCC[0], byte_5EC4CC)) {
    //       if (v2) strcpy(byte_5EC4CC, v2);
    //       else byte_5EC4CC[0] = 0;
    //     }
    //     sub_587DD0(out, byte_5EC4CC, out_len - 1);
    //     out[out_len - 1] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Relationship to the primary lookup (function with the same shape using the off_5CCBC4 table pointer) is not established; the two share the key/table buffer globals and differ only in the table pointer global.
    // UNRESOLVED: sub_587DD0 semantics (copy vs concatenate, length handling) are in the callee and not confirmed here.
}
