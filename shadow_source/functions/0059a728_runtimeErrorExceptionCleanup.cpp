// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A728
// Canonical corpus name: ExceptionCleanupWithDestructorCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExceptionCleanupWithDestructorCall_0059a728.c

void UnknownObject::runtimeErrorExceptionCleanup()
{
    // Exception-object cleanup routine for a std::runtime_error-derived object. Registers the SEH frame for this scope, stashes the exception object pointer (ecx) into the frame slot at a1-16, resets the object's vtable to the std::runtime_error vtable, clears the frame slot at a1-4, decrements the reference count of the embedded sub-object at v1+3 with a free flag of 1 via ReferenceCountDecrementWithConditionalFree, sets the frame slot at a1-4 back to -1, and finally delegates to MSVCExceptionDestructor for the exception object teardown.
    // CALL: SEHHandlerInit registers the SEH exception handler for this frame; the registered handler address is loc_59D48C. [callee:0x0058A5D8, global:0x0059D48C, function:0x0059A728, source:raw]
    // ASSIGNMENT: Store the exception object pointer v1 into the frame slot at a1-16. [function:0x0059A728, source:raw]
    // ASSIGNMENT: Reset the object's vtable to the std::runtime_error vftable (??_7runtime_error@std@@6B@). [global:0x005B9D28, source:raw]
    // ASSIGNMENT: Clear the frame slot at a1-4 to 0. [source:raw]
    // CALL: ReferenceCountDecrementWithConditionalFree(v1 + 3, 1) decrements the reference count of the embedded sub-object at (v1 + 3) with conditional-free flag 1. [callee:0x005993AF, source:raw]
    // ASSIGNMENT: Set the frame slot at a1-4 back to -1. [source:raw]
    // CALL: MSVCExceptionDestructor(v2) finalizes the exception object cleanup. [callee:0x0059BFA0, function:0x0059A728, source:raw]
    // RETURN: Return the result of MSVCExceptionDestructor. [callee:0x0059BFA0, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   v2 = v1;
    //   *(a1 - 16) = v1;
    //   *v1 = &std::runtime_error::vftable;
    //   *(a1 - 4) = 0;
    //   ReferenceCountDecrementWithConditionalFree(v1 + 3, 1);
    //   *(a1 - 4) = -1;
    //   return MSVCExceptionDestructor(v2);
    // UNRESOLVED: The embedded sub-object at (v1 + 3) is not declared as a packet field; its type and exact layout are unknown.
    // UNRESOLVED: The exact behavior of SEHHandlerInit (and the purpose of the registered loc_59D48C handler) is not evidenced within this packet.
}
