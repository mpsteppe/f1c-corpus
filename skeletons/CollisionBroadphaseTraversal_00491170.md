## CollisionBroadphaseTraversal_00491170 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_1c70 (00491c70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x8)+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(*(this+0x8)+0x4)+0x0) | 0x2 | R | — | [LLM] |
| *(*(*(this+0x8)+0x4)+0x0) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x8)+0x4)+0x0) | 0x6 | R | — | [LLM] |
| *(*(this+0x8)+0x4) | 0x0 | R | — | [LLM] |
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(obj+0x0) | 0x2 | R | — | [LLM] |
| *(obj+0x0) | 0x4 | R | — | [LLM] |
| *(obj+0x0) | 0x6 | R | — | [LLM] |
| *(this+0x8) | 0x4 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | [LLM] |
| 00491170 | CollisionBroadphaseTraversal | [LLM] |
| 00491350 | RectangleClipping | [LLM] |
| 004915a0 | AABBOverlapTest | [LLM] |
| 00491680 | sub_491680 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
