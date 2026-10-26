// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5D30
// Canonical corpus name: SceneSortComparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneSortComparator_004c5d30.c

void UnknownObject::SceneSortComparator()
{
    // Comparison functor used to order filter/property nodes for sorting. Primary key is the SceneOrder value at this+0xC: returns the signed less-than result (v4 ^ v5, overflow-corrected) of this[3] vs a2[3]. On a tie, resolves each node's scene entry in the global scene array dword_8AC490 (stride 396 / 0x18c) via the scene index at +0x0 and compares the scene-name strings at entry offset 260 (0x104) with sub_588410, returning true if the first sorts before the second. If either scene entry is null, falls back to comparing the node name strings at this+0x4 / a2+0x4, substituting byte_5EA438 for a missing string. Called by SceneFileFilterBuilder (004C6330) and MergeSortLinkedList (004C6810).
    // CALCULATION: Read the primary sort keys v2 = this[3] and v3 = a2[3]; compute the signed difference with overflow flag v5 = __OFSUB__(v2, v3) and sign flag v4 = (v2 - v3) < 0. [field:this:0x0000000C, source:raw]
    // GUARD: If v2 != v3 the nodes are ordered directly; the effective result is the overflow-corrected signed comparison v4 ^ v5. [field:this:0x0000000C, source:raw]
    // CALCULATION: On a tie, locate each node's scene entry: v6 = dword_8AC490 + 396 * *this and v7 = dword_8AC490 + 396 * *a2, using the scene index stored at this+0x0 / a2+0x0. [field:this:0x00000000, global:0x008AC490, source:raw]
    // GUARD: If both scene entries v6 and v7 are non-null, compare the scene-name strings at entry offset 260 (0x104). [global:0x008AC490, source:raw]
    // CALL: sub_588410(v6 + 260, v7 + 260): lexicographic string comparison of the two scene names; returns true when the result is negative (this sorts before a2). [callee:0x00588410, source:raw]
    // ASSIGNMENT: When a scene entry is null, fall back to the node name strings: v9 = a2[1] or byte_5EA438 if a2[1] is null; v10 = this[1] or byte_5EA438 if this[1] is null. [field:this:0x00000004, global:0x005EA438, source:raw]
    // CALL: sub_588410(v10, v9): compare the fallback name strings; the result sign v11 decides the order. [callee:0x00588410, source:raw]
    // RETURN: Return the comparator result: v11 < 0 for the fallback path (v5 forced to 0, v4 = v11 < 0), or the overflow-corrected v4 ^ v5 for the primary path. [function:0x004C5D30, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[3]; v3 = a2[3];
    //   v5 = __OFSUB__(v2, v3); v4 = (v2 - v3) < 0;
    //   if (v2 == v3) {
    //       v6 = dword_8AC490 + 396 * *this;
    //       v7 = dword_8AC490 + 396 * *a2;
    //       if (v6 && v7)
    //           return (int)sub_588410(v6 + 260, v7 + 260) < 0;
    //       v9 = a2[1] ? a2[1] : byte_5EA438;
    //       v10 = this[1] ? this[1] : byte_5EA438;
    //       v11 = sub_588410(v10, v9);
    //       return v11 < 0;
    //   }
    //   return v4 ^ v5;
    // UNRESOLVED: The dword_8AC490 scene-array element layout (stride 396 = 0x18c, scene-name at offset 260 = 0x104) is DERIVED from existing_analysis prose plus the raw-source arithmetic; the packet carries no independent layout evidence.
    // UNRESOLVED: byte_5EA438's content (a default name/path substituted when a node has no name string) is unconfirmed; existing_analysis labels it DERIVED.
    // UNRESOLVED: sub_588410's exact semantics are inferred to be a strcmp-like comparison returning negative when the first string sorts before the second; only the '< 0' tests are evidenced.
    // UNRESOLVED: Whether the compared objects are filter-property nodes or scene entries, and the class owning `this`, are not established by the packet.
    // UNRESOLVED: The boolean return contract (true when this sorts before a2) is inferred from the two '< 0' result tests.
}
