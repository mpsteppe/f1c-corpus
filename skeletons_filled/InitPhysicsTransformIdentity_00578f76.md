## InitPhysicsTransformIdentity_00578f76 — InitPhysicsConstraintMatrixRow

**Summary:** Initializes a single row of the physics dynamics constraint/solver matrix to identity (diagonal = 1.0, all other elements = 0.0). For rows 3+, also zeroes the preceding block of row elements via sub_58BB10. Part of the vehicle physics dynamics solver system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00579c47 | jpt_578F83 | R | Jump table for switch dispatch — maps case index (a1) to code block addresses |
| 008d2120 | dbl_8D2120 | W | ConstraintMatrix00 — row 0, diagonal element (set to 1.0) [DERIVED] |
| 008d21d0 | dbl_8D21D0 | W | DynSolver_Matrix_8D21D0 — row 0, column 1 off-diagonal (set to 0.0) [DERIVED] |
| 008d21d8 | dbl_8D21D8 | W | DynamicsSolver_DiagBlock1 — row 1, diagonal (set to 1.0) [DERIVED] |
| 008d2280 | dbl_8D2280 | W | DynamicsBlockElement_8D2280 — row 0, column 2 (set to 0.0) [DERIVED] |
| 008d2288 | dbl_8D2288 | W | DynSolverElem_1_2 — row 1, column 2 (set to 0.0) [DERIVED] |
| 008d2290 | dbl_8D2290 | W | DynamicsMatrix_2_2 — row 2, diagonal (set to 1.0) [DERIVED] |
| 008d2330 | dbl_8D2330 | RW | DynSolver_MatrixBlock3 — row 0, column 3; block-zeroed then row 3 diagonal set to 1.0 [DERIVED] |
| 008d2338 | dbl_8D2338 | W | DynamicsSolverBlock_8D2338 — row 1, column 3 off-diagonal (set to 0.0) [DERIVED] |
| 008d2340 | dbl_8D2340 | W | SolverBlock_8D2340 — row 2, column 3 (set to 0.0) [DERIVED] |
| 008d2348 | dbl_8D2348 | W | DynamicsBlockElement_8D2348 — row 3, diagonal (set to 1.0) [DERIVED] |
| 008d23e0 | dbl_8D23E0 | RW | DynamicsMatrix_Block4 — row 0, column 4; block-zeroed then row 4 diagonal set to 1.0 [DERIVED] |
| 008d23e8 | dbl_8D23E8 | W | DynMatrix_8D23E8 — row 1, column 4 (set to 0.0) [DERIVED] |
| 008d23f0 | dbl_8D23F0 | W | Dynamics_Block23E0_Elem — row 2, column 4 (set to 0.0) [DERIVED] |
| 008d23f8 | dbl_8D23F8 | W | DynSolver_MatrixBlock4b — row 3, column 4 (set to 0.0) [DERIVED] |
| 008d2400 | dbl_8D2400 | W | DynamicsSolverElement4_0 — row 4, diagonal (set to 1.0) [DERIVED] |
| 008d2490 | dbl_8D2490 | RW | DynamicsBlock_4 — row 0, column 5; block-zeroed then row 5 diagonal set to 1.0 [DERIVED] |
| 008d2498 | dbl_8D2498 | W | ConstraintMatrix_8D2498 — row 1, column 5 (set to 0.0) [DERIVED] |
| 008d24a0 | dbl_8D24A0 | W | DynamicsBlock_8D24A0 — row 2, column 5 (set to 0.0) [DERIVED] |
| 008d24a8 | dbl_8D24A8 | W | DynamicsMatrix_Block8 — row 3, column 5 (set to 0.0) [DERIVED] |
| 008d24b0 | dbl_8D24B0 | W | Dyn_SolverBlock_24B0 — row 4, column 5 (set to 0.0) [DERIVED] |
| 008d24b8 | dbl_8D24B8 | W | DynamicsBlock_24B8 — row 5, diagonal (set to 1.0) [DERIVED] |
| 008d2540 | dbl_8D2540 | RW | ConstraintMatrix_Body0_DOF5 — row 0, column 6; block-zeroed then row 6 diagonal set to 1.0 [DERIVED] |
| 008d2548 | dbl_8D2548 | W | DynSolver_Matrix_8D2548 — row 1, column 6 (set to 0.0) [DERIVED] |
| 008d2550 | dbl_8D2550 | W | SolverBlock_8D2550 — row 2, column 6 (set to 0.0) [DERIVED] |
| 008d2558 | dbl_8D2558 | W | DynamicsBlock_2558 — row 3, column 6 (set to 0.0) [DERIVED] |
| 008d2560 | dbl_8D2560 | W | DynSolverElem_5_2 — row 4, column 6 (set to 0.0) [DERIVED] |
| 008d2568 | dbl_8D2568 | W | DynSolverMatrixElem_8D2568 — row 5, column 6 (set to 0.0) [DERIVED] |
| 008d2570 | dbl_8D2570 | W | Dyn_SolverBlock_2570 — row 6, diagonal (set to 1.0) [DERIVED] |
| 008d25f0 | dbl_8D25F0 | RW | DynamicsMatrixBlock4 — row 0, column 7; block-zeroed then row 7 diagonal set to 1.0 [DERIVED] |
| 008d25f8 | dbl_8D25F8 | W | DynamicsSolver_DiagBlock5 — row 1, column 7 (set to 0.0) [DERIVED] |
| 008d2600 | dbl_8D2600 | W | DynamicsSolverElement2_2 — row 2, column 7 (set to 0.0) [DERIVED] |
| 008d2608 | dbl_8D2608 | W | DynSolverMatrixElem_8D2608 — row 3, column 7 (set to 0.0) [DERIVED] |
| 008d2610 | dbl_8D2610 | W | DynamicsSolverBlock_8D2610 — row 4, column 7 (set to 0.0) [DERIVED] |
| 008d2618 | dbl_8D2618 | W | DynamicsMatrixBlock8 — row 5, column 7 (set to 0.0) [DERIVED] |
| 008d2620 | dbl_8D2620 | W | DynSolverElem_6_0 — row 6, column 7 (set to 0.0) [DERIVED] |
| 008d2628 | dbl_8D2628 | W | DynamicsMatrix_Block10 — row 7, diagonal (set to 1.0) [DERIVED] |
| 008d26a0 | dbl_8D26A0 | RW | DynSolver_Block5_Element00 — row 0, column 8; block-zeroed then row 8 diagonal set to 1.0 [DERIVED] |
| 008d26a8 | dbl_8D26A8 | W | DynamicsBlockElement_8D26A8 — row 1, column 8 (set to 0.0) [DERIVED] |
| 008d26b0 | dbl_8D26B0 | W | Dyn_SolverBlock_26B0 — row 2, column 8 (set to 0.0) [DERIVED] |
| 008d26b8 | dbl_8D26B8 | W | DynamicsMatrixBlock7 — row 3, column 8 (set to 0.0) [DERIVED] |
| 008d26c0 | dbl_8D26C0 | W | DynMatrix_8D26C0 — row 4, column 8 (set to 0.0) [DERIVED] |
| 008d26c8 | dbl_8D26C8 | W | DynSolver_Block5_Element6 — row 5, column 8 (set to 0.0) [DERIVED] |
| 008d26d0 | dbl_8D26D0 | W | DynamicsSolverBlock_8D26D0 — row 6, column 8 (set to 0.0) [DERIVED] |
| 008d26d8 | dbl_8D26D8 | W | DynamicsBlock_26D8 — row 7, column 8 (set to 0.0) [DERIVED] |
| 008d26e0 | dbl_8D26E0 | W | DynamicsBlock_8D26E0 — row 8, diagonal (set to 1.0) [DERIVED] |
| 008d2750 | dbl_8D2750 | RW | DynamicsMatrix_0_9 — row 0, column 9; block-zeroed then row 9 diagonal set to 1.0 [DERIVED] |
| 008d2758 | dbl_8D2758 | W | DynSolver_MatrixBlock8b — row 1, column 9 (set to 0.0) [DERIVED] |
| 008d2760 | dbl_8D2760 | W | DynSolverElem_7_0 — row 2, column 9 (set to 0.0) [DERIVED] |
| 008d2768 | dbl_8D2768 | W | DynSolver_Block6_Element13 — row 3, column 9 (set to 0.0) [DERIVED] |
| 008d2770 | dbl_8D2770 | W | ConstraintMatrix_8D2770 — row 4, column 9 (set to 0.0) [DERIVED] |
| 008d2778 | dbl_8D2778 | W | DynamicsMatrix_2_3 — row 5, column 9 (set to 0.0) [DERIVED] |
| 008d2780 | dbl_8D2780 | W | DynMatrix_8D2780 — row 6, column 9 (set to 0.0) [DERIVED] |
| 008d2788 | dbl_8D2788 | W | DynSolverMatrixElem_8D2788 — row 7, column 9 (set to 0.0) [DERIVED] |
| 008d2790 | dbl_8D2790 | W | SolverBlock_8D2790 — row 8, column 9 (set to 0.0) [DERIVED] |
| 008d2798 | dbl_8D2798 | W | ConstraintMatrix_8D2798 — row 9, diagonal (set to 1.0) [DERIVED] |
| 008d2800 | dbl_8D2800 | W | SolverBlock_8D2800 — row 10, diagonal (set to 1.0) [DERIVED] |
| 008d2898 | dbl_8D2898 | W | DynamicsSolverBias1 — row 10, column 11 off-diagonal (set to 0.0) [DERIVED] |
| 008d28a0 | dbl_8D28A0 | W | Dyn_SolverBlock_28A0 — row 11, diagonal (set to 1.0) [DERIVED] |
| 008d2930 | dbl_8D2930 | W | DynSolverBlock_3_0 — row 10, column 12 (set to 0.0) [DERIVED] |
| 008d2938 | dbl_8D2938 | W | DynSolverMatrixElem_8D2938 — row 11, column 12 (set to 0.0) [DERIVED] |
| 008d2940 | dbl_8D2940 | W | Dyn_SolverBlock_2940 — row 12, diagonal (set to 1.0) [DERIVED] |
| 008d29c8 | dbl_8D29C8 | RW | DynamicsSolverBlock_8D29C8 — row 10, column 13; block-zeroed then row 13 diagonal set to 1.0 [DERIVED] |
| 008d29d0 | dbl_8D29D0 | W | DynamicsMatrixBlock10 — row 11, column 13 (set to 0.0) [DERIVED] |
| 008d29d8 | dbl_8D29D8 | W | DynSolverElem_3_3 — row 12, column 13 (set to 0.0) [DERIVED] |
| 008d29e0 | dbl_8D29E0 | W | DynamicsMatrix_Block11 — row 13, diagonal (set to 1.0) [DERIVED] |
| 008d2a60 | dbl_8D2A60 | RW | DynMatrix_8D2A60 — row 10, column 14; block-zeroed then row 14 diagonal set to 1.0 [DERIVED] |
| 008d2a68 | dbl_8D2A68 | W | DynSolver_Block9_Element? — row 11, column 14 (set to 0.0) [DERIVED] |
| 008d2a70 | dbl_8D2A70 | W | DynamicsSolverBlock_8D2A70 — row 12, column 14 (set to 0.0) [DERIVED] |
| 008d2a78 | dbl_8D2A78 | W | DynamicsBlock_2A78 — row 13, column 14 (set to 0.0) [DERIVED] |
| 008d2a80 | dbl_8D2A80 | W | DynamicsBlock_8D2A80 — row 14, diagonal (set to 1.0) [DERIVED] |
| 008d2af8 | dbl_8D2AF8 | RW | SolverBlock_8D2AF8 — row 10, column 15; block-zeroed then row 15 diagonal set to 1.0 [DERIVED] |
| 008d2b00 | dbl_8D2B00 | W | DynamicsMatrix_Block12 — row 11, column 15 (set to 0.0) [DERIVED] |
| 008d2b08 | dbl_8D2B08 | W | DynamicsSolverBlock_8D2B08 — row 12, column 15 (set to 0.0) [DERIVED] |
| 008d2b10 | dbl_8D2B10 | W | DynamicsMatrix_2_7 — row 13, column 15 (set to 0.0) [DERIVED] |
| 008d2b18 | dbl_8D2B18 | W | DynSolver_Matrix_8D2B18 — row 14, column 15 (set to 0.0) [DERIVED] |
| 008d2b20 | dbl_8D2B20 | W | SolverBlock_8D2B20 — row 15, block-zeroed continuation (set to 0.0) [DERIVED] |
| 008d2b28 | dbl_8D2B28 | W | ConstraintMatrix_8D2B28 — row 15, block-zeroed continuation (set to 0.0) [DERIVED] |
| 008d2b30 | dbl_8D2B30 | W | DynamicsMatrixBlock9 — row 15, block-zeroed continuation (set to 0.0) [DERIVED] |
| 008d2b38 | dbl_8D2B38 | W | DynamicsSolverElement_3_X — row 15, block-zeroed continuation (set to 0.0) [DERIVED] |
| 008d2b40 | dbl_8D2B40 | W | DynSolver_Matrix_8D2B40 — row 15, block-zeroed continuation (set to 0.0) [DERIVED] |
| 008d2b70 | dbl_8D2B70 | W | DynamicsMatrix_Block13 — row 15, diagonal (set to 1.0) [DERIVED] |
| 008d2c08 | dbl_8D2C08 | RW | DynamicsMatrix_DiagBlock — blocked-zeroed block for next row group [DERIVED] |
| 008d2c10 | dbl_8D2C10 | W | DynamicsBlock_2C10 — (set to 0.0) [DERIVED] |
| 008d2c18 | dbl_8D2C18 | W | DynMatrix_8D2C18 — (set to 0.0) [DERIVED] |
| 008d2c20 | dbl_8D2C20 | W | SolverBlock_8D2C20 — (set to 0.0) [DERIVED] |
| 008d2c28 | dbl_8D2C28 | W | DynamicsSolver_BlockCol4 — (set to 0.0) [DERIVED] |
| 008d2c30 | dbl_8D2C30 | W | Dynamics_Block2C08_Elem2 — (set to 0.0) [DERIVED] |
| 008d2c38 | dbl_8D2C38 | W | DynSolver_Matrix_8D2C38 — (set to 0.0) [DERIVED] |
| 008d2c40 | dbl_8D2C40 | W | DynSolver_Block11_Element8 — (set to 0.0) [DERIVED] |
| 008d2c48 | dbl_8D2C48 | W | Dyn_SolverBlock_2C48 — (set to 0.0) [DERIVED] |
| 008d2c50 | dbl_8D2C50 | W | DynamicsSolver_BlockCol6 — (set to 0.0) [DERIVED] |
| 008d2c80 | dbl_8D2C80 | W | DynamicsBlock_8_80 — (set to 0.0) [DERIVED] |
| 008d2c88 | dbl_8D2C88 | W | DynSolver_Block11_Element13 — row 16, diagonal (set to 1.0) [DERIVED] |
| 008d2d18 | dbl_8D2D18 | RW | DynamicsBlock_8D2D18 — block-zeroed for next row group [DERIVED] |
| 008d2d20 | dbl_8D2D20 | W | DynSolverMatrixElem_8D2D20 — (set to 0.0) [DERIVED] |
| 008d2d28 | dbl_8D2D28 | W | ConstraintMatrix_8D2D28 — (set to 0.0) [DERIVED] |
| 008d2d30 | dbl_8D2D30 | W | Dynamics_Block2D18_Elem — (set to 0.0) [DERIVED] |
| 008d2d38 | dbl_8D2D38 | W | DynamicsBlockElement_8D2D38 — (set to 0.0) [DERIVED] |
| 008d2d40 | dbl_8D2D40 | W | DynamicsBlock_8D2D40 — (set to 0.0) [DERIVED] |
| 008d2d48 | dbl_8D2D48 | W | DynamicsSolver_BlockCol5 — (set to 0.0) [DERIVED] |
| 008d2d50 | dbl_8D2D50 | W | DynamicsMatrix_3_1 — (set to 0.0) [DERIVED] |
| 008d2d58 | dbl_8D2D58 | W | DynSolverElem_8_3 — (set to 0.0) [DERIVED] |
| 008d2d60 | dbl_8D2D60 | W | DynamicsBlockElement_8D2D60 — (set to 0.0) [DERIVED] |
| 008d2d90 | dbl_8D2D90 | W | ConstraintMatrix_Body3_Row6 — (set to 0.0) [DERIVED] |
| 008d2d98 | dbl_8D2D98 | W | DynamicsSolver_BlockCol7 — (set to 0.0) [DERIVED] |
| 008d2da0 | dbl_8D2DA0 | W | ConstraintMatrix_8D2DA0 — row 17, diagonal (set to 1.0) [DERIVED] |
| 008d2e28 | dbl_8D2E28 | W | DynamicsSolverBias2 — row 18, diagonal (set to 1.0) [DERIVED] |
| 008d2ea8 | dbl_8D2EA8 | W | Dyn_SolverBlock_2EA8 — row 18, column 19 (set to 0.0) [DERIVED] |
| 008d2eb0 | dbl_8D2EB0 | W | ConstraintMatrix_8D2EB0 — row 19, diagonal (set to 1.0) [DERIVED] |
| 008d2f28 | dbl_8D2F28 | W | DynSolverBlock_4_5 — row 18, column 20 (set to 0.0) [DERIVED] |
| 008d2f30 | dbl_8D2F30 | W | SolverBlock_8D2F30 — row 19, column 20 (set to 0.0) [DERIVED] |
| 008d2f38 | dbl_8D2F38 | W | DynamicsMatrixBlock14 — row 20, diagonal (set to 1.0) [DERIVED] |
| 008d2fa8 | dbl_8D2FA8 | RW | ConstraintMatrix_8D2FA8 — block-zeroed for next row group [DERIVED] |
| 008d2fb0 | dbl_8D2FB0 | W | DynamicsMatrixBlock6 — (set to 0.0) [DERIVED] |
| 008d2fb8 | dbl_8D2FB8 | W | DynSolver_Matrix_8D2FB8 — (set to 0.0) [DERIVED] |
| 008d2fc0 | dbl_8D2FC0 | W | DynamicsBlock_8D2FC0 — (set to 0.0) [DERIVED] |
| 008d2fc8 | dbl_8D2FC8 | W | DynSolver_MatrixBlock11b — (set to 0.0) [DERIVED] |
| 008d2fd0 | dbl_8D2FD0 | W | SolverBlock_8D2FD0 — (set to 0.0) [DERIVED] |
| 008d2fd8 | dbl_8D2FD8 | W | DynamicsBlockElement_8D2FD8 — (set to 0.0) [DERIVED] |
| 008d2fe0 | dbl_8D2FE0 | W | SolverBlock_8D2FE0 — (set to 0.0) [DERIVED] |
| 008d2fe8 | dbl_8D2FE8 | W | DynamicsSolverBlock_8D2FE8 — (set to 0.0) [DERIVED] |
| 008d2ff0 | dbl_8D2FF0 | W | DynSolver_MatrixBlock11c — (set to 0.0) [DERIVED] |
| 008d3020 | dbl_8D3020 | RW | DynamicsMatrixBlock5 — block-zeroed for next row group [DERIVED] |
| 008d3028 | dbl_8D3028 | W | DynamicsBlockElement_8D3028 — (set to 0.0) [DERIVED] |
| 008d3030 | dbl_8D3030 | W | DynSolver_Matrix_8D3030 — (set to 0.0) [DERIVED] |
| 008d3050 | dbl_8D3050 | W | DynSolver_Workspace_3050 — row 21, diagonal (set to 1.0) [DERIVED] |
| 008d30b8 | dbl_8D30B8 | RW | DynamicsSolverBlock_8D30B8 — block-zeroed for next row group [DERIVED] |
| 008d30c0 | dbl_8D30C0 | W | DynamicsSolverElement_X5 — (set to 0.0) [DERIVED] |
| 008d30c8 | dbl_8D30C8 | W | DynSolver_Block13_Element? — (set to 0.0) [DERIVED] |
| 008d30d8 | dbl_8D30D8 | W | ConstraintMatrix_Body5_6 — row 22, diagonal (set to 1.0) [DERIVED] |
| 008d3138 | dbl_8D3138 | RW | DynMatrix_8D3138 — block-zeroed for next row group [DERIVED] |
| 008d3140 | dbl_8D3140 | W | Dyn_SolverBlock_3140 — (set to 0.0) [DERIVED] |
| 008d3148 | dbl_8D3148 | W | DynamicsMatrix_3_4_col1 — (set to 0.0) [DERIVED] |
| 008d3158 | dbl_8D3158 | W | DynamicsMatrixScalar — row 22, column 23 (set to 0.0); then row 23 diagonal set to 1.0 [DERIVED] |
| 008d3160 | dbl_8D3160 | W | DynSolver_Block13_Element24 — row 23, diagonal (set to 1.0) [DERIVED] |
| 008d31b8 | dbl_8D31B8 | RW | ConstraintMatrix_8D31B8 — block-zeroed for next row group [DERIVED] |
| 008d31c0 | dbl_8D31C0 | W | DynamicsMatrix_3_4_col0 — (set to 0.0) [DERIVED] |
| 008d31c8 | dbl_8D31C8 | W | DynMatrix_8D31C8 — (set to 0.0) [DERIVED] |
| 008d31d0 | dbl_8D31D0 | W | DynSolverMatrixElem_8D31D0 — (set to 0.0) [DERIVED] |
| 008d31d8 | dbl_8D31D8 | W | SolverBlock_8D31D8 — (set to 0.0) [DERIVED] |
| 008d31e0 | dbl_8D31E0 | W | DynSolver_MatrixBlock12b — (set to 0.0) [DERIVED] |
| 008d31e8 | dbl_8D31E8 | W | DynamicsMatrix_Block25 — (set to 0.0) [DERIVED] |
| 008d31f0 | dbl_8D31F0 | W | DynamicsSolver_BlockBody2 — (set to 0.0) [DERIVED] |
| 008d3210 | dbl_8D3210 | W | DynamicsSolver_Block64kC — row 21, column 24 (set to 0.0); also row 24 diagonal set to 1.0 [DERIVED] |
| 008d3228 | dbl_8D3228 | W | DynamicsMatrix_3_3 — row 24, diagonal (set to 1.0) [DERIVED] |
| 008d3278 | dbl_8D3278 | RW | DynSolver_Workspace_3278 — block-zeroed for next row group [DERIVED] |
| 008d3280 | dbl_8D3280 | W | SolverBlock_8D3280 — (set to 0.0) [DERIVED] |
| 008d3288 | dbl_8D3288 | W | ConstraintMatrix_8D3288 — (set to 0.0) [DERIVED] |
| 008d3290 | dbl_8D3290 | W | DynamicsMatrixBlock11 — (set to 0.0) [DERIVED] |
| 008d3298 | dbl_8D3298 | W | DynamicsSolverElement_X3 — (set to 0.0) [DERIVED] |
| 008d32a0 | dbl_8D32A0 | W | DynamicsBlock_32A0 — (set to 0.0) [DERIVED] |
| 008d32a8 | dbl_8D32A8 | W | DynSolverMatrixElem_8D32A8 — (set to 0.0) [DERIVED] |
| 008d32b0 | dbl_8D32B0 | W | DynamicsBlockElement_8D32B0 — (set to 0.0) [DERIVED] |
| 008d32d0 | dbl_8D32D0 | W | DynamicsBlockElement_8D32D0 — row 21, column 25 (set to 0.0) [DERIVED] |
| 008d32e8 | dbl_8D32E8 | W | SolverBlock_8D32E8 — row 24, column 25 (set to 0.0) [DERIVED] |
| 008d32f0 | dbl_8D32F0 | W | DynamicsSolverBias3 — row 25, diagonal (set to 1.0) [DERIVED] |
| 008d3338 | dbl_8D3338 | RW | DynamicsSolver_Block64kB — block-zeroed for next row group [DERIVED] |
| 008d3340 | dbl_8D3340 | W | Dynamics_Block33A8_ElemPre — (set to 0.0) [DERIVED] |
| 008d3348 | dbl_8D3348 | W | DynSolver_Matrix_8D3348 — (set to 0.0) [DERIVED] |
| 008d3350 | dbl_8D3350 | W | DynSolver_Block14_Element? — (set to 0.0) [DERIVED] |
| 008d3358 | dbl_8D3358 | W | Dyn_SolverBlock_3358 — (set to 0.0) [DERIVED] |
| 008d3360 | dbl_8D3360 | W | DynamicsMatrixBlock12 — (set to 0.0) [DERIVED] |
| 008d3368 | dbl_8D3368 | W | DynSolver_Block14_Element? — (set to 0.0) [DERIVED] |
| 008d3370 | dbl_8D3370 | W | DynSolver_MatrixBlock13 — (set to 0.0) [DERIVED] |
| 008d3390 | dbl_8D3390 | W | DynSolver_MatrixBlock12 — row 21, column 26 (set to 0.0) [DERIVED] |
| 008d33a8 | dbl_8D33A8 | W | DynamicsMatrix_Block24 — row 24, column 26 (set to 0.0) [DERIVED] |
| 008d33b0 | dbl_8D33B0 | W | DynSolver_Matrix_8D33B0 — row 25, column 26 (set to 0.0) [DERIVED] |
| 008d33b8 | dbl_8D33B8 | W | DynamicsMatrix_3_5 — row 26, diagonal (set to 1.0) [DERIVED] |
| 008d33f8 | dbl_8D33F8 | RW | DynamicsBlockElement_8D33F8 — block-zeroed for next row group [DERIVED] |
| 008d3400 | dbl_8D3400 | W | DynamicsBlock_8D3400 — (set to 0.0) [DERIVED] |
| 008d3408 | dbl_8D3408 | W | DynamicsSolver_BodyBlock1 — (set to 0.0) [DERIVED] |
| 008d3410 | dbl_8D3410 | W | DynamicsMatrix_4_0 — (set to 0.0) [DERIVED] |
| 008d3418 | dbl_8D3418 | W | DynSolverElem_12_0 — (set to 0.0) [DERIVED] |
| 008d3420 | dbl_8D3420 | W | DynamicsMatrix_4_1 — (set to 0.0) [DERIVED] |
| 008d3428 | dbl_8D3428 | W | SolverBlock_8D3428 — (set to 0.0) [DERIVED] |
| 008d3430 | dbl_8D3430 | W | DynamicsMatrix_Block28 — (set to 0.0) [DERIVED] |
| 008d3450 | dbl_8D3450 | W | DynamicsMatrix_Block29 — row 21, column 27 (set to 0.0) [DERIVED] |
| 008d3468 | dbl_8D3468 | RW | DynamicsBlock_8D3468 — zeroed via sub_58BB10 [DERIVED] |
| 008d3470 | dbl_8D3470 | W | DynamicsSolver_BodyBlock2 — (set to 0.0) [DERIVED] |
| 008d3478 | dbl_8D3478 | W | SolverBlock_8D3478 — (set to 0.0) [DERIVED] |
| 008d3480 | dbl_8D3480 | W | DynMatrix_8D3480 — row 27, diagonal (set to 1.0) [DERIVED] |
| 008d34b8 | dbl_8D34B8 | RW | DynSolver_MatrixBlock13b — block-zeroed for next row group [DERIVED] |
| 008d34c0 | dbl_8D34C0 | W | SolverBlock_8D34C0 — (set to 0.0) [DERIVED] |
| 008d34c8 | dbl_8D34C8 | W | DynamicsBlockElement_8D34C8 — (set to 0.0) [DERIVED] |
| 008d34d0 | dbl_8D34D0 | W | SolverBlock_8D34D0 — (set to 0.0) [DERIVED] |
| 008d34d8 | dbl_8D34D8 | W | DynamicsSolverBlock_8D34D8 — (set to 0.0) [DERIVED] |
| 008d34e0 | dbl_8D34E0 | W | Dynamics_Block34B8_Elem — (set to 0.0) [DERIVED] |
| 008d34e8 | dbl_8D34E8 | W | DynamicsBlock_8D34E8 — (set to 0.0) [DERIVED] |
| 008d34f0 | dbl_8D34F0 | W | DynamicsBlock_34F0 — (set to 0.0) [DERIVED] |
| 008d3510 | dbl_8D3510 | W | DynamicsBlock_11 — row 21, column 28 (set to 0.0) [DERIVED] |
| 008d3528 | dbl_8D3528 | RW | SolverBlock_8D3528 — zeroed via sub_58BB10 [DERIVED] |
| 008d3530 | dbl_8D3530 | W | DynamicsBlockElement_8D3530 — (set to 0.0) [DERIVED] |
| 008d3538 | dbl_8D3538 | W | Dynamics_Block3528_Elem — (set to 0.0) [DERIVED] |
| 008d3540 | dbl_8D3540 | W | ConstraintMatrix_8D3540 — (set to 0.0) [DERIVED] |
| 008d3548 | dbl_8D3548 | W | DynSolverMatrixElem_8D3548 — row 28, diagonal (set to 1.0) [DERIVED] |
| 008d3578 | dbl_8D3578 | RW | DynamicsMatrix_3_6 — block-zeroed for next row group [DERIVED] |
| 008d3580 | dbl_8D3580 | W | SolverBlock_8D3580 — (set to 0.0) [DERIVED] |
| 008d3588 | dbl_8D3588 | W | DynSolverMatrixElem_8D3588 — (set to 0.0) [DERIVED] |
| 008d3590 | dbl_8D3590 | W | DynSolverElem_13_0 — (set to 0.0) [DERIVED] |
| 008d3598 | dbl_8D3598 | W | DynamicsSolverBlock_8D3598 — (set to 0.0) [DERIVED] |
| 008d35a0 | dbl_8D35A0 | W | SolverBlock_8D35A0 — (set to 0.0) [DERIVED] |
| 008d35a8 | dbl_8D35A8 | W | DynSolverElem_13_2 — (set to 0.0) [DERIVED] |
| 008d35b0 | dbl_8D35B0 | W | DynamicsBlockElement_8D35B0 — (set to 0.0) [DERIVED] |
| 008d35b8 | dbl_8D35B8 | W | SolverBlock_8D35B8 — (set to 0.0) [DERIVED] |
| 008d35c0 | dbl_8D35C0 | W | Dyn_SolverBlock_35C0 — (set to 0.0) [DERIVED] |
| 008d35c8 | dbl_8D35C8 | W | DynSolver_MatrixBlock13d — (set to 0.0) [DERIVED] |
| 008d35d0 | dbl_8D35D0 | W | DynamicsBlock_8D35D0 — (set to 0.0) [DERIVED] |
| 008d35d8 | dbl_8D35D8 | W | DynSolver_Matrix_8D35D8 — (set to 0.0) [DERIVED] |
| 008d35e0 | dbl_8D35E0 | W | DynamicsMatrixBlock17 — (set to 0.0) [DERIVED] |
| 008d35e8 | dbl_8D35E8 | W | SolverBlock_8D35E8 — row 29, diagonal (set to 1.0) [DERIVED] |
| 008d3610 | dbl_8D3610 | RW | SolverBlock_8D3610 — block-zeroed for next row group [DERIVED] |
| 008d3618 | dbl_8D3618 | W | DynamicsSolverElement_X4 — (set to 0.0) [DERIVED] |
| 008d3620 | dbl_8D3620 | W | DynamicsMatrixBlock13 — (set to 0.0) [DERIVED] |
| 008d3628 | dbl_8D3628 | W | DynMatrix_8D3628 — (set to 0.0) [DERIVED] |
| 008d3630 | dbl_8D3630 | W | ConstraintMatrix_8D3630 — (set to 0.0) [DERIVED] |
| 008d3638 | dbl_8D3638 | W | Dynamics_Block3610_Elem — (set to 0.0) [DERIVED] |
| 008d3640 | dbl_8D3640 | W | DynamicsSolverBlock_8D3640 — (set to 0.0) [DERIVED] |
| 008d3648 | dbl_8D3648 | W | DynSolver_MatrixBlock14 — (set to 0.0) [DERIVED] |
| 008d3650 | dbl_8D3650 | W | DynamicsMatrix_4_3 — (set to 0.0) [DERIVED] |
| 008d3658 | dbl_8D3658 | W | DynamicsSolverElement_X7 — (set to 0.0) [DERIVED] |
| 008d3660 | dbl_8D3660 | W | DynamicsMatrix_Block30 — (set to 0.0) [DERIVED] |
| 008d3668 | dbl_8D3668 | W | SolverBlock_8D3668 — (set to 0.0) [DERIVED] |
| 008d3670 | dbl_8D3670 | W | DynamicsSolver_BodyBlock4 — (set to 0.0) [DERIVED] |
| 008d3678 | dbl_8D3678 | W | DynSolver_Block15_Element? — (set to 0.0) [DERIVED] |
| 008d3680 | dbl_8D3680 | W | DynamicsSolverElement_X9 — (set to 0.0) [DERIVED] |
| 008d3688 | dbl_8D3688 | W | ConstraintMatrix_8D3688 — row 30, diagonal (set to 1.0) [DERIVED] |
| 008d36a8 | dbl_8D36A8 | RW | DynamicsMatrix_Block136 — block-zeroed for next row group [DERIVED] |
| 008d36b0 | dbl_8D36B0 | W | Dyn_SolverBlock_36B0 — (set to 0.0) [DERIVED] |
| 008d36b8 | dbl_8D36B8 | W | DynSolver_Block15_Element? — (set to 0.0) [DERIVED] |
| 008d36c0 | dbl_8D36C0 | W | DynSolver_Matrix_8D36C0 — (set to 0.0) [DERIVED] |
| 008d36c8 | dbl_8D36C8 | W | DynamicsSolver_BlockBody3 — (set to 0.0) [DERIVED] |
| 008d36d0 | dbl_8D36D0 | W | DynamicsBlock_8D36D0 — (set to 0.0) [DERIVED] |
| 008d36d8 | dbl_8D36D8 | W | DynMatrix_8D36D8 — (set to 0.0) [DERIVED] |
| 008d36e0 | dbl_8D36E0 | W | DynamicsMatrix_Block31 — (set to 0.0) [DERIVED] |
| 008d36e8 | dbl_8D36E8 | W | DynSolver_Block15_Element? — (set to 0.0) [DERIVED] |
| 008d36f0 | dbl_8D36F0 | W | DynSolverElem_14_1 — (set to 0.0) [DERIVED] |
| 008d36f8 | dbl_8D36F8 | W | DynamicsBlock_36F8 — (set to 0.0) [DERIVED] |
| 008d3700 | dbl_8D3700 | W | DynamicsSolverElement_X8 — (set to 0.0) [DERIVED] |
| 008d3708 | dbl_8D3708 | W | DynamicsBlockElement_8D3708 — (set to 0.0) [DERIVED] |
| 008d3710 | dbl_8D3710 | W | DynamicsMatrix_4_4_col0 — (set to 0.0) [DERIVED] |
| 008d3718 | dbl_8D3718 | W | Dyn_SolverBlock_3718 — (set to 0.0) [DERIVED] |
| 008d3720 | dbl_8D3720 | W | DynSolver_Matrix_8D3720 — (set to 0.0) [DERIVED] |
| 008d3728 | dbl_8D3728 | W | DynamicsMatrix_Block32b — row 31, diagonal (set to 1.0) [DERIVED] |
| 008d3740 | dbl_8D3740 | RW | DynamicsBlock_8D3740 — block-zeroed for next row group [DERIVED] |
| 008d3748 | dbl_8D3748 | W | DynSolverElem_14_0 — (set to 0.0) [DERIVED] |
| 008d3750 | dbl_8D3750 | W | DynamicsMatrix_4_5 — (set to 0.0) [DERIVED] |
| 008d3758 | dbl_8D3758 | W | DynamicsBlockElement_8D3758 — (set to 0.0) [DERIVED] |
| 008d3760 | dbl_8D3760 | W | DynSolver_MatrixBlock14b — (set to 0.0) [DERIVED] |
| 008d3768 | dbl_8D3768 | W | SolverBlock_8D3768 — (set to 0.0) [DERIVED] |
| 008d3770 | dbl_8D3770 | W | ConstraintMatrix_8D3770 — (set to 0.0) [DERIVED] |
| 008d3778 | dbl_8D3778 | W | DynamicsBlock_3778 — (set to 0.0) [DERIVED] |
| 008d3780 | dbl_8D3780 | W | Dynamics_Block3740_Elem — (set to 0.0) [DERIVED] |
| 008d3788 | dbl_8D3788 | W | DynamicsSolverBlock_8D3788 — (set to 0.0) [DERIVED] |
| 008d3790 | dbl_8D3790 | W | DynSolverMatrixElem_8D3790 — (set to 0.0) [DERIVED] |
| 008d3798 | dbl_8D3798 | W | Dyn_SolverBlock_3798 — (set to 0.0) [DERIVED] |
| 008d37a0 | dbl_8D37A0 | W | DynSolver_MatrixBlock14c — (set to 0.0) [DERIVED] |
| 008d37a8 | dbl_8D37A8 | W | SolverBlock_8D37A8 — (set to 0.0) [DERIVED] |
| 008d37b0 | dbl_8D37B0 | W | DynSolverElem_14_2 — (set to 0.0) [DERIVED] |
| 008d37b8 | dbl_8D37B8 | W | DynamicsSolver_BodyBlock5 — (set to 0.0) [DERIVED] |
| 008d37c0 | dbl_8D37C0 | W | DynamicsBlock_37C0 — (set to 0.0) [DERIVED] |
| 008d37c8 | dbl_8D37C8 | W | DynSolver_Block16_Element? — row 32, diagonal (set to 1.0) [DERIVED] |
| 008d37d8 | dbl_8D37D8 | RW | SolverBlock_8D37D8 — block-zeroed for next row group [DERIVED] |
| 008d37e0 | dbl_8D37E0 | W | DynamicsSolverBlock_8D37E0 — (set to 0.0) [DERIVED] |
| 008d37e8 | dbl_8D37E8 | W | SolverBlock_8D37E8 — (set to 0.0) [DERIVED] |
| 008d37f0 | dbl_8D37F0 | W | DynamicsMatrix_Block33 — (set to 0.0) [DERIVED] |
| 008d37f8 | dbl_8D37F8 | W | DynamicsBlock_37F8 — (set to 0.0) [DERIVED] |
| 008d3800 | dbl_8D3800 | W | DynamicsSolverElement_X6 — (set to 0.0) [DERIVED] |
| 008d3808 | dbl_8D3808 | W | DynSolver_Matrix_8D3808 — (set to 0.0) [DERIVED] |
| 008d3810 | dbl_8D3810 | W | DynSolverMatrixElem_8D3810 — (set to 0.0) [DERIVED] |
| 008d3818 | dbl_8D3818 | W | DynamicsBlock_8D3818 — (set to 0.0) [DERIVED] |
| 008d3820 | dbl_8D3820 | W | DynMatrix_8D3820 — (set to 0.0) [DERIVED] |
| 008d3828 | dbl_8D3828 | W | DynamicsMatrixBlock16 — (set to 0.0) [DERIVED] |
| 008d3830 | dbl_8D3830 | W | DynSolverElem_14_3 — (set to 0.0) [DERIVED] |
| 008d3838 | dbl_8D3838 | W | DynamicsMatrix_Block32 — (set to 0.0) [DERIVED] |
| 008d3840 | dbl_8D3840 | W | Dynamics_Block3870_Elem4 — (set to 0.0) [DERIVED] |
| 008d3848 | dbl_8D3848 | W | DynamicsSolverBlock_8D3848 — (set to 0.0) [DERIVED] |
| 008d3850 | dbl_8D3850 | W | DynamicsBlockElement_8D3850 — (set to 0.0) [DERIVED] |
| 008d3858 | dbl_8D3858 | W | DynSolverMatrixElem_8D3858 — (set to 0.0) [DERIVED] |
| 008d3860 | dbl_8D3860 | W | DynamicsMatrix_4_5_col0 — (set to 0.0) [DERIVED] |
| 008d3868 | dbl_8D3868 | W | Dynamics_Block3870_Elem5 — row 33, diagonal (set to 1.0) [DERIVED] |
| 008d3870 | dbl_8D3870 | W | DynamicsBlock_14 — various [DERIVED] |
| 008d3878 | dbl_8D3878 | W | DynSolver_Block16_Element? — various [DERIVED] |
| 008d3880 | dbl_8D3880 | W | DynamicsSolver_DiagBlock6 — various [DERIVED] |
| 008d3888 | dbl_8D3888 | W | SolverBlock_8D3888 — various [DERIVED] |
| 008d3890 | dbl_8D3890 | W | DynamicsMatrix_Block34 — various [DERIVED] |
| 008d3898 | dbl_8D3898 | W | DynamicsSolverElement_X1 — various [DERIVED] |
| 008d38a0 | dbl_8D38A0 | W | DynSolver_MatrixBlock14e — various [DERIVED] |
| 008d38a8 | dbl_8D38A8 | W | Dynamics_Block3870_Elem — various [DERIVED] |
| 008d38b0 | dbl_8D38B0 | W | DynMatrix_8D38B0 — various [DERIVED] |
| 008d38b8 | dbl_8D38B8 | W | DynamicsMatrix_Block35 — various [DERIVED] |
| 008d38c0 | dbl_8D38C0 | W | DynamicsBlock_38C0 — various [DERIVED] |
| 008d38c8 | dbl_8D38C8 | W | DynamicsSolverElement_X2 — various [DERIVED] |
| 008d38d0 | dbl_8D38D0 | W | DynSolver_MatrixBlock14f — various [DERIVED] |
| 008d38d8 | dbl_8D38D8 | W | Dynamics_Block3870_Elem2 — various [DERIVED] |
| 008d38e0 | dbl_8D38E0 | W | DynMatrix_8D38E0 — various [DERIVED] |
| 008d38e8 | dbl_8D38E8 | W | DynSolver_Matrix_8D38E8 — various [DERIVED] |
| 008d38f0 | dbl_8D38F0 | W | DynMatrix_8D38F0 — various [DERIVED] |
| 008d38f8 | dbl_8D38F8 | W | Dynamics_Block3870_Elem3 — various [DERIVED] |
| 008d3900 | dbl_8D3900 | W | DynamicsBlock_8D3900 — various [DERIVED] |
| 008d3908 | dbl_8D3908 | W | DynSolverMatrixElem_8D3908 — various [DERIVED] |
| 008d3910 | dbl_8D3910 | W | Dyn_SolverBlock_3910 — various [DERIVED] |
| 008d3918 | dbl_8D3918 | W | DynamicsSolver_BodyBlock7 — various [DERIVED] |
| 008d3920 | dbl_8D3920 | W | DynamicsMatrixBlock15 — various [DERIVED] |
| 008d3928 | dbl_8D3928 | W | SolverBlock_8D3928 — various [DERIVED] |
| 008d3930 | dbl_8D3930 | W | ConstraintMatrix_8D3930 — various [DERIVED] |
| 008d3938 | dbl_8D3938 | W | DynSolver_Block16_Element? — various [DERIVED] |
| 008d3940 | dbl_8D3940 | W | DynamicsSolverBlock_8D3940 — various [DERIVED] |
| 008d3948 | dbl_8D3948 | W | DynamicsBlock_3948 — various [DERIVED] |
| 008d3950 | dbl_8D3950 | W | DynamicsBlock_8D3950 — various [DERIVED] |
| 008d3958 | dbl_8D3958 | W | DynMatrix_8D3958 — various [DERIVED] |
| 008d3960 | dbl_8D3960 | W | DynSolver_MatrixBlock14g — various [DERIVED] |
| 008d3968 | dbl_8D3968 | W | DynamicsMatrixBlock18 — various [DERIVED] |
| 008d3970 | dbl_8D3970 | W | SolverBlock_8D3970 — various [DERIVED] |
| 008d3978 | dbl_8D3978 | W | DynamicsBlock_8D3978 — various [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | Zero-initializes a block of double-precision floats (memset-like) — clears a predecessor segment of the constraint matrix row before setting the diagonal |

**Guard conditions:** Switch on `a1` (case 0–33): dispatches to the appropriate row initialization block. `default` case does nothing (no writes, early return). No conditional blocking — all valid cases execute their row init and return.
