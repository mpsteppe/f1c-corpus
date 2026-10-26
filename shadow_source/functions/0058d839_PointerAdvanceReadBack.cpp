// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D839
// Canonical corpus name: PointerAdvanceReadBack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PointerAdvanceReadBack_0058d839.c

void UnknownObject::PointerAdvanceReadBack()
{
    // Advances the dword pointer at a1 by 8 bytes and returns the 64-bit value that was stored just before the advance.
    // ASSIGNMENT: Increment the pointer value stored at a1 by 8 (two dwords). [source:raw, field:this:0x00000000]
    // CALCULATION: Dereference the location eight bytes before the new pointer value and return it as a 64-bit value. [source:raw, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   INT64 AdvanceReadBack(DWORD* a1) {
    //       *a1 += 8;
    //       return *(INT64*)(*a1 - 8);
    //   }
    // UNRESOLVED: Whether the 64-bit read is a double, an integer pair, or raw data is not determined by this function alone.
    // UNRESOLVED: The prelabel structural-twin note (FloatClamp, 004646c0) is DERIVED and not independently confirmed for this address.
}
