// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6D90
// Canonical corpus name: ParametricInterpolationBlending
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParametricInterpolationBlending_004f6d90.c

void UnknownObject::ParametricInterpolationBlending()
{
    // Piecewise interpolation over a segment table. The segment count is stored at this+0x0 and the segment table starts at this+4 with a 12-byte (3-float) stride: low bound, high bound, and a third per-segment value. It scans forward while the parameter a2 lies outside the current segment's [low, high] window, invoking each skipped segment's object (from the callback-object array at this+0x40) via its vtable+8 method. When the scan stops it either applies the terminal segment directly (calling the object's vtable+4 method with 2, a3, a4, a5 and a scaled parameter) or blends between two adjacent segments: it computes a normalized factor from a2 and the segment bounds, derives sqrt-based weights and scaled parameters, and invokes each participating object's vtable+4 method with (2, a3, a4, weight, scaled param, 0), then invokes vtable+8 on every remaining segment. It returns this+0 (the segment count). Called by SuspensionForceComputationWithPerCornerVirtualDi (0x004F8440).
    // ASSIGNMENT: Read result = this[0] (segment count). [field:this:0x00000000, source:raw]
    // GUARD: Guard: only proceed when this[0] > 0 (segments exist); otherwise return this[0] unchanged. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Scan segments (3-float stride from this+4) while a2 > current high bound (this+8) or a2 < current low bound (this+4). [field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: For each skipped segment, load its object from the callback array at this+0x40 (indexed by segment) and call its vtable+8 method. [field:this:0x00000040, source:raw]
    // GUARD: Branch: use the direct terminal path when the next segment index equals the count, or when a2 is below the next segment's high bound. [field:this:0x00000008, source:raw]
    // CALCULATION: Direct path: compute scaled parameter v22 = a2 * next segment low bound. [field:this:0x00000004, source:raw]
    // CALL: Direct path: call the terminal segment object's (callback array this+0x40) vtable+4 method with arguments (2, a3, a4, a5, v22, 0). [field:this:0x00000040, source:raw]
    // CALCULATION: Interpolation path: compute normalized factor v23 = (a2 - next_segment_high) / (current_segment_third - next_segment_high), sqrt-based weights v18 = sqrt(1.0 - v23) * a5 and v19 = sqrt(v23) * a5, and scaled parameters v20 = a2 * next_segment_low and v21 = a2 * segment_after_next_low. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: Interpolation path: call the two adjacent segment objects' (callback array this+0x40) vtable+4 methods with arguments (2, a3, a4, weight, scaled param, 0). [field:this:0x00000040, source:raw]
    // LOOP: Cleanup loop: for every remaining segment index, load its object from the callback array at this+0x40 and call its vtable+8 method. [field:this:0x00000040, source:raw]
    // RETURN: Return this[0] (the segment count). [field:this:0x00000000, function:0x004F6D90, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0];
    //   if (count <= 0) return count;
    //   i = segments;  /* 3 floats per segment * /
    //   while (a2 > i[1] || a2 < i[0]) {
    //       CallVtable8(this->callbacks[idx]);
    //       if (++idx >= count) return count;
    //       i += 3;
    //   }
    //   next = idx + 1;
    //   if (next == count || a2 < segments[next][1]) {
    //       CallVtable4(this->callbacks[idx], 2, a3, a4, a5, a2 * segments[next][0], 0);
    //       for (k = next; k < count; k++) CallVtable8(this->callbacks[k]);
    //   } else {
    //       f = (a2 - segments[next][1]) / (segments[idx][2] - segments[next][1]);
    //       CallVtable4(this->callbacks[idx], 2, a3, a4, sqrt(1.0 - f) * a5, a2 * segments[next][0], 0);
    //       CallVtable4(this->callbacks[next], 2, a3, a4, sqrt(f) * a5, a2 * segments[idx + 2][0], 0);
    //       for (k = idx + 2; k < count; k++) CallVtable8(this->callbacks[k]);
    //   }
    //   return count;
    // UNRESOLVED: The third float of each segment participates in the interpolation denominator (current_segment_third) and the sqrt-based weights imply blending, but the physical meaning of the table columns is inferred, not confirmed.
    // UNRESOLVED: Virtual dispatch targets are indirect (vtable +4 and +8); the callee identities, the meaning of argument literal 2, and the trailing 0 are not resolved.
    // UNRESOLVED: Packet global flt_59E43C is listed but not referenced by the raw source; its role is unresolved.
    // UNRESOLVED: The relationship to caller SuspensionForceComputationWithPerCornerVirtualDi is inferred from the call graph only.
}
