// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00506971
// Canonical corpus name: sub_506971
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_506971_00506971.c

void UnknownObject::SurfaceLockBoxCopy()
{
    // Locks a 3D sub-region (lock box) of a Direct3D surface and copies the resulting surface information into the a2 descriptor. Releases any existing interface stored at *this, queries the surface description via vtable slot +32, validates and block-aligns a supplied 3D rect (format-dependent rounding), queries render-state capability support via vtable slot +28 around sub_500EAC toggles, calls vtable slot +36 (LockBox) with mode flags, fills the descriptor (pitch, FourCC, dimensions, depth, rect copy, a6, a4), and stores the surface pointer a3 at *this.
    // GUARD: If *this is non-null, release the stored COM interface via VTableReleaseClear before the new surface pointer is stored. [guard:0, callee:0x0050653E]
    // CALL: Query the surface description from a3's vtable slot +32 into v18; the FourCC at v18 drives later rect-alignment decisions. [source:raw, function:0x00506971]
    // GUARD: When a5 (requested rect) is provided, validate the 6-dword rect against surface size: reject with error -2005530516 if x2>width, x0>x2, y2>height, y1>y2, z2>depth or z0>z2. [source:raw]
    // ASSIGNMENT: Determine whether a rect conversion is needed: when a5 is null, build a full-surface rect from v21/v22/v23, clear the conversion flag and set v9 from the a7 bit 0 test. [source:raw]
    // GUARD: Reject with error -2005530516 when the render capability flag v20 is clear and the capability word v19 lacks bit 0x200. [source:raw]
    // CALCULATION: Compute the lock mode flags from a7: base v11 = 16 * ((a7 & 1) | 0x80); optionally OR 0x2000 when a7 has bit 0x20000 set or the capability query reports support. [source:raw]
    // CALL: Toggle rendering state via sub_500EAC(1) then sub_500EAC(0) around a capability query on a3 vtable slot +28 using unk_5AD4B0. [callee:0x00500EAC, global:0x005AD4B0]
    // CALCULATION: Round the requested rect to the format block size according to the FourCC at v18: 2-pixel x/y alignment for the 844715353 and 1498831189 paths, 4-pixel x/y alignment for 827611204 / 844388420 / 861165636 / 877942852 / 894720068; clamp to surface bounds. [source:raw]
    // CALL: Call a3 vtable slot +36 (LockBox) with the aligned rect and computed flags; propagate a negative HRESULT result. [source:raw]
    // ASSIGNMENT: Fill the a2 descriptor: pitch/pointers from v26, FourCC v18, width/height from v26, depth v23, a 0x18-byte copy of the rect, a6, a4, set a2[16]=1, and store the surface pointer a3 at *this. [field:this:0x00000000]
    // RETURN: Return 0 on success, otherwise the HRESULT returned by the LockBox call. [source:raw, function:0x00506971]

    // Conservative worker pseudocode:
    //   if (*this) VTableReleaseClear(this);
    //   vtable(a3, 32)(a3, &formatInfo);
    //   if (a5) {
    //     copy 6-dword rect from a5; validate x/y/z bounds else return E_FAIL;
    //   } else {
    //     rect = full surface; conversionNeeded = false;
    //   }
    //   if (!v20 && !(v19 & 0x200)) return E_FAIL;
    //   flags = 16 * ((a7 & 1) | 0x80);
    //   if (convertOk && (v19 & 0x200)) {
    //     if (a7 & 0x20000) flags |= 0x2000;
    //     else { sub_500EAC(1); query vtable+28 with unk_5AD4B0; if supported flags |= 0x2000; sub_500EAC(0); }
    //   }
    //   align rect to format block size; clamp to surface;
    //   hr = vtable(a3, 36)(a3, &lockResult, rectOrNull, flags);
    //   if (hr < 0) return hr;
    //   fill a2 descriptor;
    //   *this = a3;
    //   return 0;
    // UNRESOLVED: Indirect vtable calls (slots +28/+32/+36, plus +8/+52 on the queried capability object) have no static targets and are not present in the evidence packet.
    // UNRESOLVED: The exact meaning of the mode-flag bits (0x80, 0x2000, 0x20000) and the FourCC constants is inferred from context only.
    // UNRESOLVED: The a2 descriptor layout (0x18-byte rect copy at a2+10, a2[16]=1 marker) is derived from the fill order, not confirmed.
    // UNRESOLVED: unk_5AD4B0 is described by prior analysis as a GPUBufferDescriptor; its exact type is not confirmed.
    // UNRESOLVED: a2, a4 and a6 roles are only partially described.
}
