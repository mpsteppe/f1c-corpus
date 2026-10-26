// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500EAC
// Canonical corpus name: sub_500EAC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_500EAC_00500eac.c

void UnknownObject::DebugSetMuteLazyInit()
{
    // Lazily resolves the D3D8 DebugSetMute function pointer, preferring the retail d3d8.dll and falling back to the debug d3d8d.dll, then calls it with the single argument a1 (mute state) to suppress or enable D3D8 debug output. Cached pointers are stored in the globals DebugSetMute (0x008B0094, retail) and dword_8B0090 (0x008B0090, debug DLL variant) so later calls skip the DLL resolution.
    // GUARD: If DebugSetMute (retail cached pointer, 0x008B0094) is already set, jump straight to the call path and invoke it with a1. [global:0x008B0094, source:raw]
    // GUARD: When DebugSetMute is not cached and dword_8B0090 (debug cached pointer, 0x008B0090) is also clear, enter the DLL resolution path; otherwise the cached debug pointer is used directly. [global:0x008B0090, source:raw]
    // CALL: Check whether d3d8.dll (string at 0x005ADB24) is already loaded via GetModuleHandleA (import at 0x0059E21C). [global:0x0059E21C, global:0x005ADB24, source:raw]
    // CALL: Load d3d8.dll (string at 0x005ADB24) explicitly via LoadLibraryA (import at 0x0059E0C8), storing the module handle in LibraryA. [global:0x0059E0C8, global:0x005ADB24, source:raw]
    // GUARD: Only when LibraryA is non-null, resolve the DebugSetMute export (name string at 0x005ADB30) via GetProcAddress (import at 0x0059E0CC) and cache it in DebugSetMute (0x008B0094). [global:0x0059E0CC, global:0x005ADB30, global:0x008B0094, source:raw]
    // CALL: Probe the debug DLL (name string at 0x005ADB40) with GetModuleHandleA and, if present, LoadLibraryA it, keeping the handle as result. [global:0x0059E21C, global:0x0059E0C8, global:0x005ADB40, source:raw]
    // CALL: If the debug DLL loaded, resolve DebugSetMute (name string at 0x005ADB30) from it via GetProcAddress and cache the pointer in dword_8B0090 (0x008B0090). [global:0x0059E0CC, global:0x005ADB30, global:0x008B0090, source:raw]
    // GUARD: After the load attempt, if DebugSetMute is still null and dword_8B0090 is null too, no DebugSetMute could be resolved and result (the DLL handle) is returned. [global:0x008B0094, global:0x008B0090, source:raw]
    // CALL: Invoke the retail cached DebugSetMute(a1) when it was resolved. [global:0x008B0094, source:raw]
    // CALL: Invoke the debug cached dword_8B0090() when only the d3d8d.dll variant was resolved. [global:0x008B0090, source:raw]
    // RETURN: Return the DebugSetMute call result (or the DLL handle when nothing could be resolved). [source:raw]
    // CALL: Used as a shared DebugSetMute initializer by SurfaceBlitOperation (0x0050099C), D3DTextureSurfaceLockCopy (0x00506559) and sub_506971 (0x00506971). [caller:0x0050099C, caller:0x00506559, caller:0x00506971, source:raw]

    // Conservative worker pseudocode:
    //   HMODULE sub_500EAC(int a1) {
    //     if (DebugSetMute) return DebugSetMute(a1);
    //     if (!dword_8B0090) {
    //       if (GetModuleHandleA("d3d8.dll")) {
    //         HMODULE h = LoadLibraryA("d3d8.dll");
    //         if (h) DebugSetMute = GetProcAddress(h, "DebugSetMute");
    //       }
    //       HMODULE r = GetModuleHandleA("d3d8d.dll");
    //       if (r) {
    //         r = LoadLibraryA("d3d8d.dll");
    //         if (r) dword_8B0090 = GetProcAddress(r, "DebugSetMute");
    //       }
    //       if (!DebugSetMute) {
    //         if (!dword_8B0090) return r;
    //         return dword_8B0090();
    //       }
    //     }
    //     return DebugSetMute(a1);
    //   }
    // UNRESOLVED: Which DLL-name string literal lives at 0x005ADB24 (aD3d8dDll) versus 0x005ADB40 (ModuleName) is not resolved from the raw source alone.
    // UNRESOLVED: The exact semantics of a1 (mute enable value) are inferred from the debugger-API name and not proven here.
    // UNRESOLVED: The ownership object for the cached function pointers is unknown.
}
