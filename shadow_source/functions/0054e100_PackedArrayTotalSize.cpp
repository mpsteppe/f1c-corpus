// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E100
// Canonical corpus name: PackedArrayTotalSize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PackedArrayTotalSize_0054e100.c

void UnknownObject::PackedArrayTotalSize()
{
    // Sums a size field located 8 bytes into each element of a packed array and returns the total. The element count is read from this[0x118] and the array base pointer from this[0x11C]; the loop advances through the array in 16-DWORD (64-byte) steps. Returns 0 when the element count is not positive. Consistent with the existing analysis (PackedArrayTotalSize_0054e100.md): count at 0x118, base pointer at 0x11C, element stride 64 bytes.
    // ASSIGNMENT: Read the element count from this[70] (offset 0x118) into the loop counter and initialize the accumulated result to 0. [field:this:0x00000118, source:raw]
    // GUARD: If the element count is not greater than 0, skip the accumulation loop and return 0. [field:this:0x00000118, source:raw]
    // CALCULATION: Set the element cursor to this[71] (offset 0x11C, the array base pointer) advanced by 8 bytes, i.e. the first element's size field. [field:this:0x0000011C, source:raw]
    // LOOP: Accumulate the DWORD at the cursor into the result, advance the cursor by 16 DWORDs (64 bytes per element, the element stride), and decrement the element count until it reaches zero. [field:this:0x00000124, source:raw]
    // RETURN: Return the accumulated total size. [source:raw]

    // Conservative worker pseudocode:
    //   count = this[0x118];
    //   result = 0;
    //   if (count > 0) {
    //     cursor = this[0x11C] + 8;
    //     do { result += *cursor; cursor += 16; } while (--count);
    //   }
    //   return result;
    // UNRESOLVED: The element layout is inferred only from pointer arithmetic: a size field at +8 with a 64-byte stride. The semantic meaning of the summed field is not determinable from this packet alone.
}
