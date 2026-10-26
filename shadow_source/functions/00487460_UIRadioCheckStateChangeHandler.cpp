// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487460
// Canonical corpus name: UIRadioCheckStateChangeHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIRadioCheckStateChangeHandler_00487460.c

void UnknownObject::UIRadioCheckStateChangeHandler()
{
    // UI radio/check-button state change handler. When the enable flag at this+224 (0xE0) is set, it snapshots the current computed state via ShortComputation_7720, normalizes the first string field (this+160, falling back to byte_5EA438 when null) through StringNormalizeLookup_a460, compares the normalized value against the second string field (this+168, same fallback) via sub_588410, and records the comparison result (v6 == 0) into the validation state via sub_487260. It then re-reads the computed state; if it differs from the snapshot, it dispatches a virtual notification through the vtable at this+0 (entry +44) with argument 1.
    // GUARD: Enable gate: when the byte at this+224 (0xE0) is zero the whole handler body is skipped and 0 is returned; otherwise the validation and notification logic runs. [field:this:0x000000E0, source:raw]
    // CALL: Snapshot the current computed state: ShortComputation_7720() is called with no argument and its result stored in v2 for later change detection. [callee:0x00487720, source:raw]
    // ASSIGNMENT: Load the first string reference from this+160 (0xA0); when it is null, use the global default byte_5EA438. [field:this:0x000000A0, global:0x005EA438, source:raw]
    // CALL: Normalize/lookup the first string: StringNormalizeLookup_a460(v3) returns v4; a null v4 skips the comparison and validation block. [callee:0x0049A460, source:raw]
    // ASSIGNMENT: Load the second string reference from this+168 (0xA8); when it is null, use the global default byte_5EA438. [field:this:0x000000A8, global:0x005EA438, source:raw]
    // CALL: Compare the normalized first value against the second string: sub_588410(v4, v5) returns v6, where 0 means a match. [callee:0x00588410, source:raw]
    // CALL: Record the validation outcome: sub_487260(obj, v6 == 0) writes the comparison-derived boolean into the validation-state field at obj+44 (0x2C). [callee:0x00487260, field:obj:0x0000002C, source:raw]
    // GUARD: Change detection: call ShortComputation_7720(this) again; when the recomputed value differs from the entry snapshot v2, the notification is dispatched. [callee:0x00487720, source:raw]
    // CALL: Virtual notification: (*(this + 0))[44](1) invokes the vtable entry at offset 44 with argument 1 when the state changed. [field:this:0x00000000, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (this[224] == 0) return 0;
    //   state_before = ShortComputation_7720();
    //   first = this[160] ? this[160] : byte_5EA438;
    //   norm = StringNormalizeLookup_a460(first);
    //   if (norm) {
    //     second = this[168] ? this[168] : byte_5EA438;
    //     equal = (sub_588410(norm, second) == 0);
    //     sub_487260(this, equal);
    //   }
    //   if (ShortComputation_7720(this) != state_before)
    //     vtable[44](1);
    //   return 0;
    // UNRESOLVED: The exact semantic roles of the string fields at +160 (0xA0) and +168 (0xA8), of the validation-state field at +44 (0x2C), and of the argument 1 passed to the vtable+44 notification are interpretations drawn from the existing analysis fill, not independently evidenced.
    // UNRESOLVED: The identity and purpose of the object (owner type UnknownObject) is not established; callers are VirtualDispatchWithErrorHandling (0x00487530), VTableDispatch_7640 (0x00487640) and UtilityFunction_7e10 (0x00487E10).
    // UNRESOLVED: The global byte_5EA438 is treated as a default/fallback string, but its exact role (application directory vs empty string) is not proven.
}
