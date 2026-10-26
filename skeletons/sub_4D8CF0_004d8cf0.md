## sub_4D8CF0_004d8cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceInitWithConstants (004d8220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d8f94 | jpt_4D8D1F | R | [LLM] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d4ad8 | aHud51264Tga | R | HudTextureString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 00800004 | unk_800004 | R | InvalidPtrSentinel [DERIVED] |
| 008ad398 | dword_8AD398 | R | StateHandleArray [DERIVED] (also: , _39c, _3a0, _3a4, _3a8 — state handles) |
| 008ad39c | dword_8AD39C | R | RenderBufferID_2 [DERIVED] |
| 008ad3a0 | dword_8AD3A0 | R | AudioEmitter_Idx3 [DERIVED] |
| 008ad3a4 | dword_8AD3A4 | R | AudioChannel4 [DERIVED] |
| 008ad3a8 | flt_8AD3A8 | R | AudioStreamHandle [DERIVED] |
| 008ad3ac | dword_8AD3AC | RW | TrackDB_DataPtr [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d9030 | AudioResourceReleaseByType | [LLM] |
| 0054fe10 | StructInitWithZeroFill | [LLM] |
| 00550080 | D3DTextureCreation | [LLM] |
| 005502c0 | DestructorWithConditionalFreeFlagClear | [LLM] |
| 00553620 | SetterWrites0x10Returns0 | [LLM] |
| 00553650 | sub_553650 | [LLM] |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
