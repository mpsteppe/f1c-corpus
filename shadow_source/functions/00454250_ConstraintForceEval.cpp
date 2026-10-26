// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00454250
// Canonical corpus name: ConstraintForceEval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstraintForceEval_00454250.c

void UnknownObject::ConstraintForceEval()
{
    // Evaluates a per-entry constraint force condition: selects a field-vector base on this (this+3464, or this+4484 when a3 is nonzero), computes (v[a2*4+920] - v[a2*4+96]) * v[a2*4+64] - input[a2], and returns 0 when the result is <= 0.34999999. Otherwise it records the outcome into the dword_7D1490 grid at index 216*a3 + 27*a2 (1056964608, i.e. float 0.5, when input[a2] >= 0.075000003, else 0) and returns 1.
    // GUARD: Select the field-vector base for this: default this+3464, switched to this+4484 when a3 is nonzero. [function:0x00454250, source:raw]
    // CALCULATION: Load three a2-indexed floats from the selected base (offsets +920, +96, +64 with a2 scaling by 4) and combine as (v[a2*4+920] - v[a2*4+96]) * v[a2*4+64]; the comparison thresholds are folded from read-only float globals flt_59E458 and flt_59EF78. [global:0x0059E458, global:0x0059EF78, source:raw]
    // CALCULATION: Subtract the per-entry float at a4 + 4*a2 from the combined product. [source:raw]
    // GUARD: If the resulting value is <= 0.34999999, return 0 (constraint considered satisfied). [source:raw]
    // ASSIGNMENT: Write into the dword_7D1490 grid at index 216*a3 + 27*a2: the value 1056964608 (0x3F000000, float 0.5) when the a4 + 4*a2 float is >= 0.075000003, otherwise 0. [global:0x007D1490, source:raw]
    // RETURN: Return 1 (constraint considered violated, outcome recorded). [source:raw]

    // Conservative worker pseudocode:
    //   base = this + 3464;
    //   if (a3) base = this + 4484;
    //   delta = (*(float*)&base[4*a2+920] - *(float*)&base[4*a2+96]) * *(float*)&base[4*a2+64] - *(float*)(a4 + 4*a2);
    //   if (delta <= 0.34999999) return 0;
    //   dword_7D1490[216*a3 + 27*a2] = (*(float*)(a4 + 4*a2) >= 0.075000003) ? 1056964608 : 0;
    //   return 1;
    // UNRESOLVED: Meaning of the a2-indexed float row (offsets +920, +96, +64 within the selected base) is unknown; it may hold per-joint or per-entry constraint force components.
    // UNRESOLVED: flt_59E458 and flt_59EF78 are read-only float globals folded into the threshold literals by Hex-Rays; the exact global-to-literal mapping is inferred, not evidenced.
    // UNRESOLVED: Layout and consumer of the dword_7D1490 grid (index 216*a3 + 27*a2) are unknown.
    // UNRESOLVED: Semantics of the input array a4 and of the a2/a3 selectors are unknown.
    // UNRESOLVED: No owner or self-identifying class evidence exists; the ABI lead name is LEGACY trust only.
}
