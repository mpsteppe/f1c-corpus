// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7E30
// Canonical corpus name: VTableDispatchWithFieldClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchWithFieldClear_004d7e30.c

void UnknownObject::VTableDispatchWithFieldClear()
{
    // State-reset virtual dispatch wrapper. Reads the vtable pointer from this+0x0, clears the state/flag dword at this+0xC to 0, then dispatches through the vtable slot at offset +0x10 (4th slot) with no arguments and returns its result. No guards; always clears then dispatches. Called by OnScreen_Restart (0049f000), sub_4D8760 (004d8760), VehicleStateUpdate (004d9fe0) and ThunkToSub4D7E30 (004db110).
    // CALCULATION: Reads the vtable pointer from this+0x0 into v1 as the dispatch base [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clears the state/flag dword at this+0xC to 0 before dispatching [field:this:0x0000000C, source:raw]
    // CALL: Dispatches the function pointer at vtable+0x10 (4th vtable slot) with no arguments [field:obj:0x00000010, source:raw]
    // RETURN: Returns the result of the dispatched vtable function [source:raw]
    // CALL: Shared state-reset dispatch wrapper called from OnScreen_Restart (0049f000), sub_4D8760 (004d8760), VehicleStateUpdate (004d9fe0) and ThunkToSub4D7E30 (004db110) [caller:0x0049F000, caller:0x004D8760, caller:0x004D9FE0, caller:0x004DB110, source:raw]

    // Conservative worker pseudocode:
    //   int VTableDispatchWithFieldClear(int *this) {
    //     v1 = *this;                 // vtable pointer at this+0x0
    //     this[3] = 0;                // clear flag at this+0xC
    //     return (*(int (**)())(v1 + 16))();  // vtable slot +0x10, no args
    //   }
    // UNRESOLVED: The owner class and the semantics of the cleared field at this+0xC are unknown; prior analysis notes it is recalculated every frame, so external pokes do not persist
    // UNRESOLVED: The target of the vtable slot at +0x10 is unknown; the '4th vtable entry / state reset' interpretation is DERIVED
}
