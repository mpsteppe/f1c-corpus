// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F31F0
// Canonical corpus name: sub_4F31F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F31F0_004f31f0.c

void UnknownObject::tireModelZeroInit()
{
    // Zero-initializer. Runs a 6-iteration loop that clears 6 DWORDs per iteration starting at this+4 (DWORD units) with stride 6 DWORDs, then explicitly zeroes fields this+0x90 through this+0xA4 and returns this. No reads, no globals, no callees.
    // LOOP: Zero 6 DWORDs per iteration for 6 iterations, starting at this+4 (DWORD units) and advancing by 6 DWORDs each pass, covering the object head region. [source:raw, function:0x004F31F0]
    // ASSIGNMENT: Zero field this+0x10. [field:this:0x00000010]
    // ASSIGNMENT: Zero field this+0x14. [field:this:0x00000014]
    // ASSIGNMENT: Zero field this+0x90. [field:this:0x00000090]
    // ASSIGNMENT: Zero field this+0x94. [field:this:0x00000094]
    // ASSIGNMENT: Zero field this+0x98. [field:this:0x00000098]
    // ASSIGNMENT: Zero field this+0x9C. [field:this:0x0000009C]
    // ASSIGNMENT: Zero field this+0xA0. [field:this:0x000000A0]
    // ASSIGNMENT: Zero field this+0xA4. [field:this:0x000000A4]
    // RETURN: Return this (chained init style). [function:0x004F31F0, source:raw]
    // UNKNOWN: Caller context: invoked by TireModelDataInit during tire-model data setup. [caller:0x004F34E0]

    // Conservative worker pseudocode:
    //   v2 = this + 4;
    //   v3 = 6;
    //   do {
    //     v2[-4] = 0; v2[-3] = 0; v2[-2] = 0; v2[-1] = 0; v2[0] = 0; v2[1] = 0;
    //     v2 += 6;
    //   } while (--v3);
    //   result[36] = 0; result[37] = 0; result[38] = 0; result[39] = 0; result[40] = 0; result[41] = 0;
    //   return this;
    // UNRESOLVED: Object identity and semantic meaning of the zeroed region.
    // UNRESOLVED: Whether this is a constructor or a reset routine.
    // UNRESOLVED: Loop also clears offsets not present in the packet field list; they are not asserted here.
}
