// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DA60
// Canonical corpus name: CollisionMaterialInit_da60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialInit_da60_0044da60.c

void UnknownObject::InitCollisionMaterialTable()
{
    // Zero-argument collision-material-table initializer. Writes 44 to the first dword of the global block at dword_7CCED0 and zeroes the five following dwords (dword_7CCED4 through dword_7CCEE4). Returns 0. Not reached from the tick root frame path; static callers are unknown.
    // ASSIGNMENT: Set dword_7CCED0[0] to the material init literal 44 [global:0x007CCED0, source:raw]
    // ASSIGNMENT: Zero the material property field dword_7CCED4 [global:0x007CCED4, source:raw]
    // ASSIGNMENT: Zero the material property field dword_7CCED8 [global:0x007CCED8, source:raw]
    // ASSIGNMENT: Zero the material property field dword_7CCEDC [global:0x007CCEDC, source:raw]
    // ASSIGNMENT: Zero the material property field dword_7CCEE0 [global:0x007CCEE0, source:raw]
    // ASSIGNMENT: Zero the material property field dword_7CCEE4 [global:0x007CCEE4, source:raw]
    // RETURN: Return 0 as the initialization result [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionMaterialInit_da60() {
    //     dword_7CCED0[0] = 44;
    //     dword_7CCED4 = 0;
    //     dword_7CCED8 = 0;
    //     dword_7CCEDC = 0;
    //     dword_7CCEE0 = 0;
    //     dword_7CCEE4 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the magic value 44 written to dword_7CCED0[0] is unknown.
    // UNRESOLVED: Owning class of the collision-material global block is unknown; owner stays UnknownObject.
    // UNRESOLVED: The block's material-table semantics are DERIVED from the vehicle subsystem tag and the existing-analysis prose only, not proven by static or runtime evidence.
}
