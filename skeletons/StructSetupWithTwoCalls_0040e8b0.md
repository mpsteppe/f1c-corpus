## StructSetupWithTwoCalls_0040e8b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |
| this | 0x1C | RW | 8 | [LLM] |
| this | 0x20 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e480 | LightFrustumClosestPoint | [LLM] |
| 004be1d0 | NestedLoopRangeTraversal | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
