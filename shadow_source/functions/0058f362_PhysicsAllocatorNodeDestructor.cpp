// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F362
// Canonical corpus name: sub_58F362
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58F362_0058f362.c

void UnknownObject::PhysicsAllocatorNodeDestructor()
{
    // Resource cleanup for a physics allocator node holding 43 sub-object pointer slots. Guards on the node pointer being non-null, then passes each of the 43 stored sub-object pointers (in a fixed, non-contiguous index order) to sub_58AA6F, a deallocation/release routine. Linear, branch-free after the null guard. Invoked by PhysicsAllocatorNodeInit (0058EF83).
    // GUARD: Guard on the node pointer a1 being non-null before any slots are released. [source:raw]
    // CALL: Release sub-object pointer slot a1[1] (this+0x4). [field:this:0x00000004, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[2] (this+0x8). [field:this:0x00000008, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[3] (this+0xC). [field:this:0x0000000C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[4] (this+0x10). [field:this:0x00000010, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[5] (this+0x14). [field:this:0x00000014, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[6] (this+0x18). [field:this:0x00000018, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[0] (this+0x0). [field:this:0x00000000, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[8] (this+0x20). [field:this:0x00000020, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[9] (this+0x24). [field:this:0x00000024, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[10] (this+0x28). [field:this:0x00000028, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[11] (this+0x2C). [field:this:0x0000002C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[12] (this+0x30). [field:this:0x00000030, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[13] (this+0x34). [field:this:0x00000034, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[7] (this+0x1C). [field:this:0x0000001C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[14] (this+0x38). [field:this:0x00000038, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[15] (this+0x3C). [field:this:0x0000003C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[16] (this+0x40). [field:this:0x00000040, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[17] (this+0x44). [field:this:0x00000044, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[18] (this+0x48). [field:this:0x00000048, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[19] (this+0x4C). [field:this:0x0000004C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[20] (this+0x50). [field:this:0x00000050, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[21] (this+0x54). [field:this:0x00000054, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[22] (this+0x58). [field:this:0x00000058, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[23] (this+0x5C). [field:this:0x0000005C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[24] (this+0x60). [field:this:0x00000060, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[25] (this+0x64). [field:this:0x00000064, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[26] (this+0x68). [field:this:0x00000068, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[27] (this+0x6C). [field:this:0x0000006C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[28] (this+0x70). [field:this:0x00000070, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[29] (this+0x74). [field:this:0x00000074, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[30] (this+0x78). [field:this:0x00000078, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[31] (this+0x7C). [field:this:0x0000007C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[32] (this+0x80). [field:this:0x00000080, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[33] (this+0x84). [field:this:0x00000084, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[34] (this+0x88). [field:this:0x00000088, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[35] (this+0x8C). [field:this:0x0000008C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[36] (this+0x90). [field:this:0x00000090, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[37] (this+0x94). [field:this:0x00000094, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[38] (this+0x98). [field:this:0x00000098, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[39] (this+0x9C). [field:this:0x0000009C, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[40] (this+0xA0). [field:this:0x000000A0, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[41] (this+0xA4). [field:this:0x000000A4, callee:0x0058AA6F, source:raw]
    // CALL: Release sub-object pointer slot a1[42] (this+0xA8), the last slot. [field:this:0x000000A8, callee:0x0058AA6F, source:raw]
    // CALL: Invoked by PhysicsAllocatorNodeInit (0058EF83) as the teardown counterpart of node allocation. [caller:0x0058EF83, source:raw]

    // Conservative worker pseudocode:
    //   void sub_58F362(LPVOID *a1) {
    //     if (!a1) return;
    //     sub_58AA6F(a1[1]); sub_58AA6F(a1[2]); sub_58AA6F(a1[3]); sub_58AA6F(a1[4]);
    //     sub_58AA6F(a1[5]); sub_58AA6F(a1[6]); sub_58AA6F(a1[0]); sub_58AA6F(a1[8]);
    //     sub_58AA6F(a1[9]); sub_58AA6F(a1[10]); sub_58AA6F(a1[11]); sub_58AA6F(a1[12]);
    //     sub_58AA6F(a1[13]); sub_58AA6F(a1[7]); sub_58AA6F(a1[14]); sub_58AA6F(a1[15]);
    //     sub_58AA6F(a1[16]); sub_58AA6F(a1[17]); sub_58AA6F(a1[18]); sub_58AA6F(a1[19]);
    //     sub_58AA6F(a1[20]); sub_58AA6F(a1[21]); sub_58AA6F(a1[22]); sub_58AA6F(a1[23]);
    //     sub_58AA6F(a1[24]); sub_58AA6F(a1[25]); sub_58AA6F(a1[26]); sub_58AA6F(a1[27]);
    //     sub_58AA6F(a1[28]); sub_58AA6F(a1[29]); sub_58AA6F(a1[30]); sub_58AA6F(a1[31]);
    //     sub_58AA6F(a1[32]); sub_58AA6F(a1[33]); sub_58AA6F(a1[34]); sub_58AA6F(a1[35]);
    //     sub_58AA6F(a1[36]); sub_58AA6F(a1[37]); sub_58AA6F(a1[38]); sub_58AA6F(a1[39]);
    //     sub_58AA6F(a1[40]); sub_58AA6F(a1[41]); sub_58AA6F(a1[42]);
    //   }
    // UNRESOLVED: The behavior of sub_58AA6F is not visible from this packet; it is only known to be called once per slot and to accept each sub-object pointer.
    // UNRESOLVED: The slot indices are visited in a fixed order that differs from array order (indices 0..6 are called before index 7, index 7 before 8); whether this order is semantically meaningful is unknown.
    // UNRESOLVED: The owning class and the meaning of the 43 slots (0x0..0xA8) are unknown; the caller name PhysicsAllocatorNodeInit is a skeleton-fill label, not a confirmed class.
}
