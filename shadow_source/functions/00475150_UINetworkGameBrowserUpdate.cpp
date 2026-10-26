// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475150
// Canonical corpus name: sub_475150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_475150_00475150.c

void UnknownObject::UINetworkGameBrowserUpdate()
{
    // Updates the network-game browser list on a UI object. Reads the current search text from the screen text accessor into a local buffer, notifies the state machine of a cleanup, and when the session manager (dword_7CD25C) reports more than zero games and is not in the searching state, sorts the session list and iterates each session, building a display row (description + translated string + player count + session id) and creating a menu item whose outline color reflects the session's locked/joined flag and player-count flag. When no sessions exist, it shows a 'Searching...' or 'No games available' status menu item instead. Called by StateResetAndConditionalInit (0x00475530) and ConditionalChain (0x00475570).
    // ASSIGNMENT: v28[0] = 0: clear the local search-text buffer. [source:raw]
    // CALL: v2 = UIScreenTextAccessor(this); if non-null, copy the current search string from the screen text accessor into v28. [callee:0x00489920, source:raw]
    // CALL: StateCleanupNotification(this): notify the UI state machine that a cleanup/refresh is happening. [callee:0x00489CB0, source:raw]
    // CALL: v5 = ShortComputation_1ff0(dword_7CD25C): query the session manager for the current game count; store into v20. [callee:0x00461FF0, global:0x007CD25C, source:raw]
    // GUARD: If the game count v5 > 0 AND VehicleStateQueryAtLargeOffset(dword_7CD25C) is false (manager not in the searching state), populate the list; otherwise fall through to the status-message path. [callee:0x00461FC0, global:0x007CD25C, source:raw]
    // CALL: NetworkFilterSort(dword_7CD25C, dword_7D1020, 0, 0): sort the session list by the network filter parameter before iterating. [callee:0x00462160, global:0x007CD25C, global:0x007D1020, source:raw]
    // LOOP: Iterate sessions from index 0 while v6 < v20, incrementing v19 each pass. [source:raw]
    // CALL: FAILWRONGDESCRIPTION(v24) then v27[0] = 0: reset the per-session description and secondary buffers. [callee:0x00461550, source:raw]
    // GUARD: Indirect thiscall via loc_462010(dword_7CD25C, v6, v24, v27, 64, &v17) returns non-zero AND v25 < 9999: fetch the session's description into v24, its translated name into v27, and a flag into v17; a session id at or above 9999 is skipped. [global:0x007CD25C, source:raw]
    // CALL: Build the row string: seed v26 with the session description v24, then StrlenOverwrite(v26); if BinarySearchInStringTable(byte_5EC4C0, v27, byte_5EC4CC) succeeds, copy the translated string from byte_5EC4CC back into itself and append it to v26. [callee:0x00423A00, callee:0x004894D0, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Format the player count v23 = '%d/%d' from v24[101] and v24[102] via StringFormatWithBufferOverflowCheck, append to v26, and StrlenOverwrite. [callee:0x0058815F, callee:0x004894D0, source:raw]
    // CALL: Format the session id v21 = '%d' from v25, append it to v26, and format the loop index v22 = '%d' from v19. [callee:0x0058815F, source:raw]
    // CALL: UIMenuItemCreator(v26, v11, byte_5EA438, v22, 0) where v11 = this[46] (the resource path at this+0xB8) with fallback to byte_5EA438: create the menu row for the session. [callee:0x00489600, field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: Set the row outline color via UIItemNameSetter(this[37] - 1, color): grey outline (aFtim14greyoutl) when the locked/joined flag v17 is set, else red outline (aFtim14redoutli) when BitFlagTestAt0x6E(v24, 2) holds, else black outline (aFtim14blkoutli). [callee:0x00489C10, callee:0x004615F0, field:this:0x00000094, global:0x005C6A28, global:0x005C6A58, global:0x005C7118, source:raw]
    // CALL: EmptyStub_0170(v24): per-iteration cleanup of the session description buffer. [callee:0x004B0170, source:raw]
    // GUARD: After the loop, if the search text v28 is non-empty, UIListSearchAndSelect(v28, 0) restores the selection. [callee:0x00489BA0, source:raw]
    // RETURN: If at least one row was created (v18), return ByteSetterAt0xe0(1) to mark the list enabled. [callee:0x0048A3B0, source:raw]
    // CALL: When the loop did not produce rows, call ByteSetterAt0xe0(0) to mark the list disabled. [callee:0x0048A3B0, source:raw]
    // CALL: If VehicleStateQueryAtLargeOffset(dword_7CD25C) is set (manager still searching), copy the aSearching string into byte_5EC4CC via BinarySearchInStringTable. [callee:0x00461FC0, callee:0x00423A00, global:0x005C70F4, global:0x005EC4C0, global:0x005EC4CC, global:0x007CD25C, source:raw]
    // CALL: Otherwise copy the aNoGamesAvailab string into byte_5EC4CC via BinarySearchInStringTable. [callee:0x00423A00, global:0x005C7104, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: UIMenuItemCreator(byte_5EC4CC, byte_5EA438, 0, 0, 0): create a single status menu item carrying the Searching / No games available message. [callee:0x00489600, global:0x005EA438, global:0x005EC4CC, source:raw]
    // RETURN: Return the result of the status UIMenuItemCreator call. [source:raw]

    // Conservative worker pseudocode:
    //   int UINetworkGameBrowserUpdate(void** this) {
    //     char searchText[128] = {0};
    //     copyFromUIScreenTextAccessor(this, searchText);
    //     StateCleanupNotification(this);
    //     int count = ShortComputation_1ff0(dword_7CD25C);
    //     if (count > 0 && !VehicleStateQueryAtLargeOffset(dword_7CD25C)) {
    //       NetworkFilterSort(dword_7CD25C, dword_7D1020, 0, 0);
    //       int made = 0;
    //       for (int i = 0; i < count; ++i) {
    //         char desc[112]; char name[64]; int flags; FAILWRONGDESCRIPTION(desc);
    //         if (loc_462010(dword_7CD25C, i, desc, name, 64, &flags) && sid < 9999) {
    //           buildRow(desc, name, desc[101], desc[102], sid);
    //           UIMenuItemCreator(row, this[46] ? this[46] : byte_5EA438, byte_5EA438, idx, 0);
    //           UIItemNameSetter(this[37] - 1, flags ? aFtim14greyoutl : (bit2(desc) ? aFtim14redoutli : aFtim14blkoutli));
    //           ++made;
    //         }
    //       }
    //       if (searchText[0]) UIListSearchAndSelect(searchText, 0);
    //       if (made) return ByteSetterAt0xe0(1);
    //     }
    //     ByteSetterAt0xe0(0);
    //     copyMsg(VehicleStateQueryAtLargeOffset(dword_7CD25C) ? aSearching : aNoGamesAvailab, byte_5EC4CC);
    //     return UIMenuItemCreator(byte_5EC4CC, byte_5EA438, 0, 0, 0);
    //   }
    // UNRESOLVED: Two packet globals, aD_1 (0x005C3280) and aDD_4 (0x005C6B1C), are not referenced by name in the raw source; they are likely the folded-in '%d' / '%d/%d' format strings used by StringFormatWithBufferOverflowCheck, but the association is not deterministic from this packet.
    // UNRESOLVED: The indirect call target loc_462010 (per-session info query) is invoked but is not present in the packet callee table.
    // UNRESOLVED: Semantics of v25 (session identifier) and the 9999 ceiling are inferred from usage; the source does not explain their meaning.
    // UNRESOLVED: The object owning this menu state is not established by the packet; owner stays UNKNOWN.
}
