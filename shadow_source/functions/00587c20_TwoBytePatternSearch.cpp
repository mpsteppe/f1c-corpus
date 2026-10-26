// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587C20
// Canonical corpus name: sub_587C20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587C20_00587c20.c

void UnknownObject::TwoBytePatternSearch()
{
    // Searches the null-terminated haystack string a1 for the two-byte pattern stored at a2 (bytes a2[0] and a2[1], i.e. fields this+0 and this+1). Returns a pointer to the match start, returns a1 unchanged when the pattern's first byte is empty, and returns 0 when the haystack is exhausted without a match. A single-byte pattern falls through to a tail-jump continuation at 0x589DB6.
    // ASSIGNMENT: Load the first pattern byte v2 = a2[0] (field this+0). [field:this:0x00000000, source:raw]
    // GUARD: If the pattern is empty (a2[0] == 0), return a1 unchanged. [source:raw]
    // ASSIGNMENT: Load the second pattern byte v4 = a2[1] (field this+1). [field:this:0x00000001, source:raw]
    // GUARD: If the pattern has only one byte (v4 == 0), tail-jump to the continuation block at 0x589DB6 for the single-byte search path. [source:raw]
    // LOOP: Scan the haystack for the first pattern byte v2, advancing v6 one byte at a time. [source:raw]
    // GUARD: When a candidate byte equals v2, check the following haystack byte against v4; on failure restart the outer scan. [source:raw]
    // LOOP: Verify the remaining pattern byte pairs (v5[2]/v5[3], then two bytes further each iteration) against the haystack, stepping two bytes at a time; a mismatching pair restarts the outer scan (LABEL_3). [source:raw]
    // RETURN: Return the match start pointer (v3 - 1) on full pattern match, or 0 when the haystack is exhausted without a match. [source:raw]

    // Conservative worker pseudocode:
    //   char c0 = a2[0], c1 = a2[1];
    //   if (!c0) return a1;
    //   if (!c1) goto single_byte_continuation_at_0x589DB6;
    //   const char *h = a1;
    //   while (*h) {
    //     if (*h == c0 && h[1] == c1) {
    //       const char *p = a2 + 2, *hp = h + 2;
    //       for (;;) {
    //         if (!*p) return h;
    //         hp += 2; if (*hp != *p) goto rescan; p += 2;
    //         if (!*p) return h;
    //         if (*(hp - 1) != *p) goto rescan;
    //       }
    //     }
    //     rescan: h++;
    //   }
    //   return 0;
    // UNRESOLVED: JUMPOUT to 0x589DB6 (the single-byte pattern path) is a tail jump outside this function body; its behavior is not modeled here.
    // UNRESOLVED: The packet prelabel flags this function as a structural twin of cluster representative 0045d4e0 (cluster_copy, DERIVED) sharing the tail block at 0x589DB6; the twin relationship is not independently verified from this body alone.
}
