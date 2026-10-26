// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005502C0
// Canonical corpus name: DestructorWithConditionalFreeFlagClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFreeFlagClear_005502c0.c

void UnknownObject::ConditionalFreeThenFlagClear()
{
    // Release/destructor method. When the sub-object pointer at this+0x54 is non-null, it runs the sub-object cleanup sub_542E50, then (if the pointer is still non-null) calls the sentinel EmptyStub_7470 and frees the sub-object via FreeWrapper_7bcf, and finally zeroes this+0x54. Regardless of the pointer state, the free/destroy flag at this+0x4 is cleared to 0. Always returns 0.
    // ASSIGNMENT: Load the sub-object pointer v2 = *(int*)(this + 0x54). [field:this:0x00000054, source:raw]
    // GUARD: If the sub-object pointer at this+0x54 is non-null, enter the cleanup-and-free block. [field:this:0x00000054, source:raw]
    // CALL: Run the sub-object cleanup/destructor sub_542E50(v2). [callee:0x00542E50, source:raw]
    // GUARD: Reload v3 = *(int*)(this + 0x54); if it is still non-null, run the stub and free. [field:this:0x00000054, source:raw]
    // CALL: Call EmptyStub_7470(*(int*)(this + 0x54)) as a sentinel before deallocation, then FreeWrapper_7bcf(v3) to release the sub-object memory. [callee:0x00557470, callee:0x00587BCF, field:this:0x00000054, source:raw]
    // ASSIGNMENT: Zero the sub-object pointer this+0x54 after freeing it. [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Clear the free/destroy flag: *(byte*)(this + 0x4) = 0, unconditionally. [field:this:0x00000004, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (this->subobject != NULL) {
    //     sub_542E50(this->subobject);
    //     if (this->subobject != NULL) {
    //       EmptyStub_7470(this->subobject);
    //       FreeWrapper_7bcf(this->subobject);
    //     }
    //     this->subobject = NULL;
    //   }
    //   this->free_flag = 0;
    //   return 0;
    // UNRESOLVED: The sub-object at this+0x54 has no concrete type evidence in the packet; sub_542E50 is a cleanup/destructor and FreeWrapper_7bcf a deallocator by name only.
    // UNRESOLVED: The purpose of the EmptyStub_7470 sentinel call between cleanup and free is unknown.
}
