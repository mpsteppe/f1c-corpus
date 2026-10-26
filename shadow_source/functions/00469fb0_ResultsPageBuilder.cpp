// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469FB0
// Canonical corpus name: ResultsPageBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResultsPageBuilder_00469fb0.c

void UnknownObject::ResultsPageBuilder()
{
    // Builds a results page menu for a race-results list. Walks the linked list rooted at dword_7D2DC0 (head copied into dword_7D2DC8), skips any entry whose path matches the settings file path (dword_7CE5EC or byte_5EA438), and for each surviving entry records the track name (looked up under aTrackname in the season-races section) plus the race number and a lap time formatted as minutes:seconds. The assembled strings are emitted as UI menu items via UIMenuItemCreator with column headers retrieved by UIListIndexedAccessor(1) and (2). ABI label Results_Page_Builder is LEGACY-only and unverified.
    // ASSIGNMENT: Initialize locals: seed the header byte v18 from byte_5EA438[0], and seed the three wide buffers v24/v23/v22 with word_5C694C followed by zero-fill (memset sizes 60 and 30 bytes). [global:0x005EA438, global:0x005C694C, source:raw]
    // CALL: Perform page-scope state cleanup by calling StateCleanupNotification(this) before building. [callee:0x00489CB0, source:raw]
    // ASSIGNMENT: Start the result walk: dword_7D2DC8 = dword_7D2DC0 (list head), and read the first entry pointer from the head node. [global:0x007D2DC0, global:0x007D2DC8, source:raw]
    // LOOP: Iterate the race-results list through the node link pointer (second dword of each entry), updating the walker global dword_7D2DC8 each step, until the link chain terminates. [global:0x007D2DC8, source:raw]
    // GUARD: Per entry, compare the entry path (string at the node, or byte_5EA438 when null) against the settings path (dword_7CE5EC, or byte_5EA438 when null) via sub_588410; entries that match are skipped for result formatting. [callee:0x00588410, global:0x007CE5EC, global:0x005EA438, source:raw]
    // CALL: For a surviving entry, locate its season-races section with SeasonRacesSectionFinder on the entry path. [callee:0x004C5840, source:raw]
    // CALL: If the section was found, copy the entry path into the v24 track buffer with sub_587DD0 (bound 0x3F), null its tail, then search for the aTrackname key with StringKeyedLinkedListSearch and overwrite the buffer with the matching value via DataEntryAccessor when present. [callee:0x00587DD0, callee:0x005679C0, callee:0x00567970, global:0x005C6984, source:raw]
    // CALL: Format the race number into v22 with StringFormatWithBufferOverflowCheck using "%d" on the entry dword at offset 16. [callee:0x0058815F, source:raw]
    // CALCULATION: Read the lap time float at entry offset 20, truncate it to an integer with CRTFtol, then split into whole minutes (divide by 60) and a remainder, reducing the float by the minute part when at least one minute is present. [callee:0x00587BDC, source:raw]
    // CALL: Format the lap time into v23 with StringFormatWithBufferOverflowCheck using "%i:%06.3f" on the minutes value and the remainder. [callee:0x0058815F, source:raw]
    // CALL: Refresh the header buffer length with StrlenOverwrite(&v18) after the string writes. [callee:0x004894D0, source:raw]
    // CALL: Build a title text into v26 from byte_5EA438 via StringFormatWithBufferOverflowCheck and create the UI menu item with UIMenuItemCreator(this, v26, 0, 0, 0, 0). [callee:0x0058815F, callee:0x00489600, global:0x005EA438, source:raw]
    // CALL: Emit column header 1: read label 1 with UIListIndexedAccessor(this, 1), concatenate label + header + race number via "%s%s%s" into v26, and create the menu item. [callee:0x00487010, callee:0x0058815F, callee:0x00489600, source:raw]
    // CALL: Emit column header 2: read label 2 with UIListIndexedAccessor(this, 2), concatenate label + header + lap time via "%s%s%s" into v26, and create the menu item. [callee:0x00487010, callee:0x0058815F, callee:0x00489600, source:raw]
    // RETURN: Return the result of the final UIMenuItemCreator call. [callee:0x00489600, source:raw]

    // Conservative worker pseudocode:
    //   void ResultsPageBuilder(int *this) {
    //     char header = byte_5EA438[0];
    //     word v24[31] = { word_5C694C }; memset(v24 + 1, 0, 0x3C);
    //     word v23[16] = { word_5C694C }; memset(v23 + 1, 0, 30);
    //     word v22[16] = { word_5C694C }; memset(v22 + 1, 0, 30);
    //     StateCleanupNotification(this);
    //     int *node = (int *)dword_7D2DC0; dword_7D2DC8 = (int)node;
    //     int *entry = node ? (int *)*node : 0;
    //     while (entry) {
    //       const char *entryPath = entry[0] ? (const char *)entry[0] : byte_5EA438;
    //       const char *settingsPath = dword_7CE5EC ? (const char *)dword_7CE5EC : byte_5EA438;
    //       if (!sub_588410(entryPath, settingsPath)) {
    //         void *section = SeasonRacesSectionFinder((int)entryPath);
    //         if (section) {
    //           sub_587DD0(v24, entryPath, 0x3F);
    //           void *found = StringKeyedLinkedListSearch(section, (int)aTrackname);
    //           if (found) strcpy((char *)v24, DataEntryAccessor(found));
    //         }
    //         StringFormatWithBufferOverflowCheck(v22, "%d", entry[4]);
    //         double t = *(float *)(entry + 5);
    //         int whole = CRTFtol(t);
    //         int minutes = whole / 60;
    //         if (minutes > 0) t -= (double)(60 * minutes);
    //         StringFormatWithBufferOverflowCheck(v23, "%i:%06.3f", minutes, t);
    //       }
    //       int *next = entry[1]; dword_7D2DC8 = (int)next;
    //       entry = next ? (int *)*next : 0;
    //     }
    //     StrlenOverwrite(&header);
    //     char text[256];
    //     StringFormatWithBufferOverflowCheck(text, byte_5EA438);
    //     UIMenuItemCreator(this, text, 0, 0, 0, 0);
    //     StringFormatWithBufferOverflowCheck(text, "%s%s%s", UIListIndexedAccessor(this, 1), &header, v22);
    //     UIMenuItemCreator(this, text, 0, 0, 0, 0);
    //     StringFormatWithBufferOverflowCheck(text, "%s%s%s", UIListIndexedAccessor(this, 2), &header, v23);
    //     return UIMenuItemCreator(this, text, 0, 0, 0, 0);
    //   }
    // UNRESOLVED: The string globals aD_1 (0x005C3280), aSSS_0 (0x005C6784) and aI063f (0x005C6930) are flagged by packet facts but do not appear in the raw decompiled source; their role is unknown.
    // UNRESOLVED: The untyped global unk_8AC368 is flagged by packet facts but absent from the raw source; its role here is unknown.
    // UNRESOLVED: sub_588410 is treated as a path-equality filter from call context; its exact comparison semantics are not documented in this function.
    // UNRESOLVED: The label strings returned by UIListIndexedAccessor(1) and (2) are defined elsewhere; their content is unknown.
    // UNRESOLVED: The stride and layout of the race-results list nodes (string at offset 0, link at offset 4, race number at offset 16, lap-time float at offset 20) are inferred from this access pattern only.
}
