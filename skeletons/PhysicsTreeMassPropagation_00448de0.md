## PhysicsTreeMassPropagation_00448de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactResponse (00449700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448de0 | PhysicsTreeMassPropagation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
