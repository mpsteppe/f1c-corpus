// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C51A0
// Canonical corpus name: TrackFilePathBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackFilePathBuilder_004c51a0.c

void UnknownObject::TrackFilePathBuilder()
{
    // Registers a scene file in the scene registry: strips the extension (after the last '.') and the directory prefix (after the last '\') from the input path a3 to derive a base filename, searches the scene registry array (dword_8AC488 entries, stride 396, names at entry+260) for a match, creates a new empty entry when absent, stores the full original path into the entry, writes season races data, then computes and stores a formatted scene-file-path result at entry+392 and returns it.
    // LOOP: Scan a3 backwards from its terminator for the last '.' (46) to strip the file extension; when found, overwrite it with a NUL (set *v4 = 0). [source:raw]
    // LOOP: Scan a3 backwards for the last '\' (92) to strip the directory prefix; when found, advance one byte past it so v5 points at the base filename after the final separator. [source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(v14, "%s", v5) to copy the base filename into the local v14 buffer using the aS_4 format string. [callee:0x0058815F, global:0x005C2C18, source:raw]
    // GUARD: Search the registry only when dword_8AC488 (registered scene count) is greater than 0. [global:0x008AC488, source:raw]
    // LOOP: Iterate scene entries at stride 396 starting from a4 + 260, comparing each entry name against the base filename via sub_588410; break when sub_588410 returns 0 (match found), incrementing v6 per entry until v6 reaches dword_8AC488. [callee:0x00588410, global:0x008AC488, source:raw]
    // ASSIGNMENT: When the search exhausted (v6 == dword_8AC488) the name is new: zero the first byte of the empty entry at a4 + 396*v6 + 260, copy the base filename from v14 into it byte-by-byte, then increment dword_8AC488. [global:0x008AC488, source:raw]
    // ASSIGNMENT: Store the full original path a3 into the selected entry (v12 + 4) via strcpy. [source:raw]
    // CALL: Call SeasonRacesSectionWriter(a3) to write season races section data for this scene file. [callee:0x004C5AE0, source:raw]
    // CALL: Call SceneFilePathFormatter(a3, 115, 211) and assign its result. [callee:0x004C5BB0, source:raw]
    // ASSIGNMENT: Store the formatted result into the entry at offset 392 (*(_DWORD *)(v12 + 392) = result). [source:raw]
    // RETURN: Return the formatted scene file path result. [function:0x004C51A0, source:raw]

    // Conservative worker pseudocode:
    //   // strip extension after last '.'
    //   v4 = a3 + strlen(a3);
    //   if (v4 > a3) {
    //     while (*v4 != 46) { if (--v4 <= a3) goto strip_dir; }
    //     *v4 = 0;
    //   }
    //   strip_dir:
    //   v5 = a3 + strlen(a3);
    //   if (v5 > a3) {
    //     while (*v5 != 92) { if (--v5 <= a3) goto format; }
    //     ++v5;
    //   }
    //   format:
    //   StringFormatWithBufferOverflowCheck(v14, aS_4, v5);
    //   v6 = 0;
    //   if (dword_8AC488 > 0) {
    //     v7 = a4 + 260;
    //     do {
    //       if (!sub_588410(v14, v7)) break;
    //       ++v6; v7 += 396;
    //     } while (v6 < dword_8AC488);
    //   }
    //   if (v6 == dword_8AC488) {
    //     v8 = a4 + 396*v6 + 260;
    //     *v8 = 0;
    //     v9 = v14; v10 = v8 - v14;
    //     do { v11 = *v9; v9[v10] = *v9; ++v9; } while (v11);
    //     ++dword_8AC488;
    //   }
    //   v12 = a4 + 396*v6;
    //   strcpy(v12 + 4, a3);
    //   SeasonRacesSectionWriter(a3);
    //   result = SceneFilePathFormatter(a3, 115, 211);
    //   *(_DWORD *)(v12 + 392) = result;
    //   return result;
    // UNRESOLVED: The magic stride 396, the entry name offset 260, the result offset 392, and the constants 115 and 211 passed to SceneFilePathFormatter have no explanatory evidence in the packet.
    // UNRESOLVED: sub_588410 returning 0 to mean 'match found' is inferred from the loop shape (break on zero) and the existing analysis prose.
    // UNRESOLVED: Legacy ABI name Track_File_Path_Builder (abi:lead) is retained as a lead only; the owning object type remains unknown.
    // UNRESOLVED: The roles of parameters a1 and a2 are unknown; they are unused in the raw source body.
}
