// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004119D0
// Canonical corpus name: ShortComputation_19d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_19d0_004119d0.c

void UnknownObject::ClassifyInputRange()
{
    // Pure integer range classifier over the single __stdcall argument a1. Returns 0 when a1 lies in (0, 291), returns 1 when a1 lies in (292, 536), and otherwise returns the default -1. The two accepted intervals are disjoint, so boundary values a1 == 291, a1 == 292 and every a1 >= 536 fall through to -1. Invoked by FontRenderingPrep (00411840), suggesting the ranges classify some font or text parameter, though the semantic meaning of the three outputs is not evidenced here.
    // ASSIGNMENT: Initialize the default result to -1 before the range checks. [source:raw]
    // GUARD: When a1 > 0 and a1 < 291, return 0. [source:raw]
    // GUARD: When a1 > 292 and a1 < 536, return 1. [source:raw]
    // RETURN: Return the default -1 when neither range matches. [function:0x004119D0, source:raw]
    // CALL: Invoked by FontRenderingPrep (00411840) during font-rendering preparation. [caller:0x00411840, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4119D0(int a1) {
    //     if (a1 > 0 && a1 < 291) return 0;
    //     if (a1 > 292 && a1 < 536) return 1;
    //     return -1;
    //   }
    // UNRESOLVED: The semantic meaning of the three outputs (and of the two integer ranges, e.g. font size or character-code categories) is not evidenced; only the integer boundaries are certain.
    // UNRESOLVED: The -1 fallback for a1 == 291, a1 == 292 and a1 >= 536 is intentional per the guard conditions, but the caller's expectation for those inputs is unknown.
}
