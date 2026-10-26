// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CBC0
// Canonical corpus name: CollisionGlobalInitF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInitF_0044cbc0.c

void UnknownObject::CollisionGlobalInitF()
{
    // Initializes collision subsystem globals: sets dword_7CD188 to 105, clears flt_7CD18C to 0.0, then calls GlobalStateInitNegOne(). No arguments, no return value.
    // ASSIGNMENT: dword_7CD188 = 105 [global:0x007CD188]
    // ASSIGNMENT: flt_7CD18C = 0.0 [global:0x007CD18C]
    // CALL: Call GlobalStateInitNegOne() with no arguments [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGlobalInitF()
    //   {
    //     dword_7CD188 = 105;
    //     flt_7CD18C = 0.0;
    //     GlobalStateInitNegOne();
    //   }
    // UNRESOLVED: Callee GlobalStateInitNegOne appears in raw source but has no address or evidence ref in the packet (callees list empty).
    // UNRESOLVED: Semantic meaning of 105 stored in dword_7CD188 is unknown.
}
