// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0080
// Canonical corpus name: sub_4D0080
// Owner: SoundSourceArray [DERIVED]
// Raw source: functions/sub_4D0080_004d0080.c

void SoundSourceArray::soundSourceArrayDestructor()
{
    // Destructor for an array of 3D sound source objects. When the array pointer (this+0x4) and the global dword_8AFE88 are both non-null, iterates the 132-byte-stride array destroying each non-null entry via F_3DSoundSourceDestructor, then walks the same entries backwards calling sub_4A2220 to clean internal state and frees the allocation block via FreeWrapper_7bcf. Finally zeroes both the pointer and the count fields (this+0x4, this+0x0).
    // GUARD: Proceeds only when the array pointer (this+0x4) is non-null and the global dword_8AFE88 is non-null; otherwise skips the whole teardown and jumps to zeroing the fields. [field:this:0x00000004, global:0x008AFE88, source:raw]
    // GUARD: Iterates the array only while the count field (this+0x0) is greater than zero. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Walks the 132-byte-stride array from index 0 up to count; for each entry whose leading dword is non-null it destroys that sound source object. [field:this:0x00000004, source:raw]
    // CALL: Calls F_3DSoundSourceDestructor on each non-null entry dword of the 132-byte-stride array to destroy the individual 3D sound source object. [callee:0x00545150, source:raw]
    // LOOP: Walks the same 132-byte-stride entries backwards (from the header-derived count down to zero), calling sub_4A2220 on each entry to clean up its internal fields. [field:this:0x00000004, callee:0x004A2220, source:raw]
    // CALL: Calls sub_4A2220 on each array entry as part of the second, backwards cleanup pass. [callee:0x004A2220, source:raw]
    // CALL: Frees the allocation block that backs the array via FreeWrapper_7bcf; the block is addressed as the array pointer minus 4 (the element-count header). [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clears the array pointer field (this+0x4) to 0 and then the count field (this+0x0) to 0, leaving the container empty. [field:this:0x00000004, field:this:0x00000000, source:raw]
    // RETURN: Returns the final result value (the zeroed count) to the caller. [function:0x004D0080, source:raw]

    // Conservative worker pseudocode:
    //   result = this->array;
    //   if (this->array != NULL && dword_8AFE88 != NULL) {
    //       for (i = 0; i < this->count; ++i)
    //           if (entryAt(this->array, i) != NULL)
    //               F_3DSoundSourceDestructor(entryAt(this->array, i));
    //       if (this->array != NULL) {
    //           headerCount = *(this->array - 4);
    //           for (j = headerCount; j > 0; --j)
    //               sub_4A2220(&entryAt(this->array, j - 1));
    //           FreeWrapper_7bcf(this->array - 4);
    //       }
    //       this->array = 0;
    //   }
    //   this->count = 0;
    //   return result;
    // UNRESOLVED: Class identity of the owning sound-source container is not evidenced in the packet; owner SoundSourceArray is DERIVED.
    // UNRESOLVED: The 132-byte per-entry layout and the entry's leading dword object are only described by the raw stride; no per-field structure is given.
    // UNRESOLVED: Role of global dword_8AFE88 is not evidenced here; the prior analysis names it a collision-geometry handle but that tier is not carried into this IR.
    // UNRESOLVED: The element-count header at array-4 is implied by the raw source read at array-4; its layout is not independently evidenced.
}
