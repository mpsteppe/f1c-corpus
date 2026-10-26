// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FAE0
// Canonical corpus name: BufferEntryClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferEntryClear_0054fae0.c

void UnknownObject::BufferEntryClear()
{
    // Resets render buffer entries for the next frame: clears the active/dirty flag bit 0 (offset 0) and zeroes the status field (offset 0x40) either on every entry (when index a2 equals the 0x8000000 bulk sentinel) or on the single entry selected by a2. Entry array and element count come from the object at this+0x1E0..0x1E8.
    // GUARD: Skip entirely when the buffer descriptor pointer at this+0x1E0 is null. [field:this:0x000001E0]
    // GUARD: When the entry index a2 equals 0x8000000, clear every entry; otherwise clear the single entry selected by a2. [source:raw]
    // GUARD: The bulk-clear loop runs only while the element count at this+0x1E4 is greater than zero. [guard:0, field:this:0x000001E4]
    // ASSIGNMENT: Load the entry-array pointer stored at this+0x1E8. [field:this:0x000001E8]
    // LOOP: Iterate every entry in the array; for each, clear the flags bit 0 (offset 0) and reset the status field (offset 0x40) to 0. [field:*(this+0x1E8):0x00000000, field:*(this+0x1E8):0x00000040]
    // ASSIGNMENT: For the single entry at index a2, clear the flags bit 0 (offset 0) and reset the status field (offset 0x40) to 0. [field:*(this+0x1E8):0x00000000, field:*(this+0x1E8):0x00000040]
    // RETURN: Implicit void return once the buffer entries have been cleared. [function:0x0054FAE0]

    // Conservative worker pseudocode:
    //   void BufferEntryClear(unsigned* this, int index) {
    //     if (this[120] == 0) return;
    //     if (index == 0x8000000) {
    //       unsigned* e = (unsigned*)this[122];
    //       for (int i = 0; i < this[121]; ++i, e += 29) { e[0] &= ~1u; e[16] = 0; }
    //     } else {
    //       unsigned* e = (unsigned*)this[122] + 29 * index;
    //       e[0] &= ~1u; e[16] = 0;
    //     }
    //   }
    // UNRESOLVED: The raw source reaches the entry array through the descriptor's +8 pointer while the packet models this+0x1E8 as the array pointer; the exact relationship between the descriptor field and this+0x1E8 is not established.
    // UNRESOLVED: The meaning of the 0x8000000 bulk-clear sentinel and of the status field at offset 0x40 (dword 16) is not established beyond the clear/reset observed here.
}
