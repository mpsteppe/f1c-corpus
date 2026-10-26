// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499DA0
// Canonical corpus name: TreeNodeRecursiveDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TreeNodeRecursiveDestructor_00499da0.c

void UnknownObject::TreeNodeRecursiveDestructor()
{
    // Recursive tree-node destructor. Selects the node-pointer slot: the caller-supplied a2, or the default this+0x8 slot when a2 is null. If the node pointer in that slot is non-null it recursively destroys both child nodes (offsets 0x28 and 0x24), runs ConditionalDualCleanup on the node, frees it via FreeWrapper_7bcf and captures that as the result. Afterwards the node slot is cleared to 0 and this+0xC is zeroed, then the FreeWrapper result is returned.
    // GUARD: Slot selection: when a2 is null the node pointer is taken from the default slot at this+0x8 [field:this:0x00000008, source:raw]
    // GUARD: Read the node pointer v4 from the selected slot; recursive destruction runs only when it is non-null [field:this:0x00000008, source:raw]
    // CALL: Recursive call destroying the first child node pointer at node offset 0x28 (dword index 10) [callee:0x00499DA0, source:raw]
    // CALL: Recursive call destroying the second child node pointer at node offset 0x24 (dword index 9) [callee:0x00499DA0, source:raw]
    // CALL: ConditionalDualCleanup invoked on the node to release two node-owned resources [callee:0x00499B50, source:raw]
    // CALL: FreeWrapper_7bcf frees the node block; its return value becomes the function result [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Selected node-pointer slot cleared to 0 after the node is freed [field:this:0x00000008, source:raw]
    // ASSIGNMENT: this+0xC zeroed unconditionally at the end of the destructor [field:this:0x0000000C, source:raw]
    // RETURN: Returns the FreeWrapper_7bcf result (or the uninitialized result variable when the node pointer was null) [source:raw]

    // Conservative worker pseudocode:
    //   DWORD** v2 = a2 ? a2 : (DWORD**)(this + 2);  // default slot this + 0x8
    //   DWORD* v4 = *v2;
    //   if (v4) {
    //       TreeNodeRecursiveDestructor(v4 + 10);   // child node at offset 0x28
    //       TreeNodeRecursiveDestructor(v4 + 9);    // child node at offset 0x24
    //       ConditionalDualCleanup(v4);
    //       result = FreeWrapper_7bcf(v4);
    //   }
    //   *v2 = 0;
    //   this[3] = 0;                               // this + 0xC
    //   return result;
    // UNRESOLVED: The child-node offsets 0x28 and 0x24 are dereferenced as DWORD* targets of the recursive destructor, so they are interpreted as child-node pointers but their exact roles (left/right sibling vs parent/child) are not established
    // UNRESOLVED: ConditionalDualCleanup's two released resources are not identifiable from this packet
    // UNRESOLVED: The null-node path returns an uninitialized result value
}
