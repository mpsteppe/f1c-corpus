## Sound_Enter_004c8a20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3380 | aEnteredSoundEn | R | EnteredSoundEnvString [DERIVED] |
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004116c0 | SceneGraphQuery | [LLM] |
| 004184f0 | LazyRendererAudioInitCheck | [LLM] |
| 004c82c0 | InitWithStatusCheck | [LLM] |
| 004c82f0 | sub_4C82F0 | [LLM] |
| 004c83b0 | sub_4C83B0 | [LLM] |
| 004c8560 | LazyAudioResourceInit | [LLM] |
| 004c8900 | GlobalDispatchWithGuard | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
