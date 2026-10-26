# Cross-Validation Results: worker_F_D

## 1894. FUN_0044E210 — CollisionGridFreeD — PASS
- Verified: Calls FUN_00587b3e(&PTR_LAB_0044e220). Source matches exactly.

## 1895. FUN_0044D580 — Collision Region Init 1 (Type 18) — FAIL
- Globals correct: DAT_007ccd08=0x12, DAT_007ccd0c..DAT_007ccd1c=0. ✓
- **ERROR [moddability]**: Doc claims "configurable — region data from .gdb/.rcd files." Source is pure hardcoded constant assignment. No string literals, no file reads. Should be `hardcoded`.

## 1896. FUN_0044CFE0 — Collision Material Coefficients Set 6 (ID 40, 1.0f) — PASS
- Verified: DAT_007cc9ec=0x28, zeros 2 fields, DAT_007cc9f8=0x3f800000. Moddability: hardcoded. ✓

## 1897. FUN_0044E390 — CollisionCallbackRegister_e3a0 — PASS
- Verified: Calls FUN_00587b3e(&DAT_0044e3a0). Moddability: hardcoded. ✓

## 1898. FUN_0044D700 — Collision Global Init (Set 0x16) — PASS
- Verified: DAT_007ccc98=0x16, zeros 5 fields. Moddability: hardcoded. ✓

## 1899. FUN_0044CDD0 — Collision Init Registration (DAT_0044cde0) — PASS
- Verified: Calls FUN_00587b3e(&DAT_0044cde0). Moddability: hardcoded. ✓

## 1900. FUN_00412C30 — MapCollisionShapeToBoneIndex — PASS
- Verified: switch on param_3 (1-0x32), maps to indices 0xbd-0x99, param_4 subtracts 1, stores at param_1+8, calls FUN_00414180(0), returns 1/-1. ✓

## 1901. FUN_0044E780 — Collision Subsystem Init (DAT_007ccfec) — PASS
- Verified: DAT_007ccfec=0x57, zeroes 4 fields, DAT_007cd000=9000. Moddability: hardcoded. ✓

## 1902. FUN_0044E840 — CollisionGlobalInitE — PASS
- Verified: DAT_007cd01c=0x59, zeroes 4 dwords at +0x20/+0x24/+0x28/+0x2c, DAT_007cd030=27000. Moddability: hardcoded. ✓

## 1903. FUN_0044C890 — Collision Init Wrapper (DAT_0044c8a0) — PASS
- Verified: Calls FUN_00587b3e(&DAT_0044c8a0). Moddability: hardcoded. ✓

## 1904. FUN_0049B630 — SpatialGridCell — PASS
- Verified: Computes cell index via __ftol, stores at *param_3, computes remainder param_2 - cellIndex * _DAT_0059f118 at *param_4. Moddability note: cell size is a global constant. ✓

## 1905. FUN_004B5630 — Collision Filter/AABB Cull — PASS
- Verified: Walks list at +0x20, cursor at +0x28. Proximity checks via FUN_005001d0/f0 and ABS diff against _DAT_005acd30. In-range nodes re-inserted at +0x10 list. Out-of-range unlinked, freed if flag set. Calls FUN_004b0170, FUN_00587bcf, operator_new, FUN_004bac20. ✓

## 1906. FUN_0044DBE0 — Collision Parameter Block Init — PASS
- Verified: DAT_007cce70=0x30, zeros 5 ints at +0x74..+0x84. Moddability: hardcoded. ✓

## 1907. FUN_0056D2D0 — FAIL
- **ERROR [description]**: Doc comment says "Physics island grouping — builds contact constraint graph." Source code computes constraint velocities: sums body vectors, cross-product differences, normalizes via 1.0/SQRT(length^2), stores constraint normal to both bodies at +0x40. Actual function is "Constraint Velocity Correction / Bilateral Constraint Normal Assembly", not island grouping.
- **ERROR [no structured entry]**: Bare-minimum code-fenced comment only. No Key logic/Globals/Calls sections.

## 1908. FUN_0056BAF0 — Constraint Stiffness Matrix Assembly — PASS
- Verified: Iterates param_1+0x23c elements stride 0x58. Computes cross products from +0x18/+0x20/+0x28 and +0x48/+0x50. Multiplies by param_1+0xb4. Differentiates constraint type by char at +0x34. Stores to matrix at *(param_1+0x228)[i*4]+j*8. Calls FUN_00435e00. ✓

