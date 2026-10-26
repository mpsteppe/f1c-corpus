// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487900
// Canonical corpus name: StateChangeHandlerWithSubscriberNotification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateChangeHandlerWithSubscriberNotification_00487900.c

void UnknownObject::StateChangeHandlerWithSubscriberNotification()
{
    // UI state-change handler with subscriber notification. Compares incoming state byte a2 against the current UI state via ByteFieldGetterAt100; when different, fires a vtable+44 notification with argument 1. Always dispatches StateChangeNotification, then activates (vtable+64 with 4) when a2 is non-zero, or deactivates via RangeCheck + ConditionalStateMachineDispatch when a2 is zero. Finally walks a subscriber linked list headed at this+0x90, invoking each node's vtable+56 with a2, advancing via StructFieldAccessor until the list ends.
    // GUARD: Guard on state difference: if (BYTE)a2 != ByteFieldGetterAt100(this), call the vtable+44 __stdcall notification with argument 1. The field obj+0x2C supplies the current UI state byte read by ByteFieldGetterAt100. [source:raw, callee:0x00486710, field:obj:0x0000002C, field:this:0x00000000]
    // CALL: Dispatch StateChangeNotification(this, a2) unconditionally after the difference check. [callee:0x00486660]
    // GUARD: Branch on a2: when non-zero take the activation path, otherwise the deactivation path. [source:raw]
    // CALL: Activation path: call the vtable+64 __thiscall virtual with (this, 4) and store its result as the return value. [source:raw, field:this:0x00000000]
    // CALL: Deactivation path: v4 = RangeCheck(this), then ConditionalStateMachineDispatch(this, v4); result stored as the return value. [callee:0x00487740, callee:0x00487830, field:obj:0x00000040]
    // ASSIGNMENT: Load the subscriber list head from this+0x90 into v5. [field:this:0x00000090]
    // LOOP: While the current subscriber node v5 is non-null, call its vtable+56 __thiscall virtual with a2, then advance v5 via StructFieldAccessor; iterate until the next-node value is null. [source:raw, callee:0x00486320, field:*(this+0x90):0x00000000, field:*(*(this+0x90)+0x0):0x00000038]
    // RETURN: Return the last stored result v3 (activation/deactivation dispatch result, or last StructFieldAccessor value when the subscriber list was walked). [source:raw]

    // Conservative worker pseudocode:
    //   char StateChangeHandlerWithSubscriberNotification(int this, int a2) {
    //     if ((BYTE)a2 != ByteFieldGetterAt100(this))
    //       (*(void (__stdcall **)(int))*this[0x0] + 44)(1);
    //     StateChangeNotification(this, a2);
    //     int v3;
    //     if ((BYTE)a2) {
    //       v3 = (*(int (__thiscall **)(int,int))*this[0x0] + 64)(this, 4);
    //     } else {
    //       char v4 = RangeCheck(this);
    //       v3 = ConditionalStateMachineDispatch(this, v4);
    //     }
    //     _DWORD *v5 = *(_DWORD **)(this + 0x90);
    //     while (v5) {
    //       (*(void (__thiscall **)(_DWORD *,int))*v5[0x0] + 56)(v5, a2);
    //       v3 = StructFieldAccessor(v5);
    //       v5 = (_DWORD *)v3;
    //     }
    //     return v3;
    //   }
    // UNRESOLVED: Identity of this (object type and vtable layout unknown); vtable slots +44, +56 and +64 are virtual methods without names.
    // UNRESOLVED: Semantics of the obj+0x2C state byte and obj+0x40 range field beyond their roles in change detection and range dispatch.
    // UNRESOLVED: Subscriber node structure at this+0x90: node field +0x0 doubles as vtable/header and StructFieldAccessor traverses via offset +0x38; exact node type unknown.
}
