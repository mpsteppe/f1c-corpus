// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C310
// Canonical corpus name: sub_49C310
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C310_0049c310.c

void UnknownObject::FormatDebugLabelFromName()
{
    // Formats a debug label into a caller-supplied buffer using a name string from a global object and outputs it. Copies the base string asc_5CCE54 into the output buffer via strcpy. If the suppression flag at dword_7C54E0 + 16484 is clear, reads a pointer at dword_7C54E0 + 16592; if that pointer is non-null, formats "%s:" (format string aS_6 at 0x005CCE60) against the name string at that pointer + 18168 using StringFormatWithBufferOverflowCheck, then emits the result through sub_589901. Always returns 0.
    // ASSIGNMENT: Copy the base string asc_5CCE54 into the output buffer lpSrcStr via strcpy; v2 is the destination pointer. [global:0x005CCE54, source:raw]
    // GUARD: If the suppression flag at dword_7C54E0 + 16484 is non-zero, skip formatting and output entirely. [global:0x007C54E0, source:raw]
    // ASSIGNMENT: Read the object pointer at dword_7C54E0 + 16592 into v3. [global:0x007C54E0, source:raw]
    // GUARD: If v3 is null, skip the formatting and output calls. [source:raw]
    // CALL: Format "%s:" (format string aS_6) against the name string at v3 + 18168 into the buffer with StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005CCE60]
    // CALL: Output the formatted label by calling sub_589901 with the buffer pointer. [callee:0x00589901]
    // RETURN: Return 0 on both the formatted and skipped paths. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatDebugLabelFromName(char* lpSrcStr, int a2) {
    //     char* v2 = strcpy(lpSrcStr, asc_5CCE54);
    //     if (!*(int*)(dword_7C54E0 + 16484)) {
    //       int v3 = *(int*)(dword_7C54E0 + 16592);
    //       if (v3) {
    //         StringFormatWithBufferOverflowCheck(v2, aS_6, v3 + 18168);
    //         sub_589901(v2);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: What asc_5CCE54 and aS_6 literally contain (base string and format string) is not shown in the raw source; the "%s:" reading of aS_6 comes from the existing analysis and is not independently evidenced.
    // UNRESOLVED: The global object dword_7C54E0 and the meaning of offsets 16484, 16592, and 18168 are not established by this function alone; the existing analysis labels dword_7C54E0 as postProcessInput, which is not independently verified here.
    // UNRESOLVED: What sub_589901 does with the formatted string (console, overlay, or log) is unknown.
}
