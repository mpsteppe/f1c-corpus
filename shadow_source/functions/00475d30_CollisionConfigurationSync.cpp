// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475D30
// Canonical corpus name: CollisionConfigurationSync
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionConfigurationSync_00475d30.c

void UnknownObject::CollisionConfigurationSync()
{
    // Frame-change collision configuration sync. Compares a stored collision config version (dword_7CD614) against the current frame counter/version (dword_7CE250); when they differ, it stamps the new version into dword_7CD614, updates physics module data from the module pointer array via ShortComputation_5bd0(&ppvOut), and reconfigures collision parameters (contact stiffness and collision arrays at 0x007CD458, 0x007CD45C, 0x007CD2B0 and 0x007CD610, plus the float loaded from dbl_8AFE90) via sub_454DA0. Invoked from F_2DRectangleDrawingWithOutline (0x00475D90).
    // GUARD: Sync block runs only when the stored version dword_7CD614 differs from the current frame counter/version dword_7CE250. The function is called from F_2DRectangleDrawingWithOutline (0x00475D90). [global:0x007CD614, global:0x007CE250, caller:0x00475D90, source:raw]
    // ASSIGNMENT: Stamp the current version: dword_7CD614 = dword_7CE250. [global:0x007CD614, global:0x007CE250, source:raw]
    // CALL: Call ShortComputation_5bd0(&ppvOut) to update physics module data derived from the module pointer array at 0x007CA590. [callee:0x00455BD0, global:0x007CA590, source:raw]
    // CALCULATION: Load v0 = dbl_8AFE90 (double read as a float parameter) for the collision configuration call. [global:0x008AFE90, source:raw]
    // CALL: Call sub_454DA0(&ppvOut, v0, &flt_7CD458, &flt_7CD45C, &flt_7CD2B0, &v2, &flt_7CD610, &v1) to configure contact stiffness and collision parameter arrays from the globals at 0x007CD458, 0x007CD45C, 0x007CD2B0 and 0x007CD610. [callee:0x00454DA0, global:0x007CA590, global:0x007CD458, global:0x007CD45C, global:0x007CD2B0, global:0x007CD610, global:0x008AFE90, source:raw]
    // RETURN: Void return; nothing executes when the stored and current versions already match. [function:0x00475D30, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionConfigurationSync() {
    //       if (dword_7CD614 != dword_7CE250) {
    //           dword_7CD614 = dword_7CE250;
    //           ShortComputation_5bd0((float*)&ppvOut);
    //           v0 = (float)dbl_8AFE90;
    //           sub_454DA0((int)&ppvOut, v0, &flt_7CD458, &flt_7CD45C, &flt_7CD2B0, &v2, &flt_7CD610, &v1);
    //       }
    //   }
    // UNRESOLVED: Semantic names of the collision parameter globals (flt_7CD458, flt_7CD45C, flt_7CD2B0, flt_7CD610) are DERIVED from existing analysis only.
    // UNRESOLVED: dbl_8AFE90's role as a configuration float is DERIVED (existing analysis: EngineCoolingRate), unconfirmed.
    // UNRESOLVED: Out parameters v1/v2 written by sub_454DA0 are not consumed by this function.
}
