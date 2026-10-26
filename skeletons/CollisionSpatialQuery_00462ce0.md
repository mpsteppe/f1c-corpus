## CollisionSpatialQuery_00462ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SendJoinRequest (00462c00), AutoJoinRetryLoop (004637a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | RW | — | [LLM] |
| obj | 0x29 | RW | 1 | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x10: [LLM: once/conditional? does external poke survive?]
- obj 0x29: [LLM: once/conditional? does external poke survive?]
- obj 0x3FC4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0a0 | flt_59F0A0 | R | MulticastTimeout [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a580 | VTableCallViaOffset0x6c | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
