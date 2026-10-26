// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551560
// Canonical corpus name: sub_551560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_551560_00551560.c

void UnknownObject::AnimationNodeCreateFromDataBlocks()
{
    // Creates a new node in a singly-linked node list anchored at this+0x13C, sizes its element/data-block array from the count at this+0x130, copies 136-byte source blocks from this+0x134, resolves each block's name against a parameter table (a2) so matched blocks store the table entry value and unmatched blocks store -1, stores the parameter table pointer on the node, and runs the sub-init chain via EntityFlagSetSubInitChain. On a null data-block count a single-element node is produced instead.
    // GUARD: Gates on the data-block count at this+0x130: a non-zero count takes the multi-block copy path, a zero count takes the single-element node path. [field:this:0x00000130, guard:0, source:raw]
    // LOOP: Walks the existing node list anchored at this+0x13C, following next pointers at +0x24 (including the chains expressed via this+0x160), to reach the tail before appending the new node. [field:this:0x0000013C, field:this:0x00000160, field:*(*(this+0x160)+0x24):0x00000024, field:*(*(*(*(this+0x160)+0x24)+0x24)+0x24):0x00000024, source:raw]
    // CALL: Allocates a 40-byte node with OperatorNewNhMallocWrapper(40); a null result leaves the node pointer null. [callee:0x00587C03, source:raw]
    // CALL: Initializes the fresh node with sub_5510F0(node, blockCount) so its element array is sized for the data-block count (or for 1 on the single-element path). [callee:0x005510F0, field:this:0x00000130, source:raw]
    // ASSIGNMENT: Appends the new node to the list: when a head exists at this+0x13C the tail's +0x24 next pointer becomes the new node; otherwise this+0x13C becomes the new node (and is cleared on allocation failure). [field:this:0x0000013C, field:*(*(this+0x160)+0x24):0x00000024, callee:0x005510F0, source:raw]
    // ASSIGNMENT: Copies the source data blocks from this+0x134 into the new node's block array, 136 bytes per block for the count at this+0x130, and stores the count into the node's block-count field. [field:this:0x00000134, field:this:0x00000130, source:raw]
    // LOOP: For each copied block (stride 136), compares the block name at block+68 against parameter-table entries in a2 (entry count at a2+12, entries at a2+16, entry stride 44); on a match stores the table entry value from entry+32 into the block's first dword, otherwise writes -1. [field:this:0x00000130, source:raw]
    // ASSIGNMENT: Stores the parameter table pointer a2 into the new node at node+0x1C. [source:raw]
    // CALL: Calls EntityFlagSetSubInitChain on the new node to run the sub-init chain (flags, data copy, timer start). [callee:0x00551440, source:raw]
    // RETURN: Returns 0. [function:0x00551560, source:raw]

    // Conservative worker pseudocode:
    //   int AnimationNodeCreateFromDataBlocks(owner* this, table* a2) {
    //     node* tail = walk_to_tail(this->listHead);
    //     node* n = OperatorNewNhMallocWrapper(40);
    //     if (n) n = sub_5510F0(n, this->blockCount ? this->blockCount : 1);
    //     append(tail, this->listHead, n);
    //     if (this->blockCount) {
    //       n->blockCount = this->blockCount;
    //       memcpy(n->blocks, this->srcBlocks, 136 * this->blockCount);
    //       for (i = 0; i < this->blockCount; i++) {
    //         n->blocks[i].first = resolve_name(a2, n->blocks[i].name); // entry+32 else -1
    //       }
    //     } else {
    //       n->blockCount = 1; n->blocks[0].first = 0;
    //     }
    //     n->paramTable = a2;
    //     EntityFlagSetSubInitChain(n);
    //     return 0;
    //   }
    // UNRESOLVED: The decompiled body walks the list from this[79] (this+0x13C), while the packet's deep list-field bases are expressed via this+0x160 chains; the exact relationship between the two object paths is not resolvable from this packet.
    // UNRESOLVED: The parameter-table layout (a2: count at +12, entries at +16, stride 44, name compare at block+68) is evidenced only by the raw source; no field evidence refs describe it.
    // UNRESOLVED: The node block-array pointer and the 136-byte block stride are derived from raw source only.
}
