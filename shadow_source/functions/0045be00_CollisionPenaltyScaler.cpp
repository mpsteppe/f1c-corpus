// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BE00
// Canonical corpus name: CollisionPenaltyScaler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionPenaltyScaler_0045be00.c

void UnknownObject::CollisionPenaltyScaler()
{
    // Scales a collision penalty value: dereferences the float threshold array from this+0x0, clamps a2 upward to the FloatArrayThresholdSearch boundary when a2 is below it, then returns a2 scaled by the penalty scale factor 0.035 as a double.
    // ASSIGNMENT: Dereference this+0x0 to obtain the float threshold array pointer v2 [field:this:0x00000000, source:raw]
    // CALL: Call FloatArrayThresholdSearch(v2) to find the threshold boundary from the float array [callee:0x0045BB00, source:raw]
    // GUARD: When a2 is below or equal to the returned threshold, clamp a2 up to that threshold [callee:0x0045BB00, source:raw]
    // CALCULATION: Scale the clamped a2 by 0.035, the penalty scale factor constant [global:0x0059F078, source:raw]
    // RETURN: Return the scaled value as double [source:raw]

    // Conservative worker pseudocode:
    //   double CollisionPenaltyScaler(float** this, int rawValue) {
    //       float* thresholds = *this;
    //       if (rawValue <= FloatArrayThresholdSearch(thresholds))
    //           rawValue = FloatArrayThresholdSearch(thresholds);
    //       return (double)rawValue * 0.035;
    //   }
    // UNRESOLVED: Owner object unknown; this points to a member holding a float threshold array pointer.
    // UNRESOLVED: Identity of the 0.035 constant as penalty scale factor (flt_59F078) is DERIVED from existing analysis, not confirmed.
    // UNRESOLVED: What a2 represents (collision penetration depth) and why it is clamped upward to a threshold are DERIVED interpretations, not confirmed.
}
