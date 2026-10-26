// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CE60
// Canonical corpus name: GlobalStateInitializer_ce60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_ce60_0044ce60.c

void UnknownObject::GlobalStateInitializerCe60()
{
    // Straight-line initializer at 0x0044CE60: stores the integer 36 into dword_7CA448, zeroes the adjacent float flt_7CA44C, then invokes InitFloatGlobals() (named callee in the raw source; its address is absent from the packet callee facts). No branches.
    // ASSIGNMENT: Set dword_7CA448 = 36, the size/count constant for this state block. [global:0x007CA448, source:raw]
    // ASSIGNMENT: Set flt_7CA44C = 0.0, zeroing the float field adjacent to dword_7CA448. [global:0x007CA44C, source:raw]
    // CALL: Invoke InitFloatGlobals(), the named callee in the raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void GlobalStateInitializerCe60() {
    //     dword_7CA448 = 36;
    //     flt_7CA44C = 0.0;
    //     InitFloatGlobals();
    //   }
    // UNRESOLVED: The address and identity of the InitFloatGlobals() callee are not present in the packet's callee facts; only its name appears in the raw source.
    // UNRESOLVED: No static callers or frame-path evidence exist in the packet, so when this initializer runs is unknown.
    // UNRESOLVED: The semantic meaning of the 36 constant and the adjacent zeroed float cannot be determined from this function alone.
}
