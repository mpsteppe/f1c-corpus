// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512850
// Canonical corpus name: BitExpandDecompress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitExpandDecompress_00512850.c

void UnknownObject::BitExpandDecompress()
{
    // One decompression/expansion step of a bit-expansion state machine. When the state byte at this+9 equals 16, deinterleaves the input buffer a2 by factor 2 (copying every second byte), packs the samples contiguously, then advances the state: sets state to 8, output stride (this+11) to 8 times the source stride (this+10), and element count (this+4) to count times source stride. Returns the state object pointer.
    // GUARD: Test state byte at this+9 equals 16; when not equal, skip the whole body and return the state object unchanged. [guard:0, field:this:0x00000009]
    // CALCULATION: Compute element count = dword at this+0 times the source-stride byte at this+10; if zero, skip the copy loop. [field:this:0x00000000, field:this:0x0000000A]
    // LOOP: Deinterleave: copy every second byte from the input buffer into a contiguous output region, count elements times. [source:raw]
    // STATE_TRANSITION: Advance state fields: set state byte at this+9 to 8, output-stride byte at this+11 to 8 times the source-stride byte, and dword at this+4 to count times source stride. [field:this:0x00000009, field:this:0x0000000B, field:this:0x0000000A, field:this:0x00000004]
    // RETURN: Return the state object pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   BitExpandDecompress(a1, a2) {
    //     if (state(a1, +9) != 16) return a1;
    //     count = dword(a1, +0) * byte(a1, +10);
    //     for (i = 0; i < count; i++) {
    //       a2[i] = a2[2*i];
    //     }
    //     byte(a1, +9) = 8;
    //     byte(a1, +11) = 8 * byte(a1, +10);
    //     dword(a1, +4) = count * byte(a1, +10);
    //     return a1;
    //   }
    // UNRESOLVED: Meaning of the state enum (16 -> 8) and of the stride fields at +10/+11 is derived from the state machine but not externally confirmed.
    // UNRESOLVED: Whether a2 is overwritten in place or must alias separate regions is unknown.
    // UNRESOLVED: Single caller sub_51389E; on_frame_path=false.
}
