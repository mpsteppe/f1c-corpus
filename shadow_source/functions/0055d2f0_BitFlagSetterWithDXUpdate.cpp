// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D2F0
// Canonical corpus name: BitFlagSetterWithDXUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagSetterWithDXUpdate_0055d2f0.c

void UnknownObject::BitFlagSetterWithDXUpdate()
{
    // Sets or clears bit 7 (0x80) of the flag word at this+0x0 based on the boolean a2 (non-zero sets, zero clears), then calls DirectXVertexBufferTextureCoordinateSetup passing the global dword_8B78A0, this pointer, the field at this+0x4, and constant 1. Returns the DirectX call's result. Invoked by sub_4FCEE0 and sub_55A500.
    // ASSIGNMENT: Read the current flag word: v2 = *this. [field:this:0x00000000, source:raw]
    // GUARD: Branch on a2: non-zero selects the bit-7 set path, zero selects the bit-7 clear path. [source:raw]
    // CALCULATION: Set bit 7: v3 = v2 | 0x80. [field:this:0x00000000, source:raw]
    // CALCULATION: Clear bit 7: v3 = v2 & 0xFFFFFF7F. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the updated flag word: *this = v3. [field:this:0x00000000, source:raw]
    // CALL: Call DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 1). [callee:0x005416A0, global:0x008B78A0, field:this:0x00000004, source:raw]
    // RETURN: Return the DirectX setup call's result. [source:raw]
    // CALL: Invoked by sub_4FCEE0 and sub_55A500 during DirectX vertex/texture management. [caller:0x004FCEE0, caller:0x0055A500, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *this;
    //   if (a2) v3 = v2 | 0x80;
    //   else    v3 = v2 & 0xFFFFFF7F;
    //   *this = v3;
    //   return DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 1);
    // UNRESOLVED: Purpose of bit 7 and of the field at this+0x4 within the owning object is not established here.
    // UNRESOLVED: Role of the global dword_8B78A0 (manager/context) passed to the DirectX setup is inferred from call order only.
}
