// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414180
// Canonical corpus name: sub_414180
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_414180_00414180.c

void UnknownObject::GlobalDataSelectorByIndex()
{
    // Index-based selector over two global DWORDs: returns the value of dword_5BF8CC when a1 is 0, the value of dword_5BF8D4 when a1 is 1, and -1 for any other index. No state is modified.
    // GUARD: If a1 is zero, return the current value of global dword_5BF8CC. [global:0x005BF8CC, source:raw]
    // GUARD: If a1 equals 1, return the current value of global dword_5BF8D4. [global:0x005BF8D4, source:raw]
    // RETURN: For any a1 other than 0 or 1, return the default value -1. [function:0x00414180, source:raw]

    // Conservative worker pseudocode:
    //   int sub_414180(int a1) {
    //     if (a1 == 0) return dword_5BF8CC;
    //     if (a1 == 1) return dword_5BF8D4;
    //     return -1;
    //   }
    // UNRESOLVED: The meaning of the two selected globals (dword_5BF8CC, dword_5BF8D4) and of the selector index a1 is unknown; caller semantics (SeasonSpecificTeamIDLookup, MapCollisionShapeToBoneIndex, etc.) vary widely.
    // UNRESOLVED: No evidence in the packet explains why the globals are 8 bytes apart (0x5BF8CC vs 0x5BF8D4).
}
