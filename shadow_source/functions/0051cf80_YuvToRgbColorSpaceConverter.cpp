// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051CF80
// Canonical corpus name: sub_51CF80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51CF80_0051cf80.c

void UnknownObject::YuvToRgbColorSpaceConverter()
{
    // Dual-output color conversion structurally twin to TexturePaletteColorLookup but writing two independent destination rows. Reads three source streams from the a2 array (a0 pair at byte offset 8*a3, a1/a2 at 4*a3), indexes four lookup tables by bytes from those streams, and writes 3 output bytes per pixel into each of two destination streams held at *a4 and *(a4+4). The main loop converts two pixels per stream per iteration and runs a1[23] >> 1 times; an odd row width writes one trailing pixel per stream. Each output channel is byte(source byte + table value + base), middle channel blending two tables via >> 16.
    // ASSIGNMENT: Load the LUT sub-object v4 from this->+0x19C (a1[103]); its entries v4[4..7] hold the four lookup tables. [field:this:0x0000019C, source:raw]
    // ASSIGNMENT: Read the additive base from this->+0x11C (a1[71]) and the row width from this->+0x5C (a1[23]). [field:this:0x0000011C, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Read the four lookup-table pointers from v4[4] (+0x1AC), v4[5] (+0x1B0), v4[6] (+0x1B4) and v4[7] (+0x1B8). [field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8, source:raw]
    // ASSIGNMENT: Resolve source streams: the a2[0] entry yields a pointer pair at byte offset 8*a3, and a2[1]/a2[2] yield pointers at 4*a3; take two destination rows from *a4 and *(a4+4). [source:raw]
    // GUARD: When a1[23] >> 1 is zero the two-pixel-per-stream loop is skipped entirely. [field:this:0x0000005C, source:raw]
    // LOOP: Two-pixel-per-stream loop running a1[23] >> 1 times, writing 12 output bytes per iteration (6 into each destination stream). [field:this:0x0000005C, source:raw]
    // CALCULATION: Index the four tables by bytes from the two auxiliary source streams; the middle channel sums two table values and shifts the sum >> 16. [field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8, source:raw]
    // ASSIGNMENT: Write two RGB pixels per destination stream per iteration, each channel computed as byte(source byte + table value + base). [field:this:0x0000011C, source:raw]
    // GUARD: When the row width is odd (a1[23] & 1), process one trailing pixel in each destination stream after the loop. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Write the final 3-byte pixel into each of the two destination streams using the same table lookups and base addition. [field:this:0x0000011C, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8, source:raw]
    // RETURN: Return the low byte of the last computed channel value (LOBYTE of the base register v5). [source:raw]

    // Conservative worker pseudocode:
    //   char YuvToRgbColorSpaceConverter(_DWORD* obj, _DWORD* srcArr, int planeBase, int dstPair) {
    //     _DWORD* lut = (_DWORD*)obj[103];
    //     int base = obj[71];
    //     int rowWidth = obj[23];
    //     int t0 = lut[4], t1 = lut[5], t2 = lut[6], t3 = lut[7];
    //     unsigned char* sA = *(unsigned char**)(srcArr[0] + 8 * planeBase);
    //     unsigned char* sB = sA + 1;
    //     unsigned char* s1 = *(unsigned char**)(4 * planeBase + srcArr[1]);
    //     unsigned char* s2 = *(unsigned char**)(4 * planeBase + srcArr[2]);
    //     _BYTE* dstA = *(_BYTE**)dstPair;
    //     _BYTE* dstB = *(_BYTE**)(dstPair + 4);
    //     if (rowWidth >> 1) {
    //       int n = rowWidth >> 1;
    //       do {
    //         int b1 = *s1++;
    //         int i0 = 4 * *s2;
    //         s2++;
    //         int c0 = *(int*)(i0 + t0);
    //         int c1 = (*(int*)(i0 + t2) + *(int*)(4 * b1 + t3)) >> 16;
    //         int c2 = *(int*)(4 * b1 + t1);
    //         int a0 = *sA++;
    //         *dstA = (int)a0 + c0 + base;
    //         dstA[1] = (int)a0 + c1 + base;
    //         dstA[2] = c2 + (int)a0 + base;
    //         int a1 = *sA++;
    //         dstA[3] = (int)a1 + c0 + base;
    //         dstA[4] = (int)a1 + c1 + base;
    //         dstA[5] = c2 + (int)a1 + base;
    //         dstA += 6;
    //         int b0 = *sB++;
    //         *dstB = (int)b0 + c0 + base;
    //         dstB[1] = (int)b0 + c1 + base;
    //         dstB[2] = c2 + (int)b0 + base;
    //         int b1b = *sB++;
    //         dstB[3] = (int)b1b + c0 + base;
    //         dstB[4] = (int)b1b + c1 + base;
    //         dstB[5] = c2 + (int)b1b + base;
    //         dstB += 6;
    //       } while (--n);
    //     }
    //     if (rowWidth & 1) {
    //       int b1 = *s1, i0 = 4 * *s2, i2 = 4 * b1;
    //       int c0 = *(int*)(i0 + t0);
    //       int c1 = (*(int*)(i0 + t2) + *(int*)(i2 + t3)) >> 16;
    //       int c2 = *(int*)(i2 + t1);
    //       int a0 = *sA, b0 = *sB;
    //       *dstA = (int)a0 + c0 + base;
    //       dstA[1] = (int)a0 + c1 + base;
    //       dstA[2] = c2 + (int)a0 + base;
    //       *dstB = (int)b0 + c0 + base;
    //       dstB[1] = (int)b0 + c1 + base;
    //       dstB[2] = c2 + (int)b0 + base;
    //     }
    //     return (char)base;
    //   }
    // UNRESOLVED: Exact color-space semantics of the four lookup tables; the legacy ABI label suggests YUV-to-RGB conversion but this is not runtime-confirmed.
    // UNRESOLVED: Meaning of the two destination rows and the two interleaved source streams in the a2[0] pointer pair.
    // UNRESOLVED: Identity of object a1 and the render-path caller; no static callers or frame-path evidence exist.
    // UNRESOLVED: Why the return value is only the low byte of the base register rather than a meaningful status or pointer.
}
