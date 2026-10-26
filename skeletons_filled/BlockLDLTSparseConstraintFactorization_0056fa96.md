## BlockLDLTSparseConstraintFactorization_0056fa96 — Block LDL^T Sparse Constraint Matrix Factorization (Dynamics Solver)

**Summary:** Performs block-LDL^T factorization of a sparse constraint matrix for the vehicle dynamics physics engine, computing L and D factors plus the solution vector via forward/backward substitution. Standalone numeric routine with no callees — all computation done on global double workspace arrays and index tables.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008cfbf0 | dbl_8CFBF0 | R | input: first diagonal block pivot of the constraint matrix |
| 008cfbf8 | dbl_8CFBF8 | RW | workspace: L factor block (1/diag * off-diag), column 0 |
| 008cfc00 | dbl_8CFC00 | RW | workspace: L factor block, column 0 row 1 |
| 008cfc20 | dbl_8CFC20 | RW | workspace: L factor block, column 0 row 2 |
| 008cfc28 | dbl_8CFC28 | RW | workspace: L factor block, column 0 row 3 |
| 008cfc90 | unk_8CFC90 | R | input: constraint matrix off-diagonal block pointer array (40 double entries) |
| 008cfcb8 | dbl_8CFCB8 | R | input: constraint matrix element at row 0, col 0 off-diag |
| 008cfcc0 | dbl_8CFCC0 | RW | workspace: D factor diagonal after rank-1 update (Schur complement), block 1 |
| 008cfcc8 | dbl_8CFCC8 | RW | workspace: L factor block, column 1 |
| 008cfce8 | dbl_8CFCE8 | RW | workspace: L factor block, column 1 row 1 |
| 008cfcf0 | dbl_8CFCF0 | RW | workspace: L factor block, column 1 row 2 |
| 008cfd58 | unk_8CFD58 | R | input: constraint matrix off-diagonal block pointer array (40 entries) |
| 008cfd80 | dbl_8CFD80 | R | input: constraint matrix element at row 0, col 0 off-diag 2 |
| 008cfd88 | dbl_8CFD88 | RW | workspace: D factor update, block 1 row 0 |
| 008cfd90 | dbl_8CFD90 | RW | workspace: D factor diagonal after rank-2 update, block 2 |
| 008cfdb0 | dbl_8CFDB0 | RW | workspace: L factor block, column 2 row 0 |
| 008cfdb8 | dbl_8CFDB8 | RW | workspace: L factor block, column 2 row 1 |
| 008cfe20 | unk_8CFE20 | R | input: constraint matrix off-diagonal block pointer array |
| 008cfe48 | dbl_8CFE48 | R | input: next diagonal pivot for block 3 |
| 008cfe50 | dbl_8CFE50 | RW | workspace: L factor block, column 3 |
| 008cfe58 | dbl_8CFE58 | RW | workspace: L factor block, column 3 row 1 |
| 008cfe70 | dbl_8CFE70 | RW | workspace: L factor block, column 3 row 2 |
| 008cfe78 | dbl_8CFE78 | RW | workspace: L factor block, column 3 row 3 |
| 008cfef8 | unk_8CFEF8 | R | input: constraint matrix off-diagonal block pointer array |
| 008cff20 | dbl_8CFF20 | R | input: constraint matrix element for off-diagonal update |
| 008cff28 | dbl_8CFF28 | RW | workspace: D factor diagonal after rank-1 update, block 3 |
| 008cff30 | dbl_8CFF30 | RW | workspace: L factor block, column 3 row 0 inner |
| 008cff48 | dbl_8CFF48 | RW | workspace: L factor block, column 3 row 1 inner |
| 008cff50 | dbl_8CFF50 | RW | workspace: L factor block, column 3 row 2 inner |
| 008cffd0 | unk_8CFFD0 | R | input: constraint matrix off-diagonal block pointer array |
| 008cfff8 | dbl_8CFFF8 | R | input: constraint matrix element for off-diagonal update |
| 008d0000 | dbl_8D0000 | RW | workspace: intermediate D update term |
| 008d0008 | dbl_8D0008 | RW | workspace: D factor diagonal after rank-2 update, block 4 |
| 008d0020 | dbl_8D0020 | RW | workspace: L factor block, column 4 |
| 008d0028 | dbl_8D0028 | RW | workspace: L factor block, column 4 row 1 |
| 008d00a8 | unk_8D00A8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d00d0 | dbl_8D00D0 | R | input: constraint matrix element for off-diagonal update |
| 008d00d8 | dbl_8D00D8 | RW | workspace: D factor update term |
| 008d00e0 | dbl_8D00E0 | RW | workspace: intermediate L factor computation |
| 008d0100 | dbl_8D0100 | RW | workspace: D factor diagonal after multi-rank update, block 5 |
| 008d0108 | dbl_8D0108 | RW | workspace: L factor block for backward substitution |
| 008d0170 | unk_8D0170 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0190 | dbl_8D0190 | R | input: constraint matrix element (base vector) |
| 008d0198 | dbl_8D0198 | R | input: constraint matrix element for off-diagonal |
| 008d01a0 | dbl_8D01A0 | RW | workspace: D factor update |
| 008d01a8 | dbl_8D01A8 | RW | workspace: intermediate L factor |
| 008d01c8 | dbl_8D01C8 | RW | workspace: L factor for backward substitution |
| 008d01d0 | dbl_8D01D0 | RW | workspace: D factor diagonal after further updates |
| 008d0238 | unk_8D0238 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0258 | dbl_8D0258 | R | input: constraint matrix element (coupled term) |
| 008d0260 | dbl_8D0260 | R | input: constraint matrix element for off-diagonal |
| 008d0268 | dbl_8D0268 | RW | workspace: L factor / D update term |
| 008d0270 | dbl_8D0270 | RW | workspace: intermediate L factor computation |
| 008d0288 | dbl_8D0288 | RW | workspace: D factor diagonal, block 6 |
| 008d0290 | dbl_8D0290 | RW | workspace: L factor block for backward substitution |
| 008d0310 | unk_8D0310 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0330 | dbl_8D0330 | R | input: constraint matrix element (coupled term) |
| 008d0338 | dbl_8D0338 | R | input: constraint matrix element for off-diagonal |
| 008d0340 | dbl_8D0340 | RW | workspace: L factor / D update term |
| 008d0348 | dbl_8D0348 | RW | workspace: intermediate L factor |
| 008d0360 | dbl_8D0360 | RW | workspace: D factor update |
| 008d0368 | dbl_8D0368 | RW | workspace: D factor diagonal, block 7 |
| 008d03e8 | unk_8D03E8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0408 | dbl_8D0408 | R | input: constraint matrix element (coupled term) |
| 008d0410 | dbl_8D0410 | R | input: next diagonal pivot for block 8 |
| 008d0418 | dbl_8D0418 | RW | workspace: L factor block, column 8 |
| 008d0420 | dbl_8D0420 | RW | workspace: L factor block, column 8 row 1 |
| 008d0440 | dbl_8D0440 | RW | workspace: L factor block, column 8 row 2 |
| 008d0448 | dbl_8D0448 | RW | workspace: L factor block, column 8 row 3 |
| 008d04b0 | unk_8D04B0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d04d8 | dbl_8D04D8 | R | input: constraint matrix element for off-diagonal |
| 008d04e0 | dbl_8D04E0 | RW | workspace: D factor diagonal after rank-1 update, block 8 |
| 008d04e8 | dbl_8D04E8 | RW | workspace: L factor block, column 8 row 0 inner |
| 008d0508 | dbl_8D0508 | RW | workspace: L factor block, column 8 row 1 inner |
| 008d0510 | dbl_8D0510 | RW | workspace: L factor block, column 8 row 2 inner |
| 008d0578 | unk_8D0578 | R | input: constraint matrix off-diagonal block pointer array |
| 008d05a0 | dbl_8D05A0 | R | input: constraint matrix element for off-diagonal |
| 008d05a8 | dbl_8D05A8 | RW | workspace: D factor update term |
| 008d05b0 | dbl_8D05B0 | RW | workspace: D factor diagonal after rank-2 update, block 9 |
| 008d05d0 | dbl_8D05D0 | RW | workspace: L factor block, column 9 |
| 008d05d8 | dbl_8D05D8 | RW | workspace: L factor block, column 9 row 1 |
| 008d0640 | unk_8D0640 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0668 | dbl_8D0668 | R | input: next diagonal pivot for block 10 |
| 008d0670 | dbl_8D0670 | RW | workspace: L factor block, column 10 |
| 008d0678 | dbl_8D0678 | RW | workspace: L factor block, column 10 row 1 |
| 008d0690 | dbl_8D0690 | RW | workspace: L factor block, column 10 row 2 |
| 008d0698 | dbl_8D0698 | RW | workspace: L factor block, column 10 row 3 |
| 008d0718 | unk_8D0718 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0740 | dbl_8D0740 | R | input: constraint matrix element for off-diagonal |
| 008d0748 | dbl_8D0748 | RW | workspace: D factor diagonal after rank-1 update, block 10 |
| 008d0750 | dbl_8D0750 | RW | workspace: L factor block, column 10 row 0 inner |
| 008d0768 | dbl_8D0768 | RW | workspace: L factor block, column 10 row 1 inner |
| 008d0770 | dbl_8D0770 | RW | workspace: L factor block, column 10 row 2 inner |
| 008d07f0 | unk_8D07F0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0818 | dbl_8D0818 | R | input: constraint matrix element for off-diagonal |
| 008d0820 | dbl_8D0820 | RW | workspace: D factor update term |
| 008d0828 | dbl_8D0828 | RW | workspace: D factor diagonal after rank-2 update, block 11 |
| 008d0840 | dbl_8D0840 | RW | workspace: L factor block, column 11 |
| 008d0848 | dbl_8D0848 | RW | workspace: L factor block, column 11 row 1 |
| 008d08c8 | unk_8D08C8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d08f0 | dbl_8D08F0 | R | input: constraint matrix element for off-diagonal |
| 008d08f8 | dbl_8D08F8 | RW | workspace: D factor update term |
| 008d0900 | dbl_8D0900 | RW | workspace: intermediate L factor |
| 008d0920 | dbl_8D0920 | RW | workspace: D factor diagonal after multi-rank update, block 12 |
| 008d0928 | dbl_8D0928 | RW | workspace: L factor for backward substitution |
| 008d0990 | unk_8D0990 | R | input: constraint matrix off-diagonal block pointer array |
| 008d09b0 | dbl_8D09B0 | R | input: constraint matrix element (coupled term) |
| 008d09b8 | dbl_8D09B8 | R | input: constraint matrix element for off-diagonal |
| 008d09c0 | dbl_8D09C0 | RW | workspace: D factor update |
| 008d09c8 | dbl_8D09C8 | RW | workspace: intermediate L factor |
| 008d09e8 | dbl_8D09E8 | RW | workspace: L factor for backward substitution |
| 008d09f0 | dbl_8D09F0 | RW | workspace: D factor diagonal, block 13 |
| 008d0a58 | unk_8D0A58 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0a78 | dbl_8D0A78 | R | input: constraint matrix element (coupled term) |
| 008d0a80 | dbl_8D0A80 | R | input: constraint matrix element for off-diagonal |
| 008d0a88 | dbl_8D0A88 | RW | workspace: D factor update |
| 008d0a90 | dbl_8D0A90 | RW | workspace: intermediate L factor |
| 008d0aa8 | dbl_8D0AA8 | RW | workspace: D factor diagonal, block 14 |
| 008d0ab0 | dbl_8D0AB0 | RW | workspace: L factor for backward substitution |
| 008d0b30 | unk_8D0B30 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0b58 | dbl_8D0B58 | R | input: constraint matrix element |
| 008d0b60 | dbl_8D0B60 | RW | workspace: D factor update |
| 008d0b68 | dbl_8D0B68 | RW | workspace: intermediate L factor |
| 008d0b80 | dbl_8D0B80 | RW | workspace: D factor diagonal update |
| 008d0b88 | dbl_8D0B88 | RW | workspace: D factor diagonal, block 15 |
| 008d0c08 | unk_8D0C08 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0c30 | dbl_8D0C30 | R | input: constraint matrix element |
| 008d0c38 | dbl_8D0C38 | RW | workspace: D factor update |
| 008d0c40 | dbl_8D0C40 | RW | workspace: intermediate D update |
| 008d0c60 | dbl_8D0C60 | RW | workspace: D factor update, block row 0 |
| 008d0c68 | dbl_8D0C68 | RW | workspace: D factor diagonal (accumulated), block row 0 |
| 008d0cd0 | dbl_8D0CD0 | RW | workspace: D factor diagonal for block 16 (after multi-column rank updates) |
| 008d0cd8 | dbl_8D0CD8 | R | input: constraint matrix element (pre-computed coefficient) |
| 008d0d70 | dbl_8D0D70 | R | input: constraint matrix sub-block pointer for column operations |
| 008d0d78 | dbl_8D0D78 | RW | workspace: D factor update, coupled term |
| 008d0d80 | dbl_8D0D80 | RW | workspace: intermediate D update |
| 008d0da0 | dbl_8D0DA0 | RW | workspace: D factor update, block row 1 |
| 008d0da8 | dbl_8D0DA8 | RW | workspace: D factor diagonal (accumulated), block row 1 |
| 008d0e10 | dbl_8D0E10 | RW | workspace: D factor update for next column |
| 008d0e18 | dbl_8D0E18 | RW | workspace: D factor diagonal, block 17 (after rank updates) |
| 008d0e20 | unk_8D0E20 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0eb0 | dbl_8D0EB0 | R | input: constraint matrix sub-block pointer for column operations |
| 008d0eb8 | dbl_8D0EB8 | RW | workspace: D factor update, coupled term |
| 008d0ec0 | dbl_8D0EC0 | RW | workspace: intermediate D update |
| 008d0ee0 | dbl_8D0EE0 | RW | workspace: D factor update, block row 2 |
| 008d0ee8 | dbl_8D0EE8 | RW | workspace: D factor diagonal (accumulated), block row 2 |
| 008d0f50 | dbl_8D0F50 | RW | workspace: D factor update for next column |
| 008d0f58 | dbl_8D0F58 | RW | workspace: intermediate D update |
| 008d0f60 | dbl_8D0F60 | RW | workspace: D factor diagonal, block 18 (after multi-rank updates) |
| 008d0f68 | unk_8D0F68 | R | input: constraint matrix off-diagonal block pointer array |
| 008d0ff0 | dbl_8D0FF0 | R | input: constraint matrix sub-block pointer for column operations |
| 008d0ff8 | dbl_8D0FF8 | RW | workspace: D factor update, coupled term |
| 008d1000 | dbl_8D1000 | RW | workspace: intermediate D update |
| 008d1020 | dbl_8D1020 | RW | workspace: D factor update, block row 3 |
| 008d1028 | dbl_8D1028 | RW | workspace: D factor diagonal (accumulated), block row 3 |
| 008d1090 | dbl_8D1090 | RW | workspace: D factor update for next column |
| 008d1098 | dbl_8D1098 | RW | workspace: intermediate D update |
| 008d10a0 | dbl_8D10A0 | RW | workspace: D factor update for block row |
| 008d10a8 | dbl_8D10A8 | RW | workspace: D factor diagonal, block 19 (after multi-rank updates) |
| 008d10b0 | unk_8D10B0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1130 | dbl_8D1130 | R | input: constraint matrix sub-block pointer for column operations |
| 008d1138 | dbl_8D1138 | RW | workspace: D factor update, coupled term |
| 008d1140 | dbl_8D1140 | RW | workspace: intermediate D update |
| 008d1160 | dbl_8D1160 | RW | workspace: D factor update, block row 4 |
| 008d1168 | dbl_8D1168 | RW | workspace: D factor diagonal (accumulated), block row 4 |
| 008d11d0 | dbl_8D11D0 | RW | workspace: D factor update for next column |
| 008d11d8 | dbl_8D11D8 | RW | workspace: intermediate D update |
| 008d11e0 | dbl_8D11E0 | RW | workspace: D factor update for block row |
| 008d11e8 | dbl_8D11E8 | RW | workspace: intermediate term update |
| 008d11f0 | dbl_8D11F0 | RW | workspace: D factor diagonal, block 20 (after multi-rank updates) |
| 008d11f8 | unk_8D11F8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1270 | dbl_8D1270 | R | input: constraint matrix diagonal entry (sub-block) |
| 008d1278 | dbl_8D1278 | RW | workspace: D factor update |
| 008d1280 | dbl_8D1280 | RW | workspace: intermediate D update |
| 008d1298 | dbl_8D1298 | RW | workspace: D factor update, block row 0 for block 7 sub |
| 008d12a0 | dbl_8D12A0 | RW | workspace: D factor diagonal (accumulated), block 7 sub-row 0 |
| 008d12f8 | dbl_8D12F8 | R | input: constraint matrix element (sub-block coefficient) |
| 008d1300 | dbl_8D1300 | RW | workspace: D factor update for next stage |
| 008d1308 | dbl_8D1308 | RW | workspace: intermediate term |
| 008d1310 | dbl_8D1310 | RW | workspace: intermediate term |
| 008d1318 | dbl_8D1318 | RW | workspace: intermediate term |
| 008d1320 | dbl_8D1320 | RW | workspace: D factor diagonal, block 21 (after multi-rank updates) |
| 008d1328 | unk_8D1328 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1398 | dbl_8D1398 | R | input: constraint matrix sub-block pointer |
| 008d13a0 | dbl_8D13A0 | RW | workspace: D factor update |
| 008d13a8 | dbl_8D13A8 | RW | workspace: intermediate D update |
| 008d13c0 | dbl_8D13C0 | RW | workspace: D factor update, block row 1 for block 7 sub |
| 008d13c8 | dbl_8D13C8 | RW | workspace: D factor diagonal (accumulated), block 7 sub-row 1 |
| 008d1420 | dbl_8D1420 | R | input: constraint matrix sub-block base pointer |
| 008d1428 | dbl_8D1428 | RW | workspace: intermediate term |
| 008d1430 | dbl_8D1430 | RW | workspace: intermediate term |
| 008d1438 | dbl_8D1438 | RW | workspace: intermediate term |
| 008d1440 | dbl_8D1440 | RW | workspace: intermediate term |
| 008d1448 | dbl_8D1448 | RW | workspace: D factor diagonal (intermediate) |
| 008d1450 | dbl_8D1450 | RW | workspace: D factor diagonal, block 22 (after multi-rank updates) |
| 008d1458 | unk_8D1458 | R | input: constraint matrix off-diagonal block pointer array |
| 008d14c0 | dbl_8D14C0 | R | input: constraint matrix diagonal entry |
| 008d14c8 | dbl_8D14C8 | RW | workspace: D factor update |
| 008d14d0 | dbl_8D14D0 | RW | workspace: intermediate D update |
| 008d14e8 | dbl_8D14E8 | RW | workspace: D factor update, block row 2 for block 7 sub |
| 008d14f0 | dbl_8D14F0 | RW | workspace: D factor diagonal (accumulated), block 7 sub-row 2 |
| 008d1548 | dbl_8D1548 | R | input: constraint matrix sub-block pointer |
| 008d1550 | dbl_8D1550 | RW | workspace: intermediate term |
| 008d1558 | dbl_8D1558 | RW | workspace: intermediate term |
| 008d1560 | dbl_8D1560 | RW | workspace: intermediate term |
| 008d1568 | dbl_8D1568 | RW | workspace: intermediate term |
| 008d1570 | dbl_8D1570 | RW | workspace: intermediate term |
| 008d1578 | dbl_8D1578 | RW | workspace: D factor diagonal (intermediate) |
| 008d1580 | dbl_8D1580 | RW | workspace: D factor diagonal, block 23 (after multi-rank updates) |
| 008d1588 | unk_8D1588 | R | input: constraint matrix off-diagonal block pointer array |
| 008d15e8 | dbl_8D15E8 | R | input: constraint matrix diagonal entry |
| 008d15f0 | dbl_8D15F0 | RW | workspace: D factor update |
| 008d15f8 | dbl_8D15F8 | RW | workspace: intermediate D update |
| 008d1610 | dbl_8D1610 | RW | workspace: D factor update, block row 3 for block 7 sub |
| 008d1618 | dbl_8D1618 | RW | workspace: D factor diagonal (accumulated), block 7 sub-row 3 |
| 008d1670 | dbl_8D1670 | R | input: constraint matrix sub-block pointer |
| 008d1678 | dbl_8D1678 | RW | workspace: intermediate term |
| 008d1680 | dbl_8D1680 | RW | workspace: intermediate term |
| 008d1688 | dbl_8D1688 | RW | workspace: intermediate term |
| 008d1690 | dbl_8D1690 | RW | workspace: intermediate term |
| 008d1698 | dbl_8D1698 | RW | workspace: intermediate term |
| 008d16a0 | dbl_8D16A0 | RW | workspace: D factor diagonal (intermediate) |
| 008d16a8 | dbl_8D16A8 | RW | workspace: D factor diagonal (intermediate) |
| 008d16b0 | dbl_8D16B0 | RW | workspace: D factor diagonal, block 24 (after multi-rank updates) |
| 008d16b8 | unk_8D16B8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1710 | dbl_8D1710 | R | input: constraint matrix diagonal entry |
| 008d1718 | dbl_8D1718 | RW | workspace: D factor update |
| 008d1720 | dbl_8D1720 | RW | workspace: intermediate D update |
| 008d1738 | dbl_8D1738 | RW | workspace: D factor update, block row 4 for block 7 sub |
| 008d1740 | dbl_8D1740 | RW | workspace: D factor diagonal (accumulated), block 7 sub-row 4 |
| 008d1798 | dbl_8D1798 | R | input: constraint matrix sub-block pointer |
| 008d17a0 | dbl_8D17A0 | RW | workspace: intermediate term |
| 008d17a8 | dbl_8D17A8 | RW | workspace: intermediate term |
| 008d17b0 | dbl_8D17B0 | RW | workspace: intermediate term |
| 008d17b8 | dbl_8D17B8 | RW | workspace: intermediate term |
| 008d17c0 | dbl_8D17C0 | RW | workspace: intermediate term |
| 008d17c8 | dbl_8D17C8 | RW | workspace: D factor diagonal (intermediate) |
| 008d17d0 | dbl_8D17D0 | RW | workspace: D factor update |
| 008d17d8 | dbl_8D17D8 | RW | workspace: intermediate term |
| 008d17e0 | dbl_8D17E0 | RW | workspace: D factor diagonal, block 25 (after multi-rank updates) |
| 008d17e8 | unk_8D17E8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1838 | dbl_8D1838 | R | input: constraint matrix element |
| 008d1840 | dbl_8D1840 | RW | workspace: D factor update |
| 008d1848 | dbl_8D1848 | RW | workspace: intermediate D update |
| 008d1868 | dbl_8D1868 | RW | workspace: D factor update, block row |
| 008d1870 | dbl_8D1870 | RW | workspace: D factor diagonal (accumulated) |
| 008d1888 | dbl_8D1888 | R | input: constraint matrix element (sub-block) |
| 008d1890 | dbl_8D1890 | RW | workspace: intermediate term |
| 008d1898 | dbl_8D1898 | RW | workspace: intermediate term |
| 008d18a0 | dbl_8D18A0 | RW | workspace: intermediate term |
| 008d18a8 | dbl_8D18A8 | RW | workspace: intermediate term |
| 008d18b0 | dbl_8D18B0 | RW | workspace: intermediate term |
| 008d18b8 | dbl_8D18B8 | RW | workspace: intermediate term |
| 008d18c0 | dbl_8D18C0 | RW | workspace: intermediate term |
| 008d18c8 | dbl_8D18C8 | RW | workspace: intermediate term |
| 008d18d0 | dbl_8D18D0 | RW | workspace: D factor diagonal (intermediate) |
| 008d18d8 | dbl_8D18D8 | RW | workspace: D factor diagonal, block 26 (after multi-rank updates) |
| 008d18e0 | unk_8D18E0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1928 | dbl_8D1928 | R | input: constraint matrix element |
| 008d1930 | dbl_8D1930 | RW | workspace: D factor update |
| 008d1938 | dbl_8D1938 | RW | workspace: intermediate D update |
| 008d1958 | dbl_8D1958 | RW | workspace: D factor update, block row |
| 008d1960 | dbl_8D1960 | RW | workspace: D factor diagonal (accumulated) |
| 008d1978 | dbl_8D1978 | R | input: constraint matrix sub-block base pointer |
| 008d1980 | dbl_8D1980 | RW | workspace: intermediate term |
| 008d1988 | dbl_8D1988 | RW | workspace: intermediate term |
| 008d1990 | dbl_8D1990 | RW | workspace: intermediate term |
| 008d1998 | dbl_8D1998 | RW | workspace: intermediate term |
| 008d19a0 | dbl_8D19A0 | RW | workspace: intermediate term |
| 008d19a8 | dbl_8D19A8 | RW | workspace: intermediate term |
| 008d19b0 | dbl_8D19B0 | RW | workspace: intermediate term |
| 008d19b8 | dbl_8D19B8 | RW | workspace: intermediate term |
| 008d19c0 | dbl_8D19C0 | RW | workspace: intermediate term |
| 008d19c8 | dbl_8D19C8 | RW | workspace: D factor diagonal (intermediate) |
| 008d19d0 | dbl_8D19D0 | RW | workspace: D factor diagonal, block 27 (after multi-rank updates) |
| 008d19d8 | unk_8D19D8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1a18 | dbl_8D1A18 | R | input: constraint matrix element |
| 008d1a20 | dbl_8D1A20 | RW | workspace: D factor update |
| 008d1a28 | dbl_8D1A28 | RW | workspace: intermediate D update |
| 008d1a48 | dbl_8D1A48 | RW | workspace: D factor update, block row |
| 008d1a50 | dbl_8D1A50 | RW | workspace: D factor diagonal (accumulated) |
| 008d1a68 | dbl_8D1A68 | R | input: constraint matrix element (sub-block) |
| 008d1a70 | dbl_8D1A70 | RW | workspace: intermediate term |
| 008d1a78 | dbl_8D1A78 | RW | workspace: intermediate term |
| 008d1a80 | dbl_8D1A80 | RW | workspace: intermediate term |
| 008d1a88 | dbl_8D1A88 | RW | workspace: intermediate term |
| 008d1a90 | dbl_8D1A90 | RW | workspace: intermediate term |
| 008d1a98 | dbl_8D1A98 | RW | workspace: intermediate term |
| 008d1aa0 | dbl_8D1AA0 | RW | workspace: intermediate term |
| 008d1aa8 | dbl_8D1AA8 | RW | workspace: intermediate term |
| 008d1ab0 | dbl_8D1AB0 | RW | workspace: intermediate term |
| 008d1ab8 | dbl_8D1AB8 | RW | workspace: intermediate term |
| 008d1ac0 | dbl_8D1AC0 | RW | workspace: intermediate term |
| 008d1ac8 | dbl_8D1AC8 | RW | workspace: D factor diagonal, block 28 (after multi-rank updates) |
| 008d1ad0 | unk_8D1AD0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1b08 | dbl_8D1B08 | R | input: constraint matrix element |
| 008d1b10 | dbl_8D1B10 | RW | workspace: D factor update |
| 008d1b18 | dbl_8D1B18 | RW | workspace: intermediate D update |
| 008d1b38 | dbl_8D1B38 | RW | workspace: D factor update, block row |
| 008d1b40 | dbl_8D1B40 | RW | workspace: D factor diagonal (accumulated) |
| 008d1b58 | dbl_8D1B58 | R | input: constraint matrix element (sub-block) |
| 008d1b60 | dbl_8D1B60 | RW | workspace: intermediate term |
| 008d1b68 | dbl_8D1B68 | RW | workspace: intermediate term |
| 008d1b70 | dbl_8D1B70 | RW | workspace: intermediate term |
| 008d1b78 | dbl_8D1B78 | RW | workspace: intermediate term |
| 008d1b80 | dbl_8D1B80 | RW | workspace: intermediate term |
| 008d1b88 | dbl_8D1B88 | RW | workspace: intermediate term |
| 008d1b90 | dbl_8D1B90 | RW | workspace: intermediate term |
| 008d1b98 | dbl_8D1B98 | RW | workspace: intermediate term |
| 008d1ba0 | dbl_8D1BA0 | RW | workspace: intermediate term |
| 008d1ba8 | dbl_8D1BA8 | RW | workspace: intermediate term |
| 008d1bb0 | dbl_8D1BB0 | RW | workspace: intermediate term |
| 008d1bb8 | dbl_8D1BB8 | RW | workspace: D factor diagonal (intermediate) |
| 008d1bc0 | dbl_8D1BC0 | RW | workspace: D factor diagonal, block 29 (after multi-rank updates) |
| 008d1bc8 | unk_8D1BC8 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1bf8 | dbl_8D1BF8 | R | input: constraint matrix element |
| 008d1c00 | dbl_8D1C00 | RW | workspace: D factor update |
| 008d1c08 | dbl_8D1C08 | RW | workspace: intermediate D update |
| 008d1c28 | dbl_8D1C28 | RW | workspace: D factor update, block row |
| 008d1c30 | dbl_8D1C30 | RW | workspace: D factor diagonal (accumulated) |
| 008d1c48 | dbl_8D1C48 | R | input: constraint matrix element (sub-block) |
| 008d1c50 | dbl_8D1C50 | RW | workspace: intermediate term |
| 008d1c58 | dbl_8D1C58 | RW | workspace: intermediate term |
| 008d1c60 | dbl_8D1C60 | RW | workspace: intermediate term |
| 008d1c68 | dbl_8D1C68 | RW | workspace: intermediate term |
| 008d1c70 | dbl_8D1C70 | RW | workspace: intermediate term |
| 008d1c78 | dbl_8D1C78 | RW | workspace: intermediate term |
| 008d1c80 | dbl_8D1C80 | RW | workspace: intermediate term |
| 008d1c88 | dbl_8D1C88 | RW | workspace: intermediate term |
| 008d1c90 | dbl_8D1C90 | RW | workspace: intermediate term |
| 008d1c98 | dbl_8D1C98 | RW | workspace: intermediate term |
| 008d1ca0 | dbl_8D1CA0 | RW | workspace: D factor diagonal (intermediate) |
| 008d1ca8 | dbl_8D1CA8 | RW | workspace: D factor diagonal (intermediate) |
| 008d1cb0 | dbl_8D1CB0 | RW | workspace: D factor diagonal (intermediate) |
| 008d1cb8 | dbl_8D1CB8 | RW | workspace: D factor diagonal, block 30 (after multi-rank updates) |
| 008d1cc0 | unk_8D1CC0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1ce8 | dbl_8D1CE8 | R | input: constraint matrix element |
| 008d1cf0 | dbl_8D1CF0 | RW | workspace: D factor update |
| 008d1cf8 | dbl_8D1CF8 | RW | workspace: intermediate D update |
| 008d1d10 | dbl_8D1D10 | RW | workspace: D factor update, block row |
| 008d1d18 | dbl_8D1D18 | RW | workspace: D factor diagonal (accumulated) |
| 008d1d20 | dbl_8D1D20 | R | input: constraint matrix element (sub-block) |
| 008d1d28 | dbl_8D1D28 | RW | workspace: intermediate term |
| 008d1d30 | dbl_8D1D30 | RW | workspace: intermediate term |
| 008d1d38 | dbl_8D1D38 | RW | workspace: intermediate term |
| 008d1d40 | dbl_8D1D40 | RW | workspace: intermediate term |
| 008d1d48 | dbl_8D1D48 | RW | workspace: intermediate term |
| 008d1d50 | dbl_8D1D50 | RW | workspace: intermediate term |
| 008d1d58 | dbl_8D1D58 | RW | workspace: intermediate term |
| 008d1d60 | dbl_8D1D60 | RW | workspace: intermediate term |
| 008d1d68 | dbl_8D1D68 | RW | workspace: intermediate term |
| 008d1d70 | dbl_8D1D70 | RW | workspace: intermediate term |
| 008d1d78 | dbl_8D1D78 | RW | workspace: intermediate term |
| 008d1d80 | dbl_8D1D80 | RW | workspace: intermediate term |
| 008d1d88 | dbl_8D1D88 | RW | workspace: D factor diagonal (intermediate) |
| 008d1d90 | dbl_8D1D90 | RW | workspace: D factor diagonal (intermediate) |
| 008d1d98 | dbl_8D1D98 | RW | workspace: D factor diagonal, block 31 (after multi-rank updates) |
| 008d1da0 | unk_8D1DA0 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1dc0 | dbl_8D1DC0 | R | input: constraint matrix element |
| 008d1dc8 | dbl_8D1DC8 | RW | workspace: D factor update |
| 008d1dd0 | dbl_8D1DD0 | RW | workspace: intermediate D update |
| 008d1de8 | dbl_8D1DE8 | RW | workspace: D factor update, block row |
| 008d1df0 | dbl_8D1DF0 | RW | workspace: D factor diagonal (accumulated) |
| 008d1df8 | dbl_8D1DF8 | R | input: constraint matrix sub-block base pointer |
| 008d1e00 | dbl_8D1E00 | RW | workspace: intermediate term |
| 008d1e08 | dbl_8D1E08 | RW | workspace: intermediate term |
| 008d1e10 | dbl_8D1E10 | RW | workspace: intermediate term |
| 008d1e18 | dbl_8D1E18 | RW | workspace: intermediate term |
| 008d1e20 | dbl_8D1E20 | RW | workspace: intermediate term |
| 008d1e28 | dbl_8D1E28 | RW | workspace: intermediate term |
| 008d1e30 | dbl_8D1E30 | RW | workspace: intermediate term |
| 008d1e38 | dbl_8D1E38 | RW | workspace: intermediate term |
| 008d1e40 | dbl_8D1E40 | RW | workspace: intermediate term |
| 008d1e48 | dbl_8D1E48 | RW | workspace: intermediate term |
| 008d1e50 | dbl_8D1E50 | RW | workspace: intermediate term |
| 008d1e58 | dbl_8D1E58 | RW | workspace: intermediate term |
| 008d1e60 | dbl_8D1E60 | RW | workspace: D factor diagonal (intermediate) |
| 008d1e68 | dbl_8D1E68 | RW | workspace: D factor diagonal (intermediate) |
| 008d1e70 | dbl_8D1E70 | RW | workspace: D factor diagonal (intermediate) |
| 008d1e78 | dbl_8D1E78 | RW | workspace: D factor diagonal, block 32 (after multi-rank updates) |
| 008d1e80 | unk_8D1E80 | R | input: constraint matrix off-diagonal block pointer array |
| 008d1e98 | dbl_8D1E98 | R | input: constraint matrix element |
| 008d1ea0 | dbl_8D1EA0 | RW | workspace: D factor update |
| 008d1ea8 | dbl_8D1EA8 | RW | workspace: intermediate D update |
| 008d1ec0 | dbl_8D1EC0 | RW | workspace: D factor update, block row |
| 008d1ec8 | dbl_8D1EC8 | RW | workspace: D factor diagonal (accumulated) |
| 008d1ed0 | dbl_8D1ED0 | R | input: constraint matrix element (sub-block) |
| 008d1ed8 | dbl_8D1ED8 | RW | workspace: intermediate term |
| 008d1ee0 | dbl_8D1EE0 | RW | workspace: intermediate term |
| 008d1ee8 | dbl_8D1EE8 | RW | workspace: intermediate term |
| 008d1ef0 | dbl_8D1EF0 | RW | workspace: intermediate term |
| 008d1ef8 | dbl_8D1EF8 | RW | workspace: intermediate term |
| 008d1f00 | dbl_8D1F00 | RW | workspace: intermediate term |
| 008d1f08 | dbl_8D1F08 | RW | workspace: intermediate term |
| 008d1f10 | dbl_8D1F10 | RW | workspace: intermediate term |
| 008d1f18 | dbl_8D1F18 | RW | workspace: intermediate term |
| 008d1f20 | dbl_8D1F20 | RW | workspace: intermediate term |
| 008d1f28 | dbl_8D1F28 | RW | workspace: intermediate term |
| 008d1f30 | dbl_8D1F30 | RW | workspace: intermediate term |
| 008d1f38 | dbl_8D1F38 | RW | workspace: intermediate term |
| 008d1f40 | dbl_8D1F40 | RW | workspace: intermediate term |
| 008d1f48 | dbl_8D1F48 | RW | workspace: D factor diagonal (intermediate) |
| 008d1f50 | dbl_8D1F50 | RW | workspace: D factor diagonal (intermediate) |
| 008d1f58 | dbl_8D1F58 | RW | workspace: D factor diagonal, block 33 (after multi-rank updates) |
| 008d1f60 | dbl_8D1F60 | RW | workspace: L factor block (forward substitution coefficient) |
| 008d1f68 | dbl_8D1F68 | RW | workspace: L factor block (forward substitution coefficient) |
| 008d1f70 | dbl_8D1F70 | R | input: constraint matrix element |
| 008d1f78 | dbl_8D1F78 | RW | workspace: D factor update |
| 008d1f80 | dbl_8D1F80 | RW | workspace: intermediate D update |
| 008d1f98 | dbl_8D1F98 | RW | workspace: D factor update, block row |
| 008d1fa0 | dbl_8D1FA0 | RW | workspace: D factor diagonal (accumulated) |
| 008d1fa8 | dbl_8D1FA8 | R | input: constraint matrix element (sub-block) |
| 008d1fb0 | dbl_8D1FB0 | RW | workspace: intermediate term |
| 008d1fb8 | dbl_8D1FB8 | RW | workspace: intermediate term |
| 008d1fc0 | dbl_8D1FC0 | RW | workspace: intermediate term |
| 008d1fc8 | dbl_8D1FC8 | RW | workspace: intermediate term |
| 008d1fd0 | dbl_8D1FD0 | RW | workspace: intermediate term |
| 008d1fd8 | dbl_8D1FD8 | RW | workspace: intermediate term |
| 008d1fe0 | dbl_8D1FE0 | RW | workspace: intermediate term |
| 008d1fe8 | dbl_8D1FE8 | RW | workspace: intermediate term |
| 008d1ff0 | dbl_8D1FF0 | RW | workspace: intermediate term |
| 008d1ff8 | dbl_8D1FF8 | RW | workspace: intermediate term |
| 008d2000 | dbl_8D2000 | RW | workspace: intermediate term |
| 008d2008 | dbl_8D2008 | RW | workspace: intermediate term |
| 008d2010 | dbl_8D2010 | RW | workspace: intermediate term |
| 008d2018 | dbl_8D2018 | RW | workspace: intermediate term |
| 008d2020 | dbl_8D2020 | RW | workspace: intermediate term |
| 008d2028 | dbl_8D2028 | RW | workspace: intermediate term |
| 008d2030 | dbl_8D2030 | RW | workspace: L factor block, final column row 0 |
| 008d2038 | dbl_8D2038 | RW | workspace: D factor diagonal, final block 34 (before back-substitution) |
| 008d2040 | dbl_8D2040 | RW | workspace: L factor block (forward substitution coefficient, final) |
| 008d2048 | dbl_8D2048 | R | input: constraint matrix sub-block pointer |
| 008d2050 | dbl_8D2050 | RW | workspace: D factor update |
| 008d2058 | dbl_8D2058 | RW | workspace: intermediate D update |
| 008d2070 | dbl_8D2070 | RW | workspace: D factor update, block row |
| 008d2078 | dbl_8D2078 | RW | workspace: D factor diagonal (accumulated) |
| 008d2080 | dbl_8D2080 | R | input: constraint matrix element (sub-block) |
| 008d2088 | dbl_8D2088 | RW | workspace: intermediate term |
| 008d2090 | dbl_8D2090 | RW | workspace: intermediate term |
| 008d2098 | dbl_8D2098 | RW | workspace: intermediate term |
| 008d20a0 | dbl_8D20A0 | RW | workspace: intermediate term |
| 008d20a8 | dbl_8D20A8 | RW | workspace: intermediate term |
| 008d20b0 | dbl_8D20B0 | RW | workspace: intermediate term |
| 008d20b8 | dbl_8D20B8 | RW | workspace: intermediate term |
| 008d20c0 | dbl_8D20C0 | RW | workspace: intermediate term |
| 008d20c8 | dbl_8D20C8 | RW | workspace: intermediate term |
| 008d20d0 | dbl_8D20D0 | RW | workspace: intermediate term |
| 008d20d8 | dbl_8D20D8 | RW | workspace: intermediate term |
| 008d20e0 | dbl_8D20E0 | RW | workspace: intermediate term |
| 008d20e8 | dbl_8D20E8 | RW | workspace: intermediate term |
| 008d20f0 | dbl_8D20F0 | RW | workspace: intermediate term |
| 008d20f8 | dbl_8D20F8 | RW | workspace: intermediate term |
| 008d2100 | dbl_8D2100 | RW | workspace: intermediate term |
| 008d2108 | dbl_8D2108 | RW | workspace: intermediate L factor term |
| 008d2110 | dbl_8D2110 | RW | workspace: intermediate L factor term |
| 008d2118 | dbl_8D2118 | RW | workspace: D factor diagonal after final column, block 35 |
| 008d3988 | dword_8D3988 | R | constraint matrix index array: column pointer table (base) |
| 008d3990 | dword_8D3990 | R | constraint matrix index array: column pointer table (end sentinel) |
| 008d3994 | dword_8D3994 | R | constraint matrix index array: sub-block offset index for column operations |
| 008d399c | dword_8D399C | R | constraint matrix index array: end sentinel for sub-block index |
| 008d39a0 | dword_8D39A0 | R | constraint matrix index array: sub-block offset index (next tier) |
| 008d39a8 | dword_8D39A8 | R | constraint matrix index array: end sentinel |
| 008d39b0 | dword_8D39B0 | R | constraint matrix index array: offset index for block 8-13 factorization |
| 008d39b8 | dword_8D39B8 | R | constraint matrix index array: end sentinel |
| 008d39bc | dword_8D39BC | R | constraint matrix index array: offset index (next tier) |
| 008d39c4 | dword_8D39C4 | R | constraint matrix index array: end sentinel |
| 008d39c8 | dword_8D39C8 | R | constraint matrix index array: offset index (further tier) |
| 008d39d0 | dword_8D39D0 | R | constraint matrix index array: end sentinel |
| 008d39d8 | dword_8D39D8 | R | solver workspace index: pointer to constraint column entry table |
| 008d39dc | dword_8D39DC | R | solver workspace index: end sentinel for column entries |
| 008d39e0 | dword_8D39E0 | R | solver workspace index: start pointer for next column span |
| 008d39e4 | dword_8D39E4 | R | solver workspace index: end sentinel |
| 008d39e8 | dword_8D39E8 | R | solver workspace index: start pointer |
| 008d39ec | dword_8D39EC | R | solver workspace index: end sentinel |
| 008d39f0 | dword_8D39F0 | R | solver workspace index: start pointer |
| 008d39f4 | dword_8D39F4 | R | solver workspace index: end sentinel |
| 008d39f8 | dword_8D39F8 | R | solver workspace index: start pointer |
| 008d39fc | dword_8D39FC | R | solver workspace index: end sentinel |
| 008d3a00 | dword_8D3A00 | R | solver workspace index: start pointer |
| 008d3a04 | dword_8D3A04 | R | solver workspace index: end sentinel |
| 008d3a08 | dword_8D3A08 | R | solver workspace index: start pointer |
| 008d3a0c | dword_8D3A0C | R | solver workspace index: end sentinel |
| 008d3a10 | dword_8D3A10 | R | solver workspace index: start pointer |
| 008d3a14 | dword_8D3A14 | R | solver workspace index: end sentinel |
| 008d3a18 | dword_8D3A18 | R | solver workspace index: start pointer |
| 008d3a1c | dword_8D3A1C | R | solver workspace index: end sentinel |
| 008d3a20 | dword_8D3A20 | R | solver workspace index: start pointer for final columns |
| 008d3a24 | dword_8D3A24 | R | solver workspace index: end sentinel |
| 008d3a28 | dbl_8D3A28 | RW | RHS vector element: right-hand side of constraint system (accumulated) |
| 008d3a30 | dbl_8D3A30 | RW | RHS vector element (back-substitution intermediate) |
| 008d3a38 | dbl_8D3A38 | RW | RHS vector element |
| 008d3a40 | dbl_8D3A40 | RW | RHS vector element |
| 008d3a48 | dbl_8D3A48 | RW | RHS vector element |
| 008d3a50 | dbl_8D3A50 | RW | RHS vector element |
| 008d3a58 | dbl_8D3A58 | RW | RHS vector element (accumulated dot product result) |
| 008d3a60 | dbl_8D3A60 | RW | RHS vector element |
| 008d3a68 | dbl_8D3A68 | RW | RHS vector element |
| 008d3a70 | dbl_8D3A70 | RW | RHS vector element |
| 008d3a78 | dbl_8D3A78 | RW | RHS vector element |
| 008d3a80 | dbl_8D3A80 | RW | RHS vector element |
| 008d3a88 | dbl_8D3A88 | RW | RHS vector element |
| 008d3a90 | dbl_8D3A90 | RW | RHS vector element |
| 008d3a98 | dbl_8D3A98 | RW | RHS vector element |
| 008d3aa0 | dbl_8D3AA0 | RW | RHS vector element |
| 008d3aa8 | dbl_8D3AA8 | RW | RHS vector element |
| 008d3ab0 | dbl_8D3AB0 | RW | RHS vector element |
| 008d3ab8 | dbl_8D3AB8 | RW | RHS vector element |
| 008d3ac0 | dbl_8D3AC0 | RW | RHS vector element |
| 008d3ac8 | dbl_8D3AC8 | RW | RHS vector element |
| 008d3ad0 | dbl_8D3AD0 | RW | RHS vector element |
| 008d3ad8 | dbl_8D3AD8 | RW | RHS vector element |
| 008d3ae0 | dbl_8D3AE0 | RW | RHS vector element |
| 008d3ae8 | dbl_8D3AE8 | RW | RHS vector element |
| 008d3af0 | dbl_8D3AF0 | RW | RHS vector element |
| 008d3af8 | dbl_8D3AF8 | RW | RHS vector element |
| 008d3b00 | dbl_8D3B00 | RW | RHS vector element |
| 008d3b08 | dbl_8D3B08 | RW | RHS vector element |
| 008d3b10 | dbl_8D3B10 | RW | RHS vector element |
| 008d3b18 | dbl_8D3B18 | RW | RHS vector element |
| 008d3b20 | dbl_8D3B20 | RW | RHS vector element |
| 008d3b28 | dbl_8D3B28 | RW | RHS vector element |
| 008d3b30 | dbl_8D3B30 | RW | RHS vector element |
| 008d3b38 | dbl_8D3B38 | RW | RHS vector element |
| 008d3b40 | dbl_8D3B40 | RW | RHS vector element |
| 008d3b48 | dbl_8D3B48 | RW | RHS vector element |
| 008d3b50 | dbl_8D3B50 | RW | RHS vector element |
| 008d3b58 | dbl_8D3B58 | RW | RHS vector element |
| 008d3b60 | dbl_8D3B60 | RW | RHS vector element (final) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branching guards — all computation is straight-line block LDL^T factorization with fixed-size dot-product loops (24, 32, 40, ..., 168 iterations). The function always executes all factorization stages and returns 0. No early exits or conditional paths.
