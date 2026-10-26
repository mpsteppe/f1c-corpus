// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5885
// Canonical corpus name: ExternalProcessLauncher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExternalProcessLauncher_004d5885.c

void UnknownObject::ExternalProcessLauncher()
{
    // External process launcher: builds a command line as `"<exe>" <args>` using StringFormatWithBufferOverflowCheck into a 256-char buffer, with the executable path taken from dword_7CEA18 when non-null else the default byte_5EA438, and the argument taken from a1 when non-null else byte_5EA438; zeroes the STARTUPINFOA (cb set to 68) and calls CreateProcessA (IAT slot at 0x0059E0D0) with creation flag 0x20 (CREATE_NO_WINDOW), returning the BOOL result. Top-level or indirect-only caller; owner UNKNOWN.
    // ASSIGNMENT: Default-argument fallback: v1 = a1; if a1 is null, v1 = byte_5EA438 (default application path/argument). [global:0x005EA438, source:raw]
    // ASSIGNMENT: Executable-path fallback: v2 = dword_7CEA18; if dword_7CEA18 is null, v2 = byte_5EA438 (default executable). [global:0x005EA438, global:0x007CEA18, source:raw]
    // CALL: Format the command line: call StringFormatWithBufferOverflowCheck(CommandLine, "\"%s\" %s", v2, v1) using the format string at 0x005D45B8, writing into the 256-char CommandLine buffer. [callee:0x0058815F, global:0x005D45B8, source:raw]
    // ASSIGNMENT: Zero-fill the STARTUPINFOA structure and set StartupInfo.cb = 68 (sizeof(STARTUPINFOA)). [source:raw]
    // CALL: Call CreateProcessA(0, CommandLine, 0, 0, 0, 0x20, 0, 0, &StartupInfo, &ProcessInformation) via its import slot at 0x0059E0D0; creation flag 0x20 is CREATE_NO_WINDOW. [global:0x0059E0D0, source:raw]
    // RETURN: Return the BOOL result of CreateProcessA (process launch success/failure). [function:0x004D5885, source:raw]

    // Conservative worker pseudocode:
    //   // Launch an external process with an optional executable override.
    //   BOOL ExternalProcessLauncher(const char* a1) {
    //       const char* args = a1 ? a1 : byte_5EA438;
    //       const char* exe  = dword_7CEA18 ? dword_7CEA18 : byte_5EA438;
    //       CHAR cmd[256];
    //       StringFormatWithBufferOverflowCheck(cmd, "\"%s\" %s", exe, args);
    //       STARTUPINFOA si; PROCESS_INFORMATION pi;
    //       memset(&si, 0, sizeof(si));
    //       si.cb = 68;
    //       return CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0x20, NULL, NULL, &si, &pi);
    //   }
    // UNRESOLVED: Owner/class is UNKNOWN; no static callers in the packet (top-level or indirect-only).
    // UNRESOLVED: byte_FF000000000053DE is listed in the packet as a write global but does not appear in the raw source text; it may be a misidentified IAT/thunk data reference.
    // UNRESOLVED: The semantic meaning of dword_7CEA18 (alternate executable override) versus byte_5EA438 (default path) is DERIVED from the null-fallback pattern, not proven.
    // UNRESOLVED: The ProcessInformation structure is populated by CreateProcessA but not otherwise consumed in this function.
}
