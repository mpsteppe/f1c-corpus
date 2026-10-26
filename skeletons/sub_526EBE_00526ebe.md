## sub_526EBE_00526ebe — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (also: ` — SIMD constant (likely PI or angle scalar) |
| 005af910 | qword_5AF910 | R | SIMDMathConst [DERIVED] |
| 005af920 | qword_5AF920 | R | MMXSignFlipConst [DERIVED] |
| 005af968 | qword_5AF968 | R | ThreeDNow_Constant_5AF968 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
