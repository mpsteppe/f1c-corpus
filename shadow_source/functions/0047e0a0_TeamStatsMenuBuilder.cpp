// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047E0A0
// Canonical corpus name: sub_47E0A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47E0A0_0047e0a0.c

void UnknownObject::TeamStatsMenuBuilder()
{
    // Builds the championship team statistics menu. Looks up a team statistics record from a global UI list accessor (via a virtual dispatch through dword_7CD8C0 plus LinkedListIndexedAccessor_f590), clears and frees the menu's existing linked list nodes, re-inserts seven stat category headers, then creates seven formatted UI menu items (label + separator + team data string at offsets 700/828/844/908/924/940/956 from the team record) plus one final separator-only item.
    // ASSIGNMENT: Initialize the team statistics string pointer v2 to 0 at function entry. [function:0x0047E0A0, source:raw]
    // CALL: Dispatch a virtual call through the vtable held by dword_7CD8C0 (offset +28) with argument 21 to obtain the stats source object v3. [global:0x007CD8C0, source:raw]
    // GUARD: If v3 is null, skip the team data lookup entirely. [source:raw]
    // CALL: Call LinkedListIndexedAccessor_f590(v3) to obtain the indexed list accessor v4. [callee:0x0048F590, source:raw]
    // GUARD: If v4 is null, skip the team data lookup entirely. [source:raw]
    // GUARD: If *(v4 + 72) > 0 and the pointer stored at *(v4 + 60) is non-null, dereference it into v6; otherwise v6 is 0. [source:raw]
    // ASSIGNMENT: Set v2 to the const char* stored at *(v6 + 60): the team statistics string record. [source:raw]
    // CALL: result = StateCleanupNotification(this): notify the state cleanup path for this menu object. [callee:0x00489CB0, source:raw]
    // GUARD: If v2 (the team statistics record) is non-null, rebuild the menu content. [source:raw]
    // ASSIGNMENT: Seed the list traversal from this[17] (linked list head); initialize separator buffer v19 from byte_5EA438[0] with v20 = 0 and v21 = 0. [field:this:0x00000044, global:0x005EA438, source:raw]
    // LOOP: Walk the linked list starting at this[17]: each iteration reads the flag byte at node + 8 and advances to the next pointer at node + 4, stopping when the next pointer is null. [field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004, source:raw]
    // CALL: When the node flag is set, free the nested data wrapper (and its inner pointer) via FreeWrapper_7bcf; free the node itself afterwards in every iteration. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the linked list fields this[17], this[18], this[19] and this[20] to 0 after freeing the old list. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // CALL: Insert seven stat category headers with index -1 via LinkedListInsertWithNodeAllocation: aTeam_1, aFounded, aHeadquarters, aStarts, aPolePositions, aWins, aConstructorCha. [callee:0x00486F30, global:0x005C743C, global:0x005C7430, global:0x005C7420, global:0x005C68F8, global:0x005C6888, global:0x005C6878, global:0x005C7404, source:raw]
    // CALL: StrlenOverwrite(&v19): recompute the separator buffer length. [callee:0x004894D0, source:raw]
    // LOOP: For each index 0..6: fetch the label with UIListIndexedAccessor(i), format '%s%s%s' (aSSS_0) into v23 as label + separator + team data string read at v2 + 700/828/844/908/924/940/956 respectively, then create a UI menu item via UIMenuItemCreator(v23, 0, 0, 0, 0). [callee:0x00487010, callee:0x0058815F, global:0x005C6784, callee:0x00489600, source:raw]
    // CALL: Format the final separator-only item with the '%s' format (aS_4) into v23, then return UIMenuItemCreator(v23, 0, 0, 0, 0). [callee:0x0058815F, global:0x005C2C18, callee:0x00489600, source:raw]
    // RETURN: When no team statistics record is present, return the stored StateCleanupNotification result. [source:raw]

    // Conservative worker pseudocode:
    //   teamStats = null;
    //   if (src = vtable(dword_7CD8C0, +28, 21)) {
    //     if (acc = LinkedListIndexedAccessor_f590(src)) {
    //       base = (*(acc+60) && *(acc+72) > 0) ? **(acc+60) : 0;
    //       teamStats = *(base + 60);
    //     }
    //   }
    //   result = StateCleanupNotification(this);
    //   if (teamStats) {
    //     freeList(this+0x44); clear this[17..20] = 0;
    //     insert(aTeam_1, aFounded, aHeadquarters, aStarts, aPolePositions, aWins, aConstructorCha);
    //     StrlenOverwrite(&separator);
    //     for (i = 0; i < 7; i++) UIMenuItemCreator(fmt('%s%s%s', UIListIndexedAccessor(i), separator, teamStats + offs[i]), 0, 0, 0, 0);
    //     return UIMenuItemCreator(fmt('%s', separator), 0, 0, 0, 0);
    //   }
    //   return result;
    // UNRESOLVED: The object returned by the virtual dispatch through dword_7CD8C0 (+28, arg 21) is unidentified.
    // UNRESOLVED: Semantics of dword_7CD8C0 itself are unknown.
    // UNRESOLVED: Meaning of each team data string offset (700/828/844/908/924/940/956) is not determined.
    // UNRESOLVED: What UIListIndexedAccessor indices 0..6 resolve to as labels is unknown.
    // UNRESOLVED: The content and role of byte_5EA438[0] as the separator buffer seed are unknown.
}
