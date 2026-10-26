## UIFocusChange_0054f7a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SwitchBasedStateHandler (0040f380), SphereProximityTag (004bdb10), AIRacingLinePathFollowing (004e9ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x218 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x218: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008c5f40 | dword_8C5F40 | W | AudioOutputHandle [DERIVED] |
| 008c5f44 | dword_8C5F44 | W | UIFocusFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | [LLM] |
| 0054f5c0 | SceneBatchRenderCheck | [LLM] |
| 0054f710 | RenderListIteration | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
