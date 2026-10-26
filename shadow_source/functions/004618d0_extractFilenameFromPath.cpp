// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004618D0
// Canonical corpus name: ReversePathSearchForBackslash
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReversePathSearchForBackslash_004618d0.c

void UnknownObject::extractFilenameFromPath()
{
    // Path utility that returns a pointer to the final path component by scanning backward from the end of a NUL-terminated string for the last backslash (ASCII 92). The ABI legacy name records it as extracting a filename from a path. It is called once, from SessionConfigBuilder at 0x00461610. With no backslash present the string start is returned.
    // CALCULATION: result = &a1[strlen(a1)]: positions a scan pointer at the terminating NUL of the input path string. [source:raw, abi:lead]
    // GUARD: if (result > a1): only scan backward when the string is non-empty; an empty string returns the start pointer immediately. [source:raw]
    // LOOP: Scan backward while *result != 92 (backslash); on each iteration decrement `result` and return the string start when the pointer reaches the beginning. [source:raw]
    // RETURN: On finding a backslash, ++result advances just past it and the function returns the pointer to the path's final component (filename after the last backslash). [source:raw]

    // Conservative worker pseudocode:
    //   const char *p = path + strlen(path);
    //   if (p > path) {
    //       while (*p != 92) {
    //           if (--p <= path) return p;
    //       }
    //       ++p;
    //   }
    //   return p;
    // UNRESOLVED: The packet does not document how SessionConfigBuilder (0x00461610) consumes the returned filename pointer.
    // UNRESOLVED: With no backslash in the path the function returns the string start; this boundary behavior is unconfirmed to match the caller's expectations.
    // UNRESOLVED: This is a standalone free function; no owning class is evidenced by the packet.
}
