// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D350
// Canonical corpus name: SessionReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionReset_0042d350.c

void UnknownObject::SessionReset()
{
    // Session teardown helper called by GameExit. Destroys the texture surfaces of the state-flag-pair object at dword_8AD254 via TextureSurfaceDestroyer, then hands dword_5EC3D0 (the season parent path, per existing analysis) to sub_422BE0 with a zero flag and returns that call's result.
    // CALL: Call TextureSurfaceDestroyer(&dword_8AD254) to destroy/unload texture surfaces owned by the global state-flag-pair object at 0x008AD254. [callee:0x004D7800, global:0x008AD254, source:raw]
    // CALL: Call sub_422BE0((const CHAR **)dword_5EC3D0, 0), passing the season parent path global at 0x005EC3D0 and a zero second argument. [callee:0x00422BE0, global:0x005EC3D0, source:raw]
    // RETURN: Return the value returned by sub_422BE0; the function's return type is char per the raw source. [source:raw]
    // CALL: Called unconditionally by GameExit (0x0042DB20) as part of session shutdown. [caller:0x0042DB20, source:raw]

    // Conservative worker pseudocode:
    //   char SessionReset() {
    //     TextureSurfaceDestroyer(&dword_8AD254);
    //     return sub_422BE0((const CHAR **)dword_5EC3D0, 0);
    //   }
    // UNRESOLVED: Whether sub_422BE0 frees or reinitializes the season-parent-path resources is not provable from this function alone.
    // UNRESOLVED: The semantics of sub_422BE0's second argument (the literal 0) are unknown.
    // UNRESOLVED: The global types (dword_8AD254 as state-flag-pair object, dword_5EC3D0 as season parent path) are DERIVED labels from existing analysis, not independently confirmed here.
}
