## SpriteOverlayListCleanup_004b6130 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30), BufferPoolAllocatorInitialization (004b71e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | RW | 0 | [LLM] |
| this | 0x9B4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x9B0: [LLM: once/conditional? does external poke survive?]
- this 0x9B4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b46f0 | QuadrupleListCleanup | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
