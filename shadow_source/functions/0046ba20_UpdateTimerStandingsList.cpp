// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046BA20
// Canonical corpus name: sub_46BA20
// Owner: TimerStandingsList [DERIVED]
// Raw source: functions/sub_46BA20_0046ba20.c

void TimerStandingsList::UpdateTimerStandingsList()
{
    // Refreshes a timer/standings UI list. With a2 non-zero, forces a full rebuild: StateCleanupNotification clears list state, then for each grid slot v11 = 1..104 the vehicle whose position field (vehicle + 16480) equals v11 is located in dword_7C54F0; non-retired vehicles (vehicle + 13000 != -1) get a display string via FTIMTimerBitmapSelector, a menu item created by UIMenuItemCreator with the vehicle number (vehicle + 18580) formatted as '%d' by StringFormatWithBufferOverflowCheck, and named via UIItemNameSetter. With a2 zero, iterates slots v4 = 0..103 incrementally, finding the vehicle whose position field minus 1 equals v4; when present and not retired it compares the existing item name (UIItemTextAccessor) against a freshly built string and updates it via sub_588410 when unchanged, or jumps to the full rebuild path on a missing item or mismatch. Returns the last computed result (0 on clean completion).
    // ASSIGNMENT: Initialize the local display buffer v20 with the byte_5EA438 seed byte and zero the remainder. [global:0x005EA438, source:raw]
    // GUARD: Branch on a2: non-zero selects the full rebuild path, zero selects the incremental text-update path. [function:0x0046BA20, source:raw]
    // CALL: StateCleanupNotification(this) clears UI list state before the rebuild. [callee:0x00489CB0, source:raw]
    // CALCULATION: Read the vehicle count dword_5C329C as the search bound v8. [global:0x005C329C, source:raw]
    // LOOP: For each slot v11 = 1..104, scan dword_7C54F0[0..v8) for a vehicle whose position field (vehicle + 16480) equals v11; return early when no match exists. [global:0x007C54F0, source:raw]
    // GUARD: Skip the vehicle when its slot-state field at vehicle + 13000 equals -1. [global:0x007C54F0, source:raw]
    // CALL: FTIMTimerBitmapSelector(this, vehicle_index, byte_7CD718, v20) composes the display string for the vehicle position. [callee:0x0046B5F0, global:0x007CD718, global:0x007C54F0, source:raw]
    // CALL: Format the vehicle number field (vehicle + 18580) as '%d' into the local buffer via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x007C54F0, source:raw]
    // CALL: UIMenuItemCreator(byte_7CD718, 0, 0, &v14, 0) creates a new UI menu item. [callee:0x00489600, global:0x007CD718, source:raw]
    // CALL: UIItemNameSetter(v9, v20) assigns the display string as the name of the item at index v9; the item index increments per created item. [callee:0x00489C10, source:raw]
    // LOOP: Incremental path: for each slot v4 = 0..103 find the vehicle in dword_7C54F0 whose position field minus 1 equals v4; when none exists or the vehicle is retired, fetch the existing item via UIListItemByIndex(v4). [callee:0x00489A10, global:0x007C54F0, source:raw]
    // GUARD: For active vehicles, compare the existing item name (UIItemTextAccessor(v4)) against the string freshly built by FTIMTimerBitmapSelector; on a missing item or a mismatch, jump to the full rebuild path (LABEL_16). [callee:0x00489C60, callee:0x00489A10, callee:0x0046B5F0, global:0x007CD718, source:raw]
    // CALL: When the existing text matches, update the item text with sub_588410(v20, v13). [callee:0x00588410, source:raw]
    // RETURN: Return the last computed result; a non-zero result routes control back to the full rebuild path. [function:0x0046BA20, source:raw]

    // Conservative worker pseudocode:
    //   init local display buffers;
    //   if (a2 != 0) {
    //       StateCleanupNotification(this);
    //       for (slot = 1; slot < 104; ++slot) {
    //           find vehicle with position == slot; if none, return;
    //           if (vehicle + 13000 != -1) {
    //               FTIMTimerBitmapSelector(this, idx, byte_7CD718, v20);
    //               format vehicle + 18580 as '%d';
    //               UIMenuItemCreator(byte_7CD718, 0, 0, &v14, 0);
    //               UIItemNameSetter(item_index++, v20);
    //           }
    //       }
    //   } else {
    //       for (v4 = 0; v4 < 104; ++v4) {
    //           find vehicle with position - 1 == v4;
    //           if (none || vehicle + 13000 == -1) item = UIListItemByIndex(v4);
    //           else {
    //               FTIMTimerBitmapSelector(this, i, byte_7CD718, v20);
    //               item = UIListItemByIndex(v4);
    //               text = UIItemTextAccessor(v4);
    //               if (!item || strcmp(item, byte_7CD718) != 0) goto rebuild;
    //               sub_588410(v20, text);
    //           }
    //           if (result) goto rebuild;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: Identity and role of this object passed to FTIMTimerBitmapSelector and StateCleanupNotification (UI state).
    // UNRESOLVED: Global aD_1 (0x5C3280) is listed in the packet but not referenced by the decompiled body.
    // UNRESOLVED: Exact semantics of the vehicle offsets 16480 (position), 13000 (slot state, -1 meaning retired/inactive) and 18580 (number) are inferred from corpus knowledge, not proven by this packet.
    // UNRESOLVED: Why a text mismatch or null result routes to the full rebuild path instead of a local repair.
}
