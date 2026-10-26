// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C130
// Canonical corpus name: DynMan_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynMan_Enter_0042c130.c

void UnknownObject::DynMan_Enter()
{
    // Dynamic management enter handler. Splits the build-path string aDDevF119992002_12 with delimiter 2 and maximum length 507 via StringSplitLoop; when that returns a non-zero byte value, writes the 'Entered DynMan Enter' message into the debug buffer at 0x008AD25C via DebugLogWrite. Unconditionally calls SeasonScoringReset and returns its result.
    // CALL: StringSplitLoop(2, aDDevF119992002_12, 507) processes the build-path string aDDevF119992002_12 with delimiter 2 and maximum length 507; the result is tested as an unsigned byte [callee:0x004D7A50, global:0x005C3334, source:raw]
    // GUARD: If the StringSplitLoop result (as unsigned byte) is non-zero, the debug log entry is written; otherwise the log is suppressed [source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredDynmanE) writes the 'Entered DynMan Enter' message aEnteredDynmanE (0x005C331C) into the debug buffer at 0x008AD25C [callee:0x004D7AA0, global:0x008AD25C, global:0x005C331C, source:raw]
    // CALL: SeasonScoringReset is invoked unconditionally; its return value becomes the function return value [source:raw]
    // RETURN: Returns the SeasonScoringReset result; the caller is Game_Enter (0x0042D370) [function:0x0042C130, caller:0x0042D370, source:raw]

    // Conservative worker pseudocode:
    //   if ((u8)StringSplitLoop(2, aDDevF119992002_12, 507)) {
    //     DebugLogWrite(&dword_8AD25C, aEnteredDynmanE);
    //   }
    //   return SeasonScoringReset();
    // UNRESOLVED: SeasonScoringReset appears in the raw decompiled source but the packet provides no address or evidence ref for it; its identity and address cannot be verified from this packet
    // UNRESOLVED: The meaning of delimiter 2 and maximum length 507 for the StringSplitLoop call is not documented
}
