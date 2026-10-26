// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495AE0
// Canonical corpus name: sub_495AE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_495AE0_00495ae0.c

void UnknownObject::ListTailPopAndRenderDispatch()
{
    // Pops the tail node of a render list and dispatches its rectangle. Reads the list head from this+0x14; when non-null and its node flag at +100 is set, it takes the tail node from this+0x18, unlinks it by writing the popped node's link at +104 into this+0x18, clears the flag at +100 of the new tail, dispatches GuardedSubRectangleRenderDispatch with the node's four fields at +4/+8/+0xC/+0x10, then zeroes the popped node's link fields at +100 and +104. Returns the original head value (or the dispatch result).
    // ASSIGNMENT: List head read from this+0x14 into result; this is the value later returned [field:this:0x00000014, source:raw]
    // GUARD: Pop proceeds only when the list head at this+0x14 is non-null [field:this:0x00000014, source:raw]
    // GUARD: Pop proceeds only when the head node's flag at +100 is set, marking the list as having a tail to pop [source:raw]
    // ASSIGNMENT: Tail node read from this+0x18 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Unlink: the popped node's link at +104 is written into this+0x18, making it the new tail [field:this:0x00000018, source:raw]
    // ASSIGNMENT: The new tail's flag at +100 is cleared [source:raw]
    // CALL: GuardedSubRectangleRenderDispatch invoked with the four fields at +4/+8/+0xC/+0x10 of the popped node, presumably rectangle position/size; result stored into result [callee:0x00499050, source:raw]
    // ASSIGNMENT: Popped node's link fields at +100 and +104 are zeroed, detaching it from the list [source:raw]
    // RETURN: Returns result: the head value read at entry, or the dispatch result once the pop executes [source:raw]
    // CALL: Invoked by ShortComputation_5b30 as the tail-pop step of a render-queue drain [caller:0x00495B30, source:raw]

    // Conservative worker pseudocode:
    //   result = *(dword*)(this + 0x14);
    //   if (result) {
    //     if (*(dword*)(result + 100)) {
    //       v2 = *(dword**)(this + 0x18);
    //       v3 = v2[26];
    //       *(dword*)(this + 0x18) = v3;
    //       *(dword*)(v3 + 100) = 0;
    //       result = GuardedSubRectangleRenderDispatch(v2[1], v2[2], v2[3], v2[4]);
    //       v2[25] = 0;
    //       v2[26] = 0;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Which of the popped node's +4/+8/+0xC/+0x10 fields are x/y/width/height is not established from this packet alone
    // UNRESOLVED: Whether node links at +100/+104 are prev/next pointers of a doubly-linked list is DERIVED from the unlink pattern, not confirmed
    // UNRESOLVED: Whether this+0x1C, this+0x20, this+0x24, this+0x28 are separate fields or part of a larger list-header structure is unresolved
    // UNRESOLVED: Roles of this+0x78 and of the this+0x7C/this+0x80/this+0xE4 fields (init 0) are unknown; they are not accessed in this function
    // UNRESOLVED: The node flag at +100 read for the head but cleared for the new tail suggests a tail-marker, but its exact meaning is not confirmed
}
