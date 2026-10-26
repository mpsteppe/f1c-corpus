// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A780
// Canonical corpus name: AIComputePassScore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIComputePassScore_0042a780.c

void UnknownObject::AIComputePassScore()
{
    // First solves opponent tire forces via TireForceSolver(a3[29], a3+30, a3[28], 16.0), then computes a passing/overtaking score as (a2 * a1[4417] + a1[4416]) * a1[4448] * a1[4431] * a3[33] and returns it. a1 is the AI state (float array), a3 is opponent vehicle data, a2 an input score term.
    // CALL: Solve opponent tire forces: TireForceSolver(a3[29], (int)(a3 + 30), a3[28], 16.0). [callee:0x004E8CE0, source:raw]
    // CALCULATION: Compute pass score: (a2 * a1[4417] + a1[4416]) * a1[4448] * a1[4431] * a3[33], combining input term a2, AI weight fields (a1[4417], a1[4416]) and AI scaling fields (a1[4448], a1[4431]) with opponent factor a3[33]. [field:this:0x00004500, field:this:0x00004504, field:this:0x0000453C, field:this:0x00004580, source:raw]
    // RETURN: Return the computed pass score. [source:raw]

    // Conservative worker pseudocode:
    //   TireForceSolver(a3[29], (int)(a3 + 30), a3[28], 16.0);
    //   return (a2 * a1[4417] + a1[4416]) * a1[4448] * a1[4431] * a3[33];
    // UNRESOLVED: Offsets into opponent data (a3[28], a3[29], a3+30, a3[33]) are not separately evidenced fields; covered by raw source only.
    // UNRESOLVED: Input term a2 (passed via ST0) has no independently evidenced role beyond the multiplicative/additive formula in the raw source.
    // UNRESOLVED: Field roles (pass-score weights versus scaling factors) in existing analysis are DERIVED prose, not packet evidence.
}
