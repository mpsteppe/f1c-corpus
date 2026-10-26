// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049FEB0
// Canonical corpus name: MergeSort
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MergeSort_0049feb0.c

void UnknownObject::MergeSort()
{
    // Recursive merge sort over a singly linked list whose nodes carry a next pointer at node+4 and a payload pointer at node+0; the sort key is the float at payload+4. Returns the new list head. A null input, or a list with fewer than 2 nodes, is returned unchanged. The list is split at its midpoint, both halves are sorted recursively, then merged back in ascending key order.
    // GUARD: Return the input pointer unchanged when it is null. [function:0x0049FEB0, source:raw]
    // LOOP: Count the list nodes by walking the next pointer at node+4 (this+0x4). [field:this:0x00000004, function:0x0049FEB0]
    // GUARD: Return the list unchanged when the count is below 2 nodes. [function:0x0049FEB0, source:raw]
    // LOOP: Advance to the midpoint node by following next pointers for half the list length. [field:this:0x00000004]
    // ASSIGNMENT: Split the list: save the second-half head read from the midpoint next pointer and clear that next pointer to terminate the first half. [field:this:0x00000004]
    // CALL: Recursively sort the first half of the list. [callee:0x0049FEB0]
    // CALL: Recursively sort the second half of the list. [callee:0x0049FEB0]
    // GUARD: During merge, return the non-null half when the other half is null. [function:0x0049FEB0, source:raw]
    // LOOP: Merge the two sorted halves in ascending order, repeatedly selecting the head with the smaller float key; the payload pointer is read from node+0 and the key is read at payload+4. [field:this:0x00000000, field:obj:0x00000004]
    // ASSIGNMENT: Link each selected node behind the running merge tail through the next pointer at node+4. [field:this:0x00000004]
    // RETURN: Return the head of the merged (or otherwise resulting) list. [function:0x0049FEB0, source:raw, field:this:0x00000004]

    // Conservative worker pseudocode:
    //   if (!a1) return a1;
    //   count = 0;
    //   for (p = a1; p; p = p[1]) count++;
    //   if (count < 2) return a1;
    //   mid = a1;
    //   for (i = count / 2 - 1; i > 0; i--) mid = mid[1];
    //   right = mid[1];
    //   mid[1] = 0;
    //   left = MergeSort(a1);
    //   right = MergeSort(right);
    //   if (!left) return right;
    //   if (!right) return left;
    //   head = tail = null;
    //   while (left && right):
    //       if (*(float*)(*left + 4) >= *(float*)(*right + 4)): n = right; right = right[1];
    //       else: n = left; left = left[1];
    //       if (tail) tail[1] = n; else head = n;
    //       tail = n;
    //   if (left) tail[1] = left;
    //   else if (right) tail[1] = right;
    //   else tail[1] = 0;
    //   return head;
    // UNRESOLVED: Packet field refs field:this:0x00000008 and field:this:0x0000000C, plus the dereferenced-base field:*(this+0x8):0x00000004, are not read by the raw source body, which only touches node+0 (payload pointer) and node+4 (next pointer). Their role, and the init_literal 0 on this+0x8, come from other corpus evidence and are unresolved here.
    // UNRESOLVED: The caller sub_49F870 passes the list head; caller-side context that would pin the meaning of the float key is not present in this packet.
}
