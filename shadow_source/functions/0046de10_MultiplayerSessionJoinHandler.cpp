// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046DE10
// Canonical corpus name: MultiplayerSessionJoinHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiplayerSessionJoinHandler_0046de10.c

void UnknownObject::MultiplayerSessionJoinHandler()
{
    // Handles the multiplayer session join flow. A per-frame countdown timer at this+0xE4 is decremented each tick while positive, gating the join attempt. A session object reached through this+0x40 is polled via its vtable entry at offset 28 (argument 34) and a FieldGetter result is checked for a negative value. On validation failure the function formats a session-id buffer from byte_5EA438, translates it via EnumToEnumTranslator, looks the entry up in the string table, copies it into byte_5EC4CC, displays the join-failure page and returns -1. On success it runs the debug-diagnostic string-split logging block, walks every vehicle slot (stride 4656) calling SessionStateTransition(-1, 0), resets the vehicle array, builds the active-vehicle pointer array, flags the session as reconnecting, dispatches the client-team-select page and returns 0.
    // ASSIGNMENT: Initialize join state: v3 = 0, v4 = -1 (default failure return) [source:raw]
    // GUARD: If the float countdown timer at a1 + 0xE4 is greater than 0.0, set v3 = 1 and decrement it by FloatFieldAccessor(*(a1 + 0x40)) [field:this:0x000000E4, field:this:0x00000040, callee:0x00498730, source:raw]
    // CALL: Poll the session object: thiscall through the vtable at *(a1 + 0x40) entry 28 with (session object, 34, a2), result in v5 [field:this:0x00000040, field:*(this+0x40):0x00000000, field:*(*(this+0x40)+0x0):0x0000001C, source:raw]
    // GUARD: If v5 is non-zero and FieldGetter(v5) is negative, set v3 = 1 and mark v12[0] = 1 (failure flag) [callee:0x00489940, source:raw]
    // CALL: Dispatch through the object vtable at *(a1 + 0) entry 56 with (a1, dword read of v12) [field:this:0x00000000, source:raw]
    // GUARD: Failure path gate: if v3 is set, fill the buffer (v12[0] = byte_5EA438[0], memset the rest to 0, v13 = 0, v14 = 0) and translate EnumToEnumTranslator(dword_7CD25C, v12) into v6, requiring it to be non-zero [global:0x005EA438, global:0x007CD25C, callee:0x00462D30, source:raw]
    // CALL: sub_462DA0(v6) resolves the translated session id handle to a string v7 [callee:0x00462DA0, source:raw]
    // GUARD: If BinarySearchInStringTable(byte_5EC4C0, v7, byte_5EC4CC) finds the session id in the table, copy it back [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Store the resolved id: strcpy(byte_5EC4CC, v7) when v7 is non-null, else clear byte_5EC4CC[0] = 0 [global:0x005EC4CC, source:raw]
    // CALL: StringCopyWithBufferRealloc(byte_5EC4CC) normalizes the session id string into an owned buffer [callee:0x00566650, global:0x005EC4CC, source:raw]
    // CALL: LookupDispatch(aJoinFailurePag, -1) displays the join-failure page [callee:0x00497940, global:0x005C6D48, source:raw]
    // ASSIGNMENT: Clear the countdown timer: *(a1 + 0xE4) = 0 [field:this:0x000000E4, source:raw]
    // RETURN: Failure path returns -1 [source:raw]
    // GUARD: Success path gate: SessionStateCheck(dword_7CD25C) must equal 3 (session state compared via the obj+0x38 field) [callee:0x00461CD0, global:0x007CD25C, field:obj:0x00000038, source:raw]
    // CALL: FAILWRONGDESCRIPTION(v12) fills the diagnostic buffer with the session description [callee:0x00461550, source:raw]
    // GUARD: If UniqueID(dword_7CD25C, v12) yields a valid unique session id, proceed with the join sequence [callee:0x004630D0, global:0x007CD25C, source:raw]
    // LOOP: Nested diagnostic logging: while dword_7C569C != 5, StringSplitLoop(2, aDDevF119992002_28, 6802..6807) gates DebugLogWrite(&dword_8AD25C, message) for each of aJoinSessionWas, aSessionNameS, aSceneBaseS, aAiOppD, aHumanOppD, aMaxPlayersD [callee:0x004D7A50, callee:0x004D7AA0, global:0x007C569C, global:0x005C6824, global:0x008AD25C, global:0x005C6D08, global:0x005C6CEC, global:0x005C6CD4, global:0x005C6CBC, global:0x005C6CA4, global:0x005C6C8C, source:raw]
    // CALL: Second poll of the session object vtable entry 28 with (session object, 34), result in v9 [field:this:0x00000040, field:*(this+0x40):0x00000000, field:*(*(this+0x40)+0x0):0x0000001C, source:raw]
    // GUARD: If v9 is non-zero, StateCleanupNotification(v9) notifies it of the session state cleanup [callee:0x00489CB0, source:raw]
    // CALL: ShortComputation_e170() performs a short helper computation [callee:0x0046E170, source:raw]
    // CALL: PathPathRegistryWriter(&byte_7CE498) registers a path string [callee:0x004B1600, global:0x007CE498, source:raw]
    // CALL: SessionConfigWriteback((int)v12) writes the session configuration back from the diagnostic buffer [callee:0x00461900, source:raw]
    // CALL: sub_4A0AF0(&unk_7CE24C) resets the session related state object [callee:0x004A0AF0, global:0x007CE24C, source:raw]
    // LOOP: Vehicle slot walk: from unk_5EC6E4, call SessionStateTransition(-1, 0) and advance the cursor by 4656 until it reaches dword_7C54E4 [callee:0x004EF5A0, global:0x005EC6E4, global:0x007C54E4, source:raw]
    // ASSIGNMENT: Mark success and reset the vehicle count: v4 = 0, dword_5C329C = 0 [global:0x005C329C, source:raw]
    // CALL: BuildActiveVehiclePointerArray() rebuilds the array of active vehicle pointers [callee:0x0042BC80, source:raw]
    // ASSIGNMENT: Set join status flags: byte_7C5690 = 1, dword_7C56A0 = 2 [global:0x007C5690, global:0x007C56A0, source:raw]
    // CALL: LookupDispatch(aClientTeamSele, -1) navigates to the client team selection screen [callee:0x00497940, global:0x005C6590, source:raw]
    // ASSIGNMENT: Clear the countdown timer again: *(a1 + 0xE4) = 0 [field:this:0x000000E4, source:raw]
    // CALL: EmptyStub_0170(v12) performs a stubbed follow-up on the diagnostic buffer [callee:0x004B0170, source:raw]
    // RETURN: Returns v4 (0 on success, -1 on failure) [source:raw]

    // Conservative worker pseudocode:
    //   v3 = 0; v4 = -1;
    //   if (*(float*)(a1 + 0xE4) > 0.0f) { v3 = 1; *(float*)(a1 + 0xE4) -= FloatFieldAccessor(*(a1 + 0x40)); }
    //   v5 = vtbl(*(a1 + 0x40))[28 / 4](*(a1 + 0x40), 34, a2);
    //   if (v5 && FieldGetter(v5) < 0) { v3 = 1; v12[0] = 1; }
    //   vtbl(a1)[56 / 4](a1, *(int*)v12);
    //   if (v3) {
    //     v12[0] = byte_5EA438[0]; memset(v12 + 1, 0, 0x7C); v13 = 0; v14 = 0;
    //     v6 = EnumToEnumTranslator(dword_7CD25C, v12);
    //     if (v6) {
    //       v7 = sub_462DA0(v6);
    //       if (BinarySearchInStringTable(byte_5EC4C0, v7, byte_5EC4CC)) {
    //         if (v7) strcpy(byte_5EC4CC, v7); else byte_5EC4CC[0] = 0;
    //       }
    //       StringCopyWithBufferRealloc(byte_5EC4CC);
    //       LookupDispatch(aJoinFailurePag, -1);
    //       *(int*)(a1 + 0xE4) = 0;
    //       return -1;
    //     }
    //   } else if (SessionStateCheck(dword_7CD25C) == 3) {
    //     FAILWRONGDESCRIPTION(v12);
    //     if (UniqueID(dword_7CD25C, v12)) {
    //       if (dword_7C569C != 5) {
    //         if (StringSplitLoop(2, aDDevF119992002_28, 6802)) DebugLogWrite(&dword_8AD25C, aJoinSessionWas);
    //         if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_28, 6803)) DebugLogWrite(&dword_8AD25C, aSessionNameS);
    //         if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_28, 6804)) DebugLogWrite(&dword_8AD25C, aSceneBaseS);
    //         if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_28, 6805)) DebugLogWrite(&dword_8AD25C, aAiOppD);
    //         if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_28, 6806)) DebugLogWrite(&dword_8AD25C, aHumanOppD);
    //         if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_28, 6807)) DebugLogWrite(&dword_8AD25C, aMaxPlayersD);
    //       }
    //       v9 = vtbl(*(a1 + 0x40))[28 / 4](*(a1 + 0x40), 34);
    //       if (v9) StateCleanupNotification(v9);
    //       ShortComputation_e170();
    //       PathPathRegistryWriter(&byte_7CE498);
    //       SessionConfigWriteback((int)v12);
    //       sub_4A0AF0(&unk_7CE24C);
    //       for (v10 = &unk_5EC6E4; (int)v10 < (int)&dword_7C54E4; v10 += 4656) SessionStateTransition(-1, 0);
    //       v4 = 0; dword_5C329C = 0;
    //       BuildActiveVehiclePointerArray();
    //       byte_7C5690 = 1; dword_7C56A0 = 2;
    //       LookupDispatch(aClientTeamSele, -1);
    //       *(int*)(a1 + 0xE4) = 0;
    //     }
    //     EmptyStub_0170(v12);
    //   }
    //   return v4;
    // UNRESOLVED: Three read-only globals are flagged by packet facts but never appear in the raw decompiled source: flt_59E440, unk_5EC6D0, dword_7CD468
    // UNRESOLVED: The session object layout behind this+0x40 (vtable base and entry-28 method at offset 0x1C) and the obj+0x38 session state field are referenced via the packet but not defined in this function
    // UNRESOLVED: The meaning of the vtable call arguments (34) and the FieldGetter negative check is unresolved
    // UNRESOLVED: The stride 4656 loop from unk_5EC6E4 to dword_7C54E4 walks a fixed-size table, but the element type is not defined here
}
