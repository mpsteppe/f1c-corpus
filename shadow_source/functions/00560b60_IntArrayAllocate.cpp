// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560B60
// Canonical corpus name: IntArrayAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntArrayAllocation_00560b60.c

void UnknownObject::IntArrayAllocate()
{
    // Initializes an integer-array container object: zeroes the element-count word at this+0x0 and allocates backing storage for a2 integers via OperatorNewNhMallocWrapper(4 * a2), storing the pointer at this+0x4. Returns this as the initialized container.
    // ASSIGNMENT: Set the element count at this+0x0 to 0. [field:this:0x00000000]
    // CALL: Allocate backing storage for a2 integers via OperatorNewNhMallocWrapper with byte size 4 * a2. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the allocated pointer at this+0x4. [field:this:0x00000004]
    // RETURN: Return this so the caller can chain further initialization. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* IntArrayAllocate(_DWORD* this, int a2) {
    //     this[0] = 0;
    //     this[1] = OperatorNewNhMallocWrapper(4 * a2);
    //     return this;
    //   }
    // UNRESOLVED: The element type is int-sized (4 bytes per element follows from the allocation scaling), but no element-type tag exists in this object.
    // UNRESOLVED: Whether a2 is a fixed capacity or an initial count is not observable here; only the allocation size scales with it.
    // UNRESOLVED: No deallocation or resize path is visible; the container lifetime is owned by the caller.
}
