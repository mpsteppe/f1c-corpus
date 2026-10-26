## D3DWindowSurfaceCreation_0044ee10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Setup (00455c60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x4)+0x0) | 0x18 | R | — | [LLM] |
| *(*(this+0x4)+0x0) | 0x1C | R | — | [LLM] |
| *(*(this+0x4)+0x0) | 0x2C | R | — | [LLM] |
| *(*(this+0x4)+0x0) | 0x34 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x24C | RW | 44 | [LLM] |
| this | 0x278 | R | — | [LLM] |
| this | 0x37C | RW | 0 | [LLM] |
| this | 0xC7C | RW | 18446744072619032576 → -0.5f | [LLM] |
| this | 0xC80 | RW | 18446744072598899917 → -0.1f | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x24C: [LLM: once/conditional? does external poke survive?]
- this 0x37C: [LLM: once/conditional? does external poke survive?]
- this 0xC7C: [LLM: once/conditional? does external poke survive?]
- this 0xC80: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0044ed10 | sub_44ED10 | R | [LLM] |
| 005ad3f0 | unk_5AD3F0 | R | RenderSetupDataPtr [DERIVED] |
| 005ad490 | unk_5AD490 | R | D3D_VertexBufferDesc [DERIVED] |
| 005b0e84 | unk_5B0E84 | R | VTable_44ee10 [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 1 | [LLM] |
| this | 0x278 | == | 19 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
