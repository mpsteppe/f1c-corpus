// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564A20
// Canonical corpus name: BufferIndexComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferIndexComputation_00564a20.c

void UnknownObject::BufferIndexComputation()
{
    // Searches a buffer object for a matching element and returns its index as (match_pointer - buffer_base) / stride, or -1 on failure. Returns -1 when the this pointer is null or the element count at this+0 is 0. Dispatch on a4: a nonzero value selects a binary search path, a zero value a linear stride-search path; both paths first run LinearInterpolation on (this, a3) and only succeed when a match pointer is returned and the found-flag v12 stayed nonzero.
    // ASSIGNMENT: Initialize the found-flag local v12 to 1. [function:0x00564A20, source:raw]
    // GUARD: Return -1 when the this pointer is null. [source:raw]
    // GUARD: Return -1 when the element count at this+0 is 0 (empty buffer). [field:this:0x00000000, source:raw]
    // GUARD: Dispatch on a4: a nonzero value selects the binary-search path, a zero value the linear stride-search path. [source:raw]
    // ASSIGNMENT: Binary path: capture the stride this[2] (this+8) and compute the search range v8 as the element-count value minus a3. [field:this:0x00000008, source:raw]
    // CALL: LinearInterpolation((int)this, a3) computes the starting offset into the buffer. [callee:0x005648B0, source:raw]
    // CALL: BinarySearchWithCallbackComparator(v8, v9, a2, &v12) searches for the key and clears v12 when no element matches. [callee:0x00564B10, source:raw]
    // ASSIGNMENT: Linear path: capture the stride this[2] (this+8) and compute the search range v10 as the element-count value minus a3. [field:this:0x00000008, source:raw]
    // CALL: LinearInterpolation((int)this, a3) computes the starting offset into the buffer. [callee:0x005648B0, source:raw]
    // CALL: CallbackBasedArrayStrideSearch(v10, v11, a2) walks the buffer by stride looking for the key element. [callee:0x00564AB0, source:raw]
    // GUARD: Only when a match pointer v6 was returned and the found-flag v12 is still nonzero is the element index computed. [source:raw]
    // CALCULATION: Return (v6 - this[5]) / this[2]: subtract the buffer base pointer at this+0x14 from the match pointer and divide by the stride at this+8. [field:this:0x00000014, field:this:0x00000008, source:raw]
    // RETURN: Return -1 when the guard fails, the buffer is empty, no match was found, or the found-flag was cleared. [source:raw]

    // Conservative worker pseudocode:
    //   int BufferIndexComputation(int* this, int a2, int a3, int a4) {
    //     int found = 1;
    //     if (!this) return -1;
    //     if (!*this) return -1;
    //     if (a4) {
    //       int stride = this[2];
    //       int range = *this - a3;
    //       LinearInterpolation((int)this, a3);
    //       int* hit = BinarySearchWithCallbackComparator(range, stride, a2, &found);
    //       if (hit && found) return (hit - this[5]) / this[2];
    //     } else {
    //       int stride = this[2];
    //       int range = *this - a3;
    //       LinearInterpolation((int)this, a3);
    //       int* hit = CallbackBasedArrayStrideSearch(range, stride, a2);
    //       if (hit && found) return (hit - this[5]) / this[2];
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The buffer object layout beyond the element count at this+0, the stride at this+8 and the base pointer at this+0x14 is unknown; the search keys a2 and a3 (a3 subtracted from the element count to form the range) have no established meaning in the packet.
    // UNRESOLVED: The exact pre-search adjustment performed by LinearInterpolation is not described by the raw source; it is invoked with the this pointer and a3 on both paths.
}
