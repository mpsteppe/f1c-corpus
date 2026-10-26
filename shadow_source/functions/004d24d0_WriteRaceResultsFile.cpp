// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D24D0
// Canonical corpus name: sub_4D24D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D24D0_004d24d0.c

void UnknownObject::WriteRaceResultsFile()
{
    // Writes a race-results text file to disk: allocates a results path, ensures every intermediate directory exists, derives the output filename (timestamped when multiplayer, fixed 'RaceResults.txt' for single-player session type 7), then, after opening the file, writes a metadata header, an optional multiplayer local-settings/drive-aids block, and one row per finishing driver (qualifying time, race place/laps, per-lap times, best lap, finish status, total fines). The path buffer is freed on exit.
    // ASSIGNMENT: Allocate a 256-byte path buffer via OperatorNewNhMallocWrapper, clear its first byte, and record capacity 256. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Seed the results path: copy the base directory string into the buffer with StringCopyWithBufferRealloc, choosing dword_5EC438 when non-null else byte_5EA438, then append the 'results' directory token with sub_5665B0(aResults). [global:0x005EC438, global:0x005EA438, callee:0x00566650, callee:0x005665B0, global:0x005D4188, source:raw]
    // LOOP: Walk the path string (bounded at 0x400 chars); at each '\' separator (0x5C) copy the substring prefix into PathName via sub_587DD0, null-terminate it, and create that intermediate directory with CreateDirectoryAWrapper. [callee:0x00587DD0, callee:0x00589671, source:raw]
    // CALL: Create the final results directory with CreateDirectoryAWrapper on the whole path. [callee:0x00589671, source:raw]
    // CALL: Read the current local time: sub_5896EE(v24) fills a raw time struct, then sub_589E6C(v24) converts it to a six-element array (sec/min/hour/day/month/year). [callee:0x005896EE, callee:0x00589E6C, source:raw]
    // ASSIGNMENT: Format the header timestamp '%d/%0.2d/%0.2d %0.2d:%0.2d:%0.2d' with StringFormatWithBufferOverflowCheck using year=arr[5]+1900, month=arr[4]+1, day=arr[3], hour=arr[2], min=arr[1], sec=arr[0]. [callee:0x0058815F, global:0x005D413C, source:raw]
    // GUARD: Branch on byte_7D0B28 (multiplayer flag): non-zero selects the timestamped filename path. [global:0x007D0B28, source:raw]
    // CALL: Multiplayer path: format the timestamped filename '%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d.txt' into v30 with StringFormatWithBufferOverflowCheck and append it to the path with sub_5665B0. [callee:0x0058815F, global:0x005D4164, callee:0x005665B0, source:raw]
    // GUARD: Non-multiplayer path: when dword_7C56A4 (session type) is not 7, jump to LABEL_46 and skip all file output, going straight to cleanup. [global:0x007C56A4, source:raw]
    // CALL: Non-multiplayer, session type 7: append the fixed 'RaceResults.txt' name token with sub_5665B0(aRaceresultsTxt). [callee:0x005665B0, global:0x005D412C, source:raw]
    // ASSIGNMENT: Zero-initialize the file-write context v20 with ZeroInitSmallStruct. [callee:0x005668B0, source:raw]
    // GUARD: Open the results file with sub_566940(path, 0, 1, 1); if it does not return 1 the write block is skipped. [callee:0x00566940, source:raw]
    // CALL: Write the header metadata labels via BufferWriteWithStringLengthCheck: aHeader, aGameS, aVersion3f, aTimestringS, &word_5C30B4, aRace, aRacemodeD, aSceneS, aAidbS, aQualifyLapsD, aRaceLapsD. [callee:0x00566C30, global:0x005D4120, global:0x005D4114, global:0x005D4104, global:0x005D40F4, global:0x005C30B4, global:0x005D40EC, global:0x005D40DC, global:0x005D40D0, global:0x005D40C4, global:0x005D40B0, global:0x005D40A0, source:raw]
    // CALCULATION: Compute an integer race-duration value: v19 = (flt_8ACF94 - flt_8ACF90) * 0.016666668, then v21 = (int)v19. [global:0x008ACF94, global:0x008ACF90, source:raw]
    // CALL: Write the remaining header labels via BufferWriteWithStringLengthCheck: aRaceTimeD, aRaceLength3f, aTrackLength4f, &word_5C30B4. [callee:0x00566C30, global:0x005D4090, global:0x005D407C, global:0x005D4068, global:0x005C30B4, source:raw]
    // GUARD: When byte_7D0B28 (multiplayer flag) is non-zero, additionally emit a local-settings / drive-aids block. [global:0x007D0B28, source:raw]
    // CALL: Write the local-settings and drive-aids labels via BufferWriteWithStringLengthCheck: aLocalSettings, aDriveaidsSteer, aDriveaidsSteer_0, aDriveaidsThrot, aDriveaidsBrake, aDriveaidsAntil, aDriveaidsSpinR, aDriveaidsInvul, aDriveaidsAutop, aDriveaidsOppos, aDriveaidsStabi, aDriveaidsNoAiC, aDriveaidsAllow, aDriveaidsAutoC, aDriveaidsAutoL, aDriveaidsAutoB, aDriveaidsShift, aDriveaidsAutoR, aDriveaidsSpeed, aDriveaidsHalfR, aDriveaidsExtra, aMechfailRateD, aGameoptDamagem, aFuelMultD, aTireMultD, aVehiclesAllowe, aMultiDataRateD, &word_5C30B4, aControls. [callee:0x00566C30, global:0x005D4054, global:0x005D4038, global:0x005D4014, global:0x005D3FF4, global:0x005D3FD8, global:0x005D3FB8, global:0x005D3F9C, global:0x005D3F80, global:0x005D3F68, global:0x005D3F4C, global:0x005D3F2C, global:0x005D3F10, global:0x005D3EEC, global:0x005D3ED0, global:0x005D3EB8, global:0x005D3EA0, global:0x005D3E84, global:0x005D3E68, global:0x005D3E44, global:0x005D3E2C, global:0x005D3E08, global:0x005D2CE0, global:0x005D3DE8, global:0x005D3DD8, global:0x005D3DC8, global:0x005D3DB0, global:0x005D3D9C, global:0x005C30B4, global:0x005D3D90, source:raw]
    // LOOP: Multiplayer block: walk the global entries from dword_7D1B08 up to (but not including) dword_7D1FD8, advancing 7 dwords per step, writing the aDDD_0 token for each entry; finish with &word_5C30B4. [global:0x005D3D84, global:0x007D1B08, global:0x007D1FD8, callee:0x00566C30, global:0x005C30B4, source:raw]
    // LOOP: Per-driver output loop: for each grid position i from 1 to dword_5C329C (vehicle count), scan the vehicle pointer array dword_7C54F0 and select the driver whose position field (record + 16480) equals i. [global:0x005C329C, global:0x007C54F0, source:raw]
    // CALL: Write the per-driver row labels via BufferWriteWithStringLengthCheck: aSlot03d, aDriverS, aVehicleS, aQualplaceD. [callee:0x00566C30, global:0x005D3D78, global:0x005D3D6C, global:0x005D3D60, global:0x005D3D50, source:raw]
    // GUARD: Qualifying time (float at record + 16476): when <= 0.0 write aQualtime; otherwise convert with FloatToIntConversionWithRemainder and write aQualtimeD063f. [global:0x005D3D28, global:0x005D3D3C, callee:0x005676C0, source:raw]
    // CALL: Write the race-place and race-laps labels via BufferWriteWithStringLengthCheck: aRaceplaceD, aRacelapsD. [callee:0x00566C30, global:0x005D3D18, global:0x005D3D08, source:raw]
    // LOOP: Multiplayer per-lap block: for each lap index j below the lap-count field (results record + 8), read the lap time with ArithmeticComparison_c2a0; when it is > 0.0, read per-lap data with sub_4BC270, convert via FloatToIntConversionWithRemainder, and write aLapD3fD063f. [global:0x007D0B28, callee:0x004BC2A0, callee:0x004BC270, callee:0x005676C0, global:0x005D3CEC, source:raw]
    // GUARD: Best race time (float at results record + 104): when <= 0.0 write aRacebesttime; otherwise convert with FloatToIntConversionWithRemainder and write aRacebestlapD06. [global:0x005D3CBC, global:0x005D3CD4, callee:0x005676C0, source:raw]
    // STATE_TRANSITION: Switch on the race-status enum (dword at results record + 48, jump table jpt_4D2CB0): cases 0 and 2 write aRacetimeDnf then aReasonD; case 1 converts the race time (float at results record + 132) via FloatToIntTruncateWithRemainder into v21 and writes aRacetimeD02d06; case 3 writes aRacetimeDq; default emits nothing. [global:0x004D2DBC, global:0x005D3C90, global:0x005D3C84, callee:0x00567700, global:0x005D3CA0, global:0x005D3C74, source:raw]
    // GUARD: Total fines (float at results record + 164): when > 0.0 write aTotalFines1f; then write the row terminator &word_5C30B4. [global:0x005D3C60, global:0x005C30B4, source:raw]
    // CALL: Close the results file context with ConditionalFileHandleCloseWithFlagDispatch(v20). [callee:0x00566B90, source:raw]
    // CALL: Clean up the file-write context v20 with SubCallWithConditionalFieldFree. [callee:0x005668D0, source:raw]
    // RETURN: LABEL_46: free the path buffer with FreeWrapper_7bcf when it was allocated, and return the path pointer. Invoked by Steward_Post (0x004D4600) as part of the post-race results system. [callee:0x00587BCF, caller:0x004D4600, source:raw]

    // Conservative worker pseudocode:
    //   LPCSTR WriteRaceResultsFile() {
    //     LPCSTR path = (LPCSTR)OperatorNewNhMallocWrapper(256);
    //     *path = 0;
    //     char* base = dword_5EC438 ? (char*)dword_5EC438 : (char*)byte_5EA438;
    //     StringCopyWithBufferRealloc(base);
    //     sub_5665B0(aResults);
    //     const char* v1 = path ? path : (char*)byte_5EA438;
    //     unsigned int v2 = 0;
    //     unsigned int v3 = strlen(v1) + 1;
    //     int v4 = v3 - 1;
    //     if (v4 > 0) do {
    //       if (v2 >= 0x400) break;
    //       if (PathName[v2 + v1 - PathName] == 92) { // '\\'
    //         sub_587DD0(PathName, v1, v2);
    //         PathName[v2] = 0;
    //         CreateDirectoryAWrapper(PathName);
    //         v4 = v3 - 1;
    //       }
    //       ++v2;
    //     } while ((int)v2 < v4);
    //     CreateDirectoryAWrapper(v1);
    //     sub_5896EE(v24);
    //     v5 = (_DWORD*)sub_589E6C(v24);
    //     // timestamp: v5[5]+1900, v5[4]+1, v5[3], v5[2], v5[1], v5[0]
    //     StringFormatWithBufferOverflowCheck(v27, "%d/%0.2d/%0.2d %0.2d:%0.2d:%0.2d", ...);
    //     if (byte_7D0B28) {
    //       StringFormatWithBufferOverflowCheck(v30, "%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d.txt", ...);
    //       sub_5665B0(v30);
    //     } else {
    //       if (dword_7C56A4 != 7) goto LABEL_46;
    //       sub_5665B0(aRaceresultsTxt);
    //     }
    //     ZeroInitSmallStruct(v20);
    //     if (sub_566940(v1, 0, 1, 1) == 1) {
    //       // header labels, then optional multiplayer drive-aids block,
    //       // then per-driver rows (qual time, race place/laps, lap times,
    //       // best lap, status switch, total fines)
    //       ConditionalFileHandleCloseWithFlagDispatch(v20);
    //     }
    //     SubCallWithConditionalFieldFree(v20);
    //   LABEL_46:
    //     if (path) return (LPCSTR)FreeWrapper_7bcf((LPVOID)path);
    //     return path;
    //   }
    // UNRESOLVED: The packet lists globals flt_59E440, flt_59E9C0, aF1Challenge990 and flt_5EA3FC, but none appears in the raw function text; their role in this function cannot be grounded and they may belong to another function or a stale xref merge.
    // UNRESOLVED: The packet lists many globals at 7CE5D0-7D0E98 addresses (dword_7CE5D0, dword_7CE608, dword_7CE6AC, dword_7CE6D0, dword_7CE6F4, dword_7CE718, dword_7CE73C, dword_7CE760, dword_7CE784, dword_7CE7A8, dword_7CE7CC, dword_7CE7F0, dword_7CE814, byte_7CE838, dword_7CE850, byte_7CE874, byte_7CE88C, dword_7CE8A4, dword_7CE910, flt_7CE934, dword_7CE958, byte_7CE994, dword_7CEA5C, dword_7D0014, dword_7D0410, dword_7D04A4, dword_7D05A0, flt_7D0798, dword_7D0B64, dword_7D0C60, dword_7D0D5C, dword_7D0D60, dword_7D0E98) with no reference in the raw function text; these likely derive from the skeleton prose layer rather than this function's instructions, so they are recorded as unresolved rather than attributed to operations.
    // UNRESOLVED: The exact meaning of the driver results record offsets (16436 base, +8 lap count, +48 status, +104 best time, +132 race time, +164 total fines, +16476 qual time, +16480 position) is DERIVED from use context only; no struct definition is available in the packet.
    // UNRESOLVED: Owner class is unknown: the function has no this pointer or vtable evidence; only the caller Steward_Post (0x004D4600) links it to the post-race system.
}
