## CareerStandingsStateLoader_004c03f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerSeasonStateFileReader (004c0b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1B0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc650 | aName_2 | R | StringName [DERIVED] |
| 005d267c | aActive | R | String_Active [DERIVED] |
| 005d2684 | aControltype | R | StringControlType [DERIVED] |
| 005d2690 | aCurrentgridpos | R | CurrentGridPosString [DERIVED] |
| 005d26a4 | aOriginalgridpo | R | OriginalGridPosString [DERIVED] |
| 005d26bc | aPolestaken | R | PolesTakenString [DERIVED] |
| 005d26c8 | aPointsposition | R | PointsPositionStr [DERIVED] |
| 005d26d8 | aSeasonpoints | R | SeasonPointsString [DERIVED] |
| 005d26e8 | aFinishpoints | R | FinishPointsField [DERIVED] |
| 005d26f8 | aS22d | R | FormatS22d [DERIVED] |
| 005d2700 | aFinishposition | R | String_FinishPosition [DERIVED] |
| 005d2710 | aRcdfile | R | RcdFileString [DERIVED] |
| 005d2718 | aVehfile | R | VehfileString [DERIVED] |
| 008ac050 | unk_8AC050 | R | Unknown_SceneSetup_8AC050 [DERIVED] |
| 008ac1e8 | unk_8AC1E8 | R | SceneRenderStruct [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
