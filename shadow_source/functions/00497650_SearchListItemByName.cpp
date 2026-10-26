// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497650
// Canonical corpus name: UIListItemSearchByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListItemSearchByName_00497650.c

void UnknownObject::SearchListItemByName()
{
    // Searches a linked list rooted at this+0x4 for the first node whose name string matches the argument a2, using sub_588410 as the comparison predicate (returns 0 on match, per the existing analysis). The head pointer this[1] (+0x4) is cached into this[3] (+0xC), which is advanced to the next node (+4) on each non-matching iteration. For each node the name string is read from node+0x34, defaulting to the global byte_5EA438 when null. Returns the matched node's data dword (v4) or 0 when the list is empty, exhausted, or no node matches.
    // ASSIGNMENT: Cache the list head: this[3] (+0xC) = this[1] (+0x4). [field:this:0x00000004, field:this:0x0000000C, function:0x00497650, source:raw]
    // GUARD: If the head pointer this[1] (+0x4) is null, return 0. [field:this:0x00000004, function:0x00497650, source:raw]
    // GUARD: Read v4 = *head; if the first node's data dword is null, return 0. [field:this:0x00000004, function:0x00497650, source:raw]
    // LOOP: Traversal loop over the linked list, keyed on the current node data v4. [field:*(this+0x4):0x00000034, function:0x00497650, source:raw]
    // ASSIGNMENT: Read the node name v5 = *(char **)(v4 + 0x34); if it is null, substitute the global default byte_5EA438. [field:*(this+0x4):0x00000034, global:0x005EA438, function:0x00497650, source:raw]
    // CALL: Compare via sub_588410(name, a2); when the predicate returns 0 the node matches and the loop breaks. [callee:0x00588410, function:0x00497650, source:raw]
    // ASSIGNMENT: On a non-match, advance this[3] (+0xC) to the next node: this[3] = *(int *)(this[3] + 4) when this[3] is non-null. [field:this:0x0000000C, function:0x00497650, source:raw]
    // GUARD: After advancing, if this[3] (+0xC) or its data dword *this[3] is null, return 0 (list exhausted); otherwise reload v4 = *this[3] and continue. [field:this:0x0000000C, function:0x00497650, source:raw]
    // RETURN: Return the matched node's data dword v4, or 0 when no match / empty / exhausted. [function:0x00497650, source:raw]

    // Conservative worker pseudocode:
    //   current = this[3] = this[1];
    //   if (!this[1]) return 0;
    //   data = *this[1];
    //   if (!data) return 0;
    //   while (1) {
    //     name = *(char **)(data + 0x34);
    //     if (!name) name = byte_5EA438;
    //     if (sub_588410(name, a2) == 0) break;
    //     if (this[3]) this[3] = *(int *)(this[3] + 4);
    //     if (!this[3]) return 0;
    //     data = *this[3];
    //     if (!data) return 0;
    //   }
    //   return data;
    // UNRESOLVED: The packet lists this+0x10 (this[4]) as a read-only field, but the raw source never accesses it; it may belong to the same object without being touched by this search.
    // UNRESOLVED: sub_588410 is assumed to be a string comparison returning 0 on equality from the existing analysis fill; its exact contract is not established by the packet.
    // UNRESOLVED: The node identity (first dword), the +4 next link and the +0x34 name offset define a linked-list layout, but the node and list-owner object types are unidentified.
    // UNRESOLVED: The single caller sub_49A5D0 (0049A5D0) indicates UI list usage but is not analyzed here.
}
