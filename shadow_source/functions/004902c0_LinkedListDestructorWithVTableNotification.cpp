// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004902C0
// Canonical corpus name: LinkedListDestructorWithVTableNotification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructorWithVTableNotification_004902c0.c

void UnknownObject::LinkedListDestructorWithVTableNotification()
{
    // Destructor for a linked list of nodes with optional vtable notification. Installs the widget-list vtable at this+0x0, walks the list starting from head this+0xE0 by following the next pointer at node+0x4, and for each node whose flag byte at node+0xC is non-zero and whose first dword is non-zero dispatches a notification through the node's sub-object vtable entry 0 with argument 1. Every node is then freed via FreeWrapper_7bcf. After the walk, this+0xE0..0xEC are zeroed and the base-class destructor is invoked at the tail.
    // ASSIGNMENT: Install the widget-list vtable off_5AC760 at this+0x0 before any node teardown [field:this:0x00000000, global:0x005AC760, source:raw]
    // LOOP: Iterate the linked list from the head pointer stored at this+0xE0, following the next-node pointer at node+0x4 until a null next pointer terminates the walk [field:*(this+0xE0):0x00000000, field:*(*(this+0xE0)+0x4):0x00000004, source:raw]
    // GUARD: Per-node notification only fires when the node flag byte at node+0xC equals 0 and the node's first dword is non-zero [guard:0, field:*(this+0xE0):0x0000000C, source:raw]
    // CALL: Dispatch the vtable notification on the node's sub-object: call through vtable entry 0 (the sub-object vtable pointer stored at node+0x0) passing the object pointer and argument 1 [field:*(*(*(this+0xE0)+0x0)+0x0):0x00000000, field:*(*(this+0xE0)+0x0):0x00000000, source:raw]
    // CALL: Free each node with FreeWrapper_7bcf regardless of the notification guard result [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list-state dwords this+0xE0, this+0xE4, this+0xE8 and this+0xEC after the walk completes [field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, source:raw]
    // RETURN: Delegate to the base-class destructor at the tail; the function is called by ConditionalFree (004902A0) [function:0x004902C0, caller:0x004902A0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x0/4] = &off_5AC760;
    //   node = this[0xE0/4];
    //   while (node) {
    //     next = *(node + 0x4);
    //     if (*(byte*)(node + 0xC) == 0 && *(node + 0x0)) {
    //       (**(void (__thiscall***)(void*,int))*(node + 0x0))(*(node + 0x0), 1);
    //     }
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this[0xE0/4] = this[0xE4/4] = this[0xE8/4] = this[0xEC/4] = 0;
    //   return base_destructor(this);
    // UNRESOLVED: The base-class destructor target is not exposed as a callee evidence entry, so its address is not recorded here
    // UNRESOLVED: The semantic role of the node flag byte at node+0xC (notify suppression flag) is inferred only from the guard and is not independently documented
}
