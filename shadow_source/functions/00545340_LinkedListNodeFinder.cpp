// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545340
// Canonical corpus name: LinkedListNodeFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeFinder_00545340.c

void UnknownObject::LinkedListNodeFinder()
{
    // Returns the node at index a2 across two hierarchical singly-linked lists. When the first-list head at this+0x100 is non-null, walks each node's sub-list (sub-list head at node+236, forward links at +76), advancing to the next first-list node through the +260 link when a sub-list runs out. When the first list is empty or exhausted, falls back to a second list headed at this+0x108, walking +76 forward links. Returns the node at index a2, or 0 when the index exceeds the reachable node count.
    // GUARD: Load the first-list head from this+0x100; when it is non-null traverse the first list plus its per-node sub-lists, otherwise skip directly to the second list at this+0x108. [field:this:0x00000100]
    // ASSIGNMENT: Start the index counter v3 at 0. [source:raw]
    // LOOP: Walk the first list: at each node read the sub-list head at node+236; when it is non-null descend into it, otherwise advance v2 to the next first-list node through the forward link at node+260. [field:*(this+0x204):0x00000104, source:raw]
    // LOOP: Walk a sub-list: while the index counter differs from a2, advance to the next sub-node through the forward link at +76 and increment the counter; a null sub-node falls back to the next first-list node. [field:*(*(this+0x1EC)+0x4C):0x0000004C, source:raw]
    // LOOP: Walk the second list starting at this+0x108, following forward links at +76 and incrementing the counter, stopping when the counter equals a2 or the list ends. [field:this:0x00000108, field:*(this+0x154):0x0000004C, source:raw]
    // RETURN: Return the node pointer at index a2, or 0 when the index exceeds the reachable nodes. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeFinder(void* this, int index) {
    //     node = this[64];                    // this+0x100 first-list head
    //     counter = 0;
    //     if (!node) goto secondList;
    //   nextNode:
    //     while (true) {
    //       sub = *(node + 236);              // sub-list head
    //       if (sub) break;
    //       node = *(node + 260);             // next first-list node
    //       if (!node) goto secondList;
    //     }
    //     while (index != counter) {
    //       sub = *(sub + 76);                // next sub-node
    //       ++counter;
    //       if (!sub) goto nextNode;
    //     }
    //     return sub;
    //   secondList:
    //     for (sub = this[66]; sub; ++counter) {   // this+0x108 second-list head
    //       if (index == counter) break;
    //       sub = *(sub + 76);
    //     }
    //     return sub;
    //   }
    // UNRESOLVED: The raw source traverses node-relative offsets 236 (sub-list head), 260 (next first-list node) and 76 (forward link), but the packet field table expresses the same links with different extraction-derived bases (this+0x1EC, this+0x154, this+0x204); only this+0x100 and this+0x108 align exactly.
    // UNRESOLVED: field:this:0x000001EC has no counterpart in the raw source text.
    // UNRESOLVED: The owning object type is unknown; caller-side labels (audio network / animation / scene) are not evidence of this object's class.
}
