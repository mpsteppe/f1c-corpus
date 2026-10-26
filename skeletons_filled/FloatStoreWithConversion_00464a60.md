## FloatStoreWithConversion_00464a60 — Speed-to-byte ratio converter

**Summary:** Stores input value to offset +0x220, maps it through cascading speed tiers (2975/7200/28800/62500) to select a conversion divisor (6/10/16/20/32), computes 1.0/divisor/0.005, converts to byte via CRTFtol, and stores to offset +0x22A.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5430 (00465430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x220 | RW | — | Input value store (speed/RPM threshold input) |
| this | 0x22A | RW | — | Computed byte result (ratio/conversion output) |

**Written-by note (persistence):**
- this 0x220: unconditionally overwritten with new input each call
- this 0x22A: unconditionally overwritten with new computed byte each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 0059eed0 | flt_59EED0 | R | BrightnessMultiplierRB [DERIVED] (also: ` — brightness multiplier for R/B channels) |
| 0059f138 | flt_59F138 | R | RadToDegFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Converts float to int (truncation) |

**Guard conditions:** No guard — always stores input and computes/stores byte output.
