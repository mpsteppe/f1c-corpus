// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3200
// Canonical corpus name: VehFileParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehFileParser_004c3200.c

void UnknownObject::VehFileParser()
{
    // Parses a vehicle .R definition file: resolves the base directory (falling back to byte_5EA438 when this+0 is null), opens the file via sub_587DB0 with the aR extension, then loops per line extracting eyepoint/camera/mirror vectors, team and driver metadata strings, and track livery records (prepending livery nodes onto the list head at this+0x3D4). After the loop it closes the file, loads the companion .ini, auto-generates a description when this+0xFC is empty, and resolves HDV/INI/GEN/SFX companion paths via FileFinder. Returns 0 on success, -1 when the file cannot be opened.
    // ASSIGNMENT: Initialize locals: memset v36 to 0, set v31/v35/v33/v34 to 0, v32 to 1, v23/v24 to 0, and the first byte of buffers v26/v27/v28/v29 to 0. [source:raw]
    // ASSIGNMENT: Resolve the base directory: v2 = *(char**)this, and when *(this) == 0 (guard: base pointer null) fall back to byte_5EA438. [field:this:0x00000000, guard:0, global:0x005EA438, source:raw]
    // CALL: Call sub_587DB0(v2, aR) to open the vehicle .R definition file; store the returned handle into v4/v5/v25. [callee:0x00587DB0, global:0x005C36F0, source:raw]
    // GUARD: When the file handle is 0 (open failed), take the failure path that logs and returns -1. [source:raw]
    // CALL: Call FileReadUntilNewline(v36, 384, v4) to read the first line into v36; if it returns true, enter the per-line parse loop. [callee:0x00587CA0, source:raw]
    // LOOP: Per line: call sub_5651B0(v30) to reset the token scratch buffer, then sub_5654A0 with the section headers aHdvehicle/aHeadphysics/aSounds/aGraphics/aGenstring to extract the HDV, head-physics, sounds, graphics and genstring file tokens into v28, v26, v27, v29 and this + 40 respectively. [callee:0x005651B0, callee:0x005654A0, global:0x005D3038, global:0x005D302C, global:0x005D3024, global:0x005D3018, global:0x005D300C, source:raw]
    // CALL: Call sub_565870(aEyepoint, this + 56, this + 60, this + 64, 0, 0, 0, 0, 0) to parse the eyepoint X/Y/Z into this+0x38/0x3C/0x40; on success apply the defaults below. [callee:0x00565870, global:0x005D3000, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // ASSIGNMENT: On the first eyepoint parse (v24 == 0): copy the eyepoint values into the camera target — this+0x44 = this+0x38, this+0x48 = this+0x40, this+0x4C = this+0x3C. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: On the first mirror-position parse (v23 == 0): set this+0x50 = eyepoint X (this+0x38), this+0x54 = eyepoint Y minus 0.079999998, this+0x58 = eyepoint Z. [field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, global:0x005ACB28, source:raw]
    // CALL: Call sub_565870(aCameratarget, this + 68, this + 72, this + 76, 0, 0, 0, 0, 0) to parse the camera target into this+0x44/0x48/0x4C; on success set v24 = 1. [callee:0x00565870, global:0x005D2FF0, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: Call sub_565870(aMirrorpos, this + 80, this + 84, this + 88, 0, 0, 0, 0, 0) to parse the mirror position into this+0x50/0x54/0x58; on success set v23 = 1. [callee:0x00565870, global:0x005D2FE4, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, source:raw]
    // CALL: Call sub_565870(aMirrornorm, this + 92, this + 96, this + 100, 0, 0, 0, 0, 0) to parse the mirror normal; the destination offsets have no field records in the packet. [callee:0x00565870, global:0x005D2FD8, source:raw]
    // CALL: Call sub_565870(aSteeringwheela, this + 104, this + 108, this + 112, 0, 0, 0, 0, 0) to parse the steering wheel position. [callee:0x00565870, global:0x005D2FC4, source:raw]
    // CALL: Call sub_5654A0(aNumber, this + 116), sub_5654A0(aTeam_0, this + 124) and sub_5654A0(aDriver_0, this + 188) to extract the car number, team name and driver name strings. [callee:0x005654A0, global:0x005D2FBC, global:0x005D2FB4, global:0x005BEA08, source:raw]
    // CALL: Call sub_5654A0(aDescription, this + 252) to extract the description string into this+0xFC. [callee:0x005654A0, global:0x005D2FA8, field:this:0x000000FC, source:raw]
    // CALL: Call sub_5654A0(aEngine, this + 316), sub_5654A0(aManufacturer, this + 380) and sub_5654A0(aClasses, this + 444) to extract engine, manufacturer and class strings. [callee:0x005654A0, global:0x005C316C, global:0x005D2F98, global:0x005C401C, source:raw]
    // CALL: Call sub_5654A0 for the team metadata fields aFullteamname/aTeamfounded/aTeamheadquarte/aTeamstarts/aTeampoles/aTeamwins/aTeamworldchamp into this + 700/828/844/908/924/940/956. [callee:0x005654A0, global:0x005D2F88, global:0x005D2F7C, global:0x005D2F68, global:0x005D2F5C, global:0x005D2F50, global:0x005D2F44, global:0x005D2F2C, source:raw]
    // CALL: Call sub_5654A0(aDefaultlivery, v38) and sub_5654A0(aPitcrewlivery, v38); on each success call StringCopyWithBufferRealloc(v38) to store the livery string. [callee:0x005654A0, global:0x005D2F1C, global:0x005D2F0C, callee:0x00566650, source:raw]
    // CALL: Call sub_5654A0(aTracklivery, v38) to extract the track livery spec, then call sub_587C20(v38, asc_5D251C) to split the spec at the asc_5D251C delimiter. [callee:0x005654A0, global:0x005D2F00, callee:0x00587C20, global:0x005D251C, source:raw]
    // ASSIGNMENT: When the split succeeds: call OperatorNewNhMallocWrapper(20) to allocate a 20-byte livery node; on success initialize node[0] = 0, node[1] = -1, node[2] = 0, node[3] = -1. [callee:0x00587C03, source:raw]
    // CALCULATION: Trim leading spaces from the first livery string and trailing spaces/commas from its end; store the trimmed string via StringCopyWithBufferRealloc, then trim and store the second string that follows the delimiter via a second StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Prepend the new livery node onto the list: node[4] = *(_DWORD*)(this + 0x3D4) (previous head), then *(_DWORD*)(this + 0x3D4) = node (new head). [field:this:0x000003D4, source:raw]
    // CALL: On the no-split path: if StringSplitLoop(1, aDDevF119992002_8, 173) returns true, call DebugLogWrite(&dword_8AD25C, aFormatIsTrackl) to log the track-livery format error. [callee:0x004D7A50, global:0x005D3044, callee:0x004D7AA0, global:0x008AD25C, global:0x005D2EC0, source:raw]
    // LOOP: Repeat the per-line parse while FileReadUntilNewline(v36, 384, v25) returns true. [callee:0x00587CA0, source:raw]
    // CALL: Call FileCloseWithLock(v5) to close the .R file after the read loop. [callee:0x00587D02, source:raw]
    // CALL: Call FileINILoader(this) to load the vehicle's companion .ini data into this. [callee:0x004C38D0, source:raw]
    // ASSIGNMENT: When the description at this+0xFC is empty (this[252] == 0), call StringFormatWithBufferOverflowCheck(this + 252, format, this + 116, this + 124) to auto-generate the description from the number and team strings. [field:this:0x000000FC, callee:0x0058815F, global:0x005D2EB4, source:raw]
    // ASSIGNMENT: Resolve the directory prefix: v20 = *(this) with fallback to byte_5EA438 when null, strcpy it into v37, then scan v37 backward to the last backslash to truncate the file name. [field:this:0x00000000, guard:0, global:0x005EA438, source:raw]
    // CALL: Resolve companion paths: FileFinder(v28, aHdv, v37, this + 8), FileFinder(v26, aIni, v37, this + 16), FileFinder(v29, aGen, v37, this + 32) and FileFinder(v27, aSfx, v37, this + 24). [callee:0x004C40D0, global:0x005D2EAC, global:0x005D2EA4, global:0x005D2E9C, global:0x005D2E94, source:raw]
    // RETURN: Return 0 on the full-success path. [function:0x004C3200, source:raw]
    // CALL: Failure path: if StringSplitLoop(1, aDDevF119992002_8, 115) returns true, call DebugLogWrite(&dword_8AD25C, aCouldNotOpenS) to log the could-not-open message, then return -1. [callee:0x004D7A50, global:0x005D3044, callee:0x004D7AA0, global:0x008AD25C, global:0x005C6810, function:0x004C3200, source:raw]

    // Conservative worker pseudocode:
    //   memset(v36, 0, sizeof(v36));
    //   base = *(char**)this; if (!base) base = byte_5EA438;
    //   h = sub_587DB0(base, aR);
    //   if (!h) {
    //     if (StringSplitLoop(1, aDDevF119992002_8, 115))
    //       DebugLogWrite(&dword_8AD25C, aCouldNotOpenS);
    //     return -1;
    //   }
    //   if (!FileReadUntilNewline(v36, 384, h)) goto close;
    //   do {
    //     sub_5651B0(v30);
    //     sub_5654A0(aHdvehicle, v28); sub_5654A0(aHeadphysics, v26);
    //     sub_5654A0(aSounds, v27); sub_5654A0(aGraphics, v29);
    //     sub_5654A0(aGenstring, this + 40);
    //     if (sub_565870(aEyepoint, this + 56, this + 60, this + 64, 0,0,0,0,0)) {
    //       if (!v24) { *(this+0x44) = *(this+0x38); *(this+0x48) = *(this+0x40); *(this+0x4C) = *(this+0x3C); }
    //       if (!v23) { *(this+0x50) = *(this+0x38); *(this+0x54) = *(this+0x3C) - 0.079999998; *(this+0x58) = *(this+0x40); }
    //     }
    //     if (sub_565870(aCameratarget, this + 68, this + 72, this + 76, 0,0,0,0,0)) v24 = 1;
    //     if (sub_565870(aMirrorpos, this + 80, this + 84, this + 88, 0,0,0,0,0)) v23 = 1;
    //     sub_565870(aMirrornorm, this + 92, this + 96, this + 100, 0,0,0,0,0);
    //     sub_565870(aSteeringwheela, this + 104, this + 108, this + 112, 0,0,0,0,0);
    //     sub_5654A0(aNumber, this + 116); sub_5654A0(aTeam_0, this + 124); sub_5654A0(aDriver_0, this + 188);
    //     sub_5654A0(aDescription, this + 252); sub_5654A0(aEngine, this + 316);
    //     sub_5654A0(aManufacturer, this + 380); sub_5654A0(aClasses, this + 444);
    //     sub_5654A0(aFullteamname, this + 700); sub_5654A0(aTeamfounded, this + 828);
    //     sub_5654A0(aTeamheadquarte, this + 844); sub_5654A0(aTeamstarts, this + 908);
    //     sub_5654A0(aTeampoles, this + 924); sub_5654A0(aTeamwins, this + 940);
    //     sub_5654A0(aTeamworldchamp, this + 956);
    //     if (sub_5654A0(aDefaultlivery, v38)) StringCopyWithBufferRealloc(v38);
    //     if (sub_5654A0(aPitcrewlivery, v38)) StringCopyWithBufferRealloc(v38);
    //     if (sub_5654A0(aTracklivery, v38)) {
    //       split = sub_587C20(v38, asc_5D251C);
    //       if (split) {
    //         node = OperatorNewNhMallocWrapper(20);
    //         if (node) { node[0] = 0; node[1] = -1; node[2] = 0; node[3] = -1; }
    //         // trim spaces/commas, store both parts via StringCopyWithBufferRealloc
    //         node[4] = *(this + 0x3D4); *(this + 0x3D4) = node;
    //       } else if (StringSplitLoop(1, aDDevF119992002_8, 173))
    //         DebugLogWrite(&dword_8AD25C, aFormatIsTrackl);
    //     }
    //   } while (FileReadUntilNewline(v36, 384, h));
    //   close:
    //   FileCloseWithLock(h);
    //   FileINILoader(this);
    //   if (!this[252]) StringFormatWithBufferOverflowCheck(this + 252, fmt, this + 116, this + 124);
    //   base = *(this) ? *(this) : byte_5EA438;
    //   strcpy(v37, base); // then truncate at last backslash
    //   FileFinder(v28, aHdv, v37, this + 8);
    //   FileFinder(v26, aIni, v37, this + 16);
    //   FileFinder(v29, aGen, v37, this + 32);
    //   FileFinder(v27, aSfx, v37, this + 24);
    //   return 0;
    // UNRESOLVED: global:0x008AC388 (unk_8AC388) is listed in the packet globals but does not appear in the raw source body; its role here is unknown.
    // UNRESOLVED: The constants 0.079999998 (mirror Y offset) and the a4s50s format string are mapped to global:0x005ACB28 and global:0x005D2EB4 by inference, not by an explicit packet reference.
    // UNRESOLVED: The number/team string offsets this + 116 / this + 124 used in the auto-description format, and the exact format characters, come from the raw source literal only.
    // UNRESOLVED: sub_5654A0 (key/value string extractor) and sub_565870 (vector parser) semantics, including which return value means a successful parse, are inferred from the loop shape and existing analysis prose.
    // UNRESOLVED: Legacy ABI name veh_File_Parser (abi:lead) is retained as a lead only; the owning object type remains unknown.
}
