// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A81B
// Canonical corpus name: CExceptionThrowWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CExceptionThrowWrapper_0059a81b.c

void UnknownObject::ThrowIosBaseFailure()
{
    // C++ exception-throw wrapper. Constructs an std::ios_base::failure exception object via sub_59A854, throws it through CxxThrowException8 with the ios_base::failure type-info global, then runs destructor cleanup with SEH vtable reset. If the ownership flag bit 0 of the stack buffer is set, the wrapped heap pointer is released through FreeWrapper_7bcf; the pointer is then returned.
    // CALL: sub_59A854 constructs the std::ios_base::failure exception object from the given context [callee:0x0059A854, source:raw]
    // CALL: CxxThrowException8 raises the exception using the stack buffer v5 and the ios_base::failure type-info global [callee:0x0059BFC3, global:0x005BB668, source:raw]
    // CALL: DestructorWithSEHVTableReset runs destructor cleanup with an SEH vtable reset anchored on savedregs [callee:0x0059A7DE, source:raw]
    // GUARD: If ownership flag bit 0 of stack buffer byte 4 (v5[4] & 1) is set, the wrapped heap pointer v3 is released [source:raw]
    // CALL: FreeWrapper_7bcf frees the heap-allocated buffer pointed to by v3 when the ownership flag is set [callee:0x00587BCF, source:raw]
    // RETURN: Return the (possibly freed) pointer v3 [function:0x0059A81B]

    // Conservative worker pseudocode:
    //   sub_59A854(this);
    //   CxxThrowException8(v5, &_TI3_AVfailure_ios_base_std__);
    //   v3 = v2;
    //   DestructorWithSEHVTableReset(&savedregs);
    //   if ((v5[4] & 1) != 0)
    //       FreeWrapper_7bcf(v3);
    //   return v3;
    // UNRESOLVED: The ownership flag semantics in stack buffer v5 (which allocation bit 0 tracks) are not documented in this packet
    // UNRESOLVED: The identity of the heap object behind v2/v3 and when it is legitimately freed versus leaked is not resolvable here
    // UNRESOLVED: The relationship between argument a2 and the exception message content is not visible from this function
}
