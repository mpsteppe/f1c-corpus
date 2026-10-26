// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CD40
// Canonical corpus name: CollisionGlobalsInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalsInit_0044cd40.c

void UnknownObject::CollisionGlobalsInit()
{
    // Initializes a pair of adjacent collision globals: writes the literal 33 into dword_7CA50C and 0.0 into flt_7CA510, then calls the InitializePhysicsConstants helper. No branches, arguments, or local state.
    // ASSIGNMENT: Write dword_7CA50C = 33. [global:0x007CA50C, source:raw]
    // ASSIGNMENT: Write flt_7CA510 = 0.0. [global:0x007CA510, source:raw]
    // CALL: Call the InitializePhysicsConstants helper function. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CA50C = 33;
    //   flt_7CA510 = 0.0;
    //   InitializePhysicsConstants();
    // UNRESOLVED: The callee named InitializePhysicsConstants in the raw source has no callee entry in the packet, so its address and semantics are unevidenced.
    // UNRESOLVED: Meaning of the 33 literal and the purpose of the zeroed float are unknown; the vehicle subsystem tag is the only hint.
    // UNRESOLVED: No callers are known, so when or how often this initializer runs is unevidenced.
}
