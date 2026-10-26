// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586AA0
// Canonical corpus name: sub_586AA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586AA0_00586aa0.c

void UnknownObject::MultiBlockBitfieldReset()
{
    // Resets/initializes a multi-block bitmap state. Clears the first DWORD at this+0x0, then processes four bitmap blocks whose metadata lives at this+0x1C (entry per block: start-position word at +0, bit-count word at +2) indexed by this+0x34/0x38/0x3C/0x40. Block 1 (this+0x34) OR/ANDs a single low bit into the bitmap bytes at this+0x14 via IndexToBitmaskConversion. Blocks 2 and 3 (this+0x38, this+0x3C) clear every bit through BitSetClearOperation. Block 4 (this+0x40) builds a selection mask via ComputeBitmaskFromBitmapEntryCount and clears/sets bits per that mask. Ends with BitfieldEncoder(this+0x44, 0), SimpleSetter_7500 on this+0x8, and zeroes this+0x48/0x4C/0x50, returning 0.
    // ASSIGNMENT: Clear the first DWORD of this (this+0x0) to literal 0 [field:this:0x00000000, source:raw]
    // CALCULATION: Read block 1 metadata at this+0x1C + 4*this[13]: start-position word at +0, bit count v5 at +2; build the full bitmask (1<<bit) up to the count [field:this:0x0000001C, field:this:0x00000034, source:raw]
    // LOOP: Block 1: for each bit, IndexToBitmaskConversion(start + count - 1 - idx) yields a byte offset v33 and mask v32; write byte at bitmap base (this+0x14) + v33, setting the bit (v32 | byte) when the low-bit selection j is set, otherwise clearing it (~v32 & byte) [callee:0x00585E80, field:this:0x00000014, field:this:0x00000034, source:raw]
    // LOOP: Block 2 (index this+0x38): read its metadata bit count and loop BitSetClearOperation(start + count - 1 - idx, 0) to clear every bit [callee:0x00586F70, field:this:0x00000038, source:raw]
    // LOOP: Block 3 (index this+0x3C): read its metadata bit count and loop BitSetClearOperation(start + count - 1 - idx, 0) to clear every bit [callee:0x00586F70, field:this:0x0000003C, source:raw]
    // CALL: ComputeBitmaskFromBitmapEntryCount(this[16], &v33) builds the selection mask for block 4 [callee:0x00586F40, field:this:0x00000040, source:raw]
    // LOOP: Block 4 (index this+0x40): read start (word at +0) and count (word at +2), loop BitSetClearOperation(start + count - 1 - idx, bit-of-mask) to clear or set each bit according to the v33 mask [callee:0x00586F70, field:this:0x00000040, source:raw]
    // CALL: BitfieldEncoder(this[17], 0) encodes the final block using the this+0x44 index with the literal 0 [callee:0x00586FA0, field:this:0x00000044, source:raw]
    // CALL: SimpleSetter_7500(this + 2) writes the second DWORD slot of this (this+0x8) [callee:0x00587500, source:raw]
    // ASSIGNMENT: Zero the trailing DWORDs this[18], this[19], this[20] at this+0x48, this+0x4C, this+0x50 [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // RETURN: Return literal 0; the function is invoked by SEHProtectedDirectXRenderStateSetup (00586700) [caller:0x00586700, function:0x00586AA0, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   for (block = 0; block < 4; ++block) {
    //     count = WORD(meta[this[13+block]] + 2);
    //     start = WORD(meta[this[13+block]] + 0);
    //     if (block == 0) {
    //       j = bitmask(count) & 1;
    //       for (i = 0; i < count; ++i) {
    //         IndexToBitmaskConversion(start + count - 1 - i, &v33, &v32);
    //         byte = bitmap_base + v33;
    //         *byte = j ? (v32 | *byte) : (~v32 & *byte);
    //       }
    //     } else if (block < 3) {
    //       for (i = 0; i < count; ++i) BitSetClearOperation(start + count - 1 - i, 0);
    //     } else {
    //       ComputeBitmaskFromBitmapEntryCount(this[16], &v33);
    //       for (i = 0; i < count; ++i)
    //         BitSetClearOperation(start + count - 1 - i, (bitmask(i) & v33) != 0);
    //     }
    //   }
    //   BitfieldEncoder(this[17], 0);
    //   SimpleSetter_7500(this + 2);
    //   this[18] = 0; this[19] = 0; this[20] = 0;
    //   return 0;
    // UNRESOLVED: The semantics of the per-block metadata (start-position word and bit-count word per entry) are inferred from the raw source access pattern; the structure of the this+0x1C table is not independently documented in this packet
    // UNRESOLVED: Why block 1 only participates through the low bit (j = bitmask & 1) while blocks 2-4 run over the full count is unexplained by the packet
    // UNRESOLVED: SimpleSetter_7500 is applied to this+0x8 (this+2 DWORD), which is not among the packet's listed fields; it is noted from the raw source only
}
