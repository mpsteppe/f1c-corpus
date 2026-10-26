// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599615
// Canonical corpus name: BufferWriteWithNullTerminate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferWriteWithNullTerminate_00599615.c

void UnknownObject::BufferWriteWithNullTerminate()
{
    // Writes a3 bytes from source pointer a2 into the buffer owned by this, after ensuring capacity via sub_599560. On success the buffer pointer at this+0x4 is the copy destination, the recorded size at this+0x8 is set to a3, and a terminating NUL is appended. Returns this. Callers include ConditionalStringFreeWithLengthCheck (005995e5), ObjectConstructorWithVTableAndStringInit (0059abcd), and four others.
    // GUARD: Only perform the write when sub_599560(this, a3, 1) returns non-zero; that call is treated as a buffer-capacity check/resize that must succeed. [callee:0x00599560, source:raw]
    // CALL: Copy a3 bytes from source a2 to the destination buffer pointer at this+0x4 via MemoryCopy_cc00. [callee:0x0058CC00, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Read the buffer pointer at this+0x4 into v4 for the null-termination step. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Record the written byte count: this+0x8 is set to a3. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Null-terminate the buffer by writing a zero byte at v4 + a3, one past the last copied byte. [field:this:0x00000004, source:raw]
    // RETURN: Return this (the buffer object) regardless of whether the write was performed. [source:raw]

    // Conservative worker pseudocode:
    //   void* BufferWriteWithNullTerminate(this, const void* src, unsigned int n) {
    //     if (sub_599560(this, n, 1)) {
    //       MemoryCopy_cc00(this->buffer, src, n);
    //       this->size = n;
    //       ((char*)this->buffer)[n] = 0;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: The semantics of the third argument 1 passed to sub_599560 (growth policy, alignment, or exact-fit flag) are unknown.
    // UNRESOLVED: Whether sub_599560 reallocates and updates the buffer pointer at this+0x4 or only validates capacity is not visible in this packet; the raw code reads this+0x4 only after the call returns.
    // UNRESOLVED: The memory-management regime (owned heap block vs borrowed) for the buffer at this+0x4 is not established.
}
