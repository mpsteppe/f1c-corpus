// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005992EF
// Canonical corpus name: BufferAppendWithMemset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferAppendWithMemset_005992ef.c

void UnknownObject::BufferAppendWithMemset()
{
    // Appends length bytes of the fill value a3 to a growable buffer: the data block lives at this+0x4 and the current size/end offset at this+0x8. First guards against size overflow (when -1 - size <= append length it raises via the sub_59AD49 length_error path) and against a zero append length. Then computes the new end position v4 = size + append length, validates that region with sub_599560, and when validation passes fills a3 into length bytes at (data + size) via sub_58BB10, advances the size at this+0x8 to v4, and writes a null terminator at the new end. Returns this.
    // GUARD: Overflow check: if (-1 - size at this+0x8) <= append length, invoke the sub_59AD49 error path (the std::length_error 'string too long' throw helper). [field:this:0x00000008, callee:0x0059AD49, source:raw]
    // GUARD: If the append length is zero, skip the append entirely and return this. [source:raw]
    // CALCULATION: Compute the new end position v4 = &retaddr[size at this+0x8], i.e. current size plus the append length. [field:this:0x00000008, source:raw]
    // CALL: sub_599560(v4, 0) validates the memory region at the new end position; the append proceeds only when it returns non-zero. [callee:0x00599560, field:this:0x00000008, source:raw]
    // CALL: sub_58BB10(data at this+0x4 + size at this+0x8, fill value a3, append length) fills that many bytes with a3 at the current buffer end (memset-like). [callee:0x0058BB10, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Advance the size at this+0x8 to the new end position v4. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write a null terminator byte at (data at this+0x4)[old size], i.e. the final appended position. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return this (buffer object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   if ((unsigned)(-1 - this->size /* +0x8 * /) <= appendLen) sub_59AD49(...);  // length_error
    //   if (appendLen) {
    //       newEnd = appendLen + this->size;
    //       if (sub_599560(newEnd, 0)) {
    //           sub_58BB10(this->data /* +0x4 * / + this->size, fill, appendLen);  // fill bytes
    //           this->size = newEnd;
    //           this->data[this->size] = 0;  // null terminate
    //       }
    //   }
    //   return this;
    // UNRESOLVED: Global dword_5B9C38 is listed as read but does not appear in the raw source text of this function.
    // UNRESOLVED: The decompiler aliases the stack slot 'retaddr' to the second argument (append length); the argument's identity as a length is DERIVED from the arithmetic v4 = &retaddr[this[2]].
    // UNRESOLVED: The meaning of the 0 second argument to sub_599560 and the semantics of its non-zero return are unknown.
    // UNRESOLVED: sub_58BB10 is treated as a memset-like fill from its argument shape (buffer pointer, byte value a3, count); its exact contract is unverified.
    // UNRESOLVED: The owning class of the growable buffer object (data at +0x4, size at +0x8) is unidentified.
}
