## MenuCursorPositioning_0047b9c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC8) | 0x40 | R | — | [LLM] |
| *(this+0xE0) | 0x0 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b730 | MenuCursorNavigationHelper | [LLM] |
| 0047b910 | MenuItemRenderHelper | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
