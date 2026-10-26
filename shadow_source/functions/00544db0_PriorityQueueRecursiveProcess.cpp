// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544DB0
// Canonical corpus name: PriorityQueueRecursiveProcess
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PriorityQueueRecursiveProcess_00544db0.c

void UnknownObject::PriorityQueueRecursiveProcess()
{
    // Recursively processes a node whose children are reached at this+0x44 and this+0x4C. Recurses into the first child whenever it is non-null, and into the second child only when it is non-null and the a2 flag is set; either recursion returning -1 aborts the whole walk with -1. When the node has a linked-list head at this+0x204, iterates the list following the +16 next pointer while sub_54CA00 returns zero, returning -1 as soon as sub_54CA00 returns non-zero. Returns 0 when the list head is null, the walk reaches a null next pointer, or no error is reported. Called from sub_544740.
    // GUARD: Read the first child pointer at this+0x44 and skip its recursion when it is null. [field:this:0x00000044, source:raw]
    // CALL: Recurse into the first child with the flag set to 1; when the recursion returns -1, return -1 immediately. [callee:0x00544DB0, field:this:0x00000044, source:raw]
    // GUARD: Read the second child pointer at this+0x4C and skip its recursion when it is null or when argument a2 is zero. [field:this:0x0000004C, source:raw]
    // CALL: Recurse into the second child with the flag set to 1; when the recursion returns -1, return -1 immediately. [callee:0x00544DB0, field:this:0x0000004C, source:raw]
    // GUARD: Read the linked-list head at this+0x204; when it is null, skip list iteration and return 0. [field:this:0x00000204, source:raw]
    // LOOP: Iterate the linked list starting at the head stored in this+0x204, calling sub_54CA00 on each node and continuing while it returns zero. [callee:0x0054CA00, field:this:0x00000204, source:raw]
    // ASSIGNMENT: Advance to the next list node by reading the pointer at +16 of the current node. [field:*(this+0x214):0x00000010, source:raw]
    // GUARD: When the next pointer at +16 is null, end the walk and return 0. [field:*(this+0x214):0x00000010, source:raw]
    // RETURN: Return -1 when sub_54CA00 returns non-zero on the current list node. [callee:0x0054CA00, source:raw]
    // RETURN: Return 0 when no child recursion or list element reported an error. [function:0x00544DB0, source:raw]
    // CALL: Invoked from sub_544740 (0x00544740). [caller:0x00544740]

    // Conservative worker pseudocode:
    //   int PriorityQueueRecursiveProcess(Node* this, int a2) {
    //     if (this->childA && PriorityQueueRecursiveProcess(this->childA, 1)) return -1;
    //     if (this->childB && a2 && PriorityQueueRecursiveProcess(this->childB, 1)) return -1;
    //     Node* node = this->listHead;
    //     if (node) {
    //       while (!sub_54CA00(node)) {
    //         node = *(Node**)(node + 16);
    //         if (!node) return 0;
    //       }
    //       return -1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The child pointers at this+0x44 and this+0x4C are recursed with the flag hard-coded to 1, while the top-level a2 flag only gates the second child; the meaning of that flag is not evidenced beyond the guard behavior.
    // UNRESOLVED: The relationship between the linked-list head at this+0x204 and the packet's list-node field base *(this+0x214) is not established; the +16 offset is applied to a node obtained from the walk, and its base linkage is inferred.
    // UNRESOLVED: The exact role of sub_54CA00's non-zero return (what error or stop condition it signals) is not evidenced.
}
