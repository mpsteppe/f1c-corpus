## GameFilterDataLoader_004c0db0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NodeAllocListInsert (004c2780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A4 | RW | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |
| this | 0x1AC | RW | 1 | [LLM] |
| this | 0x1B0 | RW | 1 | [LLM] |
| this | 0xB110 | RW | — | [LLM] |
| this | 0xB114 | RW | — | [LLM] |
| this | 0xB118 | RW | 0 | [LLM] |
| this | 0xB11C | RW | 1 | [LLM] |
| this | 0xB144 | RW | 2 | [LLM] |
| this | 0xB148 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1A4: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1AC: [LLM: once/conditional? does external poke survive?]
- this 0x1B0: [LLM: once/conditional? does external poke survive?]
- this 0xB110: [LLM: once/conditional? does external poke survive?]
- this 0xB114: [LLM: once/conditional? does external poke survive?]
- this 0xB118: [LLM: once/conditional? does external poke survive?]
- this 0xB11C: [LLM: once/conditional? does external poke survive?]
- this 0xB144: [LLM: once/conditional? does external poke survive?]
- this 0xB148: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007d0a20 | dword_7D0A20 | R | SessionVehicleCount [DERIVED] (also: ` — vehicle count) |
| 007d0dcc | dword_7D0DCC | R | AlternateFilterPath [DERIVED] (also: ` — alternate game filter path) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0b20 | sub_4B0B20 | [LLM] |
| 004bf630 | ZeroInit4Ints | [LLM] |
| 004bf640 | LinkedListDestruction_f640 | [LLM] |
| 004bf790 | AIOpponentSelection | [LLM] |
| 004bfcd0 | VehicleArrayIndexAccessor | [LLM] |
| 004c07f0 | LapSessionDataArrayInitializer | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 005681f0 | ConditionalDispatch_81f0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
