// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418C10
// Canonical corpus name: MemoryAllocation_8c10
// Owner: TextDisplayStructure [DERIVED]
// Raw source: functions/MemoryAllocation_8c10_00418c10.c

void TextDisplayStructure::TextStructDeepCleanup()
{
    // Deep cleanup of a text display structure: when the byte flag at this+0x8 is set and the data block at this+0x0 is non-null, reinitializes the block via TextFormatStructInitializer_4d70, frees nine allocated pointers inside it (eight from four 2-iteration loops at 5-dword stride plus the first block pointer), frees the data block itself, then optionally frees the container `this` when a2 bit 0 is set. Returns this. Called by NameListBuilderFromVehicleArray (0x004159B0).
    // GUARD: If byte flag at this+0x8 (cleanup enable) is non-zero, proceed with cleanup [field:this:0x00000008, source:raw]
    // GUARD: If data block pointer at this+0x0 is non-null, proceed with block cleanup [field:this:0x00000000, source:raw]
    // CALL: Reinitialize the data block via TextFormatStructInitializer_4d70 [callee:0x00414D70, source:raw]
    // LOOP: Two-iteration loop starting at block entry v3+43: for each of two pointers read at 5-dword stride, if non-null call FreeWrapper_7bcf [field:this:0x00000000, source:raw]
    // LOOP: Two-iteration loop starting at block entry v3+33: for each of two pointers read at 5-dword stride, if non-null call FreeWrapper_7bcf [field:this:0x00000000, source:raw]
    // LOOP: Two-iteration loop starting at block entry v3+23: for each of two pointers read at 5-dword stride, if non-null call FreeWrapper_7bcf [field:this:0x00000000, source:raw]
    // LOOP: Two-iteration loop starting at block entry v3+13: for each of two pointers read at 5-dword stride, if non-null call FreeWrapper_7bcf [field:this:0x00000000, source:raw]
    // GUARD: If first pointer v3[0] (offset 0x0 of the data block) is non-null, free it [field:obj:0x00000000, source:raw]
    // CALL: Free the first data block pointer via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // CALL: Free the data block itself via FreeWrapper_7bcf [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: If a2 bit 0 is set, free the container this as well [source:raw]
    // CALL: Free container this via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // RETURN: Return this [source:raw]

    // Conservative worker pseudocode:
    //   if (this->cleanupFlag) {
    //     if (this->dataBlock) {
    //       TextFormatStructInitializer_4d70(this->dataBlock);
    //       freeTwoPointersAtStride(this->dataBlock + 43);
    //       freeTwoPointersAtStride(this->dataBlock + 33);
    //       freeTwoPointersAtStride(this->dataBlock + 23);
    //       freeTwoPointersAtStride(this->dataBlock + 13);
    //       if (this->dataBlock[0]) FreeWrapper_7bcf(this->dataBlock[0]);
    //       FreeWrapper_7bcf(this->dataBlock);
    //     }
    //   }
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Exact class of the text display structure not established; offsets of the nine freed slots inside the data block are derived from source arithmetic only.
    // UNRESOLVED: Purpose of the reinitialization via TextFormatStructInitializer_4d70 during teardown not established.
}
