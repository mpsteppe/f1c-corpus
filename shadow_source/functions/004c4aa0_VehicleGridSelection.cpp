// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C4AA0
// Canonical corpus name: VehicleGridSelection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleGridSelection_004c4aa0.c

void UnknownObject::VehicleGridSelection()
{
    // Scans the vehicle grid (dword_8AC394 array of dword_8AC390 slots) and appends a linked-list node for each slot that is not already registered in the keyed list and whose per-slot field at byte offset 444 matches every value in the caller-supplied selection array a2[0..a3-1]. Returns the number of slots appended.
    // GUARD: Early exit to result 0 when *a2 is zero, when a3 is not positive, or when dword_8AC390 (slot count) is not positive. [source:raw, global:0x008AC390, function:0x004C4AA0]
    // ASSIGNMENT: Initialize slotIndex=0, matchedCount=0, slotByteOffset=0, slotCount=dword_8AC390. [source:raw, global:0x008AC390]
    // LOOP: do-while over slotIndex < slotCount (dword_8AC390); each iteration advances slotByteOffset by 1060 bytes, the stride of one slot record in the dword_8AC394 table. [source:raw, global:0x008AC390, global:0x008AC394]
    // CALL: LinkedListKeySearch(slotIndex): query whether the slot is already present in the keyed linked list; a nonzero result marks the slot as already registered. [callee:0x004C4CB0, source:raw]
    // GUARD: Skip the slot when LinkedListKeySearch reports it is already registered, or when the slot record base (dword_8AC394 + slotByteOffset) is null. [callee:0x004C4CB0, global:0x008AC394, source:raw]
    // CALCULATION: slotMatchField = dword_8AC394 + slotByteOffset + 444, pointing at the per-slot field compared against the requested selections. [global:0x008AC394, source:raw]
    // LOOP: while sub_566810(slotMatchField, a2[selectionCursor]) is zero, advance selectionCursor; the slot matches only when every a2[0..a3-1] compares equal at that field. [callee:0x00566810, source:raw]
    // CALL: OperatorNewNhMallocWrapper(4) allocates a 4-byte node storing the slot index (slotIndexNode = slotIndex). [callee:0x00587C03, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a 12-byte linked-list link: link[0] holds the slotIndexNode pointer, link[4] the next pointer initialized to 0, link[8] a byte flag initialized to 1. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Append the new link to the list: when head (this+0x8) is null set head and this+0x10 to the link; otherwise chain tail->next = link. Then tail (this+0xC) becomes the link and the count at this+0x14 increments. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Increment matchedCount for every slot appended to the list. [source:raw]
    // RETURN: Return matchedCount, the number of grid slots appended; the guarded path returns 0. [source:raw, function:0x004C4AA0]

    // Conservative worker pseudocode:
    //   // grid slots live at dword_8AC394, count in dword_8AC390, stride 1060 bytes
    //   matchedCount = 0;
    //   if (*selection && count > 0 && dword_8AC390 > 0) {
    //     for (slotByteOffset = 0; slotIndex < dword_8AC390; slotIndex++, slotByteOffset += 1060) {
    //       if (LinkedListKeySearch(slotIndex) == 0 && (dword_8AC394 + slotByteOffset) != 0) {
    //         if (all of a2[0..count-1] match *(dword_8AC394 + slotByteOffset + 444)) {
    //           slotIndexNode = OperatorNewNhMallocWrapper(4);
    //           *slotIndexNode = slotIndex;
    //           link = OperatorNewNhMallocWrapper(12);
    //           link->value = slotIndexNode; link->next = 0; link->flag = 1;
    //           if (this->head == 0) { this->head = link; this->first = link; }
    //           else { this->tail->next = link; }
    //           this->tail = link; this->count++;
    //           matchedCount++;
    //         }
    //       }
    //     }
    //   }
    //   return matchedCount;
    // UNRESOLVED: Semantics of sub_566810 comparison (equality of the slot field at byte offset 444 against selection values) are unknown; the field itself is unnamed.
    // UNRESOLVED: this+0x10 (this[4]) is written equal to the head link at list creation but is never read in this function; its role is unresolved.
    // UNRESOLVED: Meaning of the link byte flag at offset 8 (initialized to 1) is unresolved.
    // UNRESOLVED: Caller context at sub_4C4D50 is unknown, so the selection array a2 contents cannot be interpreted.
}
