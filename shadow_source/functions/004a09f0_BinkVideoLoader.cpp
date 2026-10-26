// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A09F0
// Canonical corpus name: sub_4A09F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A09F0_004a09f0.c

void UnknownObject::BinkVideoLoader()
{
    // Loads the .bik (Bink) video file for the current scene. Guarded by the scene-array entry (dword_8AC490 + 396*dword_8AC48C) being non-null and dword_7D032C == 1; extracts the directory component of the scene name, appends the .bik extension, and loads it with a retry loop. Returns the load result, or 1 when the guard fails.
    // GUARD: Proceed only if the scene entry dword_8AC490 + 396*dword_8AC48C is non-null AND dword_7D032C == 1; otherwise return 1. [global:0x008AC490, global:0x008AC48C, global:0x007D032C, source:raw]
    // RETURN: Return 1 (no load) when the guard fails. [source:raw]
    // CALCULATION: v1 = scene-name string at dword_8AC490 + 396*dword_8AC48C + 4; v2 = its end, located via strlen. [global:0x008AC490, global:0x008AC48C, source:raw]
    // LOOP: Scan v2 backward from the string end for a backslash ('\', 0x5C); stop when it reaches the string start, then advance past the backslash to isolate the directory component. [source:raw]
    // ASSIGNMENT: v3 = dword_5EC418 base path, or byte_5EA438 default directory when null. [global:0x005EC418, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v4, "%s%s%s", base, dir, .bik) builds the video path using format-string global aSSS_0 and suffix global aBik_0. [callee:0x0058815F, global:0x005C6784, global:0x005CD02C, global:0x005EC418, source:raw]
    // CALL: FileLoadWithRetryLoop(v4, 1): load the .bik file with a retry loop. [callee:0x004F9B70, source:raw]
    // RETURN: Return the FileLoadWithRetryLoop result. [source:raw]

    // Conservative worker pseudocode:
    //   if ((dword_8AC490 + 396*dword_8AC48C) && dword_7D032C == 1) {
    //       p = scene_name_ptr; end = p + strlen(p);
    //       while (end > p && *end != '\\') end--;
    //       if (end > p) end++;
    //       base = dword_5EC418 ? dword_5EC418 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(v4, "%s%s%s", base, end, aBik_0);
    //       return FileLoadWithRetryLoop(v4, 1);
    //   }
    //   return 1;
    // UNRESOLVED: aBik_0 (0x005CD02C) is the .bik extension string per the fill (BikField, DERIVED); the raw source renders it as the third format argument.
    // UNRESOLVED: aSSS_0 (0x005C6784) is the "%s%s%s" format string per the fill (sFormatPath, DERIVED); it is not spelled in the raw source text.
    // UNRESOLVED: unk_8AFE18 (0x008AFE18) appears in the packet globals table but has no visible raw-source access; its role (GameRacePhaseTimer per the fill) is not evidenced here.
    // UNRESOLVED: strlen is an implicit CRT call evidenced only by source:raw.
    // UNRESOLVED: Literals 396 (scene stride), 4, and 92 (backslash) come only from the raw source.
    // UNRESOLVED: dword_7D032C == 1 and dword_8AC48C as a scene index are fill-derived (DERIVED) semantics.
}
