// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CF20
// Canonical corpus name: CollisionStateInitAlpha2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInitAlpha2_0044cf20.c

void UnknownObject::CollisionStateInitAlpha2()
{
    // Vehicle collision-state initializer: writes a state code (38) and a float (0.0) into adjacent global slots at 0x007CA3A8/0x007CA3AC, then delegates remaining setup to a callee embedded in the raw source.
    // ASSIGNMENT: dword_7CA3A8 = 38; set collision state code global to 38. [global:0x007CA3A8, source:raw]
    // ASSIGNMENT: flt_7CA3AC = 0.0; initialize adjacent float global to 0.0. [global:0x007CA3AC, source:raw]
    // CALL: Call GlobalStateInitializer_cf34(); delegate further state initialization to the callee shown in raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionStateInitAlpha2(void) {
    //     dword_7CA3A8 = 38;
    //     flt_7CA3AC = 0.0;
    //     GlobalStateInitializer_cf34();
    //   }
    // UNRESOLVED: Callee GlobalStateInitializer_cf34 has no address or prototype in the packet; packet callees list is empty.
    // UNRESOLVED: Semantic meaning of global pair 0x007CA3A8/0x007CA3AC (state code + float) is not established.
}
