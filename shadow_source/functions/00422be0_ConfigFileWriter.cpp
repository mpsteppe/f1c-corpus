// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00422BE0
// Canonical corpus name: sub_422BE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_422BE0_00422be0.c

void UnknownObject::ConfigFileWriter()
{
    // Writes the game configuration file. Resolves the target path (explicit lpFileName, else the stored default at this+0x0, else the global empty path byte_5EA438), clears the read-only attribute via ToggleFileReadOnlyAttributeViaWin32API with flag 128, opens the file in write-text mode through sub_587DB0(aWt), and if the open fails returns 0. On success streams formatted sections via StringFormatWithNestedIO: directory paths (components, season, sound, vehiclesound, options*, replay, movie, tracks, vehicles, drivers, log, save, music, cameraeditor), hardware/video settings (gridsize, cpurating, systemram, videoram, objdetail, texdetail, videoguid, videodriver, videomode, videorefresh, windowedmode, runbenchmarks, fsaa, vsync, vbstrategy), install settings (install, installfrom, installto, autolaunch), mode (via FieldAccessorAt0x20/ArrayIndexedPointerGetter on dword_5EA43C, sub_404D20 + CRTFtol), launchtime, and version strings. Closes the file and returns 1.
    // GUARD: Resolve target path: if lpFileName is null, fall back to the stored default *this, and if that is null use the global empty path byte_5EA438 [field:this:0x00000000, global:0x005EA438, source:raw]
    // CALL: Clear read-only attribute: ToggleFileReadOnlyAttributeViaWin32API(v2, 128) [callee:0x0058BA36, source:raw]
    // CALL: Open config file in write-text mode: v4 = sub_587DB0(v2, aWt); if the handle is null return 0 [callee:0x00587DB0, global:0x005C302C, source:raw]
    // CALL: Directory section: StringFormatWithNestedIO(v5, aComponents_0), then aSeasondirS, aSounddirS, aVehiclesoundS, aOptionsanimS, aOptionsflagsS, aOptionssoundsS, aOptionsdirS, aReplaydirS, aMoviedirS, aTracksdirS, aVehiclesdirS, aDriversdirS, aLogdirS, aSavedirS, aMusicdirS, aCameraeditorre_0 [callee:0x005887B1, global:0x005C301C, global:0x005C300C, global:0x005C2FFC, global:0x005C2FE8, global:0x005C2FD8, global:0x005C2FC4, global:0x005C2FB0, global:0x005C2FA0, global:0x005C2F90, global:0x005C2F80, global:0x005C2F70, global:0x005C2F60, global:0x005C2F50, global:0x005C2F44, global:0x005C2F38, global:0x005C2F28, global:0x005C2F0C, source:raw]
    // CALL: ShortComputation_3060(this) prepares a setting value before the next write group [callee:0x00423060, source:raw]
    // CALL: Hardware section: StringFormatWithNestedIO(v5, aGridsizeD), aCpuratingD, aSystemramD, aVideoramD, aObjdetailD, aTexdetailD [callee:0x005887B1, global:0x005C2EFC, global:0x005C2EEC, global:0x005C2EDC, global:0x005C2ECC, global:0x005C2EBC, global:0x005C2EAC, source:raw]
    // CALL: ShortComputation_3060(v5) is invoked a second time before the video group, with the file handle passed instead [callee:0x00423060, source:raw]
    // CALL: Video section: StringFormatWithNestedIO(v5, aVideoguidS), aVideodriverD, aVideomodeD, aVideorefreshD, aWindowedmodeD, aRunbenchmarksD, aFsaaD, aVsyncD, aVbstrategyD [callee:0x005887B1, global:0x005C2E9C, global:0x005C2E8C, global:0x005C2E7C, global:0x005C2E68, global:0x005C2E54, global:0x005C2E40, global:0x005C2E34, global:0x005C2E28, global:0x005C2E18, source:raw]
    // CALL: Install section: StringFormatWithNestedIO(v5, aInstall_0), aInstallfromS, aInstalltoS, aAutolaunch_0 [callee:0x005887B1, global:0x005C2E0C, global:0x005C2DFC, global:0x005C2DEC, global:0x005C2DDC, source:raw]
    // CALL: Mode value: v7 = FieldAccessorAt0x20(&dword_5EA43C) then ArrayIndexedPointerGetter(v7) [callee:0x00404D10, callee:0x00404D00, global:0x005EA43C, source:raw]
    // CALL: Mode line: v8 = sub_404D20(&dword_5EA43C), convert with CRTFtol(v8), then StringFormatWithNestedIO(v5, aModeS) [callee:0x00404D20, callee:0x00587BDC, callee:0x005887B1, global:0x005EA43C, global:0x005C2DD0, source:raw]
    // CALL: Launch-time line: StringFormatWithNestedIO(v5, aLaunchtimeD) [callee:0x005887B1, global:0x005C2DC0, source:raw]
    // CALL: Version lines: StringFormatWithNestedIO(v5, aVersion_1) then StringFormatWithNestedIO(v5, aVersionF) [callee:0x005887B1, global:0x005C2DB4, global:0x005C2DA8, source:raw]
    // CALL: Close the config file: FileCloseWithLock(v5) [callee:0x00587D02, source:raw]
    // RETURN: Return 1 after a successful write [function:0x00422BE0, source:raw]
    // CALL: Invoked by ConfigIniParser (00421CD0), SessionReset (0042D350) and VidMan_Enter (004FA000) to persist settings [caller:0x00421CD0, caller:0x0042D350, caller:0x004FA000, source:raw]

    // Conservative worker pseudocode:
    //   path = lpFileName;
    //   if (!path) { path = *this; if (!path) path = &byte_5EA438; }
    //   ToggleFileReadOnlyAttributeViaWin32API(path, 128);
    //   f = sub_587DB0(path, "wt");
    //   if (!f) return 0;
    //   fprintf(f, aComponents_0); fprintf(f, aSeasondirS); fprintf(f, aSounddirS);
    //   fprintf(f, aVehiclesoundS); fprintf(f, aOptionsanimS); fprintf(f, aOptionsflagsS);
    //   fprintf(f, aOptionssoundsS); fprintf(f, aOptionsdirS); fprintf(f, aReplaydirS);
    //   fprintf(f, aMoviedirS); fprintf(f, aTracksdirS); fprintf(f, aVehiclesdirS);
    //   fprintf(f, aDriversdirS); fprintf(f, aLogdirS); fprintf(f, aSavedirS);
    //   fprintf(f, aMusicdirS); fprintf(f, aCameraeditorre_0);
    //   ShortComputation_3060(this);
    //   fprintf(f, aGridsizeD); fprintf(f, aCpuratingD); fprintf(f, aSystemramD);
    //   fprintf(f, aVideoramD); fprintf(f, aObjdetailD); fprintf(f, aTexdetailD);
    //   ShortComputation_3060(f);
    //   fprintf(f, aVideoguidS); fprintf(f, aVideodriverD); fprintf(f, aVideomodeD);
    //   fprintf(f, aVideorefreshD); fprintf(f, aWindowedmodeD); fprintf(f, aRunbenchmarksD);
    //   fprintf(f, aFsaaD); fprintf(f, aVsyncD); fprintf(f, aVbstrategyD);
    //   fprintf(f, aInstall_0); fprintf(f, aInstallfromS); fprintf(f, aInstalltoS);
    //   fprintf(f, aAutolaunch_0);
    //   ArrayIndexedPointerGetter(FieldAccessorAt0x20(&dword_5EA43C));
    //   CRTFtol(sub_404D20(&dword_5EA43C)); fprintf(f, aModeS);
    //   fprintf(f, aLaunchtimeD); fprintf(f, aVersion_1); fprintf(f, aVersionF);
    //   FileCloseWithLock(f);
    //   return 1;
    // UNRESOLVED: The exact format strings at the referenced globals are not embedded in the decompiled source, so the resulting file layout is inferred from the global naming alone
    // UNRESOLVED: ShortComputation_3060 is called with the this pointer first and with the file handle second; its role in either call site is not evident here
    // UNRESOLVED: FieldAccessorAt0x20 / ArrayIndexedPointerGetter / sub_404D20 / CRTFtol together compute the game-mode line but their exact contract is elsewhere
}
