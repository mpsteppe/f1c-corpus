## AudioEngineInitialization_00546010 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CUBESceneLoaderEntry (0048e8d0), VidMan_Init (004fa320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x100)+0x104) | 0x104 | R | — | [LLM] |
| *(obj+0x110) | 0x14 | R | — | [LLM] |
| *(obj+0x110) | 0x18 | R | — | [LLM] |
| *(obj+0x110) | 0x1C | R | — | [LLM] |
| *(obj+0x110) | 0x20 | R | — | [LLM] |
| obj | 0xEC | RW | — | [LLM] |
| obj | 0x100 | R | — | [LLM] |
| obj | 0x110 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- obj 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e238 | InterlockedIncrement | R | [LLM] |
| 008b8ee8 | dword_8B8EE8 | RW | AudioBufferSize [DERIVED] |
| 008b8eec | Addend | RW | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |
| 008b8ef0 | dword_8B8EF0 | W | AudioBufferDataPtr [DERIVED] (also: ` — buffer pointer/reference) |
| 008b8ef4 | dword_8B8EF4 | W | TotalAudioSampleDataSize [DERIVED] (also: ` — total sample data size) |
| 008b8ef8 | dword_8B8EF8 | RW | AudioBufferReadyCounter [DERIVED] (also: ` — buffer ready counter) |
| 008b8f00 | dword_8B8F00 | R | AudioSystemCallback [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |
| 0053c5d0 | LinkedListAppend_c5d0 | [LLM] |
| 0053c630 | DoublyLinkedListUnlink | [LLM] |
| 005435d0 | AudioMixerChannelInitializer | [LLM] |
| 00543a80 | MemoryAllocationWithFallback | [LLM] |
| 00543fa0 | VertexBufferResourceAllocation | [LLM] |
| 00545f50 | AudioVolumeLoadComputation | [LLM] |
| 00549170 | ArithmeticComparison_9170 | [LLM] |
| 005492b0 | LinkedListWalkWithDispatch | [LLM] |
| 00549380 | LinkedListUpdate | [LLM] |
| 00549440 | AudioNodeUpdateWalk | [LLM] |
| 00549470 | sub_549470 | [LLM] |
| 0055b8c0 | sub_55B8C0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
