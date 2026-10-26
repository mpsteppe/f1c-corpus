// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F6FE
// Canonical corpus name: PhysicsAllocatorNodeInit_f6fe
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsAllocatorNodeInit_f6fe_0058f6fe.c

void UnknownObject::PhysicsAllocatorNodeInit_f6fe()
{
    // Initializes a 3-dword allocator node head stored at global off_5E9AC0, with two paths selected by global dword_8D3F3C. When dword_8D3F3C is nonzero: allocate a 48-byte zeroed block via sub_58AB58(1, 48); if the allocation fails return 1; if sub_58F7C9 initializes the new node and reports failure, free the node (MultiFieldFree_f8eb then sub_58AA6F) and return 1; otherwise copy the three dword fields of the current head off_5E9AC0 into the new node, install the new node as the head, free the old head dword_8D3F68, and store the new node in dword_8D3F68. When dword_8D3F3C is zero: copy the three head dword fields into a static 3-field sentinel at off_5E9A90/off_5E9A94/off_5E9A98, repoint off_5E9AC0 at the sentinel, free the old head dword_8D3F68, and clear dword_8D3F68 to 0. Returns 0 on success in both paths.
    // GUARD: Branch on global dword_8D3F3C: nonzero selects the dynamic-allocate path, zero selects the static-sentinel path. [global:0x008D3F3C, source:raw]
    // CALL: Allocate a zero-initialized 48-byte block with sub_58AB58(1, 48); store it as the new node. [callee:0x0058AB58, source:raw]
    // GUARD: If the allocation returned null, return 1 (failure) without touching the list. [callee:0x0058AB58, source:raw]
    // CALL: Initialize the new node via sub_58F7C9(v0); a nonzero return marks node initialization as failed. [callee:0x0058F7C9, source:raw]
    // CALL: On initialization failure: free the node's internal multi-fields via MultiFieldFree_f8eb(v1), free the node block via sub_58AA6F(v1), and return 1. [callee:0x0058F8EB, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Copy the three dword fields of the current head into the new node: v1[0..2] = off_5E9AC0[0..2]. [global:0x005E9AC0, source:raw]
    // ASSIGNMENT: Install the new node as the list head: off_5E9AC0 = v1. [global:0x005E9AC0, source:raw]
    // CALL: Free the old head dword_8D3F68: release its internal multi-fields via MultiFieldFree_f8eb, then free the block via sub_58AA6F. [global:0x008D3F68, callee:0x0058F8EB, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Store the new node as the tracked head: dword_8D3F68 = v1. [global:0x008D3F68, source:raw]
    // ASSIGNMENT: Static-sentinel path: copy the three head dword fields into the static sentinel off_5E9A90/off_5E9A94/off_5E9A98. [global:0x005E9AC0, global:0x005E9A90, global:0x005E9A94, global:0x005E9A98, source:raw]
    // ASSIGNMENT: Repoint the list head at the static sentinel: off_5E9AC0 = &off_5E9A90. [global:0x005E9AC0, global:0x005E9A90, source:raw]
    // CALL: Free the old head dword_8D3F68 (MultiFieldFree_f8eb then sub_58AA6F) on the static-sentinel path as well. [global:0x008D3F68, callee:0x0058F8EB, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Clear the tracked head: dword_8D3F68 = 0 on the static-sentinel path. [global:0x008D3F68, source:raw]
    // RETURN: Both successful paths return 0; only the failed-allocation and failed-init branches return 1. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3F3C) {
    //       node = sub_58AB58(1, 48);
    //       if (!node) return 1;
    //       if (sub_58F7C9(node)) {
    //           MultiFieldFree_f8eb(node);
    //           sub_58AA6F(node);
    //           return 1;
    //       }
    //       node[0] = off_5E9AC0[0]; node[1] = off_5E9AC0[1]; node[2] = off_5E9AC0[2];
    //       off_5E9AC0 = node;
    //       MultiFieldFree_f8eb(dword_8D3F68);
    //       sub_58AA6F(dword_8D3F68);
    //       dword_8D3F68 = node;
    //   } else {
    //       off_5E9A90 = off_5E9AC0[0]; off_5E9A94 = off_5E9AC0[1]; off_5E9A98 = off_5E9AC0[2];
    //       off_5E9AC0 = &off_5E9A90;
    //       MultiFieldFree_f8eb(dword_8D3F68);
    //       sub_58AA6F(dword_8D3F68);
    //       dword_8D3F68 = 0;
    //   }
    //   return 0;
    // UNRESOLVED: The three dword fields of the node head off_5E9AC0 are not named by the packet; the fills read them as locale-data pointers / an allocator chain, which is DERIVED only.
    // UNRESOLVED: The semantics of sub_58F7C9's return value (nonzero reported as initialization failure) and the internal structure freed by MultiFieldFree_f8eb are not evidenced in this packet.
    // UNRESOLVED: Global dword_8D3F3C is read as a mode switch (dynamic vs static sentinel) per the fills; the packet only evidences the branch on its value.
    // UNRESOLVED: off_5E9A90/off_5E9A94/off_5E9A98 form a static 3-field sentinel structure only in aggregate; the packet does not describe its layout.
}
