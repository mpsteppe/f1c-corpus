// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3220
// Canonical corpus name: PITANIMSMASAnimationFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PITANIMSMASAnimationFileLoader_004a3220.c

void UnknownObject::PITANIMSMASAnimationFileLoader()
{
    // Loads pit crew animation data from the PITANIMS.MAS archive. Cleans up the existing pit-crew animation array, resolves the base directory from the application directory string byte_5EA438 (truncating at the last backslash), registers that directory with the string manager, opens the archive via sub_53CBC0, runs the main PitCrewAnimationLoader, closes the archive if it was opened, registers the path for string matching, and frees the temporary path copy. Returns the result of PitCrewAnimationLoader.
    // CALL: ArrayResourceCleanup(this) releases the existing pit crew animation array before reloading [callee:0x004A29A0, source:raw]
    // ASSIGNMENT: Initialize temporaries: v13 = 0, v14 = -1 [source:raw]
    // CALL: StringCopyWithBufferRealloc(a2) copies the source path string into a freshly allocated buffer [callee:0x00566650, source:raw]
    // CALCULATION: v6 = strlen(byte_5EA438) + 1 gives the full application directory string length [global:0x005EA438, source:raw]
    // GUARD: If v6 - 1 > 0, scan byte_5EA438 backwards from the last character, breaking at the first backslash (ASCII 92) [global:0x005EA438, source:raw]
    // ASSIGNMENT: Truncate byte_5EA438 at the found backslash (*i = 0) to yield the base directory; v5 = v13 [global:0x005EA438, source:raw]
    // CALL: StringRegistry(v8) registers the base directory path with the string manager; v8 falls back to byte_5EA438 when v5 is null [callee:0x0053C800, global:0x005EA438, source:raw]
    // ASSIGNMENT: Initialize the file handle slot: v12 = 0 [source:raw]
    // CALL: sub_53CBC0(&v12, aPitanimsMas) opens the PITANIMS.MAS archive, writing the handle into v12 [callee:0x0053CBC0, global:0x005CD480, source:raw]
    // CALL: PitCrewAnimationLoader(this, a2, a3, a4) parses the animation data from the opened archive; result saved to v9 [callee:0x004A2A90, source:raw]
    // GUARD: If the archive handle v12 is non-zero, PhysicsObjectLinkedListRemoval(v12) closes it [callee:0x0053CE40, source:raw]
    // CALL: StringMatchWithFlagSet(v10) registers the path for string matching with flag tracking; v10 falls back to byte_5EA438 when v13 is null [callee:0x0053C900, global:0x005EA438, source:raw]
    // GUARD: If the temporary path buffer v13 is non-zero, FreeWrapper_7bcf(v13) frees it [callee:0x00587BCF, source:raw]
    // RETURN: Returns v9, the result of PitCrewAnimationLoader; invoked by sub_4A4900 [caller:0x004A4900, function:0x004A3220, source:raw]

    // Conservative worker pseudocode:
    //   ArrayResourceCleanup(this);
    //   v13 = 0; v14 = -1;
    //   StringCopyWithBufferRealloc(a2);
    //   v6 = strlen(byte_5EA438) + 1;
    //   if (v6 - 1 > 0) {
    //     i = &byte_5EA438[v6 - 2];
    //     while (i > byte_5EA438 && *i != 92) --i;
    //     *i = 0;
    //   }
    //   StringRegistry(v13 ? v13 : byte_5EA438);
    //   v12 = 0;
    //   sub_53CBC0(&v12, aPitanimsMas);
    //   v9 = PitCrewAnimationLoader(this, a2, a3, a4);
    //   if (v12) PhysicsObjectLinkedListRemoval(v12);
    //   StringMatchWithFlagSet(v13 ? v13 : byte_5EA438);
    //   if (v13) FreeWrapper_7bcf(v13);
    //   return v9;
    // UNRESOLVED: dword_8AFE64 is flagged as a read-only global by the packet but appears nowhere in the raw decompiled source
    // UNRESOLVED: v13 (the temporary path buffer) is assigned 0 and never written between the StringCopyWithBufferRealloc(a2) call and its use, so the copy's result buffer is not visible; the v5 = v13 assignment after the backslash loop always yields null
    // UNRESOLVED: The actual relationship between a2 and byte_5EA438 (both path sources) is not resolved
}
