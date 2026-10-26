// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C9E0
// Canonical corpus name: CollisionGlobalStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalStructInit_0044c9e0.c

void UnknownObject::CollisionGlobalStructInit()
{
    // Initializes the collision subsystem's global settings block: sets the dword at 0x007CCCB0 to its default value 11 and the float at 0x007CCCB4 to 0.0, then calls SteeringSensitivityInit to initialize steering-sensitivity state. Free function with no object context.
    // ASSIGNMENT: Set dword_7CCCB0 (at 0x007CCCB0) to the default literal 11. [global:0x007CCCB0, source:raw]
    // ASSIGNMENT: Set flt_7CCCB4 (at 0x007CCCB4) to 0.0. [global:0x007CCCB4, source:raw]
    // CALL: Call SteeringSensitivityInit() to initialize steering-sensitivity state before returning. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGlobalStructInit() {
    //     dword_7CCCB0 = 11;
    //     flt_7CCCB4 = 0.0;
    //     SteeringSensitivityInit();
    //   }
    // UNRESOLVED: Semantic meaning of the default dword_7CCCB0 = 11 (e.g. a count, mode or flag) is not evidenced.
    // UNRESOLVED: The static callee list for this packet does not name SteeringSensitivityInit; the call is visible only in the raw source text.
}
