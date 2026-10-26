// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566650
// Canonical corpus name: StringCopyWithBufferRealloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithBufferRealloc_00566650.c

void UnknownObject::StringCopyWithBufferRealloc()
{
    // Copies a source string into a managed buffer (this+0x0) with capacity tracked at this+0x4, reallocating via free + new when the buffer is null or too small. Returns 0 on success, -1 on null input.
    // GUARD: If the source string a2 is null, return -1. [source:raw]
    // RETURN: Return -1 on null input. [source:raw]
    // CALCULATION: Compute v4 = strlen(a2) + 1. [source:raw]
    // GUARD: If the stored buffer pointer (this+0x0) is null, skip straight to allocation (LABEL_6). [field:this:0x00000000, source:raw]
    // GUARD: If the tracked capacity (this+0x4) is less than (signed)(v4 - 1), the buffer is too small and must be freed and reallocated. [field:this:0x00000004, source:raw]
    // CALL: Free the old buffer via FreeWrapper_7bcf(*(void**)this). [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Allocate a new buffer of v4 bytes via OperatorNewNhMallocWrapper and store it in this+0x0. [callee:0x00587C03, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Update the tracked capacity this+0x4 to v4 - 1. [field:this:0x00000004, source:raw]
    // CALL: Copy a2 into the buffer with strcpy(*(char**)this, a2). [source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == NULL) return -1;
    //   unsigned int len = strlen(a2) + 1;
    //   if (this->buffer == NULL || this->capacity < (int)(len - 1)) {
    //     FreeWrapper_7bcf(this->buffer);
    //     this->buffer = OperatorNewNhMallocWrapper(len);
    //     this->capacity = len - 1;
    //   }
    //   strcpy(this->buffer, a2);
    //   return 0;
    // UNRESOLVED: strlen and strcpy are implicit CRT calls with no callee evidence refs in the packet; they are represented only via source:raw.
}