## 1909. FUN_004359A0 — Rigid Body Constraint/Joint Solver — PASS
- Verified: Iterates param_1[0x26] constraints stride 100. Type 0 pass-through, type 2 hard constraint. Body rotation matrix at +0x7c/0x84/0x8c. Calls FUN_00435e00, FUN_00569ad0. ✓

## 1910. FUN_004AF3A0 — Physics Parameter Initialization — PASS
- Verified: Switch on setup index at +0x3b40 (cases 0-3). Case 0: default setup with 0x3df5c28f (friction), 0x4633b000 (brake), etc. Case 1: wet setup. Case 2: qualifying with FUN_004b20d0/FUN_004b1de0 pushes. Case 3: reset. Inner loop 2×8 wheel params. Calls FUN_004646c0, FUN_0047f1f0. ✓

## 1911. FUN_00431BC0 — Thunk — PASS
- Verified: Delegates to FUN_004320a0. ✓

## 1912. FUN_0043E980 — ClampedSpringIntegrator — PASS
- Verified: +0x1808 += param_2 * _DAT_0059ec78, +0x1818 += param_2 * _DAT_0059eb58. Clamps to [+0x1c20, +0x1c20+_DAT_0059eb50] and [+0x1c28, +0x1c28+_DAT_0059eb28]. Calls FUN_0043bbd0. ✓

## 1913. FUN_00448DA0 — CollisionTreeTraversal — PASS
- Verified: Calls FUN_00448730(), iterates 4 children at +0x4c..+0x58 recursively, follows sibling chain at +0x5c. ✓

## 1914. FUN_00447100 — GetBodyMotionState — PASS
- Verified: Calls FUN_00435e60 with body ptr at +0x15f0, returns position (double→float) in param_2[0..2], velocity in param_3[0..2]. ✓

## 1915. FUN_00566E40 — EulerToRotationMatrix — PASS
- Verified: Reads 3 Euler angles from param_1[0..2], uses fsin/fcos, produces 3x3 row-major rotation matrix in param_2[0..8]. Formula matches standard convention. ✓

## 1916. FUN_004361D0 — 3D Vector Transform by 3×3 Matrix (Double) — PASS
- Verified: Computes delta = param_3 - param_2, multiplies by row-major matrix param_1, stores at param_4. ✓

## 1917. FUN_004B46B0 — Struct Zero-Init (Three Regions) — PASS
- Verified: Region 1: param_1+1, 13 dwords. Region 2: param_1+0x35, 13 dwords. Region 3: param_1+0x70, 4×4 dwords = 64 bytes. Sets +0x6c=0. Returns param_1. ✓

## 1918. FUN_0045B580 — Find Active Physics Channel by Index — PASS
- Verified: Iterates 8 channels at param_1+0x90 stride 0x17 ints (0x5c bytes). Checks > DAT_0059e440. Returns index of param_2-th active. Returns 0 if fewer. ✓

## 1919. FUN_0050E2AB — Quadratic Bezier (3D) — PASS
- Verified: First pair interpolated via thunk_FUN_0050e174(local_24, param_2, param_5, param_6). Second pair via thunk_FUN_0050e174(local_14, param_3, param_4, param_6). Blend factor = 2*t*(1-t). ✓

## 1920. FUN_0059980E — Physics Block Wrapper — PASS
- Verified: Calls sub_599E71(&unk_8D4510). ✓

## 1921. FUN_005986F8 — Physics State Wrapper — PASS
- Verified: Calls FUN_00598E39(&DAT_008D4248). ✓

## 1922. FUN_0052035E — FAIL
- **ERROR [missing entry]**: No `## FUN_` entry exists in any docs/ file. Only referenced in docs/12-globals-reference.md and docs/23-gap-analysis.md. Source is SSE vector normalize with NR approximation (184 bytes, threshold at dword_8D6180, NR constant at dword_8D6188). Task claims docs/18-physics-dynamics.md but not found.

## 1923. FUN_004CE930 — ParticleCollisionEffect (DualType) — PASS
- Verified: Three collision type blocks (param_2[0], param_2[5], param_2[10]). Detail level check via DAT_007cf8a8. Visibility flags via DAT_007cf9bc/DAT_007cf9ec. Frame counter DAT_007c5698. Calls FUN_004cbc50. ✓

## 1924. FUN_00486240 — UI String Accessor (+0x18) — PASS
- Verified: Returns string at ptr->+200→+0x18 if ptr->+200 non-null, else null. ✓

## 1925. FUN_00489A10 — UI List Item by Index — PASS
- Verified: Walks linked list at +0x90 via +0x8c next pointer. Returns +0xb0 text of entry at index param_2. ✓

