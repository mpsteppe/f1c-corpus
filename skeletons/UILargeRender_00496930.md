## UILargeRender_00496930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x156C)+0x0) | 0x48 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x4C | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x50 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x5C | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x60 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x64 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x78 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x7C | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x8C | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x90 | R | — | [LLM] |
| *(*(this+0x156C)+0x0) | 0x94 | R | — | [LLM] |
| *(*(this+0x18)+0x0) | 0x38 | R | — | [LLM] |
| *(*(this+0x18)+0x0) | 0x3C | R | — | [LLM] |
| *(*(this+0x20)+0x0) | 0x58 | R | — | [LLM] |
| *(this+0x156C) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | 2 | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x88 | RW | — | [LLM] |
| this | 0x8C | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xC4 | RW | 0 | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0x1558 | R | — | [LLM] |
| this | 0x1560 | R | — | [LLM] |
| this | 0x1564 | R | — | [LLM] |
| this | 0x156C | RW | 0 | [LLM] |
| this | 0x1598 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x8C: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0xC4: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0x156C: [LLM: once/conditional? does external poke survive?]
- this 0x1598: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00496dd8 | jpt_49698B | R | [LLM] |
| 00496de0 | byte_496DE0 | R | [LLM] |
| 00496dec | jpt_496A74 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ac994 | flt_5AC994 | R | Flt_AiSteeringGain_C994 [DERIVED] |
| 005cc9e8 | dword_5CC9E8 | R | SessionInitState [CONFIRMED] (also: ` — multiplayer active flag) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486240 | UIStringAccessor | [LLM] |
| 00486260 | UIStringAccessor_6260 | [LLM] |
| 00486280 | UIStringAccessor_6280 | [LLM] |
| 004862a0 | UIStringAccessor_62a0 | [LLM] |
| 00495440 | FPSOverlayDraw | [LLM] |
| 004957a0 | UIClickEventDispatch | [LLM] |
| 00495980 | ObjectSearchWithDoubleIteration | [LLM] |
| 00496880 | sub_496880 | [LLM] |
| 00496e20 | sub_496E20 | [LLM] |
| 004979c0 | Setter | [LLM] |
| 00497e80 | sub_497E80 | [LLM] |
| 00498030 | RendererAlphaBlendSetter | [LLM] |
| 004986a0 | RenderStateReset | [LLM] |
| 00498720 | CollisionSpeedSetter | [LLM] |
| 00498740 | InitViewportDimensions | [LLM] |
| 004987b0 | CollisionResponseTypeClassification | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | != | 2 | [LLM] |
| this | 0x74 | == | 1 | [LLM] |
| this | 0x74 | == | 2 | [LLM] |
| this | 0x74 | == | 5 | [LLM] |
| this | 0x1598 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
