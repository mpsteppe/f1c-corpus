// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4800
// Canonical corpus name: BitfieldSetter_4800
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldSetter_4800_004b4800.c

void UnknownObject::BitfieldSetBit()
{
    // Set a single bit in a per-row byte bitmap. Given a byte-array `this`, sets bit a3%8 of the byte at this[13*a2 + 53 + a3/8] and returns a3/8. Row selector a2 picks a 13-byte stride; the constant 53 is a fixed base offset inside the row. Unconditional: no guard on a3, no test-and-set, no return-value status beyond the byte index.
    // CALCULATION: Derive byte index a3/8 and bit mask 1 << (a3%8) from the bit index a3. [source:raw]
    // ASSIGNMENT: OR the bit mask into this[13*a2 + 53 + a3/8], setting the selected bit in row a2. [source:raw]
    // RETURN: Return the computed byte index a3/8. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B4800(BYTE *this, int a2, int a3) {
    //     int byte_idx = a3 / 8;
    //     this[13 * a2 + 53 + byte_idx] |= 1 << (a3 % 8);
    //     return byte_idx;
    //   }
    // UNRESOLVED: Owner object and meaning of the 13-byte row stride are unknown.
    // UNRESOLVED: Meaning of the fixed base offset 53 inside each row is unproven.
    // UNRESOLVED: No bounds guard: callers must ensure a3 selects a valid bit within the row.
}
