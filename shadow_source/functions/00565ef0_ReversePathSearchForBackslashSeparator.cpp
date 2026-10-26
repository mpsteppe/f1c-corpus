// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565EF0
// Canonical corpus name: ReversePathSearchForBackslashSeparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReversePathSearchForBackslashSeparator_00565ef0.c

void UnknownObject::ReversePathSearchForBackslashSeparator()
{
    // Searches the path string returned by DirectoryEntryIterator(this) backwards for the last backslash separator. Starts at the end of the string (past the NUL) and scans left; when a backslash (ASCII 92) is found it returns the position just after it, and when the scan runs past the start of the string it returns the current (already-decremented) position. Returns 0 if the iterator produced no string.
    // CALL: Obtain the path string from DirectoryEntryIterator(this) and store it in v1. [callee:0x005662D0, source:raw]
    // ASSIGNMENT: Initialize the result pointer to 0 as the no-string default. [source:raw]
    // GUARD: Guard: only search when the iterator returned a non-null string v1. [source:raw]
    // CALCULATION: Position result at the terminating NUL of v1 using strlen(v1). [source:raw]
    // GUARD: Guard: only scan when the string is non-empty (result > v1). [source:raw]
    // LOOP: Scan backwards while *result is not the backslash separator 92; if --result passes the start of the string, return result immediately; otherwise increment result past the found backslash. [source:raw]
    // RETURN: Return the located position: after the last backslash, the start position when no backslash exists, or 0 when no string was returned. [source:raw]

    // Conservative worker pseudocode:
    //   const char *ReversePathSearchForBackslashSeparator(void *this) {
    //     const char *v1 = DirectoryEntryIterator(this);
    //     const char *result = 0;
    //     if (v1) {
    //       result = &v1[strlen(v1)];
    //       if (result > v1) {
    //         while (*result != 92) {
    //           if (--result <= v1) return result;
    //         }
    //         ++result;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Whether the string returned by DirectoryEntryIterator is a full path and how the caller uses the separator-relative offset is unknown.
    // UNRESOLVED: Character 92 is the ASCII backslash, assumed here to be the path separator.
}
