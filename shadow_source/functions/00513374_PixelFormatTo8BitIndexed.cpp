// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513374
// Canonical corpus name: PixelFormatConverter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelFormatConverter_00513374.c

void UnknownObject::PixelFormatTo8BitIndexed()
{
    // Pixel format converter on a format-state object a1 with source/destination buffer a2, a 15-bit color lookup table a3 and an index remap table a4. When the format byte at offset 0x8 is 2 (4-byte pixels) or 6 (5-byte pixels), converts pixels to 8-bit indexed through the 15-bit LUT; when it is 3, remaps existing 8-bit indices through the secondary table a4. All conversion paths require the state byte at offset 0x9 to equal 8. On completion of the two LUT paths the function updates the state: byte count at offset 0x4 = (pixel_count * 8 + 7) >> 3, stride at offset 0xB = 8, format at offset 0x8 = 3 and bytes-per-pixel at offset 0xA = 1.
    // ASSIGNMENT: Read the format byte v5 from offset 0x8 and the pixel count result from offset 0x0 (a1[0]). [field:this:0x00000008, field:this:0x00000000, source:raw]
    // GUARD: Guard for the 4-byte-per-pixel path: format byte at offset 0x8 equals 2, LUT a3 is non-zero and state byte at offset 0x9 equals 8. [field:this:0x00000008, field:this:0x00000009, guard:0, source:raw]
    // LOOP: Loop over each of the pixel_count 4-byte pixels, reading 3 color bytes per step and writing one converted byte per step to the destination. [source:raw]
    // CALCULATION: Build a 15-bit color index from the three color bytes (((b >> 3) & 0x1F) | (4 * ((g & 0xF8) | (32 * (r & 0xF8))))) and look up the 8-bit output byte in the LUT at a3. [source:raw]
    // ASSIGNMENT: Write each converted byte to the destination buffer a2. [source:raw]
    // GUARD: Guard for the 5-byte-per-pixel path: format byte at offset 0x8 equals 6, LUT a3 is non-zero and state byte at offset 0x9 equals 8. [field:this:0x00000008, field:this:0x00000009, guard:0, source:raw]
    // LOOP: Loop over each of the pixel_count 5-byte pixels, reading 3 color bytes per step and writing one converted byte per step to the destination. [source:raw]
    // CALCULATION: Build the same 15-bit color index from the three color bytes and look up the 8-bit output byte in the LUT at a3. [source:raw]
    // GUARD: Guard for the index remap path: format byte at offset 0x8 equals 3, remap table a4 is non-zero and state byte at offset 0x9 equals 8. [field:this:0x00000008, field:this:0x00000009, guard:0, source:raw]
    // LOOP: Loop over the pixel_count existing indices, replacing each 8-bit index with the value read from the remap table a4 at that index. [source:raw]
    // ASSIGNMENT: On completion of either LUT conversion path, update the state object: stride at offset 0xB = 8, format at offset 0x8 = 3, bytes-per-pixel at offset 0xA = 1 and byte count at offset 0x4 = (pixel_count * state + 7) >> 3. [field:this:0x0000000B, field:this:0x00000008, field:this:0x0000000A, field:this:0x00000004, source:raw]
    // RETURN: Return the pixel count result (for the remap path, the count value after the loop). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_513374(int *a1, char *dst, int lut15, int remapTable) {
    //     char format = ((char *)a1)[8];
    //     int count = a1[0];
    //     int pixelCount = count;
    //     if (format == 2 && lut15 && ((char *)a1)[9] == 8) {
    //       char *src = dst;
    //       if (count != 0) {
    //         int n = count;
    //         do {
    //           char r = src[0];
    //           char g = src[1];
    //           char b = src[2];
    //           *dst = ((char *)lut15)[(((b >> 3) & 0x1F) | (4 * ((g & 0xF8) | (32 * (r & 0xF8))))) ] ;
    //           src += 4;
    //           dst += 1;
    //         } while (--n != 0);
    //       }
    //       goto finish;
    //     }
    //     if (format == 6 && lut15 && ((char *)a1)[9] == 8) {
    //       char *src = dst;
    //       if (count != 0) {
    //         int n = count;
    //         do {
    //           char r = src[0];
    //           char g = src[1];
    //           char b = src[2];
    //           *dst = ((char *)lut15)[(((b >> 3) & 0x1F) | (4 * ((g & 0xF8) | (32 * (r & 0xF8))))) ] ;
    //           src += 4;
    //           dst += 1;
    //         } while (--n != 0);
    //       }
    //       goto finish;
    //     }
    //     if (format == 3 && remapTable && ((char *)a1)[9] == 8) {
    //       char *p = dst;
    //       int n = count;
    //       while (n != 0) {
    //         *p = ((char *)remapTable)[(unsigned char)*p];
    //         p += 1;
    //         --n;
    //       }
    //     }
    //     return count;
    //   finish:
    //     ((char *)a1)[11] = 8;
    //     ((char *)a1)[8] = 3;
    //     ((char *)a1)[10] = 1;
    //     a1[1] = (pixelCount * 8 + 7) >> 3;
    //     return pixelCount;
    //   }
    // UNRESOLVED: Object type and the meaning of the format state at offsets 0x8, 0x9, 0xA and 0xB are unknown; caller sub_51389E (0x0051389E) supplies the buffers and tables.
    // UNRESOLVED: The 5-byte-per-pixel path advances its source pointer by 4 bytes after reading 3 color bytes; the exact 5-byte layout is not resolved from this function alone.
    // UNRESOLVED: The remap path (format 3) does not update the state fields that the LUT paths write.
}
