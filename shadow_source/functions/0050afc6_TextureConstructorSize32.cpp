// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050AFC6
// Canonical corpus name: sub_50AFC6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50AFC6_0050afc6.c

void UnknownObject::TextureConstructorSize32()
{
    // Constructor for a DirectX texture object using a larger size literal than its siblings. Forwards this and a2 to DirectXTextureCreationWithMipmapChain with size literal 0x20 and flag 1, then writes the vtable pointer off_5ADCAC into this+0x0 and returns this. Invoked by DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9). Straight-line construction with no guards and no early return.
    // CALL: Call DirectXTextureCreationWithMipmapChain(this, a2, 0x20u, 1) to initialize the base DirectX texture object with a mipmap chain. [callee:0x00507496, source:raw]
    // ASSIGNMENT: Set the vtable pointer at this+0x0 to the global off_5ADCAC, completing the object's class identity. [field:this:0x00000000, global:0x005ADCAC, source:raw]
    // RETURN: Return this, the fully initialized texture object. [function:0x0050AFC6, source:raw]
    // CALL: Invoked by DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9) as part of texture surface construction. [caller:0x0050B8A9, source:raw]

    // Conservative worker pseudocode:
    //   float* __thiscall sub_50AFC6(float* this, float* a2) {
    //     DirectXTextureCreationWithMipmapChain(this, a2, 0x20u, 1);
    //     *(_DWORD*)this = &off_5ADCAC;
    //     return this;
    //   }
    // UNRESOLVED: Semantics of a2 (likely an allocator/size-source argument) are caller-supplied and not defined in this function.
    // UNRESOLVED: Meaning of the flag literal 1 and size literal 0x20 passed to DirectXTextureCreationWithMipmapChain is determined inside callee 00507496.
    // UNRESOLVED: Whether the larger 0x20 size literal distinguishes a physically larger surface or a different resource type is not resolvable from this function.
}
