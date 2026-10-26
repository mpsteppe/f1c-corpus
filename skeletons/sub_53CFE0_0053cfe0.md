## sub_53CFE0_0053cfe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionNodeAllocator (00494de0), CockpitDashboardLEDGaugeSetup (0049ca00), sub_4D8AB0 (004d8ab0), sub_4F8D70 (004f8d70), SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e20 | dword_8B8E20 | R | EntryRegistryHead [DERIVED] (also: ` â€” global linked list head (entry registry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d340 | LinkedListAppend_d340 | [LLM] |
| 005523e0 | HashTable | [LLM] |
| 00552470 | sub_552470 | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
