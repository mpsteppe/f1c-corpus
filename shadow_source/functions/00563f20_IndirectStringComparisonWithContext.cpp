// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563F20
// Canonical corpus name: sub_563F20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_563F20_00563f20.c

void UnknownObject::IndirectStringComparisonWithContext()
{
    // Comparison helper that compares two indirect __int16 string pointers against a shared reference string stored in the global context pointer (dword_8D46B4 + 128) using StringComparisonWithConstantDispatch, then subtracts the two per-string results to produce an ordering result. When the sort-direction flag at (dword_8D46B4 + 132) is zero the result is negated, giving reverse sort order.
    // ASSIGNMENT: Dereference the first indirect string pointer: v2 = *a1, where the string pointer is read from the memory the caller's pointer addresses (this+0). [field:this:0x00000000, source:raw]
    // CALL: Compare the second indirect string *a2 against the context reference string at (dword_8D46B4 + 128): v3 = StringComparisonWithConstantDispatch(*a2, *(const char**)(dword_8D46B4 + 128), 0). [global:0x008D46B4, callee:0x00564530, source:raw]
    // CALL: Compare the first indirect string v2 against the same context reference string and subtract the second result: result = StringComparisonWithConstantDispatch(v2, *(const char**)(dword_8D46B4 + 128), 0) - v3. [global:0x008D46B4, callee:0x00564530, source:raw]
    // GUARD: When the direction flag at (dword_8D46B4 + 132) is zero, return the negated result (-result) for reverse sort order; otherwise fall through to the direct return. [global:0x008D46B4, source:raw]
    // RETURN: Return the computed difference: -result when the direction flag is zero, otherwise result as-is. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_563F20(const __int16** a1, const __int16** a2) {
    //     const __int16* v2 = *a1;
    //     int v3 = StringComparisonWithConstantDispatch(*a2, *(const char**)(ctx + 128), 0);
    //     int result = StringComparisonWithConstantDispatch(v2, *(const char**)(ctx + 128), 0) - v3;
    //     if (*(const DWORD*)(ctx + 132) == 0) result = -result;
    //     return result;
    //   }
    //   // ctx = dword_8D46B4 (global context pointer).
    // UNRESOLVED: Identity of dword_8D46B4 (existing analysis labels it NetworkContextPtr [DERIVED]); the +128 reference-string and +132 direction-flag semantics are not independently confirmed.
    // UNRESOLVED: Why both strings are compared against a shared reference string rather than directly against each other; the differencing implies an ordering relative to the reference.
    // UNRESOLVED: Callers are not recorded statically; the function is top-level or reached indirectly, so the calling sort context is unknown.
}
