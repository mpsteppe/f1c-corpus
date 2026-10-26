// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551F10
// Canonical corpus name: ObjectCreationWithRollbackOnFailure
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectCreationWithRollbackOnFailure_00551f10.c

void UnknownObject::ObjectCreationWithRollbackOnFailure()
{
    // Allocates and initializes a 20-byte structure via wrapper allocator and initializer, stores the pointer through the out-parameter, then performs a further setup call. On any failure of that call, rolls back by destroying and freeing the allocated object, nulling the out-parameter, and returning -1.
    // GUARD: If out_object_ptr is null, return -1 immediately. [field:this:0x00000000, source:raw]
    // CALL: Allocate 20 bytes through the malloc wrapper. [callee:0x00587C03, source:raw]
    // CALL: Initialize the freshly allocated structure with default scale; otherwise result stays null. [callee:0x00551A30, source:raw]
    // ASSIGNMENT: Store the created object pointer into the out-parameter. [field:this:0x00000000, source:raw]
    // CALL: Perform the object setup with the remaining arguments, capturing the result. [callee:0x00551A50, source:raw]
    // GUARD: On non-zero setup result, roll back the created object. [field:this:0x00000000, source:raw]
    // CALL: Invoke the empty stub cleanup on the created object if it exists. [callee:0x00557470, source:raw]
    // CALL: Free the object through the free wrapper. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the out-parameter after rollback. [field:this:0x00000000, source:raw]
    // RETURN: Return -1 on setup failure, otherwise propagate the setup result. [source:raw]

    // Conservative worker pseudocode:
    //   if (out_object_ptr == 0) return -1;
    //   obj = OperatorNewNhMallocWrapper(20);
    //   obj = obj ? StructInitWithDefaultScale(obj) : 0;
    //   *out_object_ptr = obj;
    //   result = sub_551A50(obj, name_or_identifier, creation_flag, resource_id);
    //   if (result) {
    //       if (*out_object_ptr) { EmptyStub_7470(*out_object_ptr); FreeWrapper_7bcf(*out_object_ptr); }
    //       *out_object_ptr = 0;
    //       return -1;
    //   }
    //   return result;
    // UNRESOLVED: The exact role of the a2/a3/a4 arguments in the setup call at 0x00551A50 is not evident from this function alone.
}
