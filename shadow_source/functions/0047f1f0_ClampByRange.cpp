// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F1F0
// Canonical corpus name: ClampByRange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampByRange_0047f1f0.c

void UnknownObject::ClampByRange()
{
    // Clamp the integer pointed to by a1 into the inclusive range [a2, a3]: if *a1 is below the lower bound a2 it is raised to a2; if it is above the upper bound a3 it is lowered to a3. Returns the original *a1 value, read before any clamp. Called by session/config and physics-parameter setup paths.
    // RETURN: Capture the original value *a1 into the return slot before any clamping; this pre-clamp value is what the function returns. [function:0x0047F1F0, source:raw]
    // GUARD: Lower-bound guard: if *a1 < a2, clamp *a1 to the lower bound a2. [function:0x0047F1F0, source:raw]
    // GUARD: Upper-bound guard: else if *a1 > a3, clamp *a1 to the upper bound a3. (Hex-Rays reuses a2 as the write target in this branch via a2 = a3, a register-reuse artifact of the combined condition.) [function:0x0047F1F0, source:raw]
    // RETURN: Return the original *a1 value captured before clamping. [function:0x0047F1F0, source:raw]

    // Conservative worker pseudocode:
    //   int ClampByRange(int* value, int lower, int upper) {
    //       int original = *value;
    //       if (*value < lower) *value = lower;
    //       else if (*value > upper) *value = upper;
    //       return original;
    //   }
    // UNRESOLVED: The second branch reassigns a2 = a3 inside the condition before writing; Hex-Rays OR-combined the two range checks, so a2 is reused as the lower-bound write target in the first branch and the upper-bound write target in the second.
    // UNRESOLVED: No caller evidence constrains whether the clamp is used on counters, timing values or parameter slots; owner remains UNKNOWN.
}
