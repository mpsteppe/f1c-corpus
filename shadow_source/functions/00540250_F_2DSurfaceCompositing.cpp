// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540250
// Canonical corpus name: F_2DSurfaceCompositing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DSurfaceCompositing_00540250.c

void UnknownObject::F_2DSurfaceCompositing()
{
    // 2D surface compositing with an optional clipped path. Selects a source surface and a destination surface from two descriptor arrays a2 and a5 using per-descriptor flag bitmasks at index 6 (bits 1 and 2 give direct pointer candidates; bits 4 and 8 give surfaces obtained through a vtable+60 acquire call). Any acquire or blit failure is stored to *this and returns -1. When clipping is required (a10 == -2 or a2[12] > 8 or a5[12] > 8), the clip rect is applied through the sub-object at this+0x1100 via its vtable slot +0x70; otherwise a direct blit path runs two vtable+36 calls, an AudioPlaybackDispatcher notification, and vtable+40 releases of the temporary surfaces. Clears bit 0x400 of a5[6] and returns 0 on success.
    // ASSIGNMENT: Initialize clip mode v12 = (a10 == -2); force v12 = 1 when a2[12] > 8 or a5[12] > 8. [source:raw]
    // GUARD: Source surface selection: if a2[6] bit 1 set use a2[2], else if bit 2 set use a2[3]; stored via v26. [source:raw]
    // GUARD: Source fallback selection: if a2[6] bit 4 set use a2[4], else if bit 8 set use a2[5]; stored via v27. [source:raw]
    // CALL: When the fallback source pointer v15 is non-null, acquire the surface via its vtable+60 call into v26, store the result to *this, and return -1 on failure. [field:this:0x00000000, source:raw]
    // GUARD: Destination surface selection: if a5[6] bit 1 set use a5[2], else if bit 2 set use a5[3]; stored via v25. [source:raw]
    // GUARD: Destination fallback selection: if a5[6] bit 4 set use a5[4], else if bit 8 set use a5[5]; stored via v28. [source:raw]
    // CALL: When the fallback destination pointer v28 is non-null, acquire the surface via its vtable+60 call into v25, store the result to *this, and return -1 on failure. [field:this:0x00000000, source:raw]
    // GUARD: Branch on clip mode v12 to select the clipped vs direct compositing path. [source:raw]
    // CALCULATION: Clipped path: build the clip rectangle v31..v34 from a3, a4, a8+a3 and a9+a4. [source:raw]
    // CALL: Clipped path: read the sub-object pointer from this+0x1100 and call its vtable slot +0x70 with (v10, &v31, 1, v25, &v29); store the result to *this and return -1 on failure. [field:this:0x00001100, field:*(this+0x1100):0x00000070, source:raw]
    // CALCULATION: Direct path: build the source rectangle v35 = (a3, a4, a8+a3, a9+a4). [source:raw]
    // CALL: Direct path: call vtable+36 on the source surface v10 with rectangle v35; store the result to *this and return -1 on failure. [field:this:0x00000000, source:raw]
    // CALCULATION: Direct path: build the destination rectangle v36 = (a6, a7, a8+a6, a9+a7). [source:raw]
    // CALL: Direct path: call vtable+36 on the destination surface v25 with rectangle v36; store the result to *this and return -1 on failure. [field:this:0x00000000, source:raw]
    // CALL: Direct path: notify AudioPlaybackDispatcher(v32, v31, v30, v29, a8, a9, a10, a2[12]). [callee:0x005401A0, source:raw]
    // CALL: Direct path: release the temporary surfaces v26 and v25 via their vtable+40 calls. [source:raw]
    // ASSIGNMENT: If the fallback source v27 was used, store the vtable+8 call result on v26 into *this; if the fallback destination v28 was used, store the vtable+8 call result on v25 into *this. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Clear bit 0x400 of the destination descriptor flags a5[6] to mark the operation consumed. [source:raw]
    // RETURN: Return 0 on success; every vtable failure path returns -1 after storing the error to *this. [source:raw, caller:0x00543250, caller:0x005432F0]

    // Conservative worker pseudocode:
    //   int F_2DSurfaceCompositing(this, a2, a3, a4, a5, a6, a7, a8, a9, a10) {
    //     int clipped = (a10 == -2);
    //     if (a2[12] > 8 || a5[12] > 8) clipped = 1;
    //     int v26 = 0, v27 = 0, v25 = 0, v28 = 0;
    //     if (a2[6] & 1) v26 = a2[2];
    //     else if (a2[6] & 2) v26 = a2[3];
    //     else if (a2[6] & 4) { v27 = a2[4]; }
    //     else if (a2[6] & 8) { v27 = a2[5]; }
    //     if (v27) { if (acquire(v27, &v26)) return -1; }
    //     if (a5[6] & 1) v25 = a5[2];
    //     else if (a5[6] & 2) v25 = a5[3];
    //     else if (a5[6] & 4) { v28 = a5[4]; }
    //     else if (a5[6] & 8) { v28 = a5[5]; }
    //     if (v28) { if (acquire(v28, &v25)) return -1; }
    //     if (clipped) {
    //       int r[4] = { a3, a4, a8 + a3, a9 + a4 };
    //       if (call(this[1088], vtable+0x70, v26, &r, 1, v25, &a6)) return -1;
    //     } else {
    //       int src[4] = { a3, a4, a8 + a3, a9 + a4 };
    //       if (call(v26, vtable+36, &r, src, 16)) return -1;
    //       int dst[4] = { a6, a7, a8 + a6, a9 + a7 };
    //       if (call(v25, vtable+36, &d, dst, 0)) return -1;
    //       AudioPlaybackDispatcher(a4, a3, a7, a6, a8, a9, a10, a2[12]);
    //       call(v26, vtable+40); call(v25, vtable+40);
    //     }
    //     if (v27) *this = call(v26, vtable+8);
    //     if (v28) *this = call(v25, vtable+8);
    //     a5[6] &= ~0x400;
    //     return 0;
    //   }
    // UNRESOLVED: The vtable slots (vtable+60 acquire, +36 blit, +40 release, +8 result query, +0x70 clipped blit) are interface contracts on caller-supplied surfaces and cannot be named here.
    // UNRESOLVED: Semantics of a2[12] and a5[12] depth thresholds (> 8) are external to this function.
    // UNRESOLVED: Exactly how a2[12] is used by AudioPlaybackDispatcher is caller/interface-specific.
}
