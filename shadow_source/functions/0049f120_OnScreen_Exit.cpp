// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F120
// Canonical corpus name: OnScreen_Exit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OnScreen_Exit_0049f120.c

void UnknownObject::OnScreen_Exit()
{
    // Debug-log exit point invoked from GameExit. Runs StringSplitLoop(2, aDDevF119992002_16, 2705) as an assertion-style check; if the returned byte is non-zero it writes the "entered onscreen" message through DebugLogWrite, otherwise it returns the raw result unchanged.
    // CALL: Call StringSplitLoop with arguments (2, aDDevF119992002_16, 2705), passing the source-path string literal; stores the result for the following guard. Invoked in the GameExit path. [source:raw, callee:0x004D7A50, global:0x005CCF10, caller:0x0042DB20]
    // GUARD: Test the low byte of the StringSplitLoop result; non-zero passes (log the enter message), zero blocks the log and falls through to return the raw result. [source:raw, function:0x0049F120]
    // CALL: On assertion pass, call DebugLogWrite with the debug message buffer dword_8AD25C and the "entered onscreen" string aEnteredOnscree_4. [source:raw, callee:0x004D7AA0, global:0x008AD25C, global:0x005CCFA8]
    // RETURN: Return the StringSplitLoop result (the log path returns the same non-zero result). [source:raw, function:0x0049F120]

    // Conservative worker pseudocode:
    //   result = StringSplitLoop(2, aDDevF119992002_16, 2705);
    //   if ((BYTE)result != 0)
    //       DebugLogWrite(&dword_8AD25C, aEnteredOnscree_4);
    //   return result;
    // UNRESOLVED: StringSplitLoop (0x004D7A50) exact semantics are not established in this packet; the numeric literal 2705 is preserved unchanged.
}
