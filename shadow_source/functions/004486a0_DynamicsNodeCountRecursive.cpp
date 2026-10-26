// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004486A0
// Canonical corpus name: DynamicsNodeCountRecursive
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynamicsNodeCountRecursive_004486a0.c

void UnknownObject::DynamicsNodeCountRecursive()
{
    // Recursively counts the nodes of a spatial tree. Initializes a counter to 1 for the current node, then walks a four-element child-pointer array beginning at offset 0x4C, recursing into each non-null child, and finally recurses into the extra child pointer at this[23] (offset 0x5C) when non-null. Returns the accumulated node count.
    // ASSIGNMENT: Initialize the node counter to 1, counting the current node itself. [source:raw]
    // LOOP: Iterate four times over child pointers starting at this + 19 (offset 0x4C); null children are skipped. [field:this:0x0000004C, source:raw]
    // GUARD: If the child pointer at the current slot is non-null, recurse into that child subtree. [field:this:0x0000004C, source:raw]
    // CALL: Recursive call to DynamicsNodeCountRecursive for the non-null child, adding its subtree count to the accumulator. [callee:0x004486A0, source:raw]
    // GUARD: If the extra child pointer at this[23] (offset 0x5C) is non-null, recurse once more into it. [field:this:0x0000005C, source:raw]
    // CALL: Recursive call to DynamicsNodeCountRecursive for the extra child when the guard holds. [callee:0x004486A0, source:raw]
    // RETURN: Return the total accumulated node count. [source:raw]

    // Conservative worker pseudocode:
    //   count = 1;
    //   v3 = this + 19;
    //   v4 = 4;
    //   do {
    //       if (*v3) count += DynamicsNodeCountRecursive();
    //       ++v3; --v4;
    //   } while (v4);
    //   if (this[23]) count += DynamicsNodeCountRecursive();
    //   return count;
    // UNRESOLVED: The three remaining child-pointer slots between 0x4C and 0x5C are implied by the four-iteration loop but have no separate packet evidence refs.
    // UNRESOLVED: The recursion is shown with implicit this (no explicit argument in the raw source), so it is assumed to recurse on the same node pointer; the exact child-object relationship is not independently proven.
    // UNRESOLVED: Termination depends on the tree shape; no depth bound or cycle protection is evidenced.
}
