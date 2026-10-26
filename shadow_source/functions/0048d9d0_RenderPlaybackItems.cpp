// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D9D0
// Canonical corpus name: MediaBufferPlaybackManager
// Owner: Media_Buffer_Playback_Manager [DERIVED]
// Raw source: functions/MediaBufferPlaybackManager_0048d9d0.c

void Media_Buffer_Playback_Manager::RenderPlaybackItems()
{
    // Renders the media-buffer playback list for the current playback index. Caches per-item layout coordinates (X from sub_487060, Y/size from sub_4870E0) for indices 0-3 into this+0x108..0x124, positions the list iterator on the current node (this[60]) at the clamped index (this[63]), resolves the node's display string (falling back to byte_5EA438), looks it up in the string table via BinarySearchInStringTable into byte_5EC4CC, computes item layout with ShortComputation_4f00, and dispatches a UI message (UIMessageDispatch). For playback states 3/4/5/8/9 (ShortComputation_6720) it additionally walks the list to a target index (this[64]), then renders extra items (index >= 4) in a do-while loop with clip-bounds hit testing (DualFieldRead outputs) that selects UIStringAccessor_62e0 for in-bounds items and tracks the selected index in this[65]. Ends with a ConditionalDelegation_6460 call on this[33]; when non-null, fills a surface region from the delegated object's rect and invokes vtable entry #4 (render), then calls vtable entry #11 (cleanup) and returns 0.
    // ASSIGNMENT: Cache X-position layout values for item indices 0..3 into this+0x108/0x10C/0x110/0x114 via sub_487060(this, 0..3). [callee:0x00487060, field:this:0x00000108, field:this:0x0000010C, field:this:0x00000110, field:this:0x00000114, source:raw]
    // ASSIGNMENT: Cache Y/size layout values for item indices 0..3 into this+0x118/0x11C/0x120/0x124 via sub_4870E0(this, 0..3). [callee:0x004870E0, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, source:raw]
    // ASSIGNMENT: Position the current list node this[60] on the list head this[58]. [field:this:0x000000E8, field:this:0x000000F0, source:raw]
    // GUARD: Guard: if the list head this[58] is null, or the first node's data pointer (offset +0) is null, return 0 immediately. [field:this:0x000000E8, field:*(this+0xE8):0x00000000, field:*(this+0xF0):0x00000000, source:raw]
    // GUARD: Guard/clamp: if current index this[63] exceeds this[62]-1 (max valid page index), clamp this[63] to this[62]-1. [field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // GUARD: Guard: only walk the list when the clamped index this[63] is within [0, this[61]); otherwise the resolved node pointer is null. [field:this:0x000000FC, field:this:0x000000F4, source:raw]
    // LOOP: Walk the linked list from the head, following the next pointer at node offset +4, decrementing the index until the target node (index <= 0) is reached. [field:this:0x000000E8, field:*(this+0xEC):0x00000004, source:raw]
    // ASSIGNMENT: Default the resolved node pointer to null when the index is out of the list range. [source:raw]
    // ASSIGNMENT: Resolve the node display string from the node's data pointer (offset +0); when the string is null, substitute the default string byte_5EA438. [field:*(this+0xE8):0x00000000, global:0x005EA438, source:raw]
    // CALL: Look the display string up in the string table: BinarySearchInStringTable(byte_5EC4C0, string, byte_5EC4CC); on a hit, strcpy the string into byte_5EC4CC (or clear the buffer when null). [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Compute item layout dimensions: UIStringAccessor_62c0(this) then ShortComputation_4f00(accessor, byte_5EC4CC, &height, &width) producing v50/v49. [callee:0x004862C0, callee:0x00494F00, source:raw]
    // CALL: Fetch the global render context: GlobalAccessor_5150(&unk_7CDE00). [callee:0x00495150, global:0x007CDE00, source:raw]
    // ASSIGNMENT: Read cached item-3 coordinates: X from this+0x114 and Y/size from this+0x124. [field:this:0x00000114, field:this:0x00000124, source:raw]
    // CALL: Dispatch a UI message for item index 3: UIMessageDispatch(UIStringAccessor_62c0(this), string, x, y, renderContext, 1). [callee:0x004862C0, callee:0x00494F10, source:raw]
    // CALL: Fill/copy the item-3 surface rectangle: Accessor() then RenderSurfaceFillCopy(x, y, width + 20, height). [callee:0x00490920, callee:0x004918D0, source:raw]
    // CALL: Read the clip-bounds pair into local outputs via DualFieldRead(&v54, &v53). [callee:0x00498880, source:raw]
    // CALL: Compute the current playback state/mode via ShortComputation_6720(this). [callee:0x00486720, source:raw]
    // GUARD: Guard: enter the multi-item rendering path only when the playback state is one of 3, 5, 4, 8 or 9; all other states skip the extra-item loop. [source:raw]
    // CALL: Compute the additional item render count: ShortComputation_adb0(this[50] + 108) where this[50] is at this+0xC8. [callee:0x0049ADB0, field:this:0x000000C8, source:raw]
    // GUARD: Guard: if target index this[64] is out of [0, this[61]), null the current node this[60]; otherwise navigate to the target node. [field:this:0x00000100, field:this:0x000000F4, field:this:0x000000F0, source:raw]
    // LOOP: Navigate the current node from the list head toward the target index, following the next pointer at node offset +4, breaking on a null node. [field:this:0x000000E8, field:*(this+0xEC):0x00000004, source:raw]
    // ASSIGNMENT: Record the current index as the selected index this[65] = this[63] and seed the extra-item counter to 4. [field:this:0x00000104, field:this:0x000000FC, source:raw]
    // GUARD: Guard: run the extra-item do-while loop only when the computed render count exceeds 4. [source:raw]
    // LOOP: do-while loop over extra item indices 4..count-1, advancing the current node through the list and the item index each iteration. [field:this:0x000000F0, field:*(this+0xEC):0x00000004, source:raw]
    // CALL: Fetch coordinates for the current extra item index via sub_487060(this, idx) and sub_4870E0(this, idx). [callee:0x00487060, callee:0x004870E0, source:raw]
    // CALCULATION: Track the running maximum item extent: when the current item extent exceeds v52, set v52 = width + extent. [source:raw]
    // GUARD: Guard: process the current node only when it is non-null and its data pointer (offset +0) is non-null. [field:*(this+0xF0):0x00000000, source:raw]
    // ASSIGNMENT: Resolve the extra-item display string from the node data pointer; substitute default string byte_5EA438 when null. [global:0x005EA438, source:raw]
    // CALL: Look the extra-item string up in the string table and cache the result into byte_5EC4CC via BinarySearchInStringTable, with strcpy/clear on hit. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Compute extra-item layout: UIStringAccessor_62c0(this) then ShortComputation_4f00 into v50/v49. [callee:0x004862C0, callee:0x00494F00, source:raw]
    // GUARD: Clip/intersection test against the DualFieldRead bounds: outside when lowBound <= y || lowBound >= width + y || highBound <= x || highBound >= x + height. [source:raw]
    // CALL: Outside-clip path: GlobalAccessor_5150(&unk_7CDE00) + UIStringAccessor_62c0(this) + UIMessageDispatch(accessor, string, x, y, context, 1). [callee:0x00495150, callee:0x004862C0, callee:0x00494F10, global:0x007CDE00, source:raw]
    // CALL: Inside-clip path: GlobalAccessor_5150(&unk_7CDE00) + UIStringAccessor_62e0(this) + UIMessageDispatch(accessor, string, x, y, context, 1). [callee:0x00495150, callee:0x004862E0, callee:0x00494F10, global:0x007CDE00, source:raw]
    // LOOP: Inside-clip path: compute the current node's index by walking from the list head, counting nodes until the current node matches. [field:this:0x000000E8, field:*(this+0xEC):0x00000004, source:raw]
    // ASSIGNMENT: Store the computed node index as the selected index this[65]. [field:this:0x00000104, source:raw]
    // CALL: Fill/copy the extra-item surface rectangle: Accessor() then RenderSurfaceFillCopy(x, y, width + 20, height). [callee:0x00490920, callee:0x004918D0, source:raw]
    // ASSIGNMENT: Advance the current node this[60] to the next node (offset +4) when it is non-null. [field:this:0x000000F0, field:*(this+0xEC):0x00000004, source:raw]
    // CALL: Conditionally delegate based on state: ConditionalDelegation_6460(this, this[33]) where this[33] is at this+0x84; returns an object or null. [callee:0x00486460, field:this:0x00000084, source:raw]
    // GUARD: Guard: when the delegated object is non-null, render its region and invoke its virtual callbacks. [source:raw]
    // ASSIGNMENT: Read the delegated object's rect: height/width from the object at offsets +4 and +12, and this+0x4 / this+0xC as the base coordinates. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALL: Fill/copy the delegated surface rectangle: Accessor() then RenderSurfaceFillCopy(this+0xC, this+0x4, obj+12, obj+4). [callee:0x00490920, callee:0x004918D0, source:raw]
    // CALL: Virtual dispatch on vtable entry #4 (render/draw): call (*this+0x10)(this, this+0x4, obj+12, this+0xC, obj+4). [field:obj:0x00000010, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch on vtable entry #11 (cleanup/reset): call (*this+0x2C)(this, 0). [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return 0 in all paths. [source:raw]

    // Conservative worker pseudocode:
    //   int RenderPlaybackItems(MediaBufferPlaybackManager* this) {
    //     for (int idx = 0; idx < 4; ++idx) {
    //       this->itemX[idx] = sub_487060(this, idx);
    //       this->itemY[idx] = sub_4870E0(this, idx);
    //     }
    //     this->currentNode = this->listHead;
    //     if (!this->listHead || !this->listHead->data) return 0;
    //     if (this->curIndex > this->maxPageIndex - 1) this->curIndex = this->maxPageIndex - 1;
    //     const char* text = this->curIndex >= 0 && this->curIndex < this->itemCount
    //       ? nodeDataAt(this->listHead, this->curIndex) : null;
    //     if (!text) text = byte_5EA438;
    //     if (BinarySearchInStringTable(byte_5EC4C0, text, byte_5EC4CC))
    //       text ? strcpy(byte_5EC4CC, text) : (byte_5EC4CC[0] = 0);
    //     int w, h;
    //     ShortComputation_4f00(UIStringAccessor_62c0(this), byte_5EC4CC, &h, &w);
    //     void* ctx = GlobalAccessor_5150(&unk_7CDE00);
    //     UIMessageDispatch(UIStringAccessor_62c0(this), text, this->itemX[3], this->itemY[3], ctx, 1);
    //     Accessor();
    //     RenderSurfaceFillCopy(this->itemX[3], this->itemY[3], h + 20, w);
    //     DualFieldRead(&clipHi, &clipLo);
    //     int state = ShortComputation_6720(this);
    //     if (state == 3 || state == 5 || state == 4 || state == 8 || state == 9) {
    //       int count = ShortComputation_adb0(this->base + 108);
    //       if (this->targetIndex < 0 || this->targetIndex >= this->itemCount) this->currentNode = 0;
    //       else for (this->currentNode = this->listHead; this->targetIndex > 0; --this->targetIndex)
    //         if (!this->currentNode) break; else this->currentNode = this->currentNode->next;
    //       this->selectedIndex = this->curIndex;
    //       int idx = 4;
    //       if (count > 4) {
    //         do {
    //           int x = sub_487060(this, idx);
    //           int y = sub_4870E0(this, idx);
    //           if (y > maxExtent) maxExtent = w + y;
    //           if (this->currentNode && this->currentNode->data) {
    //             const char* itemText = this->currentNode->data ?: byte_5EA438;
    //             if (BinarySearchInStringTable(byte_5EC4C0, itemText, byte_5EC4CC))
    //               itemText ? strcpy(byte_5EC4CC, itemText) : (byte_5EC4CC[0] = 0);
    //             ShortComputation_4f00(UIStringAccessor_62c0(this), byte_5EC4CC, &h, &w);
    //             if (clipLo <= y || clipLo >= w + y || clipHi <= x || clipHi >= x + h) {
    //               UIMessageDispatch(UIStringAccessor_62c0(this), itemText, x, y, ctx, 1);
    //             } else {
    //               UIMessageDispatch(UIStringAccessor_62e0(this), itemText, x, y, ctx, 1);
    //               this->selectedIndex = indexOfNode(this->listHead, this->currentNode);
    //             }
    //             Accessor();
    //             RenderSurfaceFillCopy(x, y, h + 20, w);
    //             if (this->currentNode) this->currentNode = this->currentNode->next;
    //           }
    //         } while (++idx < count);
    //       }
    //     }
    //     void* delegated = ConditionalDelegation_6460(this, this->state);
    //     if (delegated) {
    //       Accessor();
    //       RenderSurfaceFillCopy(this->x, this->width, *(delegated + 12), *(delegated + 4));
    //       vtable[4](this, this->width, *(delegated + 12), this->x, *(delegated + 4));
    //     }
    //     vtable[11](this, 0);
    //     return 0;
    //   }
    // UNRESOLVED: Parameters a2, a3, a4, a5 are never referenced in the body; their purpose is unknown.
    // UNRESOLVED: The exact playback-state enum values 3/4/5/8/9 returned by ShortComputation_6720 are not named.
    // UNRESOLVED: The clip-bounds source and semantics of the DualFieldRead outputs (v53/v54) are unknown.
    // UNRESOLVED: The content of the default-string global byte_5EA438 is unknown.
    // UNRESOLVED: Whether sub_487060 / sub_4870E0 return X vs Y vs size is inferred from call order and is not independently proven.
    // UNRESOLVED: The function has no static callers; its reachability and invocation context are unknown.
}
