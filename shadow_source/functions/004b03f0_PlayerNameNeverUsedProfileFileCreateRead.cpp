// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B03F0
// Canonical corpus name: PlayerNameNeverUsedProfileFileCreateRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerNameNeverUsedProfileFileCreateRead_004b03f0.c

void UnknownObject::PlayerNameNeverUsedProfileFileCreateRead()
{
    // Player-name/profile file bootstrap. Allocates a directory-iterator object, builds a profile filename against the settings directory (dword_5EC440, falling back to byte_5EA438), and scans for existing profile entries. If an entry is found, the directory base and entry name are formatted into a path buffer and the file is copied into the settings directory via StringCopyFileCheckDispatch. If no entry is found, a default 'PlayerNameNever...' text file is read, the function recurses on the same object to create the default profile, and two flag bytes at this+0x49A8 and this+0x49A9 are set to 1. The iterator list is torn down before returning the copy/recursion result.
    // CALL: AllocateStructWithDefaultValues(v8) initializes the directory-iterator object with default values on the stack. [callee:0x00565DC0, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(FileName, &off_5D1FF0, aPlr) formats the profile filename into a 32-CHAR buffer from the string-table entry off_5D1FF0 and suffix aPlr. [callee:0x0058815F, global:0x005D1FF0, global:0x005CC1F4, source:raw]
    // GUARD: Select the directory base: use dword_5EC440 (settings directory) when nonzero, otherwise fall back to byte_5EA438 (default directory). [global:0x005EC440, global:0x005EA438, source:raw]
    // ASSIGNMENT: Store the selected directory base into v2 for the path-build helper. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALL: sub_565F80(FileName, 1, base, 1) joins the selected directory base onto the formatted profile filename. [callee:0x00565F80, source:raw]
    // CALL: sub_566380(2) is invoked with constant argument 2; exact purpose unknown. [callee:0x00566380, source:raw]
    // CALL: DirectoryEntryIterator(v8) iterates the directory object; the returned pointer v3 is the next entry name, or null when iteration is exhausted. [callee:0x005662D0, source:raw]
    // GUARD: Branch on v3: a non-null entry name selects the copy-existing-file path; a null entry selects the recursive default-profile creation path. [source:raw]
    // ASSIGNMENT: On the found-entry path, seed the path buffer v10 with byte_5EA438[0] then clear the remaining 0xFC bytes and terminator slots (v11, v12). [global:0x005EA438, source:raw]
    // CALCULATION: Zero the v10 tail: memset(&v10[1], 0, 0xFC), v11 = 0, v12 = 0 to terminate the string buffer. [source:raw]
    // GUARD: Re-select the directory base for the second format call: dword_5EC440 when nonzero else byte_5EA438. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%s%s", base, v3) concatenates the selected directory base with the found entry name into the path buffer. [callee:0x0058815F, global:0x005BE860, source:raw]
    // CALL: StringCopyFileCheckDispatch(v10, 1) copies the found profile file into the target directory; its result is stored as the function result v5. [callee:0x004B04E0, source:raw]
    // CALL: TextFileReader(aPlayernameneve) reads the default 'PlayerNameNever...' text file when no profile entry exists. [callee:0x004B09A0, global:0x005C6970, source:raw]
    // CALL: PlayerNameNeverUsedProfileFileCreateRead(this) recurses on the same object to create the default profile; result becomes v5. [callee:0x004B03F0, function:0x004B03F0, abi:lead, source:raw]
    // ASSIGNMENT: this[18856] (offset this+0x49A8) is set to 1, marking the profile-created flag byte on the recursive default-profile path. [field:this:0x000049A8, source:raw]
    // ASSIGNMENT: this[18857] (offset this+0x49A9) is set to 1, marking the secondary profile flag byte on the recursive default-profile path. [field:this:0x000049A9, source:raw]
    // CALL: LinkedListDestructorWithChildCleanup(v8) tears down the directory-iterator object before return. [callee:0x00565E20, source:raw]
    // RETURN: Return v5, the copy result from the found-entry path or the recursion result from the default-profile path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B03F0(_BYTE* this) {
    //     void v8; // directory-iterator object
    //     char FileName[32]; char buf[253]; __int16 v11; char v12;
    //     char* base; const char* entry; int result;
    //     AllocateStructWithDefaultValues(&v8);
    //     StringFormatWithBufferOverflowCheck(FileName, &off_5D1FF0, aPlr);
    //     base = dword_5EC440 ? (char*)dword_5EC440 : byte_5EA438;
    //     sub_565F80(FileName, 1, (int)base, 1);
    //     sub_566380(2);
    //     entry = DirectoryEntryIterator(&v8);
    //     if (entry) {
    //       buf[0] = byte_5EA438[0];
    //       memset(&buf[1], 0, 0xFC); v11 = 0; v12 = 0;
    //       base = dword_5EC440 ? (char*)dword_5EC440 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(buf, "%s%s", base, entry);
    //       result = StringCopyFileCheckDispatch(buf, 1);
    //     } else {
    //       TextFileReader(aPlayernameneve);
    //       result = sub_4B03F0(this);
    //       this[18856] = 1;
    //       this[18857] = 1;
    //     }
    //     LinkedListDestructorWithChildCleanup(&v8);
    //     return result;
    //   }
    // UNRESOLVED: Semantics of sub_565F80 and sub_566380(2) are unknown; sub_566380's constant 2 is uninterpreted.
    // UNRESOLVED: StringCopyFileCheckDispatch return value meaning (success/copy status) is unconfirmed.
    // UNRESOLVED: Layout and role of the v8 directory-iterator object are unknown.
    // UNRESOLVED: Precise content of off_5D1FF0 / aPlr format components and the aSS ("%s%s") global relation is not established.
    // UNRESOLVED: Meaning of the two flag bytes at this+0x49A8 / this+0x49A9 beyond 'set to 1 on default-profile creation' is unknown.
    // UNRESOLVED: Recursion depth and termination when no default source exists are unverified.
    // UNRESOLVED: Call sites from ProfileAlreadyExistsPageHandler and sub_485B90 are not analyzed in this packet.
}
