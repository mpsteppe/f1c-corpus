## SceneListSearchByPath_00477ba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830), GameContentFilterCheck (00477aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x0 | R | — | [LLM] |
| *(this+0xF0) | 0x4 | R | — | [LLM] |
| *(this+0xF0) | 0x3C | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x174 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c54f0 | AIW | [LLM] |
| 004c55b0 | TrackSceneLoader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
