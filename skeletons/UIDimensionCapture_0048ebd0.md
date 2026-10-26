## UIDimensionCapture_0048ebd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SubCallFieldZero (00477080), GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |
| this | 0xE8 | RW | — | [LLM] |
| this | 0xEC | RW | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x114 | RW | — | [LLM] |
| this | 0x118 | RW | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x120 | RW | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |
| this | 0x128 | RW | — | [LLM] |
| this | 0x12C | RW | — | [LLM] |
| this | 0x130 | RW | — | [LLM] |
| this | 0x134 | RW | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x13C | RW | — | [LLM] |
| this | 0x140 | RW | — | [LLM] |
| this | 0x144 | RW | — | [LLM] |
| this | 0x148 | RW | — | [LLM] |
| this | 0x14C | RW | — | [LLM] |
| this | 0x168 | RW | 0 | [LLM] |
| this | 0x174 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]
- this 0x11C: [LLM: once/conditional? does external poke survive?]
- this 0x120: [LLM: once/conditional? does external poke survive?]
- this 0x124: [LLM: once/conditional? does external poke survive?]
- this 0x128: [LLM: once/conditional? does external poke survive?]
- this 0x12C: [LLM: once/conditional? does external poke survive?]
- this 0x130: [LLM: once/conditional? does external poke survive?]
- this 0x134: [LLM: once/conditional? does external poke survive?]
- this 0x138: [LLM: once/conditional? does external poke survive?]
- this 0x13C: [LLM: once/conditional? does external poke survive?]
- this 0x140: [LLM: once/conditional? does external poke survive?]
- this 0x144: [LLM: once/conditional? does external poke survive?]
- this 0x148: [LLM: once/conditional? does external poke survive?]
- this 0x14C: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | [LLM] |
| 00487060 | sub_487060 | [LLM] |
| 004870e0 | sub_4870E0 | [LLM] |
| 0048f9f0 | UIWindowTextSetup | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | < | 0 | [LLM] |
| this | 0x124 | < | 0 | [LLM] |
| this | 0x140 | < | 0 | [LLM] |
| this | 0x144 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
