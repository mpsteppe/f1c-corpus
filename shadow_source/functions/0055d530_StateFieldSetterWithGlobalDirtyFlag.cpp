// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D530
// Canonical corpus name: StateFieldSetterWithGlobalDirtyFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFieldSetterWithGlobalDirtyFlag_0055d530.c

void UnknownObject::StateFieldSetterWithGlobalDirtyFlag()
{
    // Unconditional single-state-field setter. Stores the incoming value a2 into the state field this[20] (this+0x50), then calls DirectXVertexBufferTextureCoordinateSetup with the saved vertex-buffer handle (this[1]) in mode 7, and finally ORs the dirty flag 0x800 into the global UI context at dword_8B8F28 + 236. Returns the UI context pointer. Part of the DirectX vertex-buffer state update chain.
    // ASSIGNMENT: Read v3 = this[1] (this+0x4), a vertex-buffer handle/identifier, before it could be affected by later writes. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Store the incoming value a2 into the state field this[20] (this+0x50). [source:raw, field:this:0x00000050]
    // CALL: Call DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, v3, 7) to push the state value into the DirectX vertex-buffer path with mode 7. [source:raw, callee:0x005416A0, global:0x008B78A0]
    // ASSIGNMENT: Capture result = dword_8B8F28 (0x008B8F28), the global UI context pointer. [source:raw, global:0x008B8F28]
    // ASSIGNMENT: Set the dirty flag: *(dword_8B8F28 + 236) |= 0x800. [source:raw, global:0x008B8F28]
    // RETURN: Return the UI context pointer (result). [source:raw]
    // CALL: Called by sub_55A500 (0x0055A500) as part of the DirectX vertex-buffer state update chain. [caller:0x0055A500]

    // Conservative worker pseudocode:
    //   int sub_55D530(void* this, int a2) {
    //     int v3 = ((int*)this)[1];
    //     ((int*)this)[20] = a2;
    //     DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, (int)this, v3, 7);
    //     int result = dword_8B8F28;
    //     *(int*)(dword_8B8F28 + 236) |= 0x800;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of DirectX mode 7 and of the dirty flag 0x800 at context offset 236 are not established by this packet.
    // UNRESOLVED: Global object identities (dword_8B78A0, dword_8B8F28) are described only nominally as vertex-buffer/UI context; not independently confirmed.
    // UNRESOLVED: Ownership is UnknownObject.
}
