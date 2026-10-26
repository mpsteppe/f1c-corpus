// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005478B0
// Canonical corpus name: DoublyLinkedListNodeRemovalWithArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemovalWithArrayCleanup_005478b0.c

void UnknownObject::DoublyLinkedListNodeRemovalWithArrayCleanup()
{
    // Removes node a2 from a doubly linked list: unlinks prev/next pointers (links at a2+88 and a2+92), updates the list head this[10] (offset 0x28) when a2 is the head, then frees a2's trailing array allocation. The element count is read from *(a2 - 4); for a non-negative count, each element of the 96-byte-stride array is processed in reverse by EmptyStub_7470 before the whole block is freed by FreeWrapper_7bcf. Decrements the node counter this[3] (offset 0xC) and returns the new count.
    // ASSIGNMENT: Read the predecessor: v3 = *(a2 + 88). [source:raw]
    // GUARD: If a predecessor exists, splice forward: *(v3 + 92) = *(a2 + 92). [source:raw]
    // ASSIGNMENT: Read the successor: v4 = *(a2 + 92). [source:raw]
    // GUARD: If a successor exists, splice backward: *(v4 + 88) = *(a2 + 88). [source:raw]
    // GUARD: If a2 is the list head (this[10] == a2), promote the successor to head: this[10] = *(a2 + 92). [source:raw, field:this:0x00000028]
    // CALCULATION: Load the element count prefix v5 = *(a2 - 4) and seed the reverse walk pointer v6 = a2 + 96 * v5; counter v7 = v5 - 1. [source:raw]
    // GUARD: Guard on (v5 - 1) >= 0; a zero or negative count skips the element loop. [source:raw]
    // LOOP: do-while over v5 elements: step the walk pointer back 96 bytes and call EmptyStub_7470 on each element in reverse order. [source:raw, callee:0x00557470]
    // CALL: Free the allocation block (including the count prefix) at a2 - 4 via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // CALCULATION: Decrement the node counter: result = this[3] - 1; this[3] = result. [source:raw, field:this:0x0000000C]
    // RETURN: Return the decremented node count. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5478B0(DWORD *this, DWORD *node) {
    //     DWORD *prev = *(DWORD **)(node + 88);
    //     if (prev) *(DWORD **)(prev + 92) = *(DWORD **)(node + 92);
    //     DWORD *next = *(DWORD **)(node + 92);
    //     if (next) *(DWORD **)(next + 88) = *(DWORD **)(node + 88);
    //     if (this[10] == node) this[10] = next;
    //     int count = *(int *)(node - 4);
    //     char *p = (char *)node + 96 * count;
    //     if (count - 1 >= 0) {
    //       int n = count;
    //       do { p -= 96; EmptyStub_7470(p); --n; } while (n);
    //     }
    //     FreeWrapper_7bcf((LPVOID)(node - 4));
    //     int result = this[3] - 1;
    //     this[3] = result;
    //     return result;
    //   }
    // UNRESOLVED: Node layout semantics (links at +88/+92, array stride 96, count prefix at node-4) are known only as offsets from the raw source; no field evidence refs exist for them.
    // UNRESOLVED: Purpose of EmptyStub_7470 as an element cleanup callback is unknown.
    // UNRESOLVED: Owner object type holding the list head at this+0x28 and counter at this+0xC is unidentified.
}
