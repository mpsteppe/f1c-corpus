// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050099C
// Canonical corpus name: SurfaceBlitOperation
// Owner: D3DSurface [DERIVED]
// Raw source: functions/SurfaceBlitOperation_0050099c.c

void D3DSurface::blitSurface()
{
    // D3D surface blit between a source and a destination surface. Validates both surfaces are non-null, then when no color-key is active and the two surfaces are identical (same pointer, or equal payloads over 0x400 bytes) attempts a hardware blit path: builds the source/destination rectangles (from caller-provided 4-int rects or by querying each surface's descriptor via its vtable entry at offset 32), toggles a lock-state counter with sub_500EAC(1)/sub_500EAC(0), invokes destination vtable blit entries, and on failure falls back to a CPU-side lock-copy via D3DTextureSurfaceLockCopy and NetworkPacketSendReceive. Releases temporary render resources via j_RenderResourceTeardown before returning.
    // CALL: Calls ZeroInit4Ints_64bf on a temporary render-resource struct to initialize it before the blit. [callee:0x005064BF, source:raw]
    // GUARD: If the source surface (a1) is null, skips the whole blit and reports an invalid-call error. [field:this:0x00000000, source:raw]
    // GUARD: If the destination surface (a4) is null, skips the whole blit and reports an invalid-call error. [field:obj:0x00000020, source:raw]
    // GUARD: Enter the direct-blit path only when no color key applies (a7 != 5 and a8 false) and the source and destination payloads are the same surface or byte-identical over 0x400 bytes (memcmp). [source:raw]
    // CALCULATION: Builds the source rectangle: copies the caller's 4-int rect from a3 when supplied; otherwise queries the source surface descriptor through its vtable entry at offset 32 and derives the rectangle (origin 0,0) from fields v20/v21. [field:this:0x00000000, field:obj:0x00000020, source:raw]
    // CALCULATION: Builds the destination rectangle: copies the caller's 4-int rect from a6 when supplied; otherwise queries the destination surface descriptor through its vtable entry at offset 32 and derives the rectangle (origin 0,0) from fields v20/v21. [field:this:0x00000000, field:obj:0x00000020, source:raw]
    // GUARD: Proceeds with the hardware blit only when the source and destination rectangles have matching dimensions (equal widths v10-v27 == v12-v23 and equal heights v30-v28 == v11-v24). [source:raw]
    // CALL: Invokes destination vtable entry at offset 12 with the rectangle, toggles the lock-state counter with sub_500EAC(1), performs the blit, toggles the counter back with sub_500EAC(0), and releases the destination lock via its vtable. [field:obj:0x00000020, callee:0x00500EAC, source:raw]
    // CALL: When the hardware blit path is skipped or fails, calls D3DTextureSurfaceLockCopy to lock the source and copy pixel data, using the 65537 lock flag when blitting a surface onto itself and 1 otherwise. [callee:0x00506559, source:raw]
    // CALL: Calls NetworkPacketSendReceive to perform the CPU-side source-to-destination surface data transfer after the lock-copy, passing the lock descriptors and color-key parameters. [callee:0x0050070D, source:raw]
    // CALL: Calls j_RenderResourceTeardown on the temporary render-resource struct to release resources before returning. [callee:0x00506554, source:raw]
    // RETURN: Returns the blit result (0 on success, otherwise the propagated error, including the invalid-call error). [function:0x0050099C, source:raw]

    // Conservative worker pseudocode:
    //   ZeroInit4Ints_64bf(&renderResources);
    //   if (srcSurface == 0 || dstSurface == 0)
    //       result = -2005530516; // D3DERR_INVALIDCALL
    //   else {
    //       if (a7 != 5 && !a8 && (a2 == a5 || (a2 && a5 && memcmp(a2, a5, 0x400) == 0))) {
    //           buildSrcRect(); // from a3 or surface desc vtable entry +32
    //           buildDstRect(); // from a6 or surface desc vtable entry +32
    //           if (srcRect.w == dstRect.w && srcRect.h == dstRect.h) {
    //               dstVtable[+12](dstSurface, &rect);
    //               sub_500EAC(1);
    //               status = blit(dstSurface, &dstRect, srcSurface, &srcRect);
    //               sub_500EAC(0);
    //               unlock(dstSurface);
    //               if (status >= 0) result = 0; else result = status;
    //           }
    //       }
    //       if (status < 0) {
    //           flag = (srcSurface == dstSurface) ? 65537 : 1;
    //           status = D3DTextureSurfaceLockCopy(&lock, dstSurface, a5, a6, 0, flag);
    //           if (status >= 0)
    //               status = NetworkPacketSendReceive(srcSurface, a2, a3, lockDesc, a5, a7, a8);
    //           result = (status >= 0) ? 0 : status;
    //       }
    //   }
    //   j_RenderResourceTeardown(&renderResources);
    //   return result;
    // UNRESOLVED: The exact meaning of arguments a7/a8 (color-key parameters) and a2/a5 payload pointers is not evidenced beyond the raw source usage; a7==5 suppresses the direct path.
    // UNRESOLVED: The destination vtable blit/unlock entry offsets after the +32 descriptor query are present only in the untruncated source; this IR does not assert their numeric offsets.
    // UNRESOLVED: Owner type D3DSurface is DERIVED from the vtable-dispatch shape and the surface-blit ABI lead; the exact wrapper class is not evidenced.
    // UNRESOLVED: Whether the direct hardware path and the CPU fallback produce identical output for all surface formats is not determined here.
}
