// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055FBE0
// Canonical corpus name: sub_55FBE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55FBE0_0055fbe0.c

void UnknownObject::cubeMapTextureInit()
{
    // Constructor-style initializer for a cube map texture struct. Zeroes the whole object through GlobalZeroInit_c2a0, copies the cube map filename constant aCubemas410 onto the struct base, then explicitly clears eleven scalar fields (offsets 12, 16, 20, 276, 280, 284, 288, 292, 296, 300, 304). Returns the this pointer.
    // CALL: Zero-initialize the entire struct via GlobalZeroInit_c2a0 on this. [callee:0x0053C2A0]
    // ASSIGNMENT: Copy the cube map filename string constant aCubemas410 onto the struct base via strcpy. [global:0x005DBC08, source:raw]
    // ASSIGNMENT: Write 0 to the dword at offset 12. [field:this:0x0000000C]
    // ASSIGNMENT: Write 0 to the dword at offset 16. [field:this:0x00000010]
    // ASSIGNMENT: Write 0 to the byte at offset 20. [field:this:0x00000014]
    // ASSIGNMENT: Write 0 to the dword at offset 276. [field:this:0x00000114]
    // ASSIGNMENT: Write 0 to the dword at offset 280. [field:this:0x00000118]
    // ASSIGNMENT: Write 0 to the dword at offset 284. [field:this:0x0000011C]
    // ASSIGNMENT: Write 0 to the dword at offset 288. [field:this:0x00000120]
    // ASSIGNMENT: Write 0 to the dword at offset 292. [field:this:0x00000124]
    // ASSIGNMENT: Write 0 to the dword at offset 296. [field:this:0x00000128]
    // ASSIGNMENT: Write 0 to the dword at offset 300. [field:this:0x0000012C]
    // ASSIGNMENT: Write 0 to the dword at offset 304. [field:this:0x00000130]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void cubeMapTextureInit(int this) {
    //     GlobalZeroInit_c2a0((void*)this);
    //     strcpy((char*)this, aCubemas410);
    //     *(DWORD*)(this+12) = 0; *(DWORD*)(this+16) = 0; *(BYTE*)(this+20) = 0;
    //     *(DWORD*)(this+276) = 0; *(DWORD*)(this+280) = 0; *(DWORD*)(this+284) = 0;
    //     *(DWORD*)(this+288) = 0; *(DWORD*)(this+292) = 0; *(DWORD*)(this+296) = 0;
    //     *(DWORD*)(this+300) = 0; *(DWORD*)(this+304) = 0;
    //   }
    // UNRESOLVED: The exact semantic roles of the individual cleared fields (offsets 12/16/20 and 276-304) and the string content behind aCubemas410 are not established by this packet.
}
