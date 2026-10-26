// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EC1A0
// Canonical corpus name: CollisionSparkParticleEffects
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSparkParticleEffects_004ec1a0.c

void UnknownObject::CollisionSparkParticleEffects()
{
    // Per-frame collision visual/damage feedback for the vehicle: gated by vehicle identity (this[0] vs dword_7C54E8) and a restricted-mode/race-phase guard (this[0x32BC], dword_7C56A8), it scales the impact impulse, fires spark/damage events into a ring buffer (ProgressBarEventEncode + StateTransition), runs two body-zone repair-service blocks and an 8-zone body loop plus a 4-zone wheel loop that dispatch ShortComputation/RepairService events, and applies steering-geometry deformation (SteeringGeometryUpdate) and tire-scrub reset (TireScrubReset) on severe impacts. Called per frame from VehicleContactForceAccumulation.
    // GUARD: Primary path requires this[0] == dword_7C54E8 (vehicle identity matches the shared reference). [field:this:0x00000000, global:0x007C54E8]
    // GUARD: Primary path also requires byte_7C749F clear and (byte at this[0x3440] clear or byte_7C74A4 clear). [global:0x007C749F, field:this:0x00003440, global:0x007C74A4]
    // GUARD: When identity differs, the main body runs if the restricted-mode flag this[0x32BC] != 1, or if the race phase dword_7C56A8 is not 1 and not 3. [field:this:0x000032BC, global:0x007C56A8, guard:0]
    // CALCULATION: Impact magnitude v115 = |a4|; scaled force v146 = dword_7D0014 * v115 * 0.0099999998; ramped through this[0x3D78] + this[0x3D7C]*v146 and clamped to this[0x3D80]; squared into the proximity threshold v113. [global:0x007D0014, field:this:0x00003D78, field:this:0x00003D7C, field:this:0x00003D80, source:raw]
    // CALL: When the scaled force v146 exceeds this[0x3D84], TireScrubReset(this) clears the tire-scrub state. [field:this:0x00003D84, callee:0x004EFAE0]
    // CALCULATION: damage v114 = v146 * this[0x3D88], clamped to 1.0. [field:this:0x00003D88]
    // GUARD: The spark/event dispatch path runs only when the impact magnitude |a4| > this[0x3D8C] (damage threshold). [field:this:0x00003D8C]
    // CALL: Route the damage feedback by contact-direction component a2[2]: FloatParameterForwarder when < -1.0, ForceApplicationRouter when in [-1.0, 1.0), PhysicsTimeStep when >= 1.0. [callee:0x004ED1C0, callee:0x004ED1F0, callee:0x004ED220]
    // CALCULATION: v8 = this[0x3D90] * damage clamped to 1.0; v9 = sqrt(v8) / |a4|; spark direction components v118/v119/v120 = a3 components scaled by v9. [field:this:0x00003D90]
    // ASSIGNMENT: Ring-buffer slot allocation: if dword_83EE60 < 1023, increment dword_83EE60 and advance dword_8AAE64 by 432; the slot base v10 = dword_8AAE64. [global:0x0083EE60, global:0x008AAE64]
    // CALL: Encode the spark event: ProgressBarEventEncode(v10, 2, 7, 10, this[1], dbl_8AFEA0, 0); store 127-quantized direction bytes at slot+8..+13 and this[0x34AC] at slot+14; then StateTransition on the sub-object at element index 3248 of this with value 1. [callee:0x004B33B0, global:0x008AFEA0, field:this:0x00000004, field:this:0x000034AC, callee:0x004A56B0, source:raw]
    // GUARD: Body-zone block A (repair-service zone 4): gated on the dword at this[0xCC8] and the byte at this[0xD08]; when contact distance squared is below v113 and the scaled force (1 - d2/v113)*v146 exceeds this[0x3D94], draw a random value from flt_8AAE74 via ++dword_8AAE70 and proceed only when it is below this[0x3D98]; uses this[0x3D9C], this[0x3DA0], this[0x3DA4] as the zone-local reference. [field:this:0x00000CC8, field:this:0x00000D08, field:this:0x00003D94, field:this:0x00003D98, field:this:0x00003D9C, field:this:0x00003DA0, field:this:0x00003DA4, global:0x008AAE74, global:0x008AAE70]
    // CALL: Body-zone block A dispatch: RepairServiceStateDispatcher(4), then ShortComputation_1330(dword_5EA560, 4, this + element 3946, this[1], 0, &transform) with the transform built from orientation elements this[0x34AC]..this[0x34E8] plus jitter from flt_8AB274. [callee:0x004ED250, callee:0x00411330, global:0x005EA560, field:this:0x00000004, field:this:0x000034AC, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, global:0x008AB274, source:raw]
    // GUARD: Body-zone block B (repair-service zone 5): gated on the dword at this[0xD0C] and the byte at this[0xD4C]; contact distance squared below v113, scaled force above this[0x3DC4], random flt_8AAE74 draw (++dword_8AAE70) below this[0x3DC8]; uses this[0x3DCC], this[0x3DD0], this[0x3DD4] as the zone-local reference. [field:this:0x00000D0C, field:this:0x00000D4C, field:this:0x00003DC4, field:this:0x00003DC8, field:this:0x00003DCC, field:this:0x00003DD0, field:this:0x00003DD4, global:0x008AAE74, global:0x008AAE70]
    // CALL: Body-zone block B dispatch: RepairServiceStateDispatcher(5), then ShortComputation_1330(dword_5EA560, 4, this + element 3958, this[1], 1, &transform) with the same orientation transform and flt_8AB274 jitter. [callee:0x004ED250, callee:0x00411330, global:0x005EA560, field:this:0x00000004, field:this:0x000034AC, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, global:0x008AB274, source:raw]
    // LOOP: Body-zone loop over 8 zones: each zone is gated on the dword at this[0xD50] and the byte at this[0xD90]; contact distance squared from a2 to the zone anchor (this[0x3EB4], this[0x3EB8]) compared against v113, and the scaled force against the zone threshold this[0x3E90]; on a hit draw flt_8AAE74 via ++dword_8AAE70 and compare below this[0x3E90]. [field:this:0x00000D50, field:this:0x00000D90, field:this:0x00003E90, field:this:0x00003EB4, field:this:0x00003EB8, global:0x008AAE74, global:0x008AAE70, source:raw]
    // CALL: Body-zone loop dispatch: RepairServiceStateDispatcher(zone + 6), then ShortComputation_1330(dword_5EA560, 5, zone output buffer, this[1], zone, &transform) with the orientation transform this[0x34AC]..this[0x34E8], zone scale terms this[0x34EC]/this[0x34F0]/this[0x34F4] and flt_8AB274 jitter. [callee:0x004ED250, callee:0x00411330, global:0x005EA560, field:this:0x00000004, field:this:0x000034AC, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, global:0x008AB274, source:raw]
    // LOOP: Wheel-zone loop over 4 zones: each zone is gated on the dword at this[0x828] and the byte at this[0x868]; contact distance squared from a2 to the wheel anchor (this[0x3590], this[0x3594]) compared against v113; random branch taken when the scaled force is within the band this[0x3DF4]..this[0x3DF8] or the random draw (flt_8AAE74 via ++dword_8AAE70) exceeds this[0x3DFC]. [field:this:0x00000828, field:this:0x00000868, field:this:0x00003590, field:this:0x00003594, field:this:0x00003DF4, field:this:0x00003DF8, field:this:0x00003DFC, global:0x008AAE74, global:0x008AAE70, source:raw]
    // CALL: Steering-geometry branch: when the restricted-mode flag this[0x32BC] is clear, interpolate the normalized force within this[0x3DF4]..this[0x3DF8] and call SteeringGeometryUpdate(&dbl_7C7428, wheel, t) with t clamped to 1.0. [field:this:0x000032BC, field:this:0x00003DF4, field:this:0x00003DF8, global:0x007C7428, callee:0x00442060]
    // CALL: Wheel-zone damage dispatch: RepairServiceStateDispatcher(wheel), then ShortComputation_1330(dword_5EA560, 3, wheel output buffer, this[1], wheel, &transform) with the orientation transform this[0x34AC]..this[0x34E8] and flt_8AB274 jitter; the mode value this[0x39B4] then selects whether TireScrubReset(this) also runs. [callee:0x004ED250, callee:0x00411330, global:0x005EA560, field:this:0x00000004, field:this:0x000034AC, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, field:this:0x000039B4, callee:0x004EFAE0, global:0x008AB274, source:raw]
    // RETURN: Return the last computed flag byte, which encodes which entry path was taken (identity or race-phase path indicator). [function:0x004EC1A0, source:raw]

    // Conservative worker pseudocode:
    //   char CollisionSparkParticleEffects(char *this, float *a2, float *a3, float a4) {
    //     if (*(_DWORD *)this == dword_7C54E8) {
    //       if (byte_7C749F || (this[0x3440] && byte_7C74A4)) return flag;
    //     } else {
    //       if (this[0x32BC] != 1) goto body;
    //       if (dword_7C56A8 == 1 || dword_7C56A8 == 3) return dword_7C56A8;
    //     }
    //   body:
    //     v115 = fabs(a4); v146 = dword_7D0014 * v115 * 0.0099999998;
    //     v7 = clamp(v146 * this[0x3D7C] + this[0x3D78], this[0x3D80]); v113 = v7 * v7;
    //     if (v146 > this[0x3D84]) TireScrubReset(this);
    //     v114 = min(v146 * this[0x3D88], 1.0);
    //     if (v115 > this[0x3D8C]) {
    //       route_damage(a2[2], v114); /* FloatParameterForwarder | ForceApplicationRouter | PhysicsTimeStep * /
    //       v9 = sqrt(min(this[0x3D90] * v114, 1.0)) / v115;
    //       slot = alloc_ring_slot(); /* dword_83EE60, dword_8AAE64 * /
    //       ProgressBarEventEncode(slot, 2, 7, 10, this[1], dbl_8AFEA0, 0);
    //       encode_direction_bytes(slot, a2, a3, v9);
    //       StateTransition(this + 3248, 1);
    //     }
    //     repair_service_block(this[0xCC8], this[0xD08], 4, this+3946, 0);
    //     repair_service_block(this[0xD0C], this[0xD4C], 5, this+3958, 1);
    //     for (zone = 0; zone < 8; zone++) body_zone_dispatch(zone);
    //     for (wheel = 0; wheel < 4; wheel++) wheel_zone_dispatch(wheel); /* RepairServiceStateDispatcher, ShortComputation_1330, SteeringGeometryUpdate, TireScrubReset * /
    //     return flag;
    //   }
    // UNRESOLVED: Constant globals dbl_59E430, flt_59E43C, flt_59E444, flt_59E450, flt_59E670, flt_59E7E8, flt_59E7EC, flt_59E8B4, flt_5AD1EC, flt_5AD1F0, flt_5AD1F4 are read but do not appear by name in the decompiled arithmetic; their mapping to the inlined literals (e.g. 0.0099999998, 0.2, 0.30000001, 127.0) is not recoverable from this packet.
    // UNRESOLVED: StateTransition is called on the sub-object at element index 3248 of this, which is not a listed packet field.
    // UNRESOLVED: The body/wheel zone loops walk several unlisted pointers (the this+2088-based flag walk, and the this+0x3590/this+0x3E90-anchored buffer sets, plus unlisted zone-reference and output-buffer offsets). Only the listed fields are modeled as fields.
    // UNRESOLVED: The 432-byte ring-buffer stride and slot layout written by ProgressBarEventEncode (bytes at slot+8..+14) are not separately evidenced.
}
