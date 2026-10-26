// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005950A3
// Canonical corpus name: sub_5950A3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5950A3_005950a3.c

void UnknownObject::bitMaskRemapA()
{
    // Bit-mask remap helper used by BitFieldMaskMerge: reorders individual bit positions from one mask layout to another. Maps input bit 0 to output value 16, input bit 2 to output 8, input bit 3 to output 4, input bit 4 to output 2, and input bit 5 to output 1; input bit 1 is ignored. Companion to sub_595135 whose mapping is the inverse for the shared bits.
    // ASSIGNMENT: Initialize result to 0. [source:raw]
    // GUARD: If input bit 0 (a1 & 1) is set, assign result = 16 (moves bit 0 to output bit position 4). [source:raw]
    // GUARD: If input bit 2 (a1 & 4) is set, set result bit 3 (result |= 8). [source:raw]
    // GUARD: If input bit 3 (a1 & 8) is set, set result bit 2 (result |= 4). [source:raw]
    // GUARD: If input bit 4 (a1 & 0x10) is set, set result bit 1 (result |= 2). [source:raw]
    // GUARD: If input bit 5 (a1 & 0x20) is set, return result with bit 0 set (result | 1). [source:raw]
    // RETURN: Return the accumulated remapped result. [source:raw]

    // Conservative worker pseudocode:
    //   char bitMaskRemapA(char a1) {
    //     char result = 0;
    //     if (a1 & 1)  result = 16;
    //     if (a1 & 4)  result |= 8;
    //     if (a1 & 8)  result |= 4;
    //     if (a1 & 0x10) result |= 2;
    //     if (a1 & 0x20) return result | 1;
    //     return result;
    //   }
    // UNRESOLVED: Input bit 1 is never tested; it contributes nothing to the output.
    // UNRESOLVED: Semantic meaning of the two mask layouts (which field each bit represents) is not recoverable from this function alone.
}
