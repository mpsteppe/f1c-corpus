// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CED4
// Canonical corpus name: InitFloatConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitFloatConstants_0044ced4.c

void UnknownObject::InitFloatConstants()
{
    // Startup-time initializer that writes two globals at 0x7CCBFC/0x7CCC00: the dword dword_7CCBFC is set to the decimal literal -1082130432 and the float flt_7CCC00 is set to 0.0. No guards, no callees, no parameters. Named InitFloatConstants by the ABI lead; the raw source shows only these two stores.
    // ASSIGNMENT: Set dword_7CCBFC to the decimal literal -1082130432. [global:0x007CCBFC, source:raw]
    // ASSIGNMENT: Set flt_7CCC00 to 0.0. [global:0x007CCC00, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCBFC = -1082130432;
    //   flt_7CCC00 = 0.0;
    // UNRESOLVED: The semantic meaning of the decimal literal -1082130432 stored to dword_7CCBFC is not established; no IEEE-754 or integer interpretation is asserted from this packet.
    // UNRESOLVED: The calling context (which startup path invokes this initializer) is not present in the packet; callers list is empty.
    // UNRESOLVED: The identity of the object owning these two globals is unknown.
}
