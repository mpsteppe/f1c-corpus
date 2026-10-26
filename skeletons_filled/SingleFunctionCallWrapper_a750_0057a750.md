## SingleFunctionCallWrapper_a750_0057a750 — ClampedValueStore

**Summary:** Computes a reference value via sub_587890, stores min(a3, computed result) at obj+0x80. Returns the computed result. Acts as a clamp/saturate operation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x80 | RW | — | stored clamped value: min(a3, sub_587890 result) |
| this | 0x0 | R | — | context pointer; *this gives base address for field offsets |

**Written-by note (persistence):**
- obj 0x80: written once per call with clamped value; survives as persistent field

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional computation, if/else is value clamp not guard

