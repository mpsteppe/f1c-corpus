## SeasonSpecificTeamIDLookup_00413b60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00413efc | jpt_413BB2 | R | [LLM] |
| 00413f40 | jpt_413C97 | R | [LLM] |
| 00413f84 | jpt_413D7C | R | [LLM] |
| 00413fc8 | jpt_413E5F | R | [LLM] |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |
| 005bf97c | aF12001Gdb | R | aF12001Gdb [DERIVED] |
| 005bf988 | aF12000Gdb | R | TrackDatabaseFilename [DERIVED] |
| 005bf994 | aF11999Gdb | R | aF11999Gdb [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414180 | sub_414180 | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
