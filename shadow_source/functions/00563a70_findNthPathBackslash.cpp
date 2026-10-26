// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563A70
// Canonical corpus name: PathBackslashCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathBackslashCounter_00563a70.c

void UnknownObject::findNthPathBackslash()
{
    // Scans a byte buffer from a1 for a2 bytes looking for the n-th backslash (0x5C = 92) character, where n is a3. Returns the position of the n-th backslash as an offset from a1, returns 0 immediately when n is zero, and returns -1 when fewer than n backslashes exist in the range. Called by sub_563870.
    // GUARD: If a3 (count to find) is zero, returns 0 immediately without scanning. [source:raw]
    // ASSIGNMENT: Sets v5 to the end of the scan range a1 + a2 and initializes the scan pointer v4 to a1. [source:raw]
    // LOOP: Iterates while the scan pointer v4 has not reached the end v5. [source:raw]
    // GUARD: When the current byte *v4 equals 92 (backslash), decrements the remaining count v3. [source:raw]
    // CALCULATION: Advances the scan pointer v4 by one byte. [source:raw]
    // RETURN: Returns v4 - a1 (the position offset) as soon as the remaining count v3 reaches zero, i.e. the n-th backslash has been passed. [source:raw]
    // RETURN: After the loop, returns -1 when the remaining count v3 is still nonzero (fewer than n backslashes present), otherwise returns the final position v4 - a1. [source:raw]

    // Conservative worker pseudocode:
    //   int findNthPathBackslash(_BYTE *a1, int a2, int a3) {
    //       int remain = a3;
    //       _BYTE *p = a1;
    //       if (a3 == 0)
    //           return 0;
    //       _BYTE *end = &a1[a2];
    //       while (p != end) {
    //           if (*p == 92)
    //               --remain;
    //           ++p;
    //           if (remain == 0)
    //               return p - a1;
    //       }
    //       return (remain != 0) ? -1 : p - a1;
    //   }
    // UNRESOLVED: Return position counts the byte just after the n-th backslash (offset of the following byte), not the index of the backslash itself; whether callers expect the index of the backslash or the byte after it is undocumented.
    // UNRESOLVED: The purpose of caller sub_563870 (path splitting vs. tokenization) is undocumented by the packet.
    // UNRESOLVED: No class or module identity is given for this routine.
}
