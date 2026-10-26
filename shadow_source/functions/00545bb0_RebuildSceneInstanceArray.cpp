// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545BB0
// Canonical corpus name: SceneInstanceCollection
// Owner: SceneInstanceCollection [DERIVED]
// Raw source: functions/SceneInstanceCollection_00545bb0.c

void SceneInstanceCollection::RebuildSceneInstanceArray()
{
    // Rebuilds a filtered array of 24-byte scene-instance entries on 'this'. When the entry count at this+0x174 is positive, frees the previous length-prefixed array at this+0x178 (per-element teardown via EmptyStub_0170, then FreeWrapper_7bcf), allocates a fresh length-prefixed array sized for the count, initializes each slot via ShortComputation_8e00, then walks two node lists (heads at this+0x100 and this+0x108). Nodes whose chain contains a sub-node carrying flag 0x20000 are appended into the array; nodes with the 0x40 flag at offset 4 are skipped. Always returns 0.
    // GUARD: Only rebuild when the entry count at this+0x174 is positive. [field:this:0x00000174, guard:0]
    // GUARD: Proceed with freeing only when the existing array pointer at this+0x178 is non-null. [field:this:0x00000178]
    // LOOP: Walk the previous length-prefixed array (element count read from the dword preceding the array base) and run EmptyStub_0170 on each element. [callee:0x004B0170, source:raw]
    // CALL: Free the previous length-prefixed array block with FreeWrapper_7bcf. [callee:0x00587BCF]
    // CALL: Allocate a new length-prefixed array of 24-byte entries plus a 4-byte length header via OperatorNewNhMallocWrapper(24 * count + 4), and store the count in the header. [callee:0x00587C03]
    // LOOP: Initialize each 24-byte entry slot by stepping 6 dwords and calling ShortComputation_8e00 on each. [callee:0x00548E00]
    // ASSIGNMENT: Store the new array pointer at this+0x178 (this[94]). [field:this:0x00000178]
    // LOOP: Walk the first node list from its head at this+0x100, following the forward link at node+260 for each node. [field:this:0x00000100, field:*(this+0x204):0x00000104]
    // GUARD: Skip a node when the byte flags at node+4 contain bit 0x40. [field:*(this+0x204):0x00000004]
    // LOOP: For a non-skipped node, walk its sub-list starting at the sub-list head pointer (node+236, hex 0xEC), chaining through the sub-node next pointer at offset 76 (0x4C). [field:*(this+0x204):0x000000EC, field:*(*(this+0x204)+0xEC):0x00000204, field:*(*(*(this+0x204)+0xEC)+0x4C):0x0000004C]
    // LOOP: Within each sub-node, follow the chain from its head at offset 516, stepping the forward link at chain+16 until a chain node with flag 0x20000 at chain+20 is found (a missing chain head is skipped). [field:*(*(*(*(this+0x204)+0xEC)+0x204)+0x10):0x00000010, field:*(*(*(*(this+0x204)+0xEC)+0x204)+0x10):0x00000014]
    // ASSIGNMENT: Append a matching sub-node into the filtered array at this+0x178 + 16 + 24 * appendedCount. [field:this:0x00000178, source:raw]
    // LOOP: Walk the second node list from its head at this+0x108, chaining through the next pointer at offset 76 (0x4C), using the sub-chain path anchored at this+0x30C and this+0x154. [field:this:0x00000108, field:*(this+0x154):0x0000004C, field:*(*(this+0x30C)+0x10):0x00000010, field:*(*(this+0x30C)+0x10):0x00000014, field:this:0x0000030C]
    // ASSIGNMENT: For the second list, likewise walk the chain from the node offset-516 head, matching flag 0x20000 at chain+20, and append matching nodes into the filtered array. [source:raw]
    // RETURN: Return 0 on completion. [source:raw]

    // Conservative worker pseudocode:
    //   int RebuildSceneInstanceArray(SceneInstanceCollection *this) {
    //     if (this->entryCount > 0) {
    //       if (this->array) {
    //         for (i = 0; i < *(this->array - 1); ++i) EmptyStub_0170(&this->array[i]);
    //         FreeWrapper_7bcf(this->array - 1);
    //       }
    //       block = Alloc(24 * this->entryCount + 4);
    //       *block = this->entryCount;
    //       this->array = block + 1;
    //       for (i = 0; i < this->entryCount; ++i) ShortComputation_8e00(&this->array[i]);
    //       n = 0;
    //       for (node = this->firstHead; node; node = node->next260) {
    //         if (node->flags4 & 0x40) continue;
    //         for (sub = node->subList236; sub; sub = sub->next76) {
    //           for (chain = sub->chain516; chain; chain = chain->link16) {
    //             if (chain->flags20 & 0x20000) { this->array[n].owner = sub; ++n; break; }
    //           }
    //         }
    //       }
    //       for (node = this->secondHead; node; node = node->next76) {
    //         for (chain = node->chain516; chain; chain = chain->link16) {
    //           if (chain->flags20 & 0x20000) { this->array[n].owner = node; ++n; break; }
    //         }
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The extraction-listed field paths rooted at this+0x204, this+0x30C and this+0x154 are indirect readings that do not map one-to-one onto the raw C node traversal offsets (260, 236, 516, 76); the exact object graph is unconfirmed.
    // UNRESOLVED: Whether flag 0x20000 selects renderable instances or some other per-chain visibility class is unknown.
    // UNRESOLVED: EmptyStub_0170 and ShortComputation_8e00 identity and purpose are not resolved from this packet.
}
