// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004349A0
// Canonical corpus name: TrackSplineExtrapolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSplineExtrapolation_004349a0.c

void UnknownObject::TrackSplineExtrapolation()
{
    // Builds track spline extrapolation data: zero-fills a local buffer, samples consecutive track spline points from the scene via sub_403CD0, stores midpoints, extrapolates two Catmull-Rom-style extension segments, negates the result and applies fixed per-component offsets, then hands the buffer to sub_457F90 with an element count derived from dword_5C329C.
    // ASSIGNMENT: Read dword_5C329C (vehicle count) and retain it to form the output element count (count + 5) passed to sub_457F90. [global:0x005C329C, source:raw]
    // LOOP: Zero-fill 109 consecutive 3-dword blocks of the local v25 buffer (327 dwords cleared before reuse as an output area). [source:raw]
    // LOOP: Loop 103 iterations: fetch track spline points at index and index+1 via sub_403CD0(dword_5EA2C0, ...) and store the averaged midpoint of each consecutive point pair as a 3-float entry into the v31 output array. [global:0x005EA2C0, callee:0x00403CD0, source:raw]
    // CALCULATION: Extrapolate the first spline extension: from the first stored points compute doubled-difference triplets (e.g. point - point + point patterns) written into the v25/v26/v27/v23/v24 area, producing additional points ahead of the sampled curve. [source:raw]
    // CALCULATION: Extrapolate the next spline extension from points v37..v42 into v43..v51 using the same doubled-difference pattern. [source:raw]
    // LOOP: Loop 109 iterations: negate each component of the v23 triplets and subtract 0.65 from one component per iteration, applying a fixed offset to the extrapolated points. [source:raw]
    // ASSIGNMENT: Apply final per-component adjustments to the extrapolation buffer: v29 -= 0.25, v26 -= 0.75, v24 -= 2.25. [source:raw]
    // CALL: Call sub_457F90 with the extrapolation buffer address and element count dword_5C329C + 5; return its result. [callee:0x00457F90, global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   int TrackSplineExtrapolation() {
    //     int count = dword_5C329C;
    //     zero_fill_3dword_blocks(v25, 109);
    //     for (int i = 0; i < 103; ++i) {
    //       sub_403CD0(dword_5EA2C0, i, v21, v22);
    //       sub_403CD0(dword_5EA2C0, i + 1, &v14, v22);
    //       store_midpoint(v31 + i * 3, v14, v21);
    //     }
    //     extrapolate_first_extension(v25, v31);
    //     extrapolate_second_extension(v43, v37);
    //     for (int i = 0; i < 109; ++i) { negate_triplet(v23 + i * 3); v23[i * 3 + 2] -= 0.65f; }
    //     v29 -= 0.25f; v26 -= 0.75f; v24 -= 2.25f;
    //     return sub_457F90(&v23, count + 5);
    //   }
    // UNRESOLVED: The five read-only float constants (flt_59E450, flt_59E7F8, flt_59E7FC, flt_59E8F8, flt_59EAD0) are read somewhere in the instruction stream but their use is not visible in the decompiled source text; they are likely physics/scaling factors folded into the spline math.
    // UNRESOLVED: The fixed adjustment constants (0.25, 0.75, 2.25, 0.65) and the exact geometric meaning of the two extension segments are DERIVED from arithmetic structure, not confirmed.
    // UNRESOLVED: The roles of v22 and v25 as input/output arrays of sub_403CD0 beyond midpoint accumulation are not fully resolved.
}
