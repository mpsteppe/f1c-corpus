// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595135
// Canonical corpus name: sub_595135
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595135_00595135.c

void UnknownObject::bitMaskRemapB()
{
    // Bit-mask remap helper used by BitFieldMaskMerge: reorders individual bit positions from one mask layout to another. Maps input bit 4 to output value 1, input bit 3 to output 4, input bit 2 to output 8, input bit 1 to output 16, input bit 0 to output 32, and input bit 19 (0x80000) to output 2. Near-inverse of sub_5950A3 over the shared low bits.
    // ASSIGNMENT: Initialize result to (a1 & 0x10) != 0, i.e. set output bit 0 (value 1) when input bit 4 is set. [source:raw]
    // GUARD: If input bit 3 (a1 & 8) is set, set result bit 2 (result |= 4). [source:raw]
    // GUARD: If input bit 2 (a1 & 4) is set, set result bit 3 (result |= 8). [source:raw]
    // GUARD: If input bit 1 (a1 & 2) is set, set result bit 4 (result |= 0x10). [source:raw]
    // GUARD: If input bit 0 (a1 & 1) is set, set result bit 5 (result |= 0x20). [source:raw]
    // GUARD: If input bit 19 (a1 & 0x80000) is set, return result with bit 1 set (result | 2). [source:raw]
    // RETURN: Return the accumulated remapped result. [source:raw]

    // Conservative worker pseudocode:
    //   char bitMaskRemapB(int a1) {
    //     char result = (a1 & 0x10) != 0;
    //     if (a1 & 8)       result |= 4;
    //     if (a1 & 4)       result |= 8;
    //     if (a1 & 2)       result |= 0x10;
    //     if (a1 & 1)       result |= 0x20;
    //     if (a1 & 0x80000) return result | 2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the two mask layouts (which field each bit represents) is not recoverable from this function alone.
    // UNRESOLVED: Legacy ABI entry FAIL_595135 carries no usable prototype.
}
