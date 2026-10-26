// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005219E1
// Canonical corpus name: Quaternion3DMath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Quaternion3DMath_005219e1.c

void UnknownObject::ComposeMultipleQuaternions3DNow()
{
    // 3DNow!/MMX multi-quaternion composition: loads up to four input quaternions (a5..a8), performs shortest-path sign-flip selection by comparing packed sum-vs-difference squared lengths (pfcmpgt + packsswb), negates selected inputs via pxor 0x8000000080000000, normalizes the a6 quaternion and two product pairs through reciprocal refinements (pfrcp/pfrcpit1/pfrcpit2, pfrsqrt/pfrsqit1) guarded by >=1.0 and magnitude threshold checks, calls SquareRootApproximation, sub_529700 and PackedFloatingPointMath for the normalization paths, and writes three output quaternions (a2, a3, a4); a4 receives the selected a7 components directly and is also the return value.
    // ASSIGNMENT: Load input quaternion components a5 (m64_u64, v109) and a6 (v110, v111) into temporaries. [source:raw, function:0x005219E1]
    // CALCULATION: Compute packed sum (v8,v9) and difference (v10,v11) of a5 and a6, then accumulate squared lengths (v13, v14) via pfadd/pfmul/pfacc. [source:raw]
    // CALCULATION: Compute packed sum (v15,v16) and difference (v17,v18) of a6 and a7; form v19 = pfcmpgt comparing the two accumulated squared-length pairs (sum-vs-difference). [source:raw]
    // GUARD: Convert v19 to integer v20 via packsswb + cvtsi64_si32; if bit 0 set, negate a5 components with pxor 0x8000000080000000 (shortest-path sign flip). [source:raw]
    // GUARD: If bit 0x10000 set, negate a7 components (v112, v113) with pxor 0x8000000080000000. [source:raw]
    // CALCULATION: Form sum (v22,v23) and difference (v24,v25) of selected a7 and a8, accumulate squared lengths (v26,v27), and compare to select a sign flip for a8 (v114,v115 negated when difference length exceeds sum length). [source:raw]
    // CALCULATION: Normalize a6: squared length v28/v29, reciprocal via pfrcp + pfrcpit1 + pfrcpit2, negated masked components v116/v118 guarded by pfcmpgt 0x80000000800000. [source:raw]
    // CALCULATION: Quaternion cross multiplication of selected a5 by normalized a6: build lane shuffles (v33,v34) and accumulate products v126/v130 via pfacc over pfsub/pfadd/pfmul terms. [source:raw]
    // CALCULATION: Quaternion cross multiplication of selected a7 (v112,v113) by normalized a6 producing v134/v136. [source:raw]
    // GUARD: Normalize first product pair: when high dword is below 1.0 (pfcmpge 0x3F8000003F800000 fails), call SquareRootApproximation(0, v12) then sub_529700(); if magnitude >= 0x3400000034000000 refine by reciprocal and scale v126/v130. [source:raw, callee:0x00529000, callee:0x00529700]
    // CALCULATION: Combine normalized components with the -0.25 factor (0xBE800000BE800000) into v127/v131, then refine a length reciprocal via pfacc/pfrsqrt/pfrsqit1. [source:raw]
    // CALL: Call PackedFloatingPointMath() to set up packed components for the first output composition. [source:raw, callee:0x005295E0]
    // GUARD: Guard on refined length (pfcmpge abs >= 0x3400000034000000) selecting the scale multiplier; assemble v124 from the packed multiplier pair. [source:raw]
    // ASSIGNMENT: Write output a2 (a2[0], a2[1]) via pfacc accumulation of the quaternion product of the selected a5 and a6 components. [source:raw, function:0x005219E1]
    // CALCULATION: Normalize selected a7 (v112,v113): squared length v65/v66, reciprocal refinement, masked negated v117/v119. [source:raw]
    // CALCULATION: Quaternion products of normalized a6 with selected a7 (v128/v132) and with selected a8 (v135/v137). [source:raw]
    // GUARD: Normalize the v128/v132 pair: when high dword is below 1.0, call SquareRootApproximation(0, v54) and sub_529700(); refine by reciprocal when magnitude >= 0x3400000034000000 and scale. [source:raw, callee:0x00529000, callee:0x00529700]
    // GUARD: Normalize the v135/v137 pair identically: SquareRootApproximation(0, v54), sub_529700(), and optional reciprocal refinement. [source:raw, callee:0x00529000, callee:0x00529700]
    // CALCULATION: Combine the second normalized pair with the -0.25 factor (0xBE800000BE800000) into v129/v133 and refine the reciprocal-sqrt length. [source:raw]
    // CALL: Call PackedFloatingPointMath() for the second output composition. [source:raw, callee:0x005295E0]
    // GUARD: Scale the second product by the refined multiplier when the length passes the threshold; assemble v125. [source:raw]
    // ASSIGNMENT: Write output a3 (a3[0], a3[1]) from the a7/a8 product composition. [source:raw, function:0x005219E1]
    // ASSIGNMENT: Write output a4 from the selected a7 components (v112, v113) and return a4. [source:raw, function:0x005219E1]
    // CALCULATION: Read ten packed qword globals (5AF918, 5AF928, 5AF938, 5AF940, 5AF948, 5AF950, 5AF970, 5AF988, 5AF9D0, 5B06E0) as 3DNow! constants/masks for sign flips, comparisons and normalization thresholds; their contents are not present in the packet. [global:0x005AF918, global:0x005AF928, global:0x005AF938, global:0x005AF940, global:0x005AF948, global:0x005AF950, global:0x005AF970, global:0x005AF988, global:0x005AF9D0, global:0x005B06E0]

    // Conservative worker pseudocode:
    //   // 3DNow!/MMX quaternion composition producing three outputs.
    //   // Inputs a5..a8 are quaternions (pairs of __m64), a1 is a scalar used in final packing.
    //   m64 *sub_5219E1(uint a1, m64 *a2, m64 *a3, m64 *a4, m64 *a5, m64 *a6, m64 *a7, m64 *a8) {
    //     // load a5/a6, choose sign flips by comparing sum-vs-difference squared lengths
    //     // normalize a6 and two product pairs with reciprocal refinement;
    //     // write a2 and a3 as composed quaternion products;
    //     // write a4 = selected a7; return a4.
    //   }
    // UNRESOLVED: Owner/class of the function is UNKNOWN (no callers in packet; packet owner trust UNKNOWN).
    // UNRESOLVED: Exact contents and roles of the ten global packed constants are not in the packet; only that they are read.
    // UNRESOLVED: Semantic mapping of a5..a8, scalar a1, and the three outputs a2/a3/a4 (quaternion results vs matrix/interpolation intermediates) is unconfirmed.
    // UNRESOLVED: sub_529700's precise computation is unknown; it appears in the normalization path alongside SquareRootApproximation.
    // UNRESOLVED: Why a4 returns the selected a7 components directly rather than a composed result is unresolved.
}
