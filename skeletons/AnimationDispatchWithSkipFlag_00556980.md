## AnimationDispatchWithSkipFlag_00556980 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveStateTraversalWithFlagCheck (00556930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x204) | 0x20 | R | — | [LLM] |
| *(this+0x204) | 0x24 | RW | — | [LLM] |
| *(this+0x204) | 0x14C | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x204) 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | [LLM] |
| 005569f0 | SceneNodeStateUpdateWithTransform | [LLM] |
| 00556b10 | sub_556B10 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
