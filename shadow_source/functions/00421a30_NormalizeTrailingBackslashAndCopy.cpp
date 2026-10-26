// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421A30
// Canonical corpus name: DualDispatchProcessPathRegister
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualDispatchProcessPathRegister_00421a30.c

void UnknownObject::NormalizeTrailingBackslashAndCopy()
{
    // Path-string helper: normalizes the trailing backslash of the input string a1 via PathTrailingBackslashNormalizer (0x00421890), then returns the result of StringCopyWithBufferRealloc (0x00566650), which produces a copied buffer sized/reallocated for the string. Called by ConfigIniParser (0x00421CD0) when it handles path-valued config entries. The ABI legacy name Dual_Dispatch_Process_Path_Register is a descriptive label only.
    // CALL: PathTrailingBackslashNormalizer (0x00421890) is invoked with a1 to strip a trailing backslash from the path string before it is copied [callee:0x00421890, source:raw]
    // CALL: StringCopyWithBufferRealloc (0x00566650) is invoked with the same a1 and its return value becomes the function result, allocating a buffer large enough for the normalized copy [callee:0x00566650, source:raw]
    // RETURN: The value returned to the caller is the buffer produced by StringCopyWithBufferRealloc(a1); a1 itself is only mutated by the preceding normalizer, never returned [callee:0x00566650, source:raw]
    // CALL: Invoked by ConfigIniParser (0x00421CD0) as a helper when parsing path-valued configuration entries [caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   PathTrailingBackslashNormalizer(a1);
    //   return StringCopyWithBufferRealloc(a1);
    // UNRESOLVED: Ownership/lifetime contract of the buffer returned by StringCopyWithBufferRealloc (0x00566650) is not resolvable from this packet (who frees it)
    // UNRESOLVED: Several adjacent functions expose the identical body; whether they are distinct call sites of one helper or duplicated inline copies is not resolvable from this packet alone
}
