// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599485
// Canonical corpus name: sub_599485
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_599485_00599485.c

void UnknownObject::StepCounterPair()
{
    // Consumes one unit from a paired counter pair: pre-decrements the counter reached through the pointer at this+0x30 (remaining count), then post-increments the counter reached through the pointer at this+0x20 and returns its previous value.
    // CALCULATION: Pre-decrement the DWORD counter that the pointer stored at this+0x30 points to (remaining-capacity counter). [field:*(this+0x30):0x00000000, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Load the current-position counter pointer v1 = *(this+0x20) (pointer to a DWORD counter). [field:this:0x00000020, source:raw]
    // RETURN: Post-increment the DWORD at *v1 (the counter pointed to by this+0x20) and return its previous value. [field:*(this+0x20):0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   --**(this + 0x30);
    //   _DWORD* counter = *(this + 0x20);
    //   return (*counter)++;
    // UNRESOLVED: Raw source increments the DWORD VALUE at the pointer stored in this+0x20, not the pointer itself; the streambuf put-pointer-advance reading in the existing analysis conflicts with that spelling.
    // UNRESOLVED: Exact role of the two counters (remaining count vs. current position) and their owner object are unproven; legacy ABI names the type Unidentified_Logic_Pointer_Indirection_Counter_T.
}
