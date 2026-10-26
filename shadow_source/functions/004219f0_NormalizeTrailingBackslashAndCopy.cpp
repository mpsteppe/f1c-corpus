// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004219F0
// Canonical corpus name: DualFunctionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFunctionDispatch_004219f0.c

void UnknownObject::NormalizeTrailingBackslashAndCopy()
{
    // Thin stdcall helper that takes a C string, normalizes its trailing backslash via PathTrailingBackslashNormalizer, then returns the result of StringCopyWithBufferRealloc applied to the same string.
    // CALL: Call PathTrailingBackslashNormalizer on argument a1, normalizing a trailing backslash in the path string. [callee:0x00421890, source:raw]
    // RETURN: Return the result of StringCopyWithBufferRealloc(a1), a copy of the normalized string with buffer reallocation. [callee:0x00566650, source:raw]

    // Conservative worker pseudocode:
    //   PathTrailingBackslashNormalizer(a1);
    //   return StringCopyWithBufferRealloc(a1);
    // UNRESOLVED: Ownership and reallocation semantics of StringCopyWithBufferRealloc are not established from this packet.
    // UNRESOLVED: Whether a1 is a path (DERIVED from callee name) or a generic string is not confirmed.
    // UNRESOLVED: Return value meaning (new buffer pointer vs status) is unknown without callee analysis.
}
