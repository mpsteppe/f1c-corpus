// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042CA70
// Canonical corpus name: DynMan_Exit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynMan_Exit_0042ca70.c

void UnknownObject::DynManExit()
{
    // Exit path for the DynMan (Dynamic Manager) subsystem, invoked from the game shutdown path (GameExit). Calls StringSplitLoop(2, aDDevF119992002_12, 953) to run a build-path string parsing/log step; if that returns a non-zero status it writes the debug message 'entered DynManExit' through DebugLogWrite using the DebugMessageBuffer global, and returns the write status; otherwise it returns the StringSplitLoop result unchanged.
    // CALL: Call StringSplitLoop(2, aDDevF119992002_12, 953), storing the status into result. The second argument is the global build-path string (0x005C3334) and the third is literal 953. [callee:0x004D7A50, global:0x005C3334, abi:lead, source:raw]
    // GUARD: Branch on the low byte of result: a non-zero low byte selects the debug-log branch, otherwise execution falls through to return result. [function:0x0042CA70, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredDynmanE_0), writing the 'entered DynManExit' entry message to the debug message buffer at 0x008AD25C. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C34B0, source:raw]
    // RETURN: Return DebugLogWrite's result on the guarded path; on the fall-through path return the original StringSplitLoop result. [function:0x0042CA70, source:raw]
    // CALL: Called by GameExit (0x0042DB20) during the game shutdown sequence. [caller:0x0042DB20]

    // Conservative worker pseudocode:
    //   int DynManExit() {
    //     int result = StringSplitLoop(2, aDDevF119992002_12, 953);
    //     if ((unsigned char)result)
    //       return DebugLogWrite(&dword_8AD25C, aEnteredDynmanE_0);
    //     return result;
    //   }
    // UNRESOLVED: Semantics of StringSplitLoop's three arguments (2, build-path string, literal 953) are not established by this packet; only the call shape is known.
    // UNRESOLVED: Purpose of checking only the low byte of the StringSplitLoop status is unexplained by this packet.
    // UNRESOLVED: Content of aDDevF119992002_12 and the exact debug message text are not present in the packet.
}
