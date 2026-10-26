// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586FA0
// Canonical corpus name: BitfieldEncoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldEncoder_00586fa0.c

void UnknownObject::EncodeBitfieldRun()
{
    // Encodes a run of bits into a bitfield buffer. Reads a bit-run descriptor from the array at this+0x8 indexed by a2: each descriptor holds a 16-bit starting bit index (*v6) and a 16-bit run length (v5). Builds a mask of the run's bits, intersects it with the caller's mask a3, then walks the run's bits in descending index order setting or clearing each bit in the byte buffer at *this. Returns 1 on success.
    // CALCULATION: Load the descriptor array pointer v4 = this[2] (field at this+0x8). [field:this:0x00000008, source:raw]
    // CALCULATION: Read the run descriptor for index a2: run length v5 = *(unsigned __int16 *)(v4 + 4*a2 + 2) and starting bit index *v6 = *(unsigned __int16 *)(v4 + 4*a2). [field:this:0x00000008, source:raw]
    // GUARD: If the run length v5 is zero, skip mask construction and the write loop; v7 remains 0. [source:raw]
    // CALCULATION: Build the run mask v7 by setting the low v5 bits (do { v7 |= 1 << v8++; } while (v8 < v5)). [source:raw]
    // CALCULATION: Intersect the run mask with the caller mask: v15 = v7 & a3, selecting which bits of the run are to be set. [source:raw]
    // LOOP: Loop over v9 = 0..v5-1 with bit index i - v9 descending from i = *v6 + v5 - 1; each iteration computes the target byte (i - v9) >> 3 into the buffer at *this and the bit mask 1 << ((i - v9) & 7). [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Set or clear the target bit: if bit v9 of v15 is set, OR the bit mask into the byte; otherwise AND the byte with the complement of the mask. [field:this:0x00000000, source:raw]
    // RETURN: Return 1 to signal success. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_586FA0(int *this, int a2, int a3) {
    //     unsigned char *descs = (unsigned char *)this[2];
    //     unsigned int v5 = *(unsigned __int16 *)(descs + 4*a2 + 2);
    //     unsigned __int16 base = *(unsigned __int16 *)(descs + 4*a2);
    //     unsigned int mask = 0;
    //     for (unsigned int k = 0; k < v5; ++k) mask |= 1u << k;
    //     unsigned int v15 = mask & a3;
    //     int top = base + v5 - 1;
    //     for (unsigned int j = 0; j < v5; ++j) {
    //       unsigned int bit = top - j;
    //       unsigned char *p = (unsigned char *)this[0] + (bit >> 3);
    //       unsigned char bm = (unsigned char)(1u << (bit & 7));
    //       *p = ((1u << j) & v15) ? (*p | bm) : (*p & ~bm);
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Layout and meaning of the descriptor array at this+0x8 (per-entry semantics of the 16-bit base index and 16-bit run length).
    // UNRESOLVED: Meaning of the bitfield buffer at *this and of the caller-supplied mask a3.
    // UNRESOLVED: Whether descending bit iteration is semantically required or an implementation detail.
}
