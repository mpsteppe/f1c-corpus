// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465D70
// Canonical corpus name: sub_465D70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_465D70_00465d70.c

void UnknownObject::MergeSortWithPriorityTable()
{
    // Recursive merge sort of a singly-linked list whose next pointer lives at node+4, using a deterministic comparator driven by a 104-entry priority table rooted at dword_7CD2AC+58384. Walks the list to count nodes, splits it at the midpoint, sorts each half recursively via self-call, then merges the halves by comparing each head's packed key: the top two bits (value>>29), a masked sub-field (value>>18 & 0x3F), the low byte with a 255 sentinel, and position in the priority table. Consumed by EntityVisibilityGridManager (00465460) for entity ordering.
    // GUARD: If the list head a1 is null, return it unchanged (empty list) [source:raw]
    // LOOP: Count the nodes by following the next pointer at node+4 until a null link is reached [field:*(this+0x4):0x00000004, source:raw]
    // GUARD: If fewer than 2 nodes, return the list unchanged as already sorted [source:raw]
    // CALCULATION: Compute the midpoint (count/2 - 1) and advance to that node via the +4 links [field:*(this+0x4):0x00000004, source:raw]
    // ASSIGNMENT: Capture the right-half head at the midpoint's next pointer, then split the list by writing 0 to the midpoint's next pointer [field:*(this+0x4):0x00000004, source:raw]
    // CALL: Recursively sort the left half (original head) [callee:0x00465D70, source:raw]
    // CALL: Recursively sort the right half (captured head) [callee:0x00465D70, source:raw]
    // LOOP: Merge loop: while both halves remain, compare the two head keys with the priority-table comparator; each head's packed key is inspected via the top two bits (value>>29), a masked sub-field (value>>18 & 0x3F), the low byte versus the 255 sentinel, and equality tests against the 104-entry priority table at dword_7CD2AC+58384 [field:*(this+0x4):0x00000004, global:0x007CD2AC, source:raw]
    // LOOP: Winner relink: advance the winning half's head to its next pointer and append the winning node to the tail of the merged list, walking the priority-table pointer forward when the comparator needs a later entry (bounded by 104 entries) [field:*(this+0x4):0x00000004, source:raw]
    // ASSIGNMENT: When one half is exhausted, append the remaining half's nodes to the merged list tail, or a null terminator when both halves are spent [field:*(this+0x4):0x00000004, source:raw]
    // RETURN: Return the head of the merged list; the sort is used by EntityVisibilityGridManager (00465460) [caller:0x00465460, function:0x00465D70, source:raw]

    // Conservative worker pseudocode:
    //   head = a1; if (!head) return head;
    //   count = 0; for (n = head; n; n = *(n+4)) ++count;
    //   if (count < 2) return head;
    //   mid = head; for (i = 0; i < count/2 - 1; ++i) mid = *(mid+4);
    //   right = *(mid+4); *(mid+4) = 0;
    //   left = sort(head); right = sort(right);
    //   merged_head = null; merged_tail = null;
    //   while (left && right) {
    //     if (compare(left_key, right_key, priority_table_at dword_7CD2AC+58384))
    //       pick = left, left = *(left+4);
    //     else pick = right, right = *(right+4);
    //     append pick to merged list;
    //   }
    //   append remaining half to merged list;
    //   return merged_head;
    // UNRESOLVED: The semantic meaning of the priority-table values at dword_7CD2AC+58384, and how the packed-key fields (top two bits, masked sub-field, low byte, 255 sentinel) map to a visual sort order, is not derivable from this packet
    // UNRESOLVED: The node payload type and the exact layout of the 104-entry priority table are unknown; the table is read but never written by this function
    // UNRESOLVED: The caller's (00465460) grid-cell representation that this ordering feeds is outside this packet
}
