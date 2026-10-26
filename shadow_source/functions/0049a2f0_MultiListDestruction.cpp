// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A2F0
// Canonical corpus name: MultiListDestruction_a2f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiListDestruction_a2f0_0049a2f0.c

void UnknownObject::MultiListDestruction()
{
    // thiscall destructor over an array of 26 singly-linked lists. For each bucket this[0..25] it walks the list head, and per node: reads the next pointer from node index 6 (byte offset 24), runs sub_49A270 on the node as per-node cleanup, then frees the node with FreeWrapper_7bcf. Each bucket pointer is zeroed once its list is drained. Returns the result of the last FreeWrapper_7bcf call. Invoked once from sub_495300 (00495300).
    // LOOP: Outer loop over 26 buckets this[0]..this[25]; each bucket is processed and then zeroed [source:raw]
    // LOOP: Inner loop walks the list from the bucket head; the next node is read from node index 6 (byte offset 24) before the current node is cleaned and freed [source:raw]
    // CALL: sub_49A270 invoked on each node as per-node teardown before the node is freed [callee:0x0049A270, source:raw]
    // CALL: FreeWrapper_7bcf invoked on each node to release its memory; its result becomes the loop value of result [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Bucket head this[i] is set to 0 after its list has been fully drained [source:raw]
    // RETURN: Returns the value of result, i.e. the last FreeWrapper_7bcf result, after all buckets are drained [function:0x0049A2F0, source:raw]
    // CALL: Invoked by sub_495300 (00495300) as a teardown step [caller:0x00495300, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 26; ++i) {
    //       for (j = this[i]; j != 0; ) {
    //           v4 = j;
    //           j = j[6];
    //           sub_49A270(v4);
    //           result = FreeWrapper_7bcf(v4);
    //       }
    //       this[i] = 0;
    //   }
    //   return result;
    // UNRESOLVED: The per-node teardown done by sub_49A270 is not documented in this packet
    // UNRESOLVED: The node layout is only known at index 6 (next pointer); the element size and other node fields are unknown
    // UNRESOLVED: When every bucket is empty the inner loop never assigns result, so the returned value is whatever Hex-Rays left in eax; the semantic intent of the return in that case is unknown
}
