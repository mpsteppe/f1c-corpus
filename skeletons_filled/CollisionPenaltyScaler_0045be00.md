## CollisionPenaltyScaler_0045be00 — PenaltyScaler

**Summary:** Clamps collision penetration depth to a minimum threshold from float array, then scales by 0.035f. Part of collision response system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to float array of collision thresholds |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f078 | flt_59F078 | R | PenaltyScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bb00 | FloatArrayThresholdSearch | Returns threshold boundary/index for clamping |

**Guard conditions:** If a2 <= FloatArrayThresholdSearch result, clamp a2 to that threshold (prevents penalty from dropping below minimum).
