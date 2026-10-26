// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005432F0
// Canonical corpus name: ClippedRectRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClippedRectRender_005432f0.c

void UnknownObject::ClippedRectRender()
{
    // Renders a clipped 2D rectangle surface. When a10 >= 0 it derives the rectangle from the object's this+0x1C/this+0x20 dimensions scaled by a7/a8; otherwise it uses the raw float parameters directly. Coordinates are converted to integers via CRTFtol, negative offsets are folded back, the two corner pairs are normalized by sub_543540, and F_2DSurfaceCompositing composites the surface against the dword_8B78A0 target when the clipped width and height are positive, clearing the 0x400 flag on the target surface afterwards.
    // GUARD: Branch on a10 >= 0: scaled path uses this+0x1C/this+0x20 dimensions scaled by a7/a8; else direct path uses raw float parameters. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: CRTFtol converts float coordinates and dimensions to integers on both paths. [callee:0x00587BDC, source:raw]
    // CALCULATION: Scale source dimension this+0x1C by a7 (and this+0x20 by a8) to produce the integer rectangle extent. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // GUARD: If first clipped coordinate v12 < 0 subtract it from a10; if second clipped coordinate v13 < 0 subtract it from a2. [source:raw]
    // CALL: sub_543540 clamps/normalizes the two rectangle corner pairs (&a10,&a2) and (&a4,&a6) against the extent (a3,a5). [callee:0x00543540, source:raw]
    // GUARD: Composite only when clipped width a3 > 0 and clipped height a5 > 0. [source:raw]
    // CALL: F_2DSurfaceCompositing(dword_8B78A0, this, ...) composites the surface, then clears the 0x400 flag on the target surface v10[6]. [callee:0x00540250, global:0x008B78A0, source:raw]
    // RETURN: Return the compositing result, or the clipped width a3 when no compositing occurred. [source:raw]

    // Conservative worker pseudocode:
    //   int ClippedRectRender(DWORD* this, float a2, int a3, DWORD* a4,
    //                         int a5, int a6, float a7, float a8, int a9, int a10) {
    //     int x, y, w, h;
    //     if (a10 >= 0) {
    //       w = CRTFtol(this[7] * a7); h = CRTFtol(this[8] * a8);
    //       x = a10; y = CRTFtol(a2);
    //     } else {
    //       x = CRTFtol(a2); y = CRTFtol(a3); w = CRTFtol(a7); h = CRTFtol(a8);
    //     }
    //     if (x < 0) x -= x;
    //     if (y < 0) y -= y;
    //     sub_543540(&x, &y, &w, &h);
    //     if (w > 0 && h > 0) {
    //       int result = F_2DSurfaceCompositing(dword_8B78A0, this, x, y, a4, x, y, w, h, a9);
    //       a4[6] &= ~0x400u;
    //       return result;
    //     }
    //     return w;
    //   }
    // UNRESOLVED: dword_8B78A0 is described by existing analysis as a singleton/manager pointer; its exact role in compositing is not grounded by the packet.
    // UNRESOLVED: The duplicate CRTFtol calls on the scaled path and the meaning of arguments a2/a3/a9 depend on the caller's coordinate convention.
}
