// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B743
// Canonical corpus name: ConstructorSize0x30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorSize0x30_0050b743.c

void UnknownObject::ConstructDirectXSurface0x30()
{
    // DirectX surface/texture sub-constructor (size 0x30): calls DirectXTextureCreationWithMipmapChain to initialize the base object, then installs vtable off_5ADDAC at this+0x0 and returns this.
    // CALL: Calls DirectXTextureCreationWithMipmapChain(this, a2, 0x30, 1) to initialize the DirectX surface base object with a mipmap chain and size 0x30. [callee:0x00507496, caller:0x0050B8A9, source:raw, abi:lead]
    // ASSIGNMENT: Writes the address of vtable off_5ADDAC into this at offset 0x0. [global:0x005ADDAC, field:this:0x00000000, source:raw]
    // RETURN: Returns the initialized this pointer. [function:0x0050B743, source:raw]

    // Conservative worker pseudocode:
    //   DirectXTextureCreationWithMipmapChain(this, a2, 0x30, 1);
    //   this->vtable = &off_5ADDAC;
    //   return this;
    // UNRESOLVED: Meaning of the second parameter a2 passed through to DirectXTextureCreationWithMipmapChain is unknown.
    // UNRESOLVED: Semantics of the 0x30 size argument (object allocation size vs texture dimension) are not established.
}
