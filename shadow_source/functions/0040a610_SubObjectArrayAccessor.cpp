// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040A610
// Canonical corpus name: UtilityFunction_a610
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_a610_0040a610.c

void UnknownObject::SubObjectArrayAccessor()
{
    // Indexed sub-object accessor: returns the pointer stored at this[4+index] for an index in 0..8 (fields this+0x10 through this+0x30) and returns 0 for any out-of-range index. The dispatch is a switch driven by the jump table at jpt_40A61B. Called by ModeDispatchedSubsystemCall (0040d0b0).
    // GUARD: Dispatch on a2 with cases 0..8; the default case (out-of-range index) returns 0 [source:raw]
    // CALCULATION: The switch is compiled to a jump through the read-only table jpt_40A61B [global:0x0040A658, source:raw]
    // ASSIGNMENT: For index i in 0..8 returns the sub-object pointer at this[4+i], i.e. fields this+0x10 through this+0x30 [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // RETURN: Returns the selected slot value, or the initialized zero for out-of-range indices [source:raw]
    // CALL: Invoked by ModeDispatchedSubsystemCall (0040d0b0), the only known caller in this packet [caller:0x0040D0B0, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   switch (a2) {
    //     case 0: result = this[4]; break;
    //     case 1: result = this[5]; break;
    //     case 2: result = this[6]; break;
    //     case 3: result = this[7]; break;
    //     case 4: result = this[8]; break;
    //     case 5: result = this[9]; break;
    //     case 6: result = this[10]; break;
    //     case 7: result = this[11]; break;
    //     case 8: result = this[12]; break;
    //     default: return result;
    //   }
    //   return result;
    // UNRESOLVED: The meaning of the nine sub-object slots (this+0x10..this+0x30) and the owning object type are not identifiable from this packet
    // UNRESOLVED: The legacy ABI label (General_utility_function_See_decompiled_code_for) carries no semantic information
}
