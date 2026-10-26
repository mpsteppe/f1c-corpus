// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC9B0
// Canonical corpus name: sub_4BC9B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC9B0_004bc9b0.c

void UnknownObject::GridAlignmentAndJumpStartValidator()
{
    // Validates grid-position alignment and detects jump-start violations. Dereferences `this` to the vehicle float base, computes a velocity/acceleration magnitude squared (v12), transforms orientation state through SingleFunctionDispatch_10e0 / EulerToRotationMatrix / F_3DTransformWithMatrixMultiplication, derives displacement (v15-v17) and two dot products (v13 against a negated vector, v14 against orientation-matrix columns). When a2 (penalty-check mode) is set and thresholds are violated, applies a StopGoPenaltyHandler or DisqualificationHandler jump-start penalty if global dword_7CEF84 is set and the penalty-state field (obj+0x32C8) is not already 1. When aligned and a3 is set, copies a 'not lined up' string into the message buffer and invokes ShortComputation_bde0; otherwise renders the message via TextLineWrappingAndRendering. Returns char (0/1).
    // ASSIGNMENT: v4 = (float*)*this; v5 = v4 + 3: dereference `this` to the vehicle float array base and an offset pointer. [field:this:0x00000000, source:raw]
    // CALCULATION: v12 = v4[3390]^2 + v4[3391]^2 + v4[3392]^2: velocity/acceleration magnitude squared from obj fields 0x34F8/0x34FC/0x3500. [field:obj:0x000034F8, field:obj:0x000034FC, field:obj:0x00003500, source:raw]
    // GUARD: if (!a2 && v12 > 1.0) return 0: early exit when not in penalty-check mode and speed magnitude squared exceeds 1.0. [source:raw]
    // CALL: SingleFunctionDispatch_10e0(v4, v22, v23): dispatch/state helper writing a 3-vector and 12-byte buffer. [callee:0x004D10E0, source:raw]
    // CALL: EulerToRotationMatrix(v23, v25): convert Euler state into a rotation matrix (v25). [callee:0x00566E40, source:raw]
    // ASSIGNMENT: v18 = -v26; v19 = -v27; v20 = -v28: negate the rotation-derived vector components. [source:raw]
    // CALL: F_3DTransformWithMatrixMultiplication(v21, v24): transform vector v21 using matrix v24. [callee:0x004EFB20, source:raw]
    // CALCULATION: v15 = v21[0]-v22[0]; v16 = v21[1]-v22[1]; v17 = v21[2]-v22[2]: displacement between transformed and reference vectors. [source:raw]
    // CALCULATION: v13 = v20*v17 + v19*v16 + v15*v18: dot product of displacement with the negated rotation vector. [source:raw]
    // CALCULATION: v14 = -(v5[3380]*v20 + v5[3377]*v19 + v5[3374]*v18): dot product against orientation-matrix column elements at obj 0x34DC/0x34D0/0x34C4. [field:obj:0x000034DC, field:obj:0x000034D0, field:obj:0x000034C4, source:raw]
    // GUARD: Branch on a2: penalty-check path (a2 != 0) vs alignment path (a2 == 0). [source:raw]
    // GUARD: If a2: violation when v12 > 1.0 || displacementSq > 5.0625 || v13 > 1.5 || v14 < 0.75. [source:raw]
    // GUARD: Within violation: if (dword_7CEF84 && obj+0x32C8 penalty-state != 1) then penalize; guard:0 evidence is the obj+0x32C8 != 1 check. [global:0x007CEF84, field:obj:0x000032C8, guard:0, source:raw]
    // CALL: If displacementSq <= 225.0: StopGoPenaltyHandler(this, aJumpedStart, 10); else DisqualificationHandler(this, aJumpedStart): jump-start penalties with the 'jumped start' message global. [callee:0x004BBD60, callee:0x004BC0E0, global:0x005C2700, source:raw]
    // RETURN: return 0 after the penalty path (whether or not penalty was eligible). [source:raw]
    // CALCULATION: v7 = displacementSq; if (v7 <= 3.0625 && v13 <= 1.25 && v14 >= 0.85000002) goto LABEL_17 (aligned case). [source:raw]
    // GUARD: LABEL_17: if (a3) show 'not lined up' status via message buffer; else fall through to the aligned-not-flagged return. [source:raw]
    // LOOP: BinarySearchInStringTable(byte_5EC4C0, aNotLinedUpProp, byte_5EC4CC); if found, copy the aNotLinedUpProp string into byte_5EC4CC byte-by-byte until NUL. [callee:0x00423A00, global:0x005EC4C0, global:0x005D2598, global:0x005EC4CC, source:raw]
    // CALL: ShortComputation_bde0(&dword_7CD204, byte_5EC4CC, 0): status/short computation using the message buffer. [callee:0x0045BDE0, global:0x007CD204, source:raw]
    // RETURN: return 1: aligned/validated case. [source:raw]
    // GUARD: if (!a3 || v7 >= 400.0) return 0: not-aligned case without message, or displacement too large. [source:raw]
    // CALL: TextLineWrappingAndRendering(&dword_7CD204, byte_5EC4CC, 2, 16909060): render the 'not lined up' message buffer. [callee:0x0045BD10, global:0x007CD204, global:0x005EC4CC, source:raw]
    // RETURN: return 0: default/not-aligned result. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = *this; v5 = v4 + 3;
    //   v12 = v4[3390]*v4[3390] + v4[3391]*v4[3391] + v4[3392]*v4[3392];
    //   if (!a2 && v12 > 1.0) return 0;
    //   SingleFunctionDispatch_10e0(v4, v22, v23);
    //   EulerToRotationMatrix(v23, v25);
    //   v18 = -v26; v19 = -v27; v20 = -v28;
    //   F_3DTransformWithMatrixMultiplication(v21, v24);
    //   v15 = v21[0]-v22[0]; v16 = v21[1]-v22[1]; v17 = v21[2]-v22[2];
    //   v13 = v20*v17 + v19*v16 + v15*v18;
    //   v14 = -(v5[3380]*v20 + v5[3377]*v19 + v5[3374]*v18);
    //   if (a2) {
    //     if (v12 > 1.0 || v17*v17+v16*v16+v15*v15 > 5.0625 || v13 > 1.5 || v14 < 0.75) {
    //       if (dword_7CEF84 && ((DWORD*)v5)[3247] != 1) {
    //         if (v17*v17+v16*v16+v15*v15 <= 225.0) StopGoPenaltyHandler(this, aJumpedStart, 10);
    //         else DisqualificationHandler(this, aJumpedStart);
    //         return 0;
    //       }
    //       return 0;
    //     }
    //     goto ALIGNED;
    //   }
    //   if (v7 <= 3.0625 && v13 <= 1.25 && v14 >= 0.85000002) {
    //   ALIGNED:
    //     if (a3) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aNotLinedUpProp, byte_5EC4CC))
    //         copy aNotLinedUpProp into byte_5EC4CC;
    //       ShortComputation_bde0(&dword_7CD204, byte_5EC4CC, 0);
    //     }
    //     return 1;
    //   }
    //   if (!a3 || v7 >= 400.0) return 0;
    //   if (BinarySearchInStringTable(byte_5EC4C0, aNotLinedUpProp, byte_5EC4CC))
    //     copy aNotLinedUpProp into byte_5EC4CC;
    //   TextLineWrappingAndRendering(&dword_7CD204, byte_5EC4CC, 2, 16909060);
    //   return 0;
    // UNRESOLVED: flt_59E43C, flt_59E7FC, flt_59E8A4, flt_59E908, flt_59E920, flt_59F124, flt_5ACD70, flt_5ACD74, flt_5ACD78 and dword_8ACEE0 are listed as read by this function in the deterministic fact store but do not appear in the raw decompiled body; likely constant/threshold globals of inlined computations or analysis artifacts. No operation can be grounded on them from the raw source.
    // UNRESOLVED: Exact geometric meaning of v13 (dot with negated vector) and v14 (dot with orientation-matrix columns) is inferred, not proven.
    // UNRESOLVED: Literal thresholds (1.0, 5.0625, 1.5, 0.75, 3.0625, 1.25, 0.85, 225.0, 400.0) have no named constants in raw source.
    // UNRESOLVED: StopGoPenaltyHandler third argument literal 10 meaning unknown.
    // UNRESOLVED: a3 flag role: when set it emits the 'not lined up' status message; exact UI/status semantics unknown.
    // UNRESOLVED: Callers sub_4C6B60, sub_4D2170, PitCloseTeamReadyCheck, PitTimer are recorded but their call context is not part of this packet.
}
