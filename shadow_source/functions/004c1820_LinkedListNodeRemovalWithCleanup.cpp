// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1820
// Canonical corpus name: LinkedListNodeRemovalWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemovalWithCleanup_004c1820.c

void UnknownObject::LinkedListNodeRemovalWithCleanup()
{
    // Removes a node from a singly-linked list whose head/tail/count metadata lives on the this object. The target data pointer comes from LinkedListDereference(this); the list is walked from *this matching each node's data pointer at +0, tracking the previous node. On a match the node is unlinked (relinking predecessor or head, updating this[1] and this[2] when they pointed at the removed node) and this[3] is decremented. If the node's +8 ownership byte is set and its payload is non-null, the payload is passed to PitStopMemoryCleanup then freed via FreeWrapper_7bcf; the node itself is freed via FreeWrapper_7bcf. Returns 1 on successful removal, 0 when the target is null or not found.
    // CALL: Call LinkedListDereference(this) to obtain the target data pointer v2; a null result returns 0. [source:raw, callee:0x004C2850]
    // GUARD: Guard: if v2 is null, return 0 immediately. [source:raw]
    // ASSIGNMENT: Initialize walkers: v3 = *this (head node), v5 = 0 (previous node), v4 = 0 (result). [source:raw, field:this:0x00000000]
    // GUARD: Guard: if *this (head) is null, fall through and return v4 (0). [source:raw, field:this:0x00000000]
    // LOOP: Walk the list: while current node data at +0 (obj+0x4 base) does not equal v2, save current as previous (v5) and advance to next pointer at +4 (obj+0x4 base). If next becomes null the target was not found and the function returns 0. [source:raw, field:*(obj+0x4):0x00000000, field:*(obj+0x4):0x00000004]
    // GUARD: Guard: if traversal hit a null next pointer, return 0 (target not found). [source:raw, field:*(obj+0x4):0x00000004]
    // ASSIGNMENT: If the removed node v3 equals this[2], set this[2] to v3's next pointer (+4). [source:raw, field:this:0x00000008, field:*(obj+0x4):0x00000004]
    // ASSIGNMENT: Relink around the removed node: if a previous node v5 exists, set its +4 to v3's next pointer; otherwise set head *this to v3's next pointer. [source:raw, field:obj:0x00000004, field:this:0x00000000]
    // ASSIGNMENT: If this[1] equals the removed node v3, set this[1] to the previous node v5. [source:raw, field:this:0x00000004]
    // CALCULATION: Decrement the node count this[3] (offset 0xC). [source:raw, field:this:0x0000000C]
    // GUARD: Guard: if the ownership flag byte at node +8 (obj+0x4 base) is set and the payload at +0 is non-null, free the payload. [source:raw, field:*(obj+0x4):0x00000008, field:*(obj+0x4):0x00000000]
    // CALL: Call PitStopMemoryCleanup on the node payload, then FreeWrapper_7bcf on the same payload. [source:raw, callee:0x004C0B10, callee:0x00587BCF]
    // CALL: Free the removed node itself via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // RETURN: Return 1 on successful removal, or 0 for the null-target / not-found / empty-list paths. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4C1820(int *this) {
    //     int target = LinkedListDereference(this);
    //     if (!target) return 0;
    //     int cur = *this;
    //     int prev = 0;
    //     if (!cur) return 0;
    //     while (*(int*)cur != target) { prev = cur; cur = *(int*)(cur + 4); if (!cur) return 0; }
    //     if (cur == this[2]) this[2] = *(int*)(cur + 4);
    //     if (prev) *(int*)(prev + 4) = *(int*)(cur + 4); else *this = *(int*)(cur + 4);
    //     if (this[1] == cur) this[1] = prev;
    //     --this[3];
    //     if (*(char*)(cur + 8)) { void *payload = *(void**)cur; if (payload) { PitStopMemoryCleanup(payload); FreeWrapper_7bcf(payload); } }
    //     FreeWrapper_7bcf((void*)cur);
    //     return 1;
    //   }
    // UNRESOLVED: Semantic roles of this[1] and this[2] (head/tail/special pointers) are not independently confirmed; only this[0]=head is visible in source.
    // UNRESOLVED: Meaning of the ownership flag byte at node +8 and the payload contract of PitStopMemoryCleanup are unknown.
    // UNRESOLVED: The list lives on the this object, but the owning class is unidentified.
}
