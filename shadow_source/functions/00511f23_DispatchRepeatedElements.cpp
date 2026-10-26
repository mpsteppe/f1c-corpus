// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511F23
// Canonical corpus name: sub_511F23
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_511F23_00511f23.c

void UnknownObject::DispatchRepeatedElements()
{
    // Repeated element dispatch: queries the number of iterations via FlagBasedSessionModeSelector, copies the element count from this+0xBC into this+0xC0, and when the selector returns a positive count runs a nested loop — the outer loop iterating the selector count times and the inner loop iterating the element count times, calling sub_511B7C on each element of the a2 pointer array (dereferencing and advancing the pointer each iteration) with a 0 argument. Returns the value produced by the last sub_511B7C call when the loops run, otherwise the selector result.
    // CALL: Call FlagBasedSessionModeSelector(a1) to obtain the number of session-mode iterations; the result is kept as the loop bound [callee:0x0051234D, source:raw]
    // ASSIGNMENT: Read the element count dword at this+0xBC into v4 and store a copy of it at this+0xC0 [field:this:0x000000BC, field:this:0x000000C0, source:raw]
    // GUARD: Guard: the nested dispatch loops only run when the FlagBasedSessionModeSelector result is greater than zero [callee:0x0051234D, source:raw]
    // LOOP: Nested loop: the outer loop repeats the selector-count times, resetting v5 to a2 each pass; the inner loop runs the element count v4 times, calling sub_511B7C(a1, *v5++, 0) so each iteration dereferences the next array element and advances the pointer [callee:0x00511B7C, field:this:0x000000BC, source:raw]
    // RETURN: Return the value produced by the last sub_511B7C call, or the FlagBasedSessionModeSelector result when the loops do not run; called from sub_50210E (0x0050210E) [callee:0x00511B7C, callee:0x0051234D, caller:0x0050210E, function:0x00511F23, source:raw]

    // Conservative worker pseudocode:
    //   char* DispatchRepeatedElements(int a1, int* a2) {
    //     char* result = (char*)FlagBasedSessionModeSelector(a1);
    //     int v4 = *(int*)(a1 + 0xBC);
    //     *(int*)(a1 + 0xC0) = v4;
    //     if ((int)result > 0) {
    //       char* v6 = result;
    //       do {
    //         int* v5 = a2;
    //         if (v4) {
    //           int v7 = v4;
    //           do {
    //             result = (char*)sub_511B7C(a1, *v5++, 0);
    //           } while (--v7);
    //         }
    //       } while (--v6);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The LEGACY ABI lead 'Repeated_Element_Dispatch' names this exact function (abi address equals 0x00511F23) but its source contract is unknown; used only as a naming hint.
    // UNRESOLVED: The semantics of the a2 array elements and what sub_511B7C performs on each are not recoverable from this function alone.
    // UNRESOLVED: The downstream consumer of the count copy stored at this+0xC0 is not established.
}
