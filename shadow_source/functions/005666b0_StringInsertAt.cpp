// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005666B0
// Canonical corpus name: sub_5666B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5666B0_005666b0.c

void UnknownObject::StringInsertAt()
{
    // Inserts string a3 into a managed buffer (char* at this+0x0, capacity at this+0x4) at character position a2. Grows the buffer before inserting: on realloc the capacity increases by max(a4, strlen(a3)); on a null buffer a fresh buffer of that size is allocated and zeroed. Shifts the tail [a2..cur_len) right by strlen(a3), then copies a3 in. Returns 0 on success, -1 when a2 is negative or exceeds the current string length. Structural twin of StringCopyWithBufferRealloc (00566650) per the DERIVED cluster prelabel.
    // CALCULATION: Compute v5 = strlen(a3) + 1, then v6 = v5 - 1; v6 is the number of characters to insert. [source:raw]
    // CALCULATION: Determine current string length v7: if the buffer pointer (this+0x0) is non-null, v7 = strlen(*(const char**)this); otherwise v7 = 0. [field:this:0x00000000, source:raw]
    // GUARD: Validate insert position: if a2 < 0 or a2 > v7, return -1. [source:raw]
    // RETURN: Return -1 when a2 is out of range [0, current length]. [function:0x005666B0, source:raw]
    // GUARD: Realloc path: if the buffer (this+0x0) is non-null and the tracked capacity v11 (this+0x4) is less than v11 + v6 (i.e. v6 > 0), the buffer is too small for the insert. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: Compute growth v12 = a4, but if v6 > a4 use v12 = v6; new capacity v13 = v11 + v12. [field:this:0x00000004, source:raw]
    // CALL: Allocate a new buffer of v13 + 1 bytes via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // CALL: Copy the old contents into the new buffer with strcpy(v14, *(const char**)this). [field:this:0x00000000, source:raw]
    // CALL: Free the old buffer via FreeWrapper_7bcf(*(void**)this). [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the new buffer in this+0x0 and the new capacity v13 in this+0x4. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: Null-buffer path: compute capacity v9 = a4, but if v6 > a4 use v9 = v6; store v9 in this+0x4, allocate a v9 + 1 byte buffer via OperatorNewNhMallocWrapper, store it in this+0x0 and zero its first byte. [callee:0x00587C03, field:this:0x00000000, field:this:0x00000004, source:raw]
    // LOOP: Shift the tail right by v6 to make room: for i from v7 down to a2, buffer[i + v6] = buffer[i]. [field:this:0x00000000, source:raw]
    // LOOP: Copy a3 into the vacated range: for j from 0 to v6 - 1, buffer[a2 + j] = a3[j]. [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on success. [function:0x005666B0, source:raw]

    // Conservative worker pseudocode:
    //   int insert_len = strlen(a3);
    //   int cur_len = (buffer != NULL) ? strlen(buffer) : 0;
    //   if (a2 < 0 || a2 > cur_len) return -1;
    //   if (buffer != NULL) {
    //     int grow = (insert_len > a4) ? insert_len : a4;
    //     int new_cap = capacity + grow;
    //     char* nb = (char*)OperatorNewNhMallocWrapper(new_cap + 1);
    //     strcpy(nb, buffer);
    //     FreeWrapper_7bcf(buffer);
    //     buffer = nb;
    //     capacity = new_cap;
    //   } else {
    //     capacity = (insert_len > a4) ? insert_len : a4;
    //     buffer = (char*)OperatorNewNhMallocWrapper(capacity + 1);
    //     buffer[0] = 0;
    //   }
    //   for (i = cur_len; i >= a2; --i) buffer[i + insert_len] = buffer[i];
    //   for (j = 0; j < insert_len; ++j) buffer[a2 + j] = a3[j];
    //   return 0;
    // UNRESOLVED: strlen and strcpy are implicit CRT calls with no callee evidence refs in the packet; represented only via source:raw.
    // UNRESOLVED: a4 (minimum extra capacity) is caller policy; its typical value is unknown.
    // UNRESOLVED: The managing object type is unidentified (UnknownObject).
}
