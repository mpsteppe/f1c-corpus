## FloatThresholdClassification_004b2b90 — FloatToTwoBitClassifier

**Summary:** Classifies a float value into one of four 2-bit categories stored in bits [1:0] of byte at offset 0xF. Thresholds: <= 0.75 = 0, 0.75-0.85 = 1, 0.85-0.95 = 2, >= 0.95 = 3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VectorToShort3Conversion (004b2c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF | RW | — | Two-bit classification field (bits [1:0]) |

**Written-by note (persistence):**
- this 0xF: overwritten each call; external poke survives until next classification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059ee8c | flt_59EE8C | R | QualityThresholdHigh [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 <= 0.75 → BLOCKED from higher classes: sets bits to 00. 0.75 < a2 < 0.85 → PASSES to class 1 (01). 0.85 <= a2 < 0.95 → PASSES to class 2 (10). a2 >= 0.95 → PASSES to class 3 (11).
