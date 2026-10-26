// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004047D0
// Canonical corpus name: CountedLoopCallToElementUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CountedLoopCallToElementUpdate_004047d0.c

void UnknownObject::countedVehicleProximityLoop()
{
    // Runs a counted loop: for count = this[76] (at +0x130) iterations, calls VehicleProximity on successive elements of the array at base this[77] (at +0x134) with a 316-byte stride. Structural twin of ShortComputation_4790 (00404790); called by SurfaceHeightfieldCollisionCallback (0x00404250).
    // ASSIGNMENT: result = this[76] (iteration count read from +0x130). [field:this:0x00000304, source:raw]
    // ASSIGNMENT: v3 = 0; v4 = 0 (counter and index initialization). [source:raw]
    // GUARD: if (result > 0) enter the loop. [source:raw]
    // LOOP: do { ... } while (v3 < result) — counted loop, count re-read from +0x130 each iteration. [field:this:0x00000304, source:raw]
    // CALL: VehicleProximity(v4 + this[77]) — proximity evaluation for element at base +0x134 plus current index. [callee:0x004FB2E0, field:this:0x00000308, source:raw]
    // CALCULATION: v4 += 316 (advance to next element, 316-byte stride); ++v3; result = this[76] (re-read count). [field:this:0x00000304, source:raw]
    // RETURN: return result (final iteration count). [source:raw]
}
