// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465FD0
// Canonical corpus name: CollisionDistanceReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionDistanceReset_00465fd0.c

void UnknownObject::CollisionDistanceReset()
{
    // Zero-argument, void-returning reset routine under the vehicle subsystem. It writes the decimal literal 0 into the global dword_7CD460 and the decimal literal -1 into the adjacent global dword_7CD464. The packet carries no callers, callees, fields, or guards, so the collision-distance state these globals represent and its consumer are not identified.
    // ASSIGNMENT: Write the decimal literal 0 into global dword_7CD460. [source:raw, global:0x007CD460]
    // ASSIGNMENT: Write the decimal literal -1 into global dword_7CD464. [source:raw, global:0x007CD464]

    // Conservative worker pseudocode:
    //   void CollisionDistanceReset() {
    //     dword_7CD460 = 0;
    //     dword_7CD464 = -1;
    //   }
    // UNRESOLVED: The collision-distance semantics of dword_7CD460 and dword_7CD464 are not established; the packet has no read sites, writers other than this function, or consuming subsystem evidence.
    // UNRESOLVED: The -1 sentinel written to dword_7CD464 is preserved as-is per packet evidence; its intended meaning (e.g. invalid distance marker) is not asserted.
}
