// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005352B0
// Canonical corpus name: StringLengthDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringLengthDispatch_005352b0.c

void UnknownObject::StringLengthDispatch()
{
    // String-aware dispatch helper. It measures the length of the input string a2 with strlen and forwards the destination a1, the string pointer and that length to BufferFillWithTimeout (0x00535220), returning whatever it returns. Called by ResourceLookupWithDualPath (0x00566CF0).
    // CALCULATION: Compute the byte length of the NUL-terminated string a2 via strlen. [source:raw]
    // CALL: Call BufferFillWithTimeout(a1, (int)a2, strlen(a2)) to fill the destination buffer described by a1 with the string content up to its measured length. [callee:0x00535220, source:raw]
    // RETURN: Return the result produced by BufferFillWithTimeout. [source:raw]

    // Conservative worker pseudocode:
    //   int StringLengthDispatch(int a1, const char *a2) {
    //     return BufferFillWithTimeout(a1, (int)a2, strlen(a2));
    //   }
    // UNRESOLVED: The meaning of a1 (buffer handle vs pointer) and the exact success/failure return semantics are defined by BufferFillWithTimeout, which is not resolved here.
    // UNRESOLVED: Only the string-length form of the call is recovered; the purpose of the length argument inside BufferFillWithTimeout is unknown.
}
