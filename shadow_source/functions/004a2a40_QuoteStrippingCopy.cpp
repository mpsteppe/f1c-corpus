// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A2A40
// Canonical corpus name: QuoteStrippingCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuoteStrippingCopy_004a2a40.c

void UnknownObject::QuoteStrippingCopy()
{
    // Copies the source string a1 into the output buffer lpSrcStr, stripping every double-quote character (0x22 = 34), then null-terminates the result and returns the outcome of sub_589901(lpSrcStr). The write index v2 only advances for copied characters, so the output is the quote-free, compacted string.
    // ASSIGNMENT: Initialize the output write index v2 to 0. [source:raw]
    // LOOP: Iterate over source characters i from 0 to strlen(a1) - 1. [source:raw]
    // GUARD: Skip the current character when it equals the double-quote literal 34 (0x22); it is not copied. [source:raw]
    // ASSIGNMENT: Copy each non-quote source character into lpSrcStr at the advancing index v2. [source:raw]
    // ASSIGNMENT: Null-terminate the copied output: lpSrcStr[v2] = 0. [source:raw]
    // CALL: Call sub_589901(lpSrcStr) with the stripped string and propagate its return value. [callee:0x00589901, source:raw]
    // RETURN: Return the result of sub_589901(lpSrcStr). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A2A40(const char *src, char *dst) {
    //     int n = 0;
    //     for (int i = 0; i < (int)strlen(src); ++i) {
    //       char c = src[i];
    //       if (c != '"') dst[n++] = c;
    //     }
    //     dst[n] = 0;
    //     return sub_589901(dst);
    //   }
    // UNRESOLVED: Purpose of sub_589901 (result likely consumed by the PitCrewAnimationLoader caller).
    // UNRESOLVED: The prototype names the destination LPCSTR but it is written to, so the true type is a mutable char buffer.
}
