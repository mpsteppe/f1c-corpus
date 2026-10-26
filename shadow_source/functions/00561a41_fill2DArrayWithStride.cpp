// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561A41
// Canonical corpus name: F_2DArrayFillWithStrideSupport
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DArrayFillWithStrideSupport_00561a41.c

void UnknownObject::fill2DArrayWithStride()
{
    // 32-bit value fill over a 2D region using a Bresenham-style error accumulator: stores a fixed 32-bit value into consecutive dwords, advancing to the next row (by a dword row stride) whenever the error term crosses zero. No calls, no globals; the 32-bit counterpart of the 16-bit fill routines.
    // CALCULATION: Compute the starting element pointer: buffer base address a8 plus four times the element offset a6, where the factor of four accounts for four bytes per 32-bit element. [function:0x00561A41, source:raw]
    // CALCULATION: Compute the row skip in bytes as four times a5, converting the element-unit row stride a5 into a byte stride for 32-bit elements. [function:0x00561A41, source:raw]
    // ASSIGNMENT: Record the fill value a7 as the value that will be stored into each element and returned. [function:0x00561A41, source:raw]
    // LOOP: Iterate exactly a2 times, decrementing a2 each pass and stopping when it reaches zero. [function:0x00561A41, source:raw]
    // ASSIGNMENT: Store the 32-bit fill value a7 at the current element pointer and advance the pointer by one element (four bytes). [function:0x00561A41, source:raw]
    // GUARD: If the error accumulator a1 is negative, add a3 to it (stay on the current row). Otherwise add a4 and skip the pointer forward by the row byte stride, moving to the next row. [function:0x00561A41, source:raw]
    // RETURN: Return the fill value a7. [function:0x00561A41, source:raw]

    // Conservative worker pseudocode:
    //   pointer = base_address(a8) + 4 * element_offset(a6);
    //   row_byte_stride = 4 * row_element_stride(a5);
    //   fill = fill_value(a7);
    //   for (count = a2; count != 0; --count) {
    //       *pointer++ = fill;
    //       if (error(a1) < 0) { error += a3; }
    //       else { error += a4; pointer += row_byte_stride; }
    //   }
    //   return fill;
    // UNRESOLVED: Whether the buffer holds 32-bit pixel colors or generic array data is unconfirmed; the canonical name implies a 2D array fill.
    // UNRESOLVED: Parameter roles for a3 vs. a4 are inferred from the two error-accumulator branches; no caller or header evidence confirms which is the major-axis increment.
}
