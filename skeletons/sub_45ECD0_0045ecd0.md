## sub_45ECD0_0045ecd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B780) | 0x0 | R | — | [LLM] |
| *(this+0x1B784) | 0x4 | R | — | [LLM] |
| this | 0x1B780 | RW | 0 | [LLM] |
| this | 0x1B784 | RW | 0 | [LLM] |
| this | 0x1B788 | RW | 0 | [LLM] |
| this | 0x1B78C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1B780: [LLM: once/conditional? does external poke survive?]
- this 0x1B784: [LLM: once/conditional? does external poke survive?]
- this 0x1B788: [LLM: once/conditional? does external poke survive?]
- this 0x1B78C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5de8 | aAutochat10 | R | AutoChat10String [DERIVED] |
| 005c5df4 | aAutochat09 | R | Autochat09Field [DERIVED] |
| 005c5e00 | aAutochat08 | R | Format_AutoChat [DERIVED] |
| 005c5e0c | aAutochat07 | R | String_AutoChat [DERIVED] |
| 005c5e18 | aAutochat06 | R | AutoChat06String [DERIVED] |
| 005c5e24 | aAutochat05 | R | Autochat05String [DERIVED] |
| 005c5e30 | aAutochat04 | R | AutoChatString [DERIVED] |
| 005c5e3c | aAutochat03 | R | String_AutoChat [DERIVED] |
| 005c5e48 | aAutochat02 | R | s_AutoChat02 [DERIVED] |
| 005c5e54 | aAutochat01 | R | AutoChat01 [DERIVED] |
| 005c5e60 | dword_5C5E60 | R | MenuResourcePtr [DERIVED] |
| 005c5e64 | dword_5C5E64 | R | Int_RenderState_5E64 [DERIVED] |
| 005c5e68 | dword_5C5E68 | R | Unknown_Renderer_5C5E68 [DERIVED] |
| 005c5e6c | dword_5C5E6C | R | Unknown_Dword_5C5E6C [DERIVED] |
| 005c5e70 | word_5C5E70 | R | Word_UIDataBuffer [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0220 | PathTruncationUtility | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B78C | >= | 10 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
