// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8AE0
// Canonical corpus name: DualSourceAcquireWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualSourceAcquireWithFallback_004f8ae0.c

void UnknownObject::acquireValueWithFallback()
{
    // Acquires a value for the this object: calls sub_4F8B50() and stores its result into *this; if that result is zero, calls GlobalCallbackDispatcher(0) and stores its result instead. Returns the stored value.
    // CALL: Call sub_4F8B50() as the primary acquisition source and capture its return value in v2. [callee:0x004F8B50, source:raw]
    // ASSIGNMENT: Store v2 into the dword at this+0x0. [field:this:0x00000000, source:raw]
    // GUARD: If the stored value v2 is zero, treat the primary source as failed and take the fallback path. [source:raw]
    // CALL: On fallback, call GlobalCallbackDispatcher(0) and store its result into the dword at this+0x0. [callee:0x004F8C70, field:this:0x00000000, source:raw]
    // RETURN: Return the final value held in the dword at this+0x0 (primary result, or fallback result when primary was zero). [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   v2 = sub_4F8B50();
    //   *this = v2;
    //   if (!v2)
    //     *this = GlobalCallbackDispatcher(0);
    //   return *this;
    // UNRESOLVED: The object type behind this is unknown; the only recorded caller is HWInput_Enter (0x00455BF0), and what sub_4F8B50 / GlobalCallbackDispatcher(0) actually acquire is not evidenced.
}
