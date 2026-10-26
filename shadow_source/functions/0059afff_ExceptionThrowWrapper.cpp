// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AFFF
// Canonical corpus name: ExceptionThrowWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExceptionThrowWrapper_0059afff.c

void UnknownObject::ExceptionThrowWrapper()
{
    // C++ exception throw wrapper for std::out_of_range. Constructs the exception object with a vtable via ObjectInitWithVTable_b038, invokes the throw path CxxThrowException8 with the out_of_range type-info global __TI3?AVout_of_range@std@@ over a stack buffer, then runs the SEH unwind cleanup ExceptionObjectDestructorWithSEH. If the allocation flag bit in the stack buffer is set, frees the heap-allocated object via FreeWrapper_7bcf, then returns the object pointer.
    // CALL: Construct the exception object by calling ObjectInitWithVTable_b038 on the this pointer, establishing the vtable before the throw. [callee:0x0059B038, source:raw]
    // CALL: Invoke the C++ throw path CxxThrowException8 with the stack buffer and the std::out_of_range type-info global __TI3?AVout_of_range@std@@. [callee:0x0059BFC3, global:0x005BB9B8, source:raw]
    // CALL: Run the SEH unwind cleanup path ExceptionObjectDestructorWithSEH over the saved registers frame. [callee:0x0059AFC2, source:raw]
    // GUARD: Test the allocation flag bit of the stack buffer via (v5[4] & 1); when set, heap memory was allocated and must be freed. [source:raw]
    // CALL: Conditionally free the heap-allocated object via FreeWrapper_7bcf when the allocation flag bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the exception object pointer. [function:0x0059AFFF, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_59AFFF(void* this) {
    //     ObjectInitWithVTable_b038(this);
    //     CxxThrowException8(buffer, &__TI3?AVout_of_range@std@@);
    //     ExceptionObjectDestructorWithSEH(&savedregs);
    //     if ((buffer[4] & 1) != 0)
    //       FreeWrapper_7bcf(object_ptr);
    //     return object_ptr;
    //   }
    // UNRESOLVED: The decompiler carries v3 = v2 where v2 is not demonstrably initialized before the throw; the exact identity of the returned pointer is uncertain.
    // UNRESOLVED: The purpose of the unused second parameter a2 is unknown.
    // UNRESOLVED: The stack buffer v5 doubles as throw-object storage and allocation-flag storage; its exact layout is unresolved.
}
