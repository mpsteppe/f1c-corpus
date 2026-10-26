// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A640
// Canonical corpus name: CommandDispatchWithGuard_a640
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CommandDispatchWithGuard_a640_0047a640.c

void UnknownObject::CommandDispatchWithGuard()
{
    // Dispatches a command by selector 19 through the object referenced by global dword_7CD8C0, then compares the returned object's name against this. Returns 0 regardless of the result.
    // CALL: Indirect __thiscall through the vtable of dword_7CD8C0 at offset 28, requesting the object for selector 19; store the returned pointer. [source:raw, global:0x007CD8C0]
    // GUARD: Guard on the returned pointer being non-null before the name comparison. [source:raw]
    // CALL: Call ObjectNameComparison with the dispatched object and this as arguments. [source:raw, callee:0x00477280]
    // RETURN: Return constant 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CommandDispatchWithGuard(void* this) {
    //     void* obj = dword_7CD8C0->vtable[7](dword_7CD8C0, 19);
    //     if (obj) ObjectNameComparison(obj, this);
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the dispatcher object behind dword_7CD8C0 and the meaning of selector 19.
    // UNRESOLVED: Semantics of ObjectNameComparison and why its result is discarded.
}
