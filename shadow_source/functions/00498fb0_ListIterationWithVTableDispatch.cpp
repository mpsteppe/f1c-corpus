// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498FB0
// Canonical corpus name: ListIterationWithVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListIterationWithVTableDispatch_00498fb0.c

void UnknownObject::ListIterationWithVTableDispatch()
{
    // Iterates two linked lists of polymorphic nodes and dispatches the virtual method at vtable slot 116 (0x74) on every node. The first list starts at head this[19] (this+0x4C). The second list starts at the pointer stored at this[20]+68, i.e. *(this+0x94). Both lists are advanced via StructFieldAccessor until a NULL terminator node. Structurally paired with a sibling function that uses vtable slot 112.
    // LOOP: Iterate the first linked list from head this[19] (this+0x4C), advancing each step via StructFieldAccessor(i) until the node pointer becomes NULL. [field:this:0x0000004C, callee:0x00486320, source:raw]
    // CALL: Invoke the __thiscall virtual method at vtable slot 116 (0x74) on each node of the first list. [field:*(this+0x4C):0x00000074, source:raw]
    // LOOP: Iterate the second linked list from the head read at this[20]+68, which is the pointer at this+0x94, advancing via StructFieldAccessor(j) until the node pointer becomes NULL. [field:this:0x00000050, field:this:0x00000094, callee:0x00486320, source:raw]
    // CALL: Invoke the __thiscall virtual method at vtable slot 116 (0x74) on each node of the second list, reading the vtable pointer from the node itself. [field:*(this+0x94):0x00000000, field:*(*(this+0x94)+0x0):0x00000074, source:raw]

    // Conservative worker pseudocode:
    //   void sub_498FB0(void *self) {
    //     for (void *n = *(void **)((char *)self + 0x4C); n; n = StructFieldAccessor(n))
    //       (*(void (__thiscall **)(void *))(*(void **)n + 116))(n);
    //     for (void *n = *(void **)((char *)self + 0x94); n; n = StructFieldAccessor(n))
    //       (*(void (__thiscall **)(void *))(*(void **)n + 116))(n);
    //   }
    // UNRESOLVED: Identity of the dispatched virtual method at vtable slot 0x74: existing analysis labels it a render/draw method, which is DERIVED and not proven.
    // UNRESOLVED: The node object type and the exact semantics of StructFieldAccessor (0x00486320) are not established; it is treated only as the traversal-link getter.
    // UNRESOLVED: The object layout behind this+0x50 is not reconstructed; the only deterministic fact is that the second list head is read at this[20]+68.
    // UNRESOLVED: Caller UtilityFunction_7890 (0x00497890) is external context for this function and does not constrain the semantics here.
}
