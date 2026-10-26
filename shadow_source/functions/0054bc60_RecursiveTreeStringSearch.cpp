// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BC60
// Canonical corpus name: RecursiveTreeStringSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveTreeStringSearch_0054bc60.c

void UnknownObject::RecursiveTreeStringSearch()
{
    // Depth-first recursive search of a tree for a node whose base-address string equals a2. Recurses into the subtree at this+0x44, then the subtree at this+0x4C, then compares the current node's string via strcmp. Uses a3 as a found-flag pointer: the string comparison is skipped once *a3 is non-zero, and a matching node is stored into *a3.
    // GUARD: Guard on the first subtree pointer at this+0x44 being non-null before recursing into it. [field:this:0x00000044, source:raw]
    // CALL: Recursively search the first subtree (this+0x44) for the matching string. [field:this:0x00000044, callee:0x0054BC60, source:raw]
    // GUARD: Guard on the second subtree pointer at this+0x4C being non-null before recursing into it. [field:this:0x0000004C, source:raw]
    // CALL: Recursively search the second subtree (this+0x4C) for the matching string. [field:this:0x0000004C, callee:0x0054BC60, source:raw]
    // GUARD: Guard on the found-flag *a3 being unset and the current node's base string matching a2 via strcmp before recording the hit. [source:raw]
    // ASSIGNMENT: Record the matching node pointer into *a3 so later comparisons short-circuit. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_54BC60(int this, const char* a2, _DWORD* a3) {
    //     if (*(_DWORD*)(this + 68)) RecursiveTreeStringSearch(*(_DWORD*)(this + 68), a2, a3);
    //     if (*(_DWORD*)(this + 76)) RecursiveTreeStringSearch(*(_DWORD*)(this + 76), a2, a3);
    //     if (!*a3 && strcmp((const char*)this, a2) == 0) *a3 = this;
    //   }
    // UNRESOLVED: Tree node structure is unresolved; the string compared is the node base address itself, and the two subtree pointers at this+0x44 and this+0x4C are unnamed.
    // UNRESOLVED: The callers EvaluateSceneNodeProperty (005453a0) and ArithmeticComparison_9170 (00549170) were not analyzed; they may define the node and search semantics.
}
