// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E930
// Canonical corpus name: VehicleNodeCreation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleNodeCreation_0049e930.c

void UnknownObject::CreateVehicleNodeWithTexture()
{
    // Allocates a 96-byte node via the Nh-malloc wrapper, zero-fills it, and stores the pointer at this 0x8. Sets flag bit 0 at node+68, then attempts D3D texture creation with parameters (a2, 0, 2052). If texture creation succeeds the node is cleaned up and freed and this 0x8 is cleared to 0; on failure the node pointer is retained in this 0x8 for retry.
    // CALL: Allocates 96 bytes for the node struct via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // GUARD: Branches on the allocation result: zero-fill only when the allocation returned a non-null pointer. [source:raw]
    // CALL: Zero-initializes the allocated 96-byte struct via StructInitWithZeroFill. [callee:0x0054FE10]
    // ASSIGNMENT: Stores the node pointer (or 0 when allocation failed) into this 0x8. [field:this:0x00000008, source:raw]
    // GUARD: Proceeds to flag-setting and texture creation only when the node pointer is non-null. [source:raw]
    // ASSIGNMENT: Sets bit 0 of the flag dword at node+68 via bitwise-or with 1. [source:raw]
    // CALL: Attempts D3D texture creation with arguments (a2, 0, 2052). [callee:0x00550080]
    // GUARD: On D3D texture creation success, enters the cleanup-and-free path. [source:raw]
    // CALL: Invokes EmptyStub_7470 on the node pointer read from this 0x8 as a pre-free cleanup step. [callee:0x00557470, field:this:0x00000008]
    // CALL: Frees the node struct via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clears this 0x8 to 0 after the successful texture-creation path frees the node. [field:this:0x00000008]
    // RETURN: Returns this 0x8: the retained node pointer on the failure path, or 0 after the success path cleared it. [source:raw, function:0x0049E930]

    // Conservative worker pseudocode:
    //   ptr = OperatorNewNhMallocWrapper(96);
    //   this[2] = ptr ? StructInitWithZeroFill(ptr) : 0;
    //   if (this[2]) {
    //     *(this[2] + 68) |= 1;
    //     if (D3DTextureCreation(a2, 0, 2052)) {
    //       if (this[2]) {
    //         EmptyStub_7470(this[2]);
    //         FreeWrapper_7bcf(this[2]);
    //       }
    //       this[2] = 0;
    //     }
    //   }
    //   return this[2];
    // UNRESOLVED: The 2052 literal passed to D3DTextureCreation is uninterpreted.
    // UNRESOLVED: The meaning of flag bit 0 at node+68 is unknown.
    // UNRESOLVED: The a2 argument's type and the meaning of the D3DTextureCreation return value are unproven.
    // UNRESOLVED: The node struct layout beyond offset 68 and the this object owning offset 0x8 are unknown.
}
