// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ADC0
// Canonical corpus name: ObjectConstructor_adc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructor_adc0_0049adc0.c

void UnknownObject::ObjectConstructor_adc0()
{
    // Appends a node holding a pair of 16-bit values to an owned linked list. Allocates a 4-byte word-pair buffer storing a2/a3, then a 12-byte node that points to it (with a zeroed link and a 1 flag). The node is appended to the list: when the head at this+0x0 is null it becomes both head and tail (this+0x0 and this+0x8), otherwise it is linked after the tail (this+0x4). this+0x4 is always advanced to the new node and the node count at this+0xC is incremented. Returns 1 on success; on first-allocation failure calls FreeWrapper_7bcf(0) and returns 0.
    // CALL: Allocate 4 bytes via OperatorNewNhMallocWrapper for the 16-bit value pair buffer. [callee:0x00587C03, source:raw]
    // GUARD: If the pair-buffer allocation returns null, call FreeWrapper_7bcf(0) and return 0 (failure path). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Store the 16-bit parameters into the pair buffer: v4[0] = a2 and v4[1] = a3. [source:raw]
    // CALL: Allocate 12 bytes via OperatorNewNhMallocWrapper for the list node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the node: node[0] = pair buffer, node[4] = 0, node[8] = 1. When the node allocation fails the node pointer is set to null. [source:raw]
    // GUARD: Branch on the list head: if *this (head) is non-null, link the new node after the tail (this[1]+4 = node); otherwise set both the head (this[0]) and tail (this[2]) to the new node. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Advance the tail pointer: this[1] = new node. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Increment the node count at this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return 1 on success, 0 on allocation failure. [source:raw]
    // CALL: Invoked by list-building callers: sub_492A40 (00492A40), sub_493060 (00493060), and IndexedListEntryWrite (0049AE40). [caller:0x00492A40, caller:0x00493060, caller:0x0049AE40, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49ADC0(int this, short a2, short a3) {
    //     short* pair = OperatorNewNhMallocWrapper(4);
    //     if (!pair) { FreeWrapper_7bcf(0); return 0; }
    //     pair[0] = a2;
    //     pair[1] = a3;
    //     int node = OperatorNewNhMallocWrapper(12);
    //     if (node) { *(int*)node = pair; *(int*)(node+4) = 0; *(BYTE*)(node+8) = 1; }
    //     else node = 0;
    //     if (*(int*)this) *(int*)(this[1]+4) = node;
    //     else { this[0] = node; this[2] = node; }
    //     this[1] = node;
    //     ++this[3];
    //     return 1;
    //   }
    // UNRESOLVED: Object identity and the semantic meaning of the stored 16-bit pair (a2/a3) are unknown; existing analysis proposes a linked-int-pair node but that is DERIVED.
    // UNRESOLVED: When the first allocation succeeds but the 12-byte node allocation fails, the function returns 0 without freeing the leaked pair buffer (FreeWrapper_7bcf is only called on the first-allocation failure).
    // UNRESOLVED: The packet lists this+0xC as read-only even though the source increments it; the node count field grows per call.
}
