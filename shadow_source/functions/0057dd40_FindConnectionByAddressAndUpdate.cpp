// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057DD40
// Canonical corpus name: sub_57DD40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57DD40_0057dd40.c

void UnknownObject::FindConnectionByAddressAndUpdate()
{
    // Acquires a mutex-protected connection list, walks entries comparing two stored address-family/port pairs against the caller's a2 values, and on a match calls SetterAt0x24 to update the matched node and writes to offset 28 of a caller-known target. Returns 1 on match/update and 0 otherwise, always releasing the mutex. Network connection lookup/update.
    // ASSIGNMENT: Load the mutex handle from this+0xABC (decompiler this[687]) and the wait timeout from this+0xAC0 (this[688]); cursor base is &this[683] = this+0xAAC. [field:this:0x00000ABC, field:this:0x00000AC0, field:this:0x00000AAC]
    // GUARD: Guard on mutex handle being non-null and WaitForSingleObject returning 0 (acquired) or 128 (WAIT_ABANDONED): only then is the search cursor enabled; otherwise the search body is skipped and the function returns 0. [global:0x0059E1A0, field:this:0x00000ABC, field:this:0x00000AC0]
    // CALL: Call WaitForSingleObject with the mutex handle this+0xABC and the timeout value this+0xAC0 to gate the list traversal. [global:0x0059E1A0, field:this:0x00000ABC, field:this:0x00000AC0]
    // ASSIGNMENT: Initialize the traversal cursor at this+0xAB4 to the list head read from *(this+0xAAC). [field:this:0x00000AB4, field:this:0x00000AAC]
    // GUARD: Guard on the list head being non-null: empty list skips traversal and returns 0. [field:*(this+0xAAC):0x00000000]
    // LOOP: Walk the connection nodes; a node matches when (node data +4 equals a2[1] and node data +2 word equals HIWORD(a2[0])) or (node data +20 equals a2[1] and node data +18 word equals HIWORD(a2[0])). Compare fields are the two stored address-family/port pairs. [field:*(this+0xAB8):0x00000004, field:*(this+0xAB8):0x00000002, field:*(this+0xAB8):0x00000014, field:*(this+0xAB8):0x00000012, field:this:0x00000AB8]
    // CALL: On match, call SetterAt0x24 with the matched node data and the caller's a3 to update the connection entry. [callee:0x0057B6C0]
    // ASSIGNMENT: Write a4-style value to offset 28 of a caller-known target (decompiler registers v13/v14 are undefined here; the concrete target is not recoverable from this function alone). [source:raw]
    // STATE_TRANSITION: Set the return flag to 1 to signal a match was found and updated. [source:raw]
    // CALL: Always release the mutex handle at this+0xABC via ReleaseMutex before returning. [global:0x0059E1A4, field:this:0x00000ABC]
    // RETURN: Return the match flag (1 if found and updated, 0 otherwise). [source:raw]

    // Conservative worker pseudocode:
    //   char FindConnectionByAddressAndUpdate(this, a2, a3) {
    //     handle = this->mutex;                   // this+0xABC
    //     list = this + 0xAAC;
    //     cursor = 0;
    //     if (handle && (WaitForSingleObject(handle, this->timeoutMs) == 0 || == 128)) {
    //       cursor = list->head;                  // this+0xAB4 = *(this+0xAAC)
    //       nodeData = cursor->data;
    //       if (cursor) {
    //         while (nodeData
    //             && !((nodeData[+4] == a2[1] && HIWORD(a2[0]) == *(u16*)(nodeData+2))
    //                  || (nodeData[+20] == a2[1] && HIWORD(a2[0]) == *(u16*)(nodeData+18)))) {
    //           cursor = cursor->next;
    //           nodeData = cursor ? cursor->data : 0;
    //         }
    //         if (nodeData) {
    //           SetterAt0x24(nodeData, a3);
    //           *(v13 + 28) = v14;                // target unknown (undefined regs)
    //           return 1;
    //         }
    //       }
    //     }
    //     if (this->mutex) ReleaseMutex(this->mutex);
    //     return 0;
    //   }
    // UNRESOLVED: The write to offset 28 after SetterAt0x24 uses decompiler registers v13/v14 that are never assigned in this function; the concrete write target is unknown.
    // UNRESOLVED: The exact layout of the node data (two family/port pairs at +2/+4 and +18/+20) is inferred from comparison operands, not a named struct.
    // UNRESOLVED: The two address-family/port pairs' respective roles (primary/secondary or IPv4/IPv6) are not established.
    // UNRESOLVED: Caller sub_5813E0's and NetworkPacketSend_0c10's usage of the returned node is outside this function.
}
