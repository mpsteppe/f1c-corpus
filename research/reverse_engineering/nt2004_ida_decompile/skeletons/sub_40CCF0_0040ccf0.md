## sub_40CCF0_0040ccf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | [LLM] |
| obj | 0x18 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x66 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x66: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5718 | off_5D5718 | R | [LLM] |
| 005d5744 | off_5D5744 | R | [LLM] |
| 005d5748 | off_5D5748 | R | [LLM] |
| 005fb7e8 | Format | R | [LLM] |
| 005fc044 | dword_5FC044 | R | [LLM] |
| 005fc048 | dword_5FC048 | R | [LLM] |
| 005fc04c | dword_5FC04C | R | [LLM] |
| 005fc050 | off_5FC050 | R | [LLM] |
| 005fc054 | aCareer_0 | R | [LLM] |
| 005fc05c | aAndNascarClose | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a068 | dword_62A068 | R | [LLM] |
| 007663e0 | byte_7663E0 | R | [LLM] |
| 007665d8 | dword_7665D8 | R | [LLM] |
| 007d6a58 | dword_7D6A58 | R | [LLM] |
| 007d6a5c | dword_7D6A5C | R | [LLM] |
| 007d6b74 | dword_7D6B74 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405480 | sub_405480 | [LLM] |
| 0040e4c0 | sub_40E4C0 | [LLM] |
| 0040efc0 | sub_40EFC0 | [LLM] |
| 00413700 | sub_413700 | [LLM] |
| 004cd5b0 | PathTruncationUtility [structural] | [LLM] |
| 004e2420 | LinkedListDestruction_f640 [structural] | [LLM] |
| 004e2570 | sub_4E2570 | [LLM] |
| 004e28f0 | VehicleArrayIndexAccessor [structural] | [LLM] |
| 004ed5c0 | sub_4ED5C0 | [LLM] |
| 004ed6e0 | sub_4ED6E0 | [LLM] |
| 004ed6f0 | sub_4ED6F0 | [LLM] |
| 004ed7b0 | sub_4ED7B0 | [LLM] |
| 00504470 | sub_504470 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00579060 | sub_579060 | [LLM] |
| 0057a6d0 | sub_57A6D0 | [LLM] |
| 0057a6e0 | LinkedListCount [exact] | [LLM] |
| 0057ac50 | AudioFileLoadDecode [structural] | [LLM] |
| 0057ae50 | sub_57AE50 | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005bec89 | _atoi | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `%s%s`
- `_createACar.skn`
- `career`
- `AND: NASCAR ClosedWheel 2003`
