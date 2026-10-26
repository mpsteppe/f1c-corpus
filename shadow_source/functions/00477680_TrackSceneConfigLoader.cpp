// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477680
// Canonical corpus name: TrackSceneConfigLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSceneConfigLoader_00477680.c

void UnknownObject::TrackSceneConfigLoader()
{
    // Loads the current track-scene configuration. Gates on a non-null result from LinkedListIndexedAccessor_f590 (a config list) and on its pointer table at byte offset 60, then reads configuration value 1 into a 512-byte stack buffer via sub_4B1520 and processes it with sub_4C4D50. Resolves the season scene by name through SeasonSceneMatchByIndex using the first pointer-table entry (fallback byte_5EA438). Writes the font handle dword_8AC38C from ListIndexedAccessor over dword_8AC36C, retrieves the current vehicle pointer table via CurrentVehicleAccessor at unk_8AC388, and copies the vehicle name (first table entry or byte_5EA438) plus the entry-name string at pointer-table index 47 through StringCopyWithBufferRealloc. Called by CopyProfileIconBMP and GameMode.
    // GUARD: Outer gate: the whole load runs only when LinkedListIndexedAccessor_f590 returns a non-null config element [callee:0x0048F590, source:raw]
    // GUARD: Inner gate: the load continues only when the pointer table v1 read at byte offset 60 of the config element is non-null [source:raw]
    // CALL: Configuration value fetch: sub_4B1520(1, v5, 512) reads config value 1 into the 512-byte stack buffer, then sub_4C4D50 processes that buffer value [callee:0x004B1520, callee:0x004C4D50, source:raw]
    // CALL: Season scene resolution: SeasonSceneMatchByIndex is invoked with the first pointer-table entry as the scene name, defaulting to byte_5EA438 when the entry is null [callee:0x004C4FF0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Font handle update: dword_8AC38C is written with the result of ListIndexedAccessor applied to the list root dword_8AC36C [callee:0x004C5130, global:0x008AC36C, global:0x008AC38C, source:raw]
    // CALL: Current vehicle table retrieval: CurrentVehicleAccessor(unk_8AC388) returns the current vehicle pointer table v3; the vehicle name is the first table entry, defaulting to byte_5EA438 when null [callee:0x004C4080, global:0x008AC388, global:0x005EA438, source:raw]
    // CALL: String copies: StringCopyWithBufferRealloc copies the vehicle name string, then a second call copies the entry-name string located at pointer-table index 47 of v3 [callee:0x00566650, source:raw]
    // RETURN: Returns the original config-element result when either guard fails, otherwise returns the result of the last StringCopyWithBufferRealloc call [source:raw]
    // CALL: Invoked by CopyProfileIconBMP (0046CD20) and GameMode (0046D6D0) as part of track-scene setup [caller:0x0046CD20, caller:0x0046D6D0, source:raw]

    // Conservative worker pseudocode:
    //   result = LinkedListIndexedAccessor_f590();
    //   if (result) {
    //     v1 = *(char***)(result + 60);
    //     if (v1) {
    //       sub_4B1520(1, v5, 512); sub_4C4D50(v5);
    //       scene = *v1 ? *v1 : byte_5EA438; SeasonSceneMatchByIndex(scene);
    //       dword_8AC38C = ListIndexedAccessor(&dword_8AC36C);
    //       v3 = CurrentVehicleAccessor(&unk_8AC388);
    //       name = *v3 ? *v3 : byte_5EA438;
    //       StringCopyWithBufferRealloc(name);
    //       return StringCopyWithBufferRealloc(v3 + 47);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Three read-only globals flagged by packet facts (byte_7CE498, dword_7CE64C, dword_7CE668) appear nowhere in the raw decompiled source; the skeleton fill labels them AutoLoadConfigFile, GameFilterDataPath and TrackNameStringPtr but none of that is verifiable from this packet
    // UNRESOLVED: The layout of the config element (pointer table at byte offset 60) and the pointer-table entry layout of the vehicle table are reached by raw offsets only and are not defined here
}
