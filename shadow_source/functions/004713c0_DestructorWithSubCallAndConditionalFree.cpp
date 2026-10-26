// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004713C0
// Canonical corpus name: DestructorWithSubCallAndConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithSubCallAndConditionalFree_004713c0.c

void UnknownObject::DestructorWithSubCallAndConditionalFree()
{
    // Scalar-deleting destructor pattern. Calls VTableInit on this (vtable teardown sub-call), then conditionally frees the object via FreeWrapper_7bcf when the low bit of the a2 deletion-flag argument is set, and returns this. The legacy ABI symbol names it Destructor_with_Sub_Call_and_Conditional_Free but carries no prototype.
    // CALL: VTableInit(this): invoke the vtable-teardown sub-call on the object [callee:0x0048C0D0, function:0x004713C0, source:raw]
    // GUARD: if ((a2 & 1) != 0): test the low bit of the deletion flag before freeing [function:0x004713C0, source:raw]
    // CALL: FreeWrapper_7bcf(this): free the object storage when the flag bit is set [callee:0x00587BCF, function:0x004713C0, source:raw]
    // RETURN: Return this; standard scalar-deleting destructor pattern [function:0x004713C0, source:raw]

    // Conservative worker pseudocode:
    //   void *DestructorWithSubCallAndConditionalFree(void *this, char a2) {
    //     VTableInit(this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class owning this destructor is unidentified (owner is UnknownObject)
    // UNRESOLVED: What VTableInit (0x0048C0D0) tears down inside the object is not detailed in this packet
    // UNRESOLVED: FreeWrapper_7bcf is shared by sibling destructors but its allocator semantics are not established here
    // UNRESOLVED: The meaning of deletion-flag bits above bit 0 is unused/unknown
}
