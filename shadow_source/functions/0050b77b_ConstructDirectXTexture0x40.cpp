// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B77B
// Canonical corpus name: ObjectInitWithVTable_b77b
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTable_b77b_0050b77b.c

void UnknownObject::ConstructDirectXTexture0x40()
{
    // DirectX texture sub-constructor (size 0x40): calls DirectXTextureCreationWithMipmapChain to initialize the base object, then installs vtable off_5ADDBC at this+0x0 and returns this.
    // CALL: Calls DirectXTextureCreationWithMipmapChain(this, a2, 0x40, 1) to initialize the DirectX texture base object with a mipmap chain and size 0x40. [callee:0x00507496, caller:0x0050B8A9, source:raw, abi:lead]
    // ASSIGNMENT: Writes the address of vtable off_5ADDBC into this at offset 0x0. [global:0x005ADDBC, field:this:0x00000000, source:raw]
    // RETURN: Returns the initialized this pointer. [function:0x0050B77B, source:raw]

    // Conservative worker pseudocode:
    //   DirectXTextureCreationWithMipmapChain(this, a2, 0x40, 1);
    //   this->vtable = &off_5ADDBC;
    //   return this;
    // UNRESOLVED: Meaning of the second parameter a2 passed through to DirectXTextureCreationWithMipmapChain is unknown.
    // UNRESOLVED: Semantics of the 0x40 size argument (object allocation size vs texture dimension) are not established.
}
