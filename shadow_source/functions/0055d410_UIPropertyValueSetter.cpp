// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D410
// Canonical corpus name: UIPropertyValueSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIPropertyValueSetter_0055d410.c

void UnknownObject::UIPropertyValueSetter()
{
    // Stores integer argument a3 into one of three per-group alpha/scale factor fields (0x14, 0x24, 0x34) selected by selector a2 (1, 2, or 3), then calls DirectXVertexBufferTextureCoordinateSetup to refresh the DirectX vertex buffer texture coordinates from this+0x4, and finally sets the 0x800 dirty flag in the UI root context pointed to by dword_8B8F28. Called by sub_4FCEE0 and sub_55A500.
    // GUARD: Switch on selector a2: case 1 selects group 1 (offset 0x14), case 2 selects group 2 (offset 0x24), case 3 selects group 3 (offset 0x34); no write occurs for any other value [source:raw]
    // ASSIGNMENT: When a2 == 1 store a3 into this[5] (offset 0x14), the alpha/scale factor for group 1 [field:this:0x00000014, source:raw]
    // ASSIGNMENT: When a2 == 2 store a3 into this[9] (offset 0x24), the alpha/scale factor for group 2 [field:this:0x00000024, source:raw]
    // ASSIGNMENT: When a2 == 3 store a3 into this[13] (offset 0x34), the alpha/scale factor for group 3 [field:this:0x00000034, source:raw]
    // CALL: Call DirectXVertexBufferTextureCoordinateSetup with the global device/context dword_8B78A0, this pointer, this[1] (offset 0x4, read-only vertex buffer identifier), and the mode derived from the selected group (2, 3, or 4) to refresh texture coordinates [callee:0x005416A0, field:this:0x00000004, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Set the 0x800 dirty flag in the UI root context at dword_8B8F28 by OR-ing it into the DWORD at offset 236 of that context [global:0x008B8F28, source:raw]
    // RETURN: Return dword_8B8F28 (the UI root context pointer) [function:0x0055D410, global:0x008B8F28, source:raw]
    // CALL: Invoked by sub_4FCEE0 (004FCEE0) and sub_55A500 (0055A500) to set an alpha/scale factor and refresh the vertex buffer [caller:0x004FCEE0, caller:0x0055A500, source:raw]

    // Conservative worker pseudocode:
    //   switch (a2) {
    //     case 1: this[5] = a3;  DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 2); break;
    //     case 2: this[9] = a3;  DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 3); break;
    //     case 3: this[13] = a3; DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 4); break;
    //   }
    //   dword_8B8F28 + 236 |= 0x800;
    //   return dword_8B8F28;
    // UNRESOLVED: The exact semantics of the three stored values (alpha vs scale) and of the DirectX modes 2/3/4 are inferred from the sibling analysis of sub_55D320 and are not proven within this function
    // UNRESOLVED: this[1] (offset 0x4) is read-only here and passed to the DirectX call as the vertex buffer identifier, but its concrete object role is not evidenced
}