## 1926. FUN_004901A0 — UI Window Type Detection — PASS
- Verified: Copies text from +0xb8. Compares against DAT_005cc21c, DAT_005cc210, DAT_005c36f0 via FUN_00588410. Sets +0xe4 to type ID 0/1/2. ✓

## 1927. FUN_00499A70 — Data Entry Copy — FAIL
- **ERROR [description]**: Doc says "Copies string pointer from param_2 to param_1." Source does NOT copy *param_2 into *param_1. Source only calls FUN_00566650 on *param_2 (retain) and copies param_1[2] = param_2[2]. No string pointer copy to *param_1 occurs.

## 1928. FUN_005824F0 — FAIL
- **ERROR [no structured entry]**: Doc is triage-only metadata (size/category/algorithm). No Key logic/Globals/Calls sections. Source shows SEH constructor with allocations, linked-list, vtable init — proper entry needed.

## 1929. FUN_004E2D00 — Vertex Clustering/LOD Grouping — PASS
- Verified: Calls FUN_0054c210/FUN_0054c230 for D3D device setup. Iterates via FUN_0054e100/FUN_0054e120. Euclidean distance comparison for spatial proximity clustering. ✓

## 1930. FUN_0054C6C0 — Vertex Buffer Transform — PASS
- Verified: Guard at +0x14 bit 26. Calls FUN_0053b130/0x200/0x240. Two paths based on bit 23: non-skinned (stride 0xc, DAT_008b8f24 vtable) vs skinned (stride 0x10). Iterates batches at +0x11c. Copies prev frame positions to +0x8/+0x9. ✓

## 1931. FUN_00457000 — Camera/Viewport Parameters Copy — PASS
- Verified: Acquires context via FUN_00415c30+00566650. Copies viewport rect from +0x0c, projection from +0x18. Sub-rectangle copies via FUN_00456040/60/80/a0. ✓

## 1932. FUN_0044F8F0 — D3D Texture Stage / Render Target Setup — PASS
- Verified: COM vtable calls at +100, +0x24, +0xc. Reads +0x2dc for feature level. Sets +0x3f8 bitmask. ✓

## 1933. FUN_00495DC0 — 2D Screen-Space Tile Renderer — PASS
- Verified: Branches on +0x1578. Mode 0: full blit, clamps to 800x600. Mode 1: 80-step tiled with _DAT_0059e448+_DAT_0059e43c stepping. Calls FUN_004962c0, FUN_00495150, FUN_00494a30. ✓

## 1934. FUN_0051D6D2 — 2D Image Weighted Average — PASS
- Verified: Double-indirection pixel access, accumulation, shift-based weighted average computation. ✓

## 1935. FUN_0059B250 — Direct3DCreate8 (import thunk) — PASS
- Verified: 6-byte import thunk, no game logic. ✓

## 1936. FUN_0051D80A — Render Buffer Setup — PASS
- Verified: Gets buffer pointer via vtable, sets defaults (0x1f/0x3f), calls FUN_0051d247+0051d57f, loops FUN_0051d6d2 per iteration. ✓

## 1937. FUN_004900A0 — Unidentified / UI State Machine Update — PASS
- Verified: Viewport boundaries via FUN_00487060/004870e0. Mouse via FUN_00498880. State machine on param_1[0x38] (0→1→0 toggle, 2 stays 2). Vtable calls at +0x40 and +0x98. ✓

## 1938. FUN_00519375 — Vertex Buffer Offset Setup — PASS
- Verified: Reads +0x180, +0x114, vtable call for buffer setup. Register-allocated variables limit full verification but doc description is consistent with D3D vertex buffer setup pattern. ✓

## 1939. FUN_00519EB7 — Render State Copy with Validation — PASS
- Verified: Checks validation flags, copies data with iteration. Register-based decompilation limits detail verification but doc matches observed patterns. ✓

## 1940. FUN_00486540 — Linked-List Append (UI/Display List) — PASS
- Verified: Head at +0xd8, next pointer at +0x18. If head null: set head. Else: walk to tail, append. ✓

---

## Summary
**Total: 47 functions**
- **PASS: 42**
- **FAIL: 5** (1895, 1907, 1922, 1927, 1928)

**FAIL details:**
- 1895: moddability claim wrong (configurable→hardcoded)
- 1907: description mismatch (island grouping→constraint correction) + no structured entry
- 1922: missing entry entirely (no `## FUN_` header in any docs/ file)
- 1927: doc claims string copy that source doesn't perform
- 1928: triage-only metadata only, no structured entry with Key logic/Globals/Calls
