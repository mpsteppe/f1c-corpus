// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C81A0
// Canonical corpus name: ListSearchWithGlobalMatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListSearchWithGlobalMatch_004c81a0.c

void UnknownObject::ListSearchWithGlobalMatch()
{
    // Searches a linked list for an entry whose data word at +4 matches the global dword_8ACFCC. Reads the list header at this+0xC; when non-null, copies the head pointer into the header cursor slot (this+0x14) and walks the list. For each entry it compares the word at entry+4 against dword_8ACFCC; on mismatch it advances the cursor through the entry node next-pointer and continues; on match it clears the word at entry+0x18 (a match flag) and returns. Returns without modification when the header, the head pointer, or a cursor data pointer is null. Called by sub_4B3400.
    // GUARD: If the list header pointer this+0xC (this[3]) is null, skip the search entirely. [field:this:0x0000000C, guard:0, source:raw]
    // ASSIGNMENT: Copy the header head pointer (field *(this+0xC)+0) into the cursor slot this+0x14 so iteration starts at the head. [field:*(this+0xC):0x00000000, field:this:0x00000014, source:raw]
    // GUARD: If the head pointer is null, skip the search because the cursor already equals the null head. [field:*(this+0xC):0x00000000, source:raw]
    // GUARD: If the first entry data pointer (field of the cursor at +0) is null, return without modifying anything. [field:*(this+0x14):0x00000000, source:raw]
    // LOOP: Walk entries while the word at current-entry+4 does not equal the comparison global dword_8ACFCC. [field:*(*(this+0x14)+0x0):0x00000004, global:0x008ACFCC, source:raw]
    // ASSIGNMENT: Advance the cursor: when the current cursor value is non-null, overwrite the cursor slot this+0x14 with the current cursor node's next-pointer (+4). [field:this:0x00000014, field:*(this+0x14):0x00000004, source:raw]
    // GUARD: After advancing, if the new cursor is null, or its data pointer is null, stop iterating and return without a match. [field:*(this+0x14):0x00000000, source:raw]
    // STATE_TRANSITION: On match (entry+4 equals dword_8ACFCC), when the entry data word at +4 is non-null, clear the entry match-flag word at +0x18 to 0. [field:*(*(this+0x14)+0x0):0x00000018, field:*(*(this+0x14)+0x0):0x00000004, source:raw]
    // RETURN: The function returns void; control falls out after a found match, the null guards, or exhaustion of the walk. [function:0x004C81A0, source:raw]
    // CALL: Invoked by sub_4B3400 (004b3400) as the list-search utility. [caller:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   if ((header = this[3]) == 0) return;
    //   header[2] = header[0];
    //   if (header[2] == 0) return;
    //   entry = header[2][0];
    //   if (entry == 0) return;
    //   while (entry[1] != dword_8ACFCC) {
    //       if (header[2]) header[2] = header[2][1];
    //       if (header[2] == 0) return;
    //       entry = header[2][0];
    //       if (entry == 0) return;
    //   }
    //   if (entry[1]) entry[6] = 0;
    // UNRESOLVED: this+0x14 is presented by the packet as a direct field of `this` but is implemented as the cursor slot at offset +8 inside the header pointed to by this+0xC; both views address the same storage.
    // UNRESOLVED: The semantic meaning of the comparison word at entry+0x4 and the match-flag word at entry+0x18 is not established beyond the raw source.
}
