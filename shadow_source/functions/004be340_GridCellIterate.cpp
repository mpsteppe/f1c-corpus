// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE340
// Canonical corpus name: GridCellIterate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GridCellIterate_004be340.c

void UnknownObject::GridCellIterate()
{
    // Iterates the 2D spatial-grid cells overlapped by an axis-aligned box centred on position a3 with radius a4. Computes the four clamped cell coordinates via CRTFtol of (pos -/+ radius - origin) * inverseScale: X range from this+0x924 (origin) and this+0x928 (scale) using a3[0], Y range from this+0x92C and this+0x930 using a3[2]. Each coordinate is clamped to [0, 7] and any clamp sets an overflow flag. When the X and Y ranges are non-degenerate, calls ProximityCheckWithTagUpdate on every cell in the range passing the tag value at this+0x934. If the overflow flag was set, additionally calls ProximityCheckWithTagUpdate on the overflow list. Finally increments the counter at this+0x934 and returns the new value. Part of the session/grid subsystem invoked by ParticleEffectUpdateDispatch.
    // CALCULATION: Compute clamped X min cell index v6 = CRTFtol((a3[0] - a4 - origin(this+0x924)) * scale(this+0x928)), clamped to [0, 7]; set overflow flag when clamping occurs. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Compute clamped X max cell index v8 = CRTFtol((a4 + a3[0] - origin(this+0x924)) * scale(this+0x928)), clamped to [0, 7]; set overflow flag when clamping occurs. [callee:0x00587BDC, field:this:0x00000924, field:this:0x00000928, source:raw]
    // CALCULATION: Compute clamped Y min cell index v21 = CRTFtol((a3[2] - a4 - origin(this+0x92C)) * scale(this+0x930)), clamped to [0, 7]; set overflow flag when clamping occurs. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // CALCULATION: Compute clamped Y max cell index v20 = CRTFtol((a4 + a3[2] - origin(this+0x92C)) * scale(this+0x930)), clamped to [0, 7]; set overflow flag when clamping occurs. [callee:0x00587BDC, field:this:0x0000092C, field:this:0x00000930, source:raw]
    // GUARD: Skip the cell iteration entirely when the X range is degenerate (v6 > v8). [source:raw]
    // LOOP: For each X cell in [v6, v8] and each Y cell in [v21, v20], call ProximityCheckWithTagUpdate(cellPtr, tag at this+0x934, a2, a3, a4); cells advance by 9 dwords per step and rows by 72 bytes. [callee:0x004BDA20, field:this:0x00000934, source:raw]
    // GUARD: When any coordinate was clamped (overflow flag set), call ProximityCheckWithTagUpdate on the overflow list. [callee:0x004BDA20, field:this:0x00000934, source:raw]
    // STATE_TRANSITION: Increment the counter at this+0x934 and return the new value. [field:this:0x00000934, source:raw]
    // CALL: Invoked from the frame-path caller ParticleEffectUpdateDispatch (0x004EB430). [caller:0x004EB430, source:raw]

    // Conservative worker pseudocode:
    //   int GridCellIterate(int this, int a2, float *a3, float a4) {
    //     int overflow = 0;
    //     int xMin = clamp(CRTFtol((a3[0] - a4 - *(float *)(this + 2340)) * *(float *)(this + 2344)), 0, 7);
    //     int xMax = clamp(CRTFtol((a4 + a3[0] - *(float *)(this + 2340)) * *(float *)(this + 2344)), 0, 7);
    //     int yMin = clamp(CRTFtol((a3[2] - a4 - *(float *)(this + 2348)) * *(float *)(this + 2352)), 0, 7);
    //     int yMax = clamp(CRTFtol((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352)), 0, 7);
    //     if (anyClamped) overflow = 1;
    //     if (xMin <= xMax) {
    //       for (int cx = xMin; cx <= xMax; cx++)
    //         for (int cy = yMin; cy <= yMax; cy++)
    //           ProximityCheckWithTagUpdate(cell + 36 * (cy + 8 * cx), *(int *)(this + 2356), a2, (int)a3, a4);
    //     }
    //     if (overflow)
    //       ProximityCheckWithTagUpdate((void *)(this + 2304), *(int *)(this + 2356), a2, (int)a3, a4);
    //     return ++*(int *)(this + 2356);
    //   }
    // UNRESOLVED: The overflow list base at this+0x900 (byte offset 2304) is read in the raw source but has no packet field evidence ref.
    // UNRESOLVED: The grid origin/scale semantics of this+0x924/0x928/0x92C/0x930 (grid X/Y origin and inverse scale) are DERIVED from existing analysis prose.
    // UNRESOLVED: The meaning of the counter at this+0x934 (iteration counter vs per-object tag id passed to ProximityCheckWithTagUpdate) is not fully confirmed.
    // UNRESOLVED: The a3 float array layout (indices 0 and 2 as X and Y centre coordinates) is inferred from the raw indexing and not independently confirmed.
    // UNRESOLVED: The cell pointer arithmetic (36-byte cells, 8 cells per row) is read from raw source but the grid storage layout is not independently verified.
}
