// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00468A00
// Canonical corpus name: CareerModeDriverStatsReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CareerModeDriverStatsReset_00468a00.c

void UnknownObject::CareerModeDriverStatsReset()
{
    // Resets the career-mode driver stats page. Copies a cached flag byte_7CFF32 into byte_7CFF30, invokes a vtable method at obj+0x3C (byte offset 60) with argument 0, builds the world-championships page, frees the existing stat linked list rooted at this+0x44, clears the list bookkeeping fields, rebuilds the list with 13 stat-key insertions, runs state cleanup, invokes a second vtable-dispatched init at loc_468640, then sub_468BF0, and returns 0.
    // ASSIGNMENT: Flag copy: byte_7CFF30 = 0; if byte_7CFF32 is nonzero, byte_7CFF30 = byte_7CFF32. [global:0x007CFF30, global:0x007CFF32]
    // CALL: Invoke vtable method at slot obj+0x3C (byte offset 60) on this with argument 0. [field:obj:0x0000003C, field:this:0x00000000]
    // CALL: HTMLResultsStatsPageWorldChampionships(this): build the world-championships stats page. [callee:0x00468910]
    // LOOP: Walk the linked list starting at this+0x44: each node carries a data pointer at node+0, the next pointer at node+4, and a flag byte at node+8. [field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004]
    // CALL: For flagged nodes free the inner string buffer and the node data object, then free every node wrapper, all through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the list bookkeeping fields this+0x44 (head), this+0x48 (tail), this+0x4C (count), this+0x50 (capacity) to 0. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // CALL: Rebuild the stat list via LinkedListInsertWithNodeAllocation with key -1: aExperienceLaps, aStarts, aAvgStartingPos, aAvgFinishPosit, aAvgRaceLength. [callee:0x00486F30, global:0x005C6900, global:0x005C68F8, global:0x005C68E0, global:0x005C68C8, global:0x005C68B4]
    // CALL: Rebuild the stat list via LinkedListInsertWithNodeAllocation with key -1: aAvgOpponentStr, aPolePositions, aPoints, aWins, aWorldChampions. [callee:0x00486F30, global:0x005C6898, global:0x005C6888, global:0x005C6880, global:0x005C6878, global:0x005C6860]
    // CALL: Rebuild the stat list via LinkedListInsertWithNodeAllocation with key -1: aCircuit, aExperienceLaps (second insertion), aBestLap. [callee:0x00486F30, global:0x005C6920, global:0x005C6900, global:0x005C6914]
    // CALL: StateCleanupNotification(this): notify state machinery that the page was torn down. [callee:0x00489CB0]
    // CALL: Invoke the vtable-dispatched init at loc_468640 on this (secondary page rebuild). [source:raw]
    // CALL: sub_468BF0(this): final cleanup/reset step for the stats page. [callee:0x00468BF0]
    // RETURN: Return 0. [function:0x00468A00, source:raw]

    // Conservative worker pseudocode:
    //   byte_7CFF30 = 0;
    //   if (byte_7CFF32) byte_7CFF30 = byte_7CFF32;
    //   (*this[0x3C])(this, 0);
    //   HTMLResultsStatsPageWorldChampionships(this);
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
    //   insert stat keys (13 total: ExperienceLaps twice, Starts, AvgStartingPos, AvgFinishPosit, AvgRaceLength, AvgOpponentStr, PolePositions, Points, Wins, WorldChampions, Circuit, BestLap);
    //   StateCleanupNotification(this);
    //   loc_468640(this);
    //   sub_468BF0(this);
    //   return 0;
    // UNRESOLVED: The semantic meaning of the per-node flag byte and of the individual stat keys is labeled by corpus names only; the display mapping is not verified
    // UNRESOLVED: The stat list is rebuilt with a duplicated aExperienceLaps insertion and an extra aCircuit/aBestLap pair not present in the base ten keys; whether that is intentional is unresolved
}
