// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3440
// Canonical corpus name: FlagBasedLoopConditionalCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagBasedLoopConditionalCall_004a3440.c

void UnknownObject::PitCrewFlaggedArrayProcessor()
{
    // Per-frame processor for a pit-crew related object array: when the pending flag (bit 0 at this+0) is set, iterates the array at this[4] (120-byte stride, entry address +100), calls Bit12FlagSet on each non-null entry, and conditionally runs UIWidgetRecursiveStateUpdate when detail level dword_7CF884 >= 2 and this[5] is non-zero. Clears flag bits 0-1 at the end.
    // GUARD: Pending-flag guard: the whole body runs only when bit 0 of the byte at this+0 is set. [field:this:0x00000000]
    // CALCULATION: Read the element count from this[3] (this+0xC); when it is not greater than 0 the loop body is skipped. [field:this:0x0000000C]
    // LOOP: Iterate the array anchored at this[4] (this+0x10): each entry at index*120 + 100 bytes, stepping 120 bytes per element. [field:this:0x00000010]
    // CALL: For each non-null array entry, set bit 12 on that pit-crew object via Bit12FlagSet. [callee:0x0054C1A0]
    // GUARD: Conditional UI update: requires the detail-level global dword_7CF884 to be >= 2 and this[5] (this+0x14) to be non-zero. [global:0x007CF884, field:this:0x00000014]
    // CALL: Recursively update widget visibility with UIWidgetRecursiveStateUpdate(0, 0, 0). [callee:0x0054C1B0]
    // ASSIGNMENT: Acknowledge the pending flag by clearing bits 0-1 at this+0 with mask 0xFFFFFFFC. [field:this:0x00000000]
    // RETURN: Return the last-read element count (this[3]). [field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   int PitCrewFlaggedArrayProcessor(Ctl* this) {
    //     int result;
    //     if (*(BYTE*)this & 1) {
    //       result = this[3];
    //       for (int i = 0; i < result; i++) {
    //         void* obj = *(DWORD*)(i*120 + this[4] + 100);
    //         if (obj) Bit12FlagSet(obj);
    //       }
    //       if (dword_7CF884 >= 2 && this[5]) UIWidgetRecursiveStateUpdate(0, 0, 0);
    //     }
    //     *this &= 0xFFFFFFFC;
    //     return result;
    //   }
    // UNRESOLVED: The concrete type and identity of the objects in the array (entry address +100, 120-byte stride) are not established from this function alone.
    // UNRESOLVED: Whether Bit12FlagSet's bit-12 set activates or enables the object is DERIVED from the surrounding fill and not proven here.
    // UNRESOLVED: Semantics of this[5] (UI-update enable) beyond a non-zero check are unknown.
}
