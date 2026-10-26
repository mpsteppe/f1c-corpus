// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500190
// Canonical corpus name: VehicleDataBufferClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDataBufferClear_00500190.c

void UnknownObject::VehicleDataBufferClear()
{
    // Clears a 0x1B0-byte vehicle data buffer starting at this+110 floats (0x1B8 bytes) to zero, then writes the sentinel -9.9999997e37 (~ -FLT_MAX) at this+111 floats (0x1BC). Returns 0. Used during list-iteration reset.
    // ASSIGNMENT: Initialize the return value to 0. [source:raw]
    // CALL: Zero-fill 0x1B0 bytes at this+110 floats (offset 0x1B8) via memset. [source:raw]
    // ASSIGNMENT: Write the sentinel value -9.9999997e37 to this+111 floats (offset 0x1BC), overwriting the start of the cleared region. [field:this:0x000001BC, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_500190(float *this) {
    //     memset(this + 110, 0, 0x1B0);
    //     this[111] = -9.9999997e37f;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the cleared buffer (0x1B0 bytes at +0x1B8) and of the -FLT_MAX sentinel at +0x1BC depend on the unknown owning object.
    // UNRESOLVED: Global flt_5AD348 (0x005AD348) is listed as a read by static facts, but the raw decompiled source writes the sentinel literal directly; the global's exact role (possibly the source constant for the sentinel) is unclear.
    // UNRESOLVED: This function is invoked by FloatComparisonListIteration (0x004B5380); caller identity does not affect behavior inside this function.
    // UNRESOLVED: Legacy ABI lead name (abi:lead) and the function identity ref carry no additional behavior.
}
