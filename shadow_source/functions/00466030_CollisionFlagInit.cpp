// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466030
// Canonical corpus name: CollisionFlagInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionFlagInit_00466030.c

void UnknownObject::CollisionFlagInit()
{
    // Zero-argument, void-returning initializer under the vehicle subsystem. It writes the decimal literal 0 into the global dword_7CD468 and the decimal literal -1 into the adjacent global dword_7CD46C. The packet carries no callers, callees, fields, or guards, so the collision-flag state these globals represent and its consumer are not identified.
    // ASSIGNMENT: Write the decimal literal 0 into global dword_7CD468. [source:raw, global:0x007CD468]
    // ASSIGNMENT: Write the decimal literal -1 into global dword_7CD46C. [source:raw, global:0x007CD46C]

    // Conservative worker pseudocode:
    //   void CollisionFlagInit() {
    //     dword_7CD468 = 0;
    //     dword_7CD46C = -1;
    //   }
    // UNRESOLVED: The collision-flag semantics of dword_7CD468 and dword_7CD46C are not established; the packet has no read sites, writers other than this function, or consuming subsystem evidence.
    // UNRESOLVED: The -1 sentinel written to dword_7CD46C is preserved as-is per packet evidence; its intended meaning (e.g. cleared flag marker) is not asserted.
}
