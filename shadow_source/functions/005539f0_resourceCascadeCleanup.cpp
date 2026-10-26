// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005539F0
// Canonical corpus name: ResourceCascadeCleanup
// Owner: ResourceCascadeCleanup [DERIVED]
// Raw source: functions/ResourceCascadeCleanup_005539f0.c

void ResourceCascadeCleanup::resourceCascadeCleanup()
{
    // Unlinks a resource node a1 from its doubly-linked list unconditionally, then, when a1 is non-null, runs a resource-specific cleanup handler and frees the node. Returns 0. Used by six cleanup paths across collision, audio, and resource subsystems.
    // CALL: Unlink the node a1 from its doubly-linked list via DoublyLinkedListNodeUnlinkByMatch (runs unconditionally). [callee:0x0055C2E0]
    // GUARD: If a1 is non-null, perform the resource cleanup and deallocation; the unlink already ran regardless. [source:raw]
    // CALL: Run the resource-specific cleanup/release handler ConditionalResourceCleanup_3310 on a1. [callee:0x00553310]
    // CALL: Free the node allocation via FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   UnlinkNode(a1);
    //   if (a1) {
    //       CleanupResource(a1);
    //       Free(a1);
    //   }
    //   return 0;
    // UNRESOLVED: The global dword_8B78A0 is marked read but does not appear in this function's raw source; its use is in a callee or elsewhere.
    // UNRESOLVED: What the node a1 points at and which resource type it belongs to is caller-dependent and not named in the packet.
}
