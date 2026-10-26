// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047D800
// Canonical corpus name: sub_47D800
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47D800_0047d800.c

void UnknownObject::SeasonResultsMenuBuilder()
{
    // Builds the season results/leaderboard UI menu. It resets UI state, then descends the season data structure (prevyear -> grid -> drivers/times linked lists). When the drivers and times lists have matching counts it iterates both, pairs each driver name with its race time using a separator from byte_5EA438, and creates one UI menu item per pair via UIMenuItemCreator.
    // ASSIGNMENT: Initialize the local format buffer: zero v11/v12, copy byte_5EA438[0] into v10 as the separator prefix, and stash this in v13. [global:0x005EA438, source:raw]
    // CALL: Reset UI state with StateCleanupNotification(this) before building the menu. [callee:0x00489CB0]
    // CALL: Populate the buffer length header via StrlenOverwrite(&v10). [callee:0x004894D0]
    // CALL: Locate the season races data section with SeasonRacesSectionFinder(0), rooted at unk_8AC368. [callee:0x004C5840, global:0x008AC368]
    // GUARD: If the season section was not found, return the null result. [source:raw]
    // CALL: Descend the 'prevyear' key with StringKeyedLinkedListSearch(result, aPrevyear). [callee:0x005679C0, global:0x005C72C8]
    // GUARD: If the prevyear node is null, return. [source:raw]
    // CALL: Descend the 'grid' key with StringKeyedLinkedListSearch(result, aGrid_1) and keep it as v2. [callee:0x005679C0, global:0x005C72C0]
    // GUARD: If the grid node is null, return. [source:raw]
    // CALL: Descend 'drivers' from grid into v3 and 'times' from grid into result with StringKeyedLinkedListSearch. [callee:0x005679C0, global:0x005C72B8, global:0x005C72B0]
    // GUARD: If either the drivers list or the times list is null, return. [source:raw]
    // CALCULATION: Compute the drivers and times list counts with LinkedListCount; proceed only when the two counts match. [callee:0x00567980]
    // LOOP: Iterate index v5 from 0 over the driver count in a do-while loop, reloading LinkedListCount(v3) as the bound. [callee:0x00567980]
    // CALL: Fetch the driver node v6 and the time node v7 for index v5 via NullCheckWrapper. [callee:0x005679A0]
    // GUARD: If either node is null, skip formatting for this index. [source:raw]
    // CALL: Extract the string entries with DataEntryAccessor on both nodes. [callee:0x00567970]
    // CALL: Build the menu label with StringFormatWithBufferOverflowCheck(v14, "%s%s%s", driver, separator, time). [callee:0x0058815F, global:0x005C6784]
    // CALL: Create the UI menu item with UIMenuItemCreator(v13, v14, 0, 0, 0, 0). [callee:0x00489600]
    // CALCULATION: Increment v5; the loop continues while v5 is below the reloaded drivers count. [source:raw]
    // RETURN: Return the final search result pointer (null on any early exit). [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_47D800(void *this) {
    //     char buf[256];
    //     char sep = byte_5EA438[0];
    //     StateCleanupNotification(this);
    //     StrlenOverwrite(&sep);
    //     void *s = SeasonRacesSectionFinder(0);
    //     if (!s) return s;
    //     s = StringKeyedLinkedListSearch(s, "prevyear");
    //     if (!s) return s;
    //     void *grid = StringKeyedLinkedListSearch(s, "grid");
    //     if (!grid) return grid;
    //     void *drivers = StringKeyedLinkedListSearch(grid, "drivers");
    //     s = StringKeyedLinkedListSearch(grid, "times");
    //     if (!drivers || !s) return s;
    //     int n = LinkedListCount(s);
    //     if ((int)LinkedListCount(drivers) != n) return s;
    //     int i = 0;
    //     if ((int)LinkedListCount(drivers) > 0) {
    //       do {
    //         void *dn = NullCheckWrapper(i);
    //         void *tn = NullCheckWrapper(i);
    //         if (dn && tn) {
    //           StringFormatWithBufferOverflowCheck(buf, "%s%s%s",
    //               DataEntryAccessor(dn), &sep, DataEntryAccessor(tn));
    //         }
    //         UIMenuItemCreator(this, buf, 0, 0, 0, 0);
    //         ++i;
    //       } while (i < (int)LinkedListCount(drivers));
    //     }
    //     return s;
    //   }
    // UNRESOLVED: Purpose of the extra zero arguments to UIMenuItemCreator is unknown.
    // UNRESOLVED: The requirement that drivers and times list counts match is structural, but the paired-entry interpretation is inferred.
    // UNRESOLVED: unk_8AC368 as the season data root is DERIVED from the existing fill, not proven.
}
