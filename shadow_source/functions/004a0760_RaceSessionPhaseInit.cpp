// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0760
// Canonical corpus name: sub_4A0760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0760_004a0760.c

void UnknownObject::RaceSessionPhaseInit()
{
    // Initializes a race session phase: stops the audio system, resets a config buffer, runs an auto-load config check, plays the winner Bink video (winrace.bik) when the scoring gate, player-active and session flags allow it, advances pit-stop phase logic and updates season scoring/array state from the session linked list, dispatches two UI element commands through the command interface, resolves season display IDs, and sets the session state flag to 3.
    // GUARD: If the sound system interface pointer dword_5EB10C is non-null, invoke its vtable method at offset +12 (thiscall) to stop/cleanup audio. [global:0x005EB10C, source:raw]
    // CALL: BufferInitWith10fDefaults(flt_5EA618): initialize a config buffer from defaults table. [callee:0x004186A0, global:0x005EA618, source:raw]
    // CALL: sub_4B17B0(&byte_7CE498): run auto-load config check over the config flag block. [callee:0x004B17B0, global:0x007CE498, source:raw]
    // GUARD: Win-race video gate: proceed only if ScoringGateCheck() returns true, the player vehicle field at dword_7C54E8+16480 equals 1, and session flag dword_7D032C equals 1. [callee:0x0042BC10, global:0x007C54E8, global:0x007D032C, source:raw]
    // ASSIGNMENT: Select video path prefix: use dword_5EC418 if non-null, else fall back to byte_5EA438. [global:0x005EC418, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%s%s", prefix, aWinraceBik): build "<path>winrace.bik" into the 256-byte stack buffer. [callee:0x0058815F, global:0x005BE860, global:0x005CD00C, source:raw]
    // CALL: FileLoadWithRetryLoop(v8, 1): load the win-race video file with retry. [callee:0x004F9B70, source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0): dereference the session linked-list head; result stored in v1/v2. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: If the linked list dereference returned a non-null node, process the session node. [source:raw]
    // CALL: PitStopPhaseAdvance(v1): advance pit-stop phase state on the node. [callee:0x004C15A0, source:raw]
    // GUARD: Branch on DelegatedFieldGetter(&dword_7D2DB0): if it returns 3 take the phase-3 path, else the season-scoring path. [callee:0x004C2760, global:0x007D2DB0, source:raw]
    // CALL: FixedOffsetReturn(v2): obtain the node-derived object pointer into v3. [callee:0x004C1390, source:raw]
    // GUARD: Proceed only if v3 is non-null and its field at +412 equals 0. [source:raw]
    // CALL: IncrementFieldAt0x34(&dword_7D2DB0): increment the node field at offset 0x34. [callee:0x004C2C10, global:0x007D2DB0, source:raw]
    // GUARD: If session flag dword_7D032C equals 1, play the windrivers intro video. [global:0x007D032C, source:raw]
    // ASSIGNMENT: Select video path prefix for the intro video: dword_5EC418 if non-null, else byte_5EA438. [global:0x005EC418, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v8, "%s%s", prefix, aWindriversBik): build "<path>windrivers.bik". [callee:0x0058815F, global:0x005BE860, global:0x005CCFFC, source:raw]
    // CALL: FileLoadWithRetryLoop(v8, 1): load the windrivers video file with retry. [callee:0x004F9B70, source:raw]
    // CALL: SeasonScoringInfoUpdater(&dword_7D2DB0): update season scoring info for the session node. [callee:0x004C2A80, global:0x007D2DB0, source:raw]
    // CALL: ArrayCheckInit(&dword_7D2DB0): re-initialize the session array state. [callee:0x004C2810, global:0x007D2DB0, source:raw]
    // CALL: Invoke vtable+28 (thiscall, arg 40) on the command interface dword_7CD8C0 to obtain UI element pointer v5. [global:0x007CD8C0, source:raw]
    // CALL: Invoke vtable+28 (thiscall, arg 42) on the command interface dword_7CD8C0 to obtain UI element pointer v6. [global:0x007CD8C0, source:raw]
    // GUARD: If v5 is non-null, call sub_47C360(v5, 1) to set UI element 40 state. [callee:0x0047C360, source:raw]
    // GUARD: If v6 is non-null, call sub_47C360(v6, 0) to clear UI element 42 state. [callee:0x0047C360, source:raw]
    // CALL: SeasonDisplayIDResolver(): refresh season display IDs for the standings. [callee:0x0041DAF0, source:raw]
    // STATE_TRANSITION: Set session state flag dword_5CC9E8 to 3 (session active/ready). [global:0x005CC9E8, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int RaceSessionPhaseInit()
    //   {
    //     char videoPath[256];
    //     if (g_soundSystem) g_soundSystem->vtableStop();
    //     BufferInitWith10fDefaults(&g_configDefaults);
    //     AutoLoadConfigCheck(&g_configFlags);
    //     if (ScoringGateCheck() && playerField16480 == 1 && g_sessionFlag == 1)
    //     {
    //       const char* prefix = g_customPath ? g_customPath : g_defaultPath;
    //       StringFormatWithBufferOverflowCheck(videoPath, "%s%s", prefix, "winrace.bik");
    //       FileLoadWithRetryLoop(videoPath, 1);
    //     }
    //     SessionNode* node = LinkedListDereference(&g_sessionList);
    //     if (node)
    //     {
    //       PitStopPhaseAdvance(node);
    //       if (DelegatedFieldGetter(&g_sessionList) == 3)
    //       {
    //         void* obj = FixedOffsetReturn(node);
    //         if (obj && *(DWORD*)((char*)obj + 412) == 0)
    //         {
    //           IncrementFieldAt0x34(&g_sessionList);
    //           if (g_sessionFlag == 1)
    //           {
    //             const char* prefix = g_customPath ? g_customPath : g_defaultPath;
    //             StringFormatWithBufferOverflowCheck(videoPath, "%s%s", prefix, "windrivers.bik");
    //             FileLoadWithRetryLoop(videoPath, 1);
    //           }
    //         }
    //       }
    //       else
    //       {
    //         SeasonScoringInfoUpdater(&g_sessionList);
    //         ArrayCheckInit(&g_sessionList);
    //       }
    //     }
    //     void* ui40 = g_commandInterface->vtableGet(40);
    //     void* ui42 = g_commandInterface->vtableGet(42);
    //     if (ui40) SetUiState(ui40, 1);
    //     if (ui42) SetUiState(ui42, 0);
    //     SeasonDisplayIDResolver();
    //     g_sessionState = 3;
    //     return 0;
    //   }
    // UNRESOLVED: dword_5EB978 is read by SeasonDisplayIDResolver but never appears in the raw source; its purpose is unknown.
    // UNRESOLVED: unk_5EC6D0 is read by sub_4B17B0 per existing analysis but never appears in the raw source; presumed auto-load config data.
    // UNRESOLVED: unk_8AFE18 is marked read but never appears in the raw source; no consumer visible in this function.
    // UNRESOLVED: Field at +412 on the FixedOffsetReturn object and field at +16480 on the dword_7C54E8 object are only referenced as raw offsets; no type evidence.
    // UNRESOLVED: The vtable+12 sound stop and vtable+28 command-interface getters have no resolved class or callee addresses.
}
