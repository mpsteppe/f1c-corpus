// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585320
// Canonical corpus name: LinkedListWalkWithInputDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListWalkWithInputDispatch_00585320.c

void UnknownObject::LinkedListWalkWithInputDispatch()
{
    // Walks a singly linked list whose head is read from this+0x11C, keeping an iterator pointer in this+0x124. For each node whose StructFieldGetter_7720 value is not -1, calls sub_5878A0 with argument a2 and clears the node's field via FieldSetterAt0x410(-1). Traversal stops when the iterator becomes null. Called by sub_57A730.
    // ASSIGNMENT: Read the head of the linked list from this[71] (offset 0x11C) and store it into the iterator slot this[73] (offset 0x124) [field:this:0x0000011C, field:this:0x00000124, source:raw]
    // GUARD: If the head/iterator pointer is null, skip the walk entirely and return it [source:raw]
    // LOOP: Loop over nodes: start with i = *result (the node's head/next field), and continue while *result is non-zero [source:raw]
    // GUARD: Per node, check StructFieldGetter_7720(i); proceed with the dispatch only when the getter result is not -1 [callee:0x00587720, source:raw]
    // CALL: Call the dispatch callback sub_5878A0 with argument a2 for a node whose getter value is not -1 [callee:0x005878A0, source:raw]
    // CALL: Call FieldSetterAt0x410 with -1 to clear/mark the matched node's field [callee:0x00587710, source:raw]
    // ASSIGNMENT: Advance the walk: read the iterator from this[73] (offset 0x124), take its next pointer (node offset 4), store it back into this[73], and break out when it becomes null [field:this:0x00000124, source:raw]
    // RETURN: Return the final iterator pointer (null when the walk completed normally) [function:0x00585320, source:raw]
    // CALL: Invoked by sub_57A730 (0057A730) to walk the linked list and dispatch on matching nodes [caller:0x0057A730, source:raw]

    // Conservative worker pseudocode:
    //   result = this[0x11C/4];
    //   this[0x124/4] = result;
    //   if (result) {
    //     for (i = *result; *result; i = *result) {
    //       if (StructFieldGetter_7720(i) != -1) {
    //         sub_5878A0(a2);
    //         FieldSetterAt0x410(-1);
    //       }
    //       result = this[0x124/4];
    //       if (!result) break;
    //       result = result[1];
    //       this[0x124/4] = result;
    //       if (!result) break;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Fields this+0x128 and this+0x12C are flagged by packet facts as read-only but appear nowhere in the raw decompiled source; their role cannot be verified here
    // UNRESOLVED: The node layout is inferred: *result and result[1] are treated as head/next link fields, but no node type or stride is evidenced
}
