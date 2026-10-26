// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B47A0
// Canonical corpus name: ArithmeticComparison_47a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_47a0_004b47a0.c

void UnknownObject::BitmapFlagSetClear()
{
    // Set or clear a single bit in a per-row bitmap. Bit index a5 selects the bit; the sentinel a5==255 makes the call a no-op returning a1 unchanged. Otherwise computes the row base v6 = 13*a4 + a1 + 1, reads the current byte at v6 + a5/8, writes v7|v8 (set) when a3 is nonzero or ~v7&v8 (clear) when a3 is zero, and returns a5/8. a2 is never read. The 13-byte row stride matches the sibling routines sub_4B4800 and sub_4B4840, which treat the same object with per-row bitmaps.
    // GUARD: a5 == 255 is a sentinel: skip all work and return a1 unchanged. [source:raw]
    // CALCULATION: Compute row base v6 = 13*a4 + a1 + 1, the byte address of the bitmap row for entry a4. [source:raw]
    // CALCULATION: Derive byte index a5/8 and bit mask v7 = 1 << (a5%8) from the bit index a5. [source:raw]
    // CALCULATION: Read the current byte v8 at v6 + a5/8 before modifying it. [source:raw]
    // GUARD: a3 selects the operation: nonzero means set the bit, zero means clear it. [source:raw]
    // ASSIGNMENT: When a3 is nonzero, write v7|v8 at v6 + a5/8, setting the selected bit. [source:raw]
    // ASSIGNMENT: When a3 is zero, write ~v7 & v8 at v6 + a5/8, clearing the selected bit. [source:raw]
    // RETURN: Return a5/8 on the set/clear path, or a1 on the a5==255 path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B47A0(int a1, int a2, char a3, int a4, int a5) {
    //     if (a5 == 255) return a1;
    //     int v6 = 13 * a4 + a1 + 1;
    //     int byte_idx = a5 / 8;
    //     char mask = 1 << (a5 % 8);
    //     char cur = *(BYTE *)(v6 + byte_idx);
    //     *(BYTE *)(v6 + byte_idx) = a3 ? (char)(cur | mask) : (char)(cur & ~mask);
    //     return byte_idx;
    //   }
    // UNRESOLVED: Parameter a2 is never read; its meaning is unknown.
    // UNRESOLVED: Owner object and the meaning of the 13-byte-per-row structure are unknown.
    // UNRESOLVED: Purpose of the +1 flag offset and the exact meaning of a1 are caller-defined.
    // UNRESOLVED: a5==255 sentinel is inferred from the guard; the flag space is 256 bits (a5 in 0..255).
}
