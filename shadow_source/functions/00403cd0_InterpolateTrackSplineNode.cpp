// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00403CD0
// Canonical corpus name: sub_403CD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_403CD0_00403cd0.c

void UnknownObject::InterpolateTrackSplineNode()
{
    // Looks up position and orientation from a track spline array (7 floats per node, pointer at this+0x150) for node index a2, writing position to a3 and orientation to a4. If the requested entry is all-zero (invalid/empty), walks backwards in steps of 2 nodes to find the nearest valid lower entry; if a valid pair exists, linearly interpolates between node v6 and node v6+2 at fractional step (a2 - v6)/2. If no valid pair is found, falls back to node 0. A valid (non-zero) entry is copied directly. Returns a4.
    // ASSIGNMENT: Load the spline data pointer v4 from this[84] (field this+0x150) and select the 7-float entry for node index a2. [field:this:0x00000150, source:raw]
    // GUARD: Guard on entry a2: if all six floats (position + orientation) are 0.0 the node is treated as invalid and the interpolation path is taken. [source:raw]
    // LOOP: Walk backwards in steps of 2 nodes (v6 -= 2, pointer -= 14 floats) while each candidate entry is entirely zero, searching for the nearest valid lower node. [source:raw]
    // GUARD: If no valid lower neighbour exists (v6 < 2) or the candidate pair at v6-2 is also all-zero, fall back to copying node 0. [source:raw]
    // ASSIGNMENT: Fallback path: copy node 0 position (3 floats) into a3 and node 0 orientation (3 dwords at spline+12) into a4. [source:raw]
    // CALCULATION: Interpolation path: compute linear interpolation between node v6 and node v6+2 for all three position floats using fraction (a2 - v6) / 2, storing the result into a3. [source:raw]
    // ASSIGNMENT: Interpolation path: copy the orientation entry at offset 28*v6 + spline + 12 (3 dwords) into a4. [source:raw]
    // ASSIGNMENT: Direct path: when entry a2 is valid (non-zero), copy its position (3 floats) into a3 and its orientation (3 dwords at 28*a2 + spline + 12) into a4. [source:raw]
    // RETURN: Return a4 (the orientation output pointer). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_403CD0(_DWORD* this, int a2, float* a3, _DWORD* a4) {
    //     float* spline = (float*)this[84]; /* this+0x150 * /
    //     float* cur = &spline[7 * a2];
    //     if (cur[0]==0 && cur[1]==0 && cur[2]==0 && cur[3]==0 && cur[4]==0 && cur[5]==0) {
    //       int v6 = a2 - 2;
    //       while (v6 >= 0) {
    //         float* cand = &spline[7*v6];
    //         if (cand[0]||cand[1]||cand[2]||cand[3]||cand[4]||cand[5]) break;
    //         v6 -= 2;
    //       }
    //       if (v6 < 2 || entry_v6minus2_all_zero) {
    //         /* fallback to node 0 * /
    //         copy3(a3, spline); copy3(a4, spline + 3);
    //       } else {
    //         float t = (a2 - v6) / 2.0;
    //         float* lo = &spline[7*v6];
    //         a3[0] = lo[0] + (lo[0]-prev[0]) * t; ... /* per-axis lerp * /
    //         copy3(a4, spline + 7*v6 + 3);
    //       }
    //     } else {
    //       copy3(a3, cur); copy3(a4, &spline[7*a2 + 3]);
    //     }
    //     return a4;
    //   }
    // UNRESOLVED: The three extra dwords per node (spline + 7*n + 3) are interpreted as orientation (quaternion/Euler) from the caller names; that is DERIVED, not locked by the packet.
    // UNRESOLVED: The 7-float stride per node is DERIVED from the indexing arithmetic (v7 -= 14 floats == 2 nodes); the packet does not name the entry layout.
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is listed as read but does not appear in the raw source; existing analysis proposes a zero-threshold role (DERIVED).
    // UNRESOLVED: Fields this+0x154, +0x158, +0x15C, +0x160, +0x164 are read per the packet but do not appear in the decompiled body; they likely hold adjacent spline metadata.
}
