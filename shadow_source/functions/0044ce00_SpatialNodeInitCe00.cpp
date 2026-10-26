// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CE00
// Canonical corpus name: SpatialNodeInit_ce00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialNodeInit_ce00_0044ce00.c

void UnknownObject::SpatialNodeInitCe00()
{
    // Straight-line initializer at 0x0044CE00: stores the integer 35 into dword_7CA438, zeroes the adjacent float flt_7CA43C, then invokes GlobalStateInitializer_ce14() (named callee in the raw source; its address is absent from the packet callee facts). No branches.
    // ASSIGNMENT: Set dword_7CA438 = 35, the size/count constant for this state block. [global:0x007CA438, source:raw]
    // ASSIGNMENT: Set flt_7CA43C = 0.0, zeroing the float field adjacent to dword_7CA438. [global:0x007CA43C, source:raw]
    // CALL: Invoke GlobalStateInitializer_ce14(), the named callee in the raw source, which writes the next adjacent global pair. [source:raw]

    // Conservative worker pseudocode:
    //   void SpatialNodeInitCe00() {
    //     dword_7CA438 = 35;
    //     flt_7CA43C = 0.0;
    //     GlobalStateInitializer_ce14();
    //   }
    // UNRESOLVED: The address and identity of the GlobalStateInitializer_ce14() callee are not present in the packet's callee facts; only its name appears in the raw source.
    // UNRESOLVED: No static callers or frame-path evidence exist in the packet, so when this initializer runs is unknown.
    // UNRESOLVED: The semantic meaning of the 35 constant and the adjacent zeroed float cannot be determined from this function alone.
}
