// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494600
// Canonical corpus name: CollisionGlobalZeroing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalZeroing_00494600.c

void UnknownObject::CollisionGlobalZeroing()
{
    // Zeroes four collision-system global state DWORDs at 0x007CDDF0-0x007CDDFC and returns 0. Runs on the collision system reset/shutdown path.
    // ASSIGNMENT: Set result = 0. [source:raw]
    // ASSIGNMENT: Zero global dword_7CDDF0 at 0x007CDDF0. [global:0x007CDDF0, source:raw]
    // ASSIGNMENT: Zero global dword_7CDDF4 at 0x007CDDF4. [global:0x007CDDF4, source:raw]
    // ASSIGNMENT: Zero global dword_7CDDF8 at 0x007CDDF8. [global:0x007CDDF8, source:raw]
    // ASSIGNMENT: Zero global dword_7CDDFC at 0x007CDDFC. [global:0x007CDDFC, source:raw]
    // RETURN: Return result, which is 0 on every path. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalZeroing(void) {
    //     dword_7CDDF0 = 0; dword_7CDDF4 = 0;
    //     dword_7CDDF8 = 0; dword_7CDDFC = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the four zeroed globals is only DERIVED (collision state counters/flags) from the existing fill, not confirmed by a caller.
    // UNRESOLVED: No static callers are recorded in the packet; invocation context is unknown.
}
