// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F0D20
// Canonical corpus name: sub_4F0D20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F0D20_004f0d20.c

void UnknownObject::TeamColorScaleApply()
{
    // Rendering/appearance helper that applies a team-color scale to an object. Defaults the scale to 1.0. If the object's team-color identifier (this+0x4) differs from the current player's vehicle field at offset +18580 (vehicle pointer array dword_7C54F0 indexed by current player index dword_7C54DC), it issues a guarded render call on the render-object pointer at this+0x0 and runs a 3D matrix transform; a condition-flag result of that transform selects the renderer team-color scale at dword_7CF83C. Finally propagates the chosen scale to the downstream element at this+441 via ScalePropagate. Per-frame path.
    // ASSIGNMENT: v5 = 1.0: initialize the team color scale to the neutral value before the guard. [function:0x004F0D20, source:raw]
    // GUARD: If the team color identifier at this+0x4 differs from the value read at (dword_7C54F0[dword_7C54DC] + 18580), i.e. the corresponding field of the current player's vehicle, take the render/transform path. [field:this:0x00000004, global:0x007C54DC, global:0x007C54F0, function:0x004F0D20, source:raw]
    // CALL: RenderCallWithGuard(*(_DWORD**)this, &v6, v8): issue a guarded render operation using the render-object pointer stored at this+0x0. [callee:0x004D1140, field:this:0x00000000, function:0x004F0D20, source:raw]
    // CALL: F_3DTransformWithMatrixMultiplication(this, &v7, v9): apply a 3D matrix transform to the object; the carry flags c0/c2 (captured as v3/v4) produced by this call are consumed by the following guard. [callee:0x004EFB20, function:0x004F0D20, source:raw]
    // GUARD: If (v3 | v4) (the c0/c2 condition flags from the transform call) is set, select v5 = the renderer team-color scale stored at dword_7CF83C. [global:0x007CF83C, function:0x004F0D20, source:raw]
    // CALL: ScalePropagate((int)(this + 441), v5): propagate the chosen team color scale to the downstream element located at this+441. [callee:0x004E2CA0, function:0x004F0D20, source:raw]

    // Conservative worker pseudocode:
    //   float scale = 1.0f;
    //   if (teamColorId(this+0x4) != vehicle(ptrArray7C54F0[currentPlayer7C54DC]).field_at_18580) {
    //     RenderCallWithGuard(*(this), &v6, v8);
    //     F_3DTransformWithMatrixMultiplication(this, &v7, v9);
    //     if (flags) scale = teamColorScale7CF83C;
    //   }
    //   ScalePropagate(this + 441, scale);
    // UNRESOLVED: v3/v4 are unsigned byte captures of the c0/c2 CPU condition flags read after F_3DTransformWithMatrixMultiplication; Hex-Rays misrenders them as ordinary variables, so the exact meaning of the (v3 | v4) selection of dword_7CF83C is not confirmed.
    // UNRESOLVED: flt_59E46C (0x0059E46C) and dword_8ACEE0 (0x008ACEE0) are listed by IDB facts as read by this function but do not appear in the raw source; their role is unconfirmed.
    // UNRESOLVED: The object type behind `this` (render/team-color object) and the semantic of the compared field at vehicle offset +18580 are not confirmed beyond the team-color reading.
    // UNRESOLVED: The packet ABI lead name Camera_FOV_Zoom_by_Proximity (LEGACY) conflicts with the observed team-color render/scale behavior and is not treated as evidence.
}
