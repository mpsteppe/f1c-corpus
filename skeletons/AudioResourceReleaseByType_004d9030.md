## AudioResourceReleaseByType_004d9030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_8720 (004d8720), sub_4D8CF0 (004d8cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d90bc | jpt_4D903E | R | [LLM] |
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
| 005502c0 | DestructorWithConditionalFreeFlagClear | [LLM] |
| 005539f0 | ResourceCascadeCleanup | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
