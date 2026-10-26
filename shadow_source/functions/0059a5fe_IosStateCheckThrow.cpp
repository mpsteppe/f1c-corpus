// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A5FE
// Canonical corpus name: sub_59A5FE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A5FE_0059a5fe.c

void UnknownObject::IosStateCheckThrow()
{
    // Checks iostream state bits for the current stream frame and throws a std::ios_base::failure exception when error bits are set. Masks the state dword at this+0x8 with 7 to isolate eofbit/failbit/badbit, and combines it with a stored mask. If the combined bits are non-zero, first throws immediately via CxxThrowException8 when this+0xC is set, otherwise builds the error message by selecting among the badbit/failbit/eofbit string literals, copies this+0xF into an exception-context byte, decrements its reference count, writes the message into the context buffer via BufferWriteWithNullTerminate, installs the SEH handler with CExceptionInitHandler, sets the ios_base::failure vftable, and throws the constructed exception with its typeinfo. Returns the masked state (0 when no error bits are set).
    // CALL: SEHHandlerInit registers the exception handler at loc_59D464 for this frame. [callee:0x0058A5D8, global:0x0059D464]
    // CALCULATION: Reads the stream state dword at this+0x8 and masks it with 7 to isolate the eof/fail/bad bits. [field:this:0x00000008]
    // GUARD: Combines the masked state with the stored mask dword; when the combined bits are non-zero the error/exception path is taken. [field:this:0x00000008]
    // GUARD: When the byte at this+0xC is non-zero, throws immediately with CxxThrowException8(0, 0) without constructing a message. [field:this:0x0000000C, callee:0x0059BFC3]
    // ASSIGNMENT: Selects the error message literal: badbit (bit 4) uses aIosBadbitSet, otherwise failbit (bit 2) uses aIosFailbitSet, and when neither bit is set uses aIosEofbitSet. [global:0x005B9D14, global:0x005B9D00, global:0x005B9CF0]
    // CALL: Copies the byte at this+0xF into the exception-context byte and calls ReferenceCountDecrementWithConditionalFree on the context pointer. [field:this:0x0000000F, callee:0x005993AF]
    // CALL: Computes the message length with Strlen and writes the message into the context buffer with BufferWriteWithNullTerminate. [callee:0x0058E1B0, callee:0x00599615]
    // CALL: Sets the frame cleanup state, calls CExceptionInitHandler on the context, stores the std::ios_base::failure vftable pointer into the throw argument block, and throws via CxxThrowException8 with the ios_base::failure typeinfo (__TI3?AVfailure@ios_base@std@@). [callee:0x0059A69A, callee:0x0059BFC3, global:0x005B9CE4, global:0x005BB668]
    // RETURN: Returns the masked state value (0 when no error bits were set and no exception was thrown). [source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   state = *(dword*)(a1 + 8) & 7;
    //   combined = state & *(dword*)(v4 + 8);
    //   if (combined) {
    //       if (*(byte*)(a1 + 12)) CxxThrowException8(0, 0);
    //       if (combined & 4) msg = aIosBadbitSet;
    //       else { msg = aIosFailbitSet; if ((combined & 2) == 0) msg = aIosEofbitSet; }
    //       *(byte*)(a1 - 28) = *(byte*)(a1 + 15);
    //       ReferenceCountDecrementWithConditionalFree(a1 - 28, 0);
    //       BufferWriteWithNullTerminate(a1 - 28, msg, Strlen(msg));
    //       CExceptionInitHandler(a1 - 28);
    //       *(dword*)(a1 - 56) = &ios_base::failure::vftable;
    //       CxxThrowException8(a1 - 56, &_TI3_AVfailure_ios_base_std__);
    //   }
    //   return state;
    // UNRESOLVED: Register v4 is used before initialization in the Hex-Rays output (SEH frame base); the concrete target of the masked-state write is not grounded.
    // UNRESOLVED: The exception object layout (context at a1-28, throw argument block at a1-56) is compiler SEH-generated and not semantically resolved.
    // UNRESOLVED: The stored mask dword that the state is combined against is not visible in the decompiled text.
}
