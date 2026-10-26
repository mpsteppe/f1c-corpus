// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C52C0
// Canonical corpus name: SceneFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFileLoader_004c52c0.c

void UnknownObject::SceneFileLoader()
{
    // Builds the scene (.SCN) file array for the current track/season combination. Resets the scene-state globals, forms a directory path from the track dir (dword_5EC420) and season dir (dword_5EC3D8) with byte_5EA438 as the fallback, and registers it via sub_565F80(aScn, 1, path, 1). Frees any prior scene array at dword_8AC490, then allocates a 396-byte-per-entry array sized by the directory entry count from ShortComputation_5f70(&unk_8AD3B0); when the count is zero it logs four diagnostic messages. Iterates the directory entries building full paths with StringFormatWithBufferOverflowCheck, opening each via sub_587DB0(v9, aR), handing it to TrackFilePathBuilder, then closing it. Tears down the directory list via sub_565EB0 and sorts the resulting scene array with SeasonRacesSceneSorter(this). Returns the scene count dword_8AC488. Called by GameFileLoader (0042D260).
    // ASSIGNMENT: Reset scene state globals on entry: byte_8AC398, byte_8AC3E8, byte_8AC438, dword_8AC488, dword_8AC48C and dword_8AC490 all set to 0. [source:raw, global:0x008AC398, global:0x008AC3E8, global:0x008AC438, global:0x008AC488, global:0x008AC48C, global:0x008AC490]
    // CALCULATION: Select path components with fallbacks: v1 = dword_5EC420 (track dir) or byte_5EA438 when null; v2 = dword_5EC3D8 (season dir) or byte_5EA438 when null. [source:raw, global:0x005EC420, global:0x005EC3D8, global:0x005EA438]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%s%s", v2, v1) concatenates the season and track directory into the path buffer (aSS path-format string). [source:raw, callee:0x0058815F, global:0x005BE860]
    // CALL: sub_565F80(aScn, 1, v8, 1) registers the constructed scene directory path. [source:raw, callee:0x00565F80, global:0x005D31B0]
    // GUARD: When the existing scene array pointer dword_8AC490 is non-null it is released via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF, global:0x008AC490]
    // CALL: v3 = ShortComputation_5f70(&unk_8AD3B0) obtains the directory entry count used to size the scene array. [source:raw, callee:0x00565F70, global:0x008AD3B0]
    // CALL: Allocate the scene array: dword_8AC490 = OperatorNewNhMallocWrapper(396 * v3), then zero it with memset. [source:raw, callee:0x00587C03, global:0x008AC490]
    // GUARD: When the entry count v3 is zero the function emits four distinct diagnostic log messages. [source:raw]
    // CALL: StringSplitLoop(1, aDDevF119992002_8, 1282) gates DebugLogWrite(&dword_8AD25C, aCouldNotFindAn). [source:raw, callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3044, global:0x005D317C, global:0x008AD25C]
    // CALL: StringSplitLoop(1, aDDevF119992002_8, 1283) gates DebugLogWrite(&dword_8AD25C, a1IncorrectSeas). [source:raw, callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3044, global:0x005D3138, global:0x008AD25C]
    // CALL: StringSplitLoop(1, aDDevF119992002_8, 1284) gates DebugLogWrite(&dword_8AD25C, a2WeDoNotHaveRe). [source:raw, callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3044, global:0x005D30FC, global:0x008AD25C]
    // CALL: StringSplitLoop(1, aDDevF119992002_8, 1285) gates DebugLogWrite(&dword_8AD25C, a3ThereAreNoSce). [source:raw, callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3044, global:0x005D30DC, global:0x008AD25C]
    // CALL: LinkedListPopFront_5f50(&unk_8AD3B0) removes the head of the directory entry list before iteration. [source:raw, callee:0x00565F50, global:0x008AD3B0]
    // LOOP: Iterate directory entries: for each i from DirectoryEntryIterator(&unk_8AD3B0), build v9 with StringFormatWithBufferOverflowCheck(v9, "%s%s", v8, i), open v9 with sub_587DB0(v9, aR); when the handle v5 is non-null call TrackFilePathBuilder(v5, 0, v9, dword_8AC490) and FileCloseWithLock(v5); break when LinkedListNodePeek(&unk_8AD3B0) returns 0. [source:raw, callee:0x005662D0, callee:0x0058815F, callee:0x00587DB0, callee:0x004C51A0, callee:0x00587D02, callee:0x00565F20, global:0x008AD3B0, global:0x005C36F0, global:0x008AC490, global:0x005BE860]
    // CALL: sub_565EB0(&unk_8AD3B0) tears down the directory entry list after iteration. [source:raw, callee:0x00565EB0, global:0x008AD3B0]
    // CALL: SeasonRacesSceneSorter(this) sorts the loaded scene array by season/race ordering. [source:raw, callee:0x004C5940]
    // RETURN: Return the scene count dword_8AC488. [source:raw, global:0x008AC488]
    // CALL: Invoked by GameFileLoader (0042D260) as part of the game-file loading path. [caller:0x0042D260]

    // Conservative worker pseudocode:
    //   int sub_4C52C0(void* this) {
    //     const char* trackDir = dword_5EC420;
    //     byte_8AC398 = 0; byte_8AC3E8 = 0; byte_8AC438 = 0;
    //     dword_8AC488 = 0; dword_8AC48C = 0; dword_8AC490 = 0;
    //     if (!trackDir) trackDir = byte_5EA438;
    //     const char* seasonDir = dword_5EC3D8;
    //     if (!seasonDir) seasonDir = byte_5EA438;
    //     char path[256];
    //     StringFormatWithBufferOverflowCheck(path, "%s%s", seasonDir, trackDir);
    //     sub_565F80(aScn, 1, path, 1);
    //     if (dword_8AC490) FreeWrapper_7bcf((LPVOID)dword_8AC490);
    //     int count = ShortComputation_5f70(&unk_8AD3B0);
    //     dword_8AC490 = (int)OperatorNewNhMallocWrapper(396 * count);
    //     memset((void*)dword_8AC490, 0, 4 * ((unsigned int)(396 * count) >> 2));
    //     if (!count) {
    //       if (StringSplitLoop(1, aDDevF119992002_8, 1282)) DebugLogWrite(&dword_8AD25C, aCouldNotFindAn);
    //       if (StringSplitLoop(1, aDDevF119992002_8, 1283)) DebugLogWrite(&dword_8AD25C, a1IncorrectSeas);
    //       if (StringSplitLoop(1, aDDevF119992002_8, 1284)) DebugLogWrite(&dword_8AD25C, a2WeDoNotHaveRe);
    //       if (StringSplitLoop(1, aDDevF119992002_8, 1285)) DebugLogWrite(&dword_8AD25C, a3ThereAreNoSce);
    //     }
    //     LinkedListPopFront_5f50(&unk_8AD3B0);
    //     for (const char* entry = DirectoryEntryIterator(&unk_8AD3B0); entry; entry = DirectoryEntryIterator(&unk_8AD3B0)) {
    //       char full[256];
    //       StringFormatWithBufferOverflowCheck(full, "%s%s", path, entry);
    //       int h = sub_587DB0(full, aR);
    //       if (h) { TrackFilePathBuilder(h, 0, full, dword_8AC490); FileCloseWithLock(h); }
    //       if (!LinkedListNodePeek(&unk_8AD3B0)) break;
    //     }
    //     sub_565EB0(&unk_8AD3B0);
    //     SeasonRacesSceneSorter(this);
    //     return dword_8AC488;
    //   }
    // UNRESOLVED: The three byte flags reset on entry (byte_8AC398, byte_8AC3E8, byte_8AC438) and dword_8AC48C are only zeroed here; their roles as track/SCN-path/AIW-path buffers come from the skeleton fill and are DERIVED.
    // UNRESOLVED: The 396-byte scene entry layout consumed by TrackFilePathBuilder is not defined in this function.
    // UNRESOLVED: aSS (global 0x005BE860) as the "%s%s" path format string is DERIVED from existing analysis; the raw source inlines the literal.
    // UNRESOLVED: Roles of the unnamed helpers sub_565F80, sub_565EB0, sub_587DB0 and the list utilities are inferred from the surrounding call pattern, not named by the packet.
}
