## DirectDrawDisplayModeInit_00563e00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StartNetworkUpdate (00461de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0x98 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x98: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005640f0 | sub_5640F0 | R | [LLM] |
| 005645a0 | sub_5645A0 | R | [LLM] |
| 00564600 | IndirectDwordCompare | R | [LLM] |
| 00564630 | sub_564630 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005646d0 | AllocateIntArrayViaFactory | [LLM] |
| 00564740 | DestroyAudioArrayFreeElementsThenContainer | [LLM] |
| 00564810 | Malloc0x18ByteStructWithInnerBuffer | [LLM] |
| 00564860 | BatchLoopWithMemoryCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
