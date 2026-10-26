// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421A90
// Canonical corpus name: ShortComputation_1a90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1a90_00421a90.c

void UnknownObject::NormalizeTrailingBackslashAndCopyPath()
{
    // Wrapper that normalizes trailing backslashes on the input path via PathTrailingBackslashNormalizer, then returns the result of StringCopyWithBufferRealloc applied to the same string argument.
    // CALL: Call PathTrailingBackslashNormalizer(a1) to normalize trailing backslashes on the input path before copying. [callee:0x00421890, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(a1) and return its result, producing a copy of the (now normalized) path string. [callee:0x00566650, source:raw]
    // RETURN: Return the value returned by StringCopyWithBufferRealloc(a1). [callee:0x00566650, function:0x00421A90, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall NormalizeTrailingBackslashAndCopyPath(const char *a1)
    //   {
    //     PathTrailingBackslashNormalizer(a1);
    //     return StringCopyWithBufferRealloc(a1);
    //   }
    // UNRESOLVED: Why both a normalizer and a copy are applied to the same argument is unresolved; the caller's use of the returned string is unknown.
    // UNRESOLVED: Whether the return value of StringCopyWithBufferRealloc is a new allocation or a borrowed buffer is unresolved from static evidence.
}
