## FloatFractionFromInt_00464ef0 — Accumulator fraction processing with iteration

**Summary:** Adds a2 to accumulator at this[26], extracts integer part v4 via CRTFtol, iterates 104 items at this+35 stepping by 560 bytes calling sub_464B10 with v4, stores fractional remainder (v3 - v4*0.005) back to accumulator.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceManagerFrameCleanup (004651c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68 | RW | — | Float accumulator; incremented then fractional remainder stored back |

**Written-by note (persistence):**
- this 0x68: unconditionally updated each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f138 | flt_59F138 | R | RadToDegFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464b10 | sub_464B10 | Process each of 104 items with the integer part |
| 00587bdc | CRTFtol | Converts float to int (truncation) |

**Guard conditions:** No guard — always processes accumulator and iterates all 104 items.
