// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FE20
// Canonical corpus name: StateCheckConditionalDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateCheckConditionalDispatch_0046fe20.c

void UnknownObject::DispatchObjectType13LookupAndNameCompare()
{
    // Structural twin of DispatchObjectType12LookupAndNameCompare: runs preliminary setup, clears a boolean flag to 0, then looks up/creates object type 13 via the dispatch interface vtable (dword_7CD8C0 method at +28). If the returned object is non-null, compares its name with the `this` parameter. Always returns 0. The only difference from the type-12 twin is the object type argument (13 instead of 12).
    // CALL: ShortComputation_fec0() runs preliminary setup/computation before the dispatch. [callee:0x0048FEC0]
    // CALL: BooleanFlagSetterVirtualCall(0) clears a boolean flag to 0 (false). [callee:0x00490160, source:raw]
    // CALL: Dispatch interface dword_7CD8C0 vtable method at +28 is invoked with argument 13 to look up or create an object; result stored in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Name comparison runs only when the returned object v2 is non-null. [source:raw]
    // CALL: ObjectNameComparison(v2, this) compares the looked-up object's name with the `this` parameter. [callee:0x00477280, source:raw]
    // RETURN: Always returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int DispatchObjectType13LookupAndNameCompare(void *this) {
    //     ShortComputation_fec0();
    //     BooleanFlagSetterVirtualCall(0);
    //     void *v2 = g_dispatch->GetObject(13);          // *(dword_7CD8C0) vtable +28
    //     if (v2) ObjectNameComparison(v2, this);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the dword_7CD8C0 vtable method at +28 and of object type 13 are not grounded in this packet.
    // UNRESOLVED: Role of the boolean cleared by BooleanFlagSetterVirtualCall(0) is unknown.
    // UNRESOLVED: Meaning of ObjectNameComparison's result is unused (return value ignored).
}
