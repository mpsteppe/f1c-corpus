// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D1C0
// Canonical corpus name: CollisionStaticInit6d
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticInit6d_0044d1c0.c

void UnknownObject::CollisionStaticInit6d()
{
    // Collision-subsystem static initializer: unconditionally writes four globals. Sets dword_7CCFA0 to 109, clears flt_7CCFA4 to 0.0, writes dword_7CCFA8 = -1082130432, and clears flt_7CCFAC to 0.0. No guard, no call, no field access; a linear, side-effect-only initializer with no return value.
    // ASSIGNMENT: Write 109 to global dword_7CCFA0 (a render/static-type ID per existing analysis). [global:0x007CCFA0, source:raw]
    // ASSIGNMENT: Clear global flt_7CCFA4 to 0.0. [global:0x007CCFA4, source:raw]
    // ASSIGNMENT: Write -1082130432 to global dword_7CCFA8; the existing analysis interprets this literal as the IEEE-754 encoding of the -1.0f sentinel, which is DERIVED. [global:0x007CCFA8, source:raw]
    // ASSIGNMENT: Clear global flt_7CCFAC to 0.0. [global:0x007CCFAC, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionStaticInit6d() {
    //       dword_7CCFA0 = 109;
    //       flt_7CCFA4 = 0.0;
    //       dword_7CCFA8 = -1082130432;
    //       flt_7CCFAC = 0.0;
    //   }
    // UNRESOLVED: The literal -1082130432 written to dword_7CCFA8 is interpreted by existing analysis as the -1.0f sentinel; that float interpretation is DERIVED — the raw source writes the integer -1082130432 unchanged.
    // UNRESOLVED: The owner class is unknown; the function has no this pointer and no packet evidence names an owning object.
    // UNRESOLVED: The function is not on a static frame path and has no static callers; its invocation site is unresolved.
}
