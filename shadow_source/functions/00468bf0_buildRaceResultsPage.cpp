// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00468BF0
// Canonical corpus name: sub_468BF0
// Owner: GrandPrixResultsHtmlWriter [DERIVED]
// Raw source: functions/sub_468BF0_00468bf0.c

void GrandPrixResultsHtmlWriter::buildRaceResultsPage()
{
    // Builds the career race-results page: syncs the displayed track-name global from this+0x17C, then walks the race-result linked list (head dword_7D2DC0, walk pointer dword_7D2DC8), resolving each entry's grand-prix name, formatting race number and lap time, and emitting one UI menu item per column with labels from UIListIndexedAccessor(10/11/12).
    // ASSIGNMENT: Initialize local text buffers: v19 (256-byte row buffer) seeded from String1 (0x007CD8BC); v17/v15/v16 seeded from word_5C694C with zero-filled tails and v18 cleared. [global:0x007CD8BC, global:0x005C694C]
    // CALCULATION: Sync the global track name: read this+0x17C (fallback byte_5EA438) and compare with dword_7CE668 (fallback byte_5EA438); if they differ, StringCopyWithBufferRealloc updates the global track-name buffer from this object's name. [field:this:0x0000017C, global:0x007CE668, global:0x005EA438, callee:0x00566650]
    // ASSIGNMENT: Seed the walk: dword_7D2DC8 = dword_7D2DC0 (list head); current node = *dword_7D2DC0 or null when the list is empty. [global:0x007D2DC0, global:0x007D2DC8]
    // LOOP: Iterate the race-result linked list until the current node is null; the first iteration runs unconditionally via the loop flag. [global:0x007D2DC0, global:0x007D2DC8, source:raw]
    // CALL: Resolve the grand-prix name for the node: read the node's name pointer (fallback byte_5EA438); if SeasonRacesSectionFinder succeeds, StringKeyedLinkedListSearch(aGrandprixname) -> DataEntryAccessor -> strcpy into v17, otherwise bounded copy via sub_587DD0(v17, name, 63). [callee:0x004C5840, callee:0x005679C0, global:0x005C693C, callee:0x00567970, callee:0x00587DD0, global:0x005EA438]
    // CALL: Format the race number read from node+16 as "%d" into v16. [callee:0x0058815F, global:0x005C3280]
    // CALCULATION: Format the lap time: read the float at node+20, compute whole minutes as CRTFtol(value) / 60, keep the fractional-seconds remainder after subtracting whole minutes, and format "%i:%06.3f" into v15. [callee:0x00587BDC, callee:0x0058815F, global:0x005C6930]
    // CALL: Emit row 1: join the UIListIndexedAccessor(10) label, the word_5C692C separator and the grand-prix name v17 as "%s%s%s" into v19, then UIMenuItemCreator(v19, 0, 0, 0, 0). [callee:0x00487010, callee:0x0058815F, global:0x005C6784, global:0x005C692C, callee:0x00489600]
    // CALL: Emit row 2: join the UIListIndexedAccessor(11) label, the separator and the race number v16 as "%s%s%s", then UIMenuItemCreator. [callee:0x00487010, callee:0x0058815F, global:0x005C6784, global:0x005C692C, callee:0x00489600]
    // CALL: Emit row 3: join the UIListIndexedAccessor(12) label, the separator and the lap time v15 as "%s%s%s", then UIMenuItemCreator. [callee:0x00487010, callee:0x0058815F, global:0x005C6784, global:0x005C692C, callee:0x00489600]
    // CALL: Emit a separator row: format v19 from byte_5EA438 (default/empty) and call UIMenuItemCreator. [global:0x005EA438, callee:0x0058815F, callee:0x00489600]
    // ASSIGNMENT: Advance the walk: dword_7D2DC8 = *dword_7D2DC8+4 (next link); if nonzero, current node = *next, else current node = null. [global:0x007D2DC8, global:0x007D2DC0]
    // RETURN: Return the final node pointer (result). [source:raw, function:0x00468BF0]

    // Conservative worker pseudocode:
    //   init_row_and_column_buffers();
    //   if (strcmp(global_track_name ?: "", this->track_name ?: "") != 0) copy_track_name(global_track_name);
    //   walk = list_head; node = list_head ? *list_head : null;
    //   do {
    //       if (node) {
    //           name = node->name ?: "";
    //           if (is_season_race(name)) { gp = search("GrandPrixName"); if (gp) strcpy(gp_name, data(gp)); else copy_bounded(gp_name, name, 63); }
    //           sprintf(race_number, "%d", node->number);
    //           t = node->lap_time_float; mins = ftol(t)/60; if (mins > 0) t -= 60*mins;
    //           sprintf(lap_time, "%i:%06.3f", mins, t);
    //       }
    //       emit_row(label(10), gp_name);
    //       emit_row(label(11), race_number);
    //       emit_row(label(12), lap_time);
    //       emit_row("");
    //       walk = walk ? *walk+4 : 0; node = walk ? *walk : 0;
    //   } while (node);
    //   return result;
    // UNRESOLVED: role of global unk_8AC368 (0x008AC368), read-only
    // UNRESOLVED: node layout beyond offsets +16 (race number) and +20 (lap time float)
    // UNRESOLVED: meaning of the UIListIndexedAccessor label indices 10 / 11 / 12
    // UNRESOLVED: exact association of format-string globals aD_1 / aSSS_0 / aI063f with the inline "%d" / "%s%s%s" / "%i:%06.3f" literals
}
