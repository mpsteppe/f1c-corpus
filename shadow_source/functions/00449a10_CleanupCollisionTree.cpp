// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449A10
// Canonical corpus name: sub_449A10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_449A10_00449a10.c

void UnknownObject::CleanupCollisionTree()
{
    // Thin wrapper that forwards the double stored at global dbl_7C9360 into CollisionTreeNodeCleanup and returns its result. The function has no parameters, no guards, and no local side effects of its own.
    // CALL: Call CollisionTreeNodeCleanup with the value read from global dbl_7C9360 as its argument. [source:raw, global:0x007C9360]
    // RETURN: Return the result of CollisionTreeNodeCleanup directly. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_449A10() {
    //     return CollisionTreeNodeCleanup((int)dbl_7C9360);
    //   }
    // UNRESOLVED: The meaning of the global dbl_7C9360 passed to CollisionTreeNodeCleanup is unknown.
    // UNRESOLVED: What subtree the global identifies and when the cleanup is expected to run is outside this function.
}
