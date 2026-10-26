// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CF34
// Canonical corpus name: GlobalStateInitializer_cf34
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_cf34_0044cf34.c

void UnknownObject::GlobalStateInitializer_cf34()
{
    // Startup-time initializer that writes two globals at 0x7CA3B0/0x7CA3B4: the float flt_7CA3B0 is set to 0.0 and the dword dword_7CA3B4 is set to the decimal literal 1065353216. No guards, no callees, no parameters. Named Global_State_Initializer_44cf34 by the ABI lead; the raw source shows only these two stores.
    // ASSIGNMENT: Set flt_7CA3B0 to 0.0. [global:0x007CA3B0, source:raw]
    // ASSIGNMENT: Set dword_7CA3B4 to the decimal literal 1065353216. [global:0x007CA3B4, source:raw]

    // Conservative worker pseudocode:
    //   flt_7CA3B0 = 0.0;
    //   dword_7CA3B4 = 1065353216;
    // UNRESOLVED: The semantic meaning of the decimal literal 1065353216 stored to dword_7CA3B4 is not established; no IEEE-754 or integer interpretation is asserted from this packet.
    // UNRESOLVED: The calling context (which startup path invokes this initializer) is not present in the packet; callers list is empty.
    // UNRESOLVED: The identity of the object owning these two globals is unknown.
}
