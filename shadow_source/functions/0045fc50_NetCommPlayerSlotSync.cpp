// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045FC50
// Canonical corpus name: NetCommPlayerSlotSync
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetCommPlayerSlotSync_0045fc50.c

void UnknownObject::NetCommPlayerSlotSync()
{
    // Multiplayer player-slot synchronization. Gated on the SyncInProgress byte at this+0x374 (non-zero returns early). Pass 1 walks active player slots from base this+244 (dword index, byte offset this+0x3D0, stride 140) while ActiveSlotCount at this+0x3E14 is positive, FlagBitTest(slot-60, 2) marks occupied slots, and occupied slots with a non-empty name run join processing: per-vehicle slot derived from the vehicle array at &unk_5EC6D8 + 18624*slot, driver-name comparison via PathFilenameExtractor/sub_588410, resource load (VehgenScnFileLoader, SceneRenderUpdate, force-feedback, cockpit gauges, physics subsystem), joined-slot message display and sound flags. Pass 2 walks the whole vehicle array up to byte_7C54D8, unloads slots that vanished (not marked in pass 1), displays a leave message, trims the session-path linked list (this+0x3FC8 head / this+0x3FCC tail / this+0x3FD0 iterator / this+0x3FD4 count) to remove the departed path, resets the vehicle to inactive, and repoints the current player. VehicleCount at dword_5C329C is adjusted, ClearPlayerSlots runs, and the active vehicle pointer array is rebuilt.
    // GUARD: Re-entry guard: byte at this+0x374 non-zero returns immediately, skipping the entire sync pass [field:this:0x00000374, source:raw]
    // ASSIGNMENT: Local state init: 104-byte presence buffer v40 memset to 0 and locals i, v30, v32, v37, v35 cleared to 0 [source:raw]
    // GUARD: Join-detection loop gated on ActiveSlotCount at this+0x3E14 being greater than 0 (packet guard) [guard:0, field:this:0x00003E14, source:raw]
    // LOOP: Pass 1 walks player slots from base this+0x3D0 (244 as a dword index) stepping by 140 bytes, bounded by ActiveSlotCount at this+0x3E14 [field:this:0x00003E14, source:raw]
    // GUARD: Per-slot occupancy test via FlagBitTest(slot-60, 2); only occupied slots with a non-empty name (strlen check) are processed for join [callee:0x00461530, source:raw]
    // CALCULATION: Slot index v5 = v4[64]; vehicle slot pointer derived as &unk_5EC6D8 + 18624*v5; inactive slot check reads *(slot+3250) == -1 [global:0x005EC6D8, source:raw]
    // CALL: PathFilenameExtractor on the vehicle slot then sub_588410 string comparison against the slot name; join path entered when names differ, or the vehicle pointer at *(slot+1780) is null, or the slot is inactive [callee:0x004C69E0, callee:0x00588410, source:raw]
    // CALL: TwoCallDelegation(v6, v4) delegates vehicle setup calls, then StringCopyWithBufferRealloc copies the slot name into the driver field at slot+1920 [callee:0x004C7B20, callee:0x00566650, source:raw]
    // CALL: Re-check with sub_588410 and the vehicle pointer; when still mismatched the join setup runs: sub_45C030 on the slot-scoped UI data, ThunkWithStructInitSubCalls, and PerElementArrayReset(this+26864, v5) [callee:0x00588410, callee:0x0045C030, callee:0x004FFFA0, callee:0x0045C850, source:raw]
    // CALL: Player-vs-AI branch: when v5 equals IDLookupInArray(*this), the slot is the local player — SessionStateTransition((float*)v6+3, 0, 0) if the slot data flag at *(slot+16484) is clear or the slot is inactive, then SetPlayerVehicleIndex_bc40(v5); otherwise SessionStateTransition((float*)v6+3, 2, 0) [callee:0x00462330, field:this:0x00000000, callee:0x004EF5A0, callee:0x0042BC40, source:raw]
    // CALL: Slot metadata update: ConditionalFieldSetter(slot+16436, v5+1) and FieldCopy(slot+16436), tied by the skeleton to the slot-array field at this+0x410 [callee:0x004BC2F0, callee:0x004BC320, field:this:0x00000410, source:raw]
    // CALL: Server-only 'LOADING slot' log: when dword_7C569C != 5 and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4014) succeeds, DebugLogWrite(dword_8AD25C, aLoadingSlotInd-style '*** LOADING Slot' line with slot index and session time dbl_8AFEA0) [global:0x007C569C, global:0x005C5CE4, global:0x008AFEA0, global:0x005C5F2C, callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, source:raw]
    // CALL: Vehicle load completion: increment VehicleCount dword_5C329C, BuildActiveVehiclePointerArray, VehgenScnFileLoader(v6, 1), SceneRenderUpdate(v6, 1.0), LoopOverTwoParallelArrays(dword_8ACEE0) [global:0x005C329C, callee:0x0042BC80, callee:0x004C6C40, callee:0x004C6D90, callee:0x004D1030, global:0x008ACEE0, source:raw]
    // CALL: Active-slot post-load path: when *(slot+3250) is non-zero, join flags v31/v30 are set and ShortComputation_5430(*(slot+4645), slot+65 byte) runs, tied by the skeleton to the slot byte at this+0x411 [callee:0x00465430, field:this:0x00000411, source:raw]
    // CALL: Inactive-slot path: 'slot is tagged as' debug log (aSlotIsTaggedAs), loop over dword_7C54F0[v10] entries (v10 < dword_5C329C) calling AudioSoundEffectController(entry+1776, 0), then SetPlayerVehicleIndex(v5), GameStateBranchDispatch(dword_5EA510), CockpitDashboardLEDGaugeSetup(dword_7CE058), PhysicsSubsystemStep(dword_7C73E8, v5) [global:0x005C5F08, callee:0x004E0ED0, global:0x005C329C, global:0x007C54F0, callee:0x0042BBD0, callee:0x0040D100, global:0x005EA510, callee:0x0049CA00, global:0x007CE058, callee:0x00433870, global:0x007C73E8, source:raw]
    // CALL: Per-slot data copy: sub_587DD0(slot+18016, name-24, 0x17), clear byte at slot+18039, and if strcmp(slot+17952, name-56) differs call SetDriverName(slot, name-56) [callee:0x00587DD0, callee:0x004C6980, source:raw]
    // CALL: Joined-slot message: when join flag v31 is set, BinarySearchInStringTable(byte_5EC4C0, aHasEnteredTheG, byte_5EC4CC) copies the 'has entered the game' text, StringFormatWithBufferOverflowCheck(v41, "%s %s", slot+17952, byte_5EC4CC) formats it, and TextLineWrappingAndRendering(dword_7CD204, v41, 3, 16909060) displays it [callee:0x00423A00, global:0x005EC4C0, global:0x005C5EF0, global:0x005EC4CC, callee:0x0058815F, callee:0x0045BD10, global:0x007CD204, source:raw]
    // ASSIGNMENT: Presence record: v40[v39] = 1 marks the slot as still present, and the slot pointer advances by 140 [source:raw]
    // LOOP: Pass 2 walks the whole vehicle array from &unk_5EC6D8 by stride 18624 while below the byte_7C54D8 end; entries not marked in v40 and still active (*(slot+3250) != -1) are treated as departed players [global:0x005EC6D8, global:0x007C54D8, source:raw]
    // CALL: Leave message: BinarySearchInStringTable(byte_5EC4C0, aLeftTheGame, byte_5EC4CC) copies the 'left the game' text, StringFormatWithBufferOverflowCheck(v41, "%s %s", slot+17952, byte_5EC4CC) formats it, and TextLineWrappingAndRendering(dword_7CD204, v41, 3, 16909060) displays it [callee:0x00423A00, global:0x005EC4C0, global:0x005C5EE0, global:0x005EC4CC, callee:0x0058815F, callee:0x0045BD10, global:0x007CD204, source:raw]
    // CALL: Server-only 'UNLOADING slot' log: when dword_7C569C != 5 and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4111) succeeds, DebugLogWrite(dword_8AD25C, aUnloadingSlotI-style '*** UNLOADING Slot' line with index and session time dbl_8AFEA0) [global:0x007C569C, global:0x005C5CE4, global:0x008AFEA0, global:0x005C5EB4, callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, source:raw]
    // GUARD: Path-trim block gated on SessionMode at this+0x3FC4 being 2 (qualifying) or 1 (race); a backslash scan on the session path at slot+18196 trims the trailing filename segment [field:this:0x00003FC4, source:raw]
    // CALL: Session-path linked-list removal: iterator at this+0x3FD0 seeded from head this+0x3FC8; nodes are walked comparing the node string at offset 0 (*(this+0x3FCC):0) against the trimmed path via sub_588410, following the next pointer at offset 4 (*(this+0x3FCC):4); on match the node is unlinked, head this+0x3FC8 / tail this+0x3FCC / count this+0x3FD4 are updated, and the node is freed via FreeWrapper_7bcf when the flag byte at offset 8 (*(this+0x3FCC):8) is set [field:this:0x00003FC8, field:this:0x00003FD0, field:*(this+0x3FCC):0x00000000, field:*(this+0x3FCC):0x00000004, field:this:0x00003FCC, field:this:0x00003FD4, field:*(this+0x3FCC):0x00000008, callee:0x00587BCF, callee:0x00588410, source:raw]
    // CALL: After unload: sub_4C6E80(v14) cleans the vehicle slot, then SessionStateTransition((float*)v14+3, 0xFFFFFFFF, 0) marks the slot inactive [callee:0x004C6E80, callee:0x004EF5A0, source:raw]
    // CALL: Current-player repoint: when the departed slot was the current player (dword_7C54F0[dword_7C54DC]+18580 match) and the candidate at dword_7C54F0[dword_7C54E4]+18580 is inactive (dword_5EF9A0[4656*v27] == -1), scan dword_7C54F0 for the first active slot (+13000 != -1) and set dword_7C54DC and dword_7C54E0; otherwise SetPlayerVehicleIndex(v27) [global:0x007C54F0, global:0x007C54DC, global:0x007C54E4, global:0x005EF9A0, callee:0x0042BBD0, global:0x005C329C, global:0x007C54E0, source:raw]
    // CALL: Server-only 'Unsetting slot' log: when dword_7C569C != 5 and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4164) succeeds, DebugLogWrite(dword_8AD25C, aUnsettingSlotI-style '*** Unsetting Slot' line with index) [global:0x007C569C, global:0x005C5CE4, global:0x005C5E94, callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, source:raw]
    // CALL: Post-removal cleanup: when removals occurred (v34 > 0), ClearPlayerSlots(v1, 1), decrement VehicleCount dword_5C329C by v34, and BuildActiveVehiclePointerArray [callee:0x00460CB0, global:0x005C329C, callee:0x0042BC80, source:raw]
    // CALL: Sound effects: when SessionMode at this+0x3FC4 != 1 (packet guard), SoundEffectLoadPlay(0/1/2, 1065353216) fires for join/enter/leave flags i, v30, v32 respectively [guard:1, field:this:0x00003FC4, callee:0x004C8DE0, source:raw]
    // RETURN: When the processed-slot count v37 differs from VehicleCount dword_5C329C, dword_5C329C is updated to v37 and BuildActiveVehiclePointerArray's result is returned; otherwise the sync returns v37 [global:0x005C329C, callee:0x0042BC80, source:raw]
    // CALL: Invoked by SessionScoringUpdate (004643c0) [caller:0x004643C0, source:raw]

    // Conservative worker pseudocode:
    //   if (*(this + 884)) return *(this + 884);
    //   memset(v40, 0, 104); i = v30 = v32 = v37 = v35 = 0;
    //   if (this[3973] > 0) {
    //     slot = (char*)(this + 244);
    //     do {
    //       if (FlagBitTest(slot - 60, 2) && strlen(slot)) {
    //         v37++; idx = slot[64];
    //         veh = &unk_5EC6D8 + 18624*idx;
    //         if (sub_588410(PathFilenameExtractor(veh), slot) || !*(veh + 1780) || *(veh + 3250) == -1) {
    //           TwoCallDelegation(veh, slot); StringCopyWithBufferRealloc(veh + 1920, slot + 32);
    //           if (!sub_588410(PathFilenameExtractor(veh), slot) || !*(veh + 1780)) {
    //             sub_45C030(&this[14*idx + 28136]);
    //             ThunkWithStructInitSubCalls(&this[218*idx + 4192]);
    //             PerElementArrayReset(this + 26864, idx);
    //             if (idx == IDLookupInArray(*this)) {
    //               if (!*(veh + 4121) || *(veh + 3250) == -1) SessionStateTransition((float*)veh + 3, 0, 0);
    //               SetPlayerVehicleIndex_bc40(idx); }
    //             else SessionStateTransition((float*)veh + 3, 2, 0);
    //             ConditionalFieldSetter(veh + 16436, idx + 1); FieldCopy(veh + 16436);
    //             if (dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4014))
    //               DebugLogWrite(dword_8AD25C, "*** LOADING Slot...", idx, slot, dbl_8AFEA0);
    //             ++dword_5C329C; BuildActiveVehiclePointerArray();
    //             VehgenScnFileLoader(veh, 1); SceneRenderUpdate(veh, 1.0);
    //             LoopOverTwoParallelArrays(dword_8ACEE0);
    //             if (*(veh + 3250)) { v31 = 1; v30 = 1; ShortComputation_5430(*(veh + 4645), slot[65]); }
    //             else {
    //               if (dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4038))
    //                 DebugLogWrite(dword_8AD25C, aSlotIsTaggedAs);
    //               for (n = 0; n < dword_5C329C; n++) AudioSoundEffectController(dword_7C54F0[n] + 1776, 0);
    //               SetPlayerVehicleIndex(idx); GameStateBranchDispatch(&dword_5EA510);
    //               CockpitDashboardLEDGaugeSetup(&dword_7CE058); PhysicsSubsystemStep(&dword_7C73E8, idx);
    //             }
    //           }
    //         }
    //         sub_587DD0(veh + 18016, name - 24, 0x17); *(veh + 18039) = 0;
    //         if (strcmp(veh + 17952, name - 56)) SetDriverName(veh, name - 56);
    //         if (v31) { BinarySearchInStringTable(byte_5EC4C0, aHasEnteredTheG, byte_5EC4CC);
    //                    StringFormatWithBufferOverflowCheck(v41, "%s %s", veh + 17952, byte_5EC4CC);
    //                    TextLineWrappingAndRendering(&dword_7CD204, v41, 3, 16909060); }
    //         v40[idx] = 1;
    //       }
    //       slot += 140;
    //     } while (++v35 < this[3973]);
    //   }
    //   for (veh = &unk_5EC6D8, n = 0; veh < byte_7C54D8; veh += 18624, n++) {
    //     if (!v40[n] && *(veh + 3250) != -1) {
    //       BinarySearchInStringTable(byte_5EC4C0, aLeftTheGame, byte_5EC4CC);
    //       StringFormatWithBufferOverflowCheck(v41, "%s %s", veh + 17952, byte_5EC4CC);
    //       TextLineWrappingAndRendering(&dword_7CD204, v41, 3, 16909060);
    //       if (dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4111))
    //         DebugLogWrite(dword_8AD25C, "*** UNLOADING Slot...", *(veh + 4645), dbl_8AFEA0);
    //       if (SessionMode == 2 || SessionMode == 1) {
    //         trim trailing filename from veh + 18196 path;
    //         walk path list from this[4082]; if found, unlink node, update head/tail/count, free via FreeWrapper_7bcf;
    //       }
    //       sub_4C6E80(veh); SessionStateTransition((float*)veh + 3, 0xFFFFFFFF, 0);
    //       if (current player left) repoint dword_7C54DC / dword_7C54E0 to next active slot;
    //       if (dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_1, 4164))
    //         DebugLogWrite(dword_8AD25C, "*** Unsetting Slot...", n);
    //     }
    //   }
    //   if (removed > 0) { ClearPlayerSlots(this, 1); dword_5C329C -= removed; BuildActiveVehiclePointerArray(); }
    //   if (this[4081] != 1) {
    //     if (i) SoundEffectLoadPlay(0, 1065353216);
    //     if (v30) SoundEffectLoadPlay(1, 1065353216);
    //     if (v32) SoundEffectLoadPlay(2, 1065353216);
    //   }
    //   if (v37 != dword_5C329C) { dword_5C329C = v37; return BuildActiveVehiclePointerArray(); }
    //   return v37;
    // UNRESOLVED: String globals aSS_2 (0x005C5D30), unk_5EC6D0 (0x005EC6D0), dword_7CD2A8 (0x007CD2A8) and byte_8AC494 (0x008AC494) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton labels them as driver-settings suffix, vehicle-array base, a menu struct and a scene name, all unverifiable from this packet
    // UNRESOLVED: Several vehicle-slot offsets reached through the &unk_5EC6D8 + 18624*slot base (e.g. +1780, +3250, +16436, +4645, +17952, +18016) are read/written but not enumerated as packet fields; only the linked-list node fields (this+0x3FCC base) are packet-flagged
    // UNRESOLVED: The exact semantics of GameStateBranchDispatch / SessionStateTransition arguments (0, 2, 0xFFFFFFFF) are call-level states, not defined by this packet
}
