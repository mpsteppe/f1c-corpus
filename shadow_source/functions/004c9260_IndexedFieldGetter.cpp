// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9260
// Canonical corpus name: StateIndexedFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateIndexedFieldGetter_004c9260.c

void UnknownObject::IndexedFieldGetter()
{
    // Small indexed selector: reads a selector from this+0x1C and returns this+0x20 when it is 0, this+0x24 when it is 1, this+0x28 when it is 2, and 0 for any other value. Reads only; no writes. Called by EqualityStateCheck (004C9280) and ObjectPropertySetter (004C92B0), consistent with a state-keyed field accessor on a small state object.
    // ASSIGNMENT: v1 = this[7]; load the selector index from this+0x1C; result = 0. [field:this:0x0000001C, function:0x004C9260, source:raw]
    // GUARD: If !v1 (selector == 0) return this[8]; value at this+0x20. [field:this:0x00000020, function:0x004C9260, source:raw]
    // GUARD: v3 = v1 - 1; if !v3 (selector == 1) return this[9]; value at this+0x24. [field:this:0x00000024, function:0x004C9260, source:raw]
    // GUARD: If v3 == 1 (selector == 2) return this[10]; value at this+0x28. [field:this:0x00000028, function:0x004C9260, source:raw]
    // RETURN: Return 0 for any selector value outside {0, 1, 2}. [function:0x004C9260, source:raw]

    // Conservative worker pseudocode:
    //   selector = this[7];
    //   if (selector == 0)
    //     return this[8];
    //   if (selector == 1)
    //     return this[9];
    //   if (selector == 2)
    //     return this[10];
    //   return 0;
    // UNRESOLVED: The meaning of the three selected values and the selector semantics (state id versus property index) depend on the owning state object, which is unidentified.
    // UNRESOLVED: Callers EqualityStateCheck (004C9280) and ObjectPropertySetter (004C92B0) suggest a small state-machine helper cluster, but their exact roles are unverified.
}
