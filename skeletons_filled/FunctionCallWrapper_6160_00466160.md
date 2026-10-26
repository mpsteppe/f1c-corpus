## FunctionCallWrapper_6160_00466160 — ComputeAngleRatioAndStore

**Summary:** Computes sqrt(this[62]^2 - this[70]^2) → this[71] and this[70]/this[62] ratio → this[72]. Calls WrapperReturn0 and FloatConvertWrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF8 | R | — | field 62 — divisor/hypotenuse input |
| this | 0x118 | R | — | field 70 — dividend/opposite input |
| this | 0x11C | RW | — | field 71 — sqrt result storage |
| this | 0x120 | RW | — | field 72 — ratio result storage |

**Written-by note (persistence):**
- this 0x11C: conditional (computed). External poke survives.
- this 0x120: conditional (computed). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e6a0 | WrapperReturn0 | no-op/logging wrapper call |
| 00588570 | FloatConvertWrapper | float format conversion wrapper |

**Guard conditions:** None — unconditional computation.
