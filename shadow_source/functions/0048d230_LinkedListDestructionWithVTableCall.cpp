// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D230
// Canonical corpus name: LinkedListDestructionWithVTableCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructionWithVTableCall_0048d230.c

void UnknownObject::LinkedListDestructionWithVTableCall()
{
    // Destroys a singly linked list owned by the object: walks the list from the head pointer at this+0x31C, invoking an indirect vtable destructor on each node whose active-flag byte at node+0xC is non-zero and whose first DWORD is non-zero, then frees every visited node through FreeWrapper_7bcf. Afterwards zeroes the list state block this+0x31C through this+0x340 except the direction byte at this+0x33C, which is set to 1.
    // ASSIGNMENT: Seed the loop cursor i from the head pointer at this+0x31C; the first node's first DWORD is read during iteration. [field:this:0x0000031C, field:*(this+0x31C):0x00000000, source:raw]
    // LOOP: Walk the singly linked list while the current node pointer is non-zero; each iteration advances to the next node stored at node+0x4 and frees the current node as the loop increment. [field:*(*(this+0x31C)+0x4):0x00000004, field:*(this+0x31C):0x00000000, field:this:0x0000031C, source:raw]
    // GUARD: Per-node guard: the active flag byte at node+0xC is tested against zero; the vtable destructor runs only when the flag byte is non-zero and the node's first DWORD is also non-zero. [field:*(this+0x31C):0x0000000C, guard:0, source:raw]
    // CALL: Indirect __thiscall vtable destructor: call the function pointer held at the node's vtable slot, passing the node as this and 1 as the argument, for nodes whose active flag byte is set and whose first DWORD is non-zero. [field:*(*(*(this+0x31C)+0x0)+0x0):0x00000000, field:*(*(this+0x31C)+0x0):0x00000000, field:*(this+0x31C):0x0000000C, source:raw]
    // CALL: FreeWrapper_7bcf is called on each visited node (loop increment); its return value becomes result. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list state block: head at this+0x31C, and fields at this+0x320, this+0x324, this+0x328, this+0x32C, this+0x330, this+0x334, this+0x338, and this+0x340 are all cleared after the walk. [field:this:0x0000031C, field:this:0x00000320, field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, field:this:0x00000334, field:this:0x00000338, field:this:0x00000340]
    // ASSIGNMENT: Set the direction byte at this+0x33C to 1; this is the only field of the state block not reset to zero. [field:this:0x0000033C]
    // RETURN: Return the value produced by the final FreeWrapper_7bcf call (or a stale register value when the list is empty); callers PlayerProfileScanner, sub_46A2A0 and ObjectConstructorWithZeroedFields discard it as a meaningful status. [function:0x0048D230, caller:0x00468EE0, caller:0x0046A2A0, caller:0x0048C9F0, source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListDestructionWithVTableCall(void *this) {
    //     int result;
    //     void *cur = *(void **)(this + 0x31C);
    //     for (; cur; result = FreeWrapper_7bcf(cur)) {
    //       void *node = cur;
    //       bool skip = (*(unsigned char *)(node + 0xC) == 0);
    //       cur = *(void **)(node + 4);
    //       if (!skip && *(unsigned int *)node)
    //         (**(int (__thiscall ***)(void *, int))node)(node, 1);
    //     }
    //     *(void **)(this + 0x31C) = 0;
    //     *(void **)(this + 0x320) = 0;
    //     *(int *)(this + 0x324) = 0;
    //     *(int *)(this + 0x328) = 0;
    //     *(int *)(this + 0x32C) = 0;
    //     *(int *)(this + 0x330) = 0;
    //     *(int *)(this + 0x334) = 0;
    //     *(int *)(this + 0x338) = 0;
    //     *(int *)(this + 0x340) = 0;
    //     *(unsigned char *)(this + 0x33C) = 1;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the indirect vtable destructor target (the node's vtable slot) is node-type dependent and cannot be resolved from this packet.
    // UNRESOLVED: Semantic roles of the state-block fields this+0x320 .. this+0x340 (tail pointer, counts, scrolling state) are not individually established here; only the group reset and the 0x33C=1 direction byte are evidenced.
    // UNRESOLVED: The return value is the incidental result of the last free call, not a documented success/error code.
}
