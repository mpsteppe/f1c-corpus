// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BB90
// Canonical corpus name: ObjectAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectAllocator_0045bb90.c

void UnknownObject::ObjectAllocator()
{
    // Allocates an 812-byte block from the heap via 0x00587C03. On success, calls the initializer 0x0045BB40 on the block and stores the resulting pointer into this[0x0]. On allocation failure, stores 0 into this[0x0]. Returns this.
    // CALL: Request an 812-byte heap allocation through the operator-new wrapper 0x00587C03. [callee:0x00587C03, source:raw]
    // GUARD: Branch on whether the allocation returned a non-null pointer. [source:raw]
    // CALL: On success, initialize the allocated block by calling 0x0045BB40 with the block pointer. [callee:0x0045BB40, source:raw]
    // ASSIGNMENT: On success, store the initialized block pointer into this[0x0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: On allocation failure, store 0 into this[0x0]. [field:this:0x00000000, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void *__thiscall ObjectAllocator(int *this) {
    //     void *block = OperatorNewNhMallocWrapper(812);
    //     this[0] = block ? (int)ShortComputation_bb40(block) : 0;
    //     return this;
    //   }
    // UNRESOLVED: The exact 812-byte layout produced by initializer 0x0045BB40 is not covered by this packet.
    // UNRESOLVED: The owning type of this object is unknown; the stored pointer's downstream consumers are not in this packet.
    // UNRESOLVED: No static caller was captured for this function.
}
