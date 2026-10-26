// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CCB30
// Canonical corpus name: ParticleEffectPhysics
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEffectPhysics_004ccb30.c

void UnknownObject::ParticleEffectPhysics()
{
    // Per-frame particle physics update. Initializes the container via sub_4CC840, then selects lifetime parameters either from the scoring system (when dword_8AB6E4 == 2) or from default double constants. Iterates the particle array (count a1+100, element-pointer array a1+104), removing particles outside their lifetime window, applies acceleration to each particle velocity, and runs AABB collision with sliding response against the player vehicle or nearby drivers depending on dword_7CFA04 mode; surviving particles render their bounding box.
    // CALL: Entry: sub_4CC840(a1) initializes/resets the particle container (a1). [callee:0x004CC840, source:raw]
    // STATE_TRANSITION: Lifetime-parameter select: when dword_8AB6E4 == 2, Delegation(&dword_8AB6EC) supplies the current time; a VehicleDataAccessor(&dword_8AB6EC) == 5 result forces a zero term, otherwise FloatDifference(&dword_8AB6EC) supplies the scaling term. In the non-scoring fallback the time comes from dbl_8AFEA0 and the scaling term from dbl_8AFE98. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, global:0x008AFE98, callee:0x004B9CE0, callee:0x004B9CF0, callee:0x004B9E30, source:raw]
    // LOOP: Walks the particle array: count at a1+100, element-pointer array at a1+104. Each element's byte+8 and byte+12 lifetime bounds are compared against the current time; particles outside the window are removed via ArrayElementRemoval with the loop index decremented. [field:this:0x00000064, field:this:0x00000068, callee:0x004CB5A0, source:raw]
    // CALCULATION: Velocity update: new v6+48 = v19 * v6+60 + v6+48, advancing each particle velocity by the scaled lifetime term. [source:raw]
    // GUARD: Collision processing is gated on (dword_7CFA04 & 3) != 0; when active, the collision step is v23 = v6+60 * 0.03125. [global:0x007CFA04, source:raw]
    // CALL: Player-only mode (dword_7CFA04 == 1): when the player pointer dword_7C54E0 is present and the player position (dword_7C54E0+1860/+1864/+1868) lies within the 4.0 x/z window of the particle, F_3DAABBOverlapTestWithSlidingResponse resolves the particle AABB (v6+44/+48/+52) against the player box at dword_7C54E0+1776. [global:0x007C54E0, callee:0x004CBF50, source:raw]
    // CALL: Proximity mode (else branch): FindDriversInRange(flt_8AC4E0, ...) gathers nearby driver entries within a fixed radius; each candidate whose window overlaps and that is not the current player (dword_7CFA4C bit 0 unset OR driver index != dword_7C54DC) gets the sliding AABB test against the driver box (candidate+1764). [global:0x008AC4E0, global:0x007CFA4C, global:0x007C54DC, callee:0x004C9C70, callee:0x004CBF50, source:raw]
    // CALL: Surviving particles render their AABB via F_3DBoundingBoxRender on the particle and a color/vertex table pair (9095216 / 9095228) indexed by the particle type field (v6+84). [callee:0x004CC700, source:raw]
    // CALL: Invoked from ParticlePositionAdd (004CCDC0) on the particle update path. [caller:0x004CCDC0]

    // Conservative worker pseudocode:
    //   sub_4CC840(a1);
    //   if (dword_8AB6E4 == 2) { time = Delegation(&dword_8AB6EC);
    //     if (VehicleDataAccessor(&dword_8AB6EC) == 5) scale = 0.0; else scale = FloatDifference(&dword_8AB6EC); }
    //   else { time = dbl_8AFEA0; scale = dbl_8AFE98; }
    //   count = a1 + 100;
    //   for (i = 0; i < count; ) {
    //     p = *(*(a1 + 104) + 4 * i);
    //     if (time > *(p + 12) || time < *(p + 8)) { ArrayElementRemoval(a1, p); --i; }
    //     else {
    //       *(p + 48) = scale * *(p + 60) + *(p + 48);
    //       if ((dword_7CFA04 & 3) != 0) {
    //         step = *(p + 60) * 0.03125;
    //         if (dword_7CFA04 == 1) { if (dword_7C54E0 && window ok)
    //           F_3DAABBOverlapTestWithSlidingResponse(p + 44, p + 44, dword_7C54E0 + 1776); }
    //         else {
    //           drivers = FindDriversInRange(flt_8AC4E0, ...);
    //           for each driver overlapping && (dword_7CFA4C & 1 || driverIndex != dword_7C54DC)
    //             F_3DAABBOverlapTestWithSlidingResponse(p + 44, p + 44, driver + 1764);
    //         }
    //       }
    //       F_3DBoundingBoxRender(p, p + tableIndex(p + 84), p + tableIndex(p + 84));
    //       ++i;
    //     }
    //   }
    // UNRESOLVED: Two globals (flt_59E46C, flt_59ED18) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them TireSlipOffset and ForceReductionFactor, both unverifiable from this packet.
    // UNRESOLVED: The per-element particle layout is reached only by relative byte offsets (e.g. +8/+12 lifetime bounds, +48/+52 position, +60 velocity, +84 type); no element struct definition is present in this packet.
}
