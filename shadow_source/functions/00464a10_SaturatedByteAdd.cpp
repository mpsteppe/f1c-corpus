// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464A10
// Canonical corpus name: SaturatedByteAdd
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SaturatedByteAdd_00464a10.c

void UnknownObject::SaturatedByteAdd()
{
    // Saturating 7-bit add on the byte at this+0x0: masks the stored byte to 7 bits, adds a2, clamps the sum at 127, then writes back only the low 7 bits of the clamped result (preserving bit 7 of the stored byte via *this ^= (result ^ *this) & 0x7F). Returns the clamped sum. Bit 7 is treated as an independent flag bit, not part of the accumulator.
    // CALCULATION: Read the byte at offset 0x0 of this and mask it to the low 7 bits: *this & 0x7F. [field:this:0x00000000, source:raw]
    // CALCULATION: Add a2 to the 7-bit value: result = a2 + (*this & 0x7F). [source:raw]
    // GUARD: Clamp the sum at 127: if (result > 127) result = 127. [source:raw]
    // ASSIGNMENT: Write the low 7 bits of the clamped result back into the stored byte while preserving bit 7: *this ^= (result ^ *this) & 0x7F. [field:this:0x00000000, source:raw]
    // RETURN: Return the clamped sum as the function result. [source:raw]
    // CALL: Called by sub_464B10 (0x00464B10). [caller:0x00464B10, source:raw]

    // Conservative worker pseudocode:
    //   int sub_464A10(BYTE *this, int a2) {
    //     int result = a2 + (*this & 0x7F);
    //     if (result > 127)
    //       result = 127;
    //     *this ^= (result ^ *this) & 0x7F;
    //     return result;
    //   }
    // UNRESOLVED: Semantics and purpose of the preserved bit 7 (a separate flag bit carried through the accumulator) are caller-dependent.
    // UNRESOLVED: Meaning of a2 (increment amount) and the owner class are unknown here.
    // UNRESOLVED: Prelabel flags this as a structural twin of the FloatClamp cluster representative, but the field operation is integer, not float.
}
