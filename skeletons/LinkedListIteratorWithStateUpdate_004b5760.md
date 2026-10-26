## LinkedListIteratorWithStateUpdate_004b5760 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x370 | RW | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x4 | R | — | [LLM] |
| *(this+0x28) | 0x8 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x20)+0x0) 0x370: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410f60 | SceneNodeDecoder | [LLM] |
| 005001d0 | FieldCompareConstant | [LLM] |
| 005001f0 | FloatComparisonCheck | [LLM] |
| 00500210 | AudioSamplePlaybackWithPitchModulationAndStereoP | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
