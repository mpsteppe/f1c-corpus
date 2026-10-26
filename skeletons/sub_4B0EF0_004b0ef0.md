## sub_4B0EF0_004b0ef0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigWriteback (00461900), SessionInit (004a06e0), PlayerFileInit (004b0540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C4 | RW | — | [LLM] |
| this | 0x5CC | R | — | [LLM] |
| this | 0x5D0 | R | — | [LLM] |
| this | 0x7F8 | RW | — | [LLM] |
| this | 0x800 | R | — | [LLM] |
| this | 0x804 | R | — | [LLM] |
| this | 0x8F4 | RW | — | [LLM] |
| this | 0x8FC | R | — | [LLM] |
| this | 0x900 | R | — | [LLM] |
| this | 0x9F0 | RW | — | [LLM] |
| this | 0x9F8 | R | — | [LLM] |
| this | 0x9FC | R | — | [LLM] |
| this | 0xAEC | RW | — | [LLM] |
| this | 0xAF4 | R | — | [LLM] |
| this | 0xAF8 | R | — | [LLM] |
| this | 0xBE8 | RW | — | [LLM] |
| this | 0xBF0 | R | — | [LLM] |
| this | 0xBF4 | R | — | [LLM] |
| this | 0xCE4 | RW | — | [LLM] |
| this | 0xCE6 | R | — | [LLM] |
| this | 0xCE7 | R | — | [LLM] |
| this | 0x1C54 | RW | 7 | [LLM] |
| this | 0x1C5C | R | — | [LLM] |
| this | 0x1C60 | R | — | [LLM] |
| this | 0x1F78 | RW | — | [LLM] |
| this | 0x1F80 | R | — | [LLM] |
| this | 0x1F84 | R | — | [LLM] |
| this | 0x200C | RW | — | [LLM] |
| this | 0x2014 | R | — | [LLM] |
| this | 0x2018 | R | — | [LLM] |
| this | 0x2108 | RW | — | [LLM] |
| this | 0x2110 | R | — | [LLM] |
| this | 0x2114 | R | — | [LLM] |
| this | 0x2204 | RW | — | [LLM] |
| this | 0x220C | R | — | [LLM] |
| this | 0x2210 | R | — | [LLM] |
| this | 0x2300 | RW | — | [LLM] |
| this | 0x2308 | R | — | [LLM] |
| this | 0x230C | R | — | [LLM] |
| this | 0x23FC | RW | — | [LLM] |
| this | 0x2404 | R | — | [LLM] |
| this | 0x2408 | R | — | [LLM] |
| this | 0x24F8 | RW | — | [LLM] |
| this | 0x2500 | R | — | [LLM] |
| this | 0x2504 | R | — | [LLM] |
| this | 0x26CC | RW | — | [LLM] |
| this | 0x26D4 | R | — | [LLM] |
| this | 0x26D8 | R | — | [LLM] |
| this | 0x27C8 | RW | — | [LLM] |
| this | 0x27D0 | R | — | [LLM] |
| this | 0x27D4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C4: [LLM: once/conditional? does external poke survive?]
- this 0x7F8: [LLM: once/conditional? does external poke survive?]
- this 0x8F4: [LLM: once/conditional? does external poke survive?]
- this 0x9F0: [LLM: once/conditional? does external poke survive?]
- this 0xAEC: [LLM: once/conditional? does external poke survive?]
- this 0xBE8: [LLM: once/conditional? does external poke survive?]
- this 0xCE4: [LLM: once/conditional? does external poke survive?]
- this 0x1C54: [LLM: once/conditional? does external poke survive?]
- this 0x1F78: [LLM: once/conditional? does external poke survive?]
- this 0x200C: [LLM: once/conditional? does external poke survive?]
- this 0x2108: [LLM: once/conditional? does external poke survive?]
- this 0x2204: [LLM: once/conditional? does external poke survive?]
- this 0x2300: [LLM: once/conditional? does external poke survive?]
- this 0x23FC: [LLM: once/conditional? does external poke survive?]
- this 0x24F8: [LLM: once/conditional? does external poke survive?]
- this 0x26CC: [LLM: once/conditional? does external poke survive?]
- this 0x27C8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | [LLM] |
| 00464720 | ByteClamp | [LLM] |
| 0047f1f0 | ClampByRange | [LLM] |
| 004b1190 | sub_4B1190 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
