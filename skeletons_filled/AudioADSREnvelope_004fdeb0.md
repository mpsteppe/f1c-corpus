## AudioADSREnvelope_004fdeb0 — AudioADSREnvelope

**Summary:** Computes ADSR audio envelope: walks interpolated envelope table (linked list of keyframes from this+0x38), interpolates values based on phase a3, applies decay to two internal state variables (offsets 0x28, 0x2C), calls RangeInterpolationTable, computes final output at offset 0x34 with sample-rate-dependent smoothing. Core audio envelope DSP function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), WeatherConditionsFileWriter (004fe820), AudioEventRingBufferProcessing (004feaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | envelope table node threshold value |
| *(this+0x44) | 0x4 | R | — | first interpolation parameter from table node |
| *(this+0x44) | 0x8 | R | — | second interpolation parameter from table node |
| this | 0x38 | RW | — | pointer to current envelope segment table node (walked during interpolation) |
| this | 0x3C | R | — | table node's next pointer (offset 12 within node) |
| this | 0x40 | R | — | table node field (offset 8 within node) |
| this | 0x44 | R | — | pointer to envelope table base (segment/keyframe list) |

**Written-by note (persistence):**
- this 0x38: conditionally updated during table walk (moves to next node)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant (not directly referenced in this C code) |
| 0059e440 | flt_59E440 | R | zero threshold (not directly referenced) |
| 0059e450 | flt_59E450 | R | degrees-to-radians (not directly referenced) |
| 0059e800 | flt_59E800 | R | amplitude limit (not directly referenced) |
| 0059e84c | flt_59E84C | R | velocity rate limit (not directly referenced) |
| 0059e864 | flt_59E864 | R | color quantization scale (not directly referenced) |
| 005accb0 | flt_5ACCB0 | R | clutch catch speed scale (not directly referenced) |
| 005ad30c | flt_5AD30C | R | unknown float damper decay (not directly referenced) |
| 005ad310 | flt_5AD310 | R | brake force accumulation coeff (not directly referenced) |
| 005ad314 | flt_5AD314 | R | traction control multiplier (not directly referenced) |
| 005ad318 | flt_5AD318 | R | physics decay linear constant (not directly referenced) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fd6f0 | RangeInterpolationTable | final range interpolation/mapping of envelope values |
| 004fde00 | sub_4FDE00 | float-range envelope computation (called with interpolated v17) |

**Guard conditions:** three main branches: (1) table walk continues while a3 >= current node threshold; (2) v8[10] decay selected by comparison against low threshold; (3) v8[11] decay selected by comparison against same threshold.
