// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CCE0
// Canonical corpus name: CollisionMaterialInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialInit_0044cce0.c

void UnknownObject::CollisionMaterialInit()
{
    // Initializes a pair of adjacent collision/material globals: writes the literal 32 into dword_7CD158 and 0.0 into flt_7CD15C, then calls the sub_44CCF4 helper. No branches, arguments, or local state.
    // ASSIGNMENT: Write dword_7CD158 = 32. [global:0x007CD158, source:raw]
    // ASSIGNMENT: Write flt_7CD15C = 0.0. [global:0x007CD15C, source:raw]
    // CALL: Call the sub_44CCF4 helper function. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD158 = 32;
    //   flt_7CD15C = 0.0;
    //   sub_44CCF4();
    // UNRESOLVED: The callee named sub_44CCF4 in the raw source has no callee entry in the packet, so its address (implied by the name only) and semantics are unevidenced.
    // UNRESOLVED: Meaning of the 32 literal and the purpose of the zeroed float are unknown; the vehicle subsystem tag is the only hint.
    // UNRESOLVED: No callers are known, so when or how often this initializer runs is unevidenced.
}
