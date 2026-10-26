// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AF68
// Canonical corpus name: sub_59AF68
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59AF68_0059af68.c

void UnknownObject::ThrowOutOfRangeException()
{
    // Constructs and throws a std::out_of_range exception carrying the message "invalid string position". Registers an SEH handler frame, copies a one-byte buffer marker and releases the prior stack buffer reference, then writes the message with its length into the reused buffer. After initializing the exception object through the exception-init handler, it sets the out_of_range vtable and calls the C++ throw entry with the out_of_range type info. The trailing destructor call is the decoded SEH unwind epilogue, never reached because the throw does not return.
    // CALL: SEHHandlerInit registers the stack exception-handler frame for this function, linked to the landing pad global. [callee:0x0058A5D8, global:0x0059D5B0, source:raw]
    // ASSIGNMENT: Copy one byte from the caller frame slot into the buffer marker slot before reusing the buffer. [source:raw]
    // CALL: ReferenceCountDecrementWithConditionalFree releases the previous reference held by the stack buffer slot. [callee:0x005993AF, source:raw]
    // CALL: Compute the length of the message with Strlen, then BufferWriteWithNullTerminate copies "invalid string position" into the buffer including its terminator. [callee:0x0058E1B0, callee:0x00599615, global:0x005B9D98, source:raw]
    // ASSIGNMENT: Zero the exception object field used to track ownership before construction. [source:raw]
    // CALL: CExceptionInitHandler_ada3 constructs the exception object, building the logic_error base with the message. [callee:0x0059ADA3, source:raw]
    // ASSIGNMENT: Install the std::out_of_range vtable into the exception object. [global:0x005B9D8C, source:raw]
    // CALL: CxxThrowException8 raises the exception with the std::out_of_range type info, which never returns. [callee:0x0059BFC3, global:0x005BB9B8, source:raw]
    // RETURN: Trailing ExceptionObjectDestructorWithSEH is the decoded SEH unwind epilogue; unreachable after the non-returning throw. [source:raw]

    // Conservative worker pseudocode:
    //   void ThrowOutOfRange() {
    //     SEHHandlerInit();
    //     bufferMarker = callerByte;
    //     ReferenceCountDecrementWithConditionalFree(&bufferMarker, 0);
    //     const char* msg = "invalid string position";
    //     BufferWriteWithNullTerminate(&bufferMarker, msg, Strlen(msg));
    //     CExceptionInitHandler_ada3(&ex, &bufferMarker);
    //     ex.vftable = &std::out_of_range::`vftable';
    //     CxxThrowException8(&ex, &_TI3_AVout_of_range_std__);
    //   }
    // UNRESOLVED: The caller frame slots at a1-32/a1-13 are a small inlined buffer; their exact field layout is not recoverable from this function alone.
    // UNRESOLVED: ExceptionObjectDestructorWithSEH is the SEH epilogue rendered as a return value, not a genuine program-logic return.
    // UNRESOLVED: ReferenceCountDecrementWithConditionalFree operating on a stack byte slot suggests a small-buffer/string implementation detail whose type is unknown.
}
