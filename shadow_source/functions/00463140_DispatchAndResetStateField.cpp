// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463140
// Canonical corpus name: ShortComputation_3140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_3140_00463140.c

void UnknownObject::DispatchAndResetStateField()
{
    // Unconditional dual virtual dispatch on a sub-object, followed by a state reset. Reads the primary pointer at this->0x0 to reach a sub-object, loads the sub-object pointer at +0x3FB8, dispatches through DualVirtualDispatchWrapper (0x0057A660), then writes 0 to the state field at +0x3FC4. Returns the dispatch result. Called by SessionStateByte7CE25FSetter (0x00464600) and sub_4A0490 (0x004A0490).
    // CALL: Dereference this->0x0 to get the primary object, read its sub-object pointer at +0x3FB8, and dispatch through DualVirtualDispatchWrapper (0x0057A660), capturing the result. [field:this:0x00000000, field:obj:0x00003FB8, callee:0x0057A660]
    // ASSIGNMENT: After the dispatch, write 0 to the state field at sub-object +0x3FC4. [field:obj:0x00003FC4]
    // RETURN: Return the value produced by DualVirtualDispatchWrapper. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_463140(void *this) {
    //     int result = DualVirtualDispatchWrapper(*(int *)(*(char **)this + 0x3FB8));
    //     *(int *)(*(char **)this + 0x3FC4) = 0;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the dispatched sub-object at +0x3FB8 and the reset state field at +0x3FC4 is not established.
    // UNRESOLVED: Owning class is unknown; both this->0x0 indirection and the +0x3FB8 sub-object point into object layouts not identified here.
    // UNRESOLVED: Relation of this reset to the caller SessionStateByte7CE25FSetter (0x00464600) is not confirmed.
}
