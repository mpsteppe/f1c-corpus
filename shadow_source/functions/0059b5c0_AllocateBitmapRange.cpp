// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B5C0
// Canonical corpus name: BitmapAllocationTracker
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapAllocationTracker_0059b5c0.c

void UnknownObject::AllocateBitmapRange()
{
    // Allocates a range of a2 consecutive units in a bitmap tracker: grows the bitmap buffer and element array, records an element (cumulative counter low word + size a2) in the element array at index this[5], clears (marks used) a2 bits in the underlying bitmap byte array, increments the cumulative counter this[4] and element index this[5], returns the allocated slot index through *a3, and returns 1.
    // CALL: Grow bitmap buffer via sub_59B490(this, a2) so the requested range fits. [callee:0x0059B490]
    // CALL: Grow dynamic element array via GrowDynamicElementArray(this) so the next element index is within capacity. [callee:0x0059B530]
    // ASSIGNMENT: Write the low word of the cumulative counter (field 0x10) as the first word of element entry at this[2] + 4*this[5] in the element array (field 0x8), indexed by this[5] (field 0x14). [field:this:0x00000008, field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Write a2 as the size word at element entry this[2] + 4*this[5] + 2. [field:this:0x00000008]
    // LOOP: Clear (mark used) a2 bits in the bitmap byte array at *this (field 0x0): for each bit index v4 from the recorded cumulative counter to v4+a2, AND out bit (v4 & 7) in byte (v4 >> 3). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010]
    // ASSIGNMENT: Output the allocated slot index: *a3 = this[5] (element index, field 0x14). [field:this:0x00000014]
    // ASSIGNMENT: Increment cumulative allocated-unit counter this[4] (field 0x10) by a2. [field:this:0x00000010]
    // ASSIGNMENT: Increment element index / allocation count this[5] (field 0x14) by 1. [field:this:0x00000014]
    // RETURN: Return 1 (allocation always succeeds from caller perspective). [function:0x0059B5C0]

    // Conservative worker pseudocode:
    //   grow_bitmap_buffer(this, a2);
    //   grow_element_array(this);
    //   elem = element_array[this->count];  // this[2] + 4*this[5]
    //   elem.cumulative_count_word = (uint16)this->cumulative;
    //   elem.size_word = a2;
    //   for (bit = (uint16)this->cumulative; bit < (uint16)this->cumulative + a2; bit++)
    //       bitmap[bit >> 3] &= ~(1u << (bit & 7));
    //   *out_slot = this->count;
    //   this->cumulative += a2;
    //   this->count += 1;
    //   return 1;
}
