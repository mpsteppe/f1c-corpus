## TerrainSurfaceRoughnessHeightSampling_0045ca20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** NetCommSessionMessageDispatcher (0045d890), PhysicsIntegrationStep_e620 (0045e620), SessionSynchronizer (0045f950), TerrainHeightComparison (004624e0), ShortComputation_2530 (00462530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045c760 | sub_45C760 | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059f0c0 | flt_59F0C0 | R | HUDLayoutOffsetX [DERIVED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c780 | BoundedByteArrayAccessor | [LLM] |
| 0045c7a0 | FloatToShortViaFtol | [LLM] |
| 0045c7c0 | ShortToFloatConversion | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 005890aa | sub_5890AA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
