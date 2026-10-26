// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CE860
// Canonical corpus name: StringListLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringListLookup_004ce860.c

void UnknownObject::StringListLookup()
{
    // Searches a strided string table (108 bytes per entry) for a string matching the caller-supplied argument. The search string is first copied into a local buffer and passed through sub_589901, which normalizes it for comparison. Entry count and table base are read from this+0x8 and this+0xC. Returns the matching entry's index, or -1 when the table is empty or no entry matches.
    // ASSIGNMENT: Copy the caller-supplied string into a local 64-byte buffer. [source:raw]
    // CALL: Normalize/transform the copied search string in place via sub_589901 before comparison. [callee:0x00589901]
    // GUARD: Guard on entry count at this+0x8: when count <= 0 the table is empty and the function returns -1 immediately. [guard:0, field:this:0x00000008]
    // ASSIGNMENT: Initialize the match index counter to 0. [source:raw]
    // LOOP: Iterate over entries starting at this+0xC advancing 108 bytes per entry, bounded by the entry count at this+0x8. [field:this:0x0000000C, field:this:0x00000008]
    // CALL: Test each table entry against the normalized search string with StringTableLookup; the loop stops on a match. [callee:0x004CDBF0, field:this:0x0000000C]
    // RETURN: Return -1 when the count is exhausted without any entry matching. [function:0x004CE860, field:this:0x00000008]
    // RETURN: Return the index of the first entry that matches the normalized search string. [function:0x004CE860]

    // Conservative worker pseudocode:
    //   if (this->count <= 0) return -1;
    //   for (i = 0; i < this->count; i++) {
    //     if (StringTableLookup(this->table + i * 108, buffer)) return i;
    //   }
    //   return -1;
    // UNRESOLVED: Exact transformation performed by sub_589901 (case folding vs. whitespace stripping) is not established by this packet.
    // UNRESOLVED: Element layout of each 108-byte string-table entry (string pointer plus following fields) is unknown.
}
