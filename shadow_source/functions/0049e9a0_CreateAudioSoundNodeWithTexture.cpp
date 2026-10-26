// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E9A0
// Canonical corpus name: AudioSoundCreateWithHandle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSoundCreateWithHandle_0049e9a0.c

void UnknownObject::CreateAudioSoundNodeWithTexture()
{
    // Allocates a 96-byte node via the Nh-malloc wrapper, zero-fills it, and stores the pointer at this 0xC. Sets flag bit 0 at node+68, then attempts D3D texture creation with parameters (a2, 0, 2052). If texture creation succeeds the node is cleaned up and freed and this 0xC is cleared to 0; on failure the node pointer is retained in this 0xC for retry. Structurally identical to the vehicle-node creator except it stores the handle at this 0xC.
    // CALL: Allocates 96 bytes for the node struct via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // GUARD: Branches on the allocation result: zero-fill only when the allocation returned a non-null pointer. [source:raw]
    // CALL: Zero-initializes the allocated 96-byte struct via StructInitWithZeroFill. [callee:0x0054FE10]
    // ASSIGNMENT: Stores the node pointer (or 0 when allocation failed) into this 0xC. [field:this:0x0000000C, source:raw]
    // GUARD: Proceeds to flag-setting and texture creation only when the node pointer is non-null. [source:raw]
    // ASSIGNMENT: Sets bit 0 of the flag dword at node+68 via bitwise-or with 1. [source:raw]
    // CALL: Attempts D3D texture creation with arguments (a2, 0, 2052). [callee:0x00550080]
    // GUARD: On D3D texture creation success, enters the cleanup-and-free path. [source:raw]
    // CALL: Invokes EmptyStub_7470 on the node pointer read from this 0xC as a pre-free cleanup step. [callee:0x00557470, field:this:0x0000000C]
    // CALL: Frees the node struct via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clears this 0xC to 0 after the successful texture-creation path frees the node. [field:this:0x0000000C]
    // RETURN: Returns this 0xC: the retained node pointer on the failure path, or 0 after the success path cleared it. [source:raw, function:0x0049E9A0]

    // Conservative worker pseudocode:
    //   ptr = OperatorNewNhMallocWrapper(96);
    //   this[3] = ptr ? StructInitWithZeroFill(ptr) : 0;
    //   if (this[3]) {
    //     *(this[3] + 68) |= 1;
    //     if (D3DTextureCreation(a2, 0, 2052)) {
    //       if (this[3]) {
    //         EmptyStub_7470(this[3]);
    //         FreeWrapper_7bcf(this[3]);
    //       }
    //       this[3] = 0;
    //     }
    //   }
    //   return this[3];
    // UNRESOLVED: The 2052 literal passed to D3DTextureCreation is uninterpreted.
    // UNRESOLVED: The meaning of flag bit 0 at node+68 is unknown.
    // UNRESOLVED: The a2 argument's type and the meaning of the D3DTextureCreation return value are unproven.
    // UNRESOLVED: The node struct layout beyond offset 68 and the this object owning offset 0xC are unknown.
    // UNRESOLVED: The claimed audio subsystem role of this 0xC handle is not proven by static evidence alone.
}
