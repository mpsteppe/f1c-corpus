// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042CF10
// Canonical corpus name: MultiplayerVehiclePlacement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiplayerVehiclePlacement_0042cf10.c

void UnknownObject::MultiplayerVehiclePlacement()
{
    // Multiplayer session placement state machine (this[2], values 0-7). When the session is active (SessionStateCheckWrapper(&dword_7CD25C) non-zero): if the StateCheckWrapper flag is set and this[2] == 5, copy fields of every vehicle in dword_7C54F0 at offset +16436 via FieldCopy; when transitioning to state 7, optionally dev-log, reorder championship standings (ChampionshipStandingsReOrdering or sub_462E20 on dword_7CD25C), FieldCopy_c330 every vehicle, and call sub_4C6F10 on each vehicle. When the session is not active: apply transition predicates between current this[2] and target a2 (plain targets 2/3/4, or 4->5, 5->6, 6->7), calling sub_4C01A0 for non-session targets and the 4->5 case, FieldCopy for 5->6 when byte_7CEBC4 or championship mode dword_7D0410==4 (plus ConditionalSeasonDataFree(1) when championship), and FieldCopy_c330 for 6->7. Always stores the new state into this[2] and dword_7D00EC, clamping it to [dword_7D00F4, dword_7D00F8], and returns the previous value of dword_7D00F4.
    // GUARD: Session active? If (unsigned __int8)SessionStateCheckWrapper(&dword_7CD25C) is non-zero, enter the active-session branch. [callee:0x00461DB0, global:0x007CD25C]
    // CALL: v11 = StateCheckWrapper(&dword_7CD25C) captures the session-active flag for later use. [callee:0x00461DC0, global:0x007CD25C]
    // GUARD: If v11 is set and this[2] == 5, loop i < dword_5C329C calling FieldCopy(dword_7C54F0[i] + 16436) on each vehicle. [guard:0, field:this:0x00000008, callee:0x004BC320, global:0x005C329C, global:0x007C54F0]
    // GUARD: On transition to state a2 == 7: if dword_7C569C != 5 and StringSplitLoop(2, aDDevF119992002_11, 215) is non-zero, write a debug line via DebugLogWrite(&dword_8AD25C, aMultiplayerMod). [global:0x007C569C, callee:0x004D7A50, global:0x005C3590, callee:0x004D7AA0, global:0x008AD25C, global:0x005C355C]
    // CALL: If v11, ChampionshipStandingsReOrdering(&dword_7CD25C); otherwise sub_462E20(&dword_7CD25C). [callee:0x00462A10, callee:0x00462E20, global:0x007CD25C]
    // LOOP: Loop j < dword_5C329C calling FieldCopy_c330(dword_7C54F0[j] + 16436) on every vehicle. [callee:0x004BC330, global:0x005C329C, global:0x007C54F0]
    // LOOP: If the vehicle count snapshot is > 0, loop v15 < dword_5C329C calling sub_4C6F10(dword_7C54F0[v15]) on each vehicle. [callee:0x004C6F10, global:0x005C329C, global:0x007C54F0]
    // CALCULATION: Compute transition predicates in the inactive-session branch: v4 = a2 is 2, 3 or 4; v6 = this[2]==4 && a2==5; v7 = this[2]==5 && a2==6; v8 = this[2]==6 && a2==7. [field:this:0x00000008]
    // CALL: If v4 (a2 in {2,3,4}) or v6 (4->5), call sub_4C01A0(&a2). [callee:0x004C01A0]
    // GUARD: Else if v7 (5->6) and (byte_7CEBC4 or dword_7D0410 == 4): loop FieldCopy(dword_7C54F0[k] + 16436) over all vehicles; if dword_7D0410 == 4 also ConditionalSeasonDataFree(1). [callee:0x004BC320, global:0x007CEBC4, global:0x007D0410, callee:0x004C2830, global:0x005C329C, global:0x007C54F0]
    // LOOP: Else if v8 (6->7): loop m < dword_5C329C calling FieldCopy_c330(dword_7C54F0[m] + 16436). [callee:0x004BC330, global:0x005C329C, global:0x007C54F0]
    // STATE_TRANSITION: Commit the transition: this[2] = a2, and dword_7D00EC = a2 clamped into [dword_7D00F4, dword_7D00F8] (upper clamp when a2 > dword_7D00F8, lower clamp when a2 < dword_7D00F4). [field:this:0x00000008, global:0x007D00EC, global:0x007D00F4, global:0x007D00F8]
    // RETURN: Return the previous value of dword_7D00F4 read before the clamp. [global:0x007D00F4]

    // Conservative worker pseudocode:
    //   if (SessionStateCheckWrapper(&dword_7CD25C)) {
    //     v11 = StateCheckWrapper(&dword_7CD25C);
    //     if (v11 && this[2] == 5) for (i = 0; i < dword_5C329C; i++) FieldCopy(dword_7C54F0[i] + 16436);
    //     if (a2 == 7) {
    //       if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_11, 215)) DebugLogWrite(&dword_8AD25C, aMultiplayerMod);
    //       if (v11) ChampionshipStandingsReOrdering(&dword_7CD25C); else sub_462E20(&dword_7CD25C);
    //       for (j = 0; j < dword_5C329C; j++) FieldCopy_c330(dword_7C54F0[j] + 16436);
    //       for (v15 = 0; v15 < dword_5C329C; v15++) sub_4C6F10(dword_7C54F0[v15]);
    //     }
    //   } else {
    //     v4 = a2==2 || a2==3 || a2==4; v6 = this[2]==4 && a2==5;
    //     v7 = this[2]==5 && a2==6; v8 = this[2]==6 && a2==7;
    //     if (v4 || v6) sub_4C01A0(&a2);
    //     else if (v7) { if (byte_7CEBC4 || dword_7D0410 == 4) { for (...) FieldCopy(...); if (dword_7D0410 == 4) ConditionalSeasonDataFree(1); } }
    //     else if (v8) for (m = 0; m < dword_5C329C; m++) FieldCopy_c330(dword_7C54F0[m] + 16436);
    //   }
    //   this[2] = a2; dword_7D00EC = clamp(a2, dword_7D00F4, dword_7D00F8); return old_dword_7D00F4;
    // UNRESOLVED: Global dword_7D2DB0 (race-standings sort buffer per existing analysis) is listed as read but never referenced in the raw source; exact use is not evidenced by this packet.
    // UNRESOLVED: sub_462E20 is the non-active-session counterpart of ChampionshipStandingsReOrdering; its semantics are unknown.
    // UNRESOLVED: sub_4C01A0 receives the address of the local a2, so any mutation of a2 by it is invisible in this decompilation.
    // UNRESOLVED: The 16436 vehicle-struct offset and the transition-state meanings (values 0-7) are only partially evidenced; the state enum is DERIVED from the guard and caller context.
}
