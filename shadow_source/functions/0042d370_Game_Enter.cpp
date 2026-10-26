// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D370
// Canonical corpus name: Game_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Game_Enter_0042d370.c

void UnknownObject::Game_Enter()
{
    // Game session initialization entry point. Sets the game-entered flag at this+0x0 to 1, logs an 'entered game enter' debug line when StringSplitLoop parsing of aDDevF119992002_11 succeeds, then sequentially initializes subsystems — OS manager (OSMan_Enter), game files (GameFileLoader), video (VidMan_Enter), special FX, dynamics, player files, audio configs, sound, input, on-screen display and the module hook sub_463E20. Builds an audio config path from the season directory (dword_5EC3D8, fallback byte_5EA438) plus dword_7D0434 and decodes it, retrying with the aF12002Gdb track DB name on failure; then loads all .rcd and .pit files found via DirectoryEntryIterator. Returns 1 on any subsystem init failure, 0 on success.
    // ASSIGNMENT: Game-entered flag at this+0x0 is set to 1 on entry [field:this:0x00000000, source:raw]
    // CALL: When StringSplitLoop(2, aDDevF119992002_11, 360) succeeds, DebugLogWrite(&dword_8AD25C, aEnteredGameEnt) logs the 'Entered game enter' message [callee:0x004D7A50, global:0x005C3590, callee:0x004D7AA0, global:0x008AD25C, global:0x005C3610, source:raw]
    // CALL: OSMan_Enter(&unk_7CE2A4) initializes the OS manager; a non-zero result returns 1 immediately [callee:0x004A18D0, global:0x007CE2A4, source:raw]
    // CALL: GameFileLoader(this) loads game files; a non-zero result returns 1 immediately [callee:0x0042D260, source:raw]
    // CALL: VidMan_Enter(&unk_8AFE18) initializes video; a non-zero result returns 1 immediately [callee:0x004FA000, global:0x008AFE18, source:raw]
    // CALL: Subsystem enters without failure checks: SpecialFX_Enter(&dword_8ACEA0), DynMan_Enter(), PlayerFile_Enter(&byte_7CE498) [callee:0x004CEE90, global:0x008ACEA0, callee:0x0042C130, callee:0x004B1820, global:0x007CE498, source:raw]
    // CALCULATION: Audio path assembly: season directory from dword_5EC3D8 (fallback byte_5EA438 when null) is concatenated with dword_7D0434 via StringFormatWithBufferOverflowCheck(v9, "%s%s", dir, dword_7D0434) [global:0x005EC3D8, global:0x005EA438, global:0x007D0434, callee:0x0058815F, source:raw]
    // CALL: AudioFileLoadDecode(v9, 0) decodes the audio config; on failure StringCopyWithBufferRealloc(aF12002Gdb) rebuilds the path and the decode retries [callee:0x00567F40, callee:0x00566650, global:0x005BF970, global:0x005EC3D8, global:0x005EA438, global:0x007D0434, callee:0x0058815F, source:raw]
    // LOOP: .rcd load pass: sub_565F80(aRcd, 1, dir, 0) seeds the directory scan, then DirectoryEntryIterator(&unk_8AD3B0) yields each entry which is decoded with AudioFileLoadDecode(i, 0) and advanced via LinkedListNodePeek(&unk_8AD3B0) [callee:0x00565F80, global:0x005C3608, global:0x005EC3D8, global:0x005EA438, callee:0x005662D0, global:0x008AD3B0, callee:0x00567F40, callee:0x00565F20, source:raw]
    // LOOP: .pit load pass: sub_565F80(aPit, 1, dir, 0) seeds the directory scan, then the same DirectoryEntryIterator(&unk_8AD3B0) / AudioFileLoadDecode(i, 0) / LinkedListNodePeek(&unk_8AD3B0) loop decodes every entry [callee:0x00565F80, global:0x005C3600, global:0x005EC3D8, global:0x005EA438, callee:0x005662D0, global:0x008AD3B0, callee:0x00567F40, callee:0x00565F20, source:raw]
    // CALL: Sound_Enter(&byte_8AC494) initializes sound; a non-zero result returns 1 immediately [callee:0x004C8A20, global:0x008AC494, source:raw]
    // CALL: HWInput_Enter(&ppvOut) initializes hardware input; a non-zero result returns 1 immediately [callee:0x00455BF0, global:0x007CA590, source:raw]
    // CALL: Final module enters: EmptyStub_0170(&unk_7CE24D), EmptyStub_0170(&dword_8AB6E4), OnScreen_Enter(&dword_7CE048), EmptyStub_0170(&dword_8ACEE0), sub_463E20(&dword_7CD25C) [callee:0x004B0170, global:0x007CE24D, global:0x008AB6E4, callee:0x0049EF40, global:0x007CE048, global:0x008ACEE0, callee:0x00463E20, global:0x007CD25C, source:raw]
    // RETURN: Returns 0 on full success; each checked subsystem enter (OSMan, game files, video, sound, input) returns 1 on its failure [source:raw]
    // CALL: Invoked by GameMainEntry (0045b200) [caller:0x0045B200, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 1;
    //   if (StringSplitLoop(2, aDDevF119992002_11, 360)) DebugLogWrite(&dword_8AD25C, aEnteredGameEnt);
    //   if (OSMan_Enter(&unk_7CE2A4)) return 1;
    //   if (GameFileLoader(this)) return 1;
    //   if (VidMan_Enter(&unk_8AFE18)) return 1;
    //   SpecialFX_Enter(&dword_8ACEA0); DynMan_Enter(); PlayerFile_Enter(&byte_7CE498);
    //   dir = dword_5EC3D8 ? dword_5EC3D8 : &byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(v9, "%s%s", dir, dword_7D0434);
    //   if (!AudioFileLoadDecode(v9, 0)) {
    //     StringCopyWithBufferRealloc(aF12002Gdb);
    //     StringFormatWithBufferOverflowCheck(v9, "%s%s", dir, dword_7D0434);
    //     AudioFileLoadDecode(v9, 0);
    //   }
    //   sub_565F80(aRcd, 1, dir, 0);
    //   for (e = DirectoryEntryIterator(&unk_8AD3B0); e; e = DirectoryEntryIterator(&unk_8AD3B0))
    //     { AudioFileLoadDecode(e, 0); LinkedListNodePeek(&unk_8AD3B0); }
    //   sub_565F80(aPit, 1, dir, 0);
    //   for (e = DirectoryEntryIterator(&unk_8AD3B0); e; e = DirectoryEntryIterator(&unk_8AD3B0))
    //     { AudioFileLoadDecode(e, 0); LinkedListNodePeek(&unk_8AD3B0); }
    //   if (Sound_Enter(&byte_8AC494)) return 1;
    //   if (HWInput_Enter(&ppvOut)) return 1;
    //   EmptyStub_0170(&unk_7CE24D); EmptyStub_0170(&dword_8AB6E4);
    //   OnScreen_Enter(&dword_7CE048); EmptyStub_0170(&dword_8ACEE0); sub_463E20(&dword_7CD25C);
    //   return 0;
    // UNRESOLVED: Globals aSS (0x005BE860), unk_5EC6D0 (0x005EC6D0), dword_7D0438 (0x007D0438) and dword_8AD3B4 (0x008AD3B4) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton labels aSS as a path format string and unk_5EC6D0 as unused here, the other two are unnamed
}
