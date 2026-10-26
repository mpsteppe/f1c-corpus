// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D2E0
// Canonical corpus name: CollisionGlobalsInit_d2e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalsInit_d2e0_0044d2e0.c

void UnknownObject::CollisionGlobalsInit_d2e0()
{
    // Vehicle collision-globals initializer: writes integer constants (62 and 0) into adjacent dword globals at 0x007CA410/0x007CA414, then delegates remaining setup to a callee embedded in the raw source.
    // ASSIGNMENT: dword_7CA410 = 62; set first collision global to 62. [global:0x007CA410, source:raw]
    // ASSIGNMENT: dword_7CA414 = 0; set second collision global to 0. [global:0x007CA414, source:raw]
    // CALL: Call InitRenderConstantsZeroOne(); delegate render-constant initialization to the callee shown in raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGlobalsInit_d2e0(void) {
    //     dword_7CA410 = 62;
    //     dword_7CA414 = 0;
    //     InitRenderConstantsZeroOne();
    //   }
    // UNRESOLVED: Callee InitRenderConstantsZeroOne has no address or prototype in the packet; packet callees list is empty.
    // UNRESOLVED: Semantic meaning of global pair 0x007CA410/0x007CA414 (integer constants 62 and 0) is not established.
}
