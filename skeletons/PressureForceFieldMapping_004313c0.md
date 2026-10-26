## PressureForceFieldMapping_004313c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsStateInitIndexed (00431390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1640 | R | — | [LLM] |
| this | 0x1644 | RW | 0 | [LLM] |
| this | 0x1648 | R | — | [LLM] |
| this | 0x16C0 | R | — | [LLM] |
| this | 0x16C4 | RW | 0 | [LLM] |
| this | 0x16C8 | R | — | [LLM] |
| this | 0x16CC | R | — | [LLM] |
| this | 0x1CA8 | R | — | [LLM] |
| this | 0x1CAC | R | — | [LLM] |
| this | 0x1CB0 | R | — | [LLM] |
| this | 0x1CB4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1644: [LLM: once/conditional? does external poke survive?]
- this 0x16C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e290 | PositionIndexClamp | [LLM] |
| 0042ed00 | SessionStateIndexedLookup | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1640 | > | 0 | [LLM] |
| this | 0x16C0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
