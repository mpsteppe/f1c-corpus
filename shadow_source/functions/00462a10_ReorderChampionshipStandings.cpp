// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462A10
// Canonical corpus name: ChampionshipStandingsReOrdering
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChampionshipStandingsReOrdering_00462a10.c

void UnknownObject::ReorderChampionshipStandings()
{
    // Re-orders championship standings after a race result. When the entry count at obj+0x3E14 is positive, builds a linked list of sort nodes (driver index, stored value, planned position) from per-entry flag bits and the value table, merge-sorts the list by value, writes fresh sequential positions into the dword_5F0730 grid up to dword_7C9530, writes the final positions back into the standings object at offsets 0x3FD6/0x3FD9, then frees every allocated node.
    // GUARD: Guard on the entry count at obj+0x3E14 being greater than 0; the linked-list build loop only runs when at least one entry exists. [field:obj:0x00003E14, guard:0, source:raw]
    // LOOP: Iterate driver entries: test bit 2 of the per-entry flag field (offset 916) via FlagBitTest to decide whether the driver has a valid result; when set, read the driver index from offset 1040, otherwise use -1. [callee:0x00461530, source:raw]
    // CALL: Allocate a 12-byte sort node with OperatorNewNhMallocWrapper and store driver index, the per-entry value read from the value table (initial offset 15476, stride 4), and the planned position looked up from dword_5F0730 at index 4656 * driverIndex. [callee:0x00587C03, global:0x005F0730, source:raw]
    // CALL: Allocate a 12-byte list node with OperatorNewNhMallocWrapper, link it after the previous tail, and increment the node counter. [callee:0x00587C03, source:raw]
    // CALL: Merge-sort the built linked list with LinkedListMergeSort_47d0 so entries are ordered by their stored value. [callee:0x004647D0, source:raw]
    // LOOP: Walk to the tail of the sorted list by following the next-node link at offset 4 of each node. [source:raw]
    // LOOP: Write fresh sequential positions (starting at 1) into the dword_5F0730 grid, advancing by 4656 dwords per entry until the end pointer dword_7C9530 is reached. [global:0x005F0730, global:0x007C9530, source:raw]
    // ASSIGNMENT: Walk the sorted list again writing each entry's stored value to the standings object at offset 16342 (4 * position + *v1) and the new position into dword_5F0730 indexed by driver; then write the final re-ordered count as a byte at offset 16345. [field:obj:0x00003FD9, global:0x005F0730, source:raw]
    // LOOP: Free every list node and, when the node's payload flag (byte at offset 8) is set, also free the contained sort node, using FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the standings object base pointer (*this). [field:this:0x00000000, source:raw]
    // CALL: Called by MultiplayerVehiclePlacement (0x0042CF10) to re-order championship standings after a race result. [caller:0x0042CF10, source:raw]

    // Conservative worker pseudocode:
    //   int ReorderChampionshipStandings(obj) {
    //     head = tail = NULL; count = 0;
    //     if (obj->count(0x3E14) > 0) {
    //       for (i = 0; i < obj->count(0x3E14); ++i) {
    //         driver = FlagBitTest(obj->flags(916, i), 2) ? obj->driverIdx(1040, i) : -1;
    //         val = valueTable[15476 + 4 * i];
    //         pos = driver >= 0 ? dword_5F0730[4656 * driver] : -1;
    //         node = malloc(12); node->{driver, val, pos} = {driver, val, pos};
    //         listNode = malloc(12); listNode->data = node; link(tail, listNode); ++count;
    //       }
    //     }
    //     sorted = LinkedListMergeSort_47d0(head);
    //     /* renumber grid * / for (p = dword_5F0730; p < dword_7C9530; p += 4656) *p = ++n;
    //     for (node = sorted; node; node = node->next) {
    //       *(*v1 + 4 * pos + 16342) = node->data->val;
    //       if (node->data->driver >= 0) dword_5F0730[4656 * node->data->driver] = pos;
    //     }
    //     *((byte*)*v1 + 16345) = pos - 1;
    //     for (node = sorted; node; ) { tmp = node->next; if (node->flag) FreeWrapper_7bcf(node->data); FreeWrapper_7bcf(node); node = tmp; }
    //     return *v1;
    //   }
    // UNRESOLVED: The object behind *this (v1[0]) is unnamed; offsets 916/1040 are per-entry flag and driver-index fields whose struct type is not identified.
    // UNRESOLVED: The value table starting at offset 15476 and the flag/driver-entry stride 140 are taken from the loop arithmetic only; their container type is unknown.
    // UNRESOLVED: dword_5F0730 is treated as a per-driver position grid of stride 4656 dwords; its exact element layout is not independently confirmed.
}
