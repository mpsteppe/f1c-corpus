// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409950
// Canonical corpus name: sub_409950
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_409950_00409950.c

void UnknownObject::MainViewEnableCallback()
{
    // View-mode state switch: sets global flag bit 32 via GlobalFlagSetClear(32, 1), then clears bit 0x8000 in the dword at offset 236 of the object referenced by dword_8AFE88, and returns the GlobalFlagSetClear result. The inverse variant clears flag 32 and sets bit 0x8000, which together form a mode-toggle flag pair.
    // CALL: Set global flag bit 32 via GlobalFlagSetClear(32, 1), keeping the returned value as result. [callee:0x0054A200, source:raw]
    // ASSIGNMENT: Clear bit 0x8000 in the flag dword at offset 236 of the object pointed to by dword_8AFE88: *(dword_8AFE88 + 236) &= ~0x8000. [global:0x008AFE88, source:raw]
    // RETURN: Return result, the value returned by GlobalFlagSetClear. [source:raw]

    // Conservative worker pseudocode:
    //   int MainViewEnableCallback() {
    //     int result = GlobalFlagSetClear(32, 1);
    //     *(dword_8AFE88 + 236) &= ~0x8000;
    //     return result;
    //   }
    // UNRESOLVED: dword_8AFE64 is listed in the packet globals but is not referenced by the raw source; its role here is unknown.
    // UNRESOLVED: The object referenced by dword_8AFE88 and the meaning of bit 0x8000 at offset 236 are unresolved.
    // UNRESOLVED: The semantic meaning of global flag bit 32 is unresolved; the paired switch function (which clears flag 32 and sets bit 0x8000) suggests a mode flag pair.
}
