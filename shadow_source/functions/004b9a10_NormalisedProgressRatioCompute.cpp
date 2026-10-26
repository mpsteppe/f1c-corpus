// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9A10
// Canonical corpus name: sub_4B9A10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9A10_004b9a10.c

void UnknownObject::NormalisedProgressRatioCompute()
{
    // __thiscall: computes a normalised progress ratio in [0,1] over a range read from a queue, using either a wrap mode (v9 - v7) or a clamp mode driven by a session-time global minus a per-object offset (obj+0xF84). Returns (Delegation(this) - v8) / v9, or 0.0 when the computed range is <= 0. Used for steering/animation interpolation by SteeringAckermannComputation.
    // ASSIGNMENT: Dereference this to get the object pointer v2 = *this, and initialise the two range locals v7 = 0.0 and v9 = 0.0. [field:this:0x00000000, source:raw]
    // CALL: Call QueuePeek(v2, &v7, &v9) to read the range's lower (v7) and upper (v9) bounds from the queue embedded in the object. [callee:0x004B87A0, source:raw]
    // GUARD: Branch on the byte flag at obj+0xF81 (3969): non-zero selects clamp mode, zero selects wrap mode. [field:obj:0x00000F81, source:raw]
    // CALCULATION: Clamp mode: v3 = dbl_8AFEA0 - float at obj+0xF84 (3972); v8 = max(v3, v7); then v4 = dbl_8AFEA0 - v8. [field:obj:0x00000F84, global:0x008AFEA0, source:raw]
    // CALCULATION: Wrap mode: v4 = v9 - v7 and v8 = v7, i.e. range width with lower bound kept as the offset base. [source:raw]
    // GUARD: When the computed range v4 is <= 0.0, return 0.0 immediately. [source:raw]
    // CALL: Call Delegation(this) to obtain the value v5 that is placed relative to the range. [callee:0x004B9CE0, source:raw]
    // CALCULATION: Return the normalised ratio (v5 - v8) / v9. [source:raw]
    // CALL: Called by SteeringAckermannComputation (0x004DB170) to feed its steering interpolation. [caller:0x004DB170, source:raw]

    // Conservative worker pseudocode:
    //   double NormalisedProgressRatioCompute(int *this) {
    //     int obj = *this;
    //     float lo = 0.0, hi = 0.0, base;
    //     double v4;
    //     QueuePeek(obj, &lo, &hi);
    //     if (*(BYTE *)(obj + 0xF81)) {
    //       double d = dbl_8AFEA0 - *(float *)(obj + 0xF84);
    //       base = (float)(d < lo ? lo : d);
    //       v4 = dbl_8AFEA0 - base;
    //     } else {
    //       v4 = hi - lo;
    //       base = lo;
    //     }
    //     if (v4 <= 0.0) return 0.0;
    //     return (Delegation(this) - base) / v4;
    //   }
    // UNRESOLVED: Global flt_59E440 appears in the packet's global list but is not referenced by the raw source text; its role is unknown.
    // UNRESOLVED: Meaning of dbl_8AFEA0 (nominally session time per existing analysis) and the semantics of the obj+0xF84 offset are DERIVED, not confirmed here.
    // UNRESOLVED: QueuePeek's exact field layout and Delegation's returned quantity are unresolved at this site.
}
