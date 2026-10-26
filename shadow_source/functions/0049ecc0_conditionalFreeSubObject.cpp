// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ECC0
// Canonical corpus name: ConditionalFreeSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeSubCall_0049ecc0.c

void UnknownObject::conditionalFreeSubObject()
{
    // Conditionally destroys and frees a sub-object stored at this+0xC. When that pointer is non-null the destructor is called (which also clears the associated free-guard flag), the pointer is passed through an empty helper stub and then to the heap-free wrapper, and the stored pointer is nulled. The owning object and the sub-object type are not identified by the packet; the callers are multi-stage cleanup helpers.
    // GUARD: Guard on the stored sub-object pointer this[3]: a non-null value passes into the destructor/free sequence; a zero value skips the entire body and returns the uninitialized result. [field:this:0x0000000C, source:raw]
    // CALL: Calls the destructor DestructorWithConditionalFreeFlagClear() on the non-null sub-object; the callee runs the destructor and clears the associated free-guard flag. Its return value is stored into result. [callee:0x005502C0, field:this:0x0000000C, source:raw]
    // CALL: Calls the empty stub EmptyStub_7470 with this[3] as its argument just before the free; the stub has no visible body, so its real purpose (placeholder or virtual-dispatch slot) is unverified. [callee:0x00557470, field:this:0x0000000C, source:raw]
    // CALL: Calls the heap free wrapper FreeWrapper_7bcf with the re-read sub-object pointer v3, releasing the heap block held by the sub-object. [callee:0x00587BCF, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Nulls the stored pointer this[3] after the destructor/free sequence so the parent object no longer references the freed sub-object. [field:this:0x0000000C, source:raw]
    // RETURN: Returns the result value, which on the non-null path holds the destructor/free wrapper result. [function:0x0049ECC0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[3]) {
    //     result = DestructorWithConditionalFreeFlagClear();
    //     void* p = this[3];
    //     if (p) { EmptyStub_7470(this[3]); result = FreeWrapper_7bcf(p); }
    //     this[3] = 0;
    //   }
    //   return result;
    // UNRESOLVED: EmptyStub_7470 has no visible body in the packet; treating it as a placeholder/virtual-dispatch slot is a DERIVED label, not evidenced.
    // UNRESOLVED: The object type owning the this+0xC slot and the sub-object type are unknown; the existing_analysis caller MultiStageCleanupWithRepeatedCallCycle (0049d150) is consistent with cleanup but does not identify the parent class.
}
