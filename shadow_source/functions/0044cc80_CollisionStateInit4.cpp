// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CC80
// Canonical corpus name: CollisionStateInit4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit4_0044cc80.c

void UnknownObject::CollisionStateInit4()
{
    // Initializes a pair of adjacent collision/state globals: writes the literal 31 into dword_7CC9BC and 0.0 into flt_7CC9C0, then calls the AudioRendererFloatConstantInitializer helper. No branches, arguments, or local state.
    // ASSIGNMENT: Write dword_7CC9BC = 31. [global:0x007CC9BC, source:raw]
    // ASSIGNMENT: Write flt_7CC9C0 = 0.0. [global:0x007CC9C0, source:raw]
    // CALL: Call the AudioRendererFloatConstantInitializer helper function. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CC9BC = 31;
    //   flt_7CC9C0 = 0.0;
    //   AudioRendererFloatConstantInitializer();
    // UNRESOLVED: The callee named AudioRendererFloatConstantInitializer in the raw source has no callee entry in the packet, so its address and semantics are unevidenced.
    // UNRESOLVED: Meaning of the 31 literal and the purpose of the zeroed float are unknown; the vehicle subsystem tag is the only hint.
    // UNRESOLVED: No callers are known, so when or how often this initializer runs is unevidenced.
}
