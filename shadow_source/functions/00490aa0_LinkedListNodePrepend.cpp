// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490AA0
// Canonical corpus name: LinkedListNodePrepend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodePrepend_00490aa0.c

void UnknownObject::LinkedListNodePrepend()
{
    // Adds a container `this` as a new node at the head of a global linked list whose manager object comes from GlobalDataRead(). ShortArrayZeroInit(this) is applied to the payload first. A 12-byte node is allocated holding the payload pointer (+0), a next pointer (+4) and a one-byte flag (+8). When the list already has a head (v2[4] non-null) the node is prepended and the count at v2[7] is incremented; otherwise the new node becomes both head and tail (v2[5], v2[6], v2[4]) and the count at v2[7] is set to 1. Returns the new node pointer (or 0 when allocation failed or the payload was null).
    // CALL: Call GlobalDataRead() to obtain the global list-manager object v2. [callee:0x00490930, source:raw]
    // CALL: Call ShortArrayZeroInit(this) to zero-initialize the payload being inserted. [callee:0x00491330, source:raw]
    // GUARD: Guard: when the payload `this` is null, skip allocation and return the result of ShortArrayZeroInit. [source:raw]
    // CALL: OperatorNewNhMallocWrapper(12): allocate a 12-byte list node. [callee:0x00587C03, source:raw]
    // GUARD: Guard on allocation success; result becomes 0 when the allocation failed. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new node: payload pointer (+0) = this, next (+4) = 0, flag byte (+8) = 0. [source:raw]
    // GUARD: Guard: branch on whether the list manager already has a head node at v2[4]. [source:raw]
    // ASSIGNMENT: Non-empty case: link the node to the old head (node+4 = v2[4]), set v2[4] = node as the new head, and increment the count at v2[7]. [source:raw]
    // ASSIGNMENT: Empty case: set v2[5] and v2[6] (tail / head aliases) and v2[4] all to the node, and set the count at v2[7] to v2[7] + 1 (1). [source:raw]
    // RETURN: Return the new node pointer (or 0 when the payload was null or allocation failed). [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodePrepend(void *this) {
    //     ListMgr *mgr = GlobalDataRead();
    //     int result = ShortArrayZeroInit(this);
    //     if (this) {
    //       Node *node = OperatorNewNhMallocWrapper(12);
    //       if (node) {
    //         node->data = this;
    //         node->next = 0;
    //         node->flag = 0;
    //       } else {
    //         node = 0;
    //       }
    //       if (mgr->head) {
    //         node->next = mgr->head;
    //         mgr->head = node;
    //         ++mgr->count;
    //       } else {
    //         mgr->tail = node;
    //         mgr->head2 = node;
    //         mgr->head = node;
    //         mgr->count = mgr->count + 1;
    //       }
    //       result = node;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact layout of the list-manager object (v2) is inferred: v2[4]=head, v2[5]/v2[6]=tail/head aliases, v2[7]=count; none of these offsets have packet field evidence.
    // UNRESOLVED: The purpose of the one-byte flag at node+8 and the meaning of the count at v2[7] beyond a size counter are unconfirmed.
    // UNRESOLVED: The callers (broadphase/collision builders and iterator helpers) suggest a generic embedded linked list, but the concrete owner class is unknown.
}
