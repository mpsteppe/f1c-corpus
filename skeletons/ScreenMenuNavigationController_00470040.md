## ScreenMenuNavigationController_00470040 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xE0 | RW | 2 | [LLM] |
| this | 0xE8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
