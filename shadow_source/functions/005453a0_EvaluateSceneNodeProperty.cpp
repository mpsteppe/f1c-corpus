// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005453A0
// Canonical corpus name: EvaluateSceneNodeProperty
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EvaluateSceneNodeProperty_005453a0.c

void UnknownObject::EvaluateSceneNodeProperty()
{
    // Evaluates a scene-node property by recursive string search. When the flag a3 is non-zero, searches the supplied tree a2 directly via RecursiveTreeStringSearch. Otherwise walks the first node chain (head at this+0x100), probing a sub-node at each element offset 236 and calling the recursive search when present, advancing through the forward link at element offset 260, and falls back to the second chain head at this+0x108 when the first chain ends. Returns the first matched value, or 0 when nothing matches.
    // ASSIGNMENT: Initialize result = 0 and the search output slot v6 = 0 before any branching. [source:raw]
    // GUARD: Guard on a3: when non-zero, skip chain iteration and search the supplied tree a2 directly. [source:raw]
    // CALL: Call RecursiveTreeStringSearch(a2, &v6), which writes the matched value into v6; reached from both the direct path and the chain-fallback path. [source:raw, callee:0x0054BC60]
    // RETURN: Return v6 when the direct search path was taken. [source:raw]
    // ASSIGNMENT: Load v5 = this[64] (first list head at byte offset 0x100). [source:raw, field:this:0x00000100]
    // GUARD: Guard on this[64]: when the first list head at 0x100 is null, skip to the second-list fallback. [source:raw, field:this:0x00000100]
    // LOOP: while (!result): iterate the first node chain until a match is found or the chain ends. [source:raw]
    // GUARD: Guard on the sub-node at element offset 236: when non-null, run RecursiveTreeStringSearch(a2, &v6) and store the result in result. [source:raw, callee:0x0054BC60]
    // ASSIGNMENT: Advance to the next chain element: v5 = *(v5 + 260), the forward link at offset 0x104 of the element (extracted as base *(this+0x204), offset 0x104). [source:raw, field:*(this+0x204):0x00000104]
    // GUARD: Guard on v5 becoming null (chain end): if a result is already stored, return it; otherwise fall through to the second-list path. [source:raw]
    // GUARD: Guard on this[66] (second list head at byte offset 0x108): when null, return the current result (0); otherwise search the second list recursively. [source:raw, field:this:0x00000108]
    // RETURN: Return the accumulated result (matched value or 0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5453A0(DWORD *this, int tree, int useDirect) {
    //     int result = 0;
    //     int out = 0;
    //     if (useDirect) { RecursiveTreeStringSearch(tree, &out); return out; }
    //     int node = this[0x100 / 4];
    //     while (node) {
    //       if (*(DWORD *)(node + 236)) { RecursiveTreeStringSearch(tree, &out); result = out; }
    //       node = *(DWORD *)(node + 260);
    //       if (!node) { if (result) return result; break; }
    //     }
    //     if (this[0x108 / 4]) { RecursiveTreeStringSearch(tree, &out); return out; }
    //     return result;
    //   }
    // UNRESOLVED: Purpose and identity of the object owning the two chain heads (this+0x100, this+0x108) is unknown; callers span vehicle scene load, steward lighting, and graphics scene paths.
    // UNRESOLVED: field:this:0x000001EC has no grounded use in the raw source; recorded as extracted evidence only.
    // UNRESOLVED: Semantics of the tree argument a2 and the matched value written through &v6 depend on the caller's scene-tree layout.
}
