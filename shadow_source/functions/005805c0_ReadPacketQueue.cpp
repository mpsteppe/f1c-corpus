// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005805C0
// Canonical corpus name: NetworkPacketQueueReader
// Owner: NetworkPacketQueueReader [DERIVED]
// Raw source: functions/NetworkPacketQueueReader_005805c0.c

void NetworkPacketQueueReader::ReadPacketQueue()
{
    // Reads a packet element from a mutex-protected dual-list queue. First attempts the fast list (this+0xB74): waits on its mutex (this+0xB94), runs ShortComputation_a780, and validates the head element through sub_583430; if none is available it calls sub_582780 and LinkedListElementRemovalWithCleanup to obtain one. It then takes the second list (this+0xB48): waits on its mutex (this+0xB68), reads/advances the cursor (this+0xB58 -> this+0xB60), validating through sub_5832E0 and falling back to sub_5823C0 plus a re-read. The second-list result is written into the first-list element data field at +0x48 (base this+0xB8C) and returned.
    // GUARD: First list: if the mutex handle at this+0xB94 is non-null, wait on it with timeout this+0xB98; proceed with the first list only when WaitForSingleObject returns 0 (signalled) or 128 (timeout), else no list is selected. [global:0x0059E1A0, field:this:0x00000B94, field:this:0x00000B98, source:raw]
    // CALL: Run ShortComputation_a780 on the first-list cursor structure to prepare it. [callee:0x004BA780, source:raw]
    // GUARD: If the first list holds a node, read its data value, clear the node's +8 flag byte, and validate the data through sub_583430(value, 1); a failing validation treats the list as empty. [callee:0x00583430, source:raw]
    // CALL: When the first list produced no element: call sub_582780 on the list, then LinkedListElementRemovalWithCleanup on the cursor to pull an element out. [callee:0x00582780, callee:0x00582B10, source:raw]
    // CALL: Release the first-list mutex (this+0xB94) via ReleaseMutex when it is present. [global:0x0059E1A4, field:this:0x00000B94, source:raw]
    // GUARD: Second list: if the mutex handle at this+0xB68 is non-null, wait on it with timeout this+0xB6C; proceed with the second list only when WaitForSingleObject returns 0 (signalled) or 128 (timeout), else no list is selected. [global:0x0059E1A0, field:this:0x00000B68, field:this:0x00000B6C, source:raw]
    // ASSIGNMENT: Read the second-list cursor element from this+0xB58 and store it into this+0xB60. [field:this:0x00000B58, field:this:0x00000B60, source:raw]
    // CALL: If the second-list cursor element is present, clear its +8 flag byte and validate the data through sub_5832E0(value, 1); a failing validation treats it as empty. [callee:0x005832E0, source:raw]
    // CALL: When the second list still has no element: call sub_5823C0 on the list, re-run ShortComputation_a780 on its cursor, re-read this+0xB60, and validate through sub_5832E0(value, 1). [callee:0x005823C0, callee:0x004BA780, callee:0x005832E0, field:this:0x00000B60, source:raw]
    // ASSIGNMENT: Write the second-list element result into the first-list element data field at +0x48, whose pointer base is this+0xB8C. [field:*(this+0xB8C):0x00000048, field:this:0x00000B8C, source:raw]
    // CALL: Release the second-list mutex (this+0xB68) via ReleaseMutex when it is present. [global:0x0059E1A4, field:this:0x00000B68, source:raw]
    // RETURN: Return the first-list element value. [source:raw]

    // Conservative worker pseudocode:
    //   // Read one packet element from a dual-list mutex-protected queue.
    //   // Fast path: first list (base this+733, mutex this[741] / this+0xB94).
    //   void* list1 = 0;
    //   if (this[741]) {
    //       DWORD r = WaitForSingleObject(this[741], this[742]);
    //       if (r == 0 || r == 128) list1 = this + 733;
    //   }
    //   ShortComputation_a780(list1 + 4);
    //   elem1 = 0;
    //   if (list1[2]) {
    //       elem1 = *(list1[2]);
    //       *((BYTE*)list1[2] + 8) = 0;
    //       if (!sub_583430(elem1, 1)) elem1 = 0;
    //   }
    //   if (!elem1) {
    //       sub_582780(list1);
    //       elem1 = LinkedListElementRemovalWithCleanup(list1 + 4);
    //   }
    //   if (this[741]) ReleaseMutex(this[741]);
    //   // Slow path: second list (base this+722, mutex this[730] / this+0xB68).
    //   void* list2 = 0;
    //   if (this[730]) {
    //       DWORD r = WaitForSingleObject(this[730], this[731]);
    //       if (r == 0 || r == 128) list2 = this + 722;
    //   }
    //   elem2 = list2[4];
    //   list2[6] = elem2;
    //   if (elem2) {
    //       elem2 = *elem2;
    //       *((BYTE*)list2[4] + 8) = 0;
    //       if (!sub_5832E0(elem2, 1)) elem2 = 0;
    //   }
    //   if (!elem2) {
    //       sub_5823C0(list2);
    //       ShortComputation_a780(list2 + 4);
    //       if (list2[6]) {
    //           elem2 = *(list2[6]);
    //           if (!sub_5832E0(elem2, 1)) elem2 = 0;
    //       }
    //   }
    //   *(elem1 + 72) = elem2;
    //   if (list2[8]) ReleaseMutex(list2[8]);
    //   return elem1;
    // UNRESOLVED: Element data structure layout and the meaning of the field written at element +0x48 are unknown.
    // UNRESOLVED: Validation semantics of sub_583430 and sub_5832E0 (second argument 1) are unknown; they gate whether an element is accepted.
    // UNRESOLVED: Relationships between the first and second lists (producer/consumer pairing) are caller-established and not visible here.
}
