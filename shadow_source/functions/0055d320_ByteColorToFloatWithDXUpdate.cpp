// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D320
// Canonical corpus name: sub_55D320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55D320_0055d320.c

void UnknownObject::ByteColorToFloatWithDXUpdate()
{
    // UI colour-group updater. Selects one of three colour groups on this via a2 (1/2/3), converts the byte RGB inputs a3-a5 to floats by scaling with 0.0039215689 and a per-group alpha factor, writes the three components into the group's float fields, then pushes the group through DirectXVertexBufferTextureCoordinateSetup using the cached vertex-buffer identifier at this+4. Finally sets the 0x800 dirty bit on the UI context at dword_8B8F28+236 and returns that context pointer.
    // STATE_TRANSITION: Switch on a2 to choose the active colour group: case 1 targets floats this+8/+12/+16 with scale factor this+20; case 2 targets this+24/+28/+32 with scale this+36; case 3 targets this+40/+44/+48 with scale this+52 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Case 1: write the three colour components at this+8/+12/+16 from a3/a4/a5, each scaled by 0.0039215689 and the group alpha factor at this+20; stage DirectX slot selector v7 = 2 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Case 2: read the vertex-buffer identifier into v6 from this+4, write the three colour components at this+24/+28/+32 scaled by 0.0039215689 and the group alpha factor at this+36, then call DirectXVertexBufferTextureCoordinateSetup with slot selector 3 [field:this:0x00000004, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, callee:0x005416A0, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Case 3: write the three colour components at this+40/+44/+48 scaled by 0.0039215689 and the group alpha factor at this+52; stage DirectX slot selector v7 = 4 [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Push the colour group to the vertex buffer via DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(this+4), v7); cases 1 and 3 share this call, case 2 issues its own with selector 3 [callee:0x005416A0, global:0x008B78A0, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set the 0x800 dirty bit on the UI context: *(dword_8B8F28 + 236) |= 0x800 [global:0x008B8F28, source:raw]
    // RETURN: Return the UI context pointer dword_8B8F28; called by ByteExtractionFromUint (0x0055D3F0) [global:0x008B8F28, function:0x0055D320, caller:0x0055D3F0, source:raw]

    // Conservative worker pseudocode:
    //   switch (a2) {
    //     case 1:
    //       *(float *)(this + 8)  = (double)a3 * 0.0039215689 * *(float *)(this + 20);
    //       *(float *)(this + 12) = (double)a4 * 0.0039215689 * *(float *)(this + 20);
    //       *(float *)(this + 16) = (double)a5 * 0.0039215689 * *(float *)(this + 20);
    //       v7 = 2;
    //       goto DX;
    //     case 2:
    //       v6 = *(_DWORD *)(this + 4);
    //       *(float *)(this + 24) = (double)a3 * 0.0039215689 * *(float *)(this + 36);
    //       *(float *)(this + 28) = (double)a4 * 0.0039215689 * *(float *)(this + 36);
    //       *(float *)(this + 32) = (double)a5 * 0.0039215689 * *(float *)(this + 36);
    //       DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, v6, 3);
    //       break;
    //     case 3:
    //       *(float *)(this + 40) = (double)a3 * 0.0039215689 * *(float *)(this + 52);
    //       *(float *)(this + 44) = (double)a4 * 0.0039215689 * *(float *)(this + 52);
    //       *(float *)(this + 48) = (double)a5 * 0.0039215689 * *(float *)(this + 52);
    //       v7 = 4;
    //   DX:
    //       DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(_DWORD *)(this + 4), v7);
    //       break;
    //   }
    //   *(_DWORD *)(dword_8B8F28 + 236) |= 0x800;
    //   return dword_8B8F28;
    // UNRESOLVED: Read-only global flt_59E460 is flagged by packet facts but never referenced in the raw decompiled source; its relation to the 0.0039215689 scale constant is not evidenced here
    // UNRESOLVED: The exact UI role of the three colour groups (e.g. text colour vs cursor vs background) is not resolvable from this function alone
}
