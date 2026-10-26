// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051623E
// Canonical corpus name: sub_51623E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51623E_0051623e.c

void UnknownObject::AllocLinkedListNodeInsertHead2()
{
    // Sister routine to LinkedListNodeAllocAndInsert (005161DD): allocates a 0x78 (120) byte node via MemoryAllocator, populates it with a4, a5, a6 and the type byte a3, and prepends it to a separate singly-linked list anchored at this+0x48. When the category a2 is not 1, it first writes constant 12 and the category to the sub-object at obj+0x14/+0x18 and dispatches through the sub-object vtable before allocating. Returns the new node pointer.
    // CALCULATION: Read the allocator state base pointer this+0x4 into v6; its field at +68 holds the list head used at the end. [field:this:0x00000004, source:raw]
    // GUARD: Guard on a2 != 1: the constant-12 write, category write and virtual dispatch only run for non-default categories. [source:raw]
    // ASSIGNMENT: Write constant 12 to the sub-object field obj+0x14 (reached as *a1 + 20). [field:obj:0x00000014, source:raw]
    // ASSIGNMENT: Write the category a2 to the sub-object field obj+0x18 (reached as *a1 + 24). [field:obj:0x00000018, source:raw]
    // CALL: Read the this vtable pointer at this+0x0 to reach the sub-object, then virtual-dispatch through the sub-object vtable at obj+0x0, calling (*(*a1))(a1) with the object itself as the argument. [field:this:0x00000000, field:obj:0x00000000, source:raw]
    // CALL: Call MemoryAllocator(a1, a2, 0x78) to obtain a 120-byte node block. [callee:0x00515F23, source:raw]
    // ASSIGNMENT: Initialize node+0 to 0 (next-pointer start). [source:raw]
    // ASSIGNMENT: Store a5 at node+4, a4 at node+8, and a6 at node+12. [source:raw]
    // ASSIGNMENT: Zero the byte at node+34 and store the type byte a3 at node+32. [source:raw]
    // ASSIGNMENT: Link new node: node+36 receives the current head from (v6 + 68), then (v6 + 68) is set to the new node. Packet facts anchor this separate list at this+0x48. [field:this:0x00000048, source:raw]
    // RETURN: Return the new node pointer as the result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_51623E(_DWORD *this, unsigned int a2, char a3, int a4, int a5, int a6) {
    //     void *state = this[1];
    //     if (a2 != 1) {
    //       *(*this + 20) = 12;
    //       *(*this + 24) = a2;
    //       (*(void (__cdecl **)(_DWORD *))*this)(this);
    //     }
    //     node = MemoryAllocator(this, a2, 0x78);
    //     *(node + 0) = 0;
    //     *(node + 4) = a5;
    //     *(node + 8) = a4;
    //     *(node + 12) = a6;
    //     *(node + 34) = 0;
    //     *(node + 32) = a3;
    //     *(node + 36) = *(state + 68);
    //     *(state + 68) = node;
    //     return node;
    //   }
    // UNRESOLVED: The 120-byte node's field layout (offsets 0, 4, 8, 12, 32, 34, 36) has no named semantics in the packet.
    // UNRESOLVED: Identity of the virtual callback dispatched through the sub-object vtable (obj+0x0) is unknown.
    // UNRESOLVED: The list head is written through (v6 + 68) where v6 = this+0x4; packet facts name this+0x48 as the anchor, and the equivalence of the two views is not proven here.
    // UNRESOLVED: This+0x48 list is asserted to be separate from the this+0x44 list in 005161DD; no cross-reference in this packet proves they are distinct lists.
}
