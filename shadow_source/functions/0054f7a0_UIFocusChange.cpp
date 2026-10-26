// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054F7A0
// Canonical corpus name: UIFocusChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIFocusChange_0054f7a0.c

void UnknownObject::UIFocusChange()
{
    // Per-frame scene focus and render update. Guarded by a2 != this (no self-reference) and a non-null render-state descriptor at this+0x1E0. Clears the UI focus flag global dword_8C5F44, prepares the render batch transform through sub_54B570(this, 0, this[129]), and when the sub-object at this[129] has not yet set its busy bit 0x20000000 at +20, sets that bit and issues an indirect D3D-device-wrapper call (vtable slot +4 on dword_8B8F24) passing this[129]+220, this[129]+232 and this+69. Then stores the RenderListIteration(this, a3) result into dword_8C5F40 and runs SceneBatchRenderCheck(this, a2, a3).
    // GUARD: Self-reference guard: if a2 == this, the whole function body is skipped [source:raw]
    // GUARD: Descriptor guard: this[120] (field this+0x1E0) must be non-null, else the body is skipped [field:this:0x000001E0, source:raw]
    // ASSIGNMENT: Clear the UI focus flag global dword_8C5F44 to 0 [global:0x008C5F44, source:raw]
    // CALL: sub_54B570(this, 0, this[129]) prepares the render batch transform, passing the sub-object pointer at field this+0x204 [callee:0x0054B570, field:this:0x00000204, source:raw]
    // GUARD: Read v4 = this[129] and its flags dword v5 = *(v4+20); proceed with the device call only when bit 0x20000000 is not yet set [field:this:0x00000204, source:raw]
    // ASSIGNMENT: Set the busy bit: *(v4+20) |= 0x20000000 on the sub-object at this[129] [field:this:0x00000204, source:raw]
    // CALL: Indirect D3D device-wrapper call through vtable slot +4 of dword_8B8F24, with arguments (dword_8B8F24, this[129]+220, this[129]+232, this+69) [global:0x008B8F24, source:raw]
    // ASSIGNMENT: dword_8C5F40 = RenderListIteration(this, a3) stores the render-list processing result into the global [callee:0x0054F710, global:0x008C5F40, source:raw]
    // CALL: SceneBatchRenderCheck(this, a2, a3) runs batch visibility / collision processing at the end of the guarded body [callee:0x0054F5C0, source:raw]
    // CALL: Called from SwitchBasedStateHandler, SphereProximityTag and AIRacingLinePathFollowing as a shared per-frame focus/render update [caller:0x0040F380, caller:0x004BDB10, caller:0x004E9CA0]

    // Conservative worker pseudocode:
    //   void UIFocusChange(_DWORD *this, int a2, int a3) {
    //     if (a2 == (int)this || !this[120]) return;
    //     dword_8C5F44 = 0;
    //     sub_54B570((int)this, 0, this[129]);
    //     int v4 = this[129];
    //     int v5 = *(_DWORD*)(v4 + 20);
    //     if ((v5 & 0x20000000) == 0) {
    //       *(_DWORD*)(v4 + 20) = v5 | 0x20000000;
    //       (*(void (__cdecl**)(int,int,int,_DWORD*))(*(_DWORD*)dword_8B8F24 + 4))(
    //           dword_8B8F24, v4 + 220, v4 + 232, this + 69);
    //     }
    //     dword_8C5F40 = RenderListIteration(this, a3);
    //     SceneBatchRenderCheck((int)this, a2, a3);
    //   }
    // UNRESOLVED: Packet lists field this+0x218 (RW), but the raw source text shows no direct access to that offset; the skeleton's claim that it is written via dword_8C5F40 from RenderListIteration cannot be confirmed from the raw text
    // UNRESOLVED: Semantics of the busy bit 0x20000000, the D3D wrapper vtable slot +4, and this+69 / this[129]+220 / this[129]+232 arguments are inferred from raw source and skeleton prose only
    // UNRESOLVED: The object holding fields 0x1E0 / 0x204 and the identity of the sub-object at this[129] are not established by the packet
}
