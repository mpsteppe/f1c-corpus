// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1120
// Canonical corpus name: WheelForceAggregation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceAggregation_004f1120.c

void UnknownObject::WheelForceAggregation()
{
    // Aggregates wheel forces across all 4 wheels of the receiver vehicle for a given surface type a2, weighted by a speed parameter a3 clamped to 32.0. Wheels are selected by matching the surface-type field at (+84 struct, +48) of their contact entry to a2. Each selected wheel contributes force v23 = clamp(a3) * entry[39] * 0.0000038146973, accumulating a total, a speed-weighted term (a3*0.00390625 + 0.80000001) * v23, and a 3-component direction from entries 55/54/53. The result is normalized by 1/total and stored via PerIndexStructFieldSetter(a2, 1, intensity, weighted-average, &direction) when the maximum force exceeds 0.001.
    // ASSIGNMENT: Zero-initialize the accumulators (v3, v4, v5, v7, v10, v15, v17/v18/v19). [source:raw]
    // LOOP: Walk the wheel contact array starting at this + 13928 (this+0x3668), 4 entries at a float stride of 62, counting down a do-while counter from 4. [field:this:0x00003668, source:raw]
    // GUARD: Per-entry gate: the entry pointer is non-null AND the surface-type field ((entry+84 struct) + 48) equals a2 before the wheel is aggregated. [field:*(this+0x3668):0x00000054, field:*(*(this+0x3668)+0x54):0x00000030, source:raw]
    // CALCULATION: Clamp the speed parameter to 32.0, then compute per-wheel force v23 = clamped * entry[39] * 0.0000038146973 and track the running maximum v15. [source:raw]
    // CALCULATION: Accumulate total force v3 += v23, speed-weighted term v4 += (a3 * 0.00390625 + 0.80000001) * v23, and direction components v5/v7/v10 += v23 * entry[55]/entry[54]/entry[53]. [source:raw]
    // ASSIGNMENT: Pack the accumulated direction components into the output slots v17 (x), v18 (y), v19 (z). [source:raw]
    // GUARD: If the maximum force v15 > 0.001, compute the reciprocal 1.0/total, normalize the direction components by it, clamp the intensity to 1.0 when v15 exceeds 1.0, and normalize the weighted term. [source:raw]
    // CALL: Store the result with PerIndexStructFieldSetter(a2, 1, intensity, normalized-weighted-average, (int)&direction). [callee:0x004F8850, source:raw]
    // CALL: Invoked per-frame by VehicleSoundTrigger (004F12E0). [caller:0x004F12E0, source:raw]

    // Conservative worker pseudocode:
    //   void WheelForceAggregation(char *this, int a2, float a3) {
    //     float total = 0.0, weighted = 0.0, vx = 0.0, vy = 0.0, vz = 0.0;
    //     float maxForce = 0.0;
    //     float *entry = (float *)(this + 13928);
    //     int n = 4;
    //     do {
    //       if (*(DWORD*)entry && *(DWORD*)(*(DWORD*)(*(DWORD*)entry + 84) + 48) == a2) {
    //         float clamped = a3 <= 32.0 ? a3 : 32.0;
    //         float force = clamped * entry[39] * 0.0000038146973;
    //         if (force > maxForce) maxForce = force;
    //         total += force;
    //         weighted += (a3 * 0.00390625 + 0.80000001) * force;
    //         vx += force * entry[55];
    //         vy += force * entry[54];
    //         vz += force * entry[53];
    //       }
    //       entry += 62;
    //       --n;
    //     } while (n);
    //     if (maxForce > 0.001) {
    //       float recip = 1.0 / total;
    //       float intensity = maxForce <= 1.0 ? maxForce : 1.0;
    //       PerIndexStructFieldSetter(a2, 1, intensity, weighted * recip, (int)&vx);
    //     }
    //   }
    // UNRESOLVED: Seven globals flagged by packet facts (flt_59E43C, flt_59E440, flt_59E600, flt_59E8CC, flt_59EC20, flt_5AC988, flt_5AD234) appear nowhere in the raw decompiled source; the skeleton fill names them as physics constants but that is unverifiable from this packet.
    // UNRESOLVED: The per-wheel contact element layout (float stride 62) is implied by the relative offsets 39/53/54/55 and the +84 struct with its +48 surface field, but is not confirmed by packet fields.
    // UNRESOLVED: Relationship between the wheel contact array (this+0x3668) and the receiver vehicle object is not established by this packet alone.
}
