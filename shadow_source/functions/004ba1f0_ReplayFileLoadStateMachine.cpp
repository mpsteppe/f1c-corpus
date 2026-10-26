// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA1F0
// Canonical corpus name: sub_4BA1F0
// Owner: ReplayPlaybackLoaderStateMachine [DERIVED]
// Raw source: functions/sub_4BA1F0_004ba1f0.c

void ReplayPlaybackLoaderStateMachine::ReplayFileLoadStateMachine()
{
    // State machine step for the replay/VCR playback loader, polled by Game_Init (0x0042D6B0). In state 2 (*this==2) it opens the replay file, reads it in 1024-byte chunks, processes the replay data, assigns the player vehicle and dispatches menu action 5, keeping *this==2 on success and setting *this==0 on failure. In any other state it recomputes *this from a flag gate (ConditionalFlagReturn on dword_5EA43C) combined with the session flags dword_7D0038/dword_7D005C, and returns that gate result.
    // GUARD: State gate: if (*this == 2) run the replay-load branch; any other state falls through to the session-flag recompute branch. Called from Game_Init (0x0042D6B0). [guard:0, field:this:0x00000000, caller:0x0042D6B0, function:0x004BA1F0, source:raw]
    // CALL: Dev-config string parse: StringSplitLoop(2, aDDevF119992002_22, 5513); if nonzero, DebugLogWrite(&dword_8AD25C, aLoadingVcrFile). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D24DC, global:0x005D24BC, global:0x008AD25C]
    // ASSIGNMENT: Resolve replay file path: read path pointer from the vehicle object behind this+0x8 (dereferenced at vehicle+3988 bytes); fall back to global byte_5EA438 when null. [field:this:0x00000008, global:0x005EA438]
    // CALL: Zero-init 28-byte buffer v21 (ZeroInitSmallStruct); open the replay/audio stream via AudioStreamOpen(path, 0); on open failure jump to the failure label (*this=0). [callee:0x005668B0, callee:0x00566B20, field:this:0x00000000]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aPreppingReplay, byte_5EC4CC); on match, copy aPreppingReplay bytes into the message display buffer byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005D24AC, global:0x005EC4CC]
    // CALL: SessionTypeGuard(&unk_7CE24D, ..., byte_5EC4CC), then Sleep(0xFA) = 250 ms delay before continuing load. [callee:0x004A0E70, global:0x007CE24D, global:0x0059E0DC]
    // CALL: Allocate a 128-byte path object via OperatorNewNhMallocWrapper(128), zero its first byte, set its size field to 128, then initialize it via sub_4B9830. [callee:0x00587C03, callee:0x004B9830]
    // CALL: FileAttributesExistenceCheck on the replay path (or byte_5EA438 fallback when the buffer is null). [callee:0x00568540, global:0x005EA438]
    // CALL: Zero-init 28-byte buffer v20; open the replay file for reading via sub_566940(path, 0, 0, 1); on success enter the chunk-read loop. [callee:0x005668B0, callee:0x00566940]
    // LOOP: Read loop: FileWriteWithBackendDispatch(v22, 1024) until it returns <=0; dispatch each chunk via ConditionalDispatch_6bd0(v22, bytes_read). [callee:0x00566C00, callee:0x00566BD0]
    // CALL: Close both file contexts: ConditionalFileHandleCloseWithFlagDispatch(v20) then ConditionalFileHandleCloseWithFlagDispatch(v21). [callee:0x00566B90]
    // CALL: Process replay data: v2 = ThunkToFUN004b7300(this+2, path, 0). On success: SingleCallWrapper_9810(this+2), set *this=2, MenuActionDispatch(this+2, 5). [callee:0x004B97D0, callee:0x004B9810, callee:0x004B9DA0, field:this:0x00000000]
    // CALL: Cleanup: SubCallWithConditionalFieldFree(v20); free the path buffer via FreeWrapper_7bcf when v19[0] was allocated. [callee:0x005668D0, callee:0x00587BCF]
    // CALL: On successful load, resolve the player vehicle via WheelForceAccessor(this+2) and register it as player through both SetPlayerVehicleIndex and SetPlayerVehicleIndex_bc40. [callee:0x004B9820, callee:0x0042BBD0, callee:0x0042BC40]
    // CALL: QueuePeek(vehicle, &peeked_angle, v19); write the peeked angle into vehicle+0xF3C (float); AngleClampWrap(vehicle, angle). [callee:0x004B87A0, callee:0x004B86E0, field:*(this+0x8):0x00000F3C, field:this:0x00000008]
    // RETURN: Success path returns the result of SubCallWithConditionalFieldFree(v21). [callee:0x005668D0]
    // STATE_TRANSITION: Failure path (LABEL_24): set *this=0 and return SubCallWithConditionalFieldFree(v21). [field:this:0x00000000, callee:0x005668D0]
    // ASSIGNMENT: Else branch (state != 2): result = ConditionalFlagReturn(&dword_5EA43C); *this = !result && (dword_7D0038 || dword_7D005C). [callee:0x00404F10, global:0x005EA43C, global:0x007D0038, global:0x007D005C, field:this:0x00000000]
    // RETURN: Return the session-gate result: nonzero when dword_7D0038/dword_7D005C is set and the dword_5EA43C flag gate is clear. [field:this:0x00000000, global:0x007D0038, global:0x007D005C]

    // Conservative worker pseudocode:
    //   state = *this;
    //   if (state == 2) {
    //     replay_load_succeeded = false;
    //     path = *(vehicle_this + 3988) or default_path;
    //     if (!AudioStreamOpen(path, 0)) { *this = 0; return cleanup(v21); }
    //     maybe_show_prepping_replay_message();
    //     SessionTypeGuard(&unk_7CE24D, ..., msg_buf);
    //     Sleep(250);
    //     path_obj = alloc(128); init_path_obj(path_obj, path);
    //     FileAttributesExistenceCheck(path);
    //     if (open_replay(path)) {
    //       while ((n = read_chunk(buf, 1024)) > 0) dispatch_chunk(buf, n);
    //       close(v20); close(v21);
    //       replay_load_succeeded = process_replay(this + 2, path, 0);
    //       if (replay_load_succeeded) { init_single(this + 2); *this = 2; menu_action(this + 2, 5); }
    //     }
    //     cleanup(v20); free(path_obj);
    //     if (replay_load_succeeded) { set_player_vehicle(vehicle); set_player_vehicle_2(vehicle); peek_angle_into(vehicle); return cleanup(v21); }
    //     *this = 0; return cleanup(v21);
    //   }
    //   *this = !flag_gate() && (dword_7D0038 || dword_7D005C);
    //   return *this;
    // UNRESOLVED: Packet field evidence_ref field:this:0x00000F9C lists a read at vehicle offset 0xF9C, but the raw decompile shows the path pointer read at vehicle+3988 (decimal) = 0xF94. 0xF9C originates from the deterministic fact table; not reconciled with the raw listing.
    // UNRESOLVED: Global unk_5EC6D0 (0x005EC6D0) is listed as referenced but does not appear in the raw decompile text; role unknown.
    // UNRESOLVED: SessionTypeGuard is passed v5 as its second argument, which is uninitialized EDX in the decompile; argument value unknown.
    // UNRESOLVED: Local v19 doubles as the 128-byte path object and as the output buffer for QueuePeek; lifetime/overlap of the two uses is not resolved.
    // UNRESOLVED: AngleClampWrap receives v17 (copy of peeked_angle, a float stored in EDX in the decompile) after vehicle+0xF3C is already written; ordering of the clamp vs. store is ambiguous.
}
