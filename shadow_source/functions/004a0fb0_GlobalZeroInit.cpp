// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0FB0
// Canonical corpus name: GlobalZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalZeroInit_004a0fb0.c

void UnknownObject::GlobalZeroInit()
{
    // Resets five session-state globals to zero during a game restart. Writes 0 to dword_7CE250, dword_7CE258, byte_7CE260, byte_7CE269 and dword_7CE26C, then returns 0. Called by Game_Restart (0042D7A0).
    // ASSIGNMENT: dword_7CE250 is set to 0 (session-state doubleword) [global:0x007CE250, source:raw]
    // ASSIGNMENT: dword_7CE258 is set to 0 (session-state doubleword) [global:0x007CE258, source:raw]
    // ASSIGNMENT: byte_7CE260 is set to 0 (session-state byte flag) [global:0x007CE260, source:raw]
    // ASSIGNMENT: byte_7CE269 is set to 0 (session-state byte flag) [global:0x007CE269, source:raw]
    // ASSIGNMENT: dword_7CE26C is set to 0 (session-state doubleword) [global:0x007CE26C, source:raw]
    // RETURN: Returns 0 (result register carries the constant zero) [function:0x004A0FB0, source:raw]
    // CALL: Invoked by Game_Restart (0042D7A0) as part of the session/state reset path [caller:0x0042D7A0, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CE250 = 0;
    //   dword_7CE258 = 0;
    //   byte_7CE260 = 0;
    //   byte_7CE269 = 0;
    //   dword_7CE26C = 0;
    //   return 0;
    // UNRESOLVED: The individual meanings of the five reset globals (collision config, init guard, timer, etc.) come only from the fill's naming and are not independently determinable from this packet
}
