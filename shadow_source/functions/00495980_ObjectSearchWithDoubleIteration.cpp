// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495980
// Canonical corpus name: ObjectSearchWithDoubleIteration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectSearchWithDoubleIteration_00495980.c

void UnknownObject::ObjectSearchWithDoubleIteration()
{
    // Two-pass linked-list object search. Loads two criteria from this at byte offsets 0x5C and 0x60 (dword indices 23 and 24). Gets the primary container root via SimpleFieldGetter(this); if it is NULL the function returns an uninitialized value. Otherwise walks the primary list starting at ShortComputation_8f60(root) following StructFieldAccessor next-pointers, calling a virtual match predicate at vtable slot offset 48 with both criteria on each node and keeping the last matching node. If no match was found and sub_498E40(root) is non-NULL, walks a secondary list rooted at (sub_498E40(root) + 68) the same way. Returns the last matched node or NULL.
    // ASSIGNMENT: Load search criteria: v1 = this[23] (byte offset 0x5C) and v9 = this[24] (byte offset 0x60). [field:this:0x0000005C, field:this:0x00000060, source:raw]
    // CALL: Call SimpleFieldGetter(this) to obtain the primary container root; keep it as v4. [callee:0x00495970, source:raw]
    // GUARD: If the primary root v2 is NULL, return uninitialized v3 immediately. [source:raw]
    // ASSIGNMENT: Initialize v5 = 0 (no match found yet). [source:raw]
    // LOOP: Walk the primary list: for i = ShortComputation_8f60(v2) as first element, then i = StructFieldAccessor(i) (next pointer) until NULL. [callee:0x00498F60, callee:0x00486320, source:raw]
    // CALL: Invoke the virtual match predicate via vtable slot at (*i + 48) with (i, v1, v9); on non-zero result, record v5 = i (overwritten on each match). [field:this:0x0000005C, field:this:0x00000060, source:raw]
    // GUARD: If sub_498E40(v4) is non-NULL, a secondary container exists. [callee:0x00498E40, source:raw]
    // GUARD: If v5 is still 0 (no primary match), run the secondary pass. [source:raw]
    // LOOP: Walk the secondary list: for j = *(sub_498E40(v4) + 68) as first element, then j = StructFieldAccessor(j) (next pointer) until NULL. [callee:0x00498E40, callee:0x00486320, source:raw]
    // CALL: Invoke the virtual match predicate via vtable slot at (*j + 48) with (j, v1, v9); on non-zero result, record v5 = j. [field:this:0x0000005C, field:this:0x00000060, source:raw]
    // RETURN: Return v5 (last matched node from either pass, or NULL). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_495980(_DWORD *this) {
    //     int v1 = this[23];   /* byte offset 0x5C * /
    //     int v9 = this[24];   /* byte offset 0x60 * /
    //     int v4 = SimpleFieldGetter(this);
    //     if (!v4) return (_DWORD *)v3;   /* uninitialized * /
    //     _DWORD *v5 = 0;
    //     for (i = (_DWORD *)ShortComputation_8f60(v4); i; i = (_DWORD *)StructFieldAccessor(i))
    //       if ( (*(int (__thiscall **)(_DWORD *, int, int))(*i + 48))(i, v1, v9) ) v5 = i;
    //     if (sub_498E40(v4)) {
    //       if (!v5)
    //         for (j = *(_DWORD **)(sub_498E40(v4) + 68); j; j = (_DWORD *)StructFieldAccessor(j))
    //           if ( (*(int (__thiscall **)(_DWORD *, int, int))(*j + 48))(j, v1, v9) ) v5 = j;
    //     }
    //     return v5;
    //   }
    // UNRESOLVED: Returning uninitialized v3 when the primary root is NULL is a decompiler artifact; actual runtime behavior unknown.
    // UNRESOLVED: v5 is overwritten on every matching node and there is no break, so the function yields the last match in iteration order, not necessarily the first.
    // UNRESOLVED: Identity and semantics of the virtual match predicate (vtable slot at offset 48) are unknown.
    // UNRESOLVED: The proposed role in a UI/widget object lookup system is DERIVED only from the caller names.
}
