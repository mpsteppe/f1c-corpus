// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005934E1
// Canonical corpus name: sub_5934E1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5934E1_005934e1.c

void UnknownObject::CppExceptionHandlerCall()
{
    // MSVC C++ exception handler dispatch. Validates the exception record (ExceptionCode 0xE06D7363, NumberParameters 3, type-info magic 429065504 at this+0x14), unwinds a nested exception record from TLS when present (with a bad-pointer guard), validates the inline frame state a2 against the scope table bounds a5+4, then either dispatches through a fallback handler or binary-searches the scope table for the matching try-level range and dispatches to the matched catch handler by type comparison.
    // ASSIGNMENT: Nested-exception flag v15 is initialized to 0 (LOBYTE of the local). [source:raw]
    // CALCULATION: v16 = *(a2 + 8): the inline frame state (try-level/state) is read from the frame object a2. [source:raw]
    // GUARD: If v16 < -1 or v16 >= *(a5 + 4) the frame state is out of scope-table bounds and SEHGuardedFunctionPointerCall() is invoked. [callee:0x00593CFD, source:raw]
    // GUARD: If ExceptionRecord->ExceptionCode (this+0x0) differs from 0xE06D7363 the record is not a C++ exception and control jumps to the fallback path. [guard:0, field:this:0x00000000, source:raw]
    // GUARD: Nested-record detection: NumberParameters (this+0x10) equals 3, the type-info slot at this+0x14 holds 429065504 and ExceptionInformation[2] is 0. [guard:1, guard:2, field:this:0x00000010, field:this:0x00000014]
    // CALL: TLSValueRetrievalWithInit() fetches the TLS state used to locate the nested exception record and continuation context. [callee:0x0058E0C7]
    // GUARD: If TLS slot 27 of the returned state is zero there is no nested record and the function returns that TLS value early. [callee:0x0058E0C7, source:raw]
    // ASSIGNMENT: v8 = TLS slot 27 (nested exception record), a3 = TLS slot 28 (continuation context) and the nested flag v15 is set to 1. [callee:0x0058E0C7, source:raw]
    // CALL: IsBadReadPtrWrapper(v8, 1) validates the nested record pointer; on a bad pointer SEHGuardedFunctionPointerCall() is invoked instead of dereferencing it. [callee:0x00597321, callee:0x00593CFD]
    // GUARD: The nested record is validated like the primary record: ExceptionCode 0xE06D7363, NumberParameters equal to 3, type-info slot 429065504 and ExceptionInformation[2] zero. [guard:0, guard:2, field:this:0x00000010, field:this:0x00000014]
    // STATE_TRANSITION: On the fallback path: if a6 is set the record is dispatched via SEHWrapperDispatchingToHandlerFunction(ExceptionRecord, a2, a3); otherwise FontGlyphRender(v8, a2, a3, a4, a5, v16, a7, TargetFrame) acts as the fallback/catch-all handler. [callee:0x00593BBD, callee:0x00593694, source:raw]
    // CALL: BinaryIntervalSearchForMatchingRange(a5, a7, v16, ...) binary-searches the scope table for the try-level range matching the current frame state. [callee:0x0058A55A]
    // LOOP: Iterate over the scope-table entries matched by the binary search to locate the handler range for the current try level. [source:raw]
    // CALL: StructMatchingWithBitFlagsStrcmp compares the thrown type descriptor against the handler type descriptor to confirm a match. [callee:0x0059373E]
    // CALL: MultiArgRenderingDispatchWithLayout dispatches to the matched catch handler with the reconstructed arguments. [callee:0x00593839]
    // RETURN: The handler result is returned to the caller sub_593446 (0x00593446). [function:0x005934E1, caller:0x00593446, source:raw]

    // Conservative worker pseudocode:
    //   state = *(a2 + 8);
    //   if (state < -1 || state >= *(a5 + 4)) SEHGuardedFunctionPointerCall();
    //   rec = ExceptionRecord;
    //   if (rec->ExceptionCode != 0xE06D7363) goto fallback;
    //   if (rec->NumberParameters == 3 && rec->ExceptionInformation[0] == 429065504
    //       && rec->ExceptionInformation[2] == 0) {
    //     tls = TLSValueRetrievalWithInit();
    //     if (!tls[27]) return tls;
    //     rec = tls[27]; a3 = tls[28]; nested = 1;
    //     if (!IsBadReadPtrWrapper(rec, 1)) SEHGuardedFunctionPointerCall();
    //     if (rec->ExceptionCode != 0xE06D7363) goto fallback;
    //     if (!(rec->NumberParameters == 3 && rec->ExceptionInformation[0] == 429065504
    //           && rec->ExceptionInformation[2] == 0)) SEHGuardedFunctionPointerCall();
    //   }
    //   if (rec->ExceptionCode != 0xE06D7363 || rec->NumberParameters != 3
    //       || rec->ExceptionInformation[0] != 429065504) {
    //   fallback:
    //     if (a6) return SEHWrapperDispatchingToHandlerFunction(ExceptionRecord, a2, a3);
    //     return FontGlyphRender(rec, a2, a3, a4, a5, state, a7, TargetFrame);
    //   }
    //   range = BinaryIntervalSearchForMatchingRange(a5, a7, state, ...);
    //   for each candidate range in scope table: match try level;
    //   if (StructMatchingWithBitFlagsStrcmp(thrownType, handlerType))
    //     return MultiArgRenderingDispatchWithLayout(...);
    // UNRESOLVED: The scope-table layout (bounds at a5+4, ranges at a7) is not statically resolvable from this function alone.
    // UNRESOLVED: The semantics of TLS slots 27 and 28 (nested exception record and continuation context) are inferred, not confirmed by a named symbol.
    // UNRESOLVED: The function named FontGlyphRender in the raw source acts as a fallback/catch-all handler in this context; the mismatch between name and role is unresolved.
    // UNRESOLVED: The indirect dispatch details after a successful type match are only partially visible (raw source truncated).
}
