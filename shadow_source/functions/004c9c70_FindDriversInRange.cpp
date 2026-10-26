// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9C70
// Canonical corpus name: FindDriversInRange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FindDriversInRange_004c9c70.c

void UnknownObject::FindDriversInRange()
{
    // Binary search over a sorted float key array rooted at this[104] with element count dword_5C329C. Returns a pointer to the first element whose key lies within [a2 - a3, a2 + a3] and writes the count of in-range elements to *a4. Returns null with *a4 = 0 when the count is zero. Callers are per-frame rendering and animation paths (WheelRenderObjectPerFrameUpdate, ParticleInstanceUpdate, ParticleEffectPhysics, ParticleSystemUpdateWithWindAndDamping).
    // GUARD: If the element count dword_5C329C is zero or negative, write 0 to *a4 and return null. [global:0x005C329C, source:raw]
    // CALCULATION: Compute the lower bound key v10 = a2 - a3. [source:raw]
    // LOOP: Binary search narrowing [v5, v4] to locate the first element whose key this[104 + i] is not below a2 - a3, reusing the same midpoint expression on both sides of the comparison. [function:0x004C9C70, global:0x005C329C, source:raw]
    // CALCULATION: Compute the upper bound key v11 = a2 + a3. [source:raw]
    // LOOP: Scan forward from the found index while the key this[104 + i] is below a2 + a3, counting elements in the range. [function:0x004C9C70, global:0x005C329C, source:raw]
    // ASSIGNMENT: Write the number of in-range elements v8 - v6 to *a4. [source:raw]
    // RETURN: Return the pointer to the first in-range element, this + v6 (float index). [function:0x004C9C70, source:raw]
    // RETURN: Return null (with *a4 = 0) when the count is zero or the search falls off the end of the array. [global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   float *FindDriversInRange(float *keys, float center, float radius, int *countOut) {
    //     int lo = 0, hi = dword_5C329C;
    //     if (dword_5C329C <= 0) { *countOut = 0; return 0; }
    //     float lower = center - radius;
    //     while (lo < hi) {
    //       int mid = (hi + lo) >> 1;
    //       if (lower >= keys[mid + 104]) lo = mid + 1;
    //       else hi = (hi + lo) >> 1;
    //     }
    //     if (lo < dword_5C329C) {
    //       float upper = center + radius;
    //       int end = lo;
    //       while (end < dword_5C329C && upper >= keys[end + 104]) ++end;
    //       *countOut = end - lo;
    //       return &keys[lo];
    //     }
    //     *countOut = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The key array is the float array rooted at this[104]; its byte displacement is derived from the source index and its semantic meaning (e.g. per-driver distance) is unconfirmed.
    // UNRESOLVED: The owning object is unknown; callers are rendering/animation paths so a spatial query role is plausible but not established.
    // UNRESOLVED: The sort invariant of the key array is assumed from the binary search pattern but not independently verified.
}
