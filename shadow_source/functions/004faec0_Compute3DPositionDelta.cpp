// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAEC0
// Canonical corpus name: F_3DPositionDeltaComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DPositionDeltaComputation_004faec0.c

void UnknownObject::Compute3DPositionDelta()
{
    // Computes a 3D position delta and stores it in this+0xC/0x10/0x14. When the pointer at this+0x110 is non-null, delta = *(this+0x110) minus the inline triple at this+0/0x4/0x8. Otherwise, when the pointer at this+0x10C is non-null, delta = inline triple at this+0/0x4/0x8 minus *(this+0x10C). When both pointers are null it writes the default delta (0, 0, -1.0f).
    // GUARD: Load the pointer at this+0x110; if non-null take the forward-delta branch. [field:this:0x00000110, source:raw]
    // CALCULATION: Compute deltaX = *(this+0x110) x - this+0 x and store it in this+0xC. [field:*(this+0x110):0x00000000, field:this:0x00000000, field:this:0x0000000C]
    // CALCULATION: Compute deltaY = *(this+0x110) y - this+0x4 y and store it in this+0x10. [field:*(this+0x110):0x00000004, field:this:0x00000010]
    // CALCULATION: Compute deltaZ = *(this+0x110) z - this+0x8 z and store it in this+0x14. [field:*(this+0x110):0x00000008, field:this:0x00000014]
    // GUARD: When this+0x110 is null, load the pointer at this+0x10C; if non-null take the reverse-delta branch. [field:this:0x0000010C, source:raw]
    // CALCULATION: Compute deltaX = this+0 x - *(this+0x10C) x and store it in this+0xC. [field:this:0x00000000, field:*(this+0x10C):0x00000000, field:this:0x0000000C]
    // CALCULATION: Compute deltaY = this+0x4 y - *(this+0x10C) y and store it in this+0x10. [field:this:0x00000010, field:*(this+0x10C):0x00000004]
    // CALCULATION: Compute deltaZ = this+0x8 z - *(this+0x10C) z and store it in this+0x14. [field:this:0x00000014, field:*(this+0x10C):0x00000008]
    // ASSIGNMENT: Fallback when both pointers are null: write 0 to this+0xC and this+0x10 and -1082130432 (-1.0f) to this+0x14. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return the leftover register value from whichever branch executed. [source:raw]

    // Conservative worker pseudocode:
    //   if (refPtr = *(this + 0x110)) { delta[0..2] = refPtr[0..2] - inlinePos[0..2]; }
    //   else if (curPtr = *(this + 0x10C)) { delta[0..2] = inlinePos[0..2] - curPtr[0..2]; }
    //   else { delta = { 0, 0, -1.0f }; }
    // UNRESOLVED: The returned value is a decompiler artifact (LODWORD of a stored float); its semantic meaning is not recoverable from this packet.
    // UNRESOLVED: Whether the inline triple at this+0/0x4/0x8 is a stored position or a reference depends on the caller sub_402690, which is not part of this packet.
}
