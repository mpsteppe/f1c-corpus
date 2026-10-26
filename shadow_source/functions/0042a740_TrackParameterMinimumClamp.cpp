// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A740
// Canonical corpus name: TrackParameterMinimumClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackParameterMinimumClamp_0042a740.c

void UnknownObject::TrackParameterMinimumClamp()
{
    // Clamps the float at this[4385] (offset 0x4484) into the range [5.0, a2]. If the value exceeds a2 it is reduced to a2; if it is below 5.0 it is raised to 5.0. The 5.0 lower bound is sourced from read-only global flt_59E7EC (0x0059E7EC). Called by AI steering correction functions.
    // GUARD: If value at this[0x4484] > a2, clamp down [field:this:0x00004484, source:raw]
    // ASSIGNMENT: Set this[0x4484] = a2 (upper clamp) [field:this:0x00004484, source:raw]
    // GUARD: If value at this[0x4484] < 5.0 (5.0 constant held in global flt_59E7EC), clamp up [field:this:0x00004484, global:0x0059E7EC, source:raw]
    // ASSIGNMENT: Set this[0x4484] = 5.0 (lower clamp) [field:this:0x00004484, global:0x0059E7EC, source:raw]

    // Conservative worker pseudocode:
    //   void TrackParameterMinimumClamp(float *this, float a2) {
    //     if (this[4385] > a2) this[4385] = a2;
    //     if (this[4385] < 5.0) this[4385] = 5.0;
    //   }
    // UNRESOLVED: Semantic name of the clamped field at 0x4484 not established.
    // UNRESOLVED: Global 0x0059E7EC is evidenced as the source of the 5.0 literal but its own semantic name is unresolved.
}
