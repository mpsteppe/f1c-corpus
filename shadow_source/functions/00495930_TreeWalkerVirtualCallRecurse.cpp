// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495930
// Canonical corpus name: TreeWalkerVirtualCallRecurse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TreeWalkerVirtualCallRecurse_00495930.c

void UnknownObject::TreeWalkerVirtualCallRecurse()
{
    // Recursively walks a linked tree of nodes: rejects a NULL root with -1, then for each node invokes a virtual per-node callback (function pointer at vtable offset +160), recurses into the child subtree at dword index 36 (byte offset 0x90), and advances along the sibling chain. Returns 0 after a full traversal.
    // GUARD: Reject a NULL root: when a1 is NULL return -1. [source:raw]
    // CALL: Invoke the virtual per-node callback whose function pointer is stored at vtable offset +160 (0xA0) on the current node v1. [field:this:0x00000000, field:obj:0x000000A0, source:raw]
    // CALL: Recurse into the child subtree at dword index 36 (byte offset 0x90) of the current node. [field:this:0x00000090, callee:0x00495930, source:raw]
    // LOOP: Advance to the next sibling: set v1 = v1[35] and continue the walk while v1 is non-NULL. [source:raw]
    // RETURN: Return 0 after the full traversal completes. [source:raw]

    // Conservative worker pseudocode:
    //   int TreeWalkerVirtualCallRecurse(_DWORD *a1) {
    //     if (!a1)
    //       return -1;
    //     _DWORD *v1 = a1;
    //     do {
    //       (*(void (__thiscall **)(_DWORD *))(*v1 + 160))(v1);
    //       TreeWalkerVirtualCallRecurse(v1[36]);
    //       v1 = (_DWORD *)v1[35];
    //     } while (v1);
    //     return 0;
    //   }
    // UNRESOLVED: Packet lists a read at this+0x118 that is not present in the raw source (the raw source advances the walk via dword index 35); its role here is unknown.
    // UNRESOLVED: Node object type and the semantics of the virtual callback at vtable offset +160 are unidentified.
}
