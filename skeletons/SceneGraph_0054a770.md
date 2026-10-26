## SceneGraph_0054a770 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150), sub_549110 (00549110), sub_557670 (00557670), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | R | — | [LLM] |
| this | 0x1EC | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x224 | RW | 0 | [LLM] |
| this | 0x228 | R | — | [LLM] |
| this | 0x22C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x224: [LLM: once/conditional? does external poke survive?]
- this 0x22C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 0054ac30 | DoublyLinkedListUnlink_ac30 | [LLM] |
| 0054c410 | QueueResourceCleanup | [LLM] |
| 0054fa50 | LinkedNodeDestruction | [LLM] |
| 00561940 | FieldCleanupWithNullCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
