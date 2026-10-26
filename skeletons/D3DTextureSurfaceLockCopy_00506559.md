## D3DTextureSurfaceLockCopy_00506559 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), SurfaceBlitOperation (0050099c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x24 | R | — | [LLM] |
| *(*(this+0xC)+0x0) | 0x6C | R | — | [LLM] |
| *(*(this+0xC)+0x0) | 0x70 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad4c0 | unk_5AD4C0 | R | Unknown_Struct_5AD4C0 [DERIVED] |
| 005ad4d0 | unk_5AD4D0 | R | D3DSurfaceDesc [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00500eac | sub_500EAC | [LLM] |
| 005064cf | RenderResourceTeardown | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
