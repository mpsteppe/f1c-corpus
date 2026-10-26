## FunctionCallWrapper_2b10_004b2b10 — FloatToBitfield10BitsPacker

**Summary:** Multiplies a float by 3.0, truncates to integer, and packs the result into bits 22-31 (10 bits) of the dword at offset 0x30, preserving the lower 22 bits. Returns the updated dword value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | — | Bitfield dword: lower 22 bits preserved, upper 10 bits store encoded float |

**Written-by note (persistence):**
- this 0x30: overwritten each call with (int)(a2*3)<<22 | preserved low 22 bits; external poke partially survives (low 22 bits untouched)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always packs and stores unconditionally
