// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487960
// Canonical corpus name: UIControlStateChangeHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIControlStateChangeHandler_00487960.c

void UnknownObject::UIControlStateChangeHandler()
{
    // UI-control state-change handler gated by the enable byte at this+0xE0. When enabled it snapshots the current state via ShortComputation_7720, normalizes a lookup string (this+0xA0, falling back to byte_5EA438 when null) through StringNormalizeLookup_a460 using a context base 5772 bytes into the object at this+0x40, and when normalization succeeds compares it against a second string (this+0xA8, also falling back to byte_5EA438) via sub_588410, dispatching StateDependentVTableDispatch_7760 with the comparison result. If a second ShortComputation_7720 snapshot differs from the first, it fires the virtual notification at vtable offset +44 with argument 1. Always returns 0.
    // GUARD: Enable flag at this+0xE0: when zero the entire handler body is skipped and the function returns 0 [field:this:0x000000E0, source:raw]
    // CALL: First state snapshot taken via ShortComputation_7720 and stored for later change detection [callee:0x00487720, source:raw]
    // ASSIGNMENT: First normalization source loaded from this+0xA0, defaulting to byte_5EA438 when null [field:this:0x000000A0, global:0x005EA438, source:raw]
    // CALL: StringNormalizeLookup_a460 resolves the source string against a context object read 5772 bytes into the object pointed to by this+0x40 [callee:0x0049A460, field:this:0x00000040, source:raw]
    // GUARD: Normalization result guard: dispatch and comparison only run when v4 is non-null [source:raw]
    // ASSIGNMENT: Comparison target loaded from this+0xA8, defaulting to byte_5EA438 when null [field:this:0x000000A8, global:0x005EA438, source:raw]
    // CALL: sub_588410 compares the normalized lookup result against the comparison target; equality is indicated by a zero return [callee:0x00588410, source:raw]
    // CALL: StateDependentVTableDispatch_7760 dispatched with the equality flag (v6 == 0) derived from the string comparison [callee:0x00487760, source:raw]
    // GUARD: Change detection: a second ShortComputation_7720 snapshot is compared against the first; notification fires only when they differ [callee:0x00487720, source:raw]
    // CALL: Virtual notification invoked through the vtable pointer stored at this+0x0 at slot +44, passing argument 1 [field:this:0x00000000, source:raw]
    // RETURN: Function returns literal 0 on every path [source:raw]
    // CALL: Invoked by InitDispatchWithVTableCheck and sub_487D50 as the state-change handler for a UI control [caller:0x004879E0, caller:0x00487D50, source:raw]

    // Conservative worker pseudocode:
    //   if (!*(byte*)(this + 0xE0)) return 0;
    //   v2 = ShortComputation_7720(this);
    //   v3 = *(char**)(this + 0xA0); if (!v3) v3 = byte_5EA438;
    //   v4 = StringNormalizeLookup_a460(*(dword*)(this + 0x40) + 5772, v3);
    //   if (v4) {
    //     v5 = *(char**)(this + 0xA8); if (!v5) v5 = byte_5EA438;
    //     v6 = sub_588410(v4, v5);
    //     StateDependentVTableDispatch_7760(this, v6 == 0);
    //   }
    //   if (ShortComputation_7720(this) != v2) {
    //     (*(void (__stdcall**)(int))*(dword*)this[?])(1);
    //   }
    //   return 0;
    // UNRESOLVED: Field obj+0x2C is a deterministic-fact read not visible in the raw decompiled source; its role (validation state touched by StateDependentVTableDispatch_7760 per prior analysis) is not confirmable here
    // UNRESOLVED: Meaning of the 5772-byte context offset added to this+0x40 for StringNormalizeLookup_a460 is unresolved without the lookup-context layout
    // UNRESOLVED: Semantics of StateDependentVTableDispatch_7760's boolean argument (which state it selects) not established
    // UNRESOLVED: Meaning of the virtual notification slot +44 and its argument 1 not established
    // UNRESOLVED: Why the enable flag and the normalization path both re-enter ShortComputation_7720 is structural rather than semantic here
}
