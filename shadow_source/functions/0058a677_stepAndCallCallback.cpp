// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A677
// Canonical corpus name: sub_58A677
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58A677_0058a677.c

void UnknownObject::stepAndCallCallback()
{
    // Iterator dispatch helper: loops while --a3 >= 0, decrementing pointer a1 by step size a2 each iteration and invoking a callback function pointer. Returns the last callback result. Used by both NTimeCallbackLoopWithSEH variants to step through a sequence and call a per-element callback.
    // LOOP: Loop while --a3 >= 0, so the body runs a3 times. [source:raw]
    // CALCULATION: Decrement pointer a1 by step size a2 each iteration. [source:raw]
    // CALL: Invoke callback function pointer a4() and capture its result (per existing analysis, statically identified callee 0x0058A6D5 / StreamMagicNumberCheck is the likely callback target). [callee:0x0058A6D5, source:raw]
    // RETURN: Return the last callback result. [function:0x0058A677]

    // Conservative worker pseudocode:
    //   int stepAndCallCallback(int a1, int a2, int a3, int (*a4)(void)) {
    //     int result;
    //     while (--a3 >= 0) { a1 -= a2; result = a4(); }
    //     return result;
    //   }
    // UNRESOLVED: The globals 0x0058895C (ScriptFrameProcessor) and 0x005B8CA8 (stru_5B8CA8) plus the KUSER_SHARED_DATA/TEB bytes at 0xFF00000000001692..169B are SEH registration artifacts attributed to this function's scope, not visible in the raw body.
    // UNRESOLVED: Whether callee 0x0058A6D5 is the callback invoked through a4 or an SEH handler is unconfirmed.
    // UNRESOLVED: Semantic meaning of a1/a2/a3 (data pointer, element size, element count) is DERIVED from the loop shape only.
}
