// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551DD0
// Canonical corpus name: BinkVideoFrameDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinkVideoFrameDecoder_00551dd0.c

void UnknownObject::DecodeBinkVideoFrame()
{
    // Bink video frame decoder (thiscall). Waits for the next frame (BinkWait on the Bink handle at this+0), decompresses it with BinkDoFrame, advances with BinkNextFrame, and wraps the frame index this[1] modulo the total frame count read from the Bink header at *this+8. Then maps the render-path flag a2[12] through a jump table into a copy-flag word, ORs high bits from the a5 flags (0x20 sets 0x80000000, 0x10 sets 0x60000000), locks a surface via ThunkWithArgReorder, copies the frame with BinkCopyToBuffer, clears bit 0x400 of a2[6], and returns the surface-unlock result.
    // GUARD: Advance the frame only when BinkWait(*this) returns 0 (next frame is ready); otherwise skip the frame-advance block. [field:this:0x00000000, global:0x0059E340, source:raw]
    // CALL: BinkDoFrame(*this) decompresses and renders the current frame. [field:this:0x00000000, global:0x0059E344, source:raw]
    // CALL: BinkNextFrame(*this) advances the Bink stream to the next frame. [field:this:0x00000000, global:0x0059E348, source:raw]
    // CALCULATION: Advance and wrap the current frame index: this[1] = (this[1] + 1) % *(int*)(*this + 8), using the total frame count read from the Bink header. [field:this:0x00000004, field:obj:0x00000008, source:raw]
    // CALCULATION: Select the base copy-flag value v6 from the render-path flag a2[12] via the jump table: case 5 -> 9, case 6 -> 10, case 7 -> 1, case 8 -> 5, default keeps the a2 pointer value. [global:0x00551E94, source:raw]
    // CALCULATION: OR the high flag bits into v6 from a5: when (a5 & 0x20) != 0 set 0x80000000; when (a5 & 0x10) != 0 set 0x60000000. [source:raw]
    // CALL: ThunkWithArgReorder(a2, 4, 0) locks the surface/buffer and returns a destination pointer as result. [callee:0x00543210, source:raw]
    // CALL: When a surface was obtained, BinkCopyToBuffer(*this, result, a2[10], a2[8], a3, a4, v6) copies the decoded frame into the buffer using the surface pitch, rect and assembled flags. [global:0x0059E34C, field:this:0x00000000, source:raw]
    // CALL: ArgumentReorderWrapper_3230(a2, 4, 0) unlocks/releases the surface; result takes its return value. [callee:0x00543230, source:raw]
    // CALCULATION: Clear bit 0x400 of a2[6] after the copy. [source:raw]
    // RETURN: Return result (the surface unlock/return value). [source:raw]
    // CALL: Invoked by IndexedArrayLookupWithBoundsCheck (0x005504D0) to decode a Bink video frame for an indexed surface. [caller:0x005504D0]

    // Conservative worker pseudocode:
    //   int DecodeBinkVideoFrame(void *this, void *a2, int a3, int a4, int a5) {
    //     if (!BinkWait(this[0])) {
    //       BinkDoFrame(this[0]);
    //       BinkNextFrame(this[0]);
    //       this[1] = (this[1] + 1) % *(int*)(this[0] + 8);
    //     }
    //     switch (a2[12]) { case 5: v6 = 9; break; case 6: v6 = 10; break;
    //                     case 7: v6 = 1; break; case 8: v6 = 5; break;
    //                     default: v6 = (int)a2; break; }
    //     if (a5 & 0x20) v6 |= 0x80000000;
    //     if (a5 & 0x10) v6 |= 0x60000000;
    //     int result = ThunkWithArgReorder(a2, 4, 0);
    //     if (result) {
    //       BinkCopyToBuffer(this[0], result, a2[10], a2[8], a3, a4, v6);
    //       result = ArgumentReorderWrapper_3230(a2, 4, 0);
    //       a2[6] &= ~0x400u;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The render-path flag enum behind a2[12] and the a5 flag semantics (0x10/0x20) are not documented in this function.
    // UNRESOLVED: The mapping from jump-table cases 5-8 to the copy flags 9/10/1/5 is inferred from decompiler structure only.
    // UNRESOLVED: The exact meaning of the surface parameters a2[10], a2[8] and of a2[6] bit 0x400 requires the caller's surface type.
}
