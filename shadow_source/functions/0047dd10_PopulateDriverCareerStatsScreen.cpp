// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047DD10
// Canonical corpus name: DriverCareerStatsHTMLWriter
// Owner: DriverCareerStatsScreen [DERIVED]
// Raw source: functions/DriverCareerStatsHTMLWriter_0047dd10.c

void DriverCareerStatsScreen::PopulateDriverCareerStatsScreen()
{
    // Rebuilds the driver career statistics UI screen: emits a state-cleanup notification, fetches the career-data root through the command interface's vtable slot 28 with argument 17, walks a linked list returned at +0x3C, frees the previous menu-item list stored at this+0x44/0x48/0x4C/0x50, then inserts seven header labels (Driver, Nationality, Date of Birth, Starts, Pole Positions, Wins, Drivers Champion), formats a name line, and for each of seven career statistics keys (nationality, date of birth, starts, poles, wins, drivers championship) looks up the value in a career-data string-keyed linked list and renders it as a UI menu item.
    // CALL: Calls StateCleanupNotification(this) to emit the screen's state-cleanup notification before the list is rebuilt. [callee:0x00489CB0, function:0x0047DD10, source:raw]
    // CALL: Dispatches a virtual call through the object pointed to by dword_7CD8C0: reads the vtable pointer (*(dword_7CD8C0)), calls the slot at vtable byte offset 28 (slot index 7) passing (dword_7CD8C0, 17) to obtain the command/race interface object. [global:0x007CD8C0]
    // GUARD: Proceeds only if the interface object obtained from the vtable dispatch is non-null. [source:raw]
    // CALL: Calls LinkedListIndexedAccessor_f590(result) to index into the obtained interface object's linked list. [callee:0x0048F590]
    // GUARD: Proceeds only if the indexed list accessor result is non-null. [source:raw]
    // ASSIGNMENT: Reads careerData = *(int *)(result + 60): the dword at offset 0x3C of the indexed accessor result, the anchor of the career-data structure used by the rest of the function. [callee:0x0048F590]
    // GUARD: Proceeds only if careerData is non-null. [source:raw]
    // ASSIGNMENT: Loads the existing menu-item list head listNode = this[17] (dword at this+0x44) and initializes the format buffer: v29 = 0, itemFormatBuffer[0] = byte_5EA438[0], v30 = 0. [field:this:0x00000044, global:0x005EA438]
    // LOOP: Walks the menu-item linked list starting at this+0x44: reads the payload pointer from the node's first dword (*(this+0x44) data slot, offset 0x0), reads the next node pointer from the node's second dword (*(this+0x48) slot, offset 0x4), and reads a byte flag at node+8. If the flag is non-zero the payload's inner pointer and the payload are freed via FreeWrapper_7bcf; every node itself is freed via FreeWrapper_7bcf. Loop continues while the next pointer is non-null. [field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004, callee:0x00587BCF]
    // ASSIGNMENT: Clears the four menu-item list pointers to 0: this[17]=0 (this+0x44), this[18]=0 (this+0x48), this[19]=0 (this+0x4C), this[20]=0 (this+0x50). [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // CALL: Inserts the seven header label items into the screen's list via LinkedListInsertWithNodeAllocation(label, -1): aDriver_2 (0x005C73FC, Driver), aNationality_0 (0x005C73EC, Nationality), aDateOfBirth (0x005C73DC, Date of Birth), aStarts (0x005C68F8, Starts), aPolePositions (0x005C6888, Pole Positions), aWins (0x005C6878, Wins), aDriversChampio (0x005C73C4, Drivers Champion). [callee:0x00486F30, global:0x005C73FC, global:0x005C73EC, global:0x005C73DC, global:0x005C68F8, global:0x005C6888, global:0x005C6878, global:0x005C73C4]
    // CALL: Calls StrlenOverwrite(&itemFormatBuffer) to recompute the length of the 4-byte format buffer (v28/v29/v30). [callee:0x004894D0]
    // CALL: Formats StringFormatWithBufferOverflowCheck(v32, "%s", &itemFormatBuffer), copying the format buffer into the 256-byte scratch v32 using the "%s" format string (aS_4 at 0x005C2C18). [callee:0x0058815F, global:0x005C2C18]
    // CALL: Creates the first UI menu item UIMenuItemCreator(v32, 0, 0, 0, 0) from the formatted scratch buffer. [callee:0x00489600]
    // CALL: Calls AudioChannelStop(careerDataPtr + 188): reads the dword at offset 0xBC of the career data structure and passes it as the argument; the result gates the following statistic-rendering block. [callee:0x00568210]
    // GUARD: Proceeds to render statistic rows only if the AudioChannelStop(careerDataPtr+188) result is non-zero. [source:raw]
    // CALL: Renders the driver name row when careerDataPtr != -188: reads driverNameStr = UIListIndexedAccessor(0), formats StringFormatWithBufferOverflowCheck(v32, "%s%s%s", driverNameStr, &itemFormatBuffer, (const char *)(careerDataPtr + 188)) using the "%s%s%s" format (aSSS_0 at 0x005C6784), and creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Looks up the nationality label in the string table: BinarySearchInStringTable(byte_5EC4C0, aNationality, byte_5EC4CC), searching table byte_5EC4C0 for key aNationality (0x005C73B8) and writing the match into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005C73B8, global:0x005EC4CC]
    // LOOP: Copies the aNationality string into byte_5EC4CC (fallback population of the search key buffer): loop reads aNationality[count] and writes byte_5EC4CC[count++] until the terminating NUL is copied. [global:0x005C73B8, global:0x005EC4CC]
    // CALL: Searches the career data string-keyed linked list for the nationality value: nationalityEntry = StringKeyedLinkedListSearch(byte_5EC4CC). [callee:0x005679C0, global:0x005EC4CC]
    // GUARD: Renders the nationality row only if the nationality lookup returned a non-null entry. [source:raw]
    // CALL: Renders the nationality value row: value = DataEntryAccessor(nationalityEntry), label = UIListIndexedAccessor(1), formats StringFormatWithBufferOverflowCheck(v32, "%s%s%s", label, &itemFormatBuffer, value) using aSSS_0, then creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Searches the career data string-keyed linked list for the date-of-birth key aDateofbirth (0x005C73AC). [callee:0x005679C0, global:0x005C73AC]
    // GUARD: Renders the date-of-birth row only if the aDateofbirth lookup returned a non-null entry. [source:raw]
    // CALL: Renders the date-of-birth value row: value = DataEntryAccessor(entry), label = UIListIndexedAccessor(2), formats "%s%s%s" into v32, creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Searches the career data string-keyed linked list for the starts key aStarts_0 (0x005C73A4). [callee:0x005679C0, global:0x005C73A4]
    // GUARD: Renders the starts row only if the aStarts_0 lookup returned a non-null entry. [source:raw]
    // CALL: Renders the starts value row: value = DataEntryAccessor(entry), label = UIListIndexedAccessor(3), formats "%s%s%s" into v32, creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Searches the career data string-keyed linked list for the poles key aPoles (0x005C739C). [callee:0x005679C0, global:0x005C739C]
    // GUARD: Renders the pole positions row only if the aPoles lookup returned a non-null entry. [source:raw]
    // CALL: Renders the pole positions value row: value = DataEntryAccessor(entry), label = UIListIndexedAccessor(4), formats "%s%s%s" into v32, creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Searches the career data string-keyed linked list for the wins key aWins_0 (0x005C7394). [callee:0x005679C0, global:0x005C7394]
    // GUARD: Renders the wins row only if the aWins_0 lookup returned a non-null entry. [source:raw]
    // CALL: Renders the wins value row: value = DataEntryAccessor(entry), label = UIListIndexedAccessor(5), formats "%s%s%s" into v32, creates UIMenuItemCreator(v32, 0, 0, 0, 0). [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // CALL: Searches the career data string-keyed linked list for the drivers championship key aDriverschampio (0x005C737C). [callee:0x005679C0, global:0x005C737C]
    // GUARD: Renders the drivers championship row only if the aDriverschampio lookup returned a non-null entry. [source:raw]
    // CALL: Renders the drivers championship value row: value = DataEntryAccessor(entry), label = UIListIndexedAccessor(6), formats "%s%s%s" into v32, then returns UIMenuItemCreator(v32, 0, 0, 0, 0) as the function result. [callee:0x00567970, callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6784]
    // RETURN: Returns the last computed result (result from AudioChannelStop or the final UIMenuItemCreator call) when the rendered-row tail is reached. [source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this)
    //   iface = (*(*(dword_7CD8C0)+28))(dword_7CD8C0, 17)
    //   accessor = LinkedListIndexedAccessor_f590(iface) if iface
    //   careerData = *(int *)(accessor + 60) if accessor
    //   if careerData:
    //       free_list(this[17])  // walk node chain at this+0x44, free payload + nodes via FreeWrapper_7bcf
    //       this[17]=this[18]=this[19]=this[20]=0
    //       insert labels: Driver, Nationality, Date of Birth, Starts, Pole Positions, Wins, Drivers Champion
    //       StrlenOverwrite(&fmtBuf); format v32="%s" fmtBuf; UIMenuItemCreator(v32,0,0,0,0)
    //       if AudioChannelStop(*(int *)(careerData+188)):
    //           if careerData != -188: render name row (UIListIndexedAccessor(0) + *(careerData+188) as string)
    //           for key,idx in [(Nationality,1),(Date of Birth,2),(Starts,3),(Poles,4),(Wins,5),(Drivers Champion,6)]:
    //               entry = StringKeyedLinkedListSearch(resolved_key)
    //               if entry: render "%s%s%s"(UIListIndexedAccessor(idx), fmtBuf, DataEntryAccessor(entry)) as menu item
    // UNRESOLVED: Global dword_8AD3B4 (0x008AD3B4) appears in the packet's global evidence but has no reference in the raw decompiled source for this function.
    // UNRESOLVED: The dword read at (result + 60) (career-data anchor, offset 0x3C) has no packet field evidence ref.
    // UNRESOLVED: The byte flag read at node+8 inside the free-list loop has no packet field evidence ref.
    // UNRESOLVED: The dword read at (careerDataPtr + 188) (offset 0xBC) is passed to AudioChannelStop and also cast to a string pointer for the name row; its exact meaning is unproven.
    // UNRESOLVED: The vtable slot at byte offset 28 (index 7) of the dword_7CD8C0 object and argument 17 identify an unproven command-interface method.
    // UNRESOLVED: The -1 index passed to LinkedListInsertWithNodeAllocation and the 0..6 indices passed to UIListIndexedAccessor encode list/row positions whose semantic enumeration is not independently established.
    // UNRESOLVED: v29/v30 (int16/char) form the remaining bytes of the 4-byte itemFormatBuffer (v28); they are initialized to 0 and the buffer is consumed by StrlenOverwrite + format calls, but their individual roles are unknown.
}
