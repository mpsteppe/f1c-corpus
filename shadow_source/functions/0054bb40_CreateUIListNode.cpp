// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BB40
// Canonical corpus name: UIListNodeManager
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListNodeManager_0054bb40.c

void UnknownObject::CreateUIListNode()
{
    // Creates a 40-byte UI list node from a source template, initializes it via sub_5510F0 using template data at a2+0xC, and appends it to the scene's UI list-node chain. When the list head (this+0x214) is non-null the list is walked to the tail along node next pointers (node+0x24) and the new node is linked after it; otherwise the new node becomes the head. Fills the node item count (node+0x14) from the template and writes sequential indices into each item slot (stride 136) of the item array (node+0x18), registers the node with EntityFlagSetSubInitChain, stores the source template pointer in node+0x1C, collects rendering state via sub_557350, and conditionally calls sub_559200 when the this+0x218 flag is zero. Called by SceneNode (0055A910).
    // GUARD: Branch on the UI list head at this+0x214 (this[133]): when non-null walk the chain to its tail by following node next pointers (node+0x24); when null the new node will become the head. The packet models the chain anchor through the list-state container at this+0x238 [field:this:0x00000214, field:this:0x00000238, field:*(*(this+0x238)+0x24):0x00000024]
    // CALL: Allocate the 40-byte node with OperatorNewNhMallocWrapper and initialize it through sub_5510F0 with the template data at a2+0xC [callee:0x00587C03, callee:0x005510F0]
    // ASSIGNMENT: Link the new node into the chain: set the old tail node's next pointer (node+0x24) to the new node, or store the new node as the head (this+0x214) when the list was empty [field:*(*(this+0x238)+0x24):0x00000024, field:this:0x00000214]
    // ASSIGNMENT: Copy the item count from the template (a2+0xC) into the new node's count field (node+0x14) [source:raw]
    // LOOP: Write sequential indices 0,1,2,... into the new node's item array (node+0x18) with a stride of 136 bytes per item until the item count is reached [source:raw]
    // CALL: Register the new node through EntityFlagSetSubInitChain for entity flag initialization [callee:0x00551440]
    // ASSIGNMENT: Store the source template pointer (a2) in the new node's source field (node+0x1C) [source:raw]
    // CALL: sub_557350 collects rendering state into the local stack buffer [callee:0x00557350]
    // STATE_TRANSITION: Read the flag at this+0x218 (this[134]); when it is zero, call sub_559200 with the address of this[134] (dword index 134) and the collected state buffer to attach the node state [field:this:0x00000218, callee:0x00559200]
    // CALL: EmptyStub_0170 called as a no-op marker after the node setup [callee:0x004B0170]
    // RETURN: Return 0 [function:0x0054BB40, source:raw]
    // CALL: Invoked by SceneNode (0055A910) while setting up UI scene nodes [caller:0x0055A910]

    // Conservative worker pseudocode:
    //   v3 = this[133];
    //   if (v3) {
    //     for (i = *(v3 + 36); i; i = *(i + 36)) v3 = i;
    //   }
    //   if (OperatorNewNhMallocWrapper(40)) v5 = sub_5510F0(*(a2 + 12));
    //   else v5 = 0;
    //   if (v3) *(v3 + 36) = v5;
    //   else this[133] = v5;
    //   v8 = v5;
    //   v8[5] = *(v4 + 12);
    //   v9 = 0;
    //   if (v8[5] > 0) {
    //     v10 = 0;
    //     do {
    //       *(v10 + v8[6]) = v9++;
    //       v10 += 136;
    //     } while (v9 < v8[5]);
    //   }
    //   EntityFlagSetSubInitChain(v8);
    //   v8[7] = v4;
    //   sub_557350(v13);
    //   v15 = *(v4 + 12); v16 = 1120403456; v14 = 2; v19 = 14671647; v17 = 16; v18 = 0;
    //   if (!this[134]) sub_559200(this + 134, v13);
    //   EmptyStub_0170();
    //   return 0;
    // UNRESOLVED: Global dword_8B8F28 is flagged as a read by packet facts but appears nowhere in the decompiled source; it is presumed consumed by one of the callees and is not verifiable here
    // UNRESOLVED: The packet models the tail-node next pointer through base *(*(this+0x238)+0x24), while the raw source walks the chain from this[133] via node+0x24; the two anchors are not reconciled here
    // UNRESOLVED: The exact object type owning this+0x214/this+0x218/this+0x238 is unknown (UnknownObject)
}
