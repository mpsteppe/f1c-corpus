## D3DTextureCreation_00550080 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleNodeCreation (0049e930), AudioSoundCreateWithHandle (0049e9a0), sub_4D8CF0 (004d8cf0), sub_4DCBA0 (004dcba0), sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x2C | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x54) 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005b8908 | dbl_5B8908 | R | Unknown_dbl_5B8908 [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |
| 008b8e28 | dword_8B8E28 | R | AudioInitialized [DERIVED] |
| 008b8e2c | dword_8B8E2C | R | RendererMipmapFlag [DERIVED] |
| 008b8e4c | dword_8B8E4C | R | MipLODBiasCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d890 | IndexedArrayAccess_d890 | [LLM] |
| 005427d0 | sub_5427D0 | [LLM] |
| 005429b0 | sub_5429B0 | [LLM] |
| 005435c0 | sub_5435C0 | [LLM] |
| 0054fe50 | sub_54FE50 | [LLM] |
| 005502c0 | DestructorWithConditionalFreeFlagClear | [LLM] |
| 0055bfc0 | SimpleFieldGetter_bfc0 | [LLM] |
| 0055c3c0 | GetVTableParamBasedOnFlagBits | [LLM] |
| 0055c7f0 | KeyEventDispatchToSubHandlers | [LLM] |
| 0055c9a0 | MaskedFieldGetter | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
