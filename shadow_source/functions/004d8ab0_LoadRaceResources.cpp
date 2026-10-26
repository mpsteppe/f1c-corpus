// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8AB0
// Canonical corpus name: sub_4D8AB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D8AB0_004d8ab0.c

void UnknownObject::LoadRaceResources()
{
    // Reloads four named resources (globals dword_8AD388/8AD38C/8AD390/8AD394) from a path constructed by joining an override or default base directory with a suffix, then a per-resource name plus a common extension. Each successfully loaded resource is configured with the normalized screen dimensions from this[57] and this[58] at offsets 92 and 96. The first existing resource is released before the reload and the probed path object is removed from the linked list afterwards. Returns the last resource-load result, or 1 when no load runs. Called by RaceInitWithConstants (004d8220).
    // GUARD: If the first resource global dword_8AD388 is already non-null, release the previously loaded resource by calling sub_4D8FB0 before reloading. [global:0x008AD388, callee:0x004D8FB0, source:raw]
    // ASSIGNMENT: Select the base directory for path construction: use dword_5EC408 when set, otherwise fall back to the default application directory byte_5EA438. [global:0x005EC408, global:0x005EA438, source:raw]
    // CALL: Build the directory path into local buffer v7 with StringFormatWithBufferOverflowCheck using format aSS "%s%s" from the chosen base directory and the suffix global off_5D4A5C. [callee:0x0058815F, global:0x005BE860, global:0x005D4A5C, source:raw]
    // CALL: Probe/resolve the constructed path by calling sub_53CBC0 with a byref result flag v5; the subsequent load block runs only when v5 becomes non-zero. [callee:0x0053CBC0, source:raw]
    // GUARD: Guard on the path-probe result v5; when it is zero the four resource loads are skipped and the function returns 1. [source:raw]
    // LOOP: Four sequential resource loads. Each iteration formats a per-resource name as "%s%s" from one of the name suffix globals (off_5D4A48, off_5D4A4C, off_5D4A50, off_5D4A54) plus the common suffix off_5D4A58, then calls sub_53CFE0 with allocation size 133120 to load into the corresponding resource global. [global:0x005D4A48, global:0x005D4A4C, global:0x005D4A50, global:0x005D4A54, global:0x005D4A58, callee:0x0053CFE0, source:raw]
    // GUARD: After each sub_53CFE0 load, if the target resource global (dword_8AD388, dword_8AD38C, dword_8AD390, or dword_8AD394) is non-null, configure it: call MaskedFieldSetter(0, 192), then write this[57] (normalized screen width, field this+0xE4) to resource offset 92 and this[58] (normalized screen height, field this+0xE8) to resource offset 96. [callee:0x00552FD0, global:0x008AD388, global:0x008AD38C, global:0x008AD390, global:0x008AD394, field:this:0x000000E4, field:this:0x000000E8, source:raw]
    // CALL: Remove the probed path object from the linked list via PhysicsObjectLinkedListRemoval after the four loads complete. [callee:0x0053CE40, source:raw]
    // RETURN: Return v2, which holds the return value of the last sub_53CFE0 load (dword_8AD394) or 1 when no load path executed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D8AB0(_DWORD *this) {
    //     int result = 1;
    //     if (dword_8AD388) sub_4D8FB0();
    //     const char *base = dword_5EC408 ? (const char *)dword_5EC408 : byte_5EA438;
    //     int probe = 0;
    //     char path[128], name[32];
    //     StringFormatWithBufferOverflowCheck(path, "%s%s", base, off_5D4A5C);
    //     sub_53CBC0(&probe, path);
    //     if (probe) {
    //       const char *suffixes[] = { off_5D4A48, off_5D4A4C, off_5D4A50, off_5D4A54 };
    //       int *handles[] = { &dword_8AD388, &dword_8AD38C, &dword_8AD390, &dword_8AD394 };
    //       for (i = 0; i < 4; ++i) {
    //         StringFormatWithBufferOverflowCheck(name, "%s%s", suffixes[i], off_5D4A58);
    //         result = sub_53CFE0(handles[i], name, 133120);
    //         if (*handles[i]) {
    //           MaskedFieldSetter(0, 192);
    //           *(_DWORD *)(*handles[i] + 92) = this[57];
    //           *(_DWORD *)(*handles[i] + 96) = this[58];
    //         }
    //       }
    //       PhysicsObjectLinkedListRemoval(probe);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Exact semantics of sub_53CBC0 (path probe/resolution) and sub_53CFE0 (resource loader) are not documented within this function; their roles are inferred from call shape and existing analysis.
    // UNRESOLVED: The meaning of MaskedFieldSetter(0, 192) on each loaded resource is unknown.
    // UNRESOLVED: Whether the four resources are audio, render, or other object types is unresolved; existing analysis labels them music/audio handles at DERIVED tier only.
    // UNRESOLVED: The final call ResourcePathBuilder-like helper set is not referenced here; only the probed path cleanup is evidenced.
}
