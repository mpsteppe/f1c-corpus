// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4B50
// Canonical corpus name: CollisionObjectListManagement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionObjectListManagement_004b4b50.c

void UnknownObject::ProcessCollisionObjectLists()
{
    // Manages 4 collision object sub-lists held at this+0x70 with a 16-byte metadata stride ({head, tail, anchor, count} in each). If the enable flag this+0x0 is set, re-sorts every sub-list via sub_4BAB20 and re-links head/tail/anchor, then clears the flag. Scans the count array (first entry at this+0x7C) and returns 0 when all four counts are <= 0. Computes the global minimum of the head-node float value across all four sub-lists, then removes every node whose value lies within the ±0.02 tolerance of that minimum: unlinks the node, frees it, allocates a replacement and collects it into a local chain. Writes the minimum float and removed-node count into the output record a3, dispatches each collected node through FAILWRONGDESCRIPTION_42e0 / sub_4BB490, and returns the number of nodes processed.
    // ASSIGNMENT: Initialize the result counter v30 = 0; entry into the collision object list processing flow. [abi:lead, function:0x004B4B50, source:raw]
    // GUARD: If the enable flag at this+0x0 is nonzero, rebuild the four collision sub-lists. [field:this:0x00000000, function:0x004B4B50, source:raw]
    // LOOP: For each of the 4 sub-lists (head slots at this+0x70/0x74/0x78 plus the count slot this+0x7C): sort the head node via sub_4BAB20, write the sorted head back, walk the node next links (node+4) to the tail, then store the head, tail and anchor at the slot, tail slot and anchor slot respectively. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:*(this+0x70):0x00000000, field:*(this+0x70):0x00000004, field:*(this+0x70):0x00000008, callee:0x004BAB20, function:0x004B4B50, source:raw]
    // ASSIGNMENT: After the rebuild, clear the enable flag: *this = 0, disabling the re-sort path for subsequent calls. [field:this:0x00000000, function:0x004B4B50, source:raw]
    // LOOP: Scan the sub-list count array (first entry at this+0x7C) looking for the first count > 0 (guard:1); if all four counts are <= 0, return 0. [field:this:0x0000007C, guard:1, function:0x004B4B50, source:raw]
    // LOOP: Compute the global minimum: initialize the running minimum to a large sentinel; for each of the 4 sub-lists, guard:0 checks whether the head (this+0x70 slot) is non-null, then compares the head node's +4 float value against the running minimum, keeping the smaller; the anchor slot (this+0x78, field *(this+0x70)+8) is set to the head in the same pass. [field:*(*(this+0x70)+0x0):0x00000004, field:*(this+0x70):0x00000000, field:*(this+0x70):0x00000008, guard:0, function:0x004B4B50, source:raw]
    // LOOP: For each sub-list, repeatedly remove every node whose +4 float stays within the ±0.02 tolerance of the global minimum: unlink the node and fix the head/tail/anchor slots and the count at this+0x7C, free the node via ConditionalFreeByFlagCheck and FreeWrapper_7bcf, then allocate a fresh node with OperatorNewNhMallocWrapper(12) (ShortComputation_ac20 on success) and chain it onto the local collected list. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:*(this+0x70):0x00000000, field:*(this+0x70):0x00000008, callee:0x00582290, callee:0x00587BCF, callee:0x00587C03, callee:0x004BAC20, function:0x004B4B50, source:raw]
    // ASSIGNMENT: Write the results to the output record: a3+0 receives the global minimum float, a3+8 (word) receives the count of removed nodes, then FileHandleCloseRegistration(a3, a2) is invoked. [callee:0x004B4470, function:0x004B4B50, source:raw]
    // LOOP: Walk the local collected chain: for each node, FAILWRONGDESCRIPTION_42e0(a2, minimum, node), ++result counter, sub_4BB490(node, 0), then advance via sub_4BA790(&chain); nodes consumed from the chain are destroyed through ConditionalDestructor_46f0. [callee:0x004B42E0, callee:0x004BA790, callee:0x004BB490, callee:0x004646F0, function:0x004B4B50, source:raw]
    // CALL: LinkedListFree(&chain) releases the local collected node chain. [callee:0x0049AF30, function:0x004B4B50, source:raw]
    // RETURN: Return the number of nodes processed (v30). [function:0x004B4B50, source:raw]

    // Conservative worker pseudocode:
    //   processed = 0;
    //   if (this->enabled) {
    //     for (s = 0; s < 4; s++) {
    //       head = sortSubList(this->sub[s].head);   // sub_4BAB20
    //       tail = last node reachable via next links (node+4);
    //       this->sub[s].head = head; this->sub[s].tail = tail; this->sub[s].anchor = head;
    //     }
    //     this->enabled = 0;
    //   }
    //   if (all four sub-list counts <= 0) return 0;
    //   min = large sentinel;
    //   for (s = 0; s < 4; s++)
    //     if (this->sub[s].head != 0) min = fmin(min, this->sub[s].head[+4 float]);
    //   for (s = 0; s < 4; s++) {
    //     for (n = this->sub[s].head; n != 0 && fabs(n[+4 float] - min) < 0.02;) {
    //       next = n[+4];   // next link
    //       unlink n; --this->sub[s].count;
    //       ConditionalFreeByFlagCheck(n); FreeWrapper_7bcf(n);
    //       m = OperatorNewNhMallocWrapper(12) ? ShortComputation_ac20(n, 0) : 0;
    //       append m to local chain; ++removed;
    //       n = next;
    //     }
    //   }
    //   a3[+0 float] = min; a3[+8 word] = removed;
    //   FileHandleCloseRegistration(a3, a2);
    //   for (n = chain; n != 0; n = next) {
    //     next = sub_4BA790(&chain);
    //     FAILWRONGDESCRIPTION_42e0(a2, min, n);
    //     ++processed; sub_4BB490(n, 0);
    //     ConditionalDestructor_46f0(n, 1);
    //   }
    //   LinkedListFree(&chain);
    //   return processed;
    // UNRESOLVED: Globals flt_5ACD0C and dword_8AB700 are listed as read but do not appear in the raw source text; flt_5ACD0C may back the literal ±0.02 tolerance (per prior fill prose) but that link is unconfirmed.
    // UNRESOLVED: The four sub-list metadata records are stride-16 {head, tail, anchor, count} blocks; packet fields cover only the first record (this+0x70/0x74/0x78/0x7C), leaving records 2-4 un-evidenced.
    // UNRESOLVED: Caller sub_4B7860 ties this to per-frame collision management, but the owning object type is unidentified.
}
