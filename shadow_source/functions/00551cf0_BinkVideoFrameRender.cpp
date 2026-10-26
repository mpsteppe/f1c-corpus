// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551CF0
// Canonical corpus name: BinkVideoFrameRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinkVideoFrameRender_00551cf0.c

void UnknownObject::BinkVideoFrameRender()
{
    // Advances and renders one Bink video frame. When the Bink handle at this[0] reports the next frame ready (BinkWait returns 0), the frame is decompressed via BinkDoFrame, advanced via BinkNextFrame, and the current-frame counter this[1] wraps modulo the total frame count read from *this + 8. A switch on a2[12] selects BinkCopyToBuffer destination flags (5->9, 6->10, 7->1, 8->5, default -> a2 pointer); bit 0x20 of a5 forces the 0x80000000 flag. ThunkWithArgReorder(a2, 0, 0) resolves a target buffer; when nonzero, BinkCopyToBuffer copies the frame, ArgumentReorderWrapper_3230 releases it, and a2[6] clears bit 0x400. Returns whether this[1] wrapped to zero.
    // GUARD: Guard the frame-advance path on the Bink handle: only when BinkWait(*this) returns 0 is the next frame ready. [field:this:0x00000000, global:0x0059E340, source:raw]
    // CALL: Call BinkDoFrame(*this) to decompress the current frame. [field:this:0x00000000, global:0x0059E344, source:raw]
    // CALL: Call BinkNextFrame(*this) to advance to the next frame in the stream. [field:this:0x00000000, global:0x0059E348, source:raw]
    // CALCULATION: Update the current-frame counter with modulo wrap: this[1] = (this[1] + 1) % (*(_DWORD *)(*this + 8)), where *this + 8 holds the total frame count. [field:obj:0x00000008, field:this:0x00000000, field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Switch on a2[12] via jump table jpt_551D31 to select BinkCopyToBuffer destination flags: case 5 -> 9, case 6 -> 10, case 7 -> 1, case 8 -> 5, default -> (int)a2. [global:0x00551DB4, source:raw]
    // CALCULATION: If the flag argument a5 has bit 0x20 set, OR the 0x80000000 flag into v6. [source:raw]
    // CALL: Call ThunkWithArgReorder(a2, 0, 0) to resolve the target surface/buffer and store it in v7. [callee:0x00543210, source:raw]
    // GUARD: Guard the copy path on the resolved buffer: proceed only when v7 is nonzero. [source:raw]
    // CALL: Call BinkCopyToBuffer(*this, v7, a2[10], a2[8], a3, a4, v6) to copy the rendered frame into the target buffer with destination pitch, rectangle and flags. [field:this:0x00000000, global:0x0059E34C, source:raw]
    // CALL: Call ArgumentReorderWrapper_3230(a2, 0, 0) to release the resolved surface after the copy. [callee:0x00543230, source:raw]
    // ASSIGNMENT: Clear bit 0x400 in a2[6]: a2[6] &= ~0x400u. [source:raw]
    // RETURN: Return whether the current-frame counter wrapped to zero: this[1] == 0. [field:this:0x00000004, guard:0, source:raw]

    // Conservative worker pseudocode:
    //   BOOL BinkVideoFrameRender(DWORD *this, DWORD *a2, int a3, int a4, char a5) {
    //     if (!BinkWait(*this)) {
    //       BinkDoFrame(*this);
    //       BinkNextFrame(*this);
    //       this[1] = (unsigned)(this[1] + 1) % *(DWORD*)(*this + 8);
    //     }
    //     int v6;
    //     switch (a2[12]) {
    //       case 5: v6 = 9; break;
    //       case 6: v6 = 10; break;
    //       case 7: v6 = 1; break;
    //       case 8: v6 = 5; break;
    //       default: v6 = (int)a2; break;
    //     }
    //     if (a5 & 0x20) v6 |= 0x80000000;
    //     DWORD *v7 = (DWORD*)ThunkWithArgReorder(a2, 0, 0);
    //     if (v7) {
    //       BinkCopyToBuffer(*this, v7, a2[10], a2[8], a3, a4, v6);
    //       ArgumentReorderWrapper_3230(a2, 0, 0);
    //       a2[6] &= ~0x400u;
    //     }
    //     return this[1] == 0;
    //   }
    // UNRESOLVED: The switch values on a2[12] and the 0x400 bit cleared in a2[6] map to render-path flags whose semantic meaning is not established by the packet.
    // UNRESOLVED: The a2 object and its fields a2[6], a2[8], a2[10], a2[12] are not covered by the packet field evidence (which only names obj+8, this+0, this+4).
    // UNRESOLVED: The jump table jpt_551D31 backs the switch but its exact target layout is not verified.
}
