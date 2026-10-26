// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548E00
// Canonical corpus name: ShortComputation_8e00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8e00_00548e00.c

void UnknownObject::objectZeroInitConstructor()
{
    // Constructs an object: bulk zero-initializes it via GlobalZeroInit_c2a0, then explicitly clears the byte at offset 0x0 and the DWORD fields at offsets 0x10 and 0x14, and returns the this pointer.
    // CALL: Bulk zero-initialize the entire object via GlobalZeroInit_c2a0 [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Clear the first byte of the object at offset 0x0 to 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the DWORD field at offset 0x10 to 0 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Clear the DWORD field at offset 0x14 to 0 [field:this:0x00000014, source:raw]
    // RETURN: Return the this pointer as the constructed object [function:0x00548E00, source:raw]

    // Conservative worker pseudocode:
    //   void* construct(void* this) {
    //     GlobalZeroInit_c2a0(this);
    //     *((uint8_t*)this + 0x0) = 0;
    //     *((uint32_t*)((uint8_t*)this + 0x10)) = 0;
    //     *((uint32_t*)((uint8_t*)this + 0x14)) = 0;
    //     return this;
    //   }
}
