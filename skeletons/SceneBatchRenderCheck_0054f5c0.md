## SceneBatchRenderCheck_0054f5c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UIFocusChange (0054f7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E0) | 0x0 | R | — | [LLM] |
| *(this+0x1E0) | 0x4 | R | — | [LLM] |
| *(this+0x204) | 0xE8 | R | — | [LLM] |
| *(this+0x204) | 0xEC | R | — | [LLM] |
| *(this+0x204) | 0xF0 | R | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008c5f40 | dword_8C5F40 | RW | AudioOutputHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | [LLM] |
| 0054eed0 | sub_54EED0 | [LLM] |
| 0054f2f0 | CollisionContactDetection | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
