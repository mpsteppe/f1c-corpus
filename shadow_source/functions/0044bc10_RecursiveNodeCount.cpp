// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044BC10
// Canonical corpus name: RecursiveNodeCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveNodeCount_0044bc10.c

void UnknownObject::RecursiveNodeCount()
{
    // Self-recursive count of nodes produced by a halving decomposition. For a1 < 3 the function returns 1 when a1 is positive and 0 otherwise; for a1 >= 3 it returns 1 plus the counts of the two halves (a1 / 2 and a1 - a1 / 2). The result is a node/partition count rather than a value computation.
    // GUARD: Base-case guard on a1 < 3; below that threshold no recursion happens. [source:raw]
    // RETURN: Return a1 > 0 in the base case (1 for a1 of 1 or 2, 0 for a1 <= 0). [source:raw]
    // CALL: Recursive call for the upper remainder: v2 = RecursiveNodeCount(a1 - a1 / 2). [source:raw, callee:0x0044BC10]
    // CALL: Recursive call for the lower half: RecursiveNodeCount(a1 / 2). [source:raw, callee:0x0044BC10]
    // CALCULATION: Combine both recursive results plus one: v2 + RecursiveNodeCount(a1 / 2) + 1. [source:raw]
    // RETURN: Return the combined sum as the node count for this size. [source:raw]

    // Conservative worker pseudocode:
    //   int RecursiveNodeCount(int n) {
    //     if (n < 3) return n > 0;
    //     return RecursiveNodeCount(n - n / 2) + RecursiveNodeCount(n / 2) + 1;
    //   }
    // UNRESOLVED: The semantics of the counted nodes (e.g. nodes of a binary/halving tree or hierarchy elements) depend on the caller sub_44BC50 and are unconfirmed here.
}
