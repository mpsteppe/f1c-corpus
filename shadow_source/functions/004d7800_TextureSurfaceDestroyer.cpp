// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7800
// Canonical corpus name: TextureSurfaceDestroyer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureSurfaceDestroyer_004d7800.c

void UnknownObject::TextureSurfaceDestroyer()
{
    // Destroys a texture-surface container, consistent with the ABI lead Texture_Surface_Destroyer. If the entry count at this+0 is positive, iterates the active entries in the block at this+4 with a 36-byte (0x24) stride calling ArrayBlockCleanup on each. Then unconditionally clears the count at this+0. If the block pointer at this+4 is non-null, reads the allocation capacity from the header at block-4, walks all 36-byte (0x24) slots in reverse calling ArrayBlockCleanup per slot and freeing the sub-pointers at slot+0x18 and slot+0x0 via FreeWrapper_7bcf, frees the block header itself, and finally zeroes this+4. Returns the result of the last free operation. Called by SessionReset and TireBrandLoader during teardown.
    // GUARD: Guard (this+0 > 0): if the entry count at this+0 is positive, the active-entries loop runs. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Iterates v4 = 0..count-1 calling ArrayBlockCleanup on each active entry at this[1] + v4 with a 36-byte (0x24) stride. [callee:0x004D7050, field:this:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Reads the block pointer this[1] (this+4), then clears the entry count at this+0 to 0 unconditionally. [field:this:0x00000004, field:this:0x00000000, source:raw]
    // GUARD: If the saved block pointer is non-null: reads the allocation capacity at block-4, computes the full block span (capacity * 36 bytes), and walks the 36-byte (0x24) slots in reverse, calling ArrayBlockCleanup per slot and freeing the sub-pointer at slot+0x18 (if set) and at slot+0x0 (if set) via FreeWrapper_7bcf. [callee:0x004D7050, callee:0x00587BCF, field:this:0x00000004, abi:lead, source:raw]
    // CALL: Frees the block header at block-4 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zeroes the block pointer field at this+4 (this[1] = 0). [field:this:0x00000004, source:raw]
    // RETURN: Returns the result of the last free operation (or the last-read count if the block pointer was null). [function:0x004D7800, source:raw]

    // Conservative worker pseudocode:
    //   if (this->count > 0) {
    //     for (i = 0; i < this->count; i++) ArrayBlockCleanup((char*)this->block + 36*i);
    //   }
    //   block = this->block;
    //   this->count = 0;
    //   if (block) {
    //     capacity = *(int*)(block - 4);
    //     for (slot = block + 36*capacity; capacity > 0; capacity--) {
    //       slot -= 36;
    //       ArrayBlockCleanup(slot);
    //       if (*(void**)(slot + 0x18)) FreeWrapper_7bcf(*(void**)(slot + 0x18));
    //       if (*(void**)slot) FreeWrapper_7bcf(*(void**)slot);
    //     }
    //     result = FreeWrapper_7bcf(block - 4);
    //   }
    //   this->block = 0;
    //   return result;
    // UNRESOLVED: The meaning of the block header at block-4 (allocation capacity) and the identity of the per-slot sub-pointers at slot+0x0 and slot+0x18 are DERIVED from pointer arithmetic; the texture-surface element layout is not evidenced in this packet.
    // UNRESOLVED: ArrayBlockCleanup's per-slot teardown behavior is not evidenced here.
    // UNRESOLVED: The container class is unidentified; the owner remains UnknownObject.
}
