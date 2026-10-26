// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005123E0
// Canonical corpus name: sub_5123E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5123E0_005123e0.c

void UnknownObject::ConditionalPixelByteSwap()
{
    // Conditionally swaps byte pairs within a pixel buffer a2 based on a format descriptor a1: element count at this+0x0, format flags byte at this+0x8, and bits-per-pixel byte at this+0x9. The whole body is gated on bit 1 (mask 2) of the flags byte. When bpp==8 the function swaps bytes [0] and [2] of each group with group stride 3 (flags==2) or 4 (flags==6) — the classic RGB<->BGR channel swap. When bpp==16 it swaps bytes [0]<->[4] and [1]<->[5] of each group with stride 6 (flags==2) or 8 (flags==6). Count iterations are driven by the element count at this+0x0. The return value is a decompiler artifact (low byte of a pointer).
    // GUARD: Main gate: bit 1 (mask 2) of the format flags byte at this+0x8 must be set, otherwise the entire conversion is skipped. [field:this:0x00000008]
    // ASSIGNMENT: Read the iteration count from the DWORD at this+0x0. [field:this:0x00000000]
    // GUARD: Select the 8bpp paths when the bits-per-pixel byte at this+0x9 equals 8. [field:this:0x00000009]
    // GUARD: Within 8bpp, select the stride-3 path when the format flags byte equals 2. [field:this:0x00000008]
    // LOOP: 8bpp stride-3: for each of count elements swap byte 0 with byte 2 of each 3-byte group, advancing the buffer pointer by 3 per iteration (RGB<->BGR channel swap). [source:raw]
    // GUARD: Within 8bpp, select the stride-4 path when the format flags byte equals 6. [field:this:0x00000008]
    // LOOP: 8bpp stride-4: for each of count elements swap byte 0 with byte 2 of each 4-byte group, advancing by 4 per iteration (byte 3, e.g. alpha, left untouched). [source:raw]
    // GUARD: Select the 16bpp paths when the bits-per-pixel byte at this+0x9 equals 16. [field:this:0x00000009]
    // GUARD: Within 16bpp, select the stride-6 path when the format flags byte equals 2. [field:this:0x00000008]
    // LOOP: 16bpp stride-6: for each of count elements swap byte 0 with byte 4 and byte 1 with byte 5 of each 6-byte group, advancing by 6 per iteration. [source:raw]
    // GUARD: Within 16bpp, select the stride-8 path when the format flags byte equals 6. [field:this:0x00000008]
    // LOOP: 16bpp stride-8: for each of count elements swap byte 0 with byte 4 and byte 1 with byte 5 of each 8-byte group, advancing by 8 per iteration. [source:raw]
    // RETURN: Return (char)v2 where v2 is a pointer that was last overwritten with the buffer address or its low byte; the returned char is a decompiler artifact and carries no meaningful value. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_5123E0(int *desc, char *buf) {
    //     if (!((*(BYTE *)(desc + 2) /* this+0x8 * /) & 2))
    //       return (char)desc;
    //     int count = *desc;
    //     char *p = buf;
    //     if (*(BYTE *)desc + 9 == 8) {
    //       if (*(BYTE *)(desc + 2) == 2)        /* stride 3 * /
    //         while (count--) { swap(p[0], p[2]); p += 3; }
    //       else if (*(BYTE *)(desc + 2) == 6)   /* stride 4 * /
    //         while (count--) { swap(p[0], p[2]); p += 4; }
    //     } else if (*(BYTE *)desc + 9 == 16) {
    //       if (*(BYTE *)(desc + 2) == 2)        /* stride 6 * /
    //         while (count--) { swap(p[0], p[4]); swap(p[1], p[5]); p += 6; }
    //       else if (*(BYTE *)(desc + 2) == 6)   /* stride 8 * /
    //         while (count--) { swap(p[0], p[4]); swap(p[1], p[5]); p += 8; }
    //     }
    //     return (char)p;
    //   }
    // UNRESOLVED: Exact meaning of format flags values 2 vs 6 and the bpp byte (8 vs 16) is not established; interpretation as RGB<->BGR pixel channel swap is DERIVED from the byte-swap geometry.
    // UNRESOLVED: The 16bpp byte-pair swap (0<->4, 1<->5) does not map to a simple channel swap for common 565 formats; its true purpose is unknown.
    // UNRESOLVED: The returned char is a decompiler artifact of LOBYTE pointer juggling; the original return semantics are unclear.
    // UNRESOLVED: Caller sub_51389E (0x0051389E) determines the descriptor layout and pixel format.
}
