## PositionUpdate_0049aa70 — PositionalOffsetAccumulator

**Summary:** Adds each caller parameter to a corresponding baseline struct field and stores the result in an adjacent output field. Returns the computed X offset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiParamDispatch (004861a0), sub_4881F0 (004881f0), sub_492A40 (00492a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Baseline X coordinate |
| this | 0x8 | RW | — | Computed X = a2 + baseline X |
| this | 0xC | R | — | Baseline Y coordinate |
| this | 0x10 | RW | — | Computed Y = a3 + baseline Y |

**Written-by note (persistence):**
- this 0x8: overwritten each call with a2 + this[1]; external poke survives until next call
- this 0x10: overwritten each call with a3 + this[3]; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always reads baselines and writes computed positions unconditionally
