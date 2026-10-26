// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421930
// Canonical corpus name: ChainedCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChainedCall_00421930.c

void UnknownObject::NormalizePathAndCopyString()
{
    // Takes a path string, normalizes trailing backslashes via PathTrailingBackslashNormalizer, then returns the result of copying the string through StringCopyWithBufferRealloc. Called by ConfigIniParser.
    // CALL: Calls PathTrailingBackslashNormalizer(a1) to normalize trailing backslashes on the input path string. [callee:0x00421890, source:raw]
    // CALL: Calls StringCopyWithBufferRealloc(a1) to copy the normalized path string into a realloc-managed buffer. [callee:0x00566650, source:raw]
    // RETURN: Returns the integer result of StringCopyWithBufferRealloc(a1). [callee:0x00566650, source:raw]

    // Conservative worker pseudocode:
    //   PathTrailingBackslashNormalizer(a1);
    //   return StringCopyWithBufferRealloc(a1);
}
