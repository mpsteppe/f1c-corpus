// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DA00
// Canonical corpus name: CollisionStateInit1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit1_0044da00.c

void UnknownObject::InitCollisionState()
{
    // Zero-argument collision-state initializer. Writes 43 to the first dword of the global block at dword_7CCF18 and zeroes the five following dwords (dword_7CCF1C through dword_7CCF2C). Returns 0. Not reached from the tick root frame path; static callers are unknown.
    // ASSIGNMENT: Set dword_7CCF18[0] to the state init literal 43 [global:0x007CCF18, source:raw]
    // ASSIGNMENT: Zero the state selector/counter field dword_7CCF1C [global:0x007CCF1C, source:raw]
    // ASSIGNMENT: Zero the state selector/counter field dword_7CCF20 [global:0x007CCF20, source:raw]
    // ASSIGNMENT: Zero the state selector/counter field dword_7CCF24 [global:0x007CCF24, source:raw]
    // ASSIGNMENT: Zero the state selector/counter field dword_7CCF28 [global:0x007CCF28, source:raw]
    // ASSIGNMENT: Zero the state selector/counter field dword_7CCF2C [global:0x007CCF2C, source:raw]
    // RETURN: Return 0 as the initialization result [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionStateInit1() {
    //     dword_7CCF18[0] = 43;
    //     dword_7CCF1C = 0;
    //     dword_7CCF20 = 0;
    //     dword_7CCF24 = 0;
    //     dword_7CCF28 = 0;
    //     dword_7CCF2C = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the magic value 43 written to dword_7CCF18[0] is unknown.
    // UNRESOLVED: Owning class of the collision-state global block is unknown; owner stays UnknownObject.
    // UNRESOLVED: The block's selector/counter semantics are DERIVED from the vehicle subsystem tag and the existing-analysis prose only, not proven by static or runtime evidence.
}
