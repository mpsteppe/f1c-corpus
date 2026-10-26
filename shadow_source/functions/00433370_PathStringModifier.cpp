// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433370
// Canonical corpus name: PathStringModifier
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathStringModifier_00433370.c

void UnknownObject::PathStringModifier()
{
    // Runs directory-path extraction/comparison (PathDirectoryExtractionAndComparison) on this+0x8 with arguments a2/a3. If global byte_7C56C0 is set and strlen(a2) < a3-1, appends the word_5C406C marker to the end of the a2 string; sets the a4 output flag to 1. Otherwise sets the a4 flag to 0. Returns the a4 pointer.
    // CALL: Run PathDirectoryExtractionAndComparison on this+0x8 with the path buffer a2 and capacity a3. [callee:0x00433290, function:0x00433370]
    // GUARD: If global byte_7C56C0 is set. [global:0x007C56C0]
    // CALCULATION: Check whether strlen(a2) is less than a3 - 1 (buffer has room for the appended marker). [source:raw]
    // ASSIGNMENT: Append the word_5C406C marker at the end of the a2 string. [global:0x005C406C]
    // GUARD: If the a4 output pointer is non-null. [source:raw]
    // ASSIGNMENT: Set the a4 output flag to 1 (path modified). [source:raw]
    // GUARD: Else branch: if the a4 output pointer is non-null. [source:raw]
    // ASSIGNMENT: Set the a4 output flag to 0 (path not modified). [source:raw]
    // RETURN: Return the a4 output pointer. [source:raw]

    // Conservative worker pseudocode:
    //   PathDirectoryExtractionAndComparison(this + 2, a2, a3);
    //   if (byte_7C56C0) {
    //     if (strlen(a2) < a3 - 1) *(WORD *)(a2 + strlen(a2)) = word_5C406C;
    //     if (a4) *a4 = 1;
    //   } else {
    //     if (a4) *a4 = 0;
    //   }
    //   return a4;
    // UNRESOLVED: The meaning of the word_5C406C marker and of the global flag byte_7C56C0 is unverified from packet evidence alone.
    // UNRESOLVED: Whether the append at end of a2 can exceed the declared capacity is unverified; the guard relies on a3 - 1 only.
}
