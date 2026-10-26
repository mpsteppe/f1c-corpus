// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D3F0
// Canonical corpus name: sub_48D3F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48D3F0_0048d3f0.c

void UnknownObject::DestructorWithConditionalFree()
{
    // Destructor (ABI-named Destructor_with_VTable_and_Conditional_Free) that restores the object's vtable pointer field this+0x0 to off_5AC1D0, runs shared teardown via sub_485EB0(this), then conditionally frees the object through FreeWrapper_7bcf(this) when bit 0 of the a2 flag is set. Returns the reconstructed pointer.
    // ASSIGNMENT: Restore the vtable pointer field this+0x0 to off_5AC1D0, consistent with the destructor ABI. [abi:lead, field:this:0x00000000, global:0x005AC1D0, source:raw]
    // CALL: Call sub_485EB0(this) to run shared object teardown/cleanup. [callee:0x00485EB0, source:raw]
    // GUARD: Guard on (a2 & 1) != 0 deciding whether the object memory is released; when the bit is clear the free is skipped. [source:raw]
    // CALL: When the guard passes, free the object via FreeWrapper_7bcf(this). [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the reconstructed object pointer). [function:0x0048D3F0, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_48D3F0(void* this, char a2) {
    //     *(void**)this = &off_5AC1D0;
    //     sub_485EB0(this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The concrete owner class is not evidenced; the restored vtable (off_5AC1D0) is a UIWidget vtable per prior analysis, but the exact object type is unknown.
    // UNRESOLVED: Parameter a2 acts as a free-on-delete flag (bit 0); its origin and full semantics depend on the caller's object-ownership convention.
    // UNRESOLVED: sub_485EB0 performs shared teardown, but the exact cleanup scope of that subroutine is not evidenced by this packet alone.
}
