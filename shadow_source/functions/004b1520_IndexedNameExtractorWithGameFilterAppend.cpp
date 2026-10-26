// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1520
// Canonical corpus name: sub_4B1520
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1520_004b1520.c

void UnknownObject::IndexedNameExtractorWithGameFilterAppend()
{
    // Extracts a string from the indexed member slot this[7*a2 + 2609] (falling back to byte_5EA438 when null), copies it into the output buffer a3 with a length limit of a4-1, and null-terminates. Then asks ConditionalDispatch_81f0 for the game filter string (aGameFilter); if one exists and it plus the copied text plus 1 fits within a4, appends word_5C32D8 (the extension marker) followed by the game filter string to the buffer. Returns non-null when the append was performed.
    // CALCULATION: Compute the source string v4 as the value of the indexed member slot this[7*a2 + 2609]. [source:raw, function:0x004B1520]
    // GUARD: If the indexed slot is null, use byte_5EA438 as the fallback source string. [global:0x005EA438]
    // CALL: Copy the source string into the output buffer a3 with a length limit of a4-1 via sub_587DD0. [callee:0x00587DD0]
    // ASSIGNMENT: Null-terminate the copied string by setting a3[a4-1] to 0. [callee:0x00587DD0]
    // CALL: Call ConditionalDispatch_81f0 with the aGameFilter string to obtain the game filter value. [callee:0x005681F0, global:0x005C7130]
    // GUARD: If a game filter result exists and strlen(filter) + 1 + strlen(a3) is less than a4, append word_5C32D8 followed by the game filter string to the output buffer. [global:0x005C32D8, global:0x005C7130]
    // RETURN: Return the game filter result pointer, which is null when the append was skipped. [global:0x005C7130]

    // Conservative worker pseudocode:
    //   v4 = this[7*a2 + 2609];
    //   if (!v4) v4 = byte_5EA438;
    //   sub_587DD0(a3, v4, a4 - 1);
    //   a3[a4 - 1] = 0;
    //   filter = ConditionalDispatch_81f0(aGameFilter);
    //   if (filter && strlen(filter) + 1 + strlen(a3) < a4) {
    //       *(WORD*)&a3[strlen(a3)] = word_5C32D8;
    //       memcpy(&a3[strlen(a3)], filter, strlen(filter) + 1);
    //   }
    //   return filter;
    // UNRESOLVED: Exact meaning of the indexed member stride (7 dwords per entry, slot base 2609) and of the string stored there is unknown.
    // UNRESOLVED: word_5C32D8 is a two-byte marker whose text value is unconfirmed; the .HOT extension reading is DERIVED only.
    // UNRESOLVED: dword_8AD3B4 appears in the packet global list but is not referenced by this function's raw source; its role here is unclear.
}
