// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455560
// Canonical corpus name: ArrayIndexedAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayIndexedAccessor_00455560.c

void UnknownObject::NullCheckedSlotPointerAccessor()
{
    // Bound-checked __thiscall accessor over a pointer array embedded in the object. For an index a2 below 44 it reads the entry at this[2*a2 + 2220] and returns it; a null entry falls back to the global byte_5EA438, and an out-of-range index returns 0. Called from MessageNameBufferUpdate, SessionEntryListCleanup and KeyBindingUIPressKeyOrController.
    // ASSIGNMENT: Initialize the default result to 0 before any guard. [source:raw]
    // GUARD: Only when a2 is less than 44 is the object array consulted; otherwise the function falls through returning 0. [source:raw]
    // ASSIGNMENT: Read the entry pointer at this[2 * a2 + 2220]; the 2-dword index step means array entries are 8 bytes apart with the pointer in the first dword. [source:raw]
    // GUARD: If the entry pointer is null, return the global byte_5EA438 as the fallback value. [source:raw, global:0x005EA438]
    // RETURN: Return the non-null entry pointer, the byte_5EA438 fallback, or 0 for an out-of-range a2. [source:raw]
    // CALL: Shared by MessageNameBufferUpdate (0x0046AD50), SessionEntryListCleanup (0x0046AE60) and KeyBindingUIPressKeyOrController (0x0046B0C0) to fetch a per-slot string or name pointer. [caller:0x0046AD50, caller:0x0046AE60, caller:0x0046B0C0, source:raw]

    // Conservative worker pseudocode:
    //   char *sub_455560(_DWORD *this, int a2) {
    //     char *result = 0;
    //     if (a2 < 44) {
    //       result = (char *)this[2 * a2 + 2220];
    //       if (!result) return byte_5EA438;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: What the array entries point at and the meaning of the byte_5EA438 fallback are not established from this packet
    // UNRESOLVED: The caller mix (message buffer, session cleanup, key-binding UI) does not pin down a single object type for this
}
