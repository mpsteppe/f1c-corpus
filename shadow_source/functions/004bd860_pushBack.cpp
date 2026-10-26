// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BD860
// Canonical corpus name: DynamicArrayPush
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynamicArrayPush_004bd860.c

void UnknownObject::pushBack()
{
    // Appends integer a2 to a dynamic array (capacity at this+0x0, element count at this+0x4, data buffer pointer at this+0x8). When count equals capacity, grows capacity by 8: allocates a new 4-byte-per-element buffer via OperatorNewNhMallocWrapper, copies existing elements, frees the old buffer, and stores the new pointer. Appends the value at data[count], increments the count, and returns the previous count.
    // GUARD: If element count (this+0x4) equals capacity (this+0x0), grow the array. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: New capacity = old capacity + 8. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store new capacity into this+0x0. [field:this:0x00000000, source:raw]
    // CALL: Allocate a new buffer of 4 bytes per element for the new capacity via OperatorNewNhMallocWrapper. [callee:0x00587C03, field:this:0x00000000, source:raw]
    // LOOP: Copy each of the existing count elements from the old buffer into the new buffer. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: If the old buffer pointer (this+0x8) is non-zero, free it. [field:this:0x00000008, source:raw]
    // CALL: Free the old array buffer via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Point this+0x8 at the newly allocated buffer. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write a2 into data[count] (element at offset 4 * count in the buffer). [field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Increment the element count at this+0x4. [field:this:0x00000004, source:raw]
    // RETURN: Return the previous element count. [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   if (this->count == this->capacity) {
    //     this->capacity += 8;
    //     newBuf = OperatorNewNhMallocWrapper(4 * this->capacity);
    //     for (i = 0; i < this->count; ++i)
    //       newBuf[i] = this->data[i];
    //     if (this->data) FreeWrapper_7bcf(this->data);
    //     this->data = newBuf;
    //   }
    //   result = this->count;
    //   this->data[result] = a2;
    //   ++this->count;
    //   return result;
    // UNRESOLVED: Initial capacity growth policy (always +8) and the caller context of sub_4BDE20 are not evidenced beyond the push behavior itself.
}
