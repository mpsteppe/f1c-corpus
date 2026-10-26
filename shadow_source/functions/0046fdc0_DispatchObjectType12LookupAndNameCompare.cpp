// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FDC0
// Canonical corpus name: VTableDispatchWithConditionalCreation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchWithConditionalCreation_0046fdc0.c

void UnknownObject::DispatchObjectType12LookupAndNameCompare()
{
    // Performs preliminary setup, clears a boolean flag to 0, then looks up/creates object type 12 through the dispatch interface vtable (dword_7CD8C0 method at +28). If the returned object is non-null, compares its name with the `this` parameter. Always returns 0.
    // CALL: ShortComputation_fec0() runs preliminary setup/computation before the dispatch. [callee:0x0048FEC0]
    // CALL: BooleanFlagSetterVirtualCall(0) clears a boolean flag to 0 (false). [callee:0x00490160, source:raw]
    // CALL: Dispatch interface dword_7CD8C0 vtable method at +28 is invoked with argument 12 to look up or create an object; result stored in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Name comparison runs only when the returned object v2 is non-null. [source:raw]
    // CALL: ObjectNameComparison(v2, this) compares the looked-up object's name with the `this` parameter. [callee:0x00477280, source:raw]
    // RETURN: Always returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int DispatchObjectType12LookupAndNameCompare(void *this) {
    //     ShortComputation_fec0();
    //     BooleanFlagSetterVirtualCall(0);
    //     void *v2 = g_dispatch->GetObject(12);          // *(dword_7CD8C0) vtable +28
    //     if (v2) ObjectNameComparison(v2, this);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the dword_7CD8C0 vtable method at +28 and of object type 12 are not grounded in this packet.
    // UNRESOLVED: Role of the boolean cleared by BooleanFlagSetterVirtualCall(0) is unknown.
    // UNRESOLVED: Meaning of ObjectNameComparison's result is unused (return value ignored).
}
