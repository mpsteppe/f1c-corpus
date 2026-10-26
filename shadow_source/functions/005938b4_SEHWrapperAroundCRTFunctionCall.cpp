// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005938B4
// Canonical corpus name: SEHWrapperAroundCRTFunctionCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHWrapperAroundCRTFunctionCall_005938b4.c

void UnknownObject::SEHWrapperAroundCRTFunctionCall()
{
    // SEH/C++-exception wrapper around a wrapped CRT dispatch. Saves the dword preceding a2 and the two TLS slots 27/28 (via TLSValueRetrievalWithInit), installs a1 and a3 into those TLS slots, runs the wrapped body SEHExceptionFrameWrapper(a2, a4, a5, a6, a7), then restores all saved state. If the exception record behind a1 carries a C++ exception code (0xE06D7363 at +0x0), three parameters at +0x10 and magic 0x19930520 at +0x14, and the body returned non-zero, it checks CRTAbnormalTermination() and dispatches through SEHWrappedRenderDispatchCall(a1, abnormal). Returns the wrapped body's return value. Called by MultiArgRenderingDispatchWithLayout (00593839).
    // ASSIGNMENT: Saves the dword at a2-4 into v10 before the wrapped call runs [source:raw]
    // CALL: Reads TLS slots 27 and 28 via TLSValueRetrievalWithInit into v12 and v11 so the wrapper context can be restored afterward [callee:0x0058E0C7, source:raw]
    // ASSIGNMENT: Installs the wrapped-call context: writes a1 into TLS slot 27 and a3 into TLS slot 28 via TLSValueRetrievalWithInit [callee:0x0058E0C7, source:raw]
    // CALL: Runs the wrapped body SEHExceptionFrameWrapper(a2, a4, a5, a6, a7) and keeps its result in v9 [callee:0x0058A3B6, source:raw]
    // ASSIGNMENT: Restores the saved state after the wrapped call: writes v10 back to a2-4, restores TLS slot 27 to v12 and TLS slot 28 to v11 [callee:0x0058E0C7, source:raw]
    // GUARD: Exception-record guard: *a1 equals the C++ exception code 0xE06D7363 (field 0x0), a1[4] equals 3 (field 0x10), a1[5] equals the magic 0x19930520 (field 0x14), and v9 is non-zero [guard:0, guard:1, guard:2, field:this:0x00000000, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: On a matching C++ exception, calls CRTAbnormalTermination() and holds the boolean result in v8 [callee:0x0058890E, source:raw]
    // CALL: Dispatches SEHWrappedRenderDispatchCall(a1, v8) with the exception record and the abnormal-termination flag [callee:0x00593BBD, source:raw]
    // RETURN: Returns the wrapped body's result v9 in all paths [source:raw]
    // CALL: Invoked by MultiArgRenderingDispatchWithLayout (00593839), placing this on the rendering-dispatch path [caller:0x00593839, source:raw]

    // Conservative worker pseudocode:
    //   saved_a2m4 = *(a2 - 4);
    //   saved_tls27 = TLSValueRetrievalWithInit()[27];
    //   saved_tls28 = TLSValueRetrievalWithInit()[28];
    //   TLSValueRetrievalWithInit()[27] = a1;
    //   TLSValueRetrievalWithInit()[28] = a3;
    //   v9 = SEHExceptionFrameWrapper(a2, a4, a5, a6, a7);
    //   *(a2 - 4) = saved_a2m4;
    //   TLSValueRetrievalWithInit()[27] = saved_tls27;
    //   TLSValueRetrievalWithInit()[28] = saved_tls28;
    //   if (*a1 == 0xE06D7363 && a1[4] == 3 && a1[5] == 0x19930520 && v9) {
    //     abnormal = CRTAbnormalTermination();
    //     SEHWrappedRenderDispatchCall(a1, abnormal);
    //   }
    //   return v9;
    // UNRESOLVED: Callees MSVCRTSEHFrameUnwinder (005888A6) and FileMagicNumberValidator (005939CF) are flagged by packet facts but do not appear in the raw decompiled source; they are likely reached through the SEH machinery of the wrapped call
    // UNRESOLVED: Globals 0058895C and 005B9950 are flagged by packet facts but do not appear in the raw decompiled source
    // UNRESOLVED: The TLS byte globals at 0xFF00000000001692-0xFF0000000000169B are flagged as read/written by packet facts; they correspond to the TLS area behind TLSValueRetrievalWithInit and are not named in the raw source
    // UNRESOLVED: The role of the dword preceding a2 (a2-4) is unknown beyond being saved and restored
}
