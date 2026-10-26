// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051D1DB
// Canonical corpus name: TrackSurfaceHeightmapIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSurfaceHeightmapIncrement_0051d1db.c

void UnknownObject::TrackSurfaceHeightmapIncrement()
{
    // Increments uint16 counters in a track surface heightmap grid from 3-byte-per-cell source streams. For each of a4 row entries a2[2*i], a pointer to a 3-byte-per-cell stream is decoded: each cell contributes x = byte[0] >> 3, y = byte[1] >> 2, z = byte[2] >> 3, and the counter at grid cell (x, z + 32*y) is incremented, clamping an overflow wrap to 65535 (-1). The per-row inner loop bound v5 is read once from this+0x5C; the grid data array base is read as *(*(this+0x1A4) + 0x18). Returns the last grid cell WORD pointer (or a1 cast to WORD* when no cells were processed).
    // ASSIGNMENT: Initialize result to a1 cast to WORD*, the initial return value. [field:this:0x00000000, source:raw]
    // CALCULATION: Load v5 = pixel count per row from this+0x5C; this is the inner loop bound for every row entry. [field:this:0x0000005C]
    // CALCULATION: Load the heightmap sub-struct pointer from this+0x1A4, then dereference +0x18 to obtain the heightmap data array base used for indexed cell access. [field:this:0x000001A4, field:*(this+0x1A4):0x00000018]
    // LOOP: Outer loop over a4 row entries: each entry a2[2*i] is treated as a pointer to a 3-byte-per-cell pixel stream. [source:raw, function:0x0051D1DB, abi:lead]
    // GUARD: Guard on v5 != 0: when the per-row pixel count is zero, the entry is skipped and the outer loop advances. [field:this:0x0000005C, source:raw]
    // LOOP: Inner do-while loop over v5 cells: decode grid coordinates x = byte[0] >> 3, y = byte[1] >> 2, z = byte[2] >> 3, and advance the stream pointer by 3 bytes per cell. [source:raw]
    // CALCULATION: Compute the grid cell WORD pointer as *(dataArrayBase + 4*x) + (z + 32*y); the base is read from the *(this+0x1A4) sub-struct's +0x18 member. [field:*(this+0x1A4):0x00000018, source:raw]
    // ASSIGNMENT: Increment the WORD counter at the computed cell; if the increment wraps to zero, clamp the counter to 65535 (-1). [source:raw]
    // RETURN: Return the last accessed grid cell WORD pointer, or a1 cast to WORD* when no cells were processed. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   WORD * sub_51D1DB(int hms, WORD **rows, int unused, int count) {
    //     WORD *res = (WORD *)hms;
    //     int perRow = *(int *)(hms + 0x5C);
    //     int v6 = *(int *)(*(int *)(hms + 0x1A4) + 0x18);
    //     for (int i = 0; i < count; ++i) {
    //       res = rows;
    //       unsigned char *px = *(unsigned char **)&rows[2 * i];
    //       int n = perRow;
    //       while (n) {
    //         res = (WORD *)(*(int *)(v6 + 4 * (px[0] >> 3)) + 2 * ((px[2] >> 3) + 32 * (px[1] >> 2)));
    //         if (!++*res) *res = 65535;
    //         px += 3;
    //         --n;
    //       }
    //     }
    //     return res;
    //   }
    // UNRESOLVED: Owner identity of the heightmap sub-struct this (a1) is unknown; no class evidence is available.
    // UNRESOLVED: The caller and how the a2 row-pointer entries are populated are not visible from this function.
    // UNRESOLVED: v5 (this+0x5C) is read once before the outer loop; a per-entry differing pixel count is not supported by the code.
    // UNRESOLVED: Parameter a3 is unused; its intended purpose is unknown.
    // UNRESOLVED: The (x, z + 32*y) grid geometry is inferred from the shift masks, not confirmed by an independent source.
}
