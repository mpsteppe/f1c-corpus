// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C1A0
// Canonical corpus name: DynMan_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynMan_Init_0042c1a0.c

void UnknownObject::DynMan_Init()
{
    // Dynamic Manager initialization, called once from Game_Init. Scans the static vehicle array to select the player vehicle slot, sets the player vehicle index (with an all-slots-occupied fallback), conditionally loads AI driver names and count, branches between default and formation-lap AI setup based on init state and mode flags, rebuilds the active vehicle pointer array, drives the loading progress bar while loading vehicle graphics scenes, sets up the player name, and finally loads AI driver names from config for the current vehicle when its driver-name field is still null.
    // GUARD: Debug guard: when StringSplitLoop(2, aDDevF119992002_12, 525) returns non-zero, write the entry message aEnteredDynmanI to the debug buffer dword_8AD25C via DebugLogWrite. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C3334, global:0x005C3374, global:0x008AD25C, source:raw]
    // CALL: sub_40FE50(dword_5EA560): initialize the global instance identified by dword_5EA560. [callee:0x0040FE50, global:0x005EA560, source:raw]
    // ASSIGNMENT: Scan setup: v0 = dword_7D0410, v1 = 0, v2 = &dword_5EF9A0 (first vehicle slot). [global:0x007D0410, global:0x005EF9A0, source:raw]
    // LOOP: Iterate vehicle slots starting at dword_5EF9A0, advancing v2 by 4656 dwords per slot, until v2 reaches the sentinel pointer dword_7C87A0. [global:0x005EF9A0, global:0x007C87A0, source:raw]
    // ASSIGNMENT: During the scan, when dword_7D0410 != 4, write the slot field v2[868] = v1 + 1 (store the slot index in the slot). [global:0x007D0410, source:raw]
    // GUARD: Break the scan when *v2 == 0 (empty slot); the current v1 then identifies the empty slot chosen as the player vehicle. [global:0x005EF9A0, source:raw]
    // CALL: SetPlayerVehicleIndex(v1) and SetPlayerVehicleIndex_bc40(v3): register the selected index as the player vehicle (v3 is an uninitialized edx register in the raw listing). [callee:0x0042BBD0, callee:0x0042BC40, source:raw]
    // STATE_TRANSITION: If the scan found no empty slot (v1 == 104, all slots occupied), fall back to player vehicle index 0 through both setters. [callee:0x0042BBD0, callee:0x0042BC40, source:raw]
    // ASSIGNMENT: v4 = (dword_7C56A4 == 1 || dword_7C56A4 == 2 || dword_7C56A4 == 3 || dword_7C56A4 == 4): session-type mask used to gate formation-lap AI setup. [global:0x007C56A4, source:raw]
    // GUARD: First-init branch: when byte_7C5690 == 0, populate the 512-byte buffer v14 via sub_4B1520(v0, v14, 512) and configure the AI driver count via AIDriverCountSetup(v14). [global:0x007C5690, callee:0x004B1520, callee:0x004BFD90, source:raw]
    // GUARD: Within first-init, if dword_7D0410 != 3 or byte_7CEBC4 == 0, run the default AI setup sub_4BFF70(v11) and skip the formation-lap path. [global:0x007D0410, global:0x007CEBC4, callee:0x004BFF70, source:raw]
    // STATE_TRANSITION: Formation-lap path: when already initialized (byte_7C5690 != 0) and dword_7D0410 == 4 and the session mask v4 is set, run sub_4C01A0(v11); this label also joins the first-init formation-lap case. [callee:0x004C01A0, global:0x007D0410, global:0x007C56A4, source:raw]
    // CALL: BuildActiveVehiclePointerArray(): rebuild the active-vehicle pointer array. [callee:0x0042BC80, source:raw]
    // CALCULATION: v5 = (double)dword_5C329C * 1.5 + 113.0: derive the loading-progress upper bound from the vehicle count. [global:0x005C329C, source:raw]
    // CALL: sub_5895A2(v5): set the loading progress bar range to v5. [callee:0x005895A2, source:raw]
    // CALL: sub_4F9480(101.0): set the initial loading progress position; v13 = v5 - 101.0 is the per-vehicle progress span. [callee:0x004F9480, source:raw]
    // LOOP: For v6 from 0 while v6 < dword_5C329C: call VehgenScnFileLoader(1) to load each vehicle's scene, then advance the progress bar to v9 = (double)v6 / (double)dword_5C329C * v13 + 101.0 via sub_4F9480(v9). [callee:0x004C6C40, callee:0x004F9480, global:0x005C329C, source:raw]
    // CALCULATION: Recompute v7 = (double)dword_5C329C * 1.5 + 113.0, then finalize with sub_5895A2(v7) and sub_4F9480(v7). [callee:0x005895A2, callee:0x004F9480, global:0x005C329C, source:raw]
    // CALL: PlayerNameSetup(&dword_7C73E0): set up the player name from the module callback table. [callee:0x004326E0, global:0x007C73E0, source:raw]
    // GUARD: Tail guard: result = dword_7C54E4; when dword_7C54E4 < 0x68 and the vehicle's driver-name field at offset 13000 is null, return LoadAIDriverNamesFromConfig(dword_7C54E4). [global:0x007C54E4, global:0x007C54F0, callee:0x004336F0, source:raw]
    // RETURN: Return result (dword_7C54E4) when the tail guard does not fire. [source:raw]

    // Conservative worker pseudocode:
    //   // DynMan init; addresses and literals from the evidence packet.
    //   if (StringSplitLoop(2, aDDevF119992002_12, 525)) DebugLogWrite(&dword_8AD25C, aEnteredDynmanI);
    //   sub_40FE50(dword_5EA560);
    //   for (v1 = 0, v2 = &dword_5EF9A0; v2 < dword_7C87A0; v2 += 4656, ++v1) {
    //       if (dword_7D0410 != 4) v2[868] = v1 + 1;
    //       if (*v2 == 0) break;
    //   }
    //   if (v1 == 104) v1 = 0;
    //   SetPlayerVehicleIndex(v1); SetPlayerVehicleIndex_bc40(v1);
    //   if (byte_7C5690 == 0) {
    //       sub_4B1520(dword_7D0410, v14, 512); AIDriverCountSetup(v14);
    //       if (dword_7D0410 != 3 || byte_7CEBC4 == 0) sub_4BFF70(v11);
    //       else sub_4C01A0(v11);
    //   } else if (dword_7D0410 == 4 && (dword_7C56A4 >= 1 && dword_7C56A4 <= 4)) {
    //       sub_4C01A0(v11);
    //   }
    //   BuildActiveVehiclePointerArray();
    //   v5 = dword_5C329C * 1.5 + 113.0;
    //   sub_5895A2(v5); sub_4F9480(101.0);
    //   for (v6 = 0; v6 < dword_5C329C; ++v6) {
    //       VehgenScnFileLoader(1);
    //       sub_4F9480((double)v6 / dword_5C329C * (v5 - 101.0) + 101.0);
    //   }
    //   sub_5895A2(v5); sub_4F9480(v5);
    //   PlayerNameSetup(&dword_7C73E0);
    //   if (dword_7C54E4 < 0x68 && !*(_DWORD*)(dword_7C54F0[dword_7C54E4] + 13000))
    //       return LoadAIDriverNamesFromConfig(dword_7C54E4);
    //   return dword_7C54E4;
    // UNRESOLVED: flt_59E8A4, flt_59E9D0 and flt_59E9D4 are marked read in the packet but do not appear in the raw listing; their role in this function is unknown.
    // UNRESOLVED: dword_7C73E8 and byte_7CE498 are marked read in the packet but do not appear in the raw listing; their role here is unknown.
    // UNRESOLVED: v3 (edx) passed to SetPlayerVehicleIndex_bc40 is uninitialized in the raw listing, likely a Hex-Rays artifact.
    // UNRESOLVED: v12 = ++v6 is assigned but never read in the visible listing.
    // UNRESOLVED: dword_7D0410 values 3 and 4 gate different AI-setup branches; the fill labels it ChampionshipMode/RaceMode but the exact enum is not in the packet.
    // UNRESOLVED: The distinction between sub_4BFF70 (default AI setup) and sub_4C01A0 (formation-lap AI setup) is DERIVED from the existing analysis fill, not the raw listing.
    // UNRESOLVED: Offset 13000 in the vehicle object at dword_7C54F0[dword_7C54E4] is asserted by the raw listing to hold the driver-name field; its type is not confirmed in this packet.
}
