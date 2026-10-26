// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423A00
// Canonical corpus name: BinarySearchInStringTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinarySearchInStringTable_00423a00.c

void UnknownObject::BinarySearchInStringTable()
{
    // Binary searches a sorted string table (16-byte entries). this+4 holds the entry count, this+8 the table base; each entry stores a key pointer at +0 and a value pointer at +8. On a key match the value string is copied into the output buffer a3 (returns 0); on a miss or empty table the input key a2 is copied into a3 instead (returns -1). Null key/value pointers fall back to a default string at byte_5EA438.
    // ASSIGNMENT: Load the entry count from this+4 into the high search bound; initialize the low bound to 0. [field:this:0x00000004, source:raw]
    // GUARD: If the entry count is <= 0, skip the search, copy the input key a2 into the output buffer a3 (strcpy) and return -1. [source:raw]
    // ASSIGNMENT: Load the table base pointer from this+8. [field:this:0x00000008, source:raw]
    // LOOP: Binary search loop: compute mid index v5 = (low+high)>>1, fetch the entry key pointer at table + 16*v5; if the pointer is null substitute the default string byte_5EA438. [global:0x005EA438, source:raw]
    // CALCULATION: Compare the search key a2 against the entry key with strcmp. On equality break out of the loop; if the key is greater move the low bound to mid+1, otherwise move the high bound to mid. [source:raw]
    // GUARD: If the low bound reaches the high bound without a match, copy the input key a2 into the output buffer a3 and return -1. [source:raw]
    // ASSIGNMENT: On match, load the value pointer at the matched entry (table + 16*mid + 8); if null substitute the default string byte_5EA438. [field:this:0x00000008, global:0x005EA438, source:raw]
    // LOOP: Copy the matched value string byte-by-byte into the output buffer a3 using a null-terminator-scanned copy loop. [source:raw]
    // RETURN: Return 0 on a successful match, -1 on a miss. [function:0x00423A00, source:raw]

    // Conservative worker pseudocode:
    //   int hi = this->count;
    //   int lo = 0;
    //   if (hi <= 0) { strcpy(out, key); return -1; }
    //   char* base = this->table;
    //   for (;;) {
    //       int mid = (lo + hi) >> 1;
    //       const char* k = *(const char**)(base + 16*mid);
    //       if (!k) k = byte_5EA438;
    //       int c = strcmp(key, k);
    //       if (c == 0) break;
    //       if (c > 0) lo = mid + 1; else hi = (lo + hi) >> 1;
    //       if (lo >= hi) { strcpy(out, key); return -1; }
    //   }
    //   char* v = *(char**)(base + 16*mid + 8);
    //   if (!v) v = byte_5EA438;
    //   while (*v) *out++ = *v++;
    //   return 0;
    // UNRESOLVED: The 16-byte table entry layout (key pointer at +0, value pointer at +8) is DERIVED from the decompiled body's arithmetic; no formal struct definition is available in the packet.
    // UNRESOLVED: byte_5EA438 is treated as a default fallback string, but its actual content is not evidenced by this packet.
}
