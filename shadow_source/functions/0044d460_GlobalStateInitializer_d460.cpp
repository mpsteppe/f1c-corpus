// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D460
// Canonical corpus name: GlobalStateInitializer_d460
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_d460_0044d460.c

void UnknownObject::GlobalStateInitializer_d460()
{
    // Unconditional state initializer: writes six dword globals, setting dword_7CCCF0 to 15 and zeroing dword_7CCCF4, dword_7CCCF8, dword_7CCCFC, dword_7CCD00 and dword_7CCD04, then returns 0. No callees, no guards, and no static callers evidenced.
    // ASSIGNMENT: dword_7CCCF0 = 15 (the only non-zero constant written). [global:0x007CCCF0, source:raw]
    // ASSIGNMENT: dword_7CCCF4 = 0. [global:0x007CCCF4, source:raw]
    // ASSIGNMENT: dword_7CCCF8 = 0. [global:0x007CCCF8, source:raw]
    // ASSIGNMENT: dword_7CCCFC = 0. [global:0x007CCCFC, source:raw]
    // ASSIGNMENT: dword_7CCD00 = 0. [global:0x007CCD00, source:raw]
    // ASSIGNMENT: dword_7CCD04 = 0. [global:0x007CCD04, source:raw]
    // RETURN: Return 0. [function:0x0044D460, source:raw]

    // Conservative worker pseudocode:
    //   int sub_44D460() {
    //     dword_7CCCF0 = 15;
    //     dword_7CCCF4 = 0;
    //     dword_7CCCF8 = 0;
    //     dword_7CCCFC = 0;
    //     dword_7CCD00 = 0;
    //     dword_7CCD04 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The individual meaning of the six globals is not evidenced; the rain-brake/collision-state role and the value 15 are semantic proposals, not facts.
    // UNRESOLVED: No static caller or callee is evidenced, so the context in which this initializer runs is unknown.
}
