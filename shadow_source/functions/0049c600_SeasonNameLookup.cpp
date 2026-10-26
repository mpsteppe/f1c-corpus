// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C600
// Canonical corpus name: SeasonNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonNameLookup_0049c600.c

void UnknownObject::SeasonNameLookup()
{
    // String-table lookup and copy helper carrying the legacy ABI name Season_Name_Lookup. Caches the table pointer off_5CCBD0[0], binary-searches it via BinarySearchInStringTable(byte_5EC4C0, off_5CCBD0[0], byte_5EC4CC), and on a match copies the matched string into the global message buffer byte_5EC4CC (null-terminating it when the source pointer is null). Always copies up to a2-1 bytes from byte_5EC4CC into the caller-supplied output buffer a1 via sub_587DD0, null-terminates at a2-1+a1, and returns 0. Called by UIDebugOverlayRender (004dc0b0).
    // ASSIGNMENT: Cache the table entry pointer: v2 = off_5CCBD0[0]. [global:0x005CCBD0, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, off_5CCBD0[0], byte_5EC4CC): search the table for a key string; non-zero return indicates a match. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBD0, global:0x005EC4CC]
    // GUARD: Only update the message buffer when the table search reports a match. [source:raw]
    // ASSIGNMENT: On match with non-null v2, copy the matched string into the global message buffer: strcpy(byte_5EC4CC, v2). [global:0x005EC4CC, source:raw]
    // ASSIGNMENT: On match with null v2, clear the message buffer: byte_5EC4CC[0] = 0. [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(a1, byte_5EC4CC, a2 - 1): copy or concatenate the message buffer into the caller output buffer a1 up to a2-1 bytes. [callee:0x00587DD0, global:0x005EC4CC]
    // ASSIGNMENT: Null-terminate the output buffer at a2-1+a1. [source:raw]
    // RETURN: Return 0 unconditionally after filling the output buffer. [source:raw]

    // Conservative worker pseudocode:
    //   int SeasonNameLookup(char *out, int out_len) {
    //     const char *v2 = off_5CCBD0[0];
    //     if (BinarySearchInStringTable(byte_5EC4C0, off_5CCBD0[0], byte_5EC4CC)) {
    //       if (v2) strcpy(byte_5EC4CC, v2);
    //       else byte_5EC4CC[0] = 0;
    //     }
    //     sub_587DD0(out, byte_5EC4CC, out_len - 1);
    //     out[out_len - 1] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Legacy ABI name Season_Name_Lookup implies the table pointer off_5CCBD0 holds season names, but that identification is not independently confirmed; the semantic identity of the table content is UNKNOWN.
    // UNRESOLVED: sub_587DD0 semantics (copy vs concatenate, length handling) are in the callee and not confirmed here.
}
