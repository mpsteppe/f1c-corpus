// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050AE76
// Canonical corpus name: ConstructorSize0x10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorSize0x10_0050ae76.c

void UnknownObject::TextureConstructorSize16()
{
    // Unconditional texture-object constructor: runs a DirectX texture/mipmap-chain base init on this with size 0x10 and count 1, then overwrites the vtable pointer at this[0] with off_5ADC7C and returns this. Called by DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050B8A9).
    // CALL: Call DirectXTextureCreationWithMipmapChain(this, a2, 0x10u, 1) to perform base initialization with a 0x10-byte unit size and a chain count of 1. [callee:0x00507496, source:raw]
    // ASSIGNMENT: Set the vtable pointer: *(_DWORD *)this = &off_5ADC7C. [field:this:0x00000000, global:0x005ADC7C, source:raw]
    // RETURN: Return this (the initialized object). [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50AE76(float *this, float *a2) {
    //     DirectXTextureCreationWithMipmapChain(this, a2, 0x10u, 1);
    //     *(_DWORD *)this = &off_5ADC7C;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of a2 (second texture-creation argument) is caller-supplied and unknown here.
    // UNRESOLVED: Object class implied by vtable off_5ADC7C (DXTextureVTable) is not named in the packet.
}
