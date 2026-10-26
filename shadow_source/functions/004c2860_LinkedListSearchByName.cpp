// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2860
// Canonical corpus name: LinkedListSearchByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListSearchByName_004c2860.c

void UnknownObject::LinkedListSearchByName()
{
    // Walks a linked list to find the node whose name string matches a target string a2. Seeds the cursor field this+0x18 with the list-head pointer read from this+0x10; returns 0 immediately when the head is null. Each iteration reads the current node's name pointer (at node+8), falling back to byte_5EA438 when it is null, and compares it against a2 via sub_588410. On a match it breaks and returns the node pointer; otherwise it advances the cursor to the next node (pointer at cursor+4) and continues until the end of the list, returning 0. Callers: PlayerCareerStatsGameOptionsLoader (0x004C18B0) and TrackSceneNodeAdd (0x004C28D0).
    // ASSIGNMENT: Seed the list cursor this+0x18 with the list-head pointer read from this+0x10. [field:this:0x00000010, field:this:0x00000018, source:raw]
    // GUARD: Guard: if the list head this+0x10 is null, return 0 (empty list, not found). [field:this:0x00000010, function:0x004C2860, source:raw]
    // ASSIGNMENT: Read the first node pointer v4 from the head dereference (*head); if null, fall through to return. [field:this:0x00000010, source:raw]
    // LOOP: Iterate over nodes while the current node pointer is non-null. [source:raw]
    // ASSIGNMENT: Read the current node's name string pointer at node+8; when null, use the default path byte_5EA438. [field:*(this+0x10):0x00000008, global:0x005EA438, source:raw]
    // CALL: Call sub_588410(name, a2); a zero result means the names match and the walk breaks. [callee:0x00588410, source:raw]
    // ASSIGNMENT: Advance the cursor this+0x18 to the next node (pointer stored at cursor+4). [field:this:0x00000018, source:raw]
    // GUARD: Guard: if advancing the cursor this+0x18 produces null, return 0 (end of list reached without a match). [field:this:0x00000018, function:0x004C2860, source:raw]
    // RETURN: Return v4: the matching node pointer when sub_588410 returned 0, otherwise the last visited node (or 0 via the guards). [function:0x004C2860, source:raw]

    // Conservative worker pseudocode:
    //   cursor = this->head;
    //   if (!cursor) return 0;
    //   node = *cursor;
    //   while (node) {
    //       name = *(char**)(node + 8);
    //       if (!name) name = byte_5EA438;
    //       if (sub_588410(name, target) == 0) break;
    //       cursor = *(int**)(cursor + 4);
    //       if (!cursor) return 0;
    //       node = *cursor;
    //   }
    //   return node;
    // UNRESOLVED: Node layout is inferred from the dereference pattern: name pointer at node+8, next pointer at cursor+4, and head indirection (this+0x10 holds a pointer to the first-node pointer, not the node itself).
    // UNRESOLVED: sub_588410 is read as a string-equality check (0 on match) from the break-on-zero pattern only; its own contract is not independently confirmed.
    // UNRESOLVED: Packet field this+0x1C (read-only) is not referenced by the raw source; its role is unresolved.
}
