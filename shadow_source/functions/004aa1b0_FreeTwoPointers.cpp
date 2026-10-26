// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004AA1B0
// Canonical corpus name: FreeTwoPointers
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FreeTwoPointers_004aa1b0.c

void UnknownObject::FreeTwoPointers()
{
    // __thiscall helper that conditionally frees two heap pointers stored in the object: reads the pointer at this+0xC, frees it via FreeWrapper_7bcf when non-null; then reads the pointer at this+0x4 and frees it when non-null, returning its free result, or the first free result when the second pointer is null. Called by StaticInitBulk; structural twin of DualConditionalFree (0049a5a0) per cluster prelabel.
    // ASSIGNMENT: result = *(int*)(this + 0xC), load first stored pointer. [field:this:0x0000000C, source:raw]
    // GUARD: if result != 0, proceed to free the pointer at this+0xC. [field:this:0x0000000C, source:raw]
    // CALL: FreeWrapper_7bcf(*(LPVOID*)(this + 0xC)) frees the first pointer, result stored back to result. [callee:0x00587BCF, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: v3 = *(void**)(this + 0x4), load second stored pointer. [field:this:0x00000004, source:raw]
    // GUARD: if v3 != 0, free the pointer at this+0x4 and return its result. [field:this:0x00000004, source:raw]
    // CALL: FreeWrapper_7bcf(v3) frees the second pointer. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // RETURN: return result (first free's result) when the second pointer was null; otherwise return the second free's result. [function:0x004AA1B0, source:raw]

    // Conservative worker pseudocode:
    //   int FreeTwoPointers(void* this) {
    //       int result = *(int*)(this + 0xC);
    //       if (result) result = FreeWrapper_7bcf(*(void**)(this + 0xC));
    //       void* v3 = *(void**)(this + 0x4);
    //       if (v3) return FreeWrapper_7bcf(v3);
    //       return result;
    //   }
    // UNRESOLVED: Class identity unknown; no owner evidence beyond the freed-pointer layout (this+0x4, this+0xC).
    // UNRESOLVED: Return semantics of FreeWrapper_7bcf unknown.
    // UNRESOLVED: Whether this is teardown, buffer replacement, or static-init cleanup is unclear despite the StaticInitBulk caller.
    // UNRESOLVED: Relationship to cluster twin DualConditionalFree (0049a5a0) not verified.
}
