// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B050
// Canonical corpus name: CRTStrrchr
// Owner: CRuntimeLibrary [DERIVED]
// Raw source: functions/CRTStrrchr_0058b050.c

void CRuntimeLibrary::strrchr()
{
    // C standard-library strrchr implementation: scans a1 backward from its final NUL and returns a pointer to the last byte equal to a2, or 0 when no match exists. The ABI lead names this CRT__strrchr and the behavior matches the CRT contract exactly.
    // CALCULATION: Compute backward scan length v2 = strlen(a1) + 1 and place v3 at the last character a1[v2 - 1]. [source:raw]
    // LOOP: do-while loop scanning from the string end toward the start, comparing each byte *v3 with a2 until a match is found or the start is reached. [source:raw]
    // GUARD: If v2 reaches zero the loop breaks, meaning the whole string was scanned without a match. [source:raw]
    // ASSIGNMENT: v5 = v3 + 1, one byte past the last compared position; this is the candidate match location. [source:raw]
    // GUARD: Confirm the match: if *v5 == a2 the byte was found, otherwise the scan ended at the string start. [source:raw]
    // RETURN: Return v5 (pointer to the last occurrence of a2) on match, otherwise return 0. [source:raw, function:0x0058B050, abi:lead]

    // Conservative worker pseudocode:
    //   BYTE* strrchr(const char* s, BYTE c) {
    //     unsigned int n = strlen(s) + 1;
    //     const char* p = &s[n - 1];
    //     do {
    //       if (!n) break;
    //       if (*p-- == c) { p++; return (BYTE*)p; }
    //       --n;
    //     } while (1);
    //     return 0;
    //   }
    // UNRESOLVED: Callers are texture path parsing (0x00552F20) and 0x00560230; no per-caller contract is evidenced here.
    // UNRESOLVED: Owner as CRuntimeLibrary is DERIVED from the ABI lead only; no other source confirms a CRT build.
}
