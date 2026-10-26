// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004336D0
// Canonical corpus name: SafeStringCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SafeStringCopy_004336d0.c

void UnknownObject::SafeStringCopy()
{
    // Safe bounded string copy wrapper: calls sub_587DD0(a1, a2, a3) to copy at most a3 bytes from a2 into a1, forces a null terminator at a1 + a3, and returns the callee's result. Used by the AI settings file loader and the session config builder.
    // CALL: Call sub_587DD0(a1, a2, a3) and store its return value; the callee performs the bounded copy. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Null-terminate the destination: *(BYTE*)(a1 + a3) = 0. [source:raw]
    // RETURN: Return the result of sub_587DD0. [source:raw, function:0x004336D0]

    // Conservative worker pseudocode:
    //   int sub_4336D0(char* dst, const char* src, int max) {
    //     int r = sub_587DD0(dst, src, max);
    //     dst[max] = 0;
    //     return r;
    //   }
    // UNRESOLVED: Exact contract of sub_587DD0 (copy semantics, padding, and meaning of its return value) is unknown.
    // UNRESOLVED: Whether the null write at a1 + a3 stays in bounds depends on how sub_587DD0 interprets a3.
}
