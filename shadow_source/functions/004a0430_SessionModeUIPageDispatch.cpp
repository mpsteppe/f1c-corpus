// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0430
// Canonical corpus name: sub_4A0430
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0430_004a0430.c

void UnknownObject::SessionModeUIPageDispatch()
{
    // Dispatches a UI page lookup based on the mode value at dword_7D0410. Modes up to 4 open the monitor page (aMonitorpage); mode 5 opens either the multiplayer host grid (aMphostgrid) or client grid (aMpclientgrid) depending on StateCheckWrapper's result for the module manager at dword_7CD25C. All page lookups go through LookupDispatch with the dispatch interface pointer at dword_7CD8C0 and a -1 flag; every path returns 0.
    // GUARD: When the mode value at dword_7D0410 is not positive the function returns 0 immediately without any dispatch [global:0x007D0410, source:raw]
    // GUARD: When the mode value at dword_7D0410 is at most 4 the monitor page path is taken [global:0x007D0410, source:raw]
    // CALL: LookupDispatch opens the monitor page name aMonitorpage through the dispatch interface at dword_7CD8C0 with a -1 flag, then returns 0 [callee:0x00497940, global:0x005C6BD4, global:0x007CD8C0, source:raw]
    // GUARD: When the mode value at dword_7D0410 is not exactly 5 the function returns 0 without any dispatch [global:0x007D0410, source:raw]
    // CALL: StateCheckWrapper tests the module manager state at dword_7CD25C to decide between the host and client grid page [callee:0x00461DC0, global:0x007CD25C, source:raw]
    // CALL: When the state check passes, LookupDispatch opens the multiplayer host grid page aMphostgrid through the dispatch interface at dword_7CD8C0 with a -1 flag [callee:0x00497940, global:0x005C6BC8, global:0x007CD8C0, source:raw]
    // CALL: When the state check fails, LookupDispatch opens the multiplayer client grid page aMpclientgrid through the dispatch interface at dword_7CD8C0 with a -1 flag [callee:0x00497940, global:0x005C5F5C, global:0x007CD8C0, source:raw]
    // RETURN: Every control-flow path returns 0 [function:0x004A0430, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0410 <= 0) return 0;
    //   if (dword_7D0410 <= 4) {
    //     LookupDispatch(dword_7CD8C0, aMonitorpage, -1);
    //     return 0;
    //   }
    //   if (dword_7D0410 != 5) return 0;
    //   if (StateCheckWrapper(dword_7CD25C))
    //     LookupDispatch(dword_7CD8C0, aMphostgrid, -1);
    //   else
    //     LookupDispatch(dword_7CD8C0, aMpclientgrid, -1);
    //   return 0;
    // UNRESOLVED: The exact page-name strings aMonitorpage, aMphostgrid and aMpclientgrid are string globals; their full literal content is not present in this packet
    // UNRESOLVED: The -1 flag meaning passed to LookupDispatch and the details of StateCheckWrapper's state check are not documented in this packet
}
