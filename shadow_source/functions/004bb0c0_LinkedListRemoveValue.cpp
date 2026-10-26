// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB0C0
// Canonical corpus name: sub_4BB0C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BB0C0_004bb0c0.c

void UnknownObject::LinkedListRemoveValue()
{
    // Intrusive linked-list node removal keyed on the head node's stored value. Reads the value from the current head node, searches the list (following next pointers) for a node holding that same value, unlinks it, and frees it along with its owned payload when the node flag byte is set. Returns the removed value. Structural twin of the LinkedListRemoveByValue cluster representative.
    // GUARD: Empty-list guard: if the list head pointer *this is null, return 0 without modifying the list. [guard:1, field:this:0x00000000]
    // ASSIGNMENT: Save a copy of the head pointer into this[2] (this+8) before unlinking; this slot is later used to track the tail node. [field:this:0x00000008, field:this:0x00000000]
    // GUARD: Read the head node's value into v4 and test it for zero; regardless of the result, clear the node's flag byte at obj+8. If the value is zero, return 0. [guard:0, field:obj:0x00000000, field:obj:0x00000008]
    // LOOP: Linear search from the list head: walk nodes via the next pointer (obj+4) until a node whose value (obj+0) equals the key v4 is found; if the walk reaches a null next pointer first, return 0. [field:obj:0x00000000, field:obj:0x00000004]
    // CALCULATION: On match: if the matched node equals the saved tail (this+8), advance the saved tail to the matched node's next pointer; capture the next pointer (obj+4) for the unlink. [field:this:0x00000008, field:obj:0x00000004]
    // ASSIGNMENT: Unlink the matched node: write the captured next pointer into the previous node's next slot (obj+4), or into the list head (*this) when there was no previous node. [field:obj:0x00000004, field:this:0x00000000]
    // STATE_TRANSITION: If the this[1] (this+4) pointer equals the matched node, re-point it at the previous node so the tail reference stays valid after removal. [field:this:0x00000004]
    // CALCULATION: Decrement the node count stored at this[3] (this+0xC). [field:this:0x0000000C]
    // GUARD: If the matched node's flag byte (obj+8) is non-zero and its value pointer (obj+0) is non-null, the node owns its payload and the payload must be freed before the node itself. [field:obj:0x00000008, field:obj:0x00000000, callee:0x00587BCF]
    // CALL: Call EmptyStub_0170 before releasing the owned payload object. [callee:0x004B0170]
    // CALL: Free the owned payload object with FreeWrapper_7bcf. [callee:0x00587BCF]
    // CALL: Free the unlinked node itself with FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return the removed value v4 to the caller. [field:obj:0x00000000]

    // Conservative worker pseudocode:
    //   DWORD LinkedListRemoveValue(DWORD *list) {
    //     Node *head = list[0];
    //     if (!head) return 0;
    //     list[2] = list[0];
    //     DWORD key = head->value;
    //     head->flags_byte = 0;
    //     if (!key) return 0;
    //     Node *prev = 0;
    //     Node *node = list[0];
    //     while (node && node->value != key) { prev = node; node = node->next; }
    //     if (!node) return 0;
    //     if (node == (Node*)list[2]) list[2] = node->next;
    //     Node *next = node->next;
    //     if (prev) prev->next = next; else list[0] = next;
    //     if ((Node*)list[1] == node) list[1] = prev;
    //     --list[3];
    //     if (node->flags_byte && node->value) { EmptyStub_0170(); FreeWrapper_7bcf(node->value); }
    //     FreeWrapper_7bcf(node);
    //     return key;
    //   }
    // UNRESOLVED: obj+0xC is read (per packet) but no use of it is visible in the decompiled pseudocode; its role is unresolved.
    // UNRESOLVED: this[2] (this+8) is used as a tail bookmark; its exact semantic relationship to this[1] (this+4) is inferred from the structural twin.
    // UNRESOLVED: The removal key is the head node's own value, implying callers stage the key in a temporary head node; the caller contract is not visible here.
    // UNRESOLVED: EmptyStub_0170 is called with no observable effect; likely a no-op or bookkeeping stub.
}
