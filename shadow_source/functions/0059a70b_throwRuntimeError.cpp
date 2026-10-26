// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A70B
// Canonical corpus name: CThrowWithException
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CThrowWithException_0059a70b.c

void UnknownObject::throwRuntimeError()
{
    // MSVC exception-throw helper for std::runtime_error. Constructs the exception object with ExceptionObjectConstructor, then raises a C++ exception with CxxThrowException8 using a local 28-byte throw-parameter frame and the std::runtime_error type-info global at 0x005BB6D8 as the throw descriptor. The nominal trailing call to ExceptionCleanupWithDestructorCall is the decompiler-emitted fallthrough after the noreturn throw.
    // CALL: Construct the exception object: call ExceptionObjectConstructor(this). [callee:0x0059A781]
    // CALL: Raise the C++ exception: call CxxThrowException8 with the local throw frame and the std::runtime_error type-info descriptor (global 0x005BB6D8). [callee:0x0059BFC3, global:0x005BB6D8]
    // RETURN: Fallthrough path after the throw returns the result of ExceptionCleanupWithDestructorCall; effectively unreachable if CxxThrowException8 never returns. [source:raw]

    // Conservative worker pseudocode:
    //   int throwRuntimeError(void *this) {
    //     char frame[28];
    //     ExceptionObjectConstructor(this);
    //     CxxThrowException8(frame, &__TI2?AVruntime_error@std@@);
    //     return ExceptionCleanupWithDestructorCall();
    //   }
    // UNRESOLVED: ExceptionCleanupWithDestructorCall appears in the raw source but has no callee evidence reference in the packet; its address and exact role are unverified.
    // UNRESOLVED: Layout and meaning of the 28-byte local throw-parameter frame are not recovered.
    // UNRESOLVED: The 0x005BB6D8 global is the std::runtime_error type-info descriptor per its IDA name; exact structure not validated.
}
