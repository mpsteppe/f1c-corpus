// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561970
// Canonical corpus name: F_16BitPixelRectangleFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitPixelRectangleFill_00561970.c

void UnknownObject::fill16BitPixelRectangle()
{
    // 16-bit pixel fill using a Bresenham-style error accumulator: stores a fixed 16-bit value into a row of pixels, advancing to the next scanline (by a byte row stride) whenever the error term crosses zero. No calls, no globals; pure buffer-fill routine.
    // CALCULATION: Compute the starting pixel pointer: buffer base address a8 plus twice the pixel offset a6, where twice the offset accounts for two bytes per 16-bit pixel. [function:0x00561970, source:raw]
    // CALCULATION: Compute the row skip in bytes as twice a5, converting the pixel-unit row stride a5 into a byte stride for 16-bit pixels. [function:0x00561970, source:raw]
    // ASSIGNMENT: Record the fill value a7 as the value that will be stored into each pixel and returned. [function:0x00561970, source:raw]
    // LOOP: Iterate exactly a2 times, decrementing a2 each pass and stopping when it reaches zero. [function:0x00561970, source:raw]
    // ASSIGNMENT: Store the 16-bit fill value a7 at the current pixel pointer and advance the pointer by one pixel (two bytes). [function:0x00561970, source:raw]
    // GUARD: If the error accumulator a1 is negative, add a3 to it (stay on the current scanline). Otherwise add a4 and skip the pointer forward by the row byte stride, moving to the next scanline. [function:0x00561970, source:raw]
    // RETURN: Return the fill value a7. [function:0x00561970, source:raw]

    // Conservative worker pseudocode:
    //   pointer = base_address(a8) + 2 * pixel_offset(a6);
    //   row_byte_stride = 2 * row_pixel_stride(a5);
    //   fill = fill_value(a7);
    //   for (count = a2; count != 0; --count) {
    //       *pointer++ = fill;
    //       if (error(a1) < 0) { error += a3; }
    //       else { error += a4; pointer += row_byte_stride; }
    //   }
    //   return fill;
    // UNRESOLVED: The exact primitive rendered (axis-aligned rectangle scanline vs. Bresenham line segment) is not provable without caller evidence; only the canonical corpus name suggests rectangle fill.
    // UNRESOLVED: Parameter roles for a3 vs. a4 are inferred from the two error-accumulator branches; no caller or header evidence confirms which is the major-axis increment.
}
