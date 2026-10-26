// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A2840
// Canonical corpus name: sub_4A2840
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A2840_004a2840.c

void UnknownObject::UpdateKeyframeAnimation()
{
    // Piecewise-linear keyframe interpolator. Given an input value a2, walks an array of segments (7 floats each: input-min, input-max, inverse range, output-min, output-max) at this+116, finds the active segment, interpolates the output, and, when the value actually changed (compared against last value this+68), fans the result out to every callback target in the listener array this+108. Out-of-range inputs clamp to the first or last segment endpoint.
    // GUARD: Guard on the listener array at this+108; if null the whole update is skipped. [field:this:0x0000006C, source:raw]
    // CALCULATION: Read segment count v3 from this+112 and initialize the segment index v4 to 0. [field:this:0x00000070, source:raw]
    // GUARD: Only iterate when the segment count v3 is greater than zero. [field:this:0x00000070, source:raw]
    // LOOP: Scan the segment array at this+116, stepping 7 floats per segment, while a2 exceeds the current segment's input-min (i[0]). [field:this:0x00000074, field:*(this+0x74):0x00000000, source:raw]
    // GUARD: When a2 is within the current segment (a2 <= input-max i[1]), this segment is the active one. [field:*(this+0x74):0x00000004, source:raw]
    // GUARD: Change detection: skip callbacks entirely when the last value this+68 already equals a2. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Record the new input value a2 into the last-value field this+68. [field:this:0x00000044, source:raw]
    // CALCULATION: Linear interpolation: v10 = (a2 - input-min) * inverse-range i[2] * (output-max i[4] - output-min i[3]) + output-min i[3]. [field:*(this+0x74):0x00000000, field:*(this+0x74):0x00000008, field:*(this+0x74):0x0000000C, field:*(this+0x74):0x00000010, source:raw]
    // LOOP: Invoke sub_551210(entry, v10) once per listener: iterate the this+104 listener-count entries of the array at this+108. [field:this:0x00000068, field:this:0x0000006C, callee:0x00551210, source:raw]
    // STATE_TRANSITION: After exhausting every segment (++v4 == v3), a2 sits past the last segment's input-max; clamp to the final segment's output-max i[4]. [field:this:0x00000070, field:*(this+0x74):0x00000004, field:*(this+0x74):0x00000010, source:raw]
    // GUARD: Clamp guard: only emit the endpoint callback when last value this+68 differs from i[1] (last segment input-max). [field:this:0x00000044, field:*(this+0x74):0x00000004, source:raw]
    // LOOP: Clamp path: set this+68 = i[1] and call sub_551210(entry, i[4]) for every listener. [field:this:0x00000044, field:this:0x00000068, field:this:0x0000006C, field:*(this+0x74):0x00000010, callee:0x00551210, source:raw]
    // GUARD: Safety bail: return early if the running index v4 reaches or passes the segment count mid-scan. [field:this:0x00000070, source:raw]
    // ASSIGNMENT: Below-first-segment clamp after the scan loop ends with a2 <= the first segment's input-min: set last value this+68 to *i (first input-min) when it differs. [field:this:0x00000044, field:*(this+0x74):0x00000000, source:raw]
    // LOOP: Below-first-segment clamp path: call sub_551210(entry, i[3]) with the first segment's output-min for every listener. [field:this:0x00000068, field:this:0x0000006C, field:*(this+0x74):0x0000000C, callee:0x00551210, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4A2840(int this, float a2) {
    //     if (*(this+108) == 0) return;
    //     int segCount = *(this+112);
    //     if (segCount > 0) {
    //       float *seg = *(float**)(this+116);
    //       int idx = 0;
    //       for (; a2 > seg[0]; seg += 7) {
    //         if (a2 <= seg[1]) {
    //           if (*(float*)(this+68) != a2) {
    //             *(float*)(this+68) = a2;
    //             float out = (a2 - seg[0]) * seg[2] * (seg[4] - seg[3]) + seg[3];
    //             for (int n = 0; n < *(this+104); ++n)
    //               sub_551210(*(*(this+108) + 4*n), out);
    //           }
    //           return;
    //         }
    //         if (++idx == segCount) {
    //           if (*(float*)(this+68) != seg[1]) {
    //             *(float*)(this+68) = seg[1];
    //             for (int n = 0; n < *(this+104); ++n)
    //               sub_551210(*(*(this+108) + 4*n), seg[4]);
    //           }
    //           return;
    //         }
    //         if (idx >= segCount) return;
    //       }
    //       if (*(float*)(this+68) != seg[0]) {
    //         *(float*)(this+68) = seg[0];
    //         for (int n = 0; n < *(this+104); ++n)
    //           sub_551210(*(*(this+108) + 4*n), seg[3]);
    //       }
    //     }
    //   }
    // UNRESOLVED: The identity and contract of the sub_551210 callback targets and of the owning animation object are not established by this packet.
    // UNRESOLVED: The third float of each segment (i[2]) is used as a precomputed scaling factor; its exact definition (likely an inverse range) is inferred, not evidenced.
    // UNRESOLVED: The relationship of this+68 last-value field to callers that sample or reset it is unknown.
}
