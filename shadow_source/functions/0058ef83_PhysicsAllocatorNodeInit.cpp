// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058EF83
// Canonical corpus name: PhysicsAllocatorNodeInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsAllocatorNodeInit_0058ef83.c

void UnknownObject::PhysicsAllocatorNodeInit()
{
    // Initializes a single allocator/exception-handler node tracked by global dword_8D3F58, with two paths selected by global dword_8D3F44. When dword_8D3F44 is nonzero: allocate a 172-byte zeroed block via sub_58AB58(1, 172); if the allocation fails return 1; if sub_58F014(v0) reports initialization failure, finalize the node (sub_58F362), free it (sub_58AA6F), and return 1; otherwise install the block as the IO function pointer off_5E99D0, finalize and free the old tracked node dword_8D3F58, and store the new block in dword_8D3F58. When dword_8D3F44 is zero: set off_5E99D0 to the default callback pointer off_5E99D8, finalize and free the old tracked node dword_8D3F58, and clear dword_8D3F58 to 0. Returns 0 on success in both paths.
    // GUARD: Branch on global dword_8D3F44: nonzero selects the allocate-and-install path, zero selects the default-callback path. [global:0x008D3F44, source:raw]
    // CALL: Allocate a zero-initialized 172-byte block with sub_58AB58(1, 172); store it as the new node. [callee:0x0058AB58, source:raw]
    // GUARD: If the allocation returned null, return 1 (failure) without touching the tracked node. [callee:0x0058AB58, source:raw]
    // CALL: Initialize the new node via sub_58F014(v0); a nonzero return marks node initialization as failed. [callee:0x0058F014, source:raw]
    // CALL: On initialization failure: finalize the node via sub_58F362(v1), free the node block via sub_58AA6F(v1), and return 1. [callee:0x0058F362, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Install the new node as the IO function pointer: off_5E99D0 = v1. [global:0x005E99D0, source:raw]
    // CALL: Finalize the old tracked node dword_8D3F58 via sub_58F362, then free it via sub_58AA6F. [global:0x008D3F58, callee:0x0058F362, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Store the new node as the tracked node: dword_8D3F58 = v1. [global:0x008D3F58, source:raw]
    // ASSIGNMENT: Default-callback path: set the IO function pointer to the default callback global off_5E99D8: off_5E99D0 = off_5E99D8. [global:0x005E99D0, global:0x005E99D8, source:raw]
    // CALL: Finalize and free the old tracked node dword_8D3F58 on the default-callback path as well. [global:0x008D3F58, callee:0x0058F362, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Clear the tracked node: dword_8D3F58 = 0 on the default-callback path. [global:0x008D3F58, source:raw]
    // RETURN: Both successful paths return 0; only the failed-allocation and failed-init branches return 1. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3F44) {
    //       node = sub_58AB58(1, 172);
    //       if (!node) return 1;
    //       if (sub_58F014(node)) {
    //           sub_58F362(node);
    //           sub_58AA6F(node);
    //           return 1;
    //       }
    //       off_5E99D0 = node;
    //       sub_58F362(dword_8D3F58);
    //       sub_58AA6F(dword_8D3F58);
    //       dword_8D3F58 = node;
    //   } else {
    //       off_5E99D0 = off_5E99D8;
    //       sub_58F362(dword_8D3F58);
    //       sub_58AA6F(dword_8D3F58);
    //       dword_8D3F58 = 0;
    //   }
    //   return 0;
    // UNRESOLVED: The identity of the object installed at off_5E99D0 and dword_8D3F58 is not evidenced by the packet; the fills read it as a physics allocator node / CRT exception handler chain, which is DERIVED only.
    // UNRESOLVED: The semantics of sub_58F014's return value (nonzero reported as initialization failure) and the 172-byte node layout are not evidenced in this packet.
    // UNRESOLVED: The finalize step sub_58F362 (run before freeing the old node) and why the default-callback path clears the tracked node are not explained by the packet.
    // UNRESOLVED: Global dword_8D3F44 is read as a CRT-DLL switch by the fills; the packet only evidences the branch on its value.
}
