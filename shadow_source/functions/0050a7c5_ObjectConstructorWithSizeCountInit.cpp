// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A7C5
// Canonical corpus name: ObjectConstructorWithSizeCountInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithSizeCountInit_0050a7c5.c

void UnknownObject::ObjectConstructorWithSizeCountInit()
{
    // thiscall constructor that first delegates to DirectXTextureCreationWithMipmapChain(this, a2, 0x18, 1) to perform base object initialization with a 24-byte allocation and count 1, then installs the vtable pointer off_5ADBA8 at offset 0x0 and returns the this pointer. Called from DirectXTextureSurfaceFactoryDispatchingFourCCCod as a texture-object construction path.
    // CALL: Calls DirectXTextureCreationWithMipmapChain(this, a2, 0x18, 1) to run base object initialization with size 0x18 and count 1 [callee:0x00507496, source:raw]
    // ASSIGNMENT: Writes the vtable pointer off_5ADBA8 into the object at offset 0x0, installing the object's virtual dispatch table [field:this:0x00000000, global:0x005ADBA8, source:raw]
    // RETURN: Returns the this pointer as the constructed object [function:0x0050A7C5, source:raw]
    // CALL: Used as a construction helper by DirectXTextureSurfaceFactoryDispatchingFourCCCod [caller:0x0050B8A9]

    // Conservative worker pseudocode:
    //   DirectXTextureCreationWithMipmapChain(this, a2, 0x18, 1);
    //   *(_DWORD *)this = &off_5ADBA8;
    //   return this;
    // UNRESOLVED: Object layout beyond the vtable at offset 0x0 is not defined by this packet
    // UNRESOLVED: Semantics of the off_5ADBA8 vtable and the meaning of the 0x18 size are established by the texture system elsewhere
}
