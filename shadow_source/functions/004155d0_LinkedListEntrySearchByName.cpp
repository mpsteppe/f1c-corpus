// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004155D0
// Canonical corpus name: LinkedListEntrySearchByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListEntrySearchByName_004155d0.c

void UnknownObject::LinkedListEntrySearchByName()
{
    // Searches a linked list (head stored at this[8] +0x20, count at this[11] +0x2C) for an entry whose string matches a2, comparing via sub_588410 which returns 0 on equality. Each node holds a string pointer at +0x0 and a next pointer at +0x4; when a node string pointer is null the global byte_5EA438 is used as the default string. Returns the matching index or -1 when a2 is null, the list is empty, or no entry matches.
    // GUARD: If a2 is null, return -1 immediately [source:raw]
    // GUARD: If the entry count this[11] (+0x2C) is not greater than 0, return -1 (empty list) [field:this:0x0000002C]
    // LOOP: Walk entries from index 0 up to the count, starting from the list head at this[8] (+0x20) and following each node's next pointer at +0x4, with bounds re-checks against this[11] [field:this:0x00000020, field:*(this+0x24):0x00000004, field:this:0x0000002C]
    // ASSIGNMENT: Read the node's string pointer at +0x0; if it is null use the global byte_5EA438 as the default string [field:*(this+0x20):0x00000000, global:0x005EA438]
    // CALL: Compare the node string against a2 with sub_588410; a return of 0 indicates a match [callee:0x00588410]
    // RETURN: Return the current index when sub_588410 reports a match, or -1 when the walk exhausts the list without a match [function:0x004155D0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return -1;
    //   if (this[11] <= 0) return -1;
    //   node = this[8];
    //   for (i = 0; i < this[11]; ) {
    //     if (node == 0) return -1;
    //     s = *(node + 0x0);
    //     if (s == 0) s = byte_5EA438;
    //     if (sub_588410(s, a2) == 0) return i;
    //     i++;
    //     node = *(node + 0x4);
    //   }
    //   return -1;
    // UNRESOLVED: sub_588410 is treated as a string comparison returning 0 on equality (DERIVED from its use as a match test); its exact prototype is not stated in the packet
    // UNRESOLVED: The object owning the list head (+0x20) and count (+0x2C) is unidentified; owner is UNKNOWN
    // UNRESOLVED: The decompiled control flow contains bounds/validation branches (LABEL_9 paths) for out-of-range indices; the linearized walk above captures the normal path and the exact out-of-range behavior is not observable from the packet
    // UNRESOLVED: byte_5EA438 is a global string constant used as a null-string fallback; its contents are not stated in the packet
}
