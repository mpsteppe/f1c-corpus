## GlobalResourceCleanup_0053c4d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TestAndFreeWrapper (0053d4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f04 | dword_8B8F04 | RW | NetConfigData [DERIVED] |
| 008b8f18 | dword_8B8F18 | RW | NetConfigData [DERIVED] |
| 008b8f1c | dword_8B8F1C | RW | NetConfigData [DERIVED] |
| 008b8f20 | dword_8B8F20 | RW | ResourceHandle [DERIVED] |
| 008b8f2c | dword_8B8F2C | RW | RenderResourceHandle2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 0053ad50 | sub_53AD50 | [LLM] |
| 0053d850 | ObjectReleaseWithVtableCall | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 0055bf70 | ArrayOfPointersCleanupWithFreeLoop | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
