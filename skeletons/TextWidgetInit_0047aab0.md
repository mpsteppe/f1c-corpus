## TextWidgetInit_0047aab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | R | — | [LLM] |
| this | 0xE0 | RW | — | [LLM] |
| this | 0xE4 | RW | 0 | [LLM] |
| this | 0xE8 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0xF8 | RW | 5 | [LLM] |
| this | 0xFC | RW | 5 | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c71cc | aTtgjz | R | CodeKey_TTGJZ [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c5728 | dword_7C5728 | R | ScoreDB_BasePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
