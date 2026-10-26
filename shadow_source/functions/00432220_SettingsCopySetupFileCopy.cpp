// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432220
// Canonical corpus name: SettingsCopySetupFileCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SettingsCopySetupFileCopy_00432220.c

void UnknownObject::SettingsCopySetupFileCopy()
{
    // Scans the scene setup array (dword_8AC488 entries, stride 0x18C from dword_8AC490), resolves and capitalizes each scene's folder name, creates the directory tree, and when directory creation failed or a config mismatch is detected builds vehicle config entries (128-byte allocations, .svm paths) added via AddVehicleConfigEntryToLinkedList, freeing the temporary entries and terminating the accumulated path string; returns a success flag.
    // ASSIGNMENT: Reads v1 = *this, then v2 = *v1 (first path string); defaults v2 to byte_5EA438 when *v1 is null. [field:this:0x00000000, global:0x005EA438]
    // CALL: Copies the source path string via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438]
    // CALCULATION: v37 = strlen(byte_5EA438): records the default path length for later termination. [global:0x005EA438]
    // CALL: v26 = (CreateDirectoryAWrapper(byte_5EA438) == 0): creates the default application directory; flag set when creation fails. [callee:0x00589671, global:0x005EA438]
    // LOOP: Outer loop over the dword_8AC488 scene entries when dword_8AC488 > 0; v31 indexes entries, v36 counts down from dword_8AC488. [global:0x008AC488]
    // CALCULATION: v3 = v31 + dword_8AC490 + 260: computes the scene entry name offset within the scene array. [global:0x008AC490]
    // CALL: v4 = SeasonRacesSectionFinder(v3): locates the season races section for this scene entry. [callee:0x004C5840]
    // CALL: v5 = SettingsFolderResolver(v3): resolves the settings folder path for the scene. [callee:0x004326A0]
    // LOOP: Byte-by-byte copies the resolved folder string from v5 into local buffer v39 until NUL. [source:raw]
    // CALL: StringCapitalizer(v39): capitalizes the copied folder name. [callee:0x00432650]
    // GUARD: If BinarySearchInStringTable(byte_5EC4C0, v39, byte_5EC4CC) finds the name in the string table, copy v39 into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC]
    // LOOP: Copies v39 bytes into byte_5EC4CC until NUL. [global:0x005EC4CC]
    // CALL: sub_5665B0(byte_5EC4CC): appends/processes the message buffer. [callee:0x005665B0, global:0x005EC4CC]
    // CALL: sub_568620(255): prepares a path/name with size 255. [callee:0x00568620]
    // CALL: CreateDirectoryAWrapper(PathName): creates the scene directory tree. [callee:0x00589671]
    // GUARD: If byte_7D03F8 is set, resolve v10 = dword_7CE5EC (default byte_5EA438) and call sub_588410(v3, v10); on zero return set v24 = 1 (config mismatch). [global:0x007D03F8, global:0x007CE5EC, global:0x005EA438, callee:0x00588410]
    // GUARD: If v26 (dir create failed) or v24 (config mismatch), set v25 = 1 (overall failure flag) and, when v4 is non-null, build the vehicle config linked list. [source:raw, callee:0x004C5840]
    // LOOP: for i = StringKeyedLinkedListSearch(off_5C3FA8[0]); i; i = ShortComputation_adb0(i): walks the scene-entry linked list. [callee:0x005679C0, global:0x005C3FA8, callee:0x0049ADB0]
    // CALL: v32 = OperatorNewNhMallocWrapper(128): allocates a 128-byte config entry; first byte zeroed. [callee:0x00587C03]
    // ASSIGNMENT: v12 = dword_5EC440 (default byte_5EA438) then sub_5665B0(v12): appends settings-directory base to the path buffer. [global:0x005EC440, global:0x005EA438, callee:0x005665B0]
    // CALL: v13 = DataEntryAccessor(i) then sub_5665B0(v13): appends the entry's data string. [callee:0x00567970, callee:0x005665B0]
    // CALL: v14 = DataEntryAccessor(i) then StringCopyWithBufferRealloc(v14): copies the entry data string. [callee:0x00567970, callee:0x00566650]
    // CALL: sub_566810(v15, aSvm) where v15 = v34 (default byte_5EA438): appends the .svm extension; truncates at the found extension if non-null. [callee:0x00566810, global:0x005EA438, global:0x005C403C]
    // CALL: v28[0] = OperatorNewNhMallocWrapper(128): allocates a second 128-byte path buffer; first byte zeroed; capacity recorded as 128. [callee:0x00587C03]
    // CALL: v17 = lpPathName (default byte_5EA438) then sub_5665B0(v17): appends the accumulated path. [global:0x005EA438, callee:0x005665B0]
    // CALCULATION: v19 = strlen(v18) + 1 over the v28[0] path buffer (default byte_5EA438). [global:0x005EA438]
    // GUARD: If the buffer is non-empty and NullSafePointerDereference(v28)[v19-2] is not the backslash character (92), append the backslash from word_5C2AAC via sub_5665B0. [callee:0x00415C30, callee:0x005665B0, global:0x005C2AAC]
    // GUARD: v20 = v34 (default byte_5EA438); if BinarySearchInStringTable(byte_5EC4C0, v20, byte_5EC4CC) matches, strcpy byte_5EC4CC from v20 else empty it. [global:0x005EA438, callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC]
    // CALL: sub_5665B0(byte_5EC4CC) then sub_5665B0(aSvm): appends the matched name and the .svm extension. [callee:0x005665B0, global:0x005EC4CC, global:0x005C403C]
    // CALL: sub_568620(255): finalizes the 255-length path/name buffer. [callee:0x00568620]
    // GUARD: If v24 and v27: call AddVehicleConfigEntryToLinkedList(v40, v38, 0); on failure call sub_568B00(). [callee:0x00433B60, callee:0x00568B00]
    // GUARD: If v26 is false (dir creation actually succeeded), free v28[0], v34, v32 and break out of the linked-list loop. [callee:0x00587BCF]
    // CALL: Else branch calls sub_568B00() (fallback/failure handler). [callee:0x00568B00]
    // ASSIGNMENT: v27 = 0 clears the per-entry flag so only the first matching entry is added. [source:raw]
    // CALL: Frees the temporary buffers v28[0], v34 and v32 via FreeWrapper_7bcf at the end of each iteration. [callee:0x00587BCF]
    // ASSIGNMENT: v21 = lpPathName (default byte_5EA438); terminates it at index v37 with 0. [global:0x005EA438]
    // LOOP: Loop advance: v31 += 396 (scene entry stride), --v36, repeat while v36 != 1. [global:0x008AC490]
    // GUARD: If lpPathName was allocated, free it with FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Returns v25, the failure flag indicating whether any directory/config operation failed. [function:0x00432220]

    // Conservative worker pseudocode:
    //   path = *this ? **this : default; copy default; len = strlen(default)
    //   dirFailed = (CreateDirectory(default) == 0)
    //   for each of dword_8AC488 scene entries:
    //       name = capitalize(SettingsFolderResolver(entry+260))
    //       if in string table: copy name to buffer
    //       build scene path; CreateDirectory(PathName)
    //       mismatch = byte_7D03F8 && !sub_588410(entry, settingsPath)
    //       if dirFailed || mismatch:
    //           for i in scene list: build .svm vehicle config entry (128-byte allocs)
    //           if mismatch && v27: AddVehicleConfigEntryToLinkedList(v40, v38, 0) or sub_568B00()
    //           free temporaries; break on success path
    //       terminate accumulated path at len; advance entry by 396
    //   free lpPathName; return v25
    // UNRESOLVED: Semantics of sub_5665B0, sub_568620, sub_588410, sub_566810 and sub_568B00 are not established by this packet; they are treated as opaque helpers.
    // UNRESOLVED: Global dword_7C73E8 and unk_8AC368 appear in the packet evidence but not in the decompiled body; their role is unresolved.
    // UNRESOLVED: Object base dereference field obj+0x0 is listed but not separately visible in the decompiled body.
    // UNRESOLVED: PathName and v40 local buffers are populated indirectly (via helpers) and by AddVehicleConfigEntryToLinkedList; their exact contents are unresolved here.
    // UNRESOLVED: The 0x18C (396) entry stride for the scene array is inferred from the loop advance literal 396.
}
