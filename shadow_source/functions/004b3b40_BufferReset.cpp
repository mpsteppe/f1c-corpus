// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3B40
// Canonical corpus name: BufferReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferReset_004b3b40.c

void UnknownObject::BufferReset()
{
    // Drains a ring buffer of pending entries then resets it to empty, consistent with the ABI lead Buffer_Reset. If the current pointer at this+0x6C008 differs from the end pointer at this+0x6C004, repeatedly calls sub_4B3400 on the current entry, advances the current pointer by 432 bytes (0x6C0) per entry, and decrements the pending counter at this+0 until current reaches end. Finally resets the read, current, and end pointers (this+0x6C00C, +0x6C008, +0x6C004) to base+4 and returns that base pointer. Called from GamePostMainLoop and sub_4B9B80 during shutdown/reset.
    // GUARD: Guard: if the ring-buffer current pointer at this+0x6C008 (this[110594]) differs from the end pointer at this+0x6C004 (this[110593]), the drain loop runs; an already-empty buffer skips it. [field:this:0x0006C008, field:this:0x0006C004, abi:lead, source:raw]
    // LOOP: Per iteration: calls sub_4B3400 on the current entry at this[110594], advances the current pointer by 432 bytes (0x6C0), and decrements the pending counter *this (this+0). Iterates until the advanced pointer equals the end pointer this[110593] (byte 0x6C004). [callee:0x004B3400, field:this:0x0006C008, field:this:0x0006C004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: After draining (or when already empty), resets the read/current/end pointers at this+0x6C00C, this+0x6C008 and this+0x6C004 all to base+4 (this + 1). [field:this:0x0006C00C, field:this:0x0006C008, field:this:0x0006C004, source:raw]
    // RETURN: Returns the base+4 pointer (this + 1). [function:0x004B3B40, source:raw]

    // Conservative worker pseudocode:
    //   if (this->current != this->end) {
    //     do {
    //       sub_4B3400(this->current);
    //       this->current = (char*)this->current + 432;
    //       this->count--;
    //     } while (this->current != this->end);
    //   }
    //   this->read = this->current = this->end = (char*)(this + 1);
    //   return (char*)(this + 1);
    // UNRESOLVED: sub_4B3400 (the per-entry drain operation) semantics are not evidenced within this packet.
    // UNRESOLVED: The ring-buffer owning class is unidentified; the owner remains UnknownObject.
    // UNRESOLVED: The 432-byte (0x6C0) entry stride derives from raw pointer arithmetic; the entry layout is not evidenced.
}
