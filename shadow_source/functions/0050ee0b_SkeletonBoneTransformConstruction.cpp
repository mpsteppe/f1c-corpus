// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050EE0B
// Canonical corpus name: SkeletonBoneTransformConstruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SkeletonBoneTransformConstruction_0050ee0b.c

void UnknownObject::SkeletonBoneTransformConstruction()
{
    // Builds a 4x4 transformation matrix in the 16-float output a1 for a skeleton bone, returning the output pointer. With a parent transform a4 the function copies the parent's diagonal scale into a1 (a3 clear, root mode), or, when a3 is set (child mode), starts from identity, negates the offset vector a2 into the translation column a1[12..14], applies the transform thunk ThunkToFUN0050cba3 three times and re-adds a2. Without a4 it emits a full identity matrix. When the translate-modifier flag a6 is set the function re-applies the transform thunk while subtracting and then re-adding the offset a5 from the translation column, and finally, when a7 is present, adds a7 to the translation column.
    // GUARD: The parent-transform branch is taken only when the parent transform pointer a4 is non-null. [source:raw]
    // GUARD: Within the parent branch, the child/root mode is selected on the non-zero flag a3. [source:raw]
    // CALL: ThunkToIndirectCallViaDAT005d7860() dispatches an indirect call through the global function pointer before constructing the child-bone matrix. [callee:0x0050D857, source:raw]
    // GUARD: The child offset path is taken only when the offset vector a2 is non-null. [source:raw]
    // CALL: ThunkViaGlobalFunctionPointer() performs the first global-function-pointer invocation in the child path. [callee:0x0050CDF9, source:raw]
    // ASSIGNMENT: Initializes the matrix a1 to identity: the 12 off-diagonal and homogeneous entries a1[1..4], a1[6..9], a1[11] and a1[3] (offsets this+0x4 through this+0x2C) are set to 0.0 and the diagonal entries a1[0], a1[5], a1[10], a1[15] (offsets this+0x0, this+0x14, this+0x28, this+0x3C) are set to 1.0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x0000003C, source:raw]
    // CALCULATION: Negates the offset vector a2 into the translation column of the matrix: a1[12] = -a2[0], a1[13] = -a2[1], a1[14] = -a2[2]. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: ThunkToFUN0050cba3() is applied three times while the negated offset is in the translation column. [callee:0x0050CBB0, source:raw]
    // CALCULATION: Re-adds the offset vector a2 to the translation column: a1[12] += a2[0], a1[13] += a2[1], a1[14] += a2[2]. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: In the child path without an offset vector a2, ThunkViaGlobalFunctionPointer() is invoked once followed by two ThunkToFUN0050cba3() calls. [callee:0x0050CBB0, callee:0x0050CDF9, source:raw]
    // ASSIGNMENT: Root-mode construction from a parent transform a4: matrix a1 is zeroed except the diagonal, which takes the parent's diagonal scale a1[0] = a4[0], a1[5] = a4[1], a1[10] = ((_DWORD *)a4)[2], and the homogeneous entry a1[15] is set to 1.0. [field:this:0x00000000, field:this:0x00000014, field:this:0x00000028, field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Without a parent transform a4 the matrix a1 is initialized to identity: off-diagonal entries zeroed, diagonal a1[0], a1[5], a1[10] and a1[15] set to 1.0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // GUARD: The translate-modifier step runs only when the flag a6 is non-zero. [source:raw]
    // CALL: ThunkToIndirectCallViaDAT005d7860() dispatches the indirect call before the translate modifier step. [callee:0x0050D857, source:raw]
    // GUARD: The subtract/re-add translation path is taken only when the offset vector a5 is non-null. [source:raw]
    // CALCULATION: Subtracts the offset vector a5 from the translation column a1[12..14], applies ThunkToFUN0050cba3(), then re-adds a5 to the translation column. [callee:0x0050CBB0, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: When the translate modifier is set but a5 is null, a single ThunkToFUN0050cba3() call is applied instead. [callee:0x0050CBB0, source:raw]
    // CALCULATION: When the final offset vector a7 is present, adds it to the translation column: a1[12] += a7[0], a1[13] += a7[1], a1[14] += a7[2]. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // RETURN: Returns the output matrix pointer v7 (equal to a1 on every path). [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50EE0B(float *out, float *offset, int child_mode, float *parent, float *mod, int do_mod, float *final) {
    //     float *v7 = out;
    //     if (parent) {
    //       if (child_mode) {
    //         ThunkToIndirectCallViaDAT005d7860();
    //         if (offset) {
    //           ThunkViaGlobalFunctionPointer();
    //           zeroMatrix(out); identityDiagonal(out);
    //           out[12] = -offset[0]; out[13] = -offset[1]; out[14] = -offset[2];
    //           ThunkToFUN0050cba3(); ThunkToFUN0050cba3(); ThunkToFUN0050cba3();
    //           out[12] += offset[0]; out[13] += offset[1]; out[14] += offset[2];
    //         } else {
    //           ThunkViaGlobalFunctionPointer();
    //           ThunkToFUN0050cba3(); ThunkToFUN0050cba3();
    //         }
    //       } else {
    //         zeroMatrix(out);
    //         out[0] = parent[0]; out[5] = parent[1];
    //         *((_DWORD *)out + 10) = *((_DWORD *)parent + 2);
    //         out[15] = 1.0f;
    //       }
    //     } else {
    //       zeroMatrix(out); identityDiagonal(out);
    //     }
    //     if (do_mod) {
    //       ThunkToIndirectCallViaDAT005d7860();
    //       if (mod) {
    //         v7[12] -= mod[0]; v7[13] -= mod[1]; v7[14] -= mod[2];
    //         ThunkToFUN0050cba3();
    //         v7[12] += mod[0]; v7[13] += mod[1]; v7[14] += mod[2];
    //       } else {
    //         ThunkToFUN0050cba3();
    //       }
    //     }
    //     if (final) {
    //       v7[12] += final[0]; v7[13] += final[1]; v7[14] += final[2];
    //     }
    //     return v7;
    //   }
    // UNRESOLVED: The targets of ThunkToFUN0050cba3, ThunkViaGlobalFunctionPointer and ThunkToIndirectCallViaDAT005d7860 are indirect and their geometric meaning is unresolved.
    // UNRESOLVED: The owning skeleton class behind the 4x4 transform output buffer is unknown.
    // UNRESOLVED: The distinction between the offset a2 and the final a7 contributions to the translation column is unresolved.
}
