// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BDE0
// Canonical corpus name: sub_49BDE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BDE0_0049bde0.c

void UnknownObject::StringTableLookupAndCopy()
{
    // String table lookup and copy. Reads v2 = off_5CCBE4[0]; if BinarySearchInStringTable(byte_5EC4C0, off_5CCBE4[0], byte_5EC4CC) is true, copies v2 into byte_5EC4CC with a null-check fallback to an empty string. Then sub_587DD0(a1, byte_5EC4CC, a2 - 1) copies up to a2-1 characters into the caller buffer a1, and the byte at a2-1+a1 is null-terminated. Returns 0. Called by UtilityFunction_d8b0 (0049d8b0) and MultiColorTextRender (004dbf90).
    // CALCULATION: v2 = off_5CCBE4[0]: load the first pointer entry of the string table referenced by global off_5CCBE4 [global:0x005CCBE4, function:0x0049BDE0, source:raw]
    // GUARD: BinarySearchInStringTable(byte_5EC4C0, off_5CCBE4[0], byte_5EC4CC): search the string table for the key; when true, the copy into byte_5EC4CC is performed, otherwise it is skipped [callee:0x00423A00, global:0x005CCBE4, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // GUARD: Inner null-check on v2: if v2 is non-NULL strcpy it into byte_5EC4CC, else clear byte_5EC4CC[0] [global:0x005CCBE4, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: strcpy(byte_5EC4CC, v2): copy the found string into the message display buffer [global:0x005EC4CC, source:raw]
    // ASSIGNMENT: byte_5EC4CC[0] = 0: empty the message display buffer when v2 is NULL [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(a1, byte_5EC4CC, a2 - 1): copy or concatenate from the message display buffer into the caller buffer a1 with length cap a2 - 1 [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Null-terminate the output: *(_BYTE *)(a2 - 1 + a1) = 0 [source:raw]
    // RETURN: Return 0 [function:0x0049BDE0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = off_5CCBE4[0];
    //   if (BinarySearchInStringTable(byte_5EC4C0, off_5CCBE4[0], byte_5EC4CC)) {
    //     if (v2)
    //       strcpy(byte_5EC4CC, v2);
    //     else
    //       byte_5EC4CC[0] = 0;
    //   }
    //   sub_587DD0(a1, byte_5EC4CC, a2 - 1);
    //   *(char *)(a2 - 1 + a1) = 0;
    //   return 0;
    // UNRESOLVED: The role split among byte_5EC4C0 (search base), off_5CCBE4[0] (key), and byte_5EC4CC (output) in the binary search is inferred; the search semantics are not detailed in this packet
    // UNRESOLVED: sub_587DD0's exact behavior (plain copy versus concatenation) is not defined in this packet
    // UNRESOLVED: The identity of the off_5CCBE4 string table and why only entry [0] is consulted are unknown
    // UNRESOLVED: What message the buffer a1 ultimately feeds (per callers 0049d8b0 / 004dbf90) is not established by this packet
}
