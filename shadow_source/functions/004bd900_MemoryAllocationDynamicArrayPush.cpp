// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BD900
// Canonical corpus name: MemoryAllocation_d900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_d900_004bd900.c

void UnknownObject::MemoryAllocationDynamicArrayPush()
{
    // Appends one dword value to a dynamic integer array owned by this (capacity at this+0xC, count at this+0x10, data buffer pointer at this+0x14). When count equals capacity, grows capacity by 8, allocates a new buffer of 4*new_capacity bytes via OperatorNewNhMallocWrapper, copies the existing count elements, frees the old buffer via FreeWrapper_7bcf, and repoints this+0x14. Returns the pre-increment count as the index of the appended element, then increments count.
    // GUARD: Only grow the array when the element count at this+0x10 has reached the capacity at this+0xC [field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Raise capacity at this+0xC by 8 [field:this:0x0000000C, source:raw]
    // CALL: OperatorNewNhMallocWrapper allocates a new buffer of 4 * new_capacity bytes [callee:0x00587C03, field:this:0x0000000C, source:raw]
    // LOOP: Copy the existing count of 4-byte elements from the old buffer at this+0x14 into the newly allocated buffer [field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: Release the old buffer via FreeWrapper_7bcf only when this+0x14 is non-null [callee:0x00587BCF, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Point this+0x14 at the newly allocated buffer [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Store a2 at index count of the data buffer (this+0x14 + 4*count) [field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Increment the element count at this+0x10 by 1 [field:this:0x00000010, source:raw]
    // RETURN: Return the pre-increment count as the index of the appended element; called from sub_4BE010 [function:0x004BD900, caller:0x004BE010, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   if (this->count == this->capacity) {
    //     this->capacity += 8;
    //     new_buf = OperatorNewNhMallocWrapper(4 * this->capacity);
    //     for (i = 0; i < this->count; ++i) new_buf[i] = this->data[i];
    //     if (this->data) FreeWrapper_7bcf(this->data);
    //     this->data = new_buf;
    //   }
    //   index = this->count;
    //   this->data[index] = a2;
    //   this->count += 1;
    //   return index;
    // UNRESOLVED: The identity of the owning object is unknown; the capacity/count/data-buffer triple at this+0xC/0x10/0x14 mirrors the pattern of a twin dynamic-array-push function with different field offsets
    // UNRESOLVED: The growth step (8) and element stride (4) are read directly from the raw source; their semantic meaning as count-of-elements versus bytes is not independently confirmed
}
