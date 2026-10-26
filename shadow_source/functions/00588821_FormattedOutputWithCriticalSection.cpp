// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588821
// Canonical corpus name: FileOpWithGlobalBuffer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileOpWithGlobalBuffer_00588821.c

void UnknownObject::FormattedOutputWithCriticalSection()
{
    // Varargs wrapper that performs formatted output into the global buffer/context unk_5E6768 while holding its critical section. Saves the buffer state before formatting, performs the format through sub_58D04D, restores the buffer state, releases the critical section, and returns the format result.
    // CALL: Enter the critical section for global context unk_5E6768 with CriticalSectionEnter before touching the buffer. [callee:0x0058C1E0, global:0x005E6768]
    // CALL: Save the current buffer state of unk_5E6768 via sub_58E41B and keep the result for later restoration. [callee:0x0058E41B, global:0x005E6768]
    // CALL: Perform the formatted output: sub_58D04D writes the format string and va_list into unk_5E6768 and returns the result. [callee:0x0058D04D, global:0x005E6768]
    // CALL: Restore the buffer state of unk_5E6768 using the previously saved state via ClearStructFieldsIfFlagSet. [callee:0x0058E4A8, global:0x005E6768]
    // CALL: Leave the critical section on unk_5E6768 with CriticalSectionLeave_c232. [callee:0x0058C232, global:0x005E6768]
    // RETURN: Return the formatted-output result produced by sub_58D04D. [source:raw]

    // Conservative worker pseudocode:
    //   int FormattedOutputWithCriticalSection(const char *fmt, ...) {
    //     va_list va; va_start(va, fmt);
    //     CriticalSectionEnter(1, &unk_5E6768);
    //     int saved = sub_58E41B(&unk_5E6768);
    //     int result = sub_58D04D(&unk_5E6768, fmt, va);
    //     ClearStructFieldsIfFlagSet(saved, &unk_5E6768);
    //     CriticalSectionLeave_c232(1, &unk_5E6768);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the constant first argument (value 1) passed to the critical-section enter/leave routines is not established by the packet.
    // UNRESOLVED: Exact format semantics and return meaning of sub_58D04D are delegated to that callee.
    // UNRESOLVED: Callers (WindowsAdminCheck, MediaFileDecodeHeader, MPEGBuffer) show it is a shared formatted-output helper, but the specific output sink is the global unk_5E6768 context.
}
