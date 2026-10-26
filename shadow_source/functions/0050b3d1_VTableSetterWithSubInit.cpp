// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B3D1
// Canonical corpus name: VTableSetterWithSubInit_b3d1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSetterWithSubInit_b3d1_0050b3d1.c

void UnknownObject::VTableSetterWithSubInit()
{
    // DirectX texture constructor variant. Calls DirectXTextureCreationWithMipmapChain(this, a2, 0x20, 3) to initialize the base texture object with a mipmap chain, then overwrites the vtable pointer at this+0x0 with off_5ADD3C and returns this.
    // CALL: Call DirectXTextureCreationWithMipmapChain(this, a2, 0x20, 3) to initialize the base DirectX texture object with mipmap chain, size 0x20, flag 3. [source:raw, callee:0x00507496]
    // ASSIGNMENT: Write the vtable pointer at this+0x0 to the RenderNode vtable off_5ADD3C. [source:raw, field:this:0x00000000, global:0x005ADD3C]
    // RETURN: Return the initialized object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50B3D1(float *this, float *a2) {
    //     DirectXTextureCreationWithMipmapChain(this, a2, 0x20u, 3);
    //     *(DWORD *)this = &off_5ADD3C;
    //     return this;
    //   }
    // UNRESOLVED: Owner class is unknown; this is a texture sub-constructor that installs a distinct vtable (off_5ADD3C) after base init.
    // UNRESOLVED: Meaning of the 0x20 size and flag 3 arguments to DirectXTextureCreationWithMipmapChain is caller/format dependent.
    // UNRESOLVED: Identity of off_5ADD3C vtable members is unknown.
}
