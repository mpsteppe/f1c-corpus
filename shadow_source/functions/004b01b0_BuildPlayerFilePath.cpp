// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B01B0
// Canonical corpus name: sub_4B01B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B01B0_004b01b0.c

void UnknownObject::BuildPlayerFilePath()
{
    // Builds a full player file path in the caller-provided buffer a2: null-check guard on both arguments (returns -1 on failure), normalizes/copies the source string a1 into a2 via sub_4B0180, appends a1 again, then appends the '.PLR' suffix (global aPlr at 0x005CC1F4 with terminator byte_5CC1F8). Returns 0 on success. Called by StringCopyFileCheckDispatch (004B04E0) and TextFileReader (004B09A0).
    // GUARD: If either argument is null (a1 or a2), return -1 immediately. [source:raw]
    // CALL: sub_4B0180(a1, (int)a2) normalizes or copies the input string a1 into the destination buffer a2. [callee:0x004B0180, source:raw]
    // CALCULATION: Append the input string a1 to the destination buffer a2 with strcat (a1 is the file/player name portion). [source:raw]
    // CALCULATION: Append the '.PLR' file extension to a2 via strcat; the literal is stored at global aPlr (0x005CC1F4) with its trailing terminator byte at byte_5CC1F8 (0x005CC1F8). [global:0x005CC1F4, global:0x005CC1F8, source:raw]
    // RETURN: Return 0 on success (-1 on the null guard); the resulting buffer is consumed by StringCopyFileCheckDispatch (004B04E0) and TextFileReader (004B09A0). [function:0x004B01B0, caller:0x004B04E0, caller:0x004B09A0, source:raw]

    // Conservative worker pseudocode:
    //   int BuildPlayerFilePath(const char* a1, char* a2) {
    //     if (!a1 || !a2) return -1;
    //     sub_4B0180(a1, (int)a2);
    //     strcat(a2, a1);
    //     strcat(a2, ".PLR");
    //     return 0;
    //   }
    // UNRESOLVED: sub_4B0180's exact behavior (path normalization versus plain copy) is not visible from this packet; the doubled appearance of a1 (once via sub_4B0180, once via strcat) is unexplained.
    // UNRESOLVED: Whether a1 is a bare player name or an already-prefixed path is unknown; callers only establish that the result is a file path.
}
