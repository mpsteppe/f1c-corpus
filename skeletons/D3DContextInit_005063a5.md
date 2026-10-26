## D3DContextInit_005063a5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), AudioSoundBufferSetup (005007ef)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00502f31 | sub_502F31 | [LLM] |
| 00504508 | SurfacePixelCopy | [LLM] |
| 00504640 | MemoryAllocationWithVectorConstructor | [LLM] |
| 00504731 | sub_504731 | [LLM] |
| 00504933 | Direct3DTextureResampling | [LLM] |
| 00504b37 | COMInterfaceVectorProcessingMethod | [LLM] |
| 00504f5a | MultiLevelBufferAllocationWithVectorOps | [LLM] |
| 005054ec | sub_5054EC | [LLM] |
| 005058d2 | VertexBufferAllocationAndStageTransformation | [LLM] |
| 00506003 | sub_506003 | [LLM] |
| 005076fe | TextureCopyRealloc | [LLM] |
| 0050b8a9 | DirectXTextureSurfaceFactoryDispatchingFourCCCod | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
