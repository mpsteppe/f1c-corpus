// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050AF3B
// Canonical corpus name: ObjectInitWithVTable_af3b
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTable_af3b_0050af3b.c

void UnknownObject::TextureConstructorSize32()
{
    // Unconditional texture-object constructor: runs a DirectX texture/mipmap-chain base init on this with size 0x20 and count 1, then overwrites the vtable pointer at this[0] with off_5ADC9C and returns this. Called by DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050B8A9).
    // CALL: Call DirectXTextureCreationWithMipmapChain(this, a2, 0x20u, 1) to perform base initialization with a 0x20-byte unit size and a chain count of 1. [callee:0x00507496, source:raw]
    // ASSIGNMENT: Set the vtable pointer: *(_DWORD *)this = &off_5ADC9C. [field:this:0x00000000, global:0x005ADC9C, source:raw]
    // RETURN: Return this (the initialized object). [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50AF3B(float *this, float *a2) {
    //     DirectXTextureCreationWithMipmapChain(this, a2, 0x20u, 1);
    //     *(_DWORD *)this = &off_5ADC9C;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of a2 (second texture-creation argument) is caller-supplied and unknown here.
    // UNRESOLVED: Object class implied by vtable off_5ADC9C (VTable_ShaderLoader) is not named in the packet.
}
