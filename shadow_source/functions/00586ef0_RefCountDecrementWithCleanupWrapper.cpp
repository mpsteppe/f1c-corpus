// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586EF0
// Canonical corpus name: sub_586EF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586EF0_00586ef0.c

void UnknownObject::RefCountDecrementWithCleanupWrapper()
{
    // Thin wrapper that calls RefCountDecrementWithCleanup() with no arguments and returns its int result. The raw decompiled source is a single-expression forwarding wrapper. Deterministic facts additionally record a read of global 0x008D3E31 that is not visible in the decompiled body, so its role in the refcount-decrement/cleanup path is unresolved here.
    // CALL: Invoke RefCountDecrementWithCleanup() and use its return value as this function's result. [function:0x00586EF0, source:raw]
    // RETURN: Return the int value produced by RefCountDecrementWithCleanup(). [function:0x00586EF0, source:raw]

    // Conservative worker pseudocode:
    //   int RefCountDecrementWithCleanupWrapper(void) {
    //     return RefCountDecrementWithCleanup();
    //   }
    // UNRESOLVED: Global 0x008D3E31 is read per the packet but does not appear in the decompiled body; its role in the refcount-decrement/cleanup path is unresolved.
    // UNRESOLVED: RefCountDecrementWithCleanup is named only in the raw source text; it is absent from the packet callees list, so its target address and exact reference-counting semantics are unknown.
    // UNRESOLVED: The identity of the object whose reference count is decremented is unknown; no owner evidence exists.
}
