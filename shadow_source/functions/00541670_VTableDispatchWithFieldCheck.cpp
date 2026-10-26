// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541670
// Canonical corpus name: VTableDispatchWithFieldCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchWithFieldCheck_00541670.c

void UnknownObject::VTableDispatchWithFieldCheck()
{
    // Guard-gated virtual dispatch. When the flag at this+0x13D8 is non-zero, calls the virtual method stored at vtable entry 0xC8 (offset 200) of the sub-object at this+0x1100 with integer argument 139 and the caller-supplied value a2, storing the result at this+0x0. Always returns 0.
    // GUARD: Only dispatch when this[0x13D8] (guard flag) is non-zero; otherwise skip the vtable call. [field:this:0x000013D8]
    // CALL: Indirect call through vtable entry at *(this+0x1100)+0xC8 (offset 200), passing (this[0x1100], 139, a2). [field:*(this+0x1100):0x000000C8, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the result of the virtual dispatch into this[0x0]. [field:this:0x00000000]
    // RETURN: Return 0 unconditionally, regardless of whether the dispatch ran. [source:raw, function:0x00541670]

    // Conservative worker pseudocode:
    //   int sub_541670(void **this, int a2) {
    //     if (this->guard_13D8 != 0) {
    //       this->field_0 = (this->subobj_1100->vtbl[200])(this->subobj_1100, 139, a2);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the argument 139 (likely a property/message id) are not established.
    // UNRESOLVED: The virtual method at vtable entry 0xC8 is not identified; its return type and side effects are unknown.
}
