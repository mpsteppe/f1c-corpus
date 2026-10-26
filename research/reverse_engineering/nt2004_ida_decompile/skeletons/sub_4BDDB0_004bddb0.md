## sub_4BDDB0_004bddb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BFD80 (004bfd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x4C | R | — | [LLM] |
| *(this+0xB8) | 0x50 | R | — | [LLM] |
| *(this+0xB8) | 0x54 | R | — | [LLM] |
| *(this+0xB8) | 0x58 | R | — | [LLM] |
| *(this+0xB8) | 0x5C | R | — | [LLM] |
| *(this+0xB8) | 0x60 | R | — | [LLM] |
| *(this+0xB8) | 0x64 | R | — | [LLM] |
| *(this+0xC4) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | 1 | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0060116c | aSSS_3 | R | [LLM] |
| 0060950c | aCmapsMas | R | [LLM] |
| 00609aec | aDDevNascar2004_12 | R | [LLM] |
| 00609f00 | aUnableToSetupA | R | [LLM] |
| 00609f24 | aCdbMas | R | [LLM] |
| 00609f2c | aPitsMas | R | [LLM] |
| 00628f60 | flt_628F60 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a068 | dword_62A068 | R | [LLM] |
| 0062a0b8 | dword_62A0B8 | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0075aacc | dword_75AACC | R | [LLM] |
| 007d7428 | byte_7D7428 | R | [LLM] |
| 007d7920 | dword_7D7920 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |
| 007da9b8 | dword_7DA9B8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404ed0 | sub_404ED0 | [LLM] |
| 0042dbc0 | sub_42DBC0 | [LLM] |
| 004be390 | sub_4BE390 | [LLM] |
| 004bea40 | sub_4BEA40 | [LLM] |
| 004bec30 | sub_4BEC30 | [LLM] |
| 004f8f10 | sub_4F8F10 | [LLM] |
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 00591c90 | sub_591C90 | [LLM] |
| 005924d0 | sub_5924D0 | [LLM] |
| 00592750 | sub_592750 | [LLM] |
| 00596220 | sub_596220 | [LLM] |
| 005974a0 | sub_5974A0 | [LLM] |
| 0059e050 | ThreeFieldSetterWithSubCall [structural] | [LLM] |
| 0059e0f0 | sub_59E0F0 | [LLM] |
| 0059ecc0 | FlagFieldBitManipulation [structural] | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s%s`
- `%s%s%s`
- `CMAPS.MAS`
- `D:\dev\NASCAR_2004\Source\pitcrew.cpp`
- `Unable to setup after pitcrew %s`
- `CDB.MAS`
- `PITS.MAS`
