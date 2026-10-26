## NationalityDriverInfoLoader_004c78f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47F230 (0047f230), AIDriverCountSetup (004bfd90), sub_4C0850 (004c0850), TwoCallDelegation (004c7b20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4677 | RW | 0 | [LLM] |
| this | 0x46B7 | RW | 0 | [LLM] |
| this | 0x46F7 | RW | 0 | [LLM] |
| this | 0x4898 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4677: [LLM: once/conditional? does external poke survive?]
- this 0x46B7: [LLM: once/conditional? does external poke survive?]
- this 0x46F7: [LLM: once/conditional? does external poke survive?]
- this 0x4898: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c73b8 | aNationality | R | aNationality [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6980 | SetDriverName | [LLM] |
| 004c69b0 | ShortStringSet | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
