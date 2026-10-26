// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591C79
// Canonical corpus name: SetErrorCodeBasedOnInputRange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetErrorCodeBasedOnInputRange_00591c79.c

void UnknownObject::SetErrorCodeBasedOnInputRange()
{
    // Maps an input integer to a TLS error code: input 1 writes 33 into the TLS slot, inputs 2..3 write 34, and all other values leave the TLS slot untouched. Returns the TLS slot address when a code was written, otherwise returns the input cast to a pointer. Frame-path function; the TLS slot is written every call on the guarded paths.
    // ASSIGNMENT: result = a1 cast to pointer: default return value when no error code is written. [source:raw]
    // GUARD: First branch: if a1 == 1, take the error-code-33 path. [source:raw]
    // CALL: result = TLSOffsetGetter(): retrieve the TLS slot address that will hold the error code. [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: *result = 33: write error code 33 into the TLS slot at offset 0 of the returned pointer. [field:this:0x00000000, source:raw]
    // GUARD: Second branch: else if a1 > 1 && a1 <= 3, take the error-code-34 path. [source:raw]
    // CALL: result = TLSOffsetGetter(): retrieve the TLS slot address for the error-code-34 write. [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: *result = 34: write error code 34 into the TLS slot at offset 0 of the returned pointer. [field:this:0x00000000, source:raw]
    // RETURN: Return the TLS slot address when an error code was written, otherwise return the original a1 cast as pointer. [function:0x00591C79, source:raw]
    // CALL: Invoked by ConditionalMathWithDAT005e9ad0Flag (0059168F), FloatParsingWithErrorHandling (00591BF1) and sub_596175 (00596175) to set parse/range error codes on the frame path. [caller:0x0059168F, caller:0x00591BF1, caller:0x00596175, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *SetErrorCodeBasedOnInputRange(int a1) {
    //     _DWORD *result = (_DWORD *)a1;
    //     if (a1 == 1) {
    //       result = (_DWORD *)TLSOffsetGetter();
    //       *result = 33;
    //     } else if (a1 > 1 && a1 <= 3) {
    //       result = (_DWORD *)TLSOffsetGetter();
    //       *result = 34;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of error codes 33 and 34 and which component consumes the TLS slot is not established here.
    // UNRESOLVED: The TLS slot write is recalcuated per frame, so external pokes to offset 0 do not persist.
}
