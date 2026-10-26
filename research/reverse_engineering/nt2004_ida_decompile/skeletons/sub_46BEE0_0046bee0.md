## sub_46BEE0_0046bee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_466E60 (00466e60), sub_46BB60 (0046bb60), sub_46BD20 (0046bd20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5344 | GetDlgItem | R | [LLM] |
| 005d5348 | SendDlgItemMessageA | R | [LLM] |
| 005d534c | SetWindowTextA | R | [LLM] |
| 005fbe14 | aSeasonraces | R | [LLM] |
| 005fcc0c | aS_0 | R | [LLM] |
| 005fd7ac | aTrackType | R | [LLM] |
| 00600edc | aSS_8 | R | [LLM] |
| 00600ee4 | aLength | R | [LLM] |
| 00600eec | aTrackname_0 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 007652bc | hWnd | R | [LLM] |
| 007d6a30 | byte_7D6A30 | R | [LLM] |
| 007d7a10 | byte_7D7A10 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405480 | sub_405480 | [LLM] |
| 004e8dd0 | SeasonSceneNameAccessor [structural] | [LLM] |
| 0057a6d0 | sub_57A6D0 | [LLM] |
| 0057a720 | StringKeyedLinkedListSearch [structural] | [LLM] |
| 0057ae50 | sub_57AE50 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SeasonRaces`
- `Track Type`
- `%s, %s`
- `Length`
- `TrackName`
