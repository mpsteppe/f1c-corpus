// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CDBF0
// Canonical corpus name: StringTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringTableLookup_004cdbf0.c

void UnknownObject::StringTableLookup()
{
    // Searches a key=value style string table for a matching key. Copies the base path (from *this, falling back to the default directory byte_5EA438 when null) into a local buffer, then iterates lines parsed by sub_5897CA using the delimiter asc_5D251C, comparing each parsed token against the target with sub_587C20. Returns 1 when a token equals the target, 0 when parsing runs out of lines.
    // ASSIGNMENT: Read the base path string pointer from *this. [field:this:0x00000000, source:raw]
    // GUARD: When the base path pointer is null, fall back to the default directory string byte_5EA438. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Copy the selected path string into the local 256-byte buffer via strcpy. [source:raw]
    // CALL: sub_5897CA(buffer, asc_5D251C) parses the first line/token from the table using the delimiter asc_5D251C. [callee:0x005897CA, global:0x005D251C, source:raw]
    // GUARD: If the first parse returns 0 (no lines left in the table), return 0 (not found). [callee:0x005897CA, source:raw]
    // LOOP: Iterate until sub_587C20(a2, token) equals the target a2, meaning the token matches the searched key. [callee:0x00587C20, source:raw]
    // CALL: Inside the loop, sub_5897CA(0, asc_5D251C) advances to the next line/token in the table. [callee:0x005897CA, global:0x005D251C, source:raw]
    // GUARD: If the next parse returns 0 (no more lines), return 0 (not found). [callee:0x005897CA, source:raw]
    // RETURN: Return 1 once a parsed token matches the target a2; return 0 when the table is exhausted. [source:raw]

    // Conservative worker pseudocode:
    //   char StringTableLookup(const char** this_, int a2) {
    //     const char* base = *this_;
    //     if (!base) base = byte_5EA438;
    //     char buf[256];
    //     strcpy(buf, base);
    //     int token = sub_5897CA(buf, asc_5D251C);
    //     if (!token) return 0;
    //     while (sub_587C20(a2, token) != a2) {
    //       token = sub_5897CA(0, asc_5D251C);
    //       if (!token) return 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The delimited-token semantics of sub_5897CA and the comparison semantics of sub_587C20 are not established by the packet alone.
    // UNRESOLVED: The exact meaning of the target parameter a2 and the role of asc_5D251C (reported as the IniKeyValueDelim delimiter) are inferred from surrounding context only.
}
