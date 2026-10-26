// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A5E9
// Canonical corpus name: sub_59A5E9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A5E9_0059a5e9.c

void UnknownObject::ConditionalLeaveCriticalSection()
{
    // Guarded critical-section release: if the global Target (0x008D4610) equals 2, call LeaveCriticalSection on the global CriticalSection (0x008D45F8). Otherwise no operation is performed. Void, no return value. The many refcount/locale-management wrappers that call it suggest a lock-management helper.
    // GUARD: Read the global Target (0x008D4610); branch only when it equals the literal 2. [global:0x008D4610, source:raw]
    // CALL: When Target == 2, invoke LeaveCriticalSection (referenced as global entry 0x0059E170) on the global CriticalSection object (0x008D45F8). [global:0x0059E170, global:0x008D45F8, source:raw]
    // CALL: Called from a wide set of wrapper/thunk functions including RefCountDecrementWithCleanup (0x00598994), LocaleRefcountAcquireUnderLock (0x00598C1C), CounterIncrementThreadSafe (0x00598C4A), RefcountDecrementWithLock (0x00598C88), ObjectTeardownWithIteratorCleanup (0x0059AC7F) and many sub_/SingleFunctionCallWrapper thunks in the 0x00579FB0-0x00599AD9 range, consistent with a shared lock-release helper. [caller:0x00598994, caller:0x00598C1C, caller:0x00598C4A, caller:0x00598C88, caller:0x0059AC7F, caller:0x00579FB0, source:raw]

    // Conservative worker pseudocode:
    //   void ConditionalLeaveCriticalSection() {
    //     if (Target == 2)
    //       LeaveCriticalSection(&CriticalSection);
    //   }
    // UNRESOLVED: Meaning of the condition Target == 2 is unknown; no packet evidence explains what value 2 represents or who writes Target.
    // UNRESOLVED: The relation of the CriticalSection/Target globals to the refcount and locale subsystems that call this function is not established.
    // UNRESOLVED: LeaveCriticalSection is recorded as a global entry (IAT-style) rather than a callee, so the imported target address is not confirmed.
    // UNRESOLVED: No owner or ABI lead exists for this function.
}
