## ClampedReciprocalWithGuard_004fefc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690), sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | 1008981770 → 0.01f | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0xAC: [LLM: once/conditional? does external poke survive?]
- this 0xB0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 005ad2c0 | flt_5AD2C0 | R | InterpCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
