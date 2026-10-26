// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004047D0
// Canonical corpus name: CountedLoopCallToElementUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CountedLoopCallToElementUpdate_004047d0.c

void UnknownObject::CountedLoopCallToElementUpdate()
{
    // Counted loop driving VehicleProximity (004FB2E0). Reads a count from this[76] (+0x130); if positive, loops that many times calling VehicleProximity(v4 + this[77]) with v4 advancing by 316 per iteration. Returns the final count. Structural twin of ShortComputation_4790 (00404790) per the DERIVED cluster prelabel; the +316 stride suggests per-element processing of a fixed-stride table anchored at +0x134.
    // ASSIGNMENT: result = this[76]; load the iteration count from this+0x130. [field:this:0x00000130, function:0x004047D0, source:raw]
    // GUARD: If result > 0, enter the loop; otherwise skip and return the count (0). [function:0x004047D0, source:raw]
    // LOOP: do/while loop running exactly count times; each pass calls VehicleProximity and advances v4 by 316. [field:this:0x00000134, callee:0x004FB2E0, function:0x004047D0, source:raw]
    // CALL: VehicleProximity(v4 + this[77]); argument is element base (+0x134) plus running offset v4. [field:this:0x00000134, callee:0x004FB2E0, function:0x004047D0, source:raw]
    // ASSIGNMENT: Per-iteration: re-read count from this+0x130, ++v3, v4 += 316; loop while v3 < result. [field:this:0x00000130, function:0x004047D0, source:raw]
    // RETURN: Return the final count value. [function:0x004047D0, source:raw]

    // Conservative worker pseudocode:
    //   count = this[76];
    //   if (count > 0) {
    //     for (i = 0, off = 0; i < count; i++, off += 316)
    //       VehicleProximity(off + this[77]);
    //   }
    //   return count;
    // UNRESOLVED: Element stride 316 and base +0x134 imply a packed element table, but element type/size is not confirmed by the packet.
    // UNRESOLVED: Caller SurfaceHeightfieldCollisionCallback (00404250) places this in collision processing, but the owning object type is unidentified.
}
