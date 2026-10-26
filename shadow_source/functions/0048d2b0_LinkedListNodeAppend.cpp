// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D2B0
// Canonical corpus name: LinkedListNodeAppend
// Owner: LinkedList [DERIVED]
// Raw source: functions/LinkedListNodeAppend_0048d2b0.c

void LinkedList::LinkedListNodeAppend()
{
    // Appends a value to a doubly-linked list container. Allocates an 8-byte data node holding the value and a 16-byte list node, links it at the tail, bumps the item count, recomputes size statistics, and signals a change through a vtable method. Returns 1 on success, 0 when the data node allocation fails.
    // CALL: allocate 8-byte data node via heap allocator [callee:0x00587C03]
    // CALL: initialize data node vtable [callee:0x0048C9A0]
    // CALL: store appended value into data node at offset +4 [callee:0x0048C9E0]
    // GUARD: if data node allocation returned zero, return 0 [function:0x0048D2B0, source:raw]
    // CALL: allocate 16-byte list node via heap allocator [callee:0x00587C03]
    // ASSIGNMENT: initialize list node: value pointer at +0, previous 0 at +4, next 0 at +8, in-list flag 1 at +12 [source:raw]
    // GUARD: branch on whether head pointer at +0x31C is already set [field:this:0x0000031C]
    // ASSIGNMENT: existing list: link old tail forward pointer to new node and new node previous to old tail [field:this:0x00000320]
    // ASSIGNMENT: empty list: set head pointer at +0x31C and first-element pointer at +0x324 to the new node [field:this:0x0000031C, field:this:0x00000324]
    // ASSIGNMENT: update tail pointer at +0x320 to the new node [field:this:0x00000320]
    // ASSIGNMENT: increment item count at +0x328 [field:this:0x00000328]
    // CALL: recompute list size statistics after insertion [callee:0x0048CC20]
    // CALL: notify change via vtable method at index 44 with argument 1 [field:this:0x00000000, field:obj:0x0000002C]
    // RETURN: return 1 on success [function:0x0048D2B0]

    // Conservative worker pseudocode:
    //   node = alloc8();
    //   if (!node) return 0;
    //   initVTable(node); setValue(node+4, a2);
    //   lnode = alloc16();
    //   lnode+0 = node; lnode+4 = 0; lnode+8 = 0; lnode+12 = 1;
    //   if (head) { tail->next = lnode; lnode->prev = tail; }
    //   else { head = lnode; first = lnode; }
    //   tail = lnode; count++;
    //   recalcSizeStats();
    //   vtableMethod44(1);
    //   return 1;
    // UNRESOLVED: semantic of the vtable method at index 44 (change notification) is unknown
    // UNRESOLVED: role of the first-element pointer at +0x324 beyond first-insert marker is unknown
}
