// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C4FF0
// Canonical corpus name: SeasonSceneMatchByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonSceneMatchByIndex_004c4ff0.c

void UnknownObject::SeasonSceneMatchByIndex()
{
    // Searches a linked list of vehicle indices (this[4] cursor, starting at this[2] head) for a node whose vehicle name matches the search string a2. For each candidate index it computes the vehicle entry at dword_8AC394 + 1060 * index, reads the entry name (falling back to byte_5EA438 when null), and compares it with sub_588410. On match it stores the 0-based match position in this[6]; on failure (empty list or no match) it stores 0. Returns the last result value (null on the failure paths).
    // ASSIGNMENT: Set the iteration cursor this[4] to the list head pointer this[2]. [field:this:0x00000008, field:this:0x00000010, source:raw]
    // GUARD: If the head is null, result stays null; otherwise read the head node's data pointer into result. [field:this:0x00000008, field:*(this+0x8):0x00000000, source:raw]
    // ASSIGNMENT: Initialize the 0-based match counter to 0. [source:raw]
    // GUARD: If the initial result is null the list is empty: set this[6] = 0 and return null. [field:this:0x00000018, source:raw]
    // LOOP: Iterate while the current node's data pointer (this[4]) is non-null; the node data is a vehicle index. [field:this:0x00000010, field:*(this+0x10):0x00000000, source:raw]
    // CALCULATION: Compute the vehicle entry address as dword_8AC394 + 1060 * vehicleIndex. [global:0x008AC394, source:raw]
    // GUARD: If the entry exists, read its name pointer; substitute byte_5EA438 as the name when the entry's pointer is null. [global:0x005EA438, source:raw]
    // CALL: Compare the search string a2 against the vehicle name via sub_588410; a zero return signals a match and breaks the loop. [callee:0x00588410, source:raw]
    // ASSIGNMENT: Advance the cursor: read this[4], set this[4] to the next node via *(this[4] + 4), and increment the match counter. [field:this:0x00000010, source:raw]
    // STATE_TRANSITION: On a match, store the 0-based match position in this[6]. [field:this:0x00000018, source:raw]
    // RETURN: Return the current result value: null on the empty-list and not-found paths, and the last sub_588410 return value on the match path. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4C4FF0(_DWORD *this, int searchString) {
    //     this[4] = this[2];
    //     int matchIndex = 0;
    //     _DWORD *result = this[2] ? *this[2] : 0;
    //     if (result) {
    //       while (result) {
    //         char *entry = (char *)(dword_8AC394 + 1060 * *result);
    //         if (entry) {
    //           char *name = *entry ? *entry : byte_5EA438;
    //           if (!sub_588410(searchString, name)) break;
    //         }
    //         matchIndex++;
    //         if (this[4]) this[4] = *(this[4] + 4);
    //         result = this[4] ? *this[4] : 0;
    //       }
    //       this[6] = matchIndex;
    //     } else {
    //       this[6] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Field this+0x14 appears in the deterministic field facts (read-only) but is never referenced by the shown pseudocode; its role is unknown.
    // UNRESOLVED: The exact return semantics of sub_588410 (0 on match) is inferred from the control flow, not confirmed.
    // UNRESOLVED: The meaning of the constant stride 1060 on dword_8AC394 and the relationship to the 'count' field are unresolved.
}
