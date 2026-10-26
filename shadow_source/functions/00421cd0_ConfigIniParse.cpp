// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421CD0
// Canonical corpus name: ConfigIniParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigIniParser_00421cd0.c

void UnknownObject::ConfigIniParse()
{
    // Parses the game's main config.ini file. On Windows XP/NT/2000 non-admin installs it first relocates the config into the per-user special folder (CSIDL 5), creating the directory chain and copying the shipped config via CopyFileA. It then opens the config text file (falling back to an alternate source when the first open fails), reads it line by line and dispatches four sections: [Components] (directory-path registrations plus video/settings fields this+0xB8..0xE4), [Install] (install-from/to path registration), [Autolaunch] (mode, launch time, VCR cycle/file, IP address routed into the dword_5EA43C runtime struct), and [Version] (version float at this+0xE8). Returns 1 on success, 0 on failure, and re-applies file attributes via sub_422BE0(0) when the non-admin flag was set.
    // STATE_TRANSITION: Initialize: memset the v42[384] line buffer to 0, zero v37/v39/v40/v41, set v38 = 1 and v32 = 0, then fetch the default path into pszPath via sub_4230C0. (Legacy ABI lead: Config_ini_Parser_Initial_Setup.) [abi:lead, callee:0x004230C0, source:raw]
    // GUARD: OS check: when pszPath equals aWindowsXp, aWindowsNt or aWindows2000 AND WindowsAdminCheck(this) returns false, enter the non-admin directory-setup branch. [global:0x005C2D9C, global:0x005C2D90, global:0x005C2D80, callee:0x00423250, source:raw]
    // STATE_TRANSITION: Set v32 = 1 (non-admin setup flag); when SHGetSpecialFolderPathA(0, pszPath, 5, 1) succeeds, pszPath becomes the per-user special-folder path. [global:0x0059E254, source:raw]
    // CALL: Build the target config path: StringFormatWithBufferOverflowCheck(NewFileName, '%s\\%s', pszPath, aF1Challenge990_0). [callee:0x0058815F, global:0x005C2D6C, source:raw]
    // GUARD: When FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1 the target config does not exist yet, so create the directory chain and install the shipped config; otherwise only reformat the path. [callee:0x0058BA75, source:raw]
    // LOOP: Walk NewFileName character by character (cap 0x400); at each backslash (character 92) truncate the path there via sub_587DD0, null-terminate it, and CreateDirectoryAWrapper the intermediate directory. Finally CreateDirectoryAWrapper(NewFileName) creates the leaf directory. [callee:0x00587DD0, callee:0x00589671, source:raw]
    // CALL: Reallocate NewFileName via StringCopyWithBufferRealloc, reformat it as pszPath + aF1Challenge990_0 + ExistingFileName, then CopyFileA(ExistingFileName, NewFileName, 1) to install the shipped config into the non-admin location. [callee:0x00566650, callee:0x0058815F, global:0x005C2AA0, global:0x0059E19C, source:raw]
    // CALL: Else branch (config already present): reallocate NewFileName and reformat it as pszPath + aF1Challenge990_0 + ExistingFileName without copying. [callee:0x00566650, callee:0x0058815F, global:0x005C2AA0, source:raw]
    // ASSIGNMENT: Choose the config source string: v5 = a2; when a2 is null v5 = *this (field this+0x0); when both are null v5 = &byte_5EA438 (empty-string fallback). [field:this:0x00000000, global:0x005EA438, source:raw]
    // CALL: Open the config file for reading: v6 = sub_587DB0(v5, aRt) passing the 'rt' mode string aRt; record v33 = v6. [callee:0x00587DB0, global:0x005BE690, source:raw]
    // GUARD: If the first open failed (v6 == 0), attempt an alternate source with sub_422BE0(v5); when that also fails, call StringSplitLoop(1, aDDevF119992002_10, 386), log via DebugLogWrite(&dword_8AD25C, aCouldNotCreate_0) and return 0. [callee:0x00422BE0, callee:0x004D7A50, callee:0x004D7AA0, global:0x005C2D34, global:0x005C2D10, global:0x008AD25C, source:raw]
    // CALL: Retry the open: v6 = sub_587DB0(v5, aRt), v33 = v6; when it still fails, call StringSplitLoop(1, aDDevF119992002_10, 396), DebugLogWrite(&dword_8AD25C, aSuccessfullyCr) and return 0. [callee:0x00587DB0, global:0x005BE690, callee:0x004D7A50, callee:0x004D7AA0, global:0x005C2D34, global:0x005C2CD4, global:0x008AD25C, source:raw]
    // LOOP: Main parse loop: FileReadUntilNewline(v42, 256, v6) reads each line; sub_5651B0(v36) tokenizes it and the line is dispatched against the section headers via sub_587C20. [callee:0x00587CA0, callee:0x005651B0, callee:0x00587C20, source:raw]
    // GUARD: When a line starts a [Components] section (sub_587C20(v42, aComponents) true), read further lines until EOF or a closing marker (token value 1 from sub_5651B0). [callee:0x00587C20, global:0x005C2CC4, callee:0x005651B0, callee:0x00587CA0, source:raw]
    // CALL: Dispatch the directory-path tokens inside [Components] via sub_5654A0: aSeasondir->NameRegistrationDelegation, aSounddir->StringCopyRealloc, aVehiclesound->DoubleDelegateCall, aOptionsanim->ChainedCall, aOptionsflags->StringWritePathRegister, aOptionssounds->DualFunctionCallChain, aOptionsdir->ShortComputation_1990, aMoviedir->sub_4219D0, aTracksdir->DualFunctionDispatch, aVehiclesdir->DualRegistrationCall, aDriversdir->DualDispatchProcessPathRegister, aMusicdir->ShortComputation_1a90; each receives pszPath. [callee:0x005654A0, global:0x005C2CB8, global:0x005C2CAC, global:0x005C2C9C, global:0x005C2C90, global:0x005C2C80, global:0x005C2C70, global:0x005C2C64, global:0x005C2C58, global:0x005C2C4C, global:0x005C2C40, global:0x005C2C34, global:0x005C2C28, callee:0x004218D0, callee:0x004218F0, callee:0x00421910, callee:0x00421930, callee:0x00421950, callee:0x00421970, callee:0x00421990, callee:0x004219D0, callee:0x004219F0, callee:0x00421A10, callee:0x00421A30, callee:0x00421A90, source:raw]
    // GUARD: For the aReplaydir token, when the non-admin flag v32 is set, build NewFileName from the base-path prefix this[42] (field 0xA8) plus the replay path this[16] (field 0x40), each with a &byte_5EA438 fallback, via StringFormatWithBufferOverflowCheck. [callee:0x005654A0, global:0x005C2C1C, field:this:0x000000A8, field:this:0x00000040, global:0x005EA438, callee:0x0058815F, source:raw]
    // CALL: Replay dir: when FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1, walk the path creating each directory (sub_587DD0 + CreateDirectoryAWrapper), create the leaf directory, enumerate existing files via FileEnumerationByExtension(this[16], NewFileName), copy NewFileName into pszPath, restore v6 = v33, then run ShortComputation_19b0(pszPath). [callee:0x0058BA75, callee:0x00587DD0, callee:0x00589671, callee:0x00421B10, field:this:0x00000040, callee:0x0058815F, callee:0x004219B0, source:raw]
    // GUARD: For the aLogdir token, when v32 is set, build NewFileName from this[42] (field 0xA8) plus the log path this[26] (field 0x68), each with a &byte_5EA438 fallback, via StringFormatWithBufferOverflowCheck. [callee:0x005654A0, global:0x005C2C10, field:this:0x000000A8, field:this:0x00000068, global:0x005EA438, callee:0x0058815F, source:raw]
    // CALL: Log dir: when FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1, create the directory chain, enumerate files via FileEnumerationByExtension(this[26], NewFileName), copy NewFileName into pszPath, restore v6 = v33, then run DualCallWrapper(pszPath). [callee:0x0058BA75, callee:0x00587DD0, callee:0x00589671, callee:0x00421B10, field:this:0x00000068, callee:0x0058815F, callee:0x00421A50, source:raw]
    // GUARD: For the aSavedir token, when v32 is set, build NewFileName from this[42] (field 0xA8) plus the save path this[28] (field 0x70), each with a &byte_5EA438 fallback, via StringFormatWithBufferOverflowCheck. [callee:0x005654A0, global:0x005C2C08, field:this:0x000000A8, field:this:0x00000070, global:0x005EA438, callee:0x0058815F, source:raw]
    // CALL: Save dir: when FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1, create the directory chain, enumerate files via FileEnumerationByExtension(this[28], NewFileName), copy NewFileName into pszPath, restore v6 = v33, then run sub_421A70(pszPath). [callee:0x0058BA75, callee:0x00587DD0, callee:0x00589671, callee:0x00421B10, field:this:0x00000070, callee:0x0058815F, callee:0x00421A70, source:raw]
    // CALL: For the aCameraeditorre token, call DualDelegationWrapper(pszPath). [callee:0x005654A0, global:0x005C2BF0, callee:0x00421AF0, source:raw]
    // CALL: Parse the numeric settings tokens with sub_565760(token, &v31, 0, 0, 0): aGridsize->this[49] (field 0xC4, clamped to 0..104), aCpurating->this[50] (0xC8), aSystemram->this[51] (0xCC), aVideoram->this[52] (0xD0), aObjdetail->this[54] (0xD8), aTexdetail->this[55] (0xDC), aVideodriver->this[46] (0xB8), aVideomode->this[47] (0xBC), aVideorefresh->this[48] (0xC0), aFsaa->this[56] (0xE0), aVbstrategy->this[57] (0xE4); each stores the parsed v31 value into the corresponding field. [callee:0x00565760, global:0x005C2BE4, global:0x005C2BD8, global:0x005C2BCC, global:0x005C2BC0, global:0x005C2BB4, global:0x005C2BA8, global:0x005C2B90, global:0x005C2B84, global:0x005C2B74, global:0x005C2B4C, global:0x005C2B38, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, field:this:0x000000D0, field:this:0x000000D8, field:this:0x000000DC, field:this:0x000000B8, field:this:0x000000BC, field:this:0x000000C0, field:this:0x000000E0, field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Store the boolean byte flags parsed via sub_565760: aWindowedmode->byte this+212 (field 0xD4) = v31, aRunbenchmarks->byte this+213 (field 0xD5) = v31 != 0, aVsync->byte this+214 (field 0xD6) = v31 != 0. [callee:0x00565760, global:0x005C2B64, global:0x005C2B54, global:0x005C2B44, field:this:0x000000D4, field:this:0x000000D5, field:this:0x000000D6, source:raw]
    // CALL: For the aVideoguid token, read the value via sub_565520(aVideoguid, pszPath, 0) and store the string with StringCopyWithBufferRealloc(pszPath). [callee:0x00565520, global:0x005C2B9C, callee:0x00566650, source:raw]
    // GUARD: When a line starts an [Install] section (sub_587C20(v42, aInstall) true), read lines until EOF or a closing marker and dispatch: aInstallfrom->FunctionCallWrapper_1ab0(pszPath), aInstallto->PathRegistrationWrapper(pszPath). [callee:0x00587C20, global:0x005C2B2C, callee:0x005651B0, callee:0x00587CA0, callee:0x005654A0, global:0x005C2B20, global:0x005C2B14, callee:0x00421AB0, callee:0x00421AD0, source:raw]
    // GUARD: When a line starts an [Autolaunch] section (sub_587C20(v42, aAutolaunch) true), read lines until EOF or a closing marker and dispatch into the dword_5EA43C runtime struct: aMode->QuickRace(pszPath) then StructFieldSetter(&dword_5EA43C, v28); aLaunchtime->ShortComputation_4d30(&dword_5EA43C, (float)v31); aVcrcycle->ResourceListCleanup(&dword_5EA43C, v31 != 0); aVcrfile->LinkedListNodeInsertion(&dword_5EA43C, pszPath); aIpaddress->SingleFunctionCallWrapper_4ef0(pszPath). [callee:0x00587C20, global:0x005C2B04, callee:0x005651B0, callee:0x00587CA0, callee:0x005654A0, callee:0x00565760, global:0x005C2AFC, global:0x005C2AF0, global:0x005C2AE4, global:0x005C2ADC, global:0x005C2AD0, global:0x005EA43C, callee:0x00404CC0, callee:0x00404D40, callee:0x00404D30, callee:0x00404D50, callee:0x00404E60, callee:0x00404EF0, source:raw]
    // CALL: When a line starts a [Version] section (sub_587C20(v42, aVersion) true) and the next line reads successfully, tokenize it and for the aVersion_0 token (via sub_565520(aVersion_0, pszPath, 0)) store the version float: *((float*)this + 58) (field 0xE8) = sub_58850F(pszPath). [callee:0x00587C20, global:0x005C2AC4, callee:0x00587CA0, callee:0x005651B0, callee:0x00565520, global:0x005C2ABC, callee:0x0058850F, field:this:0x000000E8, source:raw]
    // RETURN: Close the config file with FileCloseWithLock(v6); when the non-admin flag v32 is set call sub_422BE0(0) to re-apply file attributes; return 1 (success). [callee:0x00587D02, callee:0x00422BE0, source:raw]

    // Conservative worker pseudocode:
    //   init locals; memset(line_buf, 0, sizeof(line_buf)); sub_4230C0(pszPath);
    //   if (isWinXP_NT_2000(pszPath) && !WindowsAdminCheck(this)) {
    //     v32 = 1;
    //     if (SHGetSpecialFolderPathA(0, pszPath, 5, 1) >= 0) {
    //       fmt(NewFileName, "%s\\%s", pszPath, aF1Challenge990_0);
    //       if (file_attrs(NewFileName) == -1) {
    //         for each char of NewFileName: at '\\' create_intermediate_dir();
    //         create_dir(NewFileName);
    //         copy_shipped_config_to(NewFileName); /* CopyFileA * /
    //       } else fmt(NewFileName, "%s\\%s%s", pszPath, aF1Challenge990_0, ExistingFileName);
    //     }
    //   }
    //   v5 = a2 ? a2 : (this->path ? this->path : &byte_5EA438);
    //   v6 = v33 = open_read(v5, "rt");
    //   if (!v6) { if (!sub_422BE0(v5)) { log_failure(); return 0; }
    //             v6 = v33 = open_read(v5, "rt"); if (!v6) { log_retry(); return 0; } }
    //   while (read_line(v42, 256, v6)) {
    //     if (section_is(v42, "[Components]")) {
    //       while (read_line(v42, 256, v6)) {
    //         token = tokenize(v36);
    //         if (token == 1) break;
    //         dispatch_dir_paths(token, pszPath);   /* seasondir..musicdir stubs * /
    //         if (replaydir && v32) { build_replay_path(); ensure_dirs(); enumerate_replays(); }
    //         if (logdir && v32)     { build_log_path(); ensure_dirs(); enumerate_logs(); }
    //         if (savedir && v32)    { build_save_path(); ensure_dirs(); enumerate_saves(); }
    //         if (cameraeditorre)    DualDelegationWrapper(pszPath);
    //         parse_video_settings(token);         /* gridsize..vbstrategy, windowed/bench/vsync * /
    //         if (videoguid)         store_videoguid(pszPath);
    //       }
    //     } else if (section_is(v42, "[Install]")) {
    //       while (read_line(v42, 256, v6)) { tokenize; if (token==1) break;
    //         installfrom ? FunctionCallWrapper_1ab0 : PathRegistrationWrapper; }
    //     } else if (section_is(v42, "[Autolaunch]")) {
    //       while (read_line(v42, 256, v6)) { tokenize; if (token==1) break;
    //         mode ? set_mode_into(dword_5EA43C) : parse_autolaunch_tokens(dword_5EA43C); }
    //     } else if (section_is(v42, "[Version]") && read_line(v42, 256, v6)) {
    //       do { tokenize; if (token==1) break;
    //            if (version_token) this->version_float = parse_float(pszPath);
    //       } while (read_line(v42, 256, v6));
    //     }
    //   }
    //   FileCloseWithLock(v6);
    //   if (v32) sub_422BE0(0);
    //   return 1;
    // UNRESOLVED: Globals aSS (0x005BE860), aS_4 (0x005C2C18), aSSS_1 (0x005C2D5C), aSS_3 (0x005C2D64) and dword_5EC3D0 (0x005EC3D0) are listed in the packet but absent from the raw decompiled source; they are presumed referenced through helper/inlined paths not visible in this body.
    // UNRESOLVED: The literal contents of the token-name strings (aSeasondir, aSounddir, ...) and the format strings (aRt, aDDevF119992002_10, ...) are not present in the packet; they are referenced by address only.
    // UNRESOLVED: The directory-path dispatch stubs (NameRegistrationDelegation, StringCopyRealloc, etc.) and the section comparison sub_587C20 have their internal semantics only as their packet names imply; the exact registration behavior is not modeled here.
    // UNRESOLVED: __alloca_probe (0x005881C0) is a compiler stack-probe helper for the large stack frame, not a semantic call.
}
