// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3560
// Canonical corpus name: FlagSetterWithOR
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetterWithOR_004a3560.c

void UnknownObject::FlagSetterWithOR()
{
    // Stores a caller-supplied value a2 into the DWORD field at offset 0x4, then sets bit 1 (value 2) on the flags DWORD at offset 0x0, and returns the stored value. The bit-1 set on the leading flags word is consistent with a dirty/change marker signalling that the stored value was updated. Only known caller is PitStopOperationTimer (0x004A6340), which is on the frame path.
    // ASSIGNMENT: Record the incoming value a2 as the function result. [source:raw, abi:lead]
    // ASSIGNMENT: Store a2 into this[1], the DWORD field at offset 0x4. [source:raw, field:this:0x00000004]
    // CALCULATION: OR value 2 into this[0], the flags DWORD at offset 0x0, setting bit 1. [source:raw, field:this:0x00000000]
    // RETURN: Return the stored value a2. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   int FlagSetterWithOR(_DWORD *this, int value) {
    //     this[1] = value;     /* offset 0x4 * /
    //     this[0] |= 2u;       /* offset 0x0: set bit 1 dirty/change flag * /
    //     return value;
    //   }
    // UNRESOLVED: Meaning of the bit-1 flag on this[0] and the exact role of the stored value at offset 0x4 are not established by this function alone; the single caller PitStopOperationTimer suggests a pit-operation parameter store, unproven here.
    // UNRESOLVED: Whether the flags word accumulates other bits (read-modify-write vs. plain set) cannot be determined from this function.
}
