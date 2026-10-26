## LoopOverTwoParallelArrays_004d1030 — Parallel vehicle arrays update loop

**Summary:** Iterates two per-vehicle data arrays in parallel: first computes DistanceComparison results and resets sentinels in AI/path data (stride 4656), then processes RenderCallWithGuard and AIVehiclePathPositionTracking on main vehicle array (stride 18624). Calls sub_4D1670 at end.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] — base of main vehicle array |
| 005f0f80 | unk_5F0F80 | R | VEH[0].0x48A8 — base of AI/path data array (parallel, stride 4656 DWORDS) |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd — sentinel boundary for main vehicle loop |
| 007c9d80 | dword_7C9D80 | R | SeasonEnd_Boundary — sentinel boundary for AI data loop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1140 | RenderCallWithGuard | Renders or gates render call for a vehicle, using distance results array |
| 004d1670 | sub_4D1670 | Post-loop processing called once after both iterations complete |
| 004ef7c0 | AIVehiclePathPositionTracking | Updates AI vehicle path position tracking data |
| 004effd0 | DistanceComparison | Computes distance comparison for a vehicle, stored in results array |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| v3 (AI data) | -1400 DWORDS (-5600 bytes) | != | -1 | Slot active sentinel |
| v5 (vehicle) | +3250 DWORDS (+13000 bytes) | != | -1 | Slot active sentinel |

**Guard interpretation:** First loop skips AI data slot if `*(v3-1400) == -1` (inactive). Second loop skips vehicle slot if `*((int*)v5+3250) == -1` (inactive). PASSES when value != -1 (slot is active). BLOCKED (skip) when value == -1 (slot is inactive/free).
