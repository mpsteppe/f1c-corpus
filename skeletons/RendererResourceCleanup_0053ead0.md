## RendererResourceCleanup_0053ead0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53E070 (0053e070), GlobalDispatch (0055c040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | RW | 0 | [LLM] |
| this | 0x1524 | RW | 0 | [LLM] |
| this | 0x1528 | RW | 0 | [LLM] |
| this | 0x152C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1100: [LLM: once/conditional? does external poke survive?]
- this 0x1524: [LLM: once/conditional? does external poke survive?]
- this 0x1528: [LLM: once/conditional? does external poke survive?]
- this 0x152C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053f270 | RenderTargetCleanup | [LLM] |
| 0053f6e0 | sub_53F6E0 | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
