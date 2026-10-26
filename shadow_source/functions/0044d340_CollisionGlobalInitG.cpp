// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D340
// Canonical corpus name: CollisionGlobalInitG
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInitG_0044d340.c

void UnknownObject::CollisionGlobalInitG()
{
    // Collision-subsystem global initializer: unconditionally writes four globals. Sets dword_7CA4D0 to 63, clears dword_7CA4D4 to 0, writes dword_7CA4D8 = -1082130432, and clears dword_7CA4DC to 0. No guard, no call, no field access; a linear, side-effect-only initializer with no return value.
    // ASSIGNMENT: Write 63 to global dword_7CA4D0 (collision world object type/index per existing analysis). [global:0x007CA4D0, source:raw]
    // ASSIGNMENT: Clear global dword_7CA4D4 to 0. [global:0x007CA4D4, source:raw]
    // ASSIGNMENT: Write -1082130432 to global dword_7CA4D8; the existing analysis interprets this literal as the -1.0f sentinel (invalid/null index), which is DERIVED. [global:0x007CA4D8, source:raw]
    // ASSIGNMENT: Clear global dword_7CA4DC to 0. [global:0x007CA4DC, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGlobalInitG() {
    //       dword_7CA4D0 = 63;
    //       dword_7CA4D4 = 0;
    //       dword_7CA4D8 = -1082130432;
    //       dword_7CA4DC = 0;
    //   }
    // UNRESOLVED: The literal -1082130432 written to dword_7CA4D8 is interpreted by existing analysis as the -1.0f sentinel; that float interpretation is DERIVED — the raw source writes the integer -1082130432 unchanged.
    // UNRESOLVED: The owner class is unknown; the function has no this pointer and no packet evidence names an owning object.
    // UNRESOLVED: The function is not on a static frame path and has no static callers; its invocation site is unresolved.
}
