// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D4F0
// Canonical corpus name: SetUIPropertyGroupWithChainUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetUIPropertyGroupWithChainUpdate_0055d4f0.c

void UnknownObject::SetUIPropertyGroupWithChainUpdate()
{
    // Stores three parameters into this fields 0x38, 0x3C, 0x40 (from a2, a3, a4), then calls DirectXVertexBufferTextureCoordinateSetup with the global dword_8B78A0, this, this[0x4], and mode 6, and finally sets bit 0x800 on the dword stored at dword_8B8F28 + 236, returning that dword.
    // ASSIGNMENT: Store a3 into field 0x3C (this[15]). [source:raw, field:this:0x0000003C]
    // ASSIGNMENT: Read this[0x4] into v4 for use as the DirectX vertex buffer handle/identifier. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Store a2 into field 0x38 (this[14]). [source:raw, field:this:0x00000038]
    // ASSIGNMENT: Store a4 into field 0x40 (this[16]). [source:raw, field:this:0x00000040]
    // CALL: Call DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, v4, 6). [source:raw, callee:0x005416A0, global:0x008B78A0]
    // CALCULATION: Set result = dword_8B8F28 and OR 0x800 into the dword at dword_8B8F28 + 236 (dirty/update flag). [source:raw, global:0x008B8F28]
    // RETURN: Return result (the dword_8B8F28 value). [source:raw]

    // Conservative worker pseudocode:
    //   int SetUIPropertyGroupWithChainUpdate(int* this, int a2, int a3, int a4) {
    //     this[15] = a3;
    //     int v4 = this[1];
    //     this[14] = a2;
    //     this[16] = a4;
    //     DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, v4, 6);
    //     int result = dword_8B8F28;
    //     *(int*)(dword_8B8F28 + 236) |= 0x800;
    //     return result;
    //   }
    // UNRESOLVED: dword_8B78A0 identity/role (sound manager per prior analysis) is not established by raw source.
    // UNRESOLVED: Bit 0x800 at dword_8B8F28 + 236 marks a dirty/update state; the exact consumer of the flag is not evidenced here.
    // UNRESOLVED: Mode 6 meaning for DirectXVertexBufferTextureCoordinateSetup is not defined by this packet.
    // UNRESOLVED: The three stored values' consumer (vertex texture coordinates per prior analysis) is caller-dependent.
}
