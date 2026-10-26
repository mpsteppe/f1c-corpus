// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004499E0
// Canonical corpus name: CollisionGlobalStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalStateReset_004499e0.c

void UnknownObject::CollisionGlobalStateReset()
{
    // Resets the collision subsystem's global root state: clears the 8-byte collision global double at 0x007C9360 to 0.0, then runs collision tree node cleanup over the same global base, returning the cleanup result. Free function with no object context.
    // ASSIGNMENT: Write 0.0 into dbl_7C9360[0], the 8-byte collision-global double at 0x007C9360, resetting the collision state root. [global:0x007C9360, source:raw]
    // CALL: Call CollisionTreeNodeCleanup with the collision-tree global base (int)dbl_7C9360 to tear down the tree nodes. [source:raw]
    // RETURN: Return the CollisionTreeNodeCleanup result. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalStateReset() {
    //     dbl_7C9360[0] = 0.0;
    //     return CollisionTreeNodeCleanup((int)dbl_7C9360);
    //   }
    // UNRESOLVED: byte_7C9364 (at 0x007C9364, immediately inside the dbl_7C9360 range) is listed as written by this function in the fact table, but no separate byte write appears in the raw decompiler source; its exact role is unresolved.
    // UNRESOLVED: The static callee list for this packet does not name CollisionTreeNodeCleanup; the call is visible only in the raw source text.
}
