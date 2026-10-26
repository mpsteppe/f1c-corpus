// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551390
// Canonical corpus name: PerEntityDataBlockCopyFromParameterTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerEntityDataBlockCopyFromParameterTable_00551390.c

void UnknownObject::CopyFromParameterTable()
{
    // Copies parameter data from a parameter table into per-entity data blocks. Clamps the selected data index against the parameter-table count, iterates the per-entity block array (base this+0x18, count this+0x14, 136-byte stride), and for each block whose first dword is not 255 copies the parameter entry selected by block type and index (a float triplet via sub_53B4C0 plus three dwords) into the block. Sets flag bit 0x10000 at this+0x4 on completion and, when a2 is non-null, clears a bitmask on the owning entity via BitmaskClear.
    // CALCULATION: Clamp the entity data index this+0x8: store a3 when a3 <= the parameter-table count read at (+20 relative to the table pointer at this+0x1C), otherwise store that count minus 1. [field:this:0x00000008, field:this:0x0000001C, field:this:0x00000030, source:raw]
    // LOOP: Iterate i in [0, count this+0x14) over per-entity data blocks starting at this+0x18 with a 136-byte stride. [field:this:0x00000014, field:this:0x00000018, source:raw]
    // GUARD: Skip the block whose first dword's low byte equals 255 (unused/empty block marker). [guard:0, field:this:0x00000018, source:raw]
    // CALCULATION: Compute the parameter entry pointer: read a pointer at (entry table base + 40 + 44 * block type), where the entry table base is the pointer read at (+16 relative to the table pointer at this+0x1C), then add 32 * data index (this+0x8). [field:this:0x0000001C, field:this:0x0000002C, field:this:0x00000008, source:raw]
    // CALL: sub_53B4C0 copies a float triplet from the parameter entry (entry + 16) into the block's data region (block + 4). [callee:0x0053B4C0, source:raw]
    // ASSIGNMENT: Copy the parameter entry dwords at entry + 4, + 8 and + 12 into the block slots tracked as this+0x4C, this+0x50 and this+0x54. [field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, source:raw]
    // STATE_TRANSITION: Set flag bit 0x10000 on the flags field at this+0x4 to mark the data copy as complete. [field:this:0x00000004, source:raw]
    // CALL: When a2 is non-null, BitmaskClear clears the bitmask pointed to by *(a2 + 312) with arguments 64, 32, 0. [callee:0x0054B330, source:raw]
    // CALL: Invoked by EntityFlagSetSubInitChain (00551440) as part of the entity flag-set sub-init chain. [caller:0x00551440]

    // Conservative worker pseudocode:
    //   void sub_551390(_DWORD *this, int a2, int a3) {
    //     int limit = *(int *)(*(int *)(this + 0x1C) + 20);
    //     this[2] = (a3 <= limit) ? a3 : limit - 1;
    //     for (i = 0; i < this[5]; ++i) {
    //       char *block = (char *)this[6] + 136 * i;
    //       if ((unsigned char)*(DWORD *)block != 255) {
    //         int type = *(unsigned char *)block;
    //         char *entry = *(char **)(*(int *)(this + 0x1C) + 16 + 40 + 44 * type) + 32 * this[2];
    //         sub_53B4C0((float *)(entry + 16), (float *)(block + 4));
    //         *(DWORD *)(block + 52) = *(DWORD *)(entry + 4);
    //         *(DWORD *)(block + 56) = *(DWORD *)(entry + 8);
    //         *(DWORD *)(block + 60) = *(DWORD *)(entry + 12);
    //       }
    //     }
    //     this[1] |= 0x10000;
    //     if (a2) BitmaskClear(*(DWORD **)(a2 + 312), 64, 32, 0);
    //   }
    // UNRESOLVED: The parameter table layout (pointer at this+0x1C, entry-table pointer at +16, count at +20, 44-byte per-type entries at base +40, 32 dwords per data index) is inferred from index arithmetic only; no named struct is evidenced.
    // UNRESOLVED: sub_53B4C0's exact copy width and the field meanings of the block slots (+4..+12 and +52..+60) are not established from this packet.
}
