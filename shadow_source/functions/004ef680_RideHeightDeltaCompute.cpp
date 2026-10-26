// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF680
// Canonical corpus name: RideHeightDelta
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RideHeightDelta_004ef680.c

void UnknownObject::RideHeightDeltaCompute()
{
    // Computes a ride-height delta and writes a small output vector. The output first dword (a2) is zeroed, the fourth float slot (a2 + 8) is set to the track Y coordinate this[0x74C], and the second slot (a2 + 4) is overwritten with the average pitch component (this[0x3688] - this[0x3708] + this[0x3590] - this[0x3610]) * 0.5. Returns the output pointer a2.
    // ASSIGNMENT: Zero the first dword of the output vector (a2). [source:raw]
    // ASSIGNMENT: Copy track Y coordinate this[0x74C] into output slot a2 + 8. [field:this:0x0000074C, source:raw]
    // CALCULATION: Write average ride height delta to output slot a2 + 4: (this[0x3688] - this[0x3708] + this[0x3590] - this[0x3610]) * 0.5. The source first writes a 0 dword to a2 + 4, which is immediately overwritten by this float result (dead store). [field:this:0x00003590, field:this:0x00003610, field:this:0x00003688, field:this:0x00003708, source:raw]
    // RETURN: Return the output vector pointer a2. [source:raw]

    // Conservative worker pseudocode:
    //   out[0] = 0;
    //   out[2] = this[0x74C];
    //   out[1] = (this[0x3688] - this[0x3708] + this[0x3590] - this[0x3610]) * 0.5;
    //   return out;
    // UNRESOLVED: Global flt_59E450 (0x0059E450) is listed in the packet globals but is absent from the raw source text; its role in this function is unresolved.
    // UNRESOLVED: Per-corner mapping of the four ride-height offsets (front/rear/left/right) is not proven by raw source; names come from existing analysis prose.
    // UNRESOLVED: The initial 0 dword write to a2 + 4 is a dead store produced by the decompiler ordering.
}
