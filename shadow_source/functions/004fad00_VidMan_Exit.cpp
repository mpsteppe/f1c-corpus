// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAD00
// Canonical corpus name: VidMan_Exit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VidMan_Exit_004fad00.c

void UnknownObject::VidMan_Exit()
{
    // Video manager exit handler. Optionally logs an exit message (guarded on StringSplitLoop formatting the message buffer with a path prefix and literal 1457), then shuts down the collision system via CollisionSystemShutdownCleanup, dispatches the race time delta handle through GlobalDispatch, runs two cleanup subroutines (sub_4A1830 called before and after sub_4A14E0), and finally frees the race time delta global (dword_8AFE64) through TestAndFreeWrapper when it is non-null, clearing it to 0. Returns the resulting value (the freed handle, or 0 once cleared). Called by GameExit (0042DB20).
    // GUARD: If StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1457) is non-zero, proceed with the debug log write [callee:0x004D7A50, global:0x008AD25C, global:0x005D6DC4, source:raw]
    // CALL: DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanE_0) writes the formatted exit message when the guard passes [callee:0x004D7AA0, global:0x008AD25C, global:0x005D6EE8, source:raw]
    // CALL: CollisionSystemShutdownCleanup() shuts down the collision detection system [callee:0x00494900, source:raw]
    // CALL: GlobalDispatch(dword_8AFE64) dispatches the race time delta handle [callee:0x0055C040, global:0x008AFE64, source:raw]
    // CALL: First call to sub_4A1830(), an unnamed cleanup routine [callee:0x004A1830, source:raw]
    // CALL: sub_4A14E0(), an unnamed cleanup routine [callee:0x004A14E0, source:raw]
    // CALL: Second call to sub_4A1830(), an unnamed cleanup routine run again after sub_4A14E0 [callee:0x004A1830, source:raw]
    // ASSIGNMENT: result = dword_8AFE64 captures the handle value before the free guard [global:0x008AFE64, source:raw]
    // GUARD: If dword_8AFE64 is non-null, free it and clear the global [global:0x008AFE64, callee:0x0053D4C0, source:raw]
    // CALL: TestAndFreeWrapper(&dword_8AFE64) frees the allocated race time delta memory and returns the outcome into result [callee:0x0053D4C0, global:0x008AFE64, source:raw]
    // ASSIGNMENT: dword_8AFE64 = 0 clears the handle after the free [global:0x008AFE64, source:raw]
    // RETURN: Returns result (the freed handle value, or 0 once dword_8AFE64 is cleared); invoked by GameExit (0042DB20) [function:0x004FAD00, caller:0x0042DB20, source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1457))
    //       DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanE_0);
    //   CollisionSystemShutdownCleanup();
    //   GlobalDispatch(dword_8AFE64);
    //   sub_4A1830();
    //   sub_4A14E0();
    //   sub_4A1830();
    //   result = dword_8AFE64;
    //   if (dword_8AFE64) {
    //       result = TestAndFreeWrapper(&dword_8AFE64);
    //       dword_8AFE64 = 0;
    //   }
    //   return result;
    // UNRESOLVED: sub_4A1830 and sub_4A14E0 are unnamed in the packet; their exact cleanup roles are unknown
    // UNRESOLVED: Globals 007CDE00 and 007CE2A4 are flagged read-only by packet facts but never appear in the raw source of this function; they are presumably read inside callees
    // UNRESOLVED: Return value consumer: GameExit (0042DB20) does not reveal whether the return value (handle or 0) is meaningful
    // UNRESOLVED: Literal 1457 in the StringSplitLoop call has no documented meaning in this packet
}
