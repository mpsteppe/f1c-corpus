## QueueResourceCleanup_0054c410 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraph (0054a770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |
| this | 0x144 | RW | 0 | [LLM] |
| this | 0x184 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x144: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 00540cb0 | AudioResourceFree | [LLM] |
| 00545f40 | ValueGetter | [LLM] |
| 00547710 | sub_547710 | [LLM] |
| 005511a0 | ObjectDestructorWithArrayCleanup | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x118 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
