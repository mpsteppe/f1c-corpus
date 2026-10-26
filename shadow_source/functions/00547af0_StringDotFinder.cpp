// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547AF0
// Canonical corpus name: StringDotFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringDotFinder_00547af0.c

void UnknownObject::StringDotFinder()
{
    // Truncates a string at its first dot character (ASCII 46): scans for the dot, replaces it with a NUL terminator, and returns 1. Returns 0 when the string is empty or contains no dot. Called by StringSearchInLinkedList to normalize a key before comparison.
    // CALL: Calls strlen on the input string to determine whether it is empty [source:raw]
    // GUARD: Returns 0 immediately when the string is empty [source:raw, function:0x00547AF0]
    // LOOP: Scans forward through the string until a dot character (ASCII 46) is found or the end of the string is reached [source:raw]
    // GUARD: Returns 0 when the end of the string is reached without finding a dot [source:raw]
    // STATE_TRANSITION: Overwrites the found dot with a NUL terminator, truncating the string at that position [source:raw]
    // RETURN: Returns 1 to signal the string was truncated at its first dot [source:raw]

    // Conservative worker pseudocode:
    //   if (strlen(s) == 0) return 0;
    //   for (i = 0; i < strlen(s); i++)
    //       if (s[i] == '.') { s[i] = 0; return 1; }
    //   return 0;
}
