// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FA000
// Canonical corpus name: VidMan_Enter
// Owner: VidMan [DERIVED]
// Raw source: functions/VidMan_Enter_004fa000.c

void VidMan::VidMan_Enter()
{
    // Video manager entry point. Debug-initializes the command-line splitter and logs 'Entered VidMan', starts the QPC timer and the system allocator. Resolves the application directory (from the configured player file entry, or a built-in default), then compares it against the configured game directory. When the directories match it enters the normal init path: reads video-config fields (width/height + two extra outputs), validates the fullscreen flag, attempts the display mode switch, and if successful sets the window/instance handles, graphics config, and initializes rendering sub-modules. When the directories differ it relaunches the game executable via CreateProcessA in the configured directory and returns 1.
    // GUARD: Entry from Game_Enter during startup; conditionally initialize command-line split on dword_8AD25C using prefix string aDDevF119992002_26 and limit 928. [caller:0x0042D370, callee:0x004D7A50, global:0x008AD25C, global:0x005D6DC4, source:raw]
    // CALL: When the splitter setup succeeded, write debug log 'Entered VidMan' from aEnteredVidmanE against buffer dword_8AD25C. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D6E6C, source:raw]
    // CALL: Initialize the QPC high-resolution timer with argument 1. [callee:0x00568BE0, source:raw]
    // GUARD: Initialize the system allocator wrapper with three zero arguments; on non-zero return exit with failure code 1. [callee:0x0053D470, source:raw]
    // CALCULATION: Resolve the configured player file entry via IndexedArrayAccess_d890(dword_5EC488); branch on whether an entry exists. [callee:0x0053D890, global:0x005EC488, source:raw]
    // CALL: When a player entry exists, copy its directory string (entry + 8) into Filename via sub_53D8E0. [callee:0x0053D8E0, global:0x005EC488, source:raw]
    // LOOP: Otherwise copy the built-in default directory string byte_5D6E60 (NUL-terminated) into Filename. [global:0x005D6E60, source:raw]
    // CALCULATION: Select expected directory: dword_5EC480 when set, else fallback byte_5EA438. [global:0x005EC480, global:0x005EA438, source:raw]
    // GUARD: Compare Filename against the expected directory with strcmp; equal selects the normal initialization path, unequal selects the relaunch path. [global:0x005EC480, source:raw]
    // CALL: Normal path: invoke UtilityFunction_9160(dword_5EC488) on the player file entry. [callee:0x004F9160, global:0x005EC488, source:raw]
    // CALL: Read guarded video-config fields: GlobalGuardedFieldReader(dword_5EC48C, &nWidth, &nHeight, &v10, &v11) fills width, height and two extra outputs. [callee:0x004F91B0, global:0x005EC48C, source:raw]
    // GUARD: If fullscreen flag byte_5EC4A4 is set, call sub_55C330(0, 0, &v10); when the returned v10 differs from the originally captured value, clear byte_5EC4A4. [callee:0x0055C330, global:0x005EC4A4, source:raw]
    // GUARD: Attempt display mode switch via sub_4A1200(nWidth, nHeight, byte_5EC4A4); non-zero (failure) skips the initialization block. [callee:0x004A1200, global:0x005EC4A4, source:raw]
    // CALL: On success, set the window handle pair and instance: ThreeGlobalSetter(hWnd, hWnd, hinst). [callee:0x0053C680, global:0x007CE2DC, global:0x007CE2A0, source:raw]
    // CALL: Apply graphics configuration state from dword_5EC4B4 via GraphicsConfigStateSetter. [callee:0x005408F0, global:0x005EC4B4, source:raw]
    // CALL: Configure the video pipeline with saved dimensions and extra values: sub_4F9420(width, height, extraValueA, extraValueB). [callee:0x004F9420, source:raw]
    // GUARD: If sub_4F9310(dword_8AFE74) is true, abort initialization and return 1. [callee:0x004F9310, global:0x008AFE74, source:raw]
    // STATE_TRANSITION: Initialize the conditional state machine (ConditionalInit), then set the full-screen projection twice around a reset: sub_5434A0(0,0,1,1,0), CallWrapper_c060(0), sub_5434A0(0,0,1,1,0), ConditionalStateReset(). [callee:0x004F9F00, callee:0x004F9F30, callee:0x005434A0, callee:0x0055C060, source:raw]
    // CALL: Finalize sub-module initialization via sub_494690(), then return 0 on the normal success path. [callee:0x00494690, function:0x004FA000, source:raw]
    // CALL: Relaunch path: set up the working directory from dword_5EC3D0 via sub_422BE0, then read the current executable path into Filename with GetModuleFileNameA(0, Filename, 0x100). [callee:0x00422BE0, global:0x005EC3D0, global:0x0059E0EC, source:raw]
    // ASSIGNMENT: Zero StartupInfo and set cb to 68 (STARTUPINFOA size). [source:raw]
    // LOOP: Copy the command-line prefix bytes byte_5D6E50 (NUL-terminated) into CommandLine, then append Filename with strcat. [global:0x005D6E50, source:raw]
    // CALL: Spawn the game in the configured directory: CreateProcessA(NULL, CommandLine, ...) with CREATE_UNICODE_ENVIRONMENT (0x20), then return 1. [global:0x0059E0D0, function:0x004FA000, source:raw]

    // Conservative worker pseudocode:
    //   int VidMan_Enter() {
    //     if (StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 928))
    //       DebugLogWrite(dword_8AD25C, aEnteredVidmanE);
    //     QPCTimerInitialization(1);
    //     if (SystemInitAllocatorWrapper(0, 0, 0)) return 1;
    //     if (IndexedArrayAccess_d890(dword_5EC488))
    //       sub_53D8E0(entry + 8, Filename);
    //     else
    //       copyStr(byte_5D6E60, Filename);
    //     expectedDir = dword_5EC480 ? (const char*)dword_5EC480 : byte_5EA438;
    //     if (strcmp(Filename, expectedDir) == 0) {
    //       UtilityFunction_9160(dword_5EC488);
    //       GlobalGuardedFieldReader(dword_5EC48C, &nWidth, &nHeight, &extraA, &extraB);
    //       orig = extraA;
    //       if (byte_5EC4A4) { sub_55C330(0, 0, &extraA); if (extraA != orig) byte_5EC4A4 = 0; }
    //       if (!sub_4A1200(nWidth, nHeight, byte_5EC4A4)) {
    //         ThreeGlobalSetter(hWnd, hWnd, hinst);
    //         GraphicsConfigStateSetter(dword_5EC4B4);
    //         sub_4F9420(nWidth, nHeight, orig, extraB);
    //         if (sub_4F9310(dword_8AFE74)) return 1;
    //         ConditionalInit(); sub_5434A0(0,0,1,1,0); CallWrapper_c060(0);
    //         sub_5434A0(0,0,1,1,0); ConditionalStateReset(); sub_494690();
    //       }
    //       return 0;
    //     } else {
    //       sub_422BE0(dword_5EC3D0, 0);
    //       GetModuleFileNameA(0, Filename, 0x100);
    //       memset(&StartupInfo, 0, sizeof(StartupInfo)); StartupInfo.cb = 68;
    //       copyStr(byte_5D6E50, CommandLine);
    //       strcat(CommandLine, Filename);
    //       CreateProcessA(0, CommandLine, 0, 0, 0, 0x20, 0, 0, &StartupInfo, &ProcessInformation);
    //       return 1;
    //     }
    //   }
    // UNRESOLVED: Semantics of sub_4F9420 and sub_4F9310 opaque; second returns a failure sentinel checked before conditional state init.
    // UNRESOLVED: Purpose of the two extra outputs (v10/v11) read by GlobalGuardedFieldReader is unknown; v10 is compared against a sub_55C330 output.
    // UNRESOLVED: Fullscreen flag byte_5EC4A4 is re-validated after sub_55C330; exact meaning of the change is unknown.
    // UNRESOLVED: Why the projection call sub_5434A0(0,0,1,1,0) is issued twice around CallWrapper_c060(0) is unexplained.
    // UNRESOLVED: Seven packet globals (unk_7CDE00, unk_7CE2A4, unk_8AFE18, dword_8AFE64, dword_8B78A0, dword_8B8DC8, byte_FF000000000053DE) are absent from the visible pseudocode; they are likely consumed inside called functions.
    // UNRESOLVED: strcmp, strcat, memset, GetModuleFileNameA and CreateProcessA are libc/WinAPI imports without callee evidence refs in the packet.
    // UNRESOLVED: Success/failure return code polarity (0 vs 1) differs between the two return-1 sites; both are failure/relaunch exits.
}
