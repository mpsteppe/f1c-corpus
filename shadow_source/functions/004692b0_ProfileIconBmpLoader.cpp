// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004692B0
// Canonical corpus name: ProfileIconBmpLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileIconBmpLoader_004692b0.c

void UnknownObject::ProfileIconBmpLoader()
{
    // Builds the file path to "ProfileIcon.bmp" by combining the settings directory (dword_5EC440, falling back to byte_5EA438) with a profile filename retrieved from a linked list via GuardedAccessor and FilenameFromLinkedList. The path is trimmed of trailing backslashes, the icon name is resolved through BinarySearchInStringTable into byte_5EC4CC, appended with strcat, the old linked-list entry matching that path is removed (LinkedListNodeRemovalByStringKey), and PlayerProfileScanner(this, 0) triggers a profile rescan. Returns 0.
    // CALL: GuardedAccessor(): obtain the linked-list handle/index used to retrieve profile entries. [callee:0x0048D360, source:raw]
    // CALL: FilenameFromLinkedList(handle): retrieve the profile filename from the linked list. [callee:0x004693E0, source:raw]
    // ASSIGNMENT: Initialize the local path buffer v12 from byte_5EA438 (default directory string): copy its first byte, zero the following 252 bytes, and zero the two trailing words. [global:0x005EA438, source:raw]
    // GUARD: Branch on dword_5EC440 (settings directory): if it is non-null use it as the directory base, otherwise fall back to byte_5EA438. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v15, "%s%s\\", directory, filename): format directory plus filename plus trailing backslash into v15 using the format string literal. [callee:0x0058815F, global:0x005C6968, source:raw]
    // CALCULATION: Copy the formatted path from v15 into the v12 buffer until the NUL terminator is reached. [source:raw]
    // CALCULATION: Trim trailing backslashes from v12: from the end, zero characters until a backslash (character code 92) is found or the buffer start is reached. [source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC): search the string table for the "ProfileIcon.bmp" name and place its resolved form into byte_5EC4CC. [callee:0x00423A00, global:0x005C6950, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: If the string-table search succeeded, copy aProfileiconBmp ("ProfileIcon.bmp") into byte_5EC4CC. [global:0x005C6950, global:0x005EC4CC, source:raw]
    // CALCULATION: strcat(v12, byte_5EC4CC): append the resolved icon filename to the constructed directory path. [global:0x005EC4CC, source:raw]
    // CALL: LinkedListNodeRemovalByStringKey(v12): remove the linked-list node whose key equals the constructed full path. [callee:0x00497C40, source:raw]
    // CALL: PlayerProfileScanner(this, 0): trigger a profile rescan so the icon change takes effect. [callee:0x00468EE0, source:raw]
    // RETURN: Return 0 after path construction, node removal, and profile rescan. [function:0x004692B0, source:raw]

    // Conservative worker pseudocode:
    //   handle = GuardedAccessor();
    //   filename = FilenameFromLinkedList(handle);
    //   memset(v12, 0, sizeof(v12));
    //   dir = dword_5EC440 ? dword_5EC440 : byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(v15, "%s%s\\", dir, filename);
    //   copy v15 into v12;
    //   trim trailing backslashes from v12;
    //   if (BinarySearchInStringTable(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC))
    //       copy aProfileiconBmp into byte_5EC4CC;
    //   strcat(v12, byte_5EC4CC);
    //   LinkedListNodeRemovalByStringKey(v12);
    //   PlayerProfileScanner(this, 0);
    //   return 0;
    // UNRESOLVED: The owning object class is not established by the packet; owner stays UnknownObject/UNKNOWN.
    // UNRESOLVED: dword_5EC440 as 'settings directory' and byte_5EA438 as 'default application directory' are DERIVED readings from the existing analysis, not independently confirmed.
    // UNRESOLVED: The format string "%s%s\\" is shown in raw source, but the aSS_5 global (0x005C6968) is the packet's record of the format-string literal's storage; its exact identity is not further confirmed.
    // UNRESOLVED: byte_5EC4CC is reused as both the search output and the strcat suffix; whether it is a shared display buffer is unconfirmed.
    // UNRESOLVED: The caller context that selects the profile to remove is not visible in this function.
}
