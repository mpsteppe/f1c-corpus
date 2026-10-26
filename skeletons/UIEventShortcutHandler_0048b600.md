## UIEventShortcutHandler_0048b600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2F4) | 0x0 | RW | 0 | [LLM] |
| *(this+0x2F4) | 0x1 | RW | 0 | [LLM] |
| *(this+0xC8) | 0x40 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0xB0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xE5 | R | — | [LLM] |
| this | 0x2EC | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x2F4 | RW | — | [LLM] |
| this | 0x2F8 | R | — | [LLM] |
| this | 0x2FC | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x2F4) 0x0: [LLM: once/conditional? does external poke survive?]
- *(this+0x2F4) 0x1: [LLM: once/conditional? does external poke survive?]
- this 0x2F4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455b30 | TranslateVirtualKey | [LLM] |
| 0048b560 | sub_48B560 | [LLM] |
| 0048b910 | SetterVTableIDCheck | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 0049a490 | StringReverseCopyLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
