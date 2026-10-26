// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564690
// Canonical corpus name: StringMallocCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringMallocCopy_00564690.c

void UnknownObject::StringMallocCopy()
{
    // Allocate-and-copy helper for C strings: if the input `this` is non-null, allocates strlen(this)+1 bytes through MallocWrapperForNhMalloc (0x0058A935) and strcpy's the source into the fresh buffer; returns the new buffer or NULL when the input was null or the allocation failed. Called by SingletonGlobalAccessorWithFallbackAlloc (0x00564270) and sub_563870 (0x00563870), which then own the returned buffer.
    // ASSIGNMENT: Initialize the result pointer to NULL before the input check. [source:raw]
    // GUARD: Guard: only proceed when the input string `this` is non-null; otherwise return NULL. [source:raw]
    // CALL: Allocate strlen(this)+1 bytes through MallocWrapperForNhMalloc (0x0058A935). [callee:0x0058A935, source:raw]
    // GUARD: Guard: if the allocation returned NULL, leave result NULL and return it (no copy). [source:raw]
    // CALL: Copy the source string into the fresh buffer with strcpy (compiler intrinsic, so no separate callee entry). [source:raw]
    // RETURN: Return the allocated and copied buffer, or NULL when input was null or allocation failed. [source:raw]
    // CALL: Callers: sub_563870 (0x00563870) and SingletonGlobalAccessorWithFallbackAlloc (0x00564270) use this to obtain owned string copies. [caller:0x00563870, caller:0x00564270, source:raw]

    // Conservative worker pseudocode:
    //   char *StringMallocCopy(const char *s) {
    //     char *result = 0;
    //     if (s) {
    //       result = MallocWrapperForNhMalloc(strlen(s) + 1);
    //       if (result)
    //         strcpy(result, s);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Ownership semantics: the returned buffer is transferred to the caller; the packet gives no free-site evidence.
    // UNRESOLVED: strlen and strcpy are compiler intrinsics and therefore have no packet callee entries; only their effect is represented.
}
