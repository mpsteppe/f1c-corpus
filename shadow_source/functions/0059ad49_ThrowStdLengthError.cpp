// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AD49
// Canonical corpus name: sub_59AD49
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59AD49_0059ad49.c

void UnknownObject::ThrowStdLengthError()
{
    // STL exception-construction path that throws a std::length_error with message 'string too long'. Installs the SEH frame, builds the message buffer at a1-32 (copy from a1-13, reference release, then write 'string too long' with null terminator), zeroes a1-4, constructs the logic_error base via CExceptionInitHandler_ada3, points a1-60 at the std::length_error vftable, and throws via CxxThrowException8 with the length_error type info. The tail call to CExceptionInitHandler_ada3(a2) is unreachable after the throw.
    // CALL: SEHHandlerInit() installs the SEH handler frame whose continuation/landing pad is loc_59D54C. [callee:0x0058A5D8, global:0x0059D54C, source:raw]
    // ASSIGNMENT: Copy the byte at (a1 - 13) into the exception message buffer slot at (a1 - 32). [source:raw]
    // CALL: ReferenceCountDecrementWithConditionalFree((a1 - 32), 0) releases the previous string-buffer reference before the new message is written. [callee:0x005993AF, source:raw]
    // CALL: Strlen('string too long') computes the message length from the aStringTooLong literal. [callee:0x0058E1B0, global:0x005B9D68, source:raw]
    // CALL: BufferWriteWithNullTerminate((a1 - 32), 'string too long', length) copies the message with a null terminator into the exception buffer. [callee:0x00599615, global:0x005B9D68, source:raw]
    // ASSIGNMENT: Zero the dword at (a1 - 4), part of the exception object/header slot. [source:raw]
    // CALL: CExceptionInitHandler_ada3(a1 - 32) constructs the logic_error base subobject of the exception. [callee:0x0059ADA3, source:raw]
    // ASSIGNMENT: Point the vtable slot at (a1 - 60) at the std::length_error vftable (??_7length_error@std@@6B@). [global:0x005B9D5C, source:raw]
    // CALL: CxxThrowException8(a1 - 60, &length_error type_info) raises the exception using the __TI3?AVlength_error@std@@ RTTI descriptor; this never returns normally. [callee:0x0059BFC3, global:0x005BB890, source:raw]
    // RETURN: Unreachable tail after the throw: return CExceptionInitHandler_ada3(a2), a leftover EH cleanup/dispose path on the second argument. [callee:0x0059ADA3, source:raw]

    // Conservative worker pseudocode:
    //   void sub_59AD49(void* frame, void* a2) {
    //     SEHHandlerInit();
    //     *(byte*)(frame - 32) = *(byte*)(frame - 13);
    //     ReferenceCountDecrementWithConditionalFree(frame - 32, 0);
    //     BufferWriteWithNullTerminate(frame - 32, "string too long", Strlen("string too long"));
    //     *(dword*)(frame - 4) = 0;
    //     CExceptionInitHandler_ada3(frame - 32);
    //     *(dword*)(frame - 60) = &std::length_error::vftable;
    //     CxxThrowException8(frame - 60, &_TI3_AVlength_error_std__);
    //     return CExceptionInitHandler_ada3(a2); /* unreachable * /
    //   }
    // UNRESOLVED: The throwing site's frame layout (a1-13, a1-32, a1-4, a1-60) and the role of the second argument a2 are specific to the caller's exception-buffer convention.
    // UNRESOLVED: Ownership: this is a std::length_error construction helper but the owning class or STL wrapper is unidentified.
    // UNRESOLVED: The unreachable tail return indicates compiler-generated EH scaffolding, not an intentional second path.
}
