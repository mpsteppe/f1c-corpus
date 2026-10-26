// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565CA0
// Canonical corpus name: sub_565CA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565CA0_00565ca0.c

void UnknownObject::ListAppendCopy()
{
    // Appends a copy of an item to a linked list owned by `this`. Allocates a 332-byte payload, initializes its back-pointer to the list owner plus a zero/-1 dword pair, copies 0x140 bytes of item data from a2 into the payload, optionally reallocates a3's string buffer (result discarded), then wraps the payload in a 12-byte node (payload pointer, next pointer, valid flag = 1) and links it at the tail of the list, updating head/tail pointers and the count at this+0xC. Always returns 0. Called by sub_565F80.
    // GUARD: If the item pointer a2 is null, skip the whole insertion and return 0. [source:raw]
    // CALL: Allocate a 332-byte payload object via OperatorNewNhMallocWrapper; on failure v3 remains null. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If allocation succeeded, initialize the payload: store the owning list pointer `this` at byte offset 0, zero the dword at byte offset 324 (payload[81]), and set -1 at byte offset 328 (payload[82]). [source:raw]
    // ASSIGNMENT: Copy 0x140 bytes from a2 into the payload at byte offset 4 (payload + 1) via qmemcpy. [source:raw]
    // CALL: If a3 is nonzero, call StringCopyWithBufferRealloc(a3) for its side effect (string buffer reallocation); the return value is discarded. [callee:0x00566650, source:raw]
    // CALL: Allocate a 12-byte list node via OperatorNewNhMallocWrapper; on failure v6 is null. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the node allocated, initialize it: payload pointer at byte offset 0, next pointer at byte offset 4 set to 0, and valid-flag byte at byte offset 8 set to 1. [source:raw]
    // GUARD: If the list head at this+0x0 is null (empty list), set the head (this+0x0), the this+0x8 pointer, and the tail (this+0x4) all to the new node, then increment the count at this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Otherwise append to the tail: write the new node as the next pointer of the old tail (this+0x4 dereferenced at byte offset 4), set the tail this+0x4 to the new node, and increment the count at this+0xC. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // RETURN: Return 0 on every path. [source:raw]

    // Conservative worker pseudocode:
    //   // Returns 0 always.
    //   if (a2 == 0) return 0;
    //   payload = OperatorNewNhMallocWrapper(332);
    //   if (payload) {
    //     payload[0] = this;   // back-pointer to owning list
    //     payload[81] = 0;
    //     payload[82] = -1;
    //   }
    //   memcpy(payload + 1, a2, 0x140);  // copy item data
    //   if (a3) StringCopyWithBufferRealloc(a3);
    //   node = OperatorNewNhMallocWrapper(12);
    //   if (node) {
    //     node[0] = payload;   // payload link
    //     node[1] = 0;         // next pointer
    //     node[2] = 1;         // valid flag
    //   }
    //   if (this[0] == 0) {
    //     this[0] = node; this[2] = node; this[1] = node;
    //   } else {
    //     this[1][1] = node;  // link old tail
    //     this[1] = node;
    //   }
    //   this[3]++;
    //   return 0;
    // UNRESOLVED: The 332-byte payload layout is untyped: the back-pointer at offset 0 and the zero/-1 dword pair at offsets 324/328 have no named meaning in the packet.
    // UNRESOLVED: The this+0x8 pointer's role (mirrored on empty-list insert) is DERIVED; it may be a last-accessed or cursor pointer, not a head/tail member.
    // UNRESOLVED: StringCopyWithBufferRealloc's result is discarded, so the call is assumed to act on a3's buffer by side effect; that assumption is DERIVED.
    // UNRESOLVED: qmemcpy at payload + 1 executes even when the 332-byte allocation failed (v3 null), a potential null dereference in the raw source.
    // UNRESOLVED: Owner object type is UNKNOWN; only the single caller sub_565F80 (0x00565F80) is known.
}
