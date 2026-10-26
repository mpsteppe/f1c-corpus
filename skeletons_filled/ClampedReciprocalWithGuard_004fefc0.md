## ClampedReciprocalWithGuard_004fefc0 — CrossfadeCoefficientCompute

**Summary:** Clamps an input blend factor to [0.01, 1.0], then computes reciprocal (1.0/factor) and reciprocal of complement (1.0/(1.0-factor)) for audio crossfade or parameter interpolation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690), sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | 1008981770 → 0.01f | Clamped interpolation/blend factor (input) |
| this | 0xAC | RW | — | Reciprocal of blend factor (1.0 / factor) |
| this | 0xB0 | RW | — | Reciprocal of complement (1.0 / (1.0 - factor)) |

**Written-by note (persistence):**
- this 0xA8: Written once per call to clamped blend factor
- this 0xAC: Written once per call to reciprocal of factor
- this 0xB0: Written once per call to reciprocal of complement

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 005ad2c0 | flt_5AD2C0 | R | InterpCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Input `a2` stored as float at this+0xA8. If value < 0.01f → clamped up to 0.01f (literal 1008981770). If value > 0.99f → clamped down to 1.0f (literal 1065185444 = 0x3F800000). Values in [0.01, 0.99] pass through unchanged.
