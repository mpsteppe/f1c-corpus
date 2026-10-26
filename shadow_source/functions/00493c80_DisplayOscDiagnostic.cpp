// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493C80
// Canonical corpus name: sub_493C80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_493C80_00493c80.c

void UnknownObject::DisplayOscDiagnostic()
{
    // Formats and reports an OSC script parser diagnostic. Selects a severity label (Undefined/Warning/Error/CriticalError) by the severity argument, prefixes it with "OSC %s on line %d : " using the current line number stored at this[99], optionally appends a caller-supplied message with delimiter characters, and lazily opens a log stream (this[2], opened through this+67 in wt mode) to write the formatted line. For Error and CriticalError severity only, the message is routed to a callback via sub_4986D0 when this[105] is set, otherwise shown with MessageBoxA using the Caption global, followed by a utility call and a return through ResourcePathBuilder. Called by five OSC parser functions (004920b0, 00492160, 00492460, 00492a40, 00493fc0).
    // GUARD: Return 0 immediately when the severity argument a2 is at most 1; only severities 2 (Error) and 3 (CriticalError) proceed past the final gate. [source:raw]
    // ASSIGNMENT: Clear the 253-byte Text buffer, seeding its first byte from byte_5EA438[0] and zero-filling the remainder (0xFC bytes). [global:0x005EA438, source:raw]
    // ASSIGNMENT: Build the severity label array from the four string globals aUndefinedError, aWarning_0, aError and aCriticalError, select the entry at index a2, and read the current OSC line number from field this[99] (this+0x18C). [global:0x005CC980, global:0x005CC978, global:0x005CC970, global:0x005CC960, field:this:0x0000018C, source:raw]
    // CALL: Format the message header into Text with StringFormatWithBufferOverflowCheck using the aOscSOnLineD format "OSC %s on line %d : " with the severity label and the line number. [callee:0x0058815F, global:0x005CC948, source:raw]
    // GUARD: When the optional message a3 is supplied, append it to Text: write the delimiter word from asc_5C64D4 at the current end, strcat a3, then append the same delimiter word and the word_5C30B4 terminator. [global:0x005C64D4, global:0x005C30B4, source:raw]
    // ASSIGNMENT: Lazily open the log stream: when field this[2] (this+0x8) is null, open the log file with sub_587DB0 on this+67 using the aWt mode string and store the handle in this[2]; if opened, initialize it via sub_587F64(handle, 0, 0). [field:this:0x00000008, callee:0x00587DB0, callee:0x00587F64, global:0x005C302C, source:raw]
    // CALL: When the log stream is open, write the message header with StringFormatWithNestedIO(stream, aS_4) and then the line terminator with StringFormatWithNestedIO(stream, &word_5C30B4). [callee:0x005887B1, global:0x005C2C18, global:0x005C30B4, source:raw]
    // GUARD: Return 0 when the severity is neither 2 nor 3; only Error and CriticalError reach the user-visible reporting path. [source:raw]
    // GUARD: When field this[105] (this+0x1A4) is non-zero, route the formatted Text to the callback sub_4986D0 and return 0 instead of showing a dialog. [field:this:0x000001A4, callee:0x004986D0, source:raw]
    // CALL: Show the user-visible popup MessageBoxA(0, Text, Caption, 0) using the Caption global as the title. [global:0x0059E2A4, global:0x005CC938, source:raw]
    // CALL: Call the utility UtilityFunction_9ca4 with argument 1 after the dialog path. [callee:0x00589CA4, source:raw]
    // RETURN: Return the result of ResourcePathBuilder(a2), the terminal helper of the reporting path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_493C80(_DWORD *this, int severity, const char *message) {
    //     if (severity <= 1) return 0;
    //     CHAR Text[253];
    //     Text[0] = byte_5EA438[0]; memset(&Text[1], 0, 0xFC);
    //     const char *labels[] = { aUndefinedError, aWarning_0, aError, aCriticalError };
    //     StringFormatWithBufferOverflowCheck(Text, "OSC %s on line %d : ", labels[severity], this[99]);
    //     if (message) {
    //       __int16 delim = *(_WORD *)asc_5C64D4;
    //       *(_WORD *)&Text[strlen(Text)] = delim;
    //       strcat(Text, message);
    //       *(_WORD *)&Text[strlen(Text)] = delim;
    //       *(_WORD *)&Text[strlen(Text)] = word_5C30B4;
    //     }
    //     if (!this[2]) {
    //       this[2] = sub_587DB0(this + 67, aWt);
    //       if (this[2]) sub_587F64(this[2], 0, 0);
    //     }
    //     if (this[2]) {
    //       StringFormatWithNestedIO(this[2], aS_4);
    //       StringFormatWithNestedIO(this[2], &word_5C30B4);
    //     }
    //     if (severity != 3 && severity != 2) return 0;
    //     if (this[105]) { sub_4986D0(Text); return 0; }
    //     MessageBoxA(0, Text, Caption, 0);
    //     UtilityFunction_9ca4(1);
    //     return ResourcePathBuilder(severity);
    //   }
    // UNRESOLVED: The exact meaning of the two StringFormatWithNestedIO writes (aS_4 header and word_5C30B4 terminator) into the log stream is unknown; aS_4 is only a format-string global.
    // UNRESOLVED: sub_4986D0 is treated as a callback dispatcher from call context and existing analysis; its behavior is not documented in this function.
    // UNRESOLVED: ResourcePathBuilder is called with the severity argument and its result returned, but the packet carries no callee evidence ref or prototype for it.
    // UNRESOLVED: The log filename layout built by sub_587DB0 from this+67 is unknown; only the aWt mode string is evidenced.
    // UNRESOLVED: The two early returns for severity 0/1 mean the Undefined and Warning labels are only ever used as format arguments, never shown as dialogs.
}
