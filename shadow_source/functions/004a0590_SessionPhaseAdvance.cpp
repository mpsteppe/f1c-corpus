// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0590
// Canonical corpus name: sub_4A0590
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0590_004a0590.c

void UnknownObject::SessionPhaseAdvance()
{
    // Advances the multiplayer session to the next phase. Reads the session-type global dword_7C56A4 and maps phases 1..6 to their successors 2..7 (any other value returns 1 via the default branch), then calls MultiplayerVehiclePlacement with the base pointer dword_7C569C and the newly computed phase. In race mode (dword_7D0410 == 4) it additionally dereferences the standings buffer dword_7D2DB0; when the cached session type was 7 it checks session activity through SessionActiveCheck, otherwise it advances the pit-stop phase with PitStopPhaseAdvance.
    // ASSIGNMENT: Cache the current session type from dword_7C56A4 into v1. [global:0x007C56A4, source:raw]
    // STATE_TRANSITION: Dispatch on dword_7C56A4 through the jump table jpt_4A05A7 mapping each phase to its successor: 1 to 2, 2 to 3, 3 to 4, 4 to 5, 5 to 6, 6 to 7. [global:0x007C56A4, global:0x004A0618, source:raw]
    // CALL: Call MultiplayerVehiclePlacement with the base pointer dword_7C569C and the computed next phase value. [callee:0x0042CF10, global:0x007C569C, source:raw]
    // GUARD: Return 0 immediately when dword_7D0410 (race-mode selector) is not 4. [global:0x007D0410, source:raw]
    // CALL: Dereference the standings buffer dword_7D2DB0 through LinkedListDereference to obtain the vehicle node. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: Return 0 when the dereferenced standings node is null. [source:raw]
    // GUARD: Branch on the cached session type v1: when it equals 7 take the session-active path, otherwise the pit-stop path. [source:raw]
    // CALL: At phase 7 call SessionActiveCheck(this) to verify the session is still active. [callee:0x004A09A0, source:raw]
    // CALL: For phases below 7 call PitStopPhaseAdvance on the standings node. [callee:0x004C15A0, source:raw]
    // RETURN: The default switch branch returns the preloaded result 1 for any unrecognized session type. [source:raw]

    // Conservative worker pseudocode:
    //   int SessionPhaseAdvance() {
    //     int cachedType = g_sessionType;
    //     switch (g_sessionType) {
    //       case 1: MultiplayerVehiclePlacement(&g_sessionBase, 2); break;
    //       case 2: MultiplayerVehiclePlacement(&g_sessionBase, 3); break;
    //       case 3: MultiplayerVehiclePlacement(&g_sessionBase, 4); break;
    //       case 4: MultiplayerVehiclePlacement(&g_sessionBase, 5); break;
    //       case 5: MultiplayerVehiclePlacement(&g_sessionBase, 6); break;
    //       case 6: MultiplayerVehiclePlacement(&g_sessionBase, 7); break;
    //       default: return 1;
    //     }
    //     if (g_raceMode != 4) return 0;
    //     node = LinkedListDereference(&g_standings);
    //     if (!node) return 0;
    //     if (cachedType == 7) SessionActiveCheck(this);
    //     else PitStopPhaseAdvance(node);
    //     return 0;
    //   }
    // UNRESOLVED: The exact semantics of the session-type values 1..7 (other than 7 being the final phase sentinel) are not established by this packet.
    // UNRESOLVED: The structure behind the base pointer dword_7C569C passed to MultiplayerVehiclePlacement is unnamed.
    // UNRESOLVED: Why race mode 4 alone proceeds to the standings dereference is not explained by this packet.
}
