// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004218F0
// Canonical corpus name: StringCopyRealloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyRealloc_004218f0.c

void UnknownObject::StringCopyRealloc()
{
    // Thin __stdcall path-registration delegate: normalizes the trailing backslash of the path string a1 in place via PathTrailingBackslashNormalizer (0x00421890, its character return is discarded), then returns the integer result of StringCopyWithBufferRealloc(a1) (0x00566650). The only caller is ConfigIniParser (0x00421CD0), so this is part of config-path string registration rather than a standalone utility.
    // CALL: Normalize the trailing backslash of the path string a1 in place via PathTrailingBackslashNormalizer; the returned character is discarded. [callee:0x00421890, source:raw]
    // CALL: Copy the string a1 into a realloc-capable buffer via StringCopyWithBufferRealloc and keep its result as the return value. [callee:0x00566650, source:raw]
    // RETURN: Return the integer result produced by StringCopyWithBufferRealloc(a1). [source:raw, abi:lead]
    // RETURN: Function 0x004218F0 is called by ConfigIniParser to register a config path string. [caller:0x00421CD0, function:0x004218F0]

    // Conservative worker pseudocode:
    //   int sub_4218F0(const char *a1) {
    //     PathTrailingBackslashNormalizer(a1);
    //     return StringCopyWithBufferRealloc(a1);
    //   }
    // UNRESOLVED: The return semantics of StringCopyWithBufferRealloc (buffer ownership, allocated size) are not evidenced by this packet.
    // UNRESOLVED: Whether a1 points to a caller-owned buffer that is safe to modify in place is assumed, not verified.
    // UNRESOLVED: ConfigIniParser's use of the returned value is not evidenced by this packet.
}
