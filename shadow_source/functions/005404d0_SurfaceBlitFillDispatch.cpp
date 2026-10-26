// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005404D0
// Canonical corpus name: F_2DSurfaceBlitFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DSurfaceBlitFill_005404d0.c

void UnknownObject::SurfaceBlitFillDispatch()
{
    // Dispatches a 2D surface blit/fill operation from a surface descriptor. If the texture-blit flag (0x40000) is set, it locks the render context via sub_55CA90, issues a vtable call at +144 on the render surface (this+0x1100) to blit the given rectangle, unlocks, and returns 0. Otherwise it selects a lockable surface from the descriptor flags (bit0/bit1 -> a2[2]/a2[3], bit2/bit3 -> a2[4]/a2[5]), locks it via vtable +36/+64, performs a row fill (32-bit RGBA path for format 8 using memset32, 16-bit packed path otherwise using RGBAByteExtraction), unlocks via vtable +40/+68, clears the 0x400 flag, and returns 0 or -1 on lock failure.
    // GUARD: Check surface descriptor flag a2[6] & 0x40000; when set take the texture-blit path. [source:raw]
    // CALL: Lock/render-context-enter call sub_55CA90(a2, 0) before the blit. [callee:0x0055CA90, source:raw]
    // ASSIGNMENT: Build blit rectangle vector v43: x=a3, y=a4, right=a5+a3, bottom=&a6[a4] (row pointer), and call the vtable slot +144 method on the render surface at this[1088] (field at this+0x1100). [field:this:0x00001100, field:*(this+0x1100):0x00000090, source:raw]
    // ASSIGNMENT: Store the blit vtable call result into *this (this+0). [field:this:0x00000000, source:raw]
    // CALL: Unlock/render-context-leave call sub_55CA90(0, 0) after the blit, then return 0. [callee:0x0055CA90, source:raw]
    // GUARD: Select surface handle for locking: a2[6]&1 -> a2[2], a2[6]&2 -> a2[3]; if the selected handle is non-null call its vtable slot +36 to lock it and store the result in *this; return -1 on failure, otherwise adopt the returned pixel buffer and store the lock metadata into a2[10]. [source:raw]
    // GUARD: Select second surface handle: a2[6]&4 -> a2[4], a2[6]&8 -> a2[5]; if non-null call its vtable slot +64 to lock it, store result in *this, return -1 on failure. [source:raw]
    // CALCULATION: Read pixel format a2[12] and row pitch a2[10]; dispatch to the fill path via the format jump table at 0x540750 (jpt_54063B). [global:0x00540750, source:raw]
    // LOOP: Pixel format 8 (32-bit RGBA): for each row, if width a5 is positive fill a5 dwords with color a7 via memset32 and advance by 4*a5 bytes, then step by the row-stride delta (pitch/4 - a5) dwords. [source:raw]
    // CALL: Default (16-bit) fill path: call RGBAByteExtraction(pixelFormat, a7) to pack the color into a 16-bit word, using the pixel-format lookup table at 0x540758 (byte_540758). [callee:0x0055CEB0, global:0x00540758, source:raw]
    // LOOP: 16-bit fill: per row fill a5 pixels by writing the packed color as a repeated 32-bit pattern via memset32 (a5/2 dwords) then handling a possible trailing odd pixel as a 16-bit word. [source:raw]
    // ASSIGNMENT: First unlock path: reselect a2[6]&1 -> a2[2] / a2[6]&2 -> a2[3]; if non-null call vtable slot +40 to unlock the first surface and store the result into *this. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Second unlock path: reselect a2[6]&4 -> a2[4] / a2[6]&8 -> a2[5]; if non-null call vtable slot +68 to unlock the second surface and store the result into *this. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the 0x400 flag from the surface descriptor: a2[6] &= ~0x400. [source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   int SurfaceBlitFillDispatch(int *this, int *desc, int x, int y, int w, char *buf, int color) {
    //     if (desc[6] & 0x40000) {
    //       sub_55CA90(desc, 0);
    //       rect = {x, y, w + x, buf + y};
    //       *this = (*(blit)(*this[1088] + 0x90))(this[1088], 1, &rect, 1, color, 0, 0);
    //       sub_55CA90(0, 0);
    //       return 0;
    //     }
    //     s = (desc[6] & 1) ? desc[2] : (desc[6] & 2) ? desc[3] : 0;
    //     if (s && (*this = (*(lock1)(*s + 36))(s, &meta, &rect, 0))) return -1;
    //     s2 = (desc[6] & 4) ? desc[4] : (desc[6] & 8) ? desc[5] : 0;
    //     if (s2 && (*this = (*(lock2)(*s2 + 64))(s2, 0, &meta, &rect, 0))) return -1;
    //     switch (desc[12]) {
    //       case 8: fill32(buf, desc[10], x, y, w, color); break;
    //       default: fill16(buf, desc[10], x, y, w, RGBAByteExtraction(desc[12], color)); break;
    //     }
    //     if (s) *this = (*(unlock1)(*s + 40))(s);
    //     if (s2) *this = (*(unlock2)(*s2 + 68))(s2, 0);
    //     desc[6] &= ~0x400;
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the render-surface object referenced at this+0x1100 and the meaning of its vtable slots +36/+40/+64/+68 is not resolvable from this packet.
    // UNRESOLVED: The purpose of the sub_55CA90 enter/leave pair (render context vs lock guard) is unclear.
    // UNRESOLVED: Pixel formats other than 8 and the default 16-bit path are handled through the jump table at 0x540750 but their per-format behavior is not shown.
    // UNRESOLVED: The exact layout of the surface descriptor a2 (fields at indexes 2..6, 10, 12) is not established here.
}
