// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421AF0
// Canonical corpus name: DualDelegationWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualDelegationWrapper_00421af0.c

void UnknownObject::NormalizeTrailingBackslashAndCopyString()
{
    // Path string helper (__stdcall, single const char* argument). Normalizes trailing backslashes on the input path string a1 in place via PathTrailingBackslashNormalizer, then copies the normalized string into a reallocated buffer via StringCopyWithBufferRealloc and returns that copy. Its only known caller is ConfigIniParser.
    // CALL: PathTrailingBackslashNormalizer(a1) normalizes trailing backslash characters on the input path string in place [callee:0x00421890, source:raw]
    // CALL: StringCopyWithBufferRealloc(a1) copies the normalized string into a reallocated buffer and returns the resulting pointer [callee:0x00566650, source:raw]
    // RETURN: Return the copy produced by StringCopyWithBufferRealloc; the only caller is ConfigIniParser [caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   PathTrailingBackslashNormalizer(a1);
    //   return StringCopyWithBufferRealloc(a1);
    // UNRESOLVED: The exact mutation performed by PathTrailingBackslashNormalizer and the allocation semantics of StringCopyWithBufferRealloc are not visible in this packet
    // UNRESOLVED: Whether the returned pointer is heap-owned (and by whom) is unknown from this evidence
}
