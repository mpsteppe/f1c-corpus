// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CA410
// Canonical corpus name: sub_4CA410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CA410_004ca410.c

void UnknownObject::FreeChild()
{
    // Frees a dynamically-allocated child object held at this+0x50 when non-null. Reads the pointer this[20] (this+0x50); if it is non-null, calls EmptyStub_0170 (no-op) and then returns FreeWrapper_7bcf(child), otherwise falls through to return an uninitialized result. Existing analysis places this on the SpecialFX_Post cleanup path.
    // ASSIGNMENT: Read the child-object pointer stored at this[20] (byte offset this+0x50) into a local. [field:this:0x00000050, source:raw]
    // GUARD: Guard on the child pointer being non-null: only when it is non-null does the cleanup path run; a null pointer falls through to the final return. [field:this:0x00000050, source:raw]
    // CALL: Call EmptyStub_0170, a no-op stub invoked immediately before the free. [callee:0x004B0170, source:raw]
    // CALL: Call FreeWrapper_7bcf(child) to release the child object from the heap and return its result. [callee:0x00587BCF, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result when the child was non-null; the null branch returns an uninitialized result (Hex-Rays artifact). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CA410(int *this) {
    //     void *child = (void *)this[20];
    //     if (child) {
    //       EmptyStub_0170();
    //       return FreeWrapper_7bcf(child);
    //     }
    //     return result;  // uninitialized in the null branch (Hex-Rays artifact)
    //   }
    // UNRESOLVED: The null branch returns an uninitialized `result`; this is a Hex-Rays artifact and the effective behavior of that path is not defined by the packet.
    // UNRESOLVED: The existing analysis names this SpecialFXFreeChild and places it on the SpecialFX_Post (0x004CFED0) cleanup phase at DERIVED trust; that owner claim is not adopted here because the packet marks the owner UNKNOWN with no evidence.
    // UNRESOLVED: The type of the object freed by FreeWrapper_7bcf and the meaning of this+0x50 are not established by the packet.
}
