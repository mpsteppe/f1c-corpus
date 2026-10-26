// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489480
// Canonical corpus name: PopListWithDestructor
// Owner: UIMenuItemList [DERIVED]
// Raw source: functions/PopListWithDestructor_00489480.c

void UIMenuItemList::PopListWithDestructor()
{
    // Pops entries from the front of a linked list whose head is at this+0x90 and whose count is at this+0x94. It removes count - index items (index read from this+0x170), and for each removed node advances the head to the node's next pointer (node + 140, the head-view at this+0x11C) and invokes the node's destructor through its vtable at node+0x0. Skips entirely when index < 0 or count <= index. Called by UIMenuItemCreator.
    // GUARD: Guard on the index at this+0x170: if index < 0, return without doing anything. [field:this:0x00000170]
    // GUARD: Guard comparing the count at this+0x94 to the index at this+0x170: nothing is popped when count <= index. [field:this:0x00000094, field:this:0x00000170]
    // CALCULATION: Compute the number of items to remove as count - index (this+0x94 minus this+0x170). [field:this:0x00000094, field:this:0x00000170]
    // LOOP: do-while loop that runs once per removed item until the removed count reaches zero. [source:raw]
    // GUARD: Per-iteration guard: only process when the current head pointer at this+0x90 is non-null. [field:this:0x00000090]
    // ASSIGNMENT: Advance the head: this+0x90 = next pointer of the current node, read from node + 140 (0x8C), which from the head-view is the field at this+0x11C. [field:this:0x00000090, field:this:0x0000011C]
    // CALL: Call the removed node's destructor through its vtable (slot 0 at node+0x0) with argument 1. [field:*(this+0x90):0x00000000]
    // CALCULATION: Decrement the item count: this+0x94 -= (count - index), i.e. subtract the number of removed items. [field:this:0x00000094]

    // Conservative worker pseudocode:
    //   void PopListWithDestructor(DWORD* this) {
    //     int index = *(int*)((char*)this + 0x170);
    //     if (index >= 0) {
    //       int count = *(int*)((char*)this + 0x94);
    //       if (count > index) {
    //         int n = count - index;
    //         do {
    //           DWORD* node = *(DWORD**)((char*)this + 0x90);
    //           if (node) {
    //             *(DWORD**)((char*)this + 0x90) = *(DWORD**)((char*)node + 140);
    //             (*(void (__thiscall **)(int, int))node)((int)node, 1);
    //           }
    //           --n;
    //         } while (n);
    //         *(int*)((char*)this + 0x94) -= count - index;
    //       }
    //     }
    //   }
    // UNRESOLVED: Node type and vtable layout are unknown; only vtable slot 0 (destructor) is exercised.
    // UNRESOLVED: What the index at this+0x170 represents (a lower bound of entries to keep) is inferred from the caller UIMenuItemCreator, not proven.
    // UNRESOLVED: Meaning of the destructor argument 1 is unknown.
}
