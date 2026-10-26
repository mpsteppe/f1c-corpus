// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CE74
// Canonical corpus name: InitFloatGlobals
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitFloatGlobals_0044ce74.c

void UnknownObject::InitFloatGlobals()
{
    // Startup-time initializer that writes two globals at 0x7CA450/0x7CA454: the float flt_7CA450 is set to 0.0 and the dword dword_7CA454 is set to the decimal literal 1065353216. No guards, no callees, no parameters. Named InitFloatGlobals by the ABI lead; the raw source shows only these two stores.
    // ASSIGNMENT: Set flt_7CA450 to 0.0. [global:0x007CA450, source:raw]
    // ASSIGNMENT: Set dword_7CA454 to the decimal literal 1065353216. [global:0x007CA454, source:raw]

    // Conservative worker pseudocode:
    //   flt_7CA450 = 0.0;
    //   dword_7CA454 = 1065353216;
    // UNRESOLVED: The semantic meaning of the decimal literal 1065353216 stored to dword_7CA454 is not established; no IEEE-754 or integer interpretation is asserted from this packet.
    // UNRESOLVED: The calling context (which startup path invokes this initializer) is not present in the packet; callers list is empty.
    // UNRESOLVED: The identity of the object owning these two globals is unknown.
}
