## MatrixFactorizeLDLT_00575bbd — Block-Structured LDL^T Factorization for Vehicle Dynamics Solver

**Summary:** Performs a block-structured LDL^T factorization (symmetric indefinite factorization, a variant of Cholesky decomposition) on the vehicle dynamics constraint system matrix. Iterates through each pivot block: computes the reciprocal of the diagonal block, scales the corresponding column to form the L factor, and subtracts rank-1 outer-product updates from the remaining submatrix. All data resides in global double-precision arrays; no parameters, no callees, pure numerical computation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d2120 | dbl_8D2120 | R | ConstraintMatrix00 [DERIVED]; (1,1) diagonal element — used as first pivot for reciprocal scaling |
| 008d2128 | dbl_8D2128 | R | LDLTSolverWorkspace [DERIVED]; L factor column 1 — scaled output of first pivot column |
| 008d2130 | dbl_8D2130 | R | SolverMatrixA [DERIVED]; matrix element used in rank-1 update during block 2 factorization |
| 008d2198 | unk_8D2198 | R | DynSolver_WS_8D2198 [DERIVED]; workspace block — receives scaled factor entries for subsequent rows |
| 008d21c8 | dbl_8D21C8 | RW | Cholesky_WorkspaceBase [DERIVED]; D factor diagonal entry — computed as reciprocal-scaled from dbl_8D2FA8 |
| 008d21d0 | dbl_8D21D0 | R | DynSolver_Matrix_8D21D0 [DERIVED]; off-diagonal block element used in rank-1 updates |
| 008d21d8 | dbl_8D21D8 | RW | DynamicsSolver_DiagBlock1 [DERIVED]; first diagonal block after rank-1 update: A22 -= L21 * D1 * L21^T |
| 008d21e0 | dbl_8D21E0 | R | Dbl_8D21E0_Solver [DERIVED]; L factor column 2 entry — computed by scaling with reciprocal of updated diagonal |
| 008d2248 | unk_8D2248 | R | LDLT_FactorWorkspace_8D2248 [DERIVED]; workspace — receives scaled factor entries for block 2 |
| 008d2278 | dbl_8D2278 | RW | DynSolver_WriteDouble_CH [DERIVED]; D factor diagonal entry for block 2 |
| 008d2280 | dbl_8D2280 | R | DynamicsBlockElement_8D2280 [DERIVED]; cross-block matrix element for rank-1 update |
| 008d2288 | dbl_8D2288 | RW | DynSolverElem_1_2 [DERIVED]; updated matrix element after block 2 rank-1 subtraction |
| 008d2290 | dbl_8D2290 | RW | DynamicsMatrix_2_2 [DERIVED]; diagonal element for block 3 — pivot for third factorization step |
| 008d2298 | unk_8D2298 | R | DynSolverBlock_2298 [DERIVED]; workspace — receives scaled L factor for block 3 |
| 008d22f8 | unk_8D22F8 | R | Dynamics_Workspace_8D22F8 [DERIVED]; workspace — scaled factor entries for subsequent rows, block 3 |
| 008d2328 | dbl_8D2328 | RW | CholeskyFactorOut1 [DERIVED]; D factor diagonal for block 3 |
| 008d2330 | dbl_8D2330 | R | DynSolver_MatrixBlock3 [DERIVED]; off-diagonal block for rank-1 update |
| 008d2338 | dbl_8D2338 | RW | DynamicsSolverBlock_8D2338 [DERIVED]; updated diagonal after block 3 factorization |
| 008d2340 | dbl_8D2340 | RW | SolverBlock_8D2340 [DERIVED]; updated matrix element after block 3 rank-1 subtraction |
| 008d2348 | dbl_8D2348 | RW | DynamicsBlockElement_8D2348 [DERIVED]; pivot diagonal for block 4 |
| 008d2350 | unk_8D2350 | R | Unknown_Struct_Cholesky [DERIVED]; workspace — scaled L factor for block 4 |
| 008d23a8 | unk_8D23A8 | R | DynamicsSolver_D23A8 [DERIVED]; workspace — scaled factor for subsequent rows, block 4 |
| 008d23d8 | dbl_8D23D8 | RW | LDLTFactorWorkspaceA [DERIVED]; D factor diagonal for block 4 |
| 008d23e0 | dbl_8D23E0 | R | DynamicsMatrix_Block4 [DERIVED]; off-diagonal element for rank-1 update |
| 008d23e8 | dbl_8D23E8 | RW | DynMatrix_8D23E8 [DERIVED]; updated diagonal after block 4 factorization |
| 008d23f0 | dbl_8D23F0 | RW | Dynamics_Block23E0_Elem [DERIVED]; updated element after rank-1 subtraction |
| 008d23f8 | dbl_8D23F8 | RW | DynSolver_MatrixBlock4b [DERIVED]; updated element after rank-1 |
| 008d2400 | dbl_8D2400 | RW | DynamicsSolverElement4_0 [DERIVED]; pivot diagonal for block 5 |
| 008d2408 | unk_8D2408 | R | LDLTSolverDataBlock [DERIVED]; workspace — scaled L factor for block 5 |
| 008d2458 | unk_8D2458 | R | Unk_DynamicsSolver2 [DERIVED]; workspace — scaled factor for subsequent rows, block 5 |
| 008d2488 | dbl_8D2488 | RW | DynSolver_WS_8D2488 [DERIVED]; D factor diagonal for block 5 |
| 008d2490 | dbl_8D2490 | R | DynamicsBlock_4 [DERIVED]; off-diagonal element for rank-1 update |
| 008d2498 | dbl_8D2498 | RW | ConstraintMatrix_8D2498 [DERIVED]; updated diagonal after block 5 factorization |
| 008d24a0 | dbl_8D24A0 | RW | DynamicsBlock_8D24A0 [DERIVED]; updated element after rank-1 |
| 008d24a8 | dbl_8D24A8 | RW | DynamicsMatrix_Block8 [DERIVED]; updated element after rank-1 |
| 008d24b0 | dbl_8D24B0 | RW | Dyn_SolverBlock_24B0 [DERIVED]; updated element after rank-1 |
| 008d24b8 | dbl_8D24B8 | RW | DynamicsBlock_24B8 [DERIVED]; pivot diagonal for block 6 |
| 008d24c0 | unk_8D24C0 | R | CholeskyMatrixBlock [DERIVED]; workspace — scaled L factor for block 6 |
| 008d2508 | unk_8D2508 | R | Cholesky_IndexArray [DERIVED]; workspace — scaled factor for subsequent rows, block 6 |
| 008d2538 | dbl_8D2538 | RW | LDLTWorkspaceB [DERIVED]; D factor diagonal for block 6 |
| 008d2540 | dbl_8D2540 | R | ConstraintMatrix_Body0_DOF5 [DERIVED]; off-diagonal element for rank-1 update |
| 008d2548 | dbl_8D2548 | RW | DynSolver_Matrix_8D2548 [DERIVED]; updated diagonal after block 6 |
| 008d2550 | dbl_8D2550 | RW | SolverBlock_8D2550 [DERIVED]; updated element after rank-1 |
| 008d2558 | dbl_8D2558 | RW | DynamicsBlock_2558 [DERIVED]; updated element after rank-1 |
| 008d2560 | dbl_8D2560 | RW | DynSolverElem_5_2 [DERIVED]; updated element after rank-1 |
| 008d2568 | dbl_8D2568 | RW | DynSolverMatrixElem_8D2568 [DERIVED]; updated element after rank-1 |
| 008d2570 | dbl_8D2570 | RW | Dyn_SolverBlock_2570 [DERIVED]; pivot diagonal for block 7 |
| 008d2578 | unk_8D2578 | R | LDLT_FactorWorkspace_8D2578 [DERIVED]; workspace — scaled L factor for block 7 |
| 008d25b8 | unk_8D25B8 | R | DynSolver_MatrixBlock_CH [DERIVED]; workspace — scaled factor for subsequent rows, block 7 |
| 008d25e8 | dbl_8D25E8 | RW | DynamicsFactorWorkspace_8D25E8 [DERIVED]; D factor diagonal for block 7 |
| 008d25f0 | dbl_8D25F0 | R | DynamicsMatrixBlock4 [DERIVED]; off-diagonal element for rank-1 |
| 008d25f8 | dbl_8D25F8 | RW | DynamicsSolver_DiagBlock5 [DERIVED]; updated diagonal after block 7 |
| 008d2600 | dbl_8D2600 | RW | DynamicsSolverElement2_2 [DERIVED]; updated element after rank-1 |
| 008d2608 | dbl_8D2608 | RW | DynSolverMatrixElem_8D2608 [DERIVED]; updated element after rank-1 |
| 008d2610 | dbl_8D2610 | RW | DynamicsSolverBlock_8D2610 [DERIVED]; updated element after rank-1 |
| 008d2618 | dbl_8D2618 | RW | DynamicsMatrixBlock8 [DERIVED]; updated element after rank-1 |
| 008d2620 | dbl_8D2620 | RW | DynSolverElem_6_0 [DERIVED]; updated element after rank-1 |
| 008d2628 | dbl_8D2628 | RW | DynamicsMatrix_Block10 [DERIVED]; pivot diagonal for block 8 |
| 008d2630 | dbl_8D2630 | RW | SolverMatrixDiag [DERIVED]; D factor off-diagonal for block 8 |
| 008d2638 | dbl_8D2638 | RW | Dynamics_Factor_D2638 [DERIVED]; D factor off-diagonal for block 8 |
| 008d2668 | unk_8D2668 | R | DynSolverBlock_2668 [DERIVED]; workspace — scaled factor for subsequent rows, block 8 |
| 008d2698 | dbl_8D2698 | RW | CholeskyFactorOut2 [DERIVED]; D factor diagonal for block 8 |
| 008d26a0 | dbl_8D26A0 | R | DynSolver_Block5_Element00 [DERIVED]; off-diagonal for rank-1 |
| 008d26a8 | dbl_8D26A8 | RW | DynamicsBlockElement_8D26A8 [DERIVED]; updated diagonal after block 8 |
| 008d26b0 | dbl_8D26B0 | RW | Dyn_SolverBlock_26B0 [DERIVED]; updated element after rank-1 |
| 008d26b8 | dbl_8D26B8 | RW | DynamicsMatrixBlock7 [DERIVED]; updated element after rank-1 |
| 008d26c0 | dbl_8D26C0 | RW | DynMatrix_8D26C0 [DERIVED]; updated element after rank-1 |
| 008d26c8 | dbl_8D26C8 | RW | DynSolver_Block5_Element6 [DERIVED]; updated element after rank-1 |
| 008d26d0 | dbl_8D26D0 | RW | DynamicsSolverBlock_8D26D0 [DERIVED]; updated element after rank-1 |
| 008d26d8 | dbl_8D26D8 | RW | DynamicsBlock_26D8 [DERIVED]; updated element after rank-1 |
| 008d26e0 | dbl_8D26E0 | RW | DynamicsBlock_8D26E0 [DERIVED]; pivot diagonal for block 9 |
| 008d26e8 | dbl_8D26E8 | RW | DynamicsSolver_D26E8 [DERIVED]; D factor off-diagonal for block 9 |
| 008d2718 | unk_8D2718 | R | Unknown_Struct_Cholesky2 [DERIVED]; workspace — scaled factor for subsequent rows, block 9 |
| 008d2748 | dbl_8D2748 | RW | LDLTFactorWorkspaceB [DERIVED]; D factor diagonal for block 9 |
| 008d2750 | dbl_8D2750 | R | DynamicsMatrix_0_9 [DERIVED]; off-diagonal for rank-1 |
| 008d2758 | dbl_8D2758 | RW | DynSolver_MatrixBlock8b [DERIVED]; updated diagonal after block 9 |
| 008d2760 | dbl_8D2760 | RW | DynSolverElem_7_0 [DERIVED]; updated element after rank-1 |
| 008d2768 | dbl_8D2768 | RW | DynSolver_Block6_Element13 [DERIVED]; updated element after rank-1 |
| 008d2770 | dbl_8D2770 | RW | ConstraintMatrix_8D2770 [DERIVED]; updated element after rank-1 |
| 008d2778 | dbl_8D2778 | RW | DynamicsMatrix_2_3 [DERIVED]; updated element after rank-1 |
| 008d2780 | dbl_8D2780 | RW | DynMatrix_8D2780 [DERIVED]; updated element after rank-1 |
| 008d2788 | dbl_8D2788 | RW | DynSolverMatrixElem_8D2788 [DERIVED]; updated element after rank-1 |
| 008d2790 | dbl_8D2790 | RW | SolverBlock_8D2790 [DERIVED]; updated element after rank-1 |
| 008d2798 | dbl_8D2798 | RW | ConstraintMatrix_8D2798 [DERIVED]; pivot diagonal for block 10 |
| 008d27c8 | unk_8D27C8 | R | LDLTSolverScratch [DERIVED]; workspace — scaled factor for subsequent rows, block 10 |
| 008d27f8 | dbl_8D27F8 | RW | Dbl_DynamicsSolverWk25 [DERIVED]; D factor diagonal for block 10 |
| 008d2800 | dbl_8D2800 | R | SolverBlock_8D2800 [DERIVED]; pivot diagonal for block 11 (second major block group, body 2) |
| 008d2808 | dbl_8D2808 | R | DynSolver_WS_8D2808 [DERIVED]; L factor column entry scaled by reciprocal |
| 008d2870 | unk_8D2870 | R | CholeskyMatrixBlock2 [DERIVED]; workspace — scaled factor for subsequent rows, block 11 |
| 008d2898 | dbl_8D2898 | R | DynamicsSolverBias1 [DERIVED]; off-diagonal for cross-block rank-1 |
| 008d28a0 | dbl_8D28A0 | RW | Dyn_SolverBlock_28A0 [DERIVED]; updated diagonal for block 11 |
| 008d28a8 | unk_8D28A8 | R | LDLT_FactorWorkspace_8D28A8 [DERIVED]; workspace — scaled L factor for block 11 |
| 008d2908 | unk_8D2908 | R | DynSolver_MatrixBlock2_CH [DERIVED]; workspace — scaled factor for subsequent rows |
| 008d2930 | dbl_8D2930 | R | DynSolverBlock_3_0 [DERIVED]; off-diagonal for rank-1 |
| 008d2938 | dbl_8D2938 | RW | DynSolverMatrixElem_8D2938 [DERIVED]; updated diagonal after block 11 |
| 008d2940 | dbl_8D2940 | RW | Dyn_SolverBlock_2940 [DERIVED]; pivot diagonal for block 12 |
| 008d2948 | dbl_8D2948 | RW | DynSolverFactorOut [DERIVED]; D factor off-diagonal for block 12 |
| 008d2950 | dbl_8D2950 | RW | SolverRHSVector [DERIVED]; D factor off-diagonal for block 12 |
| 008d29a0 | unk_8D29A0 | R | DynamicsFactorBlock_8D29A0 [DERIVED]; workspace — scaled factor |
| 008d29c8 | dbl_8D29C8 | R | DynamicsSolverBlock_8D29C8 [DERIVED]; off-diagonal for rank-1 |
| 008d29d0 | dbl_8D29D0 | RW | DynamicsMatrixBlock10 [DERIVED]; updated diagonal after block 12 |
| 008d29d8 | dbl_8D29D8 | RW | DynSolverElem_3_3 [DERIVED]; updated element after rank-1 |
| 008d29e0 | dbl_8D29E0 | RW | DynamicsMatrix_Block11 [DERIVED]; pivot diagonal for block 13 |
| 008d29e8 | dbl_8D29E8 | RW | CholeskyWorkspaceC [DERIVED]; D factor off-diagonal for block 13 |
| 008d2a38 | unk_8D2A38 | R | CholeskyWorkspace [DERIVED]; workspace |
| 008d2a60 | dbl_8D2A60 | R | DynMatrix_8D2A60 [DERIVED]; off-diagonal for rank-1 |
| 008d2a68 | dbl_8D2A68 | RW | DynSolver_Block9_Element? [DERIVED]; updated diagonal after block 13 |
| 008d2a70 | dbl_8D2A70 | RW | DynamicsSolverBlock_8D2A70 [DERIVED]; updated element after rank-1 |
| 008d2a78 | dbl_8D2A78 | RW | DynamicsBlock_2A78 [DERIVED]; updated element after rank-1 |
| 008d2a80 | dbl_8D2A80 | RW | DynamicsBlock_8D2A80 [DERIVED]; pivot diagonal for block 14 |
| 008d2ad0 | unk_8D2AD0 | R | DynamicsSolver_D2AD0 [DERIVED]; workspace |
| 008d2af8 | dbl_8D2AF8 | R | SolverBlock_8D2AF8 [DERIVED]; off-diagonal for rank-1 (beginning of third body block group) |
| 008d2b00 | dbl_8D2B00 | RW | DynamicsMatrix_Block12 [DERIVED]; updated diagonal |
| 008d2b08 | dbl_8D2B08 | RW | DynamicsSolverBlock_8D2B08 [DERIVED]; updated element after rank-1 |
| 008d2b10 | dbl_8D2B10 | RW | DynamicsMatrix_2_7 [DERIVED]; updated element after rank-1 |
| 008d2b18 | dbl_8D2B18 | RW | DynSolver_Matrix_8D2B18 [DERIVED]; updated element after rank-1 |
| 008d2b20 | dbl_8D2B20 | RW | SolverBlock_8D2B20 [DERIVED]; updated element after rank-1 |
| 008d2b28 | dbl_8D2B28 | RW | ConstraintMatrix_8D2B28 [DERIVED]; updated element after rank-1 |
| 008d2b30 | dbl_8D2B30 | RW | DynamicsMatrixBlock9 [DERIVED]; updated element after rank-1 |
| 008d2b38 | dbl_8D2B38 | RW | DynamicsSolverElement_3_X [DERIVED]; updated element after rank-1 |
| 008d2b40 | dbl_8D2B40 | RW | DynSolver_Matrix_8D2B40 [DERIVED]; updated element after rank-1 |
| 008d2b70 | dbl_8D2B70 | RW | DynamicsMatrix_Block13 [DERIVED]; pivot diagonal for block 15 |
| 008d2b78 | dbl_8D2B78 | RW | LDLTSolverWorkspaceDouble [DERIVED]; D factor off-diagonal |
| 008d2b80 | dbl_8D2B80 | RW | LDLTSolverResultBlock [DERIVED]; D factor off-diagonal |
| 008d2ba0 | dbl_8D2BA0 | RW | Dbl_DynamicsSolverWk26 [DERIVED]; D factor off-diagonal |
| 008d2bb8 | unk_8D2BB8 | R | LDLTFactorBlockPtr [DERIVED]; workspace — scaled factor |
| 008d2c08 | dbl_8D2C08 | R | DynamicsMatrix_DiagBlock [DERIVED]; off-diagonal reference for cross-body rank-1 updates |
| 008d2c10 | dbl_8D2C10 | RW | DynamicsBlock_2C10 [DERIVED]; updated element |
| 008d2c18 | dbl_8D2C18 | RW | DynMatrix_8D2C18 [DERIVED]; updated element |
| 008d2c20 | dbl_8D2C20 | RW | SolverBlock_8D2C20 [DERIVED]; updated element |
| 008d2c28 | dbl_8D2C28 | RW | DynamicsSolver_BlockCol4 [DERIVED]; updated element |
| 008d2c30 | dbl_8D2C30 | RW | Dynamics_Block2C08_Elem2 [DERIVED]; updated element |
| 008d2c38 | dbl_8D2C38 | RW | DynSolver_Matrix_8D2C38 [DERIVED]; updated element |
| 008d2c40 | dbl_8D2C40 | RW | DynSolver_Block11_Element8 [DERIVED]; updated element |
| 008d2c48 | dbl_8D2C48 | RW | Dyn_SolverBlock_2C48 [DERIVED]; updated element |
| 008d2c50 | dbl_8D2C50 | RW | DynamicsSolver_BlockCol6 [DERIVED]; updated element |
| 008d2c80 | dbl_8D2C80 | RW | DynamicsBlock_8_80 [DERIVED]; updated element |
| 008d2c88 | dbl_8D2C88 | RW | DynSolver_Block11_Element13 [DERIVED]; pivot diagonal for block 16 |
| 008d2c90 | dbl_8D2C90 | RW | FactorWorkspaceDbl1 [DERIVED]; D factor off-diagonal |
| 008d2cb0 | dbl_8D2CB0 | RW | CholeskyMatrixTemp [DERIVED]; D factor off-diagonal |
| 008d2cc8 | unk_8D2CC8 | R | DynSolver_WS_8D2CC8 [DERIVED]; workspace |
| 008d2d18 | dbl_8D2D18 | R | DynamicsBlock_8D2D18 [DERIVED]; off-diagonal for rank-1 |
| 008d2d20 | dbl_8D2D20 | RW | DynSolverMatrixElem_8D2D20 [DERIVED]; updated diagonal |
| 008d2d28 | dbl_8D2D28 | RW | ConstraintMatrix_8D2D28 [DERIVED]; updated element |
| 008d2d30 | dbl_8D2D30 | RW | Dynamics_Block2D18_Elem [DERIVED]; updated element |
| 008d2d38 | dbl_8D2D38 | RW | DynamicsBlockElement_8D2D38 [DERIVED]; updated element |
| 008d2d40 | dbl_8D2D40 | RW | DynamicsBlock_8D2D40 [DERIVED]; updated element |
| 008d2d48 | dbl_8D2D48 | RW | DynamicsSolver_BlockCol5 [DERIVED]; updated element |
| 008d2d50 | dbl_8D2D50 | RW | DynamicsMatrix_3_1 [DERIVED]; updated element |
| 008d2d58 | dbl_8D2D58 | RW | DynSolverElem_8_3 [DERIVED]; updated element |
| 008d2d60 | dbl_8D2D60 | RW | DynamicsBlockElement_8D2D60 [DERIVED]; updated element |
| 008d2d90 | dbl_8D2D90 | RW | ConstraintMatrix_Body3_Row6 [DERIVED]; updated element |
| 008d2d98 | dbl_8D2D98 | RW | DynamicsSolver_BlockCol7 [DERIVED]; updated element |
| 008d2da0 | dbl_8D2DA0 | RW | ConstraintMatrix_8D2DA0 [DERIVED]; pivot diagonal for block 17 |
| 008d2dc0 | dbl_8D2DC0 | RW | LDLT_Work_23 [DERIVED]; D factor off-diagonal |
| 008d2dd8 | unk_8D2DD8 | R | LDLTWorkArray [DERIVED]; workspace |
| 008d2e28 | dbl_8D2E28 | R | DynamicsSolverBias2 [DERIVED]; pivot diagonal for block 18 (fourth body block group) |
| 008d2e30 | dbl_8D2E30 | RW | DynSolver_WriteDouble2_CH [DERIVED]; D factor off-diagonal |
| 008d2e38 | dbl_8D2E38 | RW | DynamicsFactorWorkspace_8D2E38 [DERIVED]; D factor off-diagonal |
| 008d2e48 | dbl_8D2E48 | RW | DynSolverFactorOut2 [DERIVED]; D factor off-diagonal |
| 008d2e50 | dbl_8D2E50 | RW | SolverSolutionVec [DERIVED]; D factor off-diagonal |
| 008d2e80 | unk_8D2E80 | R | LDLT_FactorWorkspace_8D2E80 [DERIVED]; workspace |
| 008d2ea8 | dbl_8D2EA8 | R | Dyn_SolverBlock_2EA8 [DERIVED]; off-diagonal |
| 008d2eb0 | dbl_8D2EB0 | RW | ConstraintMatrix_8D2EB0 [DERIVED]; updated diagonal |
| 008d2eb8 | dbl_8D2EB8 | RW | CholeskyFactorOut3 [DERIVED]; D factor off-diagonal |
| 008d2ec8 | dbl_8D2EC8 | RW | CholeskyWorkspaceD [DERIVED]; D factor off-diagonal |
| 008d2ed0 | dbl_8D2ED0 | RW | Unknown_Double_Cholesky [DERIVED]; D factor off-diagonal |
| 008d2f00 | unk_8D2F00 | R | Dynamics_Workspace_8D2F00 [DERIVED]; workspace |
| 008d2f28 | dbl_8D2F28 | R | DynSolverBlock_4_5 [DERIVED]; off-diagonal |
| 008d2f30 | dbl_8D2F30 | RW | SolverBlock_8D2F30 [DERIVED]; updated diagonal |
| 008d2f38 | dbl_8D2F38 | RW | DynamicsMatrixBlock14 [DERIVED]; pivot diagonal for block 19 |
| 008d2f48 | dbl_8D2F48 | RW | LDLTSolverWorkspaceDouble2 [DERIVED]; D factor off-diagonal |
| 008d2f50 | dbl_8D2F50 | RW | LDLTSolverWorkBlock [DERIVED]; D factor off-diagonal |
| 008d2f80 | unk_8D2F80 | R | LDLTFactorBlockPtr2 [DERIVED]; workspace |
| 008d2fa8 | dbl_8D2FA8 | R | ConstraintMatrix_8D2FA8 [DERIVED]; cross-body coupling element used in many rank-1 updates throughout factorization |
| 008d2fb0 | dbl_8D2FB0 | RW | DynamicsMatrixBlock6 [DERIVED]; updated element |
| 008d2fb8 | dbl_8D2FB8 | RW | DynSolver_Matrix_8D2FB8 [DERIVED]; updated element |
| 008d2fc0 | dbl_8D2FC0 | RW | DynamicsBlock_8D2FC0 [DERIVED]; updated element |
| 008d2fc8 | dbl_8D2FC8 | RW | DynSolver_MatrixBlock11b [DERIVED]; updated element |
| 008d2fd0 | dbl_8D2FD0 | RW | SolverBlock_8D2FD0 [DERIVED]; updated element |
| 008d2fd8 | dbl_8D2FD8 | RW | DynamicsBlockElement_8D2FD8 [DERIVED]; updated element |
| 008d2fe0 | dbl_8D2FE0 | RW | SolverBlock_8D2FE0 [DERIVED]; updated element |
| 008d2fe8 | dbl_8D2FE8 | RW | DynamicsSolverBlock_8D2FE8 [DERIVED]; updated element |
| 008d2ff0 | dbl_8D2FF0 | RW | DynSolver_MatrixBlock11c [DERIVED]; updated element |
| 008d3020 | dbl_8D3020 | RW | DynamicsMatrixBlock5 [DERIVED]; updated element |
| 008d3028 | dbl_8D3028 | RW | DynamicsBlockElement_8D3028 [DERIVED]; updated element |
| 008d3030 | dbl_8D3030 | RW | DynSolver_Matrix_8D3030 [DERIVED]; updated element |
| 008d3050 | dbl_8D3050 | RW | DynSolver_Workspace_3050 [DERIVED]; pivot diagonal for block 20 |
| 008d3068 | dbl_8D3068 | R | Dbl_DynamicsSolverWk27 [DERIVED]; off-diagonal reference (scaled L factor from earlier block) |
| 008d3070 | dbl_8D3070 | R | LDLT_FactorWorkspace_8D3070 [DERIVED]; off-diagonal L factor entry |
| 008d3078 | dbl_8D3078 | R | DynSolverFactorConst [DERIVED]; off-diagonal L factor entry |
| 008d3080 | dbl_8D3080 | R | CholeskyDiagonalIn [DERIVED]; off-diagonal L factor entry |
| 008d3088 | dbl_8D3088 | R | DynamicsSolver_D3088 [DERIVED]; off-diagonal L factor entry |
| 008d30b8 | dbl_8D30B8 | R | DynamicsSolverBlock_8D30B8 [DERIVED]; off-diagonal for rank-1 |
| 008d30c0 | dbl_8D30C0 | RW | DynamicsSolverElement_X5 [DERIVED]; updated diagonal |
| 008d30c8 | dbl_8D30C8 | RW | DynSolver_Block13_Element? [DERIVED]; updated element |
| 008d30d8 | dbl_8D30D8 | RW | ConstraintMatrix_Body5_6 [DERIVED]; pivot diagonal for block 21 |
| 008d30e0 | dbl_8D30E0 | RW | CholeskyMatrixTemp2 [DERIVED]; D factor off-diagonal |
| 008d3110 | unk_8D3110 | R | FactorWorkspaceUnk1 [DERIVED]; workspace |
| 008d3138 | dbl_8D3138 | R | DynMatrix_8D3138 [DERIVED]; off-diagonal for rank-1 |
| 008d3140 | dbl_8D3140 | RW | Dyn_SolverBlock_3140 [DERIVED]; updated diagonal |
| 008d3148 | dbl_8D3148 | RW | DynamicsMatrix_3_4_col1 [DERIVED]; updated element |
| 008d3158 | dbl_8D3158 | RW | DynamicsMatrixScalar [DERIVED]; updated element |
| 008d3160 | dbl_8D3160 | RW | DynSolver_Block13_Element24 [DERIVED]; pivot diagonal for block 22 |
| 008d3190 | unk_8D3190 | R | Cholesky_WorkBlock [DERIVED]; workspace |
| 008d31b8 | dbl_8D31B8 | R | ConstraintMatrix_8D31B8 [DERIVED]; off-diagonal for rank-1 |
| 008d31c0 | dbl_8D31C0 | RW | DynamicsMatrix_3_4_col0 [DERIVED]; updated diagonal |
| 008d31c8 | dbl_8D31C8 | RW | DynMatrix_8D31C8 [DERIVED]; updated element |
| 008d31d0 | dbl_8D31D0 | RW | DynSolverMatrixElem_8D31D0 [DERIVED]; updated element |
| 008d31d8 | dbl_8D31D8 | RW | SolverBlock_8D31D8 [DERIVED]; updated element |
| 008d31e0 | dbl_8D31E0 | R | DynSolver_MatrixBlock12b [DERIVED]; off-diagonal for parallel rank-1 update |
| 008d31e8 | dbl_8D31E8 | RW | DynamicsMatrix_Block25 [DERIVED]; updated element |
| 008d31f0 | dbl_8D31F0 | RW | DynamicsSolver_BlockBody2 [DERIVED]; updated element |
| 008d3210 | dbl_8D3210 | RW | DynamicsSolver_Block64kC [DERIVED]; updated element |
| 008d3228 | dbl_8D3228 | RW | DynamicsMatrix_3_3 [DERIVED]; pivot diagonal for block 23 |
| 008d3230 | dbl_8D3230 | R | LDLTDiagArray [DERIVED]; D factor recalculated; used as off-diagonal scaling in subsequent updates |
| 008d3278 | dbl_8D3278 | R | DynSolver_Workspace_3278 [DERIVED]; off-diagonal for rank-1 (fifth body block group) |
| 008d3280 | dbl_8D3280 | RW | SolverBlock_8D3280 [DERIVED]; updated diagonal |
| 008d3288 | dbl_8D3288 | RW | ConstraintMatrix_8D3288 [DERIVED]; updated element |
| 008d3290 | dbl_8D3290 | RW | DynamicsMatrixBlock11 [DERIVED]; updated element |
| 008d3298 | dbl_8D3298 | RW | DynamicsSolverElement_X3 [DERIVED]; updated element |
| 008d32a0 | dbl_8D32A0 | R | DynamicsBlock_32A0 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d32a8 | dbl_8D32A8 | RW | DynSolverMatrixElem_8D32A8 [DERIVED]; updated element |
| 008d32b0 | dbl_8D32B0 | RW | DynamicsBlockElement_8D32B0 [DERIVED]; updated element |
| 008d32d0 | dbl_8D32D0 | RW | DynamicsBlockElement_8D32D0 [DERIVED]; updated element |
| 008d32e8 | dbl_8D32E8 | RW | SolverBlock_8D32E8 [DERIVED]; updated element |
| 008d32f0 | dbl_8D32F0 | RW | DynamicsSolverBias3 [DERIVED]; pivot diagonal for block 24 |
| 008d32f8 | unk_8D32F8 | R | DynamicsFactorBlock_8D32F8 [DERIVED]; workspace |
| 008d3338 | dbl_8D3338 | R | DynamicsSolver_Block64kB [DERIVED]; off-diagonal for rank-1 |
| 008d3340 | dbl_8D3340 | RW | Dynamics_Block33A8_ElemPre [DERIVED]; updated diagonal |
| 008d3348 | dbl_8D3348 | RW | DynSolver_Matrix_8D3348 [DERIVED]; updated element |
| 008d3350 | dbl_8D3350 | RW | DynSolver_Block14_Element? [DERIVED]; updated element |
| 008d3358 | dbl_8D3358 | RW | Dyn_SolverBlock_3358 [DERIVED]; updated element |
| 008d3360 | dbl_8D3360 | R | DynamicsMatrixBlock12 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d3368 | dbl_8D3368 | RW | DynSolver_Block14_Element? [DERIVED]; updated element |
| 008d3370 | dbl_8D3370 | RW | DynSolver_MatrixBlock13 [DERIVED]; updated element |
| 008d3390 | dbl_8D3390 | RW | DynSolver_MatrixBlock12 [DERIVED]; updated element |
| 008d33a8 | dbl_8D33A8 | RW | DynamicsMatrix_Block24 [DERIVED]; updated element |
| 008d33b0 | dbl_8D33B0 | RW | DynSolver_Matrix_8D33B0 [DERIVED]; updated element |
| 008d33b8 | dbl_8D33B8 | RW | DynamicsMatrix_3_5 [DERIVED]; pivot diagonal for block 25 |
| 008d33c0 | unk_8D33C0 | R | Dynamics_Workspace_8D33C0 [DERIVED]; workspace |
| 008d33f8 | dbl_8D33F8 | R | DynamicsBlockElement_8D33F8 [DERIVED]; off-diagonal for rank-1 |
| 008d3400 | dbl_8D3400 | RW | DynamicsBlock_8D3400 [DERIVED]; updated diagonal |
| 008d3408 | dbl_8D3408 | RW | DynamicsSolver_BodyBlock1 [DERIVED]; updated element |
| 008d3410 | dbl_8D3410 | RW | DynamicsMatrix_4_0 [DERIVED]; updated element |
| 008d3418 | dbl_8D3418 | RW | DynSolverElem_12_0 [DERIVED]; updated element |
| 008d3420 | dbl_8D3420 | R | DynamicsMatrix_4_1 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d3428 | dbl_8D3428 | RW | SolverBlock_8D3428 [DERIVED]; updated element |
| 008d3430 | dbl_8D3430 | RW | DynamicsMatrix_Block28 [DERIVED]; updated element |
| 008d3450 | dbl_8D3450 | RW | DynamicsMatrix_Block29 [DERIVED]; updated element |
| 008d3468 | dbl_8D3468 | RW | DynamicsBlock_8D3468 [DERIVED]; updated element |
| 008d3470 | dbl_8D3470 | RW | DynamicsSolver_BodyBlock2 [DERIVED]; updated element |
| 008d3478 | dbl_8D3478 | RW | SolverBlock_8D3478 [DERIVED]; updated element |
| 008d3480 | dbl_8D3480 | RW | DynMatrix_8D3480 [DERIVED]; pivot diagonal for block 26 |
| 008d3488 | unk_8D3488 | R | Unknown_Struct_Cholesky3 [DERIVED]; workspace |
| 008d34b8 | dbl_8D34B8 | R | DynSolver_MatrixBlock13b [DERIVED]; off-diagonal for rank-1 |
| 008d34c0 | dbl_8D34C0 | RW | SolverBlock_8D34C0 [DERIVED]; updated diagonal |
| 008d34c8 | dbl_8D34C8 | RW | DynamicsBlockElement_8D34C8 [DERIVED]; updated element |
| 008d34d0 | dbl_8D34D0 | RW | SolverBlock_8D34D0 [DERIVED]; updated element |
| 008d34d8 | dbl_8D34D8 | RW | DynamicsSolverBlock_8D34D8 [DERIVED]; updated element |
| 008d34e0 | dbl_8D34E0 | R | Dynamics_Block34B8_Elem [DERIVED]; off-diagonal for parallel rank-1 |
| 008d34e8 | dbl_8D34E8 | RW | DynamicsBlock_8D34E8 [DERIVED]; updated element |
| 008d34f0 | dbl_8D34F0 | RW | DynamicsBlock_34F0 [DERIVED]; updated element |
| 008d3510 | dbl_8D3510 | RW | DynamicsBlock_11 [DERIVED]; updated element |
| 008d3528 | dbl_8D3528 | RW | SolverBlock_8D3528 [DERIVED]; updated element |
| 008d3530 | dbl_8D3530 | RW | DynamicsBlockElement_8D3530 [DERIVED]; updated element |
| 008d3538 | dbl_8D3538 | RW | Dynamics_Block3528_Elem [DERIVED]; updated element |
| 008d3540 | dbl_8D3540 | RW | ConstraintMatrix_8D3540 [DERIVED]; updated element |
| 008d3548 | dbl_8D3548 | RW | DynSolverMatrixElem_8D3548 [DERIVED]; pivot diagonal for block 27 |
| 008d3550 | unk_8D3550 | R | LDLTFactorBlockPtr3 [DERIVED]; workspace |
| 008d3578 | dbl_8D3578 | R | DynamicsMatrix_3_6 [DERIVED]; off-diagonal for rank-1 |
| 008d3580 | dbl_8D3580 | RW | SolverBlock_8D3580 [DERIVED]; updated diagonal |
| 008d3588 | dbl_8D3588 | RW | DynSolverMatrixElem_8D3588 [DERIVED]; updated element |
| 008d3590 | dbl_8D3590 | R | DynSolverElem_13_0 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d3598 | dbl_8D3598 | RW | DynamicsSolverBlock_8D3598 [DERIVED]; updated element |
| 008d35a0 | dbl_8D35A0 | RW | SolverBlock_8D35A0 [DERIVED]; updated element |
| 008d35a8 | dbl_8D35A8 | RW | DynSolverElem_13_2 [DERIVED]; updated element |
| 008d35b0 | dbl_8D35B0 | RW | DynamicsBlockElement_8D35B0 [DERIVED]; updated element |
| 008d35b8 | dbl_8D35B8 | RW | SolverBlock_8D35B8 [DERIVED]; updated element |
| 008d35c0 | dbl_8D35C0 | RW | Dyn_SolverBlock_35C0 [DERIVED]; updated element |
| 008d35c8 | dbl_8D35C8 | RW | DynSolver_MatrixBlock13d [DERIVED]; updated element |
| 008d35d0 | dbl_8D35D0 | RW | DynamicsBlock_8D35D0 [DERIVED]; updated element |
| 008d35d8 | dbl_8D35D8 | RW | DynSolver_Matrix_8D35D8 [DERIVED]; updated element |
| 008d35e0 | dbl_8D35E0 | RW | DynamicsMatrixBlock17 [DERIVED]; updated element |
| 008d35e8 | dbl_8D35E8 | RW | SolverBlock_8D35E8 [DERIVED]; pivot diagonal for block 28 |
| 008d35f0 | unk_8D35F0 | R | LDLTSolverIndexBlock2 [DERIVED]; workspace |
| 008d3610 | dbl_8D3610 | R | SolverBlock_8D3610 [DERIVED]; off-diagonal L factor reference used in multiple subsequent blocks |
| 008d3618 | dbl_8D3618 | RW | DynamicsSolverElement_X4 [DERIVED]; updated diagonal |
| 008d3620 | dbl_8D3620 | RW | DynamicsMatrixBlock13 [DERIVED]; updated element |
| 008d3628 | dbl_8D3628 | R | DynMatrix_8D3628 [DERIVED]; off-diagonal |
| 008d3630 | dbl_8D3630 | RW | ConstraintMatrix_8D3630 [DERIVED]; updated element |
| 008d3638 | dbl_8D3638 | RW | Dynamics_Block3610_Elem [DERIVED]; updated element |
| 008d3640 | dbl_8D3640 | RW | DynamicsSolverBlock_8D3640 [DERIVED]; updated element |
| 008d3648 | dbl_8D3648 | RW | DynSolver_MatrixBlock14 [DERIVED]; updated element |
| 008d3650 | dbl_8D3650 | RW | DynamicsMatrix_4_3 [DERIVED]; updated element |
| 008d3658 | dbl_8D3658 | RW | DynamicsSolverElement_X7 [DERIVED]; updated element |
| 008d3660 | dbl_8D3660 | RW | DynamicsMatrix_Block30 [DERIVED]; updated element |
| 008d3668 | dbl_8D3668 | RW | SolverBlock_8D3668 [DERIVED]; updated element |
| 008d3670 | dbl_8D3670 | RW | DynamicsSolver_BodyBlock4 [DERIVED]; updated element |
| 008d3678 | dbl_8D3678 | RW | DynSolver_Block15_Element? [DERIVED]; updated element |
| 008d3680 | dbl_8D3680 | RW | DynamicsSolverElement_X9 [DERIVED]; updated element |
| 008d3688 | dbl_8D3688 | RW | ConstraintMatrix_8D3688 [DERIVED]; pivot diagonal for block 29 |
| 008d3690 | unk_8D3690 | R | DynSolver_WS_8D3690 [DERIVED]; workspace |
| 008d36a8 | dbl_8D36A8 | R | DynamicsMatrix_Block136 [DERIVED]; off-diagonal for rank-1 |
| 008d36b0 | dbl_8D36B0 | RW | Dyn_SolverBlock_36B0 [DERIVED]; updated diagonal |
| 008d36b8 | dbl_8D36B8 | RW | DynSolver_Block15_Element? [DERIVED]; updated element |
| 008d36c0 | dbl_8D36C0 | R | DynSolver_Matrix_8D36C0 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d36c8 | dbl_8D36C8 | RW | DynamicsSolver_BlockBody3 [DERIVED]; updated element |
| 008d36d0 | dbl_8D36D0 | RW | DynamicsBlock_8D36D0 [DERIVED]; updated element |
| 008d36d8 | dbl_8D36D8 | RW | DynMatrix_8D36D8 [DERIVED]; updated element |
| 008d36e0 | dbl_8D36E0 | RW | DynamicsMatrix_Block31 [DERIVED]; updated element |
| 008d36e8 | dbl_8D36E8 | RW | DynSolver_Block15_Element? [DERIVED]; updated element |
| 008d36f0 | dbl_8D36F0 | RW | DynSolverElem_14_1 [DERIVED]; updated element |
| 008d36f8 | dbl_8D36F8 | RW | DynamicsBlock_36F8 [DERIVED]; updated element |
| 008d3700 | dbl_8D3700 | RW | DynamicsSolverElement_X8 [DERIVED]; updated element |
| 008d3708 | dbl_8D3708 | RW | DynamicsBlockElement_8D3708 [DERIVED]; updated element |
| 008d3710 | dbl_8D3710 | RW | DynamicsMatrix_4_4_col0 [DERIVED]; updated element |
| 008d3718 | dbl_8D3718 | RW | Dyn_SolverBlock_3718 [DERIVED]; updated element |
| 008d3720 | dbl_8D3720 | RW | DynSolver_Matrix_8D3720 [DERIVED]; updated element |
| 008d3728 | dbl_8D3728 | RW | DynamicsMatrix_Block32b [DERIVED]; pivot diagonal for block 30 |
| 008d3730 | dbl_8D3730 | RW | FactorWorkspaceDbl2 [DERIVED]; D factor off-diagonal |
| 008d3738 | dbl_8D3738 | RW | CholeskyMatrixTemp3 [DERIVED]; D factor off-diagonal |
| 008d3740 | dbl_8D3740 | R | DynamicsBlock_8D3740 [DERIVED]; off-diagonal for rank-1 |
| 008d3748 | dbl_8D3748 | RW | DynSolverElem_14_0 [DERIVED]; updated diagonal |
| 008d3750 | dbl_8D3750 | RW | DynamicsMatrix_4_5 [DERIVED]; updated element |
| 008d3758 | dbl_8D3758 | R | DynamicsBlockElement_8D3758 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d3760 | dbl_8D3760 | RW | DynSolver_MatrixBlock14b [DERIVED]; updated element |
| 008d3768 | dbl_8D3768 | RW | SolverBlock_8D3768 [DERIVED]; updated element |
| 008d3770 | dbl_8D3770 | RW | ConstraintMatrix_8D3770 [DERIVED]; updated element |
| 008d3778 | dbl_8D3778 | RW | DynamicsBlock_3778 [DERIVED]; updated element |
| 008d3780 | dbl_8D3780 | RW | Dynamics_Block3740_Elem [DERIVED]; updated element |
| 008d3788 | dbl_8D3788 | RW | DynamicsSolverBlock_8D3788 [DERIVED]; updated element |
| 008d3790 | dbl_8D3790 | RW | DynSolverMatrixElem_8D3790 [DERIVED]; updated element |
| 008d3798 | dbl_8D3798 | RW | Dyn_SolverBlock_3798 [DERIVED]; updated element |
| 008d37a0 | dbl_8D37A0 | RW | DynSolver_MatrixBlock14c [DERIVED]; updated element |
| 008d37a8 | dbl_8D37A8 | RW | SolverBlock_8D37A8 [DERIVED]; updated element |
| 008d37b0 | dbl_8D37B0 | RW | DynSolverElem_14_2 [DERIVED]; updated element |
| 008d37b8 | dbl_8D37B8 | RW | DynamicsSolver_BodyBlock5 [DERIVED]; updated element |
| 008d37c0 | dbl_8D37C0 | RW | DynamicsBlock_37C0 [DERIVED]; updated element |
| 008d37c8 | dbl_8D37C8 | RW | DynSolver_Block16_Element? [DERIVED]; pivot diagonal for block 31 |
| 008d37d0 | dbl_8D37D0 | RW | LDLTWorkspaceC [DERIVED]; D factor off-diagonal |
| 008d37d8 | dbl_8D37D8 | R | SolverBlock_8D37D8 [DERIVED]; off-diagonal for rank-1 |
| 008d37e0 | dbl_8D37E0 | RW | DynamicsSolverBlock_8D37E0 [DERIVED]; updated diagonal |
| 008d37e8 | dbl_8D37E8 | RW | SolverBlock_8D37E8 [DERIVED]; updated element |
| 008d37f0 | dbl_8D37F0 | R | DynamicsMatrix_Block33 [DERIVED]; off-diagonal for parallel rank-1 |
| 008d37f8 | dbl_8D37F8 | RW | DynamicsBlock_37F8 [DERIVED]; updated element |
| 008d3800 | dbl_8D3800 | RW | DynamicsSolverElement_X6 [DERIVED]; updated element |
| 008d3808 | dbl_8D3808 | RW | DynSolver_Matrix_8D3808 [DERIVED]; updated element |
| 008d3810 | dbl_8D3810 | RW | DynSolverMatrixElem_8D3810 [DERIVED]; updated element |
| 008d3818 | dbl_8D3818 | RW | DynamicsBlock_8D3818 [DERIVED]; updated element |
| 008d3820 | dbl_8D3820 | RW | DynMatrix_8D3820 [DERIVED]; updated element |
| 008d3828 | dbl_8D3828 | RW | DynamicsMatrixBlock16 [DERIVED]; updated element |
| 008d3830 | dbl_8D3830 | RW | DynSolverElem_14_3 [DERIVED]; updated element |
| 008d3838 | dbl_8D3838 | RW | DynamicsMatrix_Block32 [DERIVED]; updated element |
| 008d3840 | dbl_8D3840 | RW | Dynamics_Block3870_Elem4 [DERIVED]; updated element |
| 008d3848 | dbl_8D3848 | RW | DynamicsSolverBlock_8D3848 [DERIVED]; updated element |
| 008d3850 | dbl_8D3850 | RW | DynamicsBlockElement_8D3850 [DERIVED]; updated element |
| 008d3858 | dbl_8D3858 | RW | DynSolverMatrixElem_8D3858 [DERIVED]; updated element |
| 008d3860 | dbl_8D3860 | RW | DynamicsMatrix_4_5_col0 [DERIVED]; updated element |
| 008d3868 | dbl_8D3868 | RW | Dynamics_Block3870_Elem5 [DERIVED]; pivot diagonal for block 32 (final pivot) |
| 008d3870 | dbl_8D3870 | RW | DynamicsBlock_14 [DERIVED]; updated D factor diagonal for final block |
| 008d3878 | dbl_8D3878 | RW | DynSolver_Block16_Element? [DERIVED]; updated element |
| 008d3880 | dbl_8D3880 | RW | DynamicsSolver_DiagBlock6 [DERIVED]; updated element |
| 008d3888 | dbl_8D3888 | RW | SolverBlock_8D3888 [DERIVED]; updated element |
| 008d3890 | dbl_8D3890 | RW | DynamicsMatrix_Block34 [DERIVED]; updated element |
| 008d3898 | dbl_8D3898 | RW | DynamicsSolverElement_X1 [DERIVED]; updated element |
| 008d38a0 | dbl_8D38A0 | RW | DynSolver_MatrixBlock14e [DERIVED]; updated element |
| 008d38a8 | dbl_8D38A8 | RW | Dynamics_Block3870_Elem [DERIVED]; updated element |
| 008d38b0 | dbl_8D38B0 | RW | DynMatrix_8D38B0 [DERIVED]; updated element |
| 008d38b8 | dbl_8D38B8 | RW | DynamicsMatrix_Block35 [DERIVED]; updated element |
| 008d38c0 | dbl_8D38C0 | RW | DynamicsBlock_38C0 [DERIVED]; updated element |
| 008d38c8 | dbl_8D38C8 | RW | DynamicsSolverElement_X2 [DERIVED]; updated element |
| 008d38d0 | dbl_8D38D0 | RW | DynSolver_MatrixBlock14f [DERIVED]; updated element |
| 008d38d8 | dbl_8D38D8 | RW | Dynamics_Block3870_Elem2 [DERIVED]; updated element |
| 008d38e0 | dbl_8D38E0 | RW | DynMatrix_8D38E0 [DERIVED]; updated element |
| 008d38e8 | dbl_8D38E8 | RW | DynSolver_Matrix_8D38E8 [DERIVED]; updated element |
| 008d38f0 | dbl_8D38F0 | RW | DynMatrix_8D38F0 [DERIVED]; updated element |
| 008d38f8 | dbl_8D38F8 | RW | Dynamics_Block3870_Elem3 [DERIVED]; updated element |
| 008d3900 | dbl_8D3900 | RW | DynamicsBlock_8D3900 [DERIVED]; updated element |
| 008d3908 | dbl_8D3908 | RW | DynSolverMatrixElem_8D3908 [DERIVED]; updated element |
| 008d3910 | dbl_8D3910 | RW | Dyn_SolverBlock_3910 [DERIVED]; updated element |
| 008d3918 | dbl_8D3918 | RW | DynamicsSolver_BodyBlock7 [DERIVED]; updated element |
| 008d3920 | dbl_8D3920 | RW | DynamicsMatrixBlock15 [DERIVED]; updated element |
| 008d3928 | dbl_8D3928 | RW | SolverBlock_8D3928 [DERIVED]; updated element |
| 008d3930 | dbl_8D3930 | RW | ConstraintMatrix_8D3930 [DERIVED]; updated element |
| 008d3938 | dbl_8D3938 | RW | DynSolver_Block16_Element? [DERIVED]; updated element |
| 008d3940 | dbl_8D3940 | RW | DynamicsSolverBlock_8D3940 [DERIVED]; updated element |
| 008d3948 | dbl_8D3948 | RW | DynamicsBlock_3948 [DERIVED]; updated element |
| 008d3950 | dbl_8D3950 | RW | DynamicsBlock_8D3950 [DERIVED]; updated element |
| 008d3958 | dbl_8D3958 | RW | DynMatrix_8D3958 [DERIVED]; updated element |
| 008d3960 | dbl_8D3960 | RW | DynSolver_MatrixBlock14g [DERIVED]; updated element |
| 008d3968 | dbl_8D3968 | RW | DynamicsMatrixBlock18 [DERIVED]; updated element |
| 008d3970 | dbl_8D3970 | RW | SolverBlock_8D3970 [DERIVED]; updated element |
| 008d3978 | dbl_8D3978 | RW | DynamicsBlock_8D3978 [DERIVED]; final updated element after all rank-1 updates |
| 008d3b68 | dword_8D3B68 | R | Dyn_SolverBlock_3B68 [DERIVED]; pointer into index array — base of column pointer table for sparse factorization |
| 008d3b6c | dword_8D3B6C | R | LDLTSolverIndexBlock [DERIVED]; column pointer for row 1 |
| 008d3b70 | dword_8D3B70 | R | LDLTIndexArrayB [DERIVED]; column pointer for row 2 |
| 008d3b74 | dword_8D3B74 | R | DynamicsSolverIndex_8D3B74 [DERIVED]; column pointer for row 3 |
| 008d3b78 | dword_8D3B78 | R | CholeskyWorkspaceA [DERIVED]; column pointer for row 4 |
| 008d3b7c | dword_8D3B7C | R | LDLTSolverWorkspace2 [DERIVED]; column pointer for row 5 |
| 008d3b80 | dword_8D3B80 | R | FactorWorkspaceInt2 [DERIVED]; column pointer for row 6 |
| 008d3b84 | dword_8D3B84 | R | LDLT_Work_Idx3 [DERIVED]; column pointer for row 7 |
| 008d3b88 | dword_8D3B88 | R | CholeskyWorkspaceB [DERIVED]; column pointer for row 8 |
| 008d3b8c | dword_8D3B8C | R | LDLTSolverWorkspace3 [DERIVED]; column pointer for row 9 |
| 008d3b90 | dword_8D3B90 | R | Dword_DynamicsSolver [DERIVED]; column pointer for body-block boundary |
| 008d3b94 | dword_8D3B94 | R | FactorWorkspaceInt3 [DERIVED]; column pointer |
| 008d3b98 | dword_8D3B98 | R | LDLT_Work_Idx4 [DERIVED]; column pointer |
| 008d3b9c | dword_8D3B9C | R | Dynamics_Offset_D3B9C [DERIVED]; column pointer |
| 008d3ba0 | dword_8D3BA0 | R | Unknown_DWord_Cholesky [DERIVED]; column pointer |
| 008d3ba4 | dword_8D3BA4 | R | FactorWorkspaceInt1 [DERIVED]; secondary column pointer array base |
| 008d3bac | dword_8D3BAC | R | Cholesky_WorkOffset2 [DERIVED]; secondary column pointer |
| 008d3bb0 | dword_8D3BB0 | R | CholeskyWorkspaceData [DERIVED]; secondary column pointer (boundary) |
| 008d3bb8 | dword_8D3BB8 | R | DynamicsSolver_D3BB8 [DERIVED]; pointer |
| 008d3bbc | dword_8D3BBC | R | DynSolver_WS_8D3BBC [DERIVED]; pointer |
| 008d3bc8 | dword_8D3BC8 | R | Cholesky_WorkOffset [DERIVED]; tertiary column pointer base |
| 008d3bcc | dword_8D3BCC | R | LDLT_Work_Idx5 [DERIVED]; pointer |
| 008d3bd0 | dword_8D3BD0 | R | DynSolver_IndexDword_CH [DERIVED]; pointer |
| 008d3bd4 | dword_8D3BD4 | R | SolverBlockIndex [DERIVED]; pointer |
| 008d3bd8 | dword_8D3BD8 | R | CholeskyWorkspaceE [DERIVED]; pointer |
| 008d3bdc | dword_8D3BDC | R | LDLTIndexArrayC [DERIVED]; pointer |
| 008d3be0 | dword_8D3BE0 | R | LDLTSolverWorkspace4 [DERIVED]; pointer |
| 008d3be4 | dword_8D3BE4 | R | Dword_DynamicsSolver2 [DERIVED]; pointer |
| 008d3be8 | dword_8D3BE8 | R | Cholesky_WorkOffset3 [DERIVED]; pointer |
| 008d3bec | dword_8D3BEC | R | LDLT_Work_Idx6 [DERIVED]; pointer |
| 008d3bf0 | unk_8D3BF0 | R | ConstraintSolverState [DERIVED]; pointer (sentinel/end of pointer array) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. The function executes unconditionally with no branches other than loop counters. There are no null-pointer checks, range validations, zero-division guards, or early-exit paths. All divisions by diagonal elements proceed without checking for zero or near-zero values (infinities/NaN propagate silently if the matrix is singular).
