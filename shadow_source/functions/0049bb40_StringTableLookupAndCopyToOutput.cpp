// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BB40
// Canonical corpus name: sub_49BB40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BB40_0049bb40.c

void UnknownObject::StringTableLookupAndCopyToOutput()
{
    // Looks up a string from a string table via BinarySearchInStringTable. On match, copies the table string (off_5CCBC4[0]) into the global message buffer byte_5EC4CC, null-terminating the buffer if the source pointer is null. Then copies up to a2-1 bytes from the message buffer into the caller-supplied output buffer a1 via sub_587DD0, null-terminates the output at a2-1+a1, and returns 0.
    // ASSIGNMENT: Cache the string-table entry pointer: v2 = off_5CCBC4[0]. [global:0x005CCBC4, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, off_5CCBC4[0], byte_5EC4CC): search the string table for a key; non-zero return means a match. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBC4, global:0x005EC4CC]
    // GUARD: Only copy into the message buffer when the table search reports a match. [source:raw]
    // ASSIGNMENT: When v2 is non-null, strcpy(byte_5EC4CC, v2): copy the matched table string into the global message buffer. [global:0x005EC4CC, source:raw]
    // ASSIGNMENT: When v2 is null, clear the message buffer: byte_5EC4CC[0] = 0. [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(a1, byte_5EC4CC, a2 - 1): copy or concatenate the message buffer into the caller output buffer a1 up to a2-1 bytes. [callee:0x00587DD0, global:0x005EC4CC]
    // ASSIGNMENT: Null-terminate the output buffer at a2-1+a1. [source:raw]
    // RETURN: Return 0 unconditionally after filling the output buffer. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49BB40(char *out, int out_len) {
    //     const char *v2 = off_5CCBC4[0];
    //     if (BinarySearchInStringTable(byte_5EC4C0, off_5CCBC4[0], byte_5EC4CC)) {
    //       if (v2) strcpy(byte_5EC4CC, v2);
    //       else byte_5EC4CC[0] = 0;
    //     }
    //     sub_587DD0(out, byte_5EC4CC, out_len - 1);
    //     out[out_len - 1] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The key passed to BinarySearchInStringTable is the global byte_5EC4C0; the matched string is taken from off_5CCBC4[0], so table and key source are not fully resolved.
    // UNRESOLVED: sub_587DD0 semantics (copy vs concatenate, length handling) are in the callee and not confirmed here.
}
