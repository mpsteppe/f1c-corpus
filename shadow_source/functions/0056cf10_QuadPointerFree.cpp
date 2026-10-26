// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056CF10
// Canonical corpus name: QuadPointerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadPointerFree_0056cf10.c

void UnknownObject::QuadPointerFree()
{
    // Releases the four pointer slots of this (this+0x0, +0x4, +0x8, +0xC). Each of the first three slots, when non-null, is freed via FreeWrapper_7bcf and then cleared to 0. The fourth slot's pointer is saved, freed when non-null, cleared to 0, and its saved value (or the FreeWrapper result) is returned.
    // GUARD: For each of the first three slots (this+0x0, +0x4, +0x8), free only when the slot is non-null [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: FreeWrapper_7bcf releases the buffer previously held in this+0x0 [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear this+0x0 to 0 after releasing it [field:this:0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf releases the buffer previously held in this+0x4 [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clear this+0x4 to 0 after releasing it [field:this:0x00000004, source:raw]
    // CALL: FreeWrapper_7bcf releases the buffer previously held in this+0x8 [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear this+0x8 to 0 after releasing it [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Save the pointer at this+0xC as the result before testing it [field:this:0x0000000C, source:raw]
    // GUARD: Release this+0xC via FreeWrapper_7bcf only when the saved pointer is non-null [callee:0x00587BCF, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear this+0xC to 0 after releasing it [field:this:0x0000000C, source:raw]
    // RETURN: Return the saved this+0xC pointer (the FreeWrapper result when it was non-null); called from sub_56C830 [function:0x0056CF10, caller:0x0056C830, field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   for (slot = 0; slot < 3; ++slot)
    //     if (this[slot]) { FreeWrapper_7bcf(this[slot]); this[slot] = 0; }
    //   result = this[3];
    //   if (result) { result = FreeWrapper_7bcf(this[3]); this[3] = 0; }
    //   return result;
    // UNRESOLVED: The owning object and the meaning of each of the four pointer slots cannot be established from this packet; the packet's prelabel notes a structural similarity to ScoreSlotDeallocator (0042ddd0) but that is a DERIVED cluster match, not independent evidence
    // UNRESOLVED: The return value (saved this+0xC) is unused or consumed by sub_56C830; its purpose is not confirmed here
}
