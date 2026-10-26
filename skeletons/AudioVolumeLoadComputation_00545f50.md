## AudioVolumeLoadComputation_00545f50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0), AudioEngineInitialization (00546010), LinkedListWalkInterlockedDec (005487a0), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00545ff8 | jpt_545F6C | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e990 | flt_59E990 | R | PhysicsConstant_59E990 [DERIVED] |
| 008b8ee8 | dword_8B8EE8 | R | AudioBufferSize [DERIVED] |
| 008b8eec | Addend | R | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |
| 008b8ef0 | dword_8B8EF0 | R | AudioBufferDataPtr [DERIVED] (also: ` — buffer pointer/reference) |
| 008b8ef4 | dword_8B8EF4 | R | TotalAudioSampleDataSize [DERIVED] (also: ` — total sample data size) |
| 008b8ef8 | dword_8B8EF8 | R | AudioBufferReadyCounter [DERIVED] (also: ` — buffer ready counter) |
| 008b8f00 | dword_8B8F00 | R | AudioSystemCallback [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
