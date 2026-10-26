## VertexBufferResourceAllocation_00543fa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110), VehicleGraphicsSceneLoader (004dfce0), AudioEngineInitialization (00546010), sub_559200 (00559200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x154) | 0x4C | R | — | [LLM] |
| *(this+0x204) | 0xEC | R | — | [LLM] |
| *(this+0x204) | 0x104 | R | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x14C | RW | 0 | [LLM] |
| this | 0x150 | RW | 0 | [LLM] |
| this | 0x1B4 | RW | 0 | [LLM] |
| this | 0x1B8 | RW | 0 | [LLM] |
| this | 0x1BC | RW | 0 | [LLM] |
| this | 0x1C0 | RW | 0 | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 0 | [LLM] |
| this | 0x1D0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x14C: [LLM: once/conditional? does external poke survive?]
- this 0x150: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1B8: [LLM: once/conditional? does external poke survive?]
- this 0x1BC: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]
- this 0x1C8: [LLM: once/conditional? does external poke survive?]
- this 0x1CC: [LLM: once/conditional? does external poke survive?]
- this 0x1D0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00544720 | jpt_5445A4 | R | [LLM] |
| 0059e234 | InterlockedDecrement | R | [LLM] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 00804000 | unk_804000 | R | D3D_VertexBuffer_State [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8eec | Addend | R | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 0053c9c0 | BitFlagArrayUpdate | [LLM] |
| 0053ced0 | DoublyLinkedListNodeRemovalByFlag | [LLM] |
| 005414e0 | Field0x13B0Accessor | [LLM] |
| 00544740 | sub_544740 | [LLM] |
| 00544d30 | AudioNetworkTreeWalker | [LLM] |
| 00545a10 | UILinkedListCleanupIterator | [LLM] |
| 00545a40 | sub_545A40 | [LLM] |
| 00545bb0 | SceneInstanceCollection | [LLM] |
| 00545f50 | AudioVolumeLoadComputation | [LLM] |
| 005487a0 | LinkedListWalkInterlockedDec | [LLM] |
| 00548810 | LinkedListAccumulation | [LLM] |
| 00548850 | sub_548850 | [LLM] |
| 00548e00 | ShortComputation_8e00 | [LLM] |
| 0054bd30 | SceneGraphRenderWalk | [LLM] |
| 00557240 | sub_557240 | [LLM] |
| 00557280 | CleanupFunction | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
