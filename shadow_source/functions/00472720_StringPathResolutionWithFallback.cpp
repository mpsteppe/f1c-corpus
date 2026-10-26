// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472720
// Canonical corpus name: StringPathResolutionWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringPathResolutionWithFallback_00472720.c

void UnknownObject::StringPathResolutionWithFallback()
{
    // Resolves an optional input string into a trimmed token and inserts it into a linked list, falling back to the raw third argument when the input string is missing or resolves to an empty token. When the input length (strlen + 1) exceeds 27, a scan starts at index len - 29 and advances while the byte is not a space (32) and the index is below len - 1, truncating the token at the first space; shorter strings are used whole. The chosen non-empty token is inserted via LinkedListInsertWithNodeAllocation (0x00486F30) with insertion position -1; when the input string is null or its leading token is empty, the fallback argument a3 is inserted instead.
    // GUARD: If the input string a2 is null, jump straight to the fallback insert path (LABEL_10). [source:raw]
    // CALCULATION: v5 = strlen(a2) + 1, the string length including its terminator. [source:raw]
    // GUARD: Only when (int)(v5 - 1) > 27 is the truncation scan performed; v6 is seeded to v5 - 29. [source:raw]
    // LOOP: Advance v6 over a2[v6] while the byte is not a space (32) and v6 stays below (int)(v5 - 1). [source:raw]
    // ASSIGNMENT: v3 = &a2[v6], the token start after the space scan (or the whole string when no scan ran). [source:raw]
    // GUARD: When v3 is non-null and *v3 is non-empty, insert v3; otherwise fall back to argument a3. [source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, selected_token_or_fallback, -1) inserts the token into the list with insertion position -1. [callee:0x00486F30, source:raw]

    // Conservative worker pseudocode:
    //   void sub_472720(this, const char *a2, int a3) {
    //     const char *v3 = a2;
    //     if (a2) {
    //       unsigned int v5 = strlen(a2) + 1;
    //       if ((int)(v5 - 1) > 27) {
    //         int v6 = v5 - 29;
    //         if (v5 - 29 < v5 - 1)
    //           do { char v7 = a2[v6++]; } while (v7 != 32 && v6 < (int)(v5 - 1));
    //         v3 = &a2[v6];
    //       }
    //     }
    //     if (v3 && *v3)
    //       LinkedListInsertWithNodeAllocation(this, (int)v3, -1);
    //     else
    //       LinkedListInsertWithNodeAllocation(this, a3, -1);
    //   }
    // UNRESOLVED: Meaning of the fallback argument a3 and of the -1 insertion position is not derivable from this packet.
    // UNRESOLVED: Why the 27/29-character window and the space scan are applied (name/path truncation context) is inferred from the string handling only.
    // UNRESOLVED: No callers appear in the packet, so the receiver owner and call-site purpose cannot be confirmed.
}
