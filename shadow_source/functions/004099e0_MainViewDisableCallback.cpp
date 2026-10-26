// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004099E0
// Canonical corpus name: sub_4099E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4099E0_004099e0.c

void UnknownObject::MainViewDisableCallback()
{
    // View-mode state switch, inverse of the paired enable variant: clears global flag bit 32 via GlobalFlagSetClear(32, 0), then sets bit 0x8000 in the dword at offset 236 of the object referenced by dword_8AFE88, and returns the GlobalFlagSetClear result.
    // CALL: Clear global flag bit 32 via GlobalFlagSetClear(32, 0), keeping the returned value as result. [callee:0x0054A200, source:raw]
    // ASSIGNMENT: Set bit 0x8000 in the flag dword at offset 236 of the object pointed to by dword_8AFE88: *(dword_8AFE88 + 236) |= 0x8000. [global:0x008AFE88, source:raw]
    // RETURN: Return result, the value returned by GlobalFlagSetClear. [source:raw]

    // Conservative worker pseudocode:
    //   int MainViewDisableCallback() {
    //     int result = GlobalFlagSetClear(32, 0);
    //     *(dword_8AFE88 + 236) |= 0x8000;
    //     return result;
    //   }
    // UNRESOLVED: dword_8AFE64 is listed in the packet globals but is not referenced by the raw source; its role here is unknown.
    // UNRESOLVED: The object referenced by dword_8AFE88 and the meaning of bit 0x8000 at offset 236 are unresolved.
    // UNRESOLVED: The semantic meaning of global flag bit 32 is unresolved; the paired switch function (which sets flag 32 and clears bit 0x8000) suggests a mode flag pair.
}
