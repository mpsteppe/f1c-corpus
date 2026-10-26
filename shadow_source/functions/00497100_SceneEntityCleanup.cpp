// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497100
// Canonical corpus name: SceneEntityCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneEntityCleanup_00497100.c

void UnknownObject::SceneEntityCleanup()
{
    // Conditional scene-entity cleanup: when parameter a2 is non-zero, renders a frame, then tears down two scene-entity linked lists rooted at this+0x18BC and this+0x18CC. Each list is processed in two passes: first every item's vtable+0x44 method (offset 0x44) is invoked through the traversal cursor, then each node is freed with FreeWrapper_7bcf, releasing the item via its vtable slot 0 when the node's active flag (byte at node+12) is clear and the item pointer is non-null. All eight list-state fields (0x18BC..0x18D8) are then zeroed and StateFlagComputation(0) is called. Regardless of a2 the function ends by calling Accessor and returning CircularBufferRingAdvance. Called by CarCrashDamageProcessing (0x00496030) and sub_496E90 (0x00496E90).
    // GUARD: Entry guard on parameter a2: a non-zero value enters the scene-entity teardown block; zero skips it entirely and jumps to the final ring-buffer advance. [caller:0x00496030, caller:0x00496E90, source:raw]
    // CALL: On the teardown path, call RenderFrameWrapper before processing the entity lists. [callee:0x004950E0, source:raw]
    // LOOP: First list, pass 1: copy the head at this+0x18BC into the traversal cursor at this+0x18C4; while the cursor and its item pointer are non-null, call each item's virtual method at vtable+0x44 (offset 0x44) and advance the cursor to the next node at offset 4. [field:this:0x000018BC, field:this:0x000018C4, field:*(this+0x18BC):0x00000000, field:*(this+0x18C0):0x00000004, field:*(*(this+0x18BC)+0x0):0x00000000, field:*(*(this+0x18BC)+0x0):0x00000044, source:raw]
    // GUARD: First-list empty indicator: the deterministic skeleton records a guard on this+0x18C8 == 0, treated here as the first list being empty or fully drained. [guard:0, field:this:0x000018C8, field:*(this+0x18C8):0x00000000, source:raw]
    // LOOP: First list, pass 2: walk nodes from the head at this+0x18BC following the next pointer at offset 4; for each node, if its active flag (byte at node+12) is clear and its item pointer is non-null, release the item through its vtable slot 0 with argument 1, then free the node with FreeWrapper_7bcf. [field:this:0x000018BC, field:this:0x000018C0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the first list's state block: this+0x18BC, this+0x18C0, this+0x18C4 and this+0x18C8 are all cleared. [field:this:0x000018BC, field:this:0x000018C0, field:this:0x000018C4, field:this:0x000018C8, source:raw]
    // LOOP: Second list, pass 1: copy the head at this+0x18CC into the traversal cursor at this+0x18D4; while the cursor and its item pointer are non-null, call each item's virtual method at vtable+0x44 (offset 0x44) and advance the cursor to the next node at offset 4. [field:this:0x000018CC, field:this:0x000018D4, field:*(this+0x18CC):0x00000000, field:*(this+0x18D0):0x00000004, field:*(*(this+0x18CC)+0x0):0x00000000, field:*(*(this+0x18CC)+0x0):0x00000044, source:raw]
    // GUARD: Second-list empty indicator: the deterministic skeleton records a guard on this+0x18D8 == 0, treated here as the second list being empty or fully drained. [guard:1, field:this:0x000018D8, field:*(this+0x18D8):0x00000000, source:raw]
    // LOOP: Second list, pass 2: walk nodes from the head at this+0x18CC following the next pointer at offset 4; for each node, if its active flag (byte at node+12) is clear and its item pointer is non-null, release the item through its vtable slot 0 with argument 1, then free the node with FreeWrapper_7bcf. [field:this:0x000018CC, field:this:0x000018D0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the second list's state block: this+0x18CC, this+0x18D0, this+0x18D4 and this+0x18D8 are all cleared. [field:this:0x000018CC, field:this:0x000018D0, field:this:0x000018D4, field:this:0x000018D8, source:raw]
    // CALL: After the teardown block, call StateFlagComputation(0) to clear the associated state flag. [callee:0x004F9B30, source:raw]
    // CALL: Tail path (always taken): call Accessor to obtain the ring-buffer structure pointer. [callee:0x00490920, source:raw]
    // CALL: Pass the Accessor result to CircularBufferRingAdvance, whose result is returned to the caller. [callee:0x004917C0, source:raw]
    // RETURN: Return the CircularBufferRingAdvance result as the function's char return value. [callee:0x004917C0, source:raw]

    // Conservative worker pseudocode:
    //   char SceneEntityCleanup(void* this, char a2) {
    //     if (a2) {
    //       RenderFrameWrapper();
    //       // first list: head this+0x18BC, cursor this+0x18C4
    //       for (cursor = head; cursor && *cursor;) {
    //         (*(cursor->item).vtable + 0x44)(cursor->item);  // invoke item method
    //         cursor = cursor->next;
    //       }
    //       for (node = head; node; node = node->next) {
    //         if (node->active == 0 && node->item)
    //           node->item->vtable[0](node->item, 1);          // release item
    //         FreeWrapper_7bcf(node);
    //       }
    //       this->list1 = 0; this->list1a = 0; this->list1b = 0; this->list1c = 0;
    //       // second list: head this+0x18CC, cursor this+0x18D4
    //       for (cursor = head; cursor && *cursor;) {
    //         (*(cursor->item).vtable + 0x44)(cursor->item);
    //         cursor = cursor->next;
    //       }
    //       for (node = head; node; node = node->next) {
    //         if (node->active == 0 && node->item)
    //           node->item->vtable[0](node->item, 1);
    //         FreeWrapper_7bcf(node);
    //       }
    //       this->list2 = 0; this->list2a = 0; this->list2b = 0; this->list2c = 0;
    //       StateFlagComputation(0);
    //     }
    //     return CircularBufferRingAdvance(Accessor());
    //   }
    // UNRESOLVED: The globals unk_7CDE00 (0x007CDE00) and unk_8AFE18 (0x008AFE18) are read along the teardown path, most plausibly inside RenderFrameWrapper or StateFlagComputation, so they cannot be placed deterministically in this body.
    // UNRESOLVED: The empty-indicator guards on this+0x18C8 and this+0x18D8 come from the deterministic skeleton; their exact role in this body (list empty vs fully drained) is DERIVED from the existing analysis.
    // UNRESOLVED: The node layout (item at node+0, next at node+4, active flag at node+12) and the identity of the owning object are inferred from the traversal code; the owner type is UNKNOWN.
    // UNRESOLVED: Which of the eight this fields are counters vs traversal cursors vs state flags is not fully pinned by the packet.
}
