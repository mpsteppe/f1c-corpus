// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586D00
// Canonical corpus name: BitmapRangeOccupancyTestViaBitOps
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapRangeOccupancyTestViaBitOps_00586d00.c

void UnknownObject::BitmapRangeOccupancyTestViaBitOps()
{
    // Tests which positions of a range are occupied in a packed bitmap. Reads a range descriptor (start WORD + count WORD) from an array at this+0x1C indexed by this+0x34, then for each of count positions builds a bitmask of occupied slots by testing bits in the bitmap at this+0x14. Returns the occupancy bitmask, or 0 when the range count is zero. Invoked by VTableDispatchWithConditionalBranch (00585400).
    // ASSIGNMENT: Read the range descriptor table base v2 = this[7] (this+0x1C) and the index v1 = this[13] (this+0x34) into the descriptor table. [field:this:0x0000001C, field:this:0x00000034, source:raw]
    // CALCULATION: Load the range descriptor at byte offset 4*v1 into v2: start position v3 = WORD at (v2 + 4*v1) and count v5 = WORD at (v2 + 4*v1 + 2). [field:this:0x0000001C, source:raw]
    // CALCULATION: Compute the end position v6 = v3 + v5 - 1 and initialize result accumulator v8 = 0. [source:raw]
    // GUARD: Guard on count v5: when the count WORD is zero, return 0 immediately without testing any bits. [source:raw]
    // LOOP: do-while loop over v7 = 0..v5-1 testing every position in the range exactly v5 times. [source:raw]
    // CALCULATION: For position v7, compute the bitmap bit: bit index ((v6 - v7) & 7) within byte at ((v6 - v7) >> 3) + this[5] (bitmap base this+0x14). [field:this:0x00000014, source:raw]
    // GUARD: Test the bit with mask (1 << ((v6 - v7) & 7)) against the bitmap byte; when set, accumulate v8 |= 1 << v7. [field:this:0x00000014, source:raw]
    // RETURN: Return the occupancy bitmask v8 after the loop, or the default result 0 when the count is zero. [source:raw]
    // CALL: Invoked by VTableDispatchWithConditionalBranch (00585400) to query range occupancy in the bitmap. [caller:0x00585400, source:raw]

    // Conservative worker pseudocode:
    //   int sub_586D00(_DWORD *this) {
    //     unsigned v1 = this[13];
    //     unsigned v2 = this[7];
    //     unsigned short v3 = *(unsigned short*)(v2 + 4*v1);
    //     unsigned v5 = *(unsigned short*)(v2 + 4*v1 + 2);
    //     if (v5 == 0) return 0;
    //     unsigned v6 = v3 + v5 - 1;
    //     int v8 = 0;
    //     for (unsigned v7 = 0; v7 < v5; ++v7)
    //       if ((1 << ((v6 - v7) & 7)) & *(BYTE*)(((v6 - v7) >> 3) + this[5]))
    //         v8 |= 1 << v7;
    //     return v8;
    //   }
    // UNRESOLVED: Semantics of the range descriptor (start + count) and the bitmap are caller-defined; the meaning of an occupied bit is not established here.
    // UNRESOLVED: Identity of the owning object and the type of the descriptor table at this+0x1C are unknown.
    // UNRESOLVED: The abi trust LEGACY name FAIL_586d00 carries no semantic content and is treated as void.
}
