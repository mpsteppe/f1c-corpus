// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541810
// Canonical corpus name: SoundInstanceUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundInstanceUpdate_00541810.c

void UnknownObject::SoundInstanceUpdate()
{
    // Updates the sound instance ID list of a sound-manager object. Guarded by a flag at this+0x13D8. When the flag is non-zero, first clears every existing instance (count at this+0x155C, array at this+0x1560) by calling the vtable method at *(this+0x1100)+0xB8 with flag 0, then writes the new instance count a2 and repopulates the array from a caller-supplied source, reading each ID from *(*(a3))+4 and calling the same vtable method with flag 1. Source entries are spaced 56 bytes apart. Returns the new instance count.
    // GUARD: Guard on the enabled flag at this+0x13D8; when zero the entire instance update is skipped and the function returns the flag value. [field:this:0x000013D8, source:raw]
    // GUARD: Guard on the existing instance count at this+0x155C being greater than zero; the clear pass only runs when it is. [guard:0, field:this:0x0000155C, source:raw]
    // LOOP: Clear pass: iterate over the existing instance ID array starting at this+0x1560, bound by the current count at this+0x155C. [field:this:0x00001560, field:this:0x0000155C, source:raw]
    // CALL: Call the vtable method at *(this+0x1100)+0xB8 with arguments (this+0x1100, instance ID, 0); flag 0 removes an existing instance. Each call result is stored into this+0x0. [field:*(this+0x1100):0x000000B8, field:this:0x00001100, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the new instance count a2 into this+0x155C. [field:this:0x0000155C, source:raw]
    // GUARD: Guard on a2 being greater than zero; the repopulate pass only runs when it is. [source:raw]
    // LOOP: Repopulate pass: iterate over the instance ID array starting at this+0x1560, a2 iterations. [field:this:0x00001560, source:raw]
    // CALCULATION: Read each new instance ID as *(*(a3) + 4): dereference the source entry pointer and take the dword at +4. [source:raw]
    // ASSIGNMENT: Store the new instance ID into the current array slot at this+0x1560 and advance the slot pointer. [field:this:0x00001560, source:raw]
    // CALL: Call the vtable method at *(this+0x1100)+0xB8 with arguments (this+0x1100, new instance ID, 1); flag 1 adds/starts an instance. Each call result is stored into this+0x0. [field:*(this+0x1100):0x000000B8, field:this:0x00001100, source:raw]
    // CALCULATION: Advance the source pointer by 56 bytes per entry (source entries are 56 bytes apart). [source:raw]
    // RETURN: Return the new instance count stored in this+0x155C (equal to a2). [field:this:0x0000155C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_541810(this, int newCount, void* src) {
    //     if (!*(this + 0x13D8)) return *(this + 0x13D8);
    //     for (int i = 0; i < *(this + 0x155C); ++i)
    //       *(this + 0) = soundMethod(*(this + 0x1100), *(this + 0x1560 + i), 0);
    //     *(this + 0x155C) = newCount;
    //     for (int i = 0; i < newCount; ++i) {
    //       int id = *(*(src + 56*i) + 4);
    //       *(this + 0x1560 + i) = id;
    //       *(this + 0) = soundMethod(*(this + 0x1100), id, 1);
    //     }
    //     return *(this + 0x155C);
    //   }
    // UNRESOLVED: Identity of the sound object at this+0x1100 and the exact role of the vtable method at +0xB8 (flag 0 vs flag 1 semantics inferred as remove/add from call order).
    // UNRESOLVED: Structure of the source entries: only the ID at +4 of each dereferenced entry and the 56-byte stride are known.
    // UNRESOLVED: Purpose of the result stored into this+0x0 on each call is unknown.
}
