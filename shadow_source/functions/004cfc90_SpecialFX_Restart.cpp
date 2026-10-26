// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CFC90
// Canonical corpus name: SpecialFX_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpecialFX_Restart_004cfc90.c

void UnknownObject::SpecialFX_Restart()
{
    // Debug trace entry called when restarting the special effects system. Invokes StringSplitLoop with the source path and line number 3295 as a conditional trace trigger, then writes an "entered special" message through DebugLogWrite when the trigger returns non-zero.
    // CALL: Call StringSplitLoop with arguments (2, SourcePath, line 3295) to conditionally enable trace output; store result. [callee:0x004D7A50, global:0x005D3624, source:raw]
    // GUARD: If the low byte of the StringSplitLoop result is non-zero, enter the debug-logging branch; otherwise skip logging. [callee:0x004D7A50, source:raw]
    // CALL: Write the entered-special message string to the debug message buffer via DebugLogWrite and return. [callee:0x004D7AA0, global:0x005D39D0, global:0x008AD25C, source:raw]
    // RETURN: Return the StringSplitLoop result unchanged when the trace branch is skipped. [callee:0x004D7A50, source:raw]

    // Conservative worker pseudocode:
    //   int SpecialFX_Restart() {
    //     int result = StringSplitLoop(2, g_sourcePath, 3295);
    //     if ((char)result)
    //       return DebugLogWrite(&g_debugMessageBuffer, g_enteredSpecialRestartString);
    //     return result;
    //   }
    // UNRESOLVED: Semantics of StringSplitLoop return value as a boolean trace gate are inferred; no packet evidence defines its contract.
    // UNRESOLVED: The exact message content of the entered-special string is not present in the packet.
}
