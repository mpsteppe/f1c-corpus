// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FC30
// Canonical corpus name: sub_46FC30
// Owner: MenuPageRouter [DERIVED]
// Raw source: functions/sub_46FC30_0046fc30.c

void MenuPageRouter::SessionStateUIScreenRouter()
{
    // Routes the session to a UI screen based on the race-mode global at 0x7D0410: championship (4) navigates to the post-race driver screen, multiplayer (5) navigates to the host or client grid depending on a state check, and anything else falls back to the main menu and resets the session-init global. Optionally stops the sound engine and resets a buffer before routing.
    // GUARD: If the sound-engine pointer at dword_5EB10C is non-null, invoke its vtable method at offset 12 to stop the sound engine. [global:0x005EB10C, source:raw]
    // CALL: Reset the buffer at flt_5EA618 via BufferInitWith10fDefaults before deciding which screen to show. [callee:0x004186A0, global:0x005EA618]
    // GUARD: Branch on dword_7D0410 equal to 4, selecting the championship post-race path. [global:0x007D0410]
    // CALL: Championship path: call sub_4A0760, then GuardedFunctionDispatch(this, aChPostracedriv) to open the post-race driver screen, and return 0. [callee:0x004A0760, callee:0x00486AA0, global:0x005C6DF8]
    // GUARD: Else if dword_7D0410 equals 5, select the multiplayer path. [global:0x007D0410]
    // GUARD: Multiplayer path: StateCheckWrapper(dword_7CD25C) decides whether the local machine acts as host or client. [callee:0x00461DC0, global:0x007CD25C]
    // CALL: Host branch: LookupDispatch(dword_7CD8C0, aMphostgrid, -1) to open the host grid screen, then return 0. [callee:0x00497940, global:0x007CD8C0, global:0x005C6BC8]
    // CALL: Client branch: LookupDispatch(dword_7CD8C0, aMpclientgrid, -1) to open the client grid screen, then return 0. [callee:0x00497940, global:0x007CD8C0, global:0x005C5F5C]
    // GUARD: Fallback path: GuardedFunctionDispatch(this, aMainMenu), set the session-init global dword_5CC9E8 to 3, and return 0. [callee:0x00486AA0, global:0x005BE708, global:0x005CC9E8]

    // Conservative worker pseudocode:
    //   int SessionStateUIScreenRouter() {
    //     if (dword_5EB10C) (*(void(**)(int))(*(DWORD*)dword_5EB10C+12))(dword_5EB10C);
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     if (dword_7D0410 == 4) { sub_4A0760(); GuardedFunctionDispatch(this, aChPostracedriv); return 0; }
    //     if (dword_7D0410 == 5) {
    //       LookupDispatch(dword_7CD8C0, StateCheckWrapper(dword_7CD25C) ? aMphostgrid : aMpclientgrid, -1);
    //       return 0;
    //     }
    //     GuardedFunctionDispatch(this, aMainMenu); dword_5CC9E8 = 3; return 0;
    //   }
    // UNRESOLVED: The global at 0x7CE24C is listed in the packet facts but does not appear in the raw function text; its role in this function is unknown.
    // UNRESOLVED: Screen name strings aMainMenu, aChPostracedriv, aMphostgrid and aMpclientgrid are referenced by address; their exact UI identities are not independently verified.
    // UNRESOLVED: Meaning of the session-init value 3 assigned to dword_5CC9E8 is not established.
}
