// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A00A0
// Canonical corpus name: sub_4A00A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A00A0_004a00a0.c

void UnknownObject::sub_4A00A0()
{
    // Post-loading session/scene initialization orchestrator. Hides the cursor, conditionally loads an FIA short BIK video when championship mode (dword_7D0410 == 4), session type 7 and timer flag dword_7D032C == 1 all hold, then chains subsystem setup: guarded module-manager dispatch, global/session-type resets, camera viewport configuration, current-vehicle binding from the active-vehicle pointer array, game-state/audio dispatch, and — gated on ScoringGateCheck — scene file load, camera and collision handling, and telemetry dump. Returns the BIK file-load result.
    // LOOP: Hide the cursor: loop ShowCursor(0) until its return value goes negative. Invoked from sub_485B90's session-setup path. [global:0x0059E2C4, caller:0x00485B90, function:0x004A00A0, source:raw]
    // GUARD: Championship-intro gate: when dword_7D0410 == 4, dword_7C56A4 == 7 and dword_7D032C == 1, load the FIA short BIK video; otherwise skip the BIK load. [global:0x007D0410, global:0x007C56A4, global:0x007D032C, source:raw]
    // CALCULATION: Compose the BIK path: use dword_5EC418 as the path base when non-null, else byte_5EA438, formatted as '%s%s' (aSS) with the aFiashortBik suffix via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005EC418, global:0x005EA438, global:0x005C6BB0, global:0x005BE860, source:raw]
    // CALL: Load the composed BIK file with a retry loop (FileLoadWithRetryLoop) and store the file-load result into v0. [callee:0x004F9B70, source:raw]
    // CALL: Dispatch a guarded subsystem call according to the current module-manager state (dword_7CD25C). [callee:0x00463E00, global:0x007CD25C, source:raw]
    // CALL: Reset global state and session-type flag: GlobalStateSetter(0) and sub_42D210(&dword_7C569C, 0). [callee:0x004A0D30, callee:0x0042D210, global:0x007C569C, source:raw]
    // CALL: Reset the global float (GlobalFloatSetter(0)) and batch-configure the camera viewport from the module pointer array ppvOut. [callee:0x004F9F70, callee:0x00453560, global:0x007CA590, source:raw]
    // CALL: Run a short computation on the session manager object dword_5EA510. [callee:0x0040D410, global:0x005EA510, source:raw]
    // ASSIGNMENT: Bind the current vehicle: dword_7C54DC = dword_7C54E4 (index) and dword_7C54E0 = dword_7C54F0[dword_7C54E4] (pointer from the active-vehicle array). [global:0x007C54DC, global:0x007C54E0, global:0x007C54E4, global:0x007C54F0, source:raw]
    // CALL: Dispatch the game-state branch and conditional audio on the session manager object dword_5EA510. [callee:0x0040D100, callee:0x0040D090, global:0x005EA510, source:raw]
    // CALL: Zero-guarded division computation on flt_5EA4E8, followed by a guarded subsystem release. [callee:0x00408450, callee:0x00495060, global:0x005EA4E8, source:raw]
    // CALL: Run remaining short computations: ShortComputation_50c0(), ShortComputation_bdf0(&dword_7CD204) and sub_4B9FD0(&dword_8AB6E4). [callee:0x004950C0, callee:0x0045BDF0, callee:0x004B9FD0, global:0x007CD204, global:0x008AB6E4, source:raw]
    // GUARD: Scoring gate: proceed into scene/camera/collision setup only when ScoringGateCheck() returns non-zero. [callee:0x0042BC10, source:raw]
    // CALL: Load a file while preserving the identity flag (FileLoadWithFlagPreserve(&dword_7C73E8)) and issue an initial scene render update (SceneRenderUpdate(0)). [callee:0x00434000, callee:0x004C6D90, global:0x007C73E8, source:raw]
    // CALCULATION: Read the player vehicle pointer dword_7C54E8 and its sub-object pointer at +13024. [global:0x007C54E8, source:raw]
    // CALL: When the sub-object is non-null and the byte flag at vehicle +13388 is set, run UtilityFunction_4000 on the sub-object and then Camera(sub-object). [callee:0x004A4000, callee:0x004A3B50, global:0x007C54E8, source:raw]
    // CALL: When session type dword_7C56A4 != 7, or race phase dword_7C56A8 is not 2/3/4, run VehicleClimbAdjust(0) and CollisionWrapperWithLock(vehicle + 12). [callee:0x004EFA40, callee:0x004E4910, global:0x007C56A4, global:0x007C56A8, global:0x007C54E8, source:raw]
    // CALL: Dump telemetry data via TelemetryDataDump(&dword_8AD238). [callee:0x004D4A80, global:0x008AD238, source:raw]
    // RETURN: Return v0, the FIA BIK file-load result (0 when the BIK was not loaded). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A00A0(void) {
    //     int v0 = 0;
    //     while (ShowCursor(0) >= 0);
    //     if (dword_7D0410 == 4 && dword_7C56A4 == 7 && dword_7D032C == 1) {
    //       const char *base = dword_5EC418 ? (const char *)dword_5EC418 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(path, "%s%s", base, aFiashortBik);
    //       v0 = FileLoadWithRetryLoop(path, 1);
    //     }
    //     GuardedFunctionCallByState(dword_7CD25C);
    //     GlobalStateSetter(0); sub_42D210(&dword_7C569C, 0); GlobalFloatSetter(0);
    //     CameraViewportConfigBatch(&ppvOut); ShortComputation_d410((int)&dword_5EA510);
    //     v2 = dword_7C54F0[dword_7C54E4]; dword_7C54DC = dword_7C54E4; dword_7C54E0 = v2;
    //     GameStateBranchDispatch(&dword_5EA510); VirtualDispatchConditionalAudio(&dword_5EA510);
    //     SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.0); GuardedSubsystemRelease();
    //     ShortComputation_50c0(); ShortComputation_bdf0(&dword_7CD204); sub_4B9FD0(&dword_8AB6E4);
    //     if (ScoringGateCheck()) {
    //       FileLoadWithFlagPreserve((char **)&dword_7C73E8); SceneRenderUpdate(0);
    //       v3 = dword_7C54E8; v4 = *(DWORD *)(dword_7C54E8 + 13024);
    //       if (v4) { if (*(BYTE *)(dword_7C54E8 + 13388)) UtilityFunction_4000(*(DWORD *)(dword_7C54E8 + 13024)); Camera(v4); v3 = dword_7C54E8; }
    //       if (dword_7C56A4 != 7 || (dword_7C56A8 != 2 && dword_7C56A8 != 3 && dword_7C56A8 != 4)) {
    //         VehicleClimbAdjust(0); v3 = dword_7C54E8;
    //       }
    //       CollisionWrapperWithLock(v3 + 12);
    //     }
    //     TelemetryDataDump(&dword_8AD238);
    //     return v0;
    //   }
    // UNRESOLVED: Four packet globals do not appear in the recovered raw body and are unaccounted: unk_5EC6D0, unk_7CDE00, unk_7CE24D, unk_8AFE18.
    // UNRESOLVED: ABI lead name 'FIA_Short_Bink_Video' (LEGACY) is kept only as a lead; the owner object stays UNKNOWN.
    // UNRESOLVED: Literal vehicle-struct offsets 13024 and 13388 are used only as source-text literals; the vehicle struct layout is not established here.
}
