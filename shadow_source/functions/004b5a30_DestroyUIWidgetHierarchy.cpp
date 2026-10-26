// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5A30
// Canonical corpus name: DestroyUIWidgetHierarchy
// Owner: UnknownObject [DERIVED]
// Raw source: functions/DestroyUIWidgetHierarchy_004b5a30.c

void UnknownObject::DestroyUIWidgetHierarchy()
{
    // Destroys the UI widget hierarchy: cleans sprite overlays, transfers linked buffers, frees several heap-allocated buffer pointers behind non-null guards, runs four linked-list destructor families over the widget sub-hierarchies at this+3908/+3924/+3940 and the widget-node lists at this+0x6D4 (1748) and this+0x6C0 (1728), frees the 104 consecutive list structures below this+0x6C0 with NodeDestructor, then destroys the remaining child lists at this+48/+32/+16 and returns the result of the final linked-list destroy helper on this.
    // CALL: Call SpriteOverlayListCleanup() with no arguments. [callee:0x004B6130]
    // CALL: Call sub_4B5E50(this) as part of the teardown sequence. [callee:0x004B5E50]
    // CALL: Call LinkedBufferTransfer(this). [callee:0x004B5F60]
    // GUARD: Guard: if the buffer pointer at this+3988 (0xF94) is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000F94, callee:0x00587BCF]
    // CALL: Call ListRebuildWithNodeTransfer on the list at this+3908. [callee:0x004B52A0]
    // CALL: Call LinkedListDestruction on the list at this+3940. [callee:0x004BA9F0]
    // CALL: Call LinkedListDestruction on the list at this+3924. [callee:0x004BA9F0]
    // CALL: Call LinkedListDestructionWithRefCountLoop on the list at this+3908. [callee:0x004BB4F0]
    // CALL: Call EmptyStub_0170() twice in sequence. [callee:0x004B0170]
    // GUARD: Guards: free the buffer at this+1836 (0x72C) if non-null, then free the buffer at this+1828 (0x724) if non-null, both with FreeWrapper_7bcf. [field:this:0x0000072C, field:this:0x00000724, callee:0x00587BCF]
    // CALL: Call LinkedListDestructor_b400 on the list at this+1812. [callee:0x004BB400]
    // GUARD: Guards: free the buffer at this+1804 (0x70C) if non-null, then free the buffer at this+1796 (0x704) if non-null, both with FreeWrapper_7bcf. [field:this:0x0000070C, field:this:0x00000704, callee:0x00587BCF]
    // CALL: Call SubCallWithConditionalFieldFree on the sub-object at this+1764. [callee:0x005668D0]
    // LOOP: Walk the widget-node list starting at this+0x6D4 (1748), advancing via the next pointer at node+4, and call ConditionalDestructor_46f0(node, 1) for every node. [field:this:0x000006D4, field:*(*(this+0x6D4)+0x4):0x00000004, callee:0x004646F0]
    // ASSIGNMENT: Zero the four header fields of the list at this+0x6D4 (0x6D4, 0x6D8, 0x6DC, 0x6E0). [field:this:0x000006D4, field:this:0x000006D8, field:this:0x000006DC, field:this:0x000006E0]
    // LOOP: Walk the widget-node list starting at this+0x6C0 (1728), advancing via the next pointer at node+4, and call LinkedListNodeDestructor_a900(1) for every node. [field:this:0x000006C0, field:*(*(this+0x6C0)+0x4):0x00000004, callee:0x004BA900]
    // ASSIGNMENT: Zero the four header fields of the list at this+0x6C0 (0x6C0, 0x6C4, 0x6C8, 0x6CC). [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC]
    // LOOP: Do-while loop over 104 consecutive list structures starting at this+1728 (0x6C0): for each list, walk its nodes via the next pointer at node+4 calling NodeDestructor(1) for each, then zero its four header fields and step backward to the previous list. [field:this:0x000006C0, callee:0x004BA8C0]
    // CALL: Call LinkedListFree on the list at this+48 twice in sequence. [callee:0x0049AF30]
    // CALL: Call ListFullDestruction on the sub-object at this+32. [callee:0x004BB650]
    // CALL: Call LinkedListDestructorWithCallback on the sub-object at this+16 twice in sequence. [callee:0x004BAEB0]
    // RETURN: Return the result of the final linked-list destroy helper invoked on this. [function:0x004B5A30, source:raw]

    // Conservative worker pseudocode:
    //   SpriteOverlayListCleanup();
    //   sub_4B5E50(this); LinkedBufferTransfer(this);
    //   if (this[3988]) free(this[3988]);
    //   ListRebuildWithNodeTransfer(this+3908);
    //   LinkedListDestruction(this+3940); LinkedListDestruction(this+3924);
    //   LinkedListDestructionWithRefCountLoop(this+3908);
    //   EmptyStub_0170(); EmptyStub_0170();
    //   if (this[1836]) free(this[1836]); if (this[1828]) free(this[1828]);
    //   LinkedListDestructor_b400(this+1812);
    //   if (this[1804]) free(this[1804]); if (this[1796]) free(this[1796]);
    //   SubCallWithConditionalFieldFree(this+1764);
    //   for (n = list@1748; n; n = n[1]) ConditionalDestructor_46f0(n, 1);
    //   zero4(list@1748);
    //   for (n = list@1728; n; n = n[1]) LinkedListNodeDestructor_a900(1);
    //   zero4(list@1728);
    //   for (i = 104; i; i--) { for (n = head; n; n = n[1]) NodeDestructor(1); zero4(head); head -= 16; }
    //   LinkedListFree(this+48); LinkedListFree(this+48);
    //   ListFullDestruction(this+32);
    //   LinkedListDestructorWithCallback(this+16); LinkedListDestructorWithCallback(this+16);
    //   return LinkedListDestroy(this);
    // UNRESOLVED: The final linked-list destroy helper that produces the return value (named LinkedListDestroy_b5a0 in the decompiled source) has no entry in the packet callee table, so its address cannot be cited.
    // UNRESOLVED: Several child-list offsets used by the helpers (this+16, +32, +48, +1764, +1812, +3908, +3924, +3940) have no packet field evidence refs; only the helper-call callee refs are citable for them.
    // UNRESOLVED: EmptyStub_0170 is called twice but is a stub with unknown effect.
    // UNRESOLVED: The single known caller sub_4B41D0 (0x004B41D0) is not referenced inside the operation list.
}
