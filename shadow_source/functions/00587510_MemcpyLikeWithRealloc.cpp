// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587510
// Canonical corpus name: MemcpyLikeWithRealloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemcpyLikeWithRealloc_00587510.c

void UnknownObject::MemcpyLikeWithRealloc()
{
    // Manages a growable buffer (pointer at 0x0, capacity at 0x4, stored size at 0x8). If a3 exceeds capacity, frees the old buffer and allocates a new one of size a3. When the buffer is non-null and a3 is positive, copies a3 bytes from a2 into it and records the stored size; otherwise records stored size 0. Returns 1 in both paths.
    // GUARD: If requested size a3 is greater than current capacity (this+4), the buffer must be reallocated. [field:this:0x00000004]
    // CALL: If an old buffer exists at this+0, free it via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000]
    // CALL: Allocate a new buffer of size a3 via OperatorNewWithResultCheck, storing the result into this+0. [callee:0x005874D0, field:this:0x00000000]
    // ASSIGNMENT: Update capacity (this+4) to the new size a3. [field:this:0x00000004]
    // GUARD: If the buffer at this+0 is non-null and a3 is positive, copy a3 bytes from a2 into it and record stored size a3 at this+8. [field:this:0x00000000, field:this:0x00000008]
    // ASSIGNMENT: On the copy path, set stored size (this+8) to a3. [field:this:0x00000008]
    // ASSIGNMENT: On the skip path (null buffer or non-positive size), set stored size (this+8) to 0. [field:this:0x00000008]
    // RETURN: Return 1 on the copy path and on the skip path (skip is not an error). [source:raw]

    // Conservative worker pseudocode:
    //   if (a3 > this->capacity) {
    //       if (this->buf) FreeWrapper_7bcf(this->buf);
    //       OperatorNewWithResultCheck(a3, &this->buf);
    //       this->capacity = a3;
    //   }
    //   if (this->buf && a3 > 0) {
    //       qmemcpy(this->buf, a2, a3);
    //       this->storedSize = a3;
    //       return 1;
    //   }
    //   this->storedSize = 0;
    //   return 1;
    // UNRESOLVED: The stored-size field at this+8 appears in a growable-buffer pattern shared with the caller MemcpyLikeWithRealloc-style buffers; exact struct layout (allocation header versus pure data buffer) is unconfirmed.
    // UNRESOLVED: Allocation failure inside OperatorNewWithResultCheck is not explicitly guarded in this function, so behavior when the allocator reports failure is inferred, not evidenced.
    // UNRESOLVED: Field at this+0 is read from and written to across the realloc path; the init_literal 0 recorded for this+8 comes from the skip-path assignment only.
}
