// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B04E0
// Canonical corpus name: StringCopyFileCheckDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyFileCheckDispatch_004b04e0.c

void UnknownObject::StringCopyFileCheckDispatch()
{
    // Copies the input string a2 into the internal buffer at this+20, selects a target directory (dword_5EC440, falling back to byte_5EA438 when null), and checks that directory against the copied path with sub_566810. If the check fails, builds the full path from a2 and the copied buffer via sub_4B01B0. Finally calls PlayerFileInit(a3) and returns its result.
    // LOOP: Copy the null-terminated string a2 byte by byte into the internal buffer at this+20. [source:raw, function:0x004B04E0]
    // GUARD: Select the target directory v7 as dword_5EC440, or byte_5EA438 as the fallback if dword_5EC440 is null. [global:0x005EC440, global:0x005EA438]
    // GUARD: If sub_566810(buffer_at_this_plus_20, v7) returns false, build the full path from a2 and the copied buffer via sub_4B01B0. [callee:0x00566810, callee:0x004B01B0]
    // RETURN: Call PlayerFileInit(a3) and return its result. [callee:0x004B0540]

    // Conservative worker pseudocode:
    //   v3 = this + 20;
    //   strcpy(v3, a2);
    //   v7 = dword_5EC440 ? dword_5EC440 : byte_5EA438;
    //   if (!sub_566810(v3, v7)) sub_4B01B0(a2, v3);
    //   return PlayerFileInit(a3);
    // UNRESOLVED: Semantics of sub_566810 (directory prefix comparison) and sub_4B01B0 (path building) are inferred from callers, not confirmed.
    // UNRESOLVED: Purpose of the a3 argument passed to PlayerFileInit is unknown.
}
