// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469D30
// Canonical corpus name: PlayerStatsDisplayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerStatsDisplayCleanup_00469d30.c

void UnknownObject::PlayerStatsDisplayCleanup()
{
    // Tears down the career-mode player stats display: frees the stat linked list rooted at this+0x44, clears list bookkeeping, repopulates the list with three stat keys (aCircuit, aExperienceLaps, aBestLap), runs state cleanup, rebuilds the player stats page via sub_469900, resets a flag via ByteSetterAt0xe0, and returns 0.
    // LOOP: Walk the linked list starting at this+0x44: each node carries a data pointer at node+0, the next pointer at node+4, and a flag byte at node+8. [field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004]
    // CALL: For flagged nodes free the inner string buffer and the node data object, then free every node wrapper, all through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the list bookkeeping fields this+0x44 (head), this+0x48 (tail), this+0x4C (count), this+0x50 (capacity) to 0. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // CALL: Rebuild the stat list via LinkedListInsertWithNodeAllocation with key -1: aCircuit, aExperienceLaps, aBestLap. [callee:0x00486F30, global:0x005C6920, global:0x005C6900, global:0x005C6914]
    // CALL: StateCleanupNotification(this): notify state machinery that the display was torn down. [callee:0x00489CB0]
    // CALL: sub_469900(this): rebuild the player stats display page from the remaining data. [callee:0x00469900]
    // CALL: ByteSetterAt0xe0(0): reset a flag byte associated with the display. [callee:0x0048A3B0]
    // RETURN: Return 0. [function:0x00469D30, source:raw]

    // Conservative worker pseudocode:
    //   for (node = this[0x44]; node; node = next) {
    //     next = *(node + 4); flag = *(node + 8);
    //     if (flag) {
    //       data = *(node + 0);
    //       if (data) {
    //         if (*data) FreeWrapper_7bcf(*data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //   }
    //   this[0x44] = this[0x48] = this[0x4C] = this[0x50] = 0;
    //   LinkedListInsertWithNodeAllocation(aCircuit, -1);
    //   LinkedListInsertWithNodeAllocation(aExperienceLaps, -1);
    //   LinkedListInsertWithNodeAllocation(aBestLap, -1);
    //   StateCleanupNotification(this);
    //   sub_469900(this);
    //   ByteSetterAt0xe0(0);
    //   return 0;
    // UNRESOLVED: The semantic meaning of the per-node flag byte and the player-stats key labels is carried from corpus names only; the display mapping is not verified
    // UNRESOLVED: Only three stat keys are reinstated here versus the thirteen reinstated by the analogous career driver stats reset function; whether the player stats page intentionally shows fewer rows is unresolved
}
