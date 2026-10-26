// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462330
// Canonical corpus name: IDLookupInArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDLookupInArray_00462330.c

void UnknownObject::IDLookupInArray()
{
    // Returns the index of a target ID within a 104-entry DWORD array. Reads the object pointer from this+0, obtains the target ID by calling SingleFunctionCallWrapper_a810 with the value stored at obj+0x3FB8, then linearly scans the ID array at obj+0x3E18, returning the index of the first entry equal to the target or -1 when no match is found. Invoked by NetCommPlayerSlotSync (0x0045FC50) to map a queried ID to a player-slot index.
    // CALL: Read the object pointer from this+0, read the ID value stored at obj+0x3FB8, and call SingleFunctionCallWrapper_a810 with it; store the returned target ID in targetId. [callee:0x0057A810, field:this:0x00000000, field:obj:0x00003FB8]
    // ASSIGNMENT: Initialize matchIndex to 0 before starting the array scan. [source:raw]
    // LOOP: Scan the DWORD array starting at obj+0x3E18, comparing each entry against targetId; iteration continues while the current entry does not equal targetId. [field:obj:0x00003E18, abi:lead, source:raw]
    // GUARD: Increment matchIndex on each array step; if it reaches 104 (the full array scanned without a match), return -1. [function:0x00462330, source:raw]
    // RETURN: Return matchIndex, the index of the first array entry equal to the target ID, or -1 when no entry matches. [function:0x00462330, source:raw]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   targetId = SingleFunctionCallWrapper_a810(*(obj + 0x3FB8));
    //   matchIndex = 0;
    //   for (cursor = obj + 0x3E18; *cursor != targetId; ++cursor) {
    //       if (++matchIndex >= 104) return -1;
    //   }
    //   return matchIndex;
    // UNRESOLVED: The owning class/object is unidentified; only its observable layout is known (ID array at obj+0x3E18, value source at obj+0x3FB8) and that it is called from NetCommPlayerSlotSync.
    // UNRESOLVED: The meaning of the value passed to SingleFunctionCallWrapper_a810 and of its return (what the target ID represents) is not resolved.
}
