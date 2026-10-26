// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005648B0
// Canonical corpus name: LinearInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinearInterpolation_005648b0.c

void UnknownObject::LinearInterpolation()
{
    // Straight-line arithmetic helper: reads a 32-bit value at object offset +20 as a base, reads a 32-bit value at offset +8 as a delta, and returns base + a2 * delta. The name matches the ABI label Linear_Interpolation: a2 acts as the interpolation factor interpolating between the two stored values. No branches, calls, or side effects.
    // CALCULATION: Read the base value: a 32-bit value at object offset +20. [source:raw]
    // CALCULATION: Read the delta value: a 32-bit value at object offset +8, scaled by interpolation factor a2. [source:raw]
    // CALCULATION: Combine the two: result = base + a2 * delta, a linear interpolation between the value at +20 and the value at +8. [source:raw]
    // RETURN: Return the interpolated result. [source:raw, function:0x005648B0]

    // Conservative worker pseudocode:
    //   int sub_5648B0(int obj, int factor) {
    //     return *(int*)(obj + 20) + factor * *(int*)(obj + 8);
    //   }
    // UNRESOLVED: The struct layout is unknown: offsets +8 (delta) and +20 (base) have no named field evidence in the packet.
    // UNRESOLVED: Object type and the meaning of a2 (time fraction, weighting, or arbitrary scale) are not established; the packet provides no field or owner facts.
}
