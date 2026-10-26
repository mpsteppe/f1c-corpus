// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B47E
// Canonical corpus name: DirectXTextureSurfaceBlitWithColorSpaceConversio
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXTextureSurfaceBlitWithColorSpaceConversio_0050b47e.c

void UnknownObject::DirectXTextureSurfaceBlitWithColorSpaceConversion()
{
    // DirectX texture surface blit with color-space conversion. Lazily allocates an intermediate conversion buffer (width*256 bytes, row-count width*16) on first call, updates cached source width/height when the incoming offsets change, blits scanlines through an indirect row-blit callback, copies 16-byte pixels from the conversion buffer to the output surface pointer at this+0x10, and optionally runs a channel-decode pass (scale factors 31.0/63.0/31.0 and 1/31, 1/63) that zeros pixels whose decoded RGBA equals a reference color. Returns a DWORD read from dword_8B009C on the decode path.
    // CALL: SEHHandlerInit() installs structured exception handling before any buffer access [callee:0x0058A5D8, source:raw]
    // ASSIGNMENT: Store the device/surface object pointer into the local slot at *(a1-4); it becomes the owning object v4 for all field reads that follow [source:raw]
    // CALCULATION: Accumulate source position: this+0x8 gains the object field at +4148 and this+0xC gains the object field at +4160 [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: If the object's +4280 field (cached conversion buffer pointer) is zero, run the one-time allocation path [source:raw]
    // CALL: OperatorNewNhMallocWrapper((width) << 8) allocates the intermediate conversion buffer whose size is the object +4260 width times 256 [callee:0x00587C03, source:raw]
    // CALL: sub_5008C2(buffer, 16, 16*width, sub_5007EC) initializes the buffer rows using element size 16 and the sub_5007EC callback [callee:0x005008C2, global:0x005007EC, source:raw]
    // GUARD: If the allocation failed the null pointer is stored at object +4280 and the function returns early; otherwise the buffer pointer is stored there and processing continues [source:raw]
    // CALCULATION: v9 = a1[2] & 0xFFFFFFFC aligns the source width to a 4-pixel boundary for comparison against the cached object +4272 width and +4276 height [source:raw]
    // GUARD: If the aligned width or the height differs from the cached object +4272/+4276, the cached dimensions are updated and the scanline blit loop is re-run [source:raw]
    // CALCULATION: Compute the starting scanline pointer v12 from the object base +24 plus pitch terms: +4180*height, +4224*(width>>2) and +4176*(aligned_width>>2) [source:raw]
    // LOOP: While the row index v10 (starting at object +4236) is below the object +4244 row count: call the indirect row-blit function at object +4228(dest_row, src_row), then advance v12 by the pitch at +4224, v11 by 256 bytes and v10 by 4 [source:raw]
    // CALCULATION: result = object +4144 - object +4236; v13 = (a1[2] - object +4240) & 3; v14 = result + object +4184 bounds the copy loop [source:raw]
    // LOOP: Copy 16 bytes per pixel from the conversion buffer (address computed with a 4x4 swizzle over result and v13) into the output pixels at this+0x10; the output pointer advances 16 bytes per iteration [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004, field:*(this+0x10):0x00000008, field:*(this+0x10):0x0000000C, field:this:0x00000010, source:raw]
    // GUARD: If the object +16 flag is non-zero the color-space conversion pass runs after the copy [source:raw]
    // CALL: UtilityFunction_7473() runs before the per-pixel decode loop [callee:0x00507473, source:raw]
    // LOOP: While the output pointer at this+0x10 is below the end bound v17: decode the pixel channels read from this+0x10 with scale factors 31.0 (R), 63.0 (G), 31.0 (B) and 1/31, 1/63, 1/31 scaling for the byte-to-channel conversion [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004, field:*(this+0x10):0x00000008, field:*(this+0x10):0x0000000C, field:this:0x00000010, source:raw]
    // GUARD: If the decoded RGBA matches the reference color (object +4204 alpha scale folded in), the pixel at this+0x10 is cleared to four zero DWORDs [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004, field:*(this+0x10):0x00000008, field:*(this+0x10):0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: result is set to dword_8B009C and stored into the local slot at *(a1-9) [global:0x008B009C, source:raw]
    // RETURN: Return the unsigned int result; on the color-space path it is dword_8B009C, otherwise the copy-loop remainder [function:0x0050B47E, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   thisObj = *(a1-4);
    //   this[0x8/4] += thisObj[+4148/4];
    //   this[0xC/4] += thisObj[+4160/4];
    //   if (thisObj[+4280/4] == 0) {
    //     buf = OperatorNewNhMallocWrapper(thisObj[+4260/4] << 8);
    //     if (buf) sub_5008C2(buf, 16, 16*thisObj[+4260/4], sub_5007EC); else buf = 0;
    //     thisObj[+4280/4] = buf;
    //     if (!buf) return result;
    //   }
    //   alignedW = this[0x8/4] & 0xFFFFFFFC;
    //   if (alignedW != thisObj[+4272/4] || this[0xC/4] != thisObj[+4276/4]) {
    //     thisObj[+4272/4] = alignedW;
    //     thisObj[+4276/4] = this[0xC/4];
    //     row = base + pitch*height + pitch*(width>>2) + ...;
    //     for (idx = thisObj[+4236/4]; idx < thisObj[+4244/4]; idx += 4) {
    //       (fn at thisObj[+4228/4])(destRow, row); row += thisObj[+4224/4]; destRow += 256;
    //     }
    //   }
    //   for (result = thisObj[+4144/4]-thisObj[+4236/4]; result < result + thisObj[+4184/4]; ++result) {
    //     copy 16 bytes swizzled from conversion buffer into *(this+0x10); *(this+0x10) += 16;
    //   }
    //   if (thisObj[+16/4]) {
    //     UtilityFunction_7473();
    //     while (*(this+0x10) < end) {
    //       decode R,G,B,A from *(this+0x10) via 31.0/63.0/31.0 and 1/31, 1/63;
    //       if (decoded == reference color) { write four zero DWORDs to *(this+0x10); }
    //       *(this+0x10) += 16;
    //     }
    //     result = dword_8B009C; *(a1-9) = dword_8B009C;
    //   }
    //   return result;
    // UNRESOLVED: Six packet globals (loc_59C58C, flt_59E450, flt_5ACCD0, flt_5ACCD4, flt_5ACCD8, flt_5ACCDC) appear nowhere in the raw decompiled source text; they are likely used at disassembly level (channel-decode tables or floating constants) and cannot be verified from this packet
    // UNRESOLVED: The device/surface object offsets (+4148, +4160, +4260, +4272, +4276, +4224, +4228, +4244, +4236, +4240, +4144, +4184, +16, +4204, +1052) are the bulk of the function's state but are not exposed as packet field evidence, so they are described only in prose
}
