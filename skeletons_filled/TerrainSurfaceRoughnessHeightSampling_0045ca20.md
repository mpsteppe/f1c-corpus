## TerrainSurfaceRoughnessHeightSampling_0045ca20 — TerrainSurfaceRoughnessHeightSampling

**Summary:** Samples terrain surface roughness/height at a given index: validates surface type, checks cached height, otherwise decodes packed height data, computes weighted average over sample window, caches result, and computes penetration compensation for surface type 16. Part of terrain/collision system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** NetCommSessionMessageDispatcher (0045d890), PhysicsIntegrationStep_e620 (0045e620), SessionSynchronizer (0045f950), TerrainHeightComparison (004624e0), ShortComputation_2530 (00462530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045c760 | sub_45C760 | R | Wavelet/height-field decoding function pointer passed to sub_5890AA |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059f0c0 | flt_59F0C0 | R | HUDLayoutOffsetX [DERIVED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 — surface type lookup array (indexed by a2 * 4656) |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c780 | BoundedByteArrayAccessor | Read bounded byte from surface roughness array by index |
| 0045c7a0 | FloatToShortViaFtol | Convert float to short via ftol for penetration storage |
| 0045c7c0 | ShortToFloatConversion | Convert short to float for weighted average accumulation |
| 00587bdc | CRTFtol | CRT ftol conversion (float-to-int) |
| 005890aa | sub_5890AA | Decode/process packed height-field data array using wavelet function |

**Guard conditions:** Surface type check at dword_5EF9A0[4656*a2]: if != 2, BLOCK (return 1, *a3=0.0). BoundedByteArrayAccessor: if returns 0, BLOCK (return 0, *a3=9.9989996). Cached height at this[4*v6+4388] > 0.0: PASS (return 1, use cached). Flag a4 LOBYTE set AND v7 != 16: BLOCK (return false, *a3=9.9989996). Main path continues with data processing otherwise.
