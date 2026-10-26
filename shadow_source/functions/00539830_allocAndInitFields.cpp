// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00539830
// Canonical corpus name: ObjectAllocFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectAllocFieldInit_00539830.c

void UnknownObject::allocAndInitFields()
{
    // Allocates a small object through an indirect allocator function pointer on a5 (entry +32, taking the object payload pointer at a5+40 and arguments 1 and 26), then, if the allocation succeeded, initializes the new object's header fields: zeroes the first dword, stores byte a1 at +16, byte a2 at +17, dword a3 at +18, and dword a4 at +22. Returns the allocated object pointer.
    // CALL: Invoke the allocator through the function pointer at a5+32, passing the object pointer stored at a5+40 and the integer arguments 1 and 26; capture the returned pointer. [source:raw]
    // GUARD: If the allocation returned a non-null pointer, proceed to initialize the object's fields. [source:raw]
    // ASSIGNMENT: Zero the first dword of the allocated object (offset +0). [source:raw]
    // ASSIGNMENT: Store byte parameter a1 at object offset +16. [source:raw]
    // ASSIGNMENT: Store byte parameter a2 at object offset +17. [source:raw]
    // ASSIGNMENT: Store dword parameter a3 at object offset +18. [source:raw]
    // ASSIGNMENT: Store dword parameter a4 at object offset +22. [source:raw]
    // RETURN: Return the allocated object pointer (null when allocation failed). [source:raw]

    // Conservative worker pseudocode:
    //   obj = a5->allocator(a5->payload, 1, 26);
    //   if (obj) { obj->flags = 0; obj->field16 = a1; obj->field17 = a2; obj->field18 = a3; obj->field22 = a4; }
    //   return obj;
    // UNRESOLVED: Allocator ABI not established: a5+32 is an indirect function pointer; arguments 1 and 26 are most plausibly element count and element size but this is unproven.
    // UNRESOLVED: Field semantics of offsets +16/+17 (bytes) and +18/+22 (dwords) within the allocated object are unknown.
    // UNRESOLVED: Object type and the relationship to caller sub_537110 are not determined.
}
