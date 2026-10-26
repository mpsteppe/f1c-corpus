// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053FD40
// Canonical corpus name: DirectXDeviceSurfaceCreationWithFormatCapability
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXDeviceSurfaceCreationWithFormatCapability_0053fd40.c

void UnknownObject::DirectXDeviceSurfaceCreationWithFormatCapability()
{
    // DirectX surface blit with format-aware source/destination selection. Prepares a format buffer via sub_55C650, initializes the destination surface via sub_53F720, picks source and destination surfaces from the a2/a4 descriptor arrays using the a3/a5 flag bitmasks (1, 2, 4, 8), blits through SurfaceBlitOperation with a fill color derived from a4[6], releases temporary surfaces through their vtable+8, and optionally copies via D3DSurfaceCopyBlit when a4[11] > 1. Stops at the first failure storing -1 in *this. Returns 0 on success, and skips the whole pipeline when a6 & 0x1000000 is set. Called by sub_5429B0 (0x005429B0).
    // CALL: Initialize the format buffer v19 via sub_55C650(v19, a2[12], 0). [callee:0x0055C650, source:raw]
    // CALCULATION: Compute the fill color v9 from dst descriptor a4[6]: -16777216 when bit 0x800 is set, else -65281. [source:raw]
    // CALL: Prepare/allocate the destination surface via sub_53F720(this, a4, a4[11]); on a non-zero return store it in *this and return -1. [callee:0x0053F720, field:this:0x00000000, source:raw]
    // GUARD: If a6 & 0x1000000 is set, skip the entire blit pipeline and return 0 immediately. [source:raw]
    // GUARD: Select the source surface from the a2 descriptor using a3 flags: bit 4 -> a2[4], bit 8 -> a2[5], bit 1 -> a2[2], bit 2 -> a2[3]; if no flag matches or the chosen surface is null, return -1. [source:raw]
    // CALL: For a3 bits 4 or 8, call the selected surface's vtable method at vtable+60 with (surface, 0, &a2), storing the result in *this and returning -1 on failure. [field:this:0x00000000, source:raw]
    // GUARD: Select the destination surface from the a4 descriptor using a5 flags with the same 1/2/4/8 bit scheme; return -1 if no flag matches or the chosen surface is null. [source:raw]
    // CALL: For a5 bits 4 or 8, call the destination surface's vtable method at vtable+60 with (surface, 0, &v18), storing the result in *this and returning -1 on failure. [field:this:0x00000000, source:raw]
    // CALL: Blit the selected surfaces via SurfaceBlitOperation(v18, 0, 0, a2, 0, 0, 4, v9); store the result in *this and return -1 on failure. [callee:0x0050099C, field:this:0x00000000, source:raw]
    // CALL: If a3 & 0xC, release the temporary source surface via its vtable+8 method. [source:raw]
    // CALL: If a5 & 0xC, release the temporary destination surface via its vtable+8 method. [source:raw]
    // CALL: If a4[11] > 1, copy the surface data via D3DSurfaceCopyBlit(a4[4], 0, 0xFFFFFFFF, 5). [callee:0x00500BC8, source:raw]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53FD40(int *this, int *a2, char a3, int *a4, char a5, int a6) {
    //     _BYTE fmt[4];
    //     sub_55C650(fmt, a2[12], 0);
    //     int fill = (a4[6] & 0x800) ? -16777216 : -65281;
    //     if (sub_53F720((int)this, a4, a4[11])) return -1;
    //     if (!(a6 & 0x1000000)) {
    //       int *src;
    //       if ((a3 & 4) && (src = (int*)a2[4]) || (a3 & 8) && (src = (int*)a2[5])) {
    //         int r = (*(int(**)(int,int,int*))(*(int*)src + 60))(src, 0, (int*)&a2);
    //         *this = r; if (r) return -1;
    //       } else if ((a3 & 1) && a2[2]) {
    //         a2 = (int*)a2[2];
    //       } else {
    //         if (!(a3 & 2)) return -1;
    //         if (!a2[3]) return -1;
    //         a2 = (int*)a2[3];
    //       }
    //       int dst;
    //       if ((a5 & 4) && (dst = a4[4]) || (a5 & 8) && (dst = a4[5])) {
    //         int r = (*(int(**)(int,int,int*))(*(int*)dst + 60))(dst, 0, &dst);
    //         *this = r; if (r) return -1;
    //       } else {
    //         if (!(a5 & 1) || !(dst = a4[2])) {
    //           if (!(a5 & 2)) return -1;
    //           dst = a4[3]; if (!dst) return -1;
    //         }
    //       }
    //       int r = SurfaceBlitOperation(dst, 0, 0, (int)a2, 0, 0, 4, fill);
    //       *this = r; if (r) return -1;
    //       if (a3 & 0xC) (*(void(**)(int*))(*a2 + 8))(a2);
    //       if (a5 & 0xC) (*(void(**)(int))(*(int*)dst + 8))(dst);
    //       if (a4[11] > 1) D3DSurfaceCopyBlit(a4[4], 0, 0xFFFFFFFF, 5);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the a3/a5 flag bits (1, 2, 4, 8) and of the a2/a4 descriptor arrays are caller-defined and unproven here.
    // UNRESOLVED: The vtable method at +60 and the release method at +8 belong to an unknown DirectDraw/D3D surface interface; identity not confirmed.
    // UNRESOLVED: Exact role of sub_53F720 and the meaning of the a6 & 0x1000000 skip flag are outside this function.
    // UNRESOLVED: The constants -16777216 and -65281 are kept in the packet's decimal spelling; their color meaning is not proven by this packet.
}
