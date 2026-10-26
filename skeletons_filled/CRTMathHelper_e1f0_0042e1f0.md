## CRTMathHelper_e1f0_0042e1f0 — ScaledValueAndIndexParser

**Summary:** Parses configuration tokens: scales two doubles by a5 factor, converts a token to int via CRTFtol, and parses/clamps a final index within [0, storedCount-1]. Used for vehicle setup file values.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PerWheelBrakeSuspensionDataLoader (004f2c60), FenderAeroSetupSectionReader (004f3090), EngineMapSetupFieldDefinitions (004f3c10), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | scaledDoubleValue1 |
| this | 0x8 | RW | — | scaledDoubleValue2 |
| this | 0x10 | RW | — | storedCountFromToken |
| this | 0x14 | RW | 0 | clampedIndexValue |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565760 | sub_565760 | Parses number from token string into integer at this+0x14 |
| 00565aa0 | sub_565AA0 | Parses tokens from input, extracts values into two doubles and an int |
| 00587bdc | CRTFtol | Converts double to int (float-to-int truncation) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | >= | 0 | clampedIndexValue |

**Guard interpretation:** If a3 is non-zero, parse+scale path executes (first token triplet). Then index at 0x14 is parsed. PASSES when value >= 0: clamps to [0, storedCount-1]. BLOCKED when value < 0: forces to 0.
