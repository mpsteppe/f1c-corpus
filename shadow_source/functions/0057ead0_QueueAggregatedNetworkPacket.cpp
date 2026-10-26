// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057EAD0
// Canonical corpus name: NetworkPacketSend_ead0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketSend_ead0_0057ead0.c

void UnknownObject::QueueAggregatedNetworkPacket()
{
    // Mutex-protected network packet aggregation/queueing. Computes a network-order key (htonl(0), INADDR_ANY semantics), acquires the mutex at this+0xB10 with the timeout at this+0xB14, then searches the list rooted at this+0xB00 for a node whose data first-dword equals the key. If found, updates the node data's latest-value field; otherwise allocates a 16-byte data node and a 12-byte list node via OperatorNewNhMallocWrapper and links the new node at the list tail (updating head this+0xB00, tail this+0xB04, cursor this+0xB08 and count this+0xB0C). Every call accumulates a2 into the data node's sum field and increments its counter field, then releases the mutex and returns 1. Returns 0 on missing mutex or wait failure.
    // GUARD: If the mutex handle at this+0xB10 is null, return 0 without queueing. [field:this:0x00000B10, source:raw]
    // CALL: Copy a 4-dword struct from this+673 into a stack local via Copy4DwordsStructToStruct, compute the queue key v15 as htonl(0) (network order INADDR_ANY) and call htons(0). [callee:0x0057B9F0, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: Acquire the mutex at this+0xB10 with WaitForSingleObject using the timeout value at this+0xB14. [global:0x0059E1A0, field:this:0x00000B10, field:this:0x00000B14, source:raw]
    // GUARD: If the wait result is non-zero and not equal to 128 (WAIT_ABANDONED), return 0. [field:this:0x00000B10, source:raw]
    // LOOP: Walk the list rooted at this+0xB00 from head, advancing through each node's second-dword next link, skipping nodes whose data pointer is null or whose data first-dword does not equal the key. [field:this:0x00000B00, field:*(this+0xB04):0x00000000, source:raw]
    // ASSIGNMENT: If a matching node was found, set its data node's latest-value field (data+0x4) to a2. [field:*(this+0xB04):0x00000004, source:raw]
    // ASSIGNMENT: Otherwise allocate a 16-byte data node via OperatorNewNhMallocWrapper (key first, other dwords zeroed) and a 12-byte list node; on first insert set head this+0xB00 and cursor this+0xB08, otherwise link through the tail this+0xB04; set tail this+0xB04 to the new node and increment the node count at this+0xB0C. [callee:0x00587C03, field:this:0x00000B00, field:this:0x00000B04, field:this:0x00000B08, field:this:0x00000B0C, field:*(this+0xB04):0x00000000, source:raw]
    // ASSIGNMENT: Update the data node: latest value field data+0x4 set to a2, accumulated sum field data+0x8 incremented by a2, and counter field data+0xC incremented by 1. [field:*(this+0xB04):0x00000004, field:*(this+0xB04):0x00000008, field:*(this+0xB04):0x0000000C, source:raw]
    // CALL: Release the mutex at this+0xB10 with ReleaseMutex. [global:0x0059E1A4, field:this:0x00000B10, source:raw]
    // RETURN: Return 1 on successful queue/update. [function:0x0057EAD0, source:raw]

    // Conservative worker pseudocode:
    //   key = htonl(0);
    //   if (!this[0xB10/4]) return 0;
    //   wr = WaitForSingleObject(this[0xB10/4], this[0xB14/4]);
    //   if (wr && wr != 128) return 0;
    //   node = find_node(head=this[0xB00/4], key);
    //   if (!node) { data = alloc(16); list = alloc(12); link_at_tail(); this[0xB0C/4]++; }
    //   data[1] = a2; data[2] += a2; data[3]++;
    //   ReleaseMutex(this[0xB10/4]);
    //   return 1;
    // UNRESOLVED: The 4-dword struct copied from this+673 is written into a stack local and its role relative to the key field is not fully determined from this function alone.
    // UNRESOLVED: The meaning of the accumulated sum and counter fields (data+0x8, data+0xC) as network statistics is inferred from the aggregation pattern, not independently evidenced.
    // UNRESOLVED: The node list's ownership model and lifetime (who consumes or frees the queued nodes) is not evidenced by this packet.
}
