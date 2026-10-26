// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542050
// Canonical corpus name: sub_542050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_542050_00542050.c

void UnknownObject::CameraProjectionSetup()
{
    // Rebuilds a camera/viewport projection state on an unknown camera object. Stores horizontal FOV from a2 at this+0x6C and derives vertical FOV at this+0x70 either from a3 (when a4 is non-zero) or from the aspect-corrected expression (dword_8B8DD8 / dword_8B8DD4) * 1.33334 * a2 * 0.80385852. Computes frustum plane tangents (this+0x1C, this+0x20), clip-plane half extents (this+0x0C, this+0x10) from viewport dimensions at this+0x54/0x58, fills projection sub-matrices at this+0xDC..0xF8, fills a view-rotation matrix at this+0x9C..0xD8 from sin/cos of the half FOVs, writes a far-corner distance at this+0x78, then optionally negates this+0x0C when the flags byte at this+0x80 has bit 0x10 set, and returns that flags byte.
    // ASSIGNMENT: Store the horizontal FOV parameter a2 at this+0x6C. [field:this:0x0000006C, source:raw]
    // GUARD: Branch on parameter a4: when non-zero the vertical FOV is taken directly from a3; otherwise it is computed from the screen-ratio globals. [source:raw]
    // CALCULATION: Compute vertical FOV as (dword_8B8DD8 / dword_8B8DD4) * 1.33334 * a2 * 0.80385852 when a4 is zero. [global:0x008B8DD8, global:0x008B8DD4, source:raw]
    // ASSIGNMENT: Store the resolved vertical FOV (v4) at this+0x70. [field:this:0x00000070, source:raw]
    // ASSIGNMENT: Store tan(a2 * 0.5), the horizontal frustum slope, at this+0x1C. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store tan(v4 * 0.5), the vertical frustum slope, at this+0x20. [field:this:0x00000020, source:raw]
    // CALCULATION: Compute sin and cos of the horizontal half-FOV (v7, v8) and of the vertical half-FOV (v16, v15) for the rotation matrices. [source:raw]
    // ASSIGNMENT: Store the left clip-plane half-width at this+0x0C = (int)(this+0x54) * 0.5 / tan(horizontal half-FOV); reads the viewport width at this+0x54. [field:this:0x0000000C, field:this:0x00000054, source:raw]
    // ASSIGNMENT: Store the top clip-plane half-height at this+0x10 = (int)(this+0x58) * 0.5 / tan(vertical half-FOV); reads the viewport height at this+0x58. [field:this:0x00000010, field:this:0x00000058, source:raw]
    // ASSIGNMENT: Initialize projection-matrix tail: zero this+0xEC and this+0xF0, set this+0xF4 to -1082130432 (i.e. -1.0f), and set this+0xF8 to the negation of the near-plane value at this+0x8. [field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Initialize the matrix tail: zero this+0xDC and this+0xE0, set this+0xE4 to 1065353216 (i.e. 1.0f), and copy the near-plane distance from this+0x4 into this+0xE8. [field:this:0x000000DC, field:this:0x000000E0, field:this:0x000000E4, field:this:0x000000E8, field:this:0x00000004, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0x9C = -cos(half horizontal FOV) and zero this+0xA0. [field:this:0x0000009C, field:this:0x000000A0, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xA4 = sin(half horizontal FOV) and zero this+0xA8. [field:this:0x000000A4, field:this:0x000000A8, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xAC = cos(half horizontal FOV) and zero this+0xB0. [field:this:0x000000AC, field:this:0x000000B0, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xB4 = sin(half horizontal FOV) and zero this+0xB8. [field:this:0x000000B4, field:this:0x000000B8, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xC0 = cos(half vertical FOV) and zero this+0xBC. [field:this:0x000000C0, field:this:0x000000BC, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xC4 = sin(half vertical FOV) and zero this+0xC8. [field:this:0x000000C4, field:this:0x000000C8, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xD0 = -cos(half vertical FOV) and zero this+0xCC. [field:this:0x000000D0, field:this:0x000000CC, source:raw]
    // ASSIGNMENT: View-rotation entry: set this+0xD4 = sin(half vertical FOV) and zero this+0xD8. [field:this:0x000000D4, field:this:0x000000D8, source:raw]
    // CALCULATION: Compute far-plane terms scaled by the near-plane value: h_term = tan(this+0x6C * 0.5) * this+0x8 and v_term = tan(this+0x70 * 0.5) * this+0x8. [field:this:0x0000006C, field:this:0x00000070, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the far-corner distance sqrt(v_term*v_term + h_term*h_term) at this+0x78. [field:this:0x00000078, source:raw]
    // ASSIGNMENT: Read the flags byte at this+0x80 into result. [field:this:0x00000080, source:raw]
    // GUARD: When the flags byte has bit 0x10 set, negate the left clip-plane half-width at this+0x0C (mirrored frustum). [field:this:0x0000000C, source:raw]
    // RETURN: Return the flags byte read from this+0x80. [source:raw]

    // Conservative worker pseudocode:
    //   char CameraProjectionSetup(void *this, float hFov, float vFovIn, int useVovIn) {
    //     *(float *)((char *)this + 0x6C) = hFov;
    //     float vFov = useVovIn ? vFovIn
    //       : ((float)dword_8B8DD8 / (float)dword_8B8DD4) * 1.33334f * hFov * 0.80385852f;
    //     *(float *)((char *)this + 0x70) = vFov;
    //     float tH = tanf(hFov * 0.5f);
    //     float tV = tanf(vFov * 0.5f);
    //     *(float *)((char *)this + 0x1C) = tH;
    //     *(float *)((char *)this + 0x20) = tV;
    //     float sH = sinf(hFov * 0.5f), cH = cosf(hFov * 0.5f);
    //     float sV = sinf(vFov * 0.5f), cV = cosf(vFov * 0.5f);
    //     *(float *)((char *)this + 0x0C) = (float)*(int *)((char *)this + 0x54) * 0.5f / tH;
    //     *(float *)((char *)this + 0x10) = (float)*(int *)((char *)this + 0x58) * 0.5f / tV;
    //     *(int *)((char *)this + 0xEC) = 0; *(int *)((char *)this + 0xF0) = 0;
    //     *(int *)((char *)this + 0xF4) = -1082130432;
    //     *(float *)((char *)this + 0xF8) = -*(float *)((char *)this + 0x08);
    //     *(int *)((char *)this + 0xDC) = 0; *(int *)((char *)this + 0xE0) = 0;
    //     *(int *)((char *)this + 0xE4) = 1065353216;
    //     *(int *)((char *)this + 0xE8) = *(int *)((char *)this + 0x04);
    //     *(float *)((char *)this + 0x9C) = -cH; *(int *)((char *)this + 0xA0) = 0;
    //     *(float *)((char *)this + 0xA4) = sH; *(int *)((char *)this + 0xA8) = 0;
    //     *(float *)((char *)this + 0xAC) = cH; *(int *)((char *)this + 0xB0) = 0;
    //     *(float *)((char *)this + 0xB4) = sH; *(int *)((char *)this + 0xB8) = 0;
    //     *(float *)((char *)this + 0xC0) = cV; *(int *)((char *)this + 0xBC) = 0;
    //     *(float *)((char *)this + 0xC4) = sV; *(int *)((char *)this + 0xC8) = 0;
    //     *(float *)((char *)this + 0xD0) = -cV; *(int *)((char *)this + 0xCC) = 0;
    //     *(float *)((char *)this + 0xD4) = sV; *(int *)((char *)this + 0xD8) = 0;
    //     float hT = tanf(*(float *)((char *)this + 0x6C) * 0.5f) * *(float *)((char *)this + 0x08);
    //     float vT = tanf(*(float *)((char *)this + 0x70) * 0.5f) * *(float *)((char *)this + 0x08);
    //     *(float *)((char *)this + 0x78) = sqrtf(vT * vT + hT * hT);
    //     char flags = *(char *)((char *)this + 0x80);
    //     if (flags & 0x10)
    //       *(float *)((char *)this + 0x0C) = -*(float *)((char *)this + 0x0C);
    //     return flags;
    //   }
    // UNRESOLVED: flt_59E450, flt_5B8978 and flt_5B897C are listed as read globals by the packet but do not appear in the raw decompiled source; Hex-Rays likely folded their values into the FOV computation literals (1.33334, 0.80385852). Their exact consumption site is unresolved.
    // UNRESOLVED: The matrix block layout (which offsets form the projection matrix vs. the view-rotation matrix, and the exact row/column meaning of the entries at 0x9C..0xD8) is DERIVED interpretation, not confirmed.
    // UNRESOLVED: Field 0xF8 is written to the negation of this+0x8 with no further read in this function; its role is unresolved.
    // UNRESOLVED: Field 0x78 far-corner distance formula is inferred; the semantic pairing of the two tan-scaled terms is not confirmed by other evidence.
}
