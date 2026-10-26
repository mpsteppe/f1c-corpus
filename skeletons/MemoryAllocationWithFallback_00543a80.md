## MemoryAllocationWithFallback_00543a80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8dbc | dword_8B8DBC | RW | AudioStreamHandleA [DERIVED] (also: ` — Stream handle A) |
| 008b8dc0 | dword_8B8DC0 | RW | StreamHandleB [DERIVED] |
| 008b8df4 | dword_8B8DF4 | R | ShadowMapWidth [DERIVED] |
| 008b8df8 | dword_8B8DF8 | R | SoundBufferFlags [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005426a0 | AudioEmitterCreate | [LLM] |
| 00542950 | UtilityFunction_2950 | [LLM] |
| 00542e50 | sub_542E50 | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 0055b6b0 | sub_55B6B0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
