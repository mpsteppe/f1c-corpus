// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567CC0
// Canonical corpus name: sub_567CC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_567CC0_00567cc0.c

void UnknownObject::RecursiveTreeStructFree()
{
    // Recursive destructor for a tree-like node. Returns immediately when the node pointer a1 is NULL (recursion terminator), otherwise recurses into the three child pointers at offsets 0x4, 0x8 and 0xC, calls DualPointerCleanup on the current node, deallocates it through FreeWrapper_7bcf and returns that result. Called from F_9PointerArrayCleanup (0x00567F10).
    // GUARD: Guard on node pointer a1 being non-NULL; a NULL node is skipped, which terminates the recursion. [source:raw]
    // CALL: Recursively free the first child node stored at offset 0x4 of this. [field:this:0x00000004, callee:0x00567CC0]
    // CALL: Recursively free the second child node stored at offset 0x8 of this. [field:this:0x00000008, callee:0x00567CC0]
    // CALL: Recursively free the third child node stored at offset 0xC of this. [field:this:0x0000000C, callee:0x00567CC0]
    // CALL: Call DualPointerCleanup(this) to tear down the current node's internal data. [callee:0x00567940]
    // CALL: Call FreeWrapper_7bcf(this) to deallocate the current node. [callee:0x00587BCF]
    // RETURN: Return the result of FreeWrapper_7bcf, or the uninitialized local result when the NULL-node guard fired. [source:raw, callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   int sub_567CC0(_DWORD *node) {
    //     int result;
    //     if (node) {
    //       sub_567CC0(node[1]);
    //       sub_567CC0(node[2]);
    //       sub_567CC0(node[3]);
    //       DualPointerCleanup(node);
    //       return FreeWrapper_7bcf(node);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: When node is NULL the raw source returns the uninitialized local result; the caller F_9PointerArrayCleanup (0x00567F10) never observes it for live nodes.
    // UNRESOLVED: Identity of the tree type and the meaning of the three child pointers at offsets 0x4, 0x8, 0xC are not established here.
}
