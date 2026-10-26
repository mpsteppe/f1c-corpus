// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D040
// Canonical corpus name: CollisionFrictionInit29
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionFrictionInit29_0044d040.c

void UnknownObject::CollisionFrictionInit29()
{
    // Vehicle collision-friction initializer: writes a code (41) and a float (0.0) into adjacent global slots at 0x007CA3D8/0x007CA3DC, then delegates remaining setup to a callee embedded in the raw source.
    // ASSIGNMENT: dword_7CA3D8 = 41; set friction-related code global to 41. [global:0x007CA3D8, source:raw]
    // ASSIGNMENT: flt_7CA3DC = 0.0; initialize adjacent float global to 0.0. [global:0x007CA3DC, source:raw]
    // CALL: Call InitFloatGlobals_d054(); delegate further float-global initialization to the callee shown in raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionFrictionInit29(void) {
    //     dword_7CA3D8 = 41;
    //     flt_7CA3DC = 0.0;
    //     InitFloatGlobals_d054();
    //   }
    // UNRESOLVED: Callee InitFloatGlobals_d054 has no address or prototype in the packet; packet callees list is empty.
    // UNRESOLVED: Semantic meaning of global pair 0x007CA3D8/0x007CA3DC (code + float) is not established.
}
