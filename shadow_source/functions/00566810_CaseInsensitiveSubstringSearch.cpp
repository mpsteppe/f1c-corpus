// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566810
// Canonical corpus name: sub_566810
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_566810_00566810.c

void UnknownObject::CaseInsensitiveSubstringSearch()
{
    // Case-insensitive substring search. Scans the haystack string a1 for the pattern a2, comparing each haystack byte against two case variants of the pattern byte produced by sub_589A35 and sub_58B465 (presumably a lowercase and uppercase normalization). Returns a pointer to the first matching run, or 0 when no match or either input is null. Consistent with callers such as DriverNameIDLookup, TrackNameDisplayIDLookup and StringMatchingWithCaseSensitiveCaseInsensitiveMo that match names and tokens.
    // GUARD: Early return 0 when the haystack a1 is null. [source:raw]
    // GUARD: Early return 0 when the pattern a2 is null. [source:raw, function:0x00566810]
    // CALL: Call sub_589A35 with the current pattern byte to obtain the first case-normalized variant v6. [callee:0x00589A35]
    // CALL: Call sub_58B465 with the current pattern byte to obtain the second case-normalized variant v7. [callee:0x0058B465]
    // GUARD: Loop body runs only while the haystack start byte *a1 is non-zero. [source:raw, field:this:0x00000000]
    // LOOP: Scan the haystack from the current scan cursor until a terminating zero byte; the inner pattern run advances only on a match, otherwise the search resumes one byte past the last recorded run start. [source:raw]
    // CALCULATION: Match test: current haystack byte *v5 equals either case variant v6 or v7 of the pattern byte. [source:raw, caller:0x00415D90, caller:0x00417F60, caller:0x0045BA60]
    // ASSIGNMENT: Record the run start: when the run length v4 is zero, store the current scan cursor into v9 (match_start). [source:raw]
    // CALCULATION: On a match, advance the pattern cursor, increment the run length, and if the pattern terminator is reached return v9 (match start). [source:raw]
    // CALCULATION: On a mismatch, reset the run length to zero, rewind the pattern cursor to a2, move the scan cursor past the last recorded run start (v9 + 1, or v5 + 1 if none), and clear v9. [source:raw]
    // RETURN: Return v9 (pointer to the first matching run) when the full pattern is found. [source:raw]
    // RETURN: Return 0 when the haystack terminator is reached without a full match. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *sub_566810(_BYTE *haystack, char *pattern) {
    //     if (!haystack || !pattern) return 0;
    //     if (!*haystack) return 0;
    //     char *p = pattern;
    //     int run = 0;
    //     _BYTE *scan = haystack;
    //     _BYTE *match = 0;
    //     for (;;) {
    //       char lo = sub_589A35(*p);
    //       char hi = sub_58B465(*p);
    //       if (*scan == lo || *scan == hi) {
    //         if (!run) match = scan;
    //         char c = *++p;
    //         ++run;
    //         if (!c) return match;
    //         ++scan;
    //       } else {
    //         run = 0;
    //         p = pattern;
    //         scan = match ? match + 1 : scan + 1;
    //         match = 0;
    //       }
    //       if (!*scan) return 0;
    //     }
    //   }
    // UNRESOLVED: Exact direction of the two case normalizations: sub_589A35 and sub_58B465 likely map a byte to lower and upper case, but which is which is unproven.
    // UNRESOLVED: Behavior when the two case variants collide (e.g. a non-alphabetic byte) is unspecified by the evidence.
    // UNRESOLVED: Byte vs. character semantics are identical here because the comparison is byte-wise on char-sized inputs.
}
