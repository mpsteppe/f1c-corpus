## ActorNodeLinkedListAppend_00545250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewMeshLoader (004a2010), PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x154)+0x4C) | 0x4C | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x154 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x154)+0x4C) 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544c50 | TreeNodeAccumulator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
