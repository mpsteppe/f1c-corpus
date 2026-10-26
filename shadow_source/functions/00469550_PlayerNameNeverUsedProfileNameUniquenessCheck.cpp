// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469550
// Canonical corpus name: PlayerNameNeverUsedProfileNameUniquenessCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerNameNeverUsedProfileNameUniquenessCheck_00469550.c

void UnknownObject::PlayerNameNeverUsedProfileNameUniquenessCheck()
{
    // Profile-name uniqueness check over the receiver's linked-list of profile filenames. Returns false when a2 is null or empty, true when the profile count at this[276] (offset 0x450) is non-positive or when a2 matches none of the entries, and otherwise falls through to a special-case boolean combining the byte_7D2E41 flag with a comparison of a2 against the "PlayerNameNever" string. Called by ProfileAlreadyExistsPageHandler (0046CB50).
    // GUARD: If a2 is null or its strlen is zero, return false immediately. [source:raw]
    // ASSIGNMENT: Initialize the iteration index v3 to 0 and snapshot the entry count v5 = this[276] (field 0x450). [field:this:0x00000450, source:raw]
    // GUARD: If the entry count v5 is not positive, return true (no profiles exist to conflict with). [field:this:0x00000450, source:raw]
    // LOOP: Iterate the linked list from index 0 upward while the index stays below the entry count. [source:raw]
    // CALL: Fetch the profile filename at index v3 from the receiver's linked list via FilenameFromLinkedList. [callee:0x004693E0, source:raw]
    // ASSIGNMENT: Seed the local buffer: v6[0] = byte_5EA438[0], memset the remaining 0x1FC bytes to 0, and zero v7 and v8. [global:0x005EA438, source:raw]
    // CALL: Call sub_568910(512) to move the fetched filename into the local comparison buffer. [callee:0x00568910, source:raw]
    // CALL: Compare the local buffer against a2 via sub_588410; a non-zero result (match) breaks the loop. [callee:0x00588410, source:raw]
    // RETURN: After incrementing v3, if the index reaches the entry count v5 with no match, return true. [field:this:0x00000450, source:raw]
    // RETURN: Fall-through (a match was found): return byte_7D2E41 AND the negation of comparing the aPlayernameneve string against a2. [global:0x007D2E41, global:0x005C6970, callee:0x00588410, source:raw]
    // CALL: Invoked by ProfileAlreadyExistsPageHandler (0046CB50) during profile creation/validation. [caller:0x0046CB50, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_469550(DWORD* this, const char* a2) {
    //     if (!a2 || strlen(a2) == 0) return false;
    //     int v3 = 0;
    //     int v5 = this[276];
    //     if (v5 <= 0) return true;
    //     while (true) {
    //       FilenameFromLinkedList(this, v3);
    //       char v6[509]; __int16 v7; char v8;
    //       v6[0] = byte_5EA438[0];
    //       memset(&v6[1], 0, 0x1FC);
    //       v7 = 0; v8 = 0;
    //       sub_568910(512);
    //       if (sub_588410(v6, a2)) break;
    //       if (++v3 >= v5) return true;
    //     }
    //     return byte_7D2E41 && !sub_588410(aPlayernameneve, a2);
    //   }
    // UNRESOLVED: sub_568910 and sub_588410 are unnamed; the fill labels them filename-copy and string-compare, unverifiable from this packet
    // UNRESOLVED: The break-on-match path falls to a special-case boolean involving the aPlayernameneve string rather than an immediate false; the exact intended semantics are ambiguous
    // UNRESOLVED: The byte_7D2E41 flag (fill labels it Byte_SeasonScoringFlag) and the byte_5EA438 buffer meaning are unverifiable from this packet
    // UNRESOLVED: The linked-list element type and how FilenameFromLinkedList populates the comparison buffer depend on sub_568910's contract
}
