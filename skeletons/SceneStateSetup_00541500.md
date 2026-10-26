## SceneStateSetup_00541500 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCopyWithFlagUnion (0055d2a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xB0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | R | — | [LLM] |
| this | 0x13B4 | RW | — | [LLM] |
| this | 0x13D8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x13B4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad208 | dbl_5AD208 | R | LifetimeClampThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
