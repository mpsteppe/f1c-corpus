// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1820
// Canonical corpus name: PlayerFile_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerFile_Enter_004b1820.c

void UnknownObject::PlayerFileEnter()
{
    // Player-file handler entry. When StringSplitLoop(2, aDDevF119992002_20, 2463) reports verbose debug enabled, writes a debug line to the buffer dword_8AD25C with message aEnteredPlayerf via DebugLogWrite. Then stores the vehicle-data global pointer unk_5EC6D8 into this+0x49B0 and returns the result of PlayerNameNeverUsedProfileFileCreateRead on this.
    // GUARD: When StringSplitLoop(2, aDDevF119992002_20, 2463) is non-zero (verbose debug enabled), take the logging branch. [callee:0x004D7A50, global:0x005D22E0]
    // CALL: Write the debug line using the message buffer dword_8AD25C and the string literal aEnteredPlayerf via DebugLogWrite. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D2334]
    // ASSIGNMENT: Set this+0x49B0 to the vehicle-data global pointer unk_5EC6D8. [field:this:0x000049B0, global:0x005EC6D8]
    // CALL: Initialize the player profile by calling PlayerNameNeverUsedProfileFileCreateRead on this; the target is named only in the raw source and the packet does not list it among callees. [function:0x004B1820, source:raw]
    // RETURN: Return the profile-create/read call result. [function:0x004B1820, source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_20, 2463))
    //       DebugLogWrite(&dword_8AD25C, aEnteredPlayerf);
    //   this[0x49B0] = &unk_5EC6D8;
    //   return PlayerNameNeverUsedProfileFileCreateRead(this);
    // UNRESOLVED: The final call target PlayerNameNeverUsedProfileFileCreateRead appears in the raw source but has no callee evidence ref in this packet, so it cannot be cross-checked statically here.
    // UNRESOLVED: aDDevF119992002_20 and aEnteredPlayerf are string-literal globals whose exact text is not visible in this packet.
}
