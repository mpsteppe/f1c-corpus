// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046EE60
// Canonical corpus name: HTMLSeasonOutput
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HTMLSeasonOutput_0046ee60.c

void UnknownObject::HTMLSeasonOutput()
{
    // Builds the season-output HTML/list UI. Cleans up UI state via StateCleanupNotification, creates a path-separator menu item labeled from word_5BEB48, retrieves the entry count from the module callback table dword_7C73E0 via VehicleFieldAccessor, then loops over the list creating one menu item per entry via IndexedListEntryAccessor + UIMenuItemCreator. Returns the result of the last menu-item creation.
    // CALL: Clean up UI state via StateCleanupNotification(this). [callee:0x00489CB0, source:raw]
    // CALL: Create the path-separator menu item via UIMenuItemCreator(this, &word_5BEB48, 0, 0, 0, 0). [global:0x005BEB48, callee:0x00489600, source:raw]
    // CALL: Retrieve the entry count via VehicleFieldAccessor(dword_7C73E0) and cache it in v3. [global:0x007C73E0, callee:0x00432810, source:raw]
    // LOOP: For each index i from 0 to count-1: fetch the entry label via IndexedListEntryAccessor(dword_7C73E0, i) into v5 and create a menu item via UIMenuItemCreator(this, v5, 0, 0, 0, 0), storing the result. [global:0x007C73E0, callee:0x00432820, callee:0x00489600, source:raw]
    // RETURN: Return the result of the last UIMenuItemCreator call. [source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this);
    //   UIMenuItemCreator(this, &word_5BEB48, 0, 0, 0, 0);
    //   v3 = VehicleFieldAccessor(dword_7C73E0);
    //   for (i = 0; i < v3; ++i) {
    //     v5 = IndexedListEntryAccessor(dword_7C73E0, i);
    //     result = UIMenuItemCreator(this, v5, 0, 0, 0, 0);
    //   }
    //   return result;
    // UNRESOLVED: The role of dword_7C73E0 as a module callback table and of word_5BEB48 as a path separator are DERIVED from the legacy analysis; not independently confirmed.
    // UNRESOLVED: The object type behind this and the layout of the created menu items are unknown (owner UNKNOWN).
}
