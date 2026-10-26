// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B3B0
// Canonical corpus name: sub_59B3B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B3B0_0059b3b0.c

void UnknownObject::SurfaceCopyReallocAssign()
{
    // Copies surface fields from source object a2 into destination object this, reallocating the destination pixel buffer and clip-rect array when their capacities are smaller than the source's. After the capacity checks it copies the pixel data block, the clip-rect array data, and the scalar fields verbatim, then returns this.
    // GUARD: If destination pixel capacity (this+0x4) is smaller than source pixel capacity (a2+0x4), the pixel buffer must be reallocated. [field:this:0x00000004]
    // CALL: FreeWrapper_7bcf frees the old pixel buffer pointer held at this+0x0 before reallocation. [callee:0x00587BCF, field:this:0x00000000]
    // ASSIGNMENT: Allocate the new pixel buffer with OperatorNewNhMallocWrapper sized to the source pixel capacity (a2+0x4) and store it at this+0x0. [callee:0x00587C03, field:this:0x00000000]
    // ASSIGNMENT: Update destination pixel capacity this+0x4 to the source pixel capacity (a2+0x4). [field:this:0x00000004]
    // GUARD: If destination clip-rect capacity (this+0xC) is smaller than source clip-rect capacity (a2+0xC), the clip-rect array must be reallocated. [field:this:0x0000000C]
    // CALL: FreeWrapper_7bcf frees the old clip-rect array pointer held at this+0x8 before reallocation. [callee:0x00587BCF, field:this:0x00000008]
    // CALCULATION: Compute the allocation byte size for the clip-rect array as 4 * source clip-rect capacity (a2+0xC). [callee:0x00587C03, field:this:0x0000000C]
    // CALL: OperatorNewNhMallocWrapper allocates the clip-rect array sized to 4 * source capacity. [callee:0x00587C03, field:this:0x00000008]
    // LOOP: Zero-initialize the freshly allocated clip-rect array in 4-byte units when the allocation succeeded. [source:raw]
    // ASSIGNMENT: Store the new clip-rect array pointer at this+0x8. [field:this:0x00000008]
    // ASSIGNMENT: Update destination clip-rect capacity this+0xC to the source clip-rect capacity (a2+0xC). [field:this:0x0000000C]
    // CALCULATION: Copy the pixel data block: qmemcpy(this+0x0, a2+0x0, source pixel capacity at a2+0x4). [field:this:0x00000000, field:this:0x00000004]
    // CALCULATION: Copy the clip-rect data block: qmemcpy(this+0x8, a2+0x8, 4 * source used clip-rect count at a2+0x14). [field:this:0x00000008, field:this:0x00000014]
    // ASSIGNMENT: Copy scalar field this+0x10 from source a2+0x10. [field:this:0x00000010]
    // ASSIGNMENT: Copy the used clip-rect count: this+0x14 = a2+0x14. [field:this:0x00000014]
    // ASSIGNMENT: Copy surface width field: this+0x18 = a2+0x18. [field:this:0x00000018]
    // ASSIGNMENT: Copy surface height field: this+0x1C = a2+0x1C. [field:this:0x0000001C]
    // RETURN: Return the destination surface pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   int SurfaceCopyReallocAssign(int this, int src) {
    //     if (this->cap_pixels < src->cap_pixels) {
    //       FreeWrapper_7bcf(this->pixels);
    //       this->pixels = OperatorNewNhMallocWrapper(src->cap_pixels);
    //       this->cap_pixels = src->cap_pixels;
    //     }
    //     if (this->cap_clips < src->cap_clips) {
    //       FreeWrapper_7bcf(this->clips);
    //       this->clips = OperatorNewNhMallocWrapper(4 * src->cap_clips);
    //       if (this->clips) zero_words(this->clips, src->cap_clips);
    //       this->cap_clips = src->cap_clips;
    //     }
    //     qmemcpy(this->pixels, src->pixels, src->cap_pixels);
    //     qmemcpy(this->clips, src->clips, 4 * src->used_clips);
    //     this->field10 = src->field10;
    //     this->used_clips = src->used_clips;
    //     this->width = src->width;
    //     this->height = src->height;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the scalar field at this+0x10: copied verbatim with no capacity or copy-size logic, so its role is unknown.
    // UNRESOLVED: Exact pixel format / clip-rect element layout is inferred from copy sizes, not proven by static evidence.
    // UNRESOLVED: Owner object type and the surface use in the caller ShortComputation_6e50 are not established.
}
