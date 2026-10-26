// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004486E0
// Canonical corpus name: BVHTreeLinearize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BVHTreeLinearize_004486e0.c

void UnknownObject::BVHTreeLinearize()
{
    // Recursively flattens a tree into a contiguous output array. Stores the current node pointer at out[a3], records the output index a3 into this[18] (offset 0x48), then recurses over up to four consecutive child pointers beginning at offset 0x4C (skipping null children) and finally over one extra child at offset 0x5C if non-null. Returns the next free output index.
    // ASSIGNMENT: Write the output index a3 into this[18] (offset 0x48), recording where this node was placed. [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Store the current node pointer at out[a3] in the output array, and compute the next output index as a3 + 1. [source:raw]
    // LOOP: Iterate four times over child pointers starting at offset 0x4C; null children are skipped. [field:this:0x0000004C, source:raw]
    // GUARD: If the child pointer at the current cursor position is non-null, recurse into that child subtree. [field:this:0x0000004C, callee:0x004486E0, source:raw]
    // CALL: Recursive call to linearize the child subtree into the remaining output slots, threading the running output index. [callee:0x004486E0, source:raw]
    // GUARD: If the extra child pointer at this[23] (offset 0x5C) is non-null, recurse once more into it. [field:this:0x0000005C, source:raw]
    // CALL: Recursive call to linearize the extra child subtree when the guard holds. [callee:0x004486E0, source:raw]
    // RETURN: Return the final next free output index. [source:raw]

    // Conservative worker pseudocode:
    //   this[18] = a3;
    //   out[a3] = this;
    //   result = a3 + 1;
    //   for (v6 = 4, v5 = this + 19; v6; --v6, ++v5)
    //       if (*v5) result = BVHTreeLinearize(out, result);
    //   if (this[23]) result = BVHTreeLinearize(out, result);
    //   return result;
    // UNRESOLVED: Child pointer offsets 0x50, 0x54 and 0x58 (the remaining three loop slots) have no packet evidence reference; they are implied by the four-iteration loop beginning at 0x4C.
    // UNRESOLVED: Whether the traversal order is pre-order and what the flattened array is later used for is DERIVED from existing analysis, not independently proven.
}
