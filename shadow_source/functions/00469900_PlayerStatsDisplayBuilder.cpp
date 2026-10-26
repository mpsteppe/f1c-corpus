// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469900
// Canonical corpus name: sub_469900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_469900_00469900.c

void UnknownObject::PlayerStatsDisplayBuilder()
{
    // Builds the player stats display page. Seeds three word buffers from word_5C694C, derives a default path prefix from byte_5EA438, updates the global track-name string dword_7CE668 to match this[96] (field at this+0x180) when they differ, then walks the race-result linked list (head dword_7D2DC0, cursor dword_7D2DC8). For the head entry and then each list entry it formats the grand-prix name, race number and lap time and creates one UI menu item per column label (UIListIndexedAccessor 0, 1, 2), prefixing each item with the path buffer and emitting a blank separator item before every list entry.
    // ASSIGNMENT: Seed local buffers: v23 = byte_5EA438[0] (default path prefix), v24/v25 cleared; each of v29, v28, v27 starts with word_5C694C followed by memset zeroed tails. [global:0x005EA438, global:0x005C694C]
    // ASSIGNMENT: Resolve track-name strings: v1 = this[96] (field at this+0x180) falling back to byte_5EA438; v2 = dword_7CE668 falling back to byte_5EA438. [field:this:0x00000180, global:0x007CE668, global:0x005EA438]
    // GUARD: When strcmp(v2, v1) is non-zero the global track-name string dword_7CE668 differs from this[96]; it is updated via StringCopyWithBufferRealloc. [global:0x007CE668, field:this:0x00000180, global:0x005EA438, callee:0x00566650]
    // ASSIGNMENT: dword_7D2DC8 = dword_7D2DC0 copies the race-result list head into the walk cursor. [global:0x007D2DC8, global:0x007D2DC0]
    // GUARD: If dword_7D2DC0 (list head) is non-null and its node holds an entry, the head entry is formatted specially before the loop. [global:0x007D2DC0]
    // CALL: StringCopyWithValidation(v29, 64, aGrandprixname, entry name or byte_5EA438) copies the grand-prix name; on success sub_587DD0(v29, name, 63) post-processes it and the high byte of the v30 terminator is cleared. [callee:0x004C58A0, global:0x005C693C, global:0x005EA438, callee:0x00587DD0]
    // CALL: StringFormatWithBufferOverflowCheck(v27, "%d", race number at entry+16) formats the race number into v27. [callee:0x0058815F]
    // CALCULATION: Lap time: CRTFtol converts the seconds float at entry+20; minutes = v/60; when minutes > 0 the remainder seconds float is reduced by 60*minutes; then StringFormatWithBufferOverflowCheck(v28, "%i:%06.3f", v/60, remainder) formats minutes and seconds into v28. [callee:0x00587BDC, callee:0x0058815F, global:0x005C6930]
    // CALL: StrlenOverwrite(&v23) fixes the length/termination of the path prefix buffer after assembly. [callee:0x004894D0]
    // CALL: For column labels 0, 1 and 2: UIListIndexedAccessor(label) fetches the label, StringFormatWithBufferOverflowCheck(v31, "%s%s%s", label, path buffer, data buffer) composes the item text, and UIMenuItemCreator(v31, 0, 0, 0, 0) creates the menu item. [callee:0x00487010, callee:0x0058815F, global:0x005C6784, callee:0x00489600]
    // LOOP: Walk the race-result linked list: advance the cursor dword_7D2DC8 to *(node+4) and take the entry from the node; while an entry exists, emit a blank separator item (StringFormatWithBufferOverflowCheck(v31, byte_5EA438) + UIMenuItemCreator), then format the grand-prix name, race number and lap time into items exactly like the head entry, and advance. [global:0x007D2DC8, global:0x005EA438, callee:0x0058815F, callee:0x00489600, callee:0x00487010, callee:0x004C58A0, global:0x005C693C, callee:0x00587DD0, callee:0x00587BDC, global:0x005C6930, global:0x005C6784]
    // RETURN: Returns the final cursor value read from dword_7D2DC8 (the last node visited, or 0 when the list is empty). [source:raw, global:0x007D2DC8]

    // Conservative worker pseudocode:
    //   seedBuffers();
    //   v1 = this[96] ? this[96] : byte_5EA438;
    //   v2 = dword_7CE668 ? dword_7CE668 : byte_5EA438;
    //   if (strcmp(v2, v1) != 0) StringCopyWithBufferRealloc(dword_7CE668 ? dword_7CE668 : byte_5EA438);
    //   dword_7D2DC8 = dword_7D2DC0;
    //   if (dword_7D2DC0 && *(dword_7D2DC0)) {
    //     formatGrandPrixName(v29, entry);
    //     formatRaceNumber(v27, entry);
    //     formatLapTime(v28, entry);
    //   }
    //   StrlenOverwrite(&v23);
    //   emitColumnItems(0); emitColumnItems(1); emitColumnItems(2);
    //   while (cursor = next(cursor)) {
    //     emitSeparator();
    //     formatGrandPrixName(v29, cursor); formatRaceNumber(v27, cursor); formatLapTime(v28, cursor);
    //     emitColumnItems(0); emitColumnItems(1); emitColumnItems(2);
    //   }
    //   return dword_7D2DC8;
    // UNRESOLVED: aD_1 (0x005C3280) and unk_8AC368 (0x008AC368) are packet-listed globals with no occurrence in the raw source text.
    // UNRESOLVED: Exact identity of the format-string literals ("%d", "%s%s%s", "%i:%06.3f") versus the packet string globals is not fully pinned.
    // UNRESOLVED: byte_5EA438[0] path-prefix assembly and the meaning of the v30 terminator high byte are inferred.
}
