// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517F04
// Canonical corpus name: MemsetWithByteFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemsetWithByteFill_00517f04.c

void UnknownObject::MemsetWithByteFill()
{
    // Replicated-byte buffer fill. Builds a 32-bit pattern value by replicating the single fill byte a4 across all four byte lanes, fills the dword-aligned bulk of the buffer with that pattern via memset32, then covers the remaining a5 & 3 trailing bytes with a scalar memset using the original byte value. Returns the destination pointer a3.
    // CALCULATION: Replicate the fill byte a4 into both low byte lanes of a1 (LOBYTE and BYTE1 set to a4), then shift the combined value left by 16 and OR the low word back in to form a 4-byte repeating pattern value v5. [source:raw]
    // CALCULATION: Compute the dword-aligned bulk word count a5 >> 2. [source:raw]
    // CALL: Call memset32(a3, v5, a5 >> 2) to fill the dword-aligned bulk region with the replicated 32-bit pattern. [source:raw]
    // CALCULATION: Compute the tail position past the bulk region: a3 + 4 * (a5 >> 2). [source:raw]
    // CALL: Call memset(&a3[4 * (a5 >> 2)], a4, a5 & 3) to fill the residual 0 to 3 trailing bytes with the original fill byte a4. [source:raw]
    // RETURN: Return the destination buffer pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_517F04(int pattern_reg, int unused, char *dst, char fill, unsigned int count) {
    //     int pattern = fill | (fill << 8);
    //     pattern = (pattern << 16) | (pattern & 65535);
    //     memset32(dst, pattern, count >> 2);
    //     memset(&dst[4 * (count >> 2)], fill, count & 3);
    //     return dst;
    //   }
    // UNRESOLVED: The destination object and its element type are caller-supplied; only byte-copy semantics are visible here.
    // UNRESOLVED: a2 is unused by the decompiled body.
    // UNRESOLVED: The two callers (AudioBufferSizeCalc and sub_519019) use this as a generic fill, but their buffer layouts are not evidenced in this packet.
}
