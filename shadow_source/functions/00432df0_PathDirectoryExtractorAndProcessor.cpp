// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432DF0
// Canonical corpus name: sub_432DF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_432DF0_00432df0.c

void UnknownObject::PathDirectoryExtractorAndProcessor()
{
    // Computes a derived value from a2 via ShortComputation_0b10 and copies it through StringCopyWithBufferRealloc, then extracts the directory portion of a path string: the first string of this (falling back to the default buffer byte_5EA438 when null) is truncated at its last backslash (0x5C / 92) by zeroing trailing characters. Finally the first global function-pointer slot off_5C3F9C[0] is passed to sub_5665B0 for path processing.
    // CALL: ShortComputation_0b10(a2) computes a derived value from the a2 argument and stores it into v3. [callee:0x004B0B10]
    // CALL: StringCopyWithBufferRealloc(v3) copies the computed string into a destination with automatic buffer reallocation. [callee:0x00566650]
    // ASSIGNMENT: Load the first string pointer of this; when this[0] is null, fall back to the default buffer byte_5EA438. [field:this:0x00000000, global:0x005EA438, source:raw]
    // CALCULATION: Compute the path length v5 = strlen(v4) + 1; if (v5 - 1) > 0 the truncation loop runs. [source:raw]
    // LOOP: Walk backward from &v4[v5 - 2] to v4, zeroing each character until a backslash byte (92 / 0x5C) is found, which strips the filename and leaves the directory part. [source:raw]
    // CALL: sub_5665B0(off_5C3F9C[0]) processes the (now directory-only) path via the first entry of the global function-pointer/table at off_5C3F9C. [callee:0x005665B0, global:0x005C3F9C]
    // RETURN: Return the result of sub_5665B0. [source:raw]

    // Conservative worker pseudocode:
    //   int PathDirectoryExtractorAndProcessor(const char **this, int a2) {
    //     int v3 = ShortComputation_0b10(a2);
    //     StringCopyWithBufferRealloc(v3);
    //     const char *p = this[0];
    //     if (!p) p = &byte_5EA438;
    //     unsigned int len = strlen(p) + 1;
    //     if ((int)(len - 1) > 0) {
    //       const char *i = &p[len - 2];
    //       for (; i >= p; *i-- = 0) { if (*i == 92) break; }
    //     }
    //     return sub_5665B0(off_5C3F9C[0]);
    //   }
    // UNRESOLVED: off_5C3F9C is a global table/function-pointer array; only slot [0] is consumed here and its meaning is external to this packet.
    // UNRESOLVED: StringCopyWithBufferRealloc returns a buffer pointer whose value is ignored by this function (only the side effect of the copy is relied upon).
    // UNRESOLVED: Exact semantics of ShortComputation_0b10(a2) and sub_5665B0 are defined by their own functions, not this packet.
}
