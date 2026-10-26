// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047E680
// Canonical corpus name: DualStateCheckedDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualStateCheckedDispatch_0047e680.c

void UnknownObject::DualStateCheckedDispatch()
{
    // Dispatches two commands by selectors 25 and 26 through the object referenced by global dword_7CD8C0, comparing each dispatched object's name against this when it is non-null. Returns 0.
    // CALL: Indirect __thiscall through the vtable of dword_7CD8C0 at offset 28, requesting the object for selector 25; store the returned pointer. [source:raw, global:0x007CD8C0]
    // GUARD: Guard on the first dispatched pointer being non-null before its name comparison. [source:raw]
    // CALL: Call ObjectNameComparison with the first dispatched object and this as arguments. [source:raw, callee:0x00477280]
    // CALL: Indirect __thiscall through the vtable of dword_7CD8C0 at offset 28, requesting the object for selector 26; store the returned pointer. [source:raw, global:0x007CD8C0]
    // GUARD: Guard on the second dispatched pointer being non-null before its name comparison. [source:raw]
    // CALL: Call ObjectNameComparison with the second dispatched object and this as arguments. [source:raw, callee:0x00477280]
    // RETURN: Return constant 0. [source:raw]

    // Conservative worker pseudocode:
    //   int DualStateCheckedDispatch(void* this) {
    //     void* first = dword_7CD8C0->vtable[7](dword_7CD8C0, 25);
    //     if (first) ObjectNameComparison(first, this);
    //     void* second = dword_7CD8C0->vtable[7](dword_7CD8C0, 26);
    //     if (second) ObjectNameComparison(second, this);
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the dispatcher object behind dword_7CD8C0 and the meaning of selectors 25 and 26.
    // UNRESOLVED: Semantics of ObjectNameComparison and why its result is discarded.
}
