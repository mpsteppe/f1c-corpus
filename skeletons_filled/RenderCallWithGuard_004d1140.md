## RenderCallWithGuard_004d1140 — RenderIndexedStructDataWithGuard

**Summary:** If grid position index (this[0x48A4]) is unset (< 0), recalculate via sub_4C6F10. Then read indexed struct data from setup scene using grid position index and column index via IndexedStructDataRead.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), Camera (004a3b50), SceneRenderUpdate (004c6d90), RenderTickUpdate (004c8b70), LoopOverTwoParallelArrays (004d1030), sub_4D1180 (004d1180), AIRacingLinePathFollowing (004e9ca0), DistanceComparison (004effd0), sub_4F0D20 (004f0d20), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48A4 | R | — | allocated grid position index (-1 = unset) |
| this | 0x48A8 | R | — | allocated team column index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403fc0 | IndexedStructDataRead | read indexed struct data from setup scene |
| 004c6f10 | sub_4C6F10 | allocate/find a free grid position for this vehicle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x48A4 | < | 0 | grid position index < 0 means unallocated |

**Guard interpretation:** Passes (recalculates) when this[0x48A4] < 0 (no grid slot allocated yet). After recalculation, always reads struct data by position+column index. If index >= 0, skips sub_4C6F10 and reads directly.
