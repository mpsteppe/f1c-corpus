## sub_4FDE00_004fde00 — FloatRangeEnvelopeCompute

**Summary:** Computes two scalar outputs at offsets 0x20 and 0x24 from input float a2 using threshold-based envelope logic. Below 0.6: both zero. 0.6-0.7: first ramps linearly 0→1. 0.7-1.0: first saturates at 1, second ramps 0→1. Above 1.0: both saturate at 1. Used in audio/physics signal envelope context.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30), AudioADSREnvelope (004fdeb0), sub_4FE350 (004fe350), AudioEventRingBufferProcessing (004feaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | 0 | first output value (ramps from 0→1 over input range 0.6→0.7) |
| this | 0x24 | RW | 0 | second output value (ramps from 0→1 over input range 0.7→1.0) |

**Written-by note (persistence):**
- this 0x20: conditionally set per envelope logic; overwritten each call
- this 0x24: conditionally set per envelope logic; overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant (not directly referenced in this C code) |
| 0059e4e8 | flt_59E4E8 | R | physics/math scaling constant (not directly referenced in this C code) |
| 0059e6e8 | flt_59E6E8 | R | tire damping blend factor (not directly referenced in this C code) |
| 0059e8f8 | flt_59E8F8 | R | physics constant (not directly referenced in this C code) |
| 005ad304 | flt_5AD304 | R | particle fade-out slope (not directly referenced in this C code) |
| 005ad308 | flt_5AD308 | R | brake ramp slope (not directly referenced in this C code) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** main branch on a2 > 0.6f — if false, both outputs zeroed. Nested branches at 0.7 and 1.0 thresholds determine which ramp case applies.
