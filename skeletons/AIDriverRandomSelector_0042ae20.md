## AIDriverRandomSelector_0042ae20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C6E80 (004c6e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4420 | RW | — | [LLM] |
| this | 0x45F8 | RW | — | [LLM] |
| this | 0x45FC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4420: [LLM: once/conditional? does external poke survive?]
- this 0x45F8: [LLM: once/conditional? does external poke survive?]
- this 0x45FC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ad00 | LateralForceTorqueCalculation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
