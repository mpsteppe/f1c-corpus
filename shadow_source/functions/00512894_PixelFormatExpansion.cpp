// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512894
// Canonical corpus name: PixelFormatExpansion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelFormatExpansion_00512894.c

void UnknownObject::PixelFormatExpansion()
{
    // One step of an in-place pixel-format expansion. Reads the base-format byte at this+8 (0 or 2) and the bit-depth state byte at this+9 (8 or 16), expands the pixel buffer at a2 from the current byte-per-pixel width to the next one, then writes back the stride (this+11), bytes-per-pixel (this+10) and expanded count (this+4). Returns the new count.
    // GUARD: Read pixel count at this+0 and base-format byte at this+8: value 0 selects the 2-byte-family path, value 2 the 4-byte-family path; any other value returns the count unchanged. [field:this:0x00000000, field:this:0x00000008]
    // GUARD: Within base format 0, test the bit-depth state byte at this+9 equals 8 to select the 1-to-2-byte-per-pixel step; return unchanged when the state is neither 8 nor 16. [field:this:0x00000009]
    // LOOP: Base 0, state 8: expand in place from 1 to 2 bytes per pixel, walking the buffer backward and interleaving the source byte with the fill byte; then set bytes-per-pixel (this+10) to 2, stride (this+11) to 16, and double the count. [field:this:0x0000000A, field:this:0x0000000B, source:raw]
    // LOOP: Base 0, state 16: expand in place from 2 to 4 bytes per pixel, spreading each source byte over 4 output bytes with color/alpha fill; then set bytes-per-pixel (this+10) to 2, stride (this+11) to 32, and quadruple the count. [field:this:0x00000009, field:this:0x0000000A, field:this:0x0000000B, source:raw]
    // LOOP: Base 2, state 8: expand in place from 1 to 4 bytes per pixel; then set stride (this+11) to 32, bytes-per-pixel (this+10) to 4, and quadruple the count. [field:this:0x0000000A, field:this:0x0000000B, source:raw]
    // LOOP: Base 2, state 16: expand in place from 4 to 8 bytes per pixel; then set stride (this+11) to 64, bytes-per-pixel (this+10) to 4, and octuple the count. [field:this:0x0000000A, field:this:0x0000000B, source:raw]
    // ASSIGNMENT: Write the expanded count to the dword at this+4. [field:this:0x00000004]
    // RETURN: Return the expanded count. [source:raw]

    // Conservative worker pseudocode:
    //   PixelFormatExpansion(a1, a2, a3, a4) {
    //     count = dword(a1, +0); base = byte(a1, +8); state = byte(a1, +9);
    //     if (base == 0) {
    //       if (state == 8) { expand_1_to_2(a2, count, a3, a4); byte(a1,+10)=2; byte(a1,+11)=16; count *= 2; }
    //       else if (state == 16) { expand_2_to_4(a2, count, a3, a4); byte(a1,+10)=2; byte(a1,+11)=32; count *= 4; }
    //     } else if (base == 2) {
    //       if (state == 8) { expand_1_to_4(a2, count, a3, a4); byte(a1,+11)=32; byte(a1,+10)=4; count *= 4; }
    //       else if (state == 16) { expand_4_to_8(a2, count, a3, a4); byte(a1,+11)=64; byte(a1,+10)=4; count *= 8; }
    //     }
    //     dword(a1, +4) = count;
    //     return count;
    //   }
    // UNRESOLVED: Exact byte-interleave pattern of each expansion branch (which position receives the color word low byte vs byte-1) is not fully resolved from source:raw.
    // UNRESOLVED: Whether the sign flag a4 selects a final tail-write variant is inferred, not confirmed.
    // UNRESOLVED: Meaning of the base-format enum (0 vs 2) outside this state machine is unknown.
    // UNRESOLVED: Single caller sub_51389E; on_frame_path=false.
}
