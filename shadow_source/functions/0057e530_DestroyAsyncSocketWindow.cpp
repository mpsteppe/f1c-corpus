// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E530
// Canonical corpus name: sub_57E530
// Owner: AsyncSocketWindowSubsystem [DERIVED]
// Raw source: functions/sub_57E530_0057e530.c

void AsyncSocketWindowSubsystem::DestroyAsyncSocketWindow()
{
    // Destroys the hidden async-socket message window: if global handle dword_8D3E28 is non-zero it calls DestroyWindow on it, unregisters the window class via UnregisterClassA using lpClassName and the HINSTANCE at this[477], clears the global handle to 0, and returns 1; otherwise returns 0 immediately.
    // GUARD: If dword_8D3E28 (async-socket window handle) is non-zero, perform cleanup; otherwise return 0 with no work. [global:0x008D3E28, source:raw]
    // CALL: DestroyWindow(dword_8D3E28) destroys the hidden window. [global:0x0059E278, global:0x008D3E28, source:raw]
    // CALL: UnregisterClassA(lpClassName, this[477]) removes the registered window class using the HINSTANCE stored at this+0x774. [global:0x0059E27C, global:0x005E5374, field:this:0x00000774, source:raw]
    // ASSIGNMENT: Clear the global window handle dword_8D3E28 to 0. [global:0x008D3E28, source:raw]
    // RETURN: Return 1 when the window existed and was destroyed; return 0 when dword_8D3E28 was already zero. Invoked by caller sub_57BCE0. [caller:0x0057BCE0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3E28) {
    //     DestroyWindow(dword_8D3E28);
    //     UnregisterClassA(lpClassName, this[477]);
    //     dword_8D3E28 = 0;
    //     return 1;
    //   }
    //   return 0;
    // UNRESOLVED: Exact window class name carried by lpClassName is not evidenced in this function.
    // UNRESOLVED: Relationship of this+0x774 (HINSTANCE) to the async-socket window owner is not directly evidenced.
}
