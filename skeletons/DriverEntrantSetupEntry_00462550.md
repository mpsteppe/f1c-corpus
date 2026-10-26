## DriverEntrantSetupEntry_00462550 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3FC8)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x3FC8) | 0x0 | R | — | [LLM] |
| *(obj+0x3FC8) | 0x8 | R | — | [LLM] |
| obj | 0x1AC | R | — | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | RW | 2 | [LLM] |
| obj | 0x3FC8 | RW | 0 | [LLM] |
| obj | 0x3FCC | RW | 0 | [LLM] |
| obj | 0x3FD0 | RW | 0 | [LLM] |
| obj | 0x3FD4 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x3FC4: [LLM: once/conditional? does external poke survive?]
- obj 0x3FC8: [LLM: once/conditional? does external poke survive?]
- obj 0x3FCC: [LLM: once/conditional? does external poke survive?]
- obj 0x3FD0: [LLM: once/conditional? does external poke survive?]
- obj 0x3FD4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd270 | unk_7CD270 | R | HudLayout_Default [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007d0fc4 | dword_7D0FC4 | R | RaceSetupByte_0FC4 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c240 | FileScanner | [LLM] |
| 0045e590 | BufferFillWith0xFFFFFFFF | [LLM] |
| 004615f0 | BitFlagTestAt0x6E | [LLM] |
| 00461cd0 | SessionStateCheck | [LLM] |
| 00463710 | StringCopyToStructField | [LLM] |
| 0057a200 | MemcpyLikeCopyWithWordByteSplitSizeStore | [LLM] |
| 0057a4f0 | VirtualFunctionDispatchWithStackFrames | [LLM] |
| 0057a880 | VTableQueryWithStackBufferResult | [LLM] |
| 0057a8b0 | VTableCallViaOffset0x7c | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
