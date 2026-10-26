// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046CD20
// Canonical corpus name: CopyProfileIconBMP
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CopyProfileIconBMP_0046cd20.c

void UnknownObject::CopyProfileIconBMP()
{
    // Copies the profile icon bitmap file (lpExistingFileName, source) into a destination path built from this[57] (or the byte_5EA438 default) plus the appended literal "ProfileIcon.bmp", then triggers scene/track state reload and refresh. Removes any stale linked-list node keyed by the destination path, verifies the source file via sub_497AD0, strips backslash/extension fragments from a copy of the source name into the managed buffer, copies with CopyFileA (fail-if-exists), then dispatches two game commands through the dword_7CD8C0 vtable+28 interface (17: scene name accessor + track config loader; 45: followed by a vtable+56 call), copies data-path strings via StringCopyWithBufferRealloc, calls sub_4B0770(0), and returns 0.
    // GUARD: Source directory: read this[57] (byte offset 0xE4); if null, fall back to the byte_5EA438 default path. [field:this:0x000000E4, global:0x005EA438, source:raw]
    // CALL: NameCompareAndFormat(v1) normalizes the source directory path string. [callee:0x004B1410, source:raw]
    // CALL: PathTruncationUtility(NewFileName, 256) initializes the 256-byte destination path buffer. [callee:0x004B0220, source:raw]
    // CALCULATION: Append the 16-byte literal "ProfileIcon.bmp" (aProfileiconBmp plus byte_5C6954, byte_5C6958, byte_5C695C) to NewFileName at strlen(NewFileName) by copying four dwords. [global:0x005C6950, global:0x005C6954, global:0x005C6958, global:0x005C695C, source:raw]
    // CALL: LinkedListNodeRemovalByStringKey(NewFileName) removes any existing linked-list node keyed by the destination path. [callee:0x00497C40, source:raw]
    // GUARD: If sub_497AD0(lpExistingFileName, 0) returns non-null, the source icon file lpExistingFileName exists and the copy block proceeds; otherwise the copy block is skipped. [callee:0x00497AD0, global:0x005C6658, source:raw]
    // LOOP: Scan lpExistingFileName backward to the last backslash (92) to isolate the filename portion, keeping the whole string if none is found. [global:0x005C6658, source:raw]
    // CALL: StringCopyWithBufferRealloc(v6) copies the isolated filename portion into the managed buffer. [callee:0x00566650, source:raw]
    // ASSIGNMENT: v7 = dword_7CE684, or byte_5EA438 if null; scan backward to the last dot (46) and truncate the extension by writing 0 there. [global:0x007CE684, global:0x005EA438, source:raw]
    // CALL: FileAttributesExistenceCheck(NewFileName) verifies or cleans up the destination file attributes. [callee:0x00568540, source:raw]
    // CALL: CopyFileA(lpExistingFileName, NewFileName, 1) copies the source icon file to the destination path, failing if the destination already exists (bFailIfExists = 1). [global:0x0059E19C, source:raw]
    // CALL: Virtual dispatch through the dword_7CD8C0 command interface (vtable + 28) with argument 17, producing result object v9/v10. [global:0x007CD8C0, function:0x0046CD20, source:raw]
    // GUARD: If the command 17 result object v9 is non-null, proceed with scene/track reload. [global:0x007CD8C0, function:0x0046CD20, source:raw]
    // CALL: SeasonSceneNameAccessor(v9) accesses the current scene name after the command dispatch. [callee:0x00477640, source:raw]
    // CALL: TrackSceneConfigLoader(v10) loads the track/scene configuration. [callee:0x00477680, source:raw]
    // ASSIGNMENT: v11 = dword_7CE64C, or byte_5EA438 if null. [global:0x007CE64C, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v11) copies the data path string into the managed buffer. [callee:0x00566650, source:raw]
    // CALL: StringCopyWithBufferRealloc(byte_5EA438) copies the default path string into the managed buffer. [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: sub_4B0770(0) performs a post-copy refresh or cleanup with argument 0. [callee:0x004B0770, source:raw]
    // CALL: Virtual dispatch through the dword_7CD8C0 command interface (vtable + 28) with argument 45, producing result object v12. [global:0x007CD8C0, function:0x0046CD20, source:raw]
    // GUARD: If the command 45 result object v12 is non-null, make a virtual call through v12's vtable + 56 with argument 0. [global:0x007CD8C0, function:0x0046CD20, source:raw]
    // RETURN: Return 0. [function:0x0046CD20, source:raw]

    // Conservative worker pseudocode:
    //   char* srcDir = this[57] ? (char*)this[57] : byte_5EA438;
    //   NameCompareAndFormat(srcDir);
    //   PathTruncationUtility(NewFileName, 256);
    //   strcat(NewFileName, aProfileiconBmp);  // append "ProfileIcon.bmp"
    //   LinkedListNodeRemovalByStringKey(NewFileName);
    //   if (sub_497AD0(lpExistingFileName, 0)) {
    //     // isolate filename portion after the last backslash (92)
    //     const char* name = strrchr(lpExistingFileName, '\\'); name = name ? name + 1 : lpExistingFileName;
    //     StringCopyWithBufferRealloc(name);
    //     // strip extension at last dot (46) from dword_7CE684 (or byte_5EA438)
    //     char* p = dword_7CE684 ? (char*)dword_7CE684 : byte_5EA438;
    //     char* dot = strrchr(p, '.'); if (dot) *dot = 0;
    //     FileAttributesExistenceCheck(NewFileName);
    //     CopyFileA(lpExistingFileName, NewFileName, 1);
    //   }
    //   void* cmd17 = dispatch(dword_7CD8C0, 17);
    //   if (cmd17) { SeasonSceneNameAccessor(cmd17); TrackSceneConfigLoader(cmd17); }
    //   StringCopyWithBufferRealloc(dword_7CE64C ? (char*)dword_7CE64C : byte_5EA438);
    //   StringCopyWithBufferRealloc(byte_5EA438);
    //   sub_4B0770(0);
    //   void* cmd45 = dispatch(dword_7CD8C0, 45);
    //   if (cmd45) call vtable+56 on cmd45 with argument 0;
    //   return 0;
    // UNRESOLVED: callee:0x00587BCF FreeWrapper_7bcf appears in the packet's static callee list but not in the raw function body; it is likely reached indirectly (e.g. a buffer free inside StringCopyWithBufferRealloc or inside a virtual dispatch), so its exact role here is not evidenced.
    // UNRESOLVED: global:0x007CE498 (byte_7CE498) and global:0x007CE630 (dword_7CE630) are in the packet's static global list but absent from the raw function body; their role in this function is not evidenced.
    // UNRESOLVED: The command dispatch through dword_7CD8C0 (vtable + 28) and the per-command-object call at vtable + 56 are indirect; the concrete callees for commands 17 and 45 are not present in the packet.
}
