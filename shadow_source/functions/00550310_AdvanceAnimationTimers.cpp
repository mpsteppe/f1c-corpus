// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550310
// Canonical corpus name: D3DAnimationTimeUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DAnimationTimeUpdate_00550310.c

void UnknownObject::AdvanceAnimationTimers()
{
    // Advances per-entry animation timers by a per-frame delta. Each entry whose accumulator is still below its duration has the timer incremented and a completion flag bit cleared; each entry that has reached or passed its duration keeps the timer, sets the completion flag bit, and calls InterruptDispatch with the timer value. Iterates a node list from an animation block anchored at this+0x110.
    // ASSIGNMENT: Load the animation block pointer from this+0x110 (decompiler this[68]) as the walk anchor. [field:this:0x00000110]
    // LOOP: Walk the animation-node linked list: start at the block pointer +0x90 bytes, follow each node's next link at +0xC0 bytes until null. this+0x134 names the container and the packet's *(this+0x134)+0x15C field the list/iteration data. [field:this:0x00000134, field:*(this+0x134):0x0000015C]
    // GUARD: Per-node state check: only process the node when its state/control field (attributed to *(this+0x134)+0x168) has bit 0x400 set. [field:*(this+0x134):0x00000168]
    // GUARD: Entry-loop gate: only iterate when the entry count field (attributed to *(this+0x134)+0x164) is greater than 0 (packet guard:0). [field:*(this+0x134):0x00000164, guard:0]
    // LOOP: Iterate the node's entry array starting at the entries pointer +0x40 bytes, advancing by a fixed 37-dword stride per entry. [field:*(this+0x134):0x00000180]
    // GUARD: Per-entry gate: only advance the timer when the entry threshold counter (attributed to *(this+0x134)+0x1A8) is greater than 1 (packet guard:1). [field:*(this+0x134):0x000001A8, guard:1]
    // CALCULATION: Compare the entry's current timer (+28 bytes) against its duration (+24 bytes); a timer below duration keeps the animation running. [field:*(this+0x134):0x000001C0]
    // ASSIGNMENT: Timer below duration: add the caller delta to the accumulator (attributed to *(this+0x134)+0x1B0) and clear the completion flag bit 2 (value 4) in the entry flag word (attributed to *(this+0x134)+0x1C4). [field:*(this+0x134):0x000001B0, field:*(this+0x134):0x000001C4]
    // STATE_TRANSITION: Timer reached or passed duration: keep the timer value, set the completion flag bit 2 (value 4) in the entry flag word, and dispatch the interrupt callback with the current timer value. [field:*(this+0x134):0x000001C4, callee:0x0058957A]
    // CALL: Call InterruptDispatch with the entry timer value when an entry completes. [callee:0x0058957A]
    // RETURN: Return the last computed result register value; it is not an explicit status, so the return value carries no confirmed semantic. [source:raw]

    // Conservative worker pseudocode:
    //   AdvanceAnimationTimers(animController, delta) {
    //     block = animController->block;                       // this+0x110
    //     for (node = block->nodeList; node; node = node->next) { // head at +0x90, next at +0xC0
    //       if ((node->state & 0x400) == 0) continue;          // state +0x168
    //       for (idx = 0; idx < node->entryCount; ++idx) {     // count +0x164, guard:0
    //         entry = (Entry*)(node->entries + idx * 148);     // entries +0x40, stride 148 bytes
    //         if (entry->threshold <= 1) continue;             // +8, guard:1
    //         if (entry->timer < entry->duration) {            // timer +28, duration +24
    //           entry->timer += delta;
    //           entry->flags &= ~4;                            // clear completion bit 2
    //         } else {
    //           InterruptDispatch(entry->timer);
    //           entry->flags |= 4;                             // set completion bit 2
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: The exact mapping between decompiler this-relative accesses and the packet's *(this+0x134)-relative field bases (0x15C, 0x164, 0x168, 0x180, 0x1A8, 0x1B0, 0x1C0, 0x1C4) is an extraction attribution and is not independently confirmed.
    // UNRESOLVED: The per-entry layout (timer at +28, duration at +24, threshold at +8, flag bit 2) is derived from decompiler index math, not from a named struct.
    // UNRESOLVED: Caller sub_557120 is not on a confirmed frame path; call frequency and entry semantics are unknown.
}
