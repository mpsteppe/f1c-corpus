// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051212E
// Canonical corpus name: ShortComputation_212e
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_212e_0051212e.c

void UnknownObject::ReadDwordFieldAt12()
{
    // Null-guarded field read: returns the 32-bit value at *(a2 + 12) when both arguments are non-null, otherwise 0. The first argument (a1) is only tested for non-null and is otherwise unused. In the caller InitializeMediaSurfaceFromStream (0x0050210E) the returned value is stored as the row stride of a media-surface context.
    // GUARD: Both-arguments guard: when a1 or a2 is null the function returns 0 immediately without dereferencing a2. [source:raw, function:0x0051212E]
    // RETURN: Return the dword at *(a2 + 12) when both a1 and a2 are non-null; in the caller this value becomes the row stride written to the media-surface context (this[12]). [source:raw, abi:lead, caller:0x0050210E]

    // Conservative worker pseudocode:
    //   int sub_51212E(int a1, int a2) {
    //     if (a1 && a2)
    //       return *(int*)(a2 + 12);
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of the value at a2+12 (interpreted by the caller as a row stride) is not independently confirmed by this function's own evidence.
    // UNRESOLVED: The role of a1 is unknown: it must be non-null for the read to happen but is never otherwise used.
}
