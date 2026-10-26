// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DAB2
// Canonical corpus name: QuaternionNormalizeAndDecompose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionNormalizeAndDecompose_0050dab2.c

void UnknownObject::QuaternionNormalizeAndDecompose()
{
    // Normalizes a quaternion (x,y,z,w at this+0x0..0xC) and decomposes it: writes the normalized vector part into a2 and twice the scalar part (2*w) into a3. Falls back to an identity direction {1,0,0} and 0.0 when the squared norm is at or below the near-zero threshold 1.1754944e-38.
    // CALCULATION: Compute squared norm v3 = a1[0]^2 + a1[1]^2 + a1[2]^2 + a1[3]^2 from the four quaternion components (this+0x0..0xC). Matches the legacy abi label normalize-and-decompose. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, abi:lead, source:raw]
    // GUARD: Degenerate case: if v3 <= 1.1754944e-38 (near-zero float epsilon), take the identity fallback path. [source:raw]
    // ASSIGNMENT: Degenerate a2 path: if a2 is non-null, write identity vector {1.0, 0.0, 0.0}. [source:raw]
    // ASSIGNMENT: Degenerate a3 path: if a3 is non-null, write 0.0. [source:raw]
    // CALCULATION: Normalization path: v4 = 1.0/sqrt(v3); if a2 is non-null write normalized vector part a2 = v4 * a1[0..2] (this+0x0, +0x4, +0x8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: Non-degenerate a3 path: call FloatFunctionPassThrough() then write *a3 = 2.0 * a1[3] (twice the scalar part, this+0xC). [callee:0x005894A0, field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   v3 = a1[0]*a1[0] + a1[1]*a1[1] + a1[2]*a1[2] + a1[3]*a1[3]
    //   if (v3 <= 1.1754944e-38) {
    //       if (a2) { a2[0] = 1.0; a2[1] = 0.0; a2[2] = 0.0; }
    //       if (a3) *a3 = 0.0;
    //   } else {
    //       if (a2) { v4 = 1.0/sqrt(v3); a2[0] = v4*a1[0]; a2[1] = v4*a1[1]; a2[2] = v4*a1[2]; }
    //       if (a3) { FloatFunctionPassThrough(); *a3 = a1[3] + a1[3]; }
    //   }
    // UNRESOLVED: Packet lists globals flt_59E43C (0x0059E43C) and flt_5ADE40 (0x005ADE40) as reads, but the raw source text contains no reference to either; possibly decompiler-omitted operands (thresholds). Left unclaimed.
    // UNRESOLVED: FloatFunctionPassThrough() effect is unknown; may alter floating-point state or be a no-op.
    // UNRESOLVED: Output-parameter semantics of a2/a3 are inferred from the arithmetic, not grounded by packet evidence.
    // UNRESOLVED: The threshold literal 1.1754944e-38 is a float near-zero epsilon; the exact source constant is unknown.
}
