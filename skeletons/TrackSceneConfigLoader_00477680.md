## TrackSceneConfigLoader_00477680 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CopyProfileIconBMP (0046cd20), GameMode (0046d6d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007ce668 | dword_7CE668 | R | TrackNameStringPtr [DERIVED] (also: ` � track name display string) |
| 008ac36c | dword_8AC36C | R | Unknown_VehicleSetup_8AC36C [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac38c | dword_8AC38C | W | CurrentFontHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f590 | LinkedListIndexedAccessor_f590 | [LLM] |
| 004b1520 | sub_4B1520 | [LLM] |
| 004c4080 | CurrentVehicleAccessor | [LLM] |
| 004c4d50 | sub_4C4D50 | [LLM] |
| 004c4ff0 | SeasonSceneMatchByIndex | [LLM] |
| 004c5130 | ListIndexedAccessor | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
