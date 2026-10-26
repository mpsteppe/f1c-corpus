## BrakeCoolingPostTreatment_004e5080 — brake cooling effectiveness factor computation

**Summary:** Computes brake cooling effectiveness factor from temperature delta and cooling mode selector, clamped to [0,1]. Part of brake thermal/suspension system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionSpringDampingRateReset (004e4f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34A8 | R | — | ambient or reference temperature for cooling delta |
| this | 0x3570 | RW | 0 | brake cooling effectiveness factor output, clamped [0,1] |
| this | 0x35B0 | R | — | front or rear axle cooling input for averaging |
| this | 0x36A8 | R | — | front or rear axle cooling input for averaging |
| this | 0x37A0 | R | — | left or right axle cooling input for averaging |
| this | 0x3898 | R | — | left or right axle cooling input for averaging |
| this | 0x3990 | R | — | fuelConsumptionFactor [CONFIRMED] |
| this | 0x3994 | R | — | brake bias offset constant (50.0 subtracted in formula) |
| this | 0x39B4 | R | — | cooling mode selector (0=2-wheel avg, 1=4-wheel avg, 2=1-wheel avg) |
| this | 0x39EC | R | — | anti-lock or cooling enhancement enable flag |
| this | 0x39F0 | RW | — | cooling override/fallback state copy from offset 0x3A08 |
| this | 0x3A04 | RW | — | temperature delta (self-difference, computed here) |
| this | 0x3A08 | R | — | cooling lookup index/state selector (0-7 low range, -1=index 0, 1=direct) |

**Written-by note (persistence):**
- this 0x3570: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist
- this 0x3A04: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3A08 | == | 18446744073709551615 | cooling lookup index -1 → maps to index 0 in lookup table |
| this | 0x3A08 | == | 1 | cooling state 1 with 0x39EC flag set → bypass averaging, use fuelConsumptionFactor directly |

**Guard interpretation:** 0x3A08 == -1 (u64 cast) forces index 0 in the brake cooling lookup table. 0x3A08 == 1 combined with byte flag at 0x39EC being non-zero selects direct fuel-consumption-factor path instead of per-axle averaging. BLOCKED: any other 0x3A08 value enters the normal averaging path; delta <= 0 copies state to 0x39F0 and skips all computation.
