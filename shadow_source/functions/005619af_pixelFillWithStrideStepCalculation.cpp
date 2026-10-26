// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005619AF
// Canonical corpus name: PixelFillWithStrideStepCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelFillWithStrideStepCalculation_005619af.c

void UnknownObject::pixelFillWithStrideStepCalculation()
{
    // 16-bit pixel fill with a per-pixel stride step plus a Bresenham-style conditional scanline advance: stores a fixed 16-bit value, advances the pointer by a small byte step a8 on every pixel, and adds a larger row byte stride whenever the error accumulator crosses zero. No calls, no globals.
    // CALCULATION: Compute the starting pixel pointer: buffer base address a9 plus twice the pixel offset a6, where twice the offset accounts for two bytes per 16-bit pixel. [function:0x005619AF, source:raw]
    // CALCULATION: Compute the conditional row byte stride as twice a5, converting the pixel-unit row stride a5 into a byte stride for 16-bit pixels. [function:0x005619AF, source:raw]
    // CALCULATION: Compute the per-pixel byte stride as twice a8, converting the pixel-unit step a8 into a byte step for 16-bit pixels. [function:0x005619AF, source:raw]
    // ASSIGNMENT: Record the fill value a7 as the value that will be stored into each pixel and returned. [function:0x005619AF, source:raw]
    // LOOP: Iterate exactly a2 times, decrementing a2 each pass and stopping when it reaches zero. [function:0x005619AF, source:raw]
    // ASSIGNMENT: Store the 16-bit fill value a7 at the current pixel pointer, then advance the pointer forward by the per-pixel byte stride. [function:0x005619AF, source:raw]
    // GUARD: If the error accumulator a1 is negative, add a3 to it (stay on the current scanline). Otherwise add a4 and additionally advance the pointer by the conditional row byte stride. [function:0x005619AF, source:raw]
    // RETURN: Return the fill value a7. [function:0x005619AF, source:raw]

    // Conservative worker pseudocode:
    //   pointer = base_address(a9) + 2 * pixel_offset(a6);
    //   row_byte_stride = 2 * row_pixel_stride(a5);
    //   pixel_byte_stride = 2 * pixel_stride(a8);
    //   fill = fill_value(a7);
    //   for (count = a2; count != 0; --count) {
    //       *pointer = fill;
    //       pointer += pixel_byte_stride;
    //       if (error(a1) < 0) { error += a3; }
    //       else { error += a4; pointer += row_byte_stride; }
    //   }
    //   return fill;
    // UNRESOLVED: The per-pixel stride a8 suggests a sloped or diagonal line fill, but the exact geometric primitive is unconfirmed without caller evidence.
    // UNRESOLVED: Parameter roles for a3 vs. a4 are inferred from the two error-accumulator branches; no caller or header evidence confirms which is the major-axis increment.
}
