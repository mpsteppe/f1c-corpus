// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A14E0
// Canonical corpus name: sub_4A14E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A14E0_004a14e0.c

void UnknownObject::DestroyGameWindows()
{
    // Shutdown-time cleanup that destroys up to two windows and unregisters their window classes, then releases the cursor clip. If the primary window handle dword_7CE2E0 equals the secondary handle hWnd, the secondary is cleared first to avoid a double-destroy. The dword_7CE2E0 window uses the 'CubeRealTime' class; a distinct hWnd window uses ClassName. Returns the result of ClipCursor(0).
    // ASSIGNMENT: Initialize v0 from global hWnd. [global:0x007CE2DC]
    // GUARD: When dword_7CE2E0 equals hWnd, clear the local v0 and reset global hWnd to 0 to avoid destroying the same window twice. [global:0x007CE2E0, global:0x007CE2DC]
    // GUARD: When dword_7CE2E0 is non-NULL, destroy it, unregister its 'CubeRealTime' window class, and zero the global. [global:0x007CE2E0, global:0x005CD0A4, global:0x007CE2A0]
    // CALL: DestroyWindow(dword_7CE2E0) for the primary window. [global:0x0059E278, global:0x007CE2E0]
    // CALL: UnregisterClassA(aCuberealtime, hinst) for the primary window class. [global:0x0059E27C, global:0x005CD0A4, global:0x007CE2A0]
    // ASSIGNMENT: Set dword_7CE2E0 to 0 after destroying the primary window. [global:0x007CE2E0]
    // GUARD: When the captured secondary handle v0 is non-NULL, destroy that window too. [global:0x007CE2DC]
    // CALL: DestroyWindow(v0) for the secondary window. [global:0x0059E278, global:0x007CE2DC]
    // CALL: UnregisterClassA(ClassName, hinst) for the secondary window class. [global:0x0059E27C, global:0x005CD090, global:0x007CE2A0]
    // ASSIGNMENT: Reset global hWnd to 0 after destroying the secondary window. [global:0x007CE2DC]
    // RETURN: Return ClipCursor(0) to release the cursor clip rectangle. [global:0x0059E294]

    // Conservative worker pseudocode:
    //   BOOL DestroyGameWindows() {
    //     HWND h1 = dword_7CE2E0;
    //     HWND v0 = hWnd;
    //     if (dword_7CE2E0 == hWnd) { v0 = 0; hWnd = 0; }
    //     if (dword_7CE2E0) {
    //       DestroyWindow(dword_7CE2E0);
    //       UnregisterClassA(aCuberealtime, hinst);
    //       v0 = hWnd;
    //       dword_7CE2E0 = 0;
    //     }
    //     if (v0) {
    //       DestroyWindow(v0);
    //       UnregisterClassA(ClassName, hinst);
    //       hWnd = 0;
    //     }
    //     return ClipCursor(0);
    //   }
    // UNRESOLVED: Why dword_7CE2E0's window is re-fetched (v0 = hWnd) inside the first destroy branch is not evidenced.
    // UNRESOLVED: The two window classes' ownership (which subsystem creates each window) is caller-supplied and unknown here.
    // UNRESOLVED: hinst and the global function pointers are imported values; their initialization site is outside this function.
}
