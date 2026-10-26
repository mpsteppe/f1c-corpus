// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A19E
// Canonical corpus name: sub_58A19E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58A19E_0058a19e.c

void UnknownObject::WinMainEntryPoint()
{
    // Program entry point (equivalent to WinMain). Reads the Windows version via GetVersion and unpacks major/minor/build into four globals (dword_8D3E74/78/7C/80). Runs two guarded early-initialization steps (sub_59325D, TLSAllocationThreadIDInit) that exit via ErrorHandlerWithOptionalCleanupThenExit (codes 0x1C and 0x10) on failure. Registers a CRT SEH frame (ms_exc.registration.TryLevel = 0, sub_592F2C), then performs runtime init calls (sub_592DFA, sub_592BAD, sub_592AF4, sub_589C77), captures the command line into dword_8D5A44 and the environment pointer into dword_8D3EB4, queries STARTUPINFO for the window show mode (default 10 when dwFlags bit0 is clear), obtains the module handle, and calls GameMainEntry(hInstance, 0, nCmdShowParam, nCmdShow). After the main routine returns it runs UtilityFunction_9ca4 on the result and returns sub_592924(exception code, exception record).
    // CALL: Call GetVersion() to read the Windows OS version into Version. [source:raw, global:0x0059E1C4]
    // ASSIGNMENT: Unpack the version into globals: dword_8D3E80 = BYTE1(Version), dword_8D3E7C = low byte of Version, dword_8D3E78 = BYTE1(Version) + (low byte << 8), dword_8D3E74 = HIWORD(Version). [source:raw, global:0x008D3E74, global:0x008D3E78, global:0x008D3E7C, global:0x008D3E80]
    // CALL: Call sub_59325D(1) as the first guarded initialization step. [source:raw, callee:0x0059325D]
    // GUARD: If sub_59325D(1) returns 0, call ErrorHandlerWithOptionalCleanupThenExit(0x1C) and terminate. [source:raw, callee:0x0058A2CB]
    // CALL: Call TLSAllocationThreadIDInit() to initialize the TLS thread-ID machinery. [source:raw, callee:0x0058E060]
    // GUARD: If TLSAllocationThreadIDInit() returns 0, call ErrorHandlerWithOptionalCleanupThenExit(0x10) and terminate. [source:raw, callee:0x0058A2CB]
    // STATE_TRANSITION: Register the CRT exception frame: set ms_exc.registration.TryLevel = 0 and call sub_592F2C(), with stru_5B8C88 as the exception registration frame. [source:raw, callee:0x00592F2C, global:0x005B8C88]
    // CALL: Call GetCommandLineA() and store its result into dword_8D5A44. [source:raw, global:0x0059E1C8, global:0x008D5A44]
    // CALL: Call sub_592DFA() and store its result as the environment/command-line derived pointer in dword_8D3EB4. [source:raw, callee:0x00592DFA, global:0x008D3EB4]
    // CALL: Call the runtime init routine sub_592BAD(). [source:raw, callee:0x00592BAD]
    // CALL: Call the runtime init routine sub_592AF4(). [source:raw, callee:0x00592AF4]
    // CALL: Call the runtime init routine sub_589C77(). [source:raw, callee:0x00589C77]
    // CALL: Zero StartupInfo.dwFlags and call GetStartupInfoA(&StartupInfo) to read the process startup state. [source:raw, global:0x0059E1CC]
    // CALL: Call sub_592A9C() to obtain the startup-show parameter v5. [source:raw, callee:0x00592A9C]
    // GUARD: Select the window show mode: use StartupInfo.wShowWindow when StartupInfo.dwFlags bit0 is set, otherwise the default value 10; assign the result to v4. [source:raw]
    // CALL: Call GetModuleHandleA(0) to get the module handle for the current executable into ModuleHandleA. [source:raw, global:0x0059E21C]
    // CALL: Call GameMainEntry(ModuleHandleA, 0, v5, v4) with the module handle, null instance, startup-show parameter and show mode; capture the return value in v6. [source:raw, callee:0x0045B200]
    // CALL: Call UtilityFunction_9ca4(v6) with the GameMainEntry result. [source:raw, callee:0x00589CA4]
    // RETURN: Return sub_592924(ms_exc.exc_ptr->ExceptionRecord->ExceptionCode, ms_exc.exc_ptr), using the exception code and record from the CRT SEH frame. [source:raw, callee:0x00592924]

    // Conservative worker pseudocode:
    //   int WinMainEntryPoint() {
    //     DWORD ver = GetVersion();
    //     dword_8D3E80 = BYTE1(ver);
    //     dword_8D3E7C = LOBYTE(ver);
    //     dword_8D3E78 = BYTE1(ver) + (LOBYTE(ver) << 8);
    //     dword_8D3E74 = HIWORD(ver);
    //     if (!sub_59325D(1)) ErrorHandlerWithOptionalCleanupThenExit(0x1C);
    //     if (!TLSAllocationThreadIDInit()) ErrorHandlerWithOptionalCleanupThenExit(0x10);
    //     // install CRT exception frame
    //     ms_exc.registration.TryLevel = 0;
    //     sub_592F2C();
    //     dword_8D5A44 = (int)GetCommandLineA();
    //     dword_8D3EB4 = (LPVOID)sub_592DFA();
    //     sub_592BAD(); sub_592AF4(); sub_589C77();
    //     STARTUPINFOA si; si.dwFlags = 0; GetStartupInfoA(&si);
    //     int showParam = sub_592A9C();
    //     int show = (si.dwFlags & 1) ? si.wShowWindow : 10;
    //     HMODULE h = GetModuleHandleA(0);
    //     UINT code = GameMainEntry(h, 0, showParam, show);
    //     UtilityFunction_9ca4(code);
    //     return sub_592924(ms_exc.exc_ptr->ExceptionRecord->ExceptionCode, ms_exc.exc_ptr);
    //   }
    // UNRESOLVED: sub_589CB5 is listed as a callee but does not appear in the raw source text; it is likely reached indirectly through the SEH/exception path and its role is unconfirmed.
    // UNRESOLVED: The read-only global ScriptFrameProcessor (0058895c) is noted by the existing analysis as referenced by init subsystems, but the raw source does not reference it directly; its use is indirect.
    // UNRESOLVED: The byte globals at high artifact addresses (byte_FF00000000001695, byte_FF00000000001699, byte_FF0000000000169A, byte_FF0000000000169B, byte_FF000000000053E9, byte_FF000000000053EA) most plausibly belong to the CRT SEH/CPPEH frame and are not referenced directly by the decompiled statements.
}
