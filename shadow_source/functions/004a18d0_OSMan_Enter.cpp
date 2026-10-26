// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A18D0
// Canonical corpus name: OSMan_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OSMan_Enter_004a18d0.c

void UnknownObject::OSMan_Enter()
{
    // Single-instance guard. Calls StringSplitLoop(2, build-version string, 420) and, when it returns nonzero, writes a debug log line announcing OS-manager entry. Then assigns global hObject = CreateMutexA(0, 1, Name) to create a named mutex with initial ownership requested. Returns TRUE when the mutex already exists (GetLastError() == 183, another instance running) or when the handle is null (creation failed); returns FALSE only when this instance created and owns the mutex.
    // CALL: Call StringSplitLoop(2, aDDevF119992002_19, 420) to parse the build-version string; the boolean outcome is used only as a log trigger. [callee:0x004D7A50, global:0x005CD0EC, source:raw]
    // GUARD: When StringSplitLoop returns nonzero, proceed to write the OS-manager entry log line. [callee:0x004D7A50, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredOsmanEn) to log that the OS manager was entered. [callee:0x004D7AA0, global:0x008AD25C, global:0x005CD0D4, source:raw]
    // ASSIGNMENT: Assign global hObject = CreateMutexA(0, 1, Name): create a named mutex from global Name with initial ownership requested. [global:0x005CD0B4, global:0x007CE2D8, global:0x0059E1AC, source:raw]
    // CALCULATION: Build the return condition: handle null (creation failed) OR GetLastError() == 183 (ERROR_ALREADY_EXISTS, another instance owns the mutex). [global:0x007CE2D8, global:0x0059E188, source:raw]
    // RETURN: Return TRUE when the mutex could not be exclusively created (already running or failure); FALSE when this instance is the sole owner. [global:0x0059E188, source:raw]

    // Conservative worker pseudocode:
    //   BOOL OSMan_Enter() {
    //     if (StringSplitLoop(2, sBuildVersion, 420))
    //       DebugLogWrite(&gDebugBuffer, "Entered OSManager");
    //     gMutexHandle = CreateMutexA(0, 1, gMutexName);
    //     return (gMutexHandle == 0) || (GetLastError() == 183);
    //   }
    // UNRESOLVED: What StringSplitLoop(2, buildVersionString, 420) actually detects in the build string; only its boolean outcome is consumed here.
    // UNRESOLVED: Global hObject (0x007CE2D8) is written but never read inside this function; its later consumers are outside this packet.
    // UNRESOLVED: The exact mutex name string global Name resolves to is not visible in the raw source.
}
