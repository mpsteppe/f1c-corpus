// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004326E0
// Canonical corpus name: PlayerNameSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerNameSetup_004326e0.c

void UnknownObject::PlayerNameSetup()
{
    // Sets up the player-name configuration at startup (called from DynMan_Init). Reads the settings setup file, copies setup files into place, resolves the settings folder path (using dword_7CE5EC or a default buffer byte_5EA438), searches a string table for a player name to copy into byte_5EC4CC, then walks a per-driver linked list rooted at *(this+0x20) looking for the first entry whose name matches the default name; on a match it enumerates the matching file path via PathNormalizerFileEnumeration. Wraps the whole pass with Wrapper calls.
    // CALL: Call SettingsSetupFileRead(this) to read the settings setup file and enumerate its directory. [callee:0x00432180, field:this:0x00000000, abi:lead]
    // CALL: Call SettingsCopySetupFileCopy((char***)this) to copy settings files to their target locations. [callee:0x00432220, field:this:0x00000000]
    // CALL: Call Wrapper(this) for the initial settings pass. [callee:0x004326D0, field:this:0x00000000]
    // GUARD: Select the settings folder source path: use dword_7CE5EC if nonzero, otherwise fall back to the default buffer &byte_5EA438. [global:0x007CE5EC, global:0x005EA438]
    // CALL: Call SettingsFolderResolver on the selected settings path to resolve the settings section. [callee:0x004326A0, global:0x007CE5EC, global:0x005EA438]
    // CALL: Call StringCopyWithBufferRealloc(resolvedPath) to copy the resolved path into an owning buffer. [callee:0x00566650]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, &byte_5EA438, byte_5EC4CC) to search a sorted string table for the player name held in byte_5EA438. [callee:0x00423A00, global:0x005EC4C0, global:0x005EA438, global:0x005EC4CC]
    // GUARD: If the string-table search hit, copy &byte_5EA438 into byte_5EC4CC; otherwise clear byte_5EC4CC (set first byte to 0). [global:0x005EC4CC, global:0x005EA438]
    // ASSIGNMENT: strcpy(byte_5EC4CC, &byte_5EA438) when the search matched, or byte_5EC4CC[0] = 0 when the source pointer is null. [global:0x005EC4CC, global:0x005EA438]
    // CALL: Call StringCopyWithBufferRealloc(byte_5EC4CC) to copy the player-name buffer into an owning buffer. [callee:0x00566650, global:0x005EC4CC]
    // LOOP: Iterate the per-driver list rooted at *(this+0x20); the loop bound comes from *(this+0x2C) and the walk advances through node +4 (next) pointers. [field:obj:0x00000020, field:obj:0x0000002C, field:*(*(obj+0x20)+0x4):0x00000004]
    // CALCULATION: Walk the linked list: fetch node via *(*(this+0x20)) and advance with v6 = *(v6 + 4); the remaining walk index v5 counts down as nodes are skipped. [field:*(*(obj+0x20)+0x4):0x00000004, field:*(*(obj+0x20)+0x4):0x00000000]
    // GUARD: Stop the walk when the node pointer is null or the node's name pointer (*node) is null. [field:*(*(obj+0x20)+0x4):0x00000000, field:*(*(obj+0x20)+0x4):0x00000004]
    // ASSIGNMENT: Take the candidate name from the node: v8 = *node, defaulting to &byte_5EA438 when the node name pointer is null. [field:*(*(*(obj+0x20)+0x4)+0x0):0x00000000, global:0x005EA438]
    // CALL: Call sub_588410(candidateName, &byte_5EA438) to compare the node's name against the default player name. [callee:0x00588410, global:0x005EA438, field:*(*(*(obj+0x20)+0x4)+0x0):0x00000000]
    // GUARD: If sub_588410 returns false (names do not match), prepare the candidate path (defaulting to &byte_5EA438 when the node name is null) and enumerate it. [callee:0x00588410, global:0x005EA438]
    // CALL: Call PathNormalizerFileEnumeration(candidatePath) to enumerate the matching file in the settings directory, then break out of the loop. [callee:0x00432980, global:0x005EA438]
    // CALL: Call Wrapper(this) for the final settings pass. [callee:0x004326D0, field:this:0x00000000]
    // RETURN: Return 0 on completion. [abi:lead, function:0x004326E0]

    // Conservative worker pseudocode:
    //   int PlayerNameSetup(char **this) {
    //     SettingsSetupFileRead(this);
    //     SettingsCopySetupFileCopy((char***)this);
    //     Wrapper(this);
    //     const char *path = dword_7CE5EC ? dword_7CE5EC : &byte_5EA438;
    //     StringCopyWithBufferRealloc(SettingsFolderResolver(path));
    //     if (BinarySearchInStringTable(byte_5EC4C0, &byte_5EA438, byte_5EC4CC))
    //       (&byte_5EA438) ? strcpy(byte_5EC4CC, &byte_5EA438) : (byte_5EC4CC[0] = 0);
    //     StringCopyWithBufferRealloc(byte_5EC4CC);
    //     for (int i = 0; i < *((DWORD*)*this + 11); i++) {
    //       DWORD node = *((DWORD*)*this + 8);
    //       for (int j = i; j > 0 && node; j--) node = *(DWORD*)(node + 4);
    //       if (!node || !*(DWORD*)node) break;
    //       char *name = *(char**)node;
    //       if (!name) name = &byte_5EA438;
    //       if (!sub_588410(name, &byte_5EA438)) {
    //         char *cand = *(char**)node;
    //         if (!cand) cand = &byte_5EA438;
    //         PathNormalizerFileEnumeration(cand);
    //         break;
    //       }
    //     }
    //     Wrapper(this);
    //     return 0;
    //   }
    // UNRESOLVED: callee FreeWrapper_7bcf (0x00587BCF) appears in the packet but not in the raw decompiled C text; likely an inlined or unrendered allocator/destructor path, so no operation was bound to it.
    // UNRESOLVED: Exact semantics of BinarySearchInStringTable's three buffers (byte_5EC4C0 table, byte_5EA438 needle, byte_5EC4CC output) are inferred only from the call site.
    // UNRESOLVED: Node struct at *(*(this+0x20)+0x4): +0 holds a char* name pointer and +4 a next pointer; the enclosing driver-entry struct type and its other members are unknown.
    // UNRESOLVED: Relationship between the count field *(this+0x2C) and the list head *(this+0x20) is not fully determined from this function alone.
    // UNRESOLVED: sub_588410 (string comparison / match predicate) is unverified; the equality sense (match vs non-match) is inferred from the follow-up enumerate-on-false branch.
    // UNRESOLVED: PathNormalizerFileEnumeration enumerates files for the matched name, but the exact filesystem semantics are outside this function.
}
