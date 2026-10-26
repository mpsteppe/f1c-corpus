// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466140
// Canonical corpus name: ShortComputation_6140
// Owner: UIObject [DERIVED]
// Raw source: functions/ShortComputation_6140_00466140.c

void UIObject::UIObjectDestructorWithStateReset()
{
    // Destructor-style cleanup for an object whose vtable pointer is assigned off_59F140. It reassigns this+0x0 to off_59F140, calls StateResetWithZero to clear object state, then tail-returns Destructor_e670(this). Existing analysis labels it a UI object destructor with state reset.
    // ASSIGNMENT: *this = &off_59F140 assigns the object's vtable pointer (field this+0x0) to off_59F140 before cleanup. [field:this:0x00000000, global:0x0059F140, source:raw]
    // CALL: StateResetWithZero() resets the object's state after the vtable reassignment. [callee:0x004662E0, source:raw]
    // RETURN: Tail-return the result of Destructor_e670(this) as the final destructor step. [function:0x00466140, source:raw]

    // Conservative worker pseudocode:
    //   int sub_466140(_DWORD *this) {
    //     *this = &off_59F140;
    //     StateResetWithZero();
    //     return Destructor_e670(this);
    //   }
    // UNRESOLVED: Identity of the UI class and the object lifetime contract (Destructor_e670 has no packet callee evidence ref) are unverified.
    // UNRESOLVED: What state StateResetWithZero clears beyond 'state field' is unknown.
    // UNRESOLVED: Whether Destructor_e670 frees memory is unknown; caller DestructorWithConditionalFree_5a70 handles its own conditional free.
}
