// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AC20
// Canonical corpus name: TextureSurfaceDimensionValidityCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureSurfaceDimensionValidityCheck_0049ac20.c

void UnknownObject::textureSurfaceDimensionValidityCheck()
{
    // Returns true only when both 16-bit texture surface dimensions are positive. Reads two 16-bit fields at +0x28 and +0x2A on the caller-owned object and returns their combined positivity. No callees, no globals, no branches beyond the two comparisons.
    // GUARD: Require the 16-bit value at this+0x28 (surface dimension 1) to be greater than 0. [field:this:0x00000028, guard:0]
    // GUARD: Require the 16-bit value at this+0x2A (surface dimension 2) to be greater than 0. [field:this:0x0000002A, guard:1]
    // CALCULATION: Conjoin both positivity tests; the result is the logical AND of the two guards. [guard:0, guard:1, source:raw]
    // RETURN: Return true only if both dimensions are positive, otherwise false. [function:0x0049AC20, source:raw]

    // Conservative worker pseudocode:
    //   return this[20] > 0 && this[21] > 0;
    // UNRESOLVED: Semantic roles of the two dimensions (which is height, which is width) are not established by packet evidence; naming in existing analysis is not an evidence-linked fact.
}
