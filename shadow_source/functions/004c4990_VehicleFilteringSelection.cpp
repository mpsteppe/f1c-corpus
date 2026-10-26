// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C4990
// Canonical corpus name: VehicleFilteringSelection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleFilteringSelection_004c4990.c

void UnknownObject::VehicleFilteringSelection()
{
    // Filters the global vehicle array by a caller-supplied criteria list, skipping vehicles already present in an exclusion keyed list, and appends each fully matching vehicle index to a linked list owned by the this object (head/tail/first/count). Returns the number of matches.
    // GUARD: Proceed only if the first criteria word *a2 is non-zero; otherwise return 0 immediately. [source:raw]
    // GUARD: Proceed only if the criteria count a3 is greater than 0. [source:raw]
    // GUARD: Proceed only if dword_8AC390 (vehicle count) is greater than 0. [global:0x008AC390, source:raw]
    // LOOP: Iterate vehicle index v6 from 0 to dword_8AC390, advancing the byte offset v12 by the 1060-byte vehicle stride from the array base dword_8AC394. [global:0x008AC390, global:0x008AC394, source:raw]
    // GUARD: Skip the slot when LinkedListKeySearch(v6) is non-zero (index already in the exclusion list) or when the vehicle pointer at dword_8AC394 + v12 is null. [callee:0x004C4CB0, global:0x008AC394, source:raw]
    // CALL: Inner criteria loop: compare vehicle field at byte offset 444 against each criteria value a2[v7] via sub_566810; break out when the comparison returns 0 (mismatch). [callee:0x00566810, source:raw]
    // GUARD: Accept the vehicle only when the criteria loop consumed all a3 criteria (matched every value). [source:raw]
    // CALL: Allocate a 4-byte cell via OperatorNewNhMallocWrapper and store the matching vehicle index v6 in it. [callee:0x00587C03, source:raw]
    // CALL: Allocate a 12-byte node via OperatorNewNhMallocWrapper; initialize value pointer to the index cell, next pointer to 0, and flag byte at +8 to 1; on allocation failure node is null. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Append the node to the result list: if this+0x8 (tail) is non-null link tail->next else set this+0x8 (head) and this+0x10 (first) to the node; set this+0xC (tail) to the node and increment this+0x14 (count). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return v13, the number of vehicles appended to the result list; return 0 on any failed guard. [source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (*criteria && criteria_count > 0 && dword_8AC390 > 0) {
    //     for (i = 0; i < dword_8AC390; ++i) {
    //       if (!LinkedListKeySearch(i) && vehicle[i]) {
    //         matched = 0;
    //         while (matched < criteria_count && sub_566810(vehicle[i] + 444, criteria[matched])) ++matched;
    //         if (matched == criteria_count) {
    //           cell = OperatorNewNhMallocWrapper(4); *cell = i;
    //           node = OperatorNewNhMallocWrapper(12);
    //           if (node) { *(int*)node = cell; *(int*)(node+4) = 0; *(char*)(node+8) = 1; }
    //           append(node, &this->head, &this->tail, &this->first, &this->count);
    //           ++result;
    //         }
    //       }
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Semantics of the node flag byte at offset +8 (1 on creation) are not established.
    // UNRESOLVED: Exact comparison contract of sub_566810: a 0 return is treated as a mismatch, but its operands and field meaning are not independently confirmed.
    // UNRESOLVED: Relationship between this+0x10 (first, set only on first insertion) and this+0x8 (head) is not fully resolved.
    // UNRESOLVED: Single caller sub_4C4D50 (0x004C4D50) not yet characterized; the caller identity of this object is unknown.
}
