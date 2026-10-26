// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x008D8000
// Canonical corpus name: start
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/start_008d8000.c

void UnknownObject::start()
{
    // Program entry point: allocates a global working buffer, loads and initializes the oph.dll and steeringwheel.dll plugins (caching their exports into globals and invoking their start routines), resolves IsDebuggerPresent from KERNEL32, and only proceeds to the main application entry sub_58A19E when no debugger is detected.
    // ASSIGNMENT: Allocate the global working buffer: dword_5C7530 = LocalAlloc(0x40, 0x7D0). [global:0x0059E190, global:0x005C7530, source:raw]
    // GUARD: Load oph.dll via LoadLibraryA(aOphDll); if the handle is null, skip the oph.dll initialization block. [global:0x0059E0C8, global:0x005BD0C0, source:raw]
    // ASSIGNMENT: Cache oph.dll exports into globals: hModule = module handle; start_0 = GetProcAddress(hModule, aStart); port = GetProcAddress(hModule, aPort); dword_5C752C = GetProcAddress(hModule, aIp). [global:0x005C7520, global:0x005C7524, global:0x005C7528, global:0x005C752C, global:0x0059E0CC, global:0x005BD0D0, global:0x005BD0E0, global:0x005BD0F0, source:raw]
    // CALL: Invoke the resolved oph.dll start routine through the cached start_0 function pointer. [global:0x005C7524, source:raw]
    // GUARD: Load steeringwheel.dll via LoadLibraryA(aSteeringwheelD); if the handle is null, skip the steering-wheel plugin block. [global:0x0059E0C8, global:0x005BD100, source:raw]
    // ASSIGNMENT: Cache steering-wheel plugin data: dword_5C7534 = module handle; start_1 = GetProcAddress(handle, aStart). [global:0x005C7534, global:0x005C7538, global:0x0059E0CC, global:0x005BD0D0, source:raw]
    // CALL: Invoke the resolved steeringwheel.dll start routine through the cached start_1 function pointer. [global:0x005C7538, source:raw]
    // ASSIGNMENT: Resolve the debugger probe: GetModuleHandleA(aKernel32); if KERNEL32 is loaded, GetProcAddress(handle, aIsdebuggerpres) and cache the result in dword_5C753C. [global:0x0059E21C, global:0x005B8D74, global:0x0059E0CC, global:0x005BD120, global:0x005C753C, source:raw]
    // GUARD: Probe with IsDebuggerPresent via the cached dword_5C753C pointer; when the probe reports no debugger, fall through to the main application entry sub_58A19E instead of returning the probe result. [global:0x005C753C, function:0x008D8000, source:raw]
    // RETURN: Return the debugger-present probe result; the non-debugged path returns after the main application entry sub_58A19E runs. [function:0x008D8000, source:raw]

    // Conservative worker pseudocode:
    //   g_workBuffer = LocalAlloc(0x40, 0x7D0);
    //   if (h = LoadLibraryA("oph.dll")) { cache exports into globals; start(); }
    //   if (h = LoadLibraryA("steeringwheel.dll")) { cache handle and start; start(); }
    //   resolve IsDebuggerPresent from KERNEL32;
    //   if (!IsDebuggerPresent()) sub_58A19E();
    // UNRESOLVED: ownership and exact role of the dword_5C7530 working buffer and of the oph.dll / steeringwheel.dll contracts
    // UNRESOLVED: sub_58A19E is referenced by name only and has no callee evidence ref in this packet
}
