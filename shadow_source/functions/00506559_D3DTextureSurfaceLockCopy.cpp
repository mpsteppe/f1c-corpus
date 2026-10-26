// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00506559
// Canonical corpus name: D3DTextureSurfaceLockCopy
// Owner: D3DTextureSurfaceCopier [DERIVED]
// Raw source: functions/D3DTextureSurfaceLockCopy_00506559.c

void D3DTextureSurfaceCopier::D3DTextureSurfaceLockCopy()
{
    // D3D surface copy helper: tears down existing render resources, queries the input surface (a3) description, validates the optional source rect (a5) against the surface dimensions, optionally probes hardware capability via GetDesc, creates a compatible surface sized to the source, copies pixel data (CopyRects) or locks the destination surface rect (LockRect) with per-format (compressed vs. plain) alignment, and fills the output descriptor a2 with pitch, format, dimensions, rect and ownership fields. this+0x8 holds the destination surface, this+0xC the source surface, this+0x0 the control flags (a7) and this+0x4 the input surface pointer (a3). Returns 0 on success or a D3D error code.
    // CALL: RenderResourceTeardown(this) releases existing render resources owned by the copier before re-locking. [callee:0x005064CF, source:raw]
    // CALL: Dispatch the vtable+32 method on the input surface a3, which fills the description locals (v25 format and v26..v29 dimensions). [source:raw]
    // GUARD: When a5 is provided, copy the four rect coordinates and validate them against the surface dimensions v28/v29; an out-of-range rect returns a fixed D3D error code. [source:raw]
    // CALCULATION: Derive control flags: v43 = (a7 & 1) == 0 and no partial rect; v45 marks a partial rect; the rect defaults to the full surface when a5 is null. [source:raw]
    // GUARD: Capability gate: when a7 bit 0x10000 is clear, run sub_500EAC(1), then GetDesc (vtable+28) on a3 with the unk_5AD4D0 descriptor buffer to decide whether the lock-copy path is supported; fall back to reading a3[4] format bits when GetDesc fails, then sub_500EAC(0). [global:0x005AD4D0, callee:0x00500EAC, source:raw]
    // CALCULATION: Compressed-format alignment: when the format code v25 belongs to the DXT-style compressed family, round width and height up to a 4-byte boundary ((dims+3) & ~3); otherwise keep them as-is. [source:raw]
    // CALL: Create a compatible surface: dispatch the vtable+108 method on the source surface (pointer at this+0xC, vtable at *(this+0xC)+0x0) with the aligned dimensions, format and a result slot at this+0x8; a negative HRESULT aborts. [field:this:0x0000000C, field:*(this+0xC):0x00000000, field:*(*(this+0xC)+0x0):0x0000006C, source:raw]
    // CALL: Optional CopyRects: when the fast path is not selected, dispatch the vtable+112 method on the source surface (this+0xC) to copy into the compatible surface. [field:*(this+0xC):0x00000000, field:*(*(this+0xC)+0x0):0x00000070, source:raw]
    // CALL: Hardware support probe: when the fast path is active, run sub_500EAC(1), GetDesc (vtable+28) on a3 with the unk_5AD4C0 descriptor buffer, and if the queried support check reports true OR the 0x2000 flag into the LockRect flags; release the descriptor and run sub_500EAC(0). [global:0x005AD4C0, callee:0x00500EAC, source:raw]
    // CALCULATION: Per-format rect alignment before locking: DXT-family formats align the rect coordinates to 4 bytes, the odd-aligned format family to 2 bytes, otherwise the rect is used as-is, clamping against the surface dimensions. [source:raw]
    // CALL: LockRect on the destination surface: dispatch the vtable+36 method (field *(*(this+0x8)+0x0)+0x24) on the destination surface pointer (this+0x8, vtable at *(this+0x8)+0x0) with the aligned source rect and computed flags; a negative HRESULT propagates. [field:this:0x00000008, field:*(this+0x8):0x00000000, field:*(*(this+0x8)+0x0):0x00000024, source:raw]
    // ASSIGNMENT: Fill the output descriptor a2: zero sentinel slots, store pitch, format, dimensions, the four rect coordinates, the extra a4/a6 values, and set the 1-valued marker fields. [source:raw]
    // ASSIGNMENT: Persist state on the copier: store the input surface pointer a3 into this+0x4 and the control flags a7 into this+0x0. [field:this:0x00000004, field:this:0x00000000, source:raw]
    // RETURN: Return 0 on success; propagate any negative HRESULT from the surface vtable calls. [function:0x00506559, source:raw]
    // CALL: Invoked by NetworkPacketSendReceive (0050070d) and SurfaceBlitOperation (0050099c) to lock and copy texture surface data. [caller:0x0050070D, caller:0x0050099C, source:raw]

    // Conservative worker pseudocode:
    //   RenderResourceTeardown(this);
    //   format = a3->vtable[8](a3, &desc);  /* vtable+32, fills format + dims * /
    //   if (a5) { copy rect; if (rect out of surface bounds) return D3DERR; }
    //   fast = (a7 & 1) == 0 && !partial_rect;
    //   if ((a7 & 0x10000) == 0) {
    //     sub_500EAC(1);
    //     if (a3->GetDesc(a3, &unk_5AD4D0, &desc) < 0) v44 = ((a3[4] >> 26) & 1) == 0;
    //     else { v44 = 1; release desc; }
    //     sub_500EAC(0);
    //     if (!v44) { v41 = a3; goto fill_descriptor; }
    //   }
    //   if (is_dxt_format(format)) { w = align4(w); h = align4(h); }
    //   src = this->src_0xC;
    //   this->dest_0x8 = CreateCompatibleSurface(src, w, h, format); /* vtable+108 * /
    //   if (this->dest_0x8 < 0) return hr;
    //   if (!fast && CopyRects(src, a3, 0, 0, this->dest_0x8, 0) < 0) return hr;
    //   lock_flags = 16 * (a7 & 1 | 0x80);
    //   if (fast && !v44 && (v26 & 0x200) != 0) {
    //     sub_500EAC(1);
    //     if (a3->GetDesc(a3, &unk_5AD4C0, &desc) >= 0) {
    //       if (desc_support_check(desc) == 1) { lock_flags |= 0x2000; partial = 0; }
    //       release desc;
    //     }
    //     sub_500EAC(0);
    //   }
    //   if (partial) {
    //     align rect per format (4-byte DXT, 2-byte odd, else plain); clamp to surface;
    //     if (LockRect(this->dest_0x8, &rect_desc, &rect, lock_flags) < 0) return hr; /* vtable+36 * /
    //   } else {
    //     if (LockRect(this->dest_0x8, &rect_desc, 0, lock_flags) < 0) return hr;
    //   }
    //   fill_descriptor:
    //   a2->pitch = pitch; a2->format = format; a2->w = v28; a2->h = v29;
    //   a2->rect = (v34, v35, v36, v37); a2->extra1 = a6; a2->extra2 = a4;
    //   this->ptr_0x4 = a3; this->flags_0x0 = a7;
    //   return 0;
    // UNRESOLVED: the exact surface vtable method identities at offsets 32, 28, 12, 36, 108 and 112 (GetDesc, CreateCompatibleSurface, CopyRects, LockRect) are inferred from the packet's field names and call-site shape, not independently confirmed
    // UNRESOLVED: the semantic meaning of the unk_5AD4C0 / unk_5AD4D0 descriptor buffers and of a3[4] bit 26 is not established
    // UNRESOLVED: the exact set of DXT/odd-aligned format codes is present in the raw body but their D3DFMT identities are not resolved here
    // UNRESOLVED: the purpose of the sub_500EAC(1)/sub_500EAC(0) pairing (likely a global lock/unlock guard) is DERIVED from call-site placement only
    // UNRESOLVED: field:this:0x00000000 and field:this:0x00000004 are write-once stores (a7, a3); external pokes do not survive per existing_analysis
}
