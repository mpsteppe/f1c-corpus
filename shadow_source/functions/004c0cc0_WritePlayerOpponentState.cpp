// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0CC0
// Canonical corpus name: PlayerOpponentStateWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerOpponentStateWriter_004c0cc0.c

void UnknownObject::WritePlayerOpponentState()
{
    // Writes career/season state for the player and each active opponent into the output text buffer a2: appends season-status, race-session, race-over and current-race keys via BufferWriteWithStringLengthCheck, writes the 'Player' section (aPlayer) via SettingsIniFileWriter from this+44908, then loops over 103 opponent slots with stride 436, writing an indexed opponent section (format aS22d_0, base key aOpponent) for every slot whose active flag at this+0x1B0 is set. When path argument a3 is set, resolves a3 and the separator token word_5C30B4 first, and appends word_5C30B4 as a closing separator at the end. Returns 0.
    // GUARD: When the output buffer's first dword (*a2) is zero, do nothing and skip the whole write. [source:raw]
    // CALL: When path argument a3 is non-null, resolve it with ResourceLookupWithDualPath and also resolve the separator token word_5C30B4 with ResourceLookupWithDualPath. [callee:0x00566CF0, global:0x005C30B4, source:raw]
    // CALL: Append the season-status key (aSeasonstatusD) to the output buffer with BufferWriteWithStringLengthCheck. [callee:0x00566C30, global:0x005D28A0, source:raw]
    // CALL: Append the race-session key (aRacesessionD) to the output buffer with BufferWriteWithStringLengthCheck. [callee:0x00566C30, global:0x005D2890, source:raw]
    // CALL: Append the race-over key (aRaceoverD) to the output buffer with BufferWriteWithStringLengthCheck. [callee:0x00566C30, global:0x005D2880, source:raw]
    // CALL: Append the current-race key (aCurrentraceD) to the output buffer with BufferWriteWithStringLengthCheck. [callee:0x00566C30, global:0x005D2870, source:raw]
    // CALL: Write the 'Player' section (aPlayer) via SettingsIniFileWriter using the state block at this+44908 (0xAF6C) as its source object. [callee:0x004C0690, global:0x005D284C, source:raw]
    // LOOP: Loop over 103 opponent slots: when the active flag byte at this+0x1B0 is set, format an indexed section name with StringFormatWithBufferOverflowCheck using '%s%2.2d]' (aS22d_0), base key aOpponent and index i, then write that section via SettingsIniFileWriter from this; advance this by 436 (0x1B4) per iteration. [field:this:0x000001B0, callee:0x0058815F, callee:0x004C0690, global:0x005D2864, global:0x005D2858, source:raw]
    // CALL: Append the closing separator token word_5C30B4 to the output buffer with BufferWriteWithStringLengthCheck. [callee:0x00566C30, global:0x005C30B4, source:raw]
    // RETURN: Return 0 on all paths. [source:raw]

    // Conservative worker pseudocode:
    //   char WritePlayerOpponentState(int this, _DWORD* a2, int a3) {
    //     if (!*a2) return 0;
    //     if (a3) {
    //       ResourceLookupWithDualPath(a3);
    //       ResourceLookupWithDualPath(&word_5C30B4);
    //     }
    //     BufferWriteWithStringLengthCheck(a2, aSeasonstatusD);
    //     BufferWriteWithStringLengthCheck(a2, aRacesessionD);
    //     BufferWriteWithStringLengthCheck(a2, aRaceoverD);
    //     BufferWriteWithStringLengthCheck(a2, aCurrentraceD);
    //     SettingsIniFileWriter((int*)(this + 44908), a2, (int)aPlayer);
    //     char v6[32];
    //     for (int i = 0; i < 103; ++i) {
    //       if (*(_BYTE*)(this + 432)) {
    //         StringFormatWithBufferOverflowCheck(v6, "%s%2.2d]", aOpponent, i);
    //         SettingsIniFileWriter((int*)this, a2, (int)v6);
    //       }
    //       this += 436;
    //     }
    //     BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
    //     return 0;
    //   }
    // UNRESOLVED: The active-flag byte at this+0x1B0 is read once per 436-byte stride, implying an array of 103 records; the record layout beyond the flag byte is not evidenced in this packet.
    // UNRESOLVED: The player state block at this+44908 (0xAF6C) has no field evidence entry in this packet; its byte offset is DERIVED from the raw source text only.
    // UNRESOLVED: The exact semantics of ResourceLookupWithDualPath's dual-path resolution and of the separator token word_5C30B4 are inferred, not independently evidenced.
    // UNRESOLVED: The legacy ABI name Player_Opponent_State_Writer is supplied by the packet but is not corroborated by static evidence here.
}
