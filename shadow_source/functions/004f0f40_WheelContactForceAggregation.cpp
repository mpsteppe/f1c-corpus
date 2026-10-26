// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F0F40
// Canonical corpus name: WheelContactForceAggregation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelContactForceAggregation_004f0f40.c

void UnknownObject::WheelContactForceAggregation()
{
    // Aggregates wheel contact forces across all 4 wheels of the receiver vehicle for a given surface type a2. A grip factor (0.86000001, or 0.5 when this+0x32BC is non-zero) weights each wheel's contact force v24 = (grip - entry[38]) * entry[39] * 0.00012207031. Wheels are selected by matching the surface-type field at (+84 struct, +52) of their contact entry to a2. Positive forces accumulate a total, a grip/geometry-weighted term, and a 3-component direction, then the result is normalized by 1/total and stored via PerIndexStructFieldSetter(a2, 2, intensity, weighted-average, &direction).
    // ASSIGNMENT: Zero-initialize the accumulators (v2, v4, v5, v6, v7, v14, v18/v19/v20) and set the default grip factor v15 = 0.86000001. [source:raw]
    // GUARD: Read v3 = *(DWORD*)(this + 0x32BC); when non-zero, lower the grip factor to 0.5. [field:this:0x000032BC, source:raw]
    // LOOP: Walk the wheel contact array starting at this + 3482 (this+0x3668), 4 entries at a float stride of 62, counting down a do-while counter from 4. [field:this:0x00003668, source:raw]
    // GUARD: Per-entry gate: the entry pointer is non-null AND the surface-type field ((entry+84 struct) + 52) equals a2 before the wheel is aggregated. [field:*(this+0x3668):0x00000054, field:*(*(this+0x3668)+0x54):0x00000034, source:raw]
    // CALCULATION: Compute per-wheel contact force v24 = (grip - entry[38]) * entry[39] * 0.00012207031 and track the running maximum v14. [source:raw]
    // CALCULATION: When v24 > 0.0, accumulate total force v2 += v24, weighted term v4 += (1.1 - entry[38]*0.5 + entry[40]*0.00390625) * v24, and direction components v5/v6/v7 += v24 * entry[55]/entry[54]/entry[53]. [source:raw]
    // ASSIGNMENT: Pack the accumulated direction components into the output slots v18 (x), v19 (y), v20 (z). [source:raw]
    // GUARD: If the maximum contact force v14 > 0.001, compute the reciprocal 1.0/total, normalize the weighted average and direction by it, and clamp the intensity to 1.0 when v14 exceeds 1.0. [source:raw]
    // CALL: Store the result with PerIndexStructFieldSetter(a2, 2, intensity, normalized-weighted-average, (int)&direction). [callee:0x004F8850, source:raw]
    // CALL: Invoked per-frame by VehicleSoundTrigger (004F12E0). [caller:0x004F12E0, source:raw]

    // Conservative worker pseudocode:
    //   float *WheelContactForceAggregation(float *this, int a2) {
    //     float total = 0.0, weighted = 0.0, vx = 0.0, vy = 0.0, vz = 0.0;
    //     float maxForce = 0.0;
    //     float grip = 0.86000001;
    //     if (this[3247]) grip = 0.5;
    //     float *entry = this + 3482;
    //     int n = 4;
    //     do {
    //       if (*(DWORD*)entry && *(DWORD*)(*(DWORD*)(*(DWORD*)entry + 84) + 52) == a2) {
    //         float force = (grip - entry[38]) * entry[39] * 0.00012207031;
    //         if (force > maxForce) maxForce = force;
    //         if (force > 0.0) {
    //           total += force;
    //           weighted += (1.1 - entry[38] * 0.5 + entry[40] * 0.00390625) * force;
    //           vx += force * entry[55];
    //           vy += force * entry[54];
    //           vz += force * entry[53];
    //         }
    //       }
    //       entry += 62;
    //       --n;
    //     } while (n);
    //     if (maxForce > 0.001) {
    //       float recip = 1.0 / total;
    //       float intensity = maxForce <= 1.0 ? maxForce : 1.0;
    //       return PerIndexStructFieldSetter(a2, 2, intensity, weighted * recip, &vx);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Seven globals flagged by packet facts (flt_59E43C, flt_59E440, flt_59E450, flt_59E600, flt_59E9E4, flt_5AC988, flt_5AD230) appear nowhere in the raw decompiled source; the skeleton fill names them as physics constants but that is unverifiable from this packet.
    // UNRESOLVED: The per-wheel contact element layout (float stride 62) is implied by the relative offsets 38/39/40/53/54/55 and the +84 struct with its +52 surface field, but is not confirmed by packet fields.
    // UNRESOLVED: Relationship between the wheel contact array (this+0x3668) and the receiver vehicle object is not established by this packet alone.
}
