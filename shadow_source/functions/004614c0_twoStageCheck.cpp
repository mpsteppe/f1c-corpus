// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004614C0
// Canonical corpus name: TwoStageCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoStageCheck_004614c0.c

void UnknownObject::twoStageCheck()
{
    // Returns TRUE when FlagBitTest(2) is set and FlagBitTest(4) is clear. Two independent flag-bit queries are combined with a logical AND of the first test and the negation of the second; the meaning of flag bits 2 and 4 is unresolved.
    // CALL: FlagBitTest(2) queries the state of flag bit 2; the result must be set for the function to return TRUE. [source:raw, callee:0x00461530]
    // CALL: FlagBitTest(4) queries the state of flag bit 4; the result must be clear for the function to return TRUE. [source:raw, callee:0x00461530]
    // CALCULATION: The two flag queries are combined as FlagBitTest(2) AND NOT FlagBitTest(4). [source:raw]
    // RETURN: Returns TRUE only if flag bit 2 is set and flag bit 4 is clear, otherwise FALSE. [source:raw]

    // Conservative worker pseudocode:
    //   return FlagBitTest(2) && !FlagBitTest(4);
    // UNRESOLVED: Semantics of flag bits 2 and 4 in the store that FlagBitTest reads.
    // UNRESOLVED: Which global flag store FlagBitTest operates on.
    // UNRESOLVED: Callers InputCommandDispatchToEntities and TeamRadioNetworkMessageProcessing suggest an input/team-radio gating role, but this is not evidenced.
}
