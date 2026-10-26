// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421990
// Canonical corpus name: ShortComputation_1990
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1990_00421990.c

void UnknownObject::NormalizePathAndCopyString()
{
    // Path-string registration helper: normalizes trailing backslashes on the input path a1 via PathTrailingBackslashNormalizer, then returns the integer result of copying the normalized string through StringCopyWithBufferRealloc. Called by ConfigIniParser.
    // CALL: Calls PathTrailingBackslashNormalizer(a1) to normalize trailing backslashes on the input path string. [callee:0x00421890, source:raw]
    // CALL: Calls StringCopyWithBufferRealloc(a1) to copy the normalized path string into a realloc-managed buffer. [callee:0x00566650, source:raw]
    // RETURN: Returns the integer result of StringCopyWithBufferRealloc(a1). [callee:0x00566650, source:raw]
    // CALL: Reached from ConfigIniParser (00421CD0) as one of a chain of path-registration helpers. [caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   PathTrailingBackslashNormalizer(a1);
    //   return StringCopyWithBufferRealloc(a1);
}
