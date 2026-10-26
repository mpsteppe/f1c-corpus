// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC250
// Canonical corpus name: DrawYellowTextAtFixedScreenPosition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DrawYellowTextAtFixedScreenPosition_004dc250.c

void UnknownObject::DrawYellowTextAtFixedScreenPosition()
{
    // Retrieves a context/global object via SwitchBasedGlobalLookup(0); when non-null, sets the object's color field at +72 to yellow (16776960) and renders a text string through sub_49F1C0 at fixed screen coordinates (880, 140) using the race session state and render device globals. Always returns 0.
    // CALL: Call SwitchBasedGlobalLookup(0) to obtain a context/global object pointer. [callee:0x004D7FA0, source:raw]
    // GUARD: If the lookup result v0 is non-null, proceed with rendering; otherwise skip and return 0. [source:raw]
    // ASSIGNMENT: Write the yellow color value 16776960 into the object's field at +72. [source:raw]
    // CALL: Call sub_49F1C0 with the race session state (dword_7CE048), fixed coordinates 880 and 140, the yellow color 16776960, the context object v0, and the render device (dword_8B8DC8). [callee:0x0049F1C0, global:0x007CE048, global:0x008B8DC8, source:raw]
    // RETURN: Return 0. [function:0x004DC250, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DC250() {
    //     int v0 = SwitchBasedGlobalLookup(0);
    //     if (v0) {
    //       *(_DWORD*)(v0 + 72) = 16776960;
    //       sub_49F1C0(dword_7CE048, 880, 140, 16776960, v0, dword_8B8DC8);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the object returned by SwitchBasedGlobalLookup(0) and the exact text rendered by sub_49F1C0 are unknown.
    // UNRESOLVED: Color field at +72 belongs to the lookup result object, not a typed field of the owner class; its exact meaning is unverified.
    // UNRESOLVED: Semantic roles of dword_7CE048 and dword_8B8DC8 are only labeled DERIVED by existing analysis, not confirmed.
}
