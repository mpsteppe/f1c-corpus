// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005665B0
// Canonical corpus name: sub_5665B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5665B0_005665b0.c

void UnknownObject::StringBufferConcatAlloc()
{
    // Appends string a2 to a growable string buffer: buffer pointer at this+0x0, capacity at this+0x4. If the buffer holds an existing string and its capacity is smaller than the combined length, allocates a new buffer via OperatorNewNhMallocWrapper, copies the old content, frees the old buffer with FreeWrapper_7bcf and updates pointer/capacity, then strcat-appends a2. If the buffer is empty it delegates to StringCopyWithBufferRealloc(a2). Widely called by file/path loaders and UI setup paths.
    // GUARD: If a2 is null, do nothing. [source:raw]
    // GUARD: If the buffer pointer at this+0x0 is non-null, take the in-place concat path; otherwise delegate to StringCopyWithBufferRealloc(a2). [field:this:0x00000000, source:raw]
    // CALCULATION: v3 = strlen(*this) + 1; v4 = strlen(a2) + 1; v5 = v4 - 1 + v3 - 1, the combined content length (excludes the null terminators). [field:this:0x00000000, source:raw]
    // GUARD: If capacity at this+0x4 is less than the combined length v5, reallocate. [field:this:0x00000004, source:raw]
    // CALL: Reallocation: v6 = OperatorNewNhMallocWrapper(v4 + v3 - 1); strcpy(v6, *this); FreeWrapper_7bcf(*this); *this = v6; this+0x4 = v5. [callee:0x00587C03, callee:0x00587BCF, field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: Append: strcat(*(char**)this, a2) after ensuring capacity. [field:this:0x00000000, source:raw]
    // CALL: Empty-buffer path: StringCopyWithBufferRealloc(a2) allocates and copies the string into the buffer. [callee:0x00566650, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return;
    //   if (*this) {
    //       unsigned need = strlen(*this) + strlen(a2) + 1;
    //       if (cap_at(this,4) < need - 1) {
    //           char* nb = OperatorNewNhMallocWrapper(strlen(*this) + strlen(a2) + 1);
    //           strcpy(nb, *this);
    //           FreeWrapper_7bcf(*this);
    //           *this = nb;
    //           cap_at(this,4) = strlen(*this) + strlen(a2);
    //       }
    //       strcat(*this, a2);
    //   } else {
    //       StringCopyWithBufferRealloc(a2);
    //   }
    // UNRESOLVED: Buffer pointer and capacity fields are recalculated/rewritten by this allocator, so external pokes do not persist.
    // UNRESOLVED: Owner object type (growable string container) is UNKNOWN; callers span file loaders, UI, AI settings and physics parser paths.
    // UNRESOLVED: Semantics of the v5/v4+v3-1 size arithmetic (exact terminator accounting) is transcribed from source but not proven against the allocator contract.
}
