## ClampedPhysicsScaleWithThreshold_00462ff0 — Physics Scale Clamp with Speed Threshold

**Summary:** Computes clamped physics scale factor for a vehicle: picks input or default base scale, adjusts by speed-based multiplier (if under 25mph), conditionally scales by 4x if flag bit 2 not set, clamps result to [0.0, 0.5]. Used in tire temperature simulation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TireTemperatureSimStep (004c77d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | default base scale value (used when a3 <= 0) |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e860 | flt_59E860 | R | AIDifficultyScaleFactor [DERIVED] |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059f124 | flt_59F124 | R | UILayoutOffset [DERIVED] (also: ` � layout constants) |
| 0059f128 | flt_59F128 | R | AeroDownforceCoeff [DERIVED] (also: ` — aero constant) |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Input a3 <= 0 uses default base from +0x4 instead. Speed < 25 mph applies linear multiplier. Flag bit 2 at v3[4655] clear (not set) causes 4x scale. Final result clamped to [0.0, 0.5].
