## CollisionNoiseGenerator_004962c0 — LookupTableNoiseInterp

**Summary:** Generates a noise value from a 16-entry float lookup table (at float[1419] = offset 0x162C) using linear interpolation between adjacent entries. Applies an optional per-sample transform (sub_5881F0) when the blend parameter a3 >= 0. Used by the collision damage system for impact visual variation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495DC0 (00495dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | Float constant used in sub_5881F0 transform computation |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f) — compared against a3 to decide if transform is applied |
| 0059eed0 | flt_59EED0 | R | Brightness multiplier — used in sub_5881F0 color/visual transform |
| 005ac9d0 | dbl_5AC9D0 | R | Double constant (16.0 scaling factor for index calculation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Convert float to integer (floor) for lookup table index |
| 005881f0 | sub_5881F0 | Per-sample noise transform (applied conditionally when a3 >= 0) |
| 0058957a | InterruptDispatch | Runtime dispatch/interrupt check called each noise sample |

**Guard conditions:** Index v4 (= floor(a2 * 16.0)) >= 16 → return 1.0 (BLOCKED, out of lookup table range). When v4 == 15, next-sample value clamped to 1.0 (edge of table).
