## sub_5ACC30_005acc30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5ADC80 (005adc80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb918 | aRb | R | [LLM] |
| 005fcd58 | aSS_0 | R | [LLM] |
| 0061b780 | aIllegalMeshFil | R | [LLM] |
| 0061b79c | aCouldNotLocate_0 | R | [LLM] |
| 0061bc08 | aErrorLoadingMa | R | [LLM] |
| 0061bc2c | aErrorLoadingAn_2 | R | [LLM] |
| 0061bc4c | aAnm | R | [LLM] |
| 007e4ccc | byte_7E4CCC | R | [LLM] |
| 007e5d54 | dword_7E5D54 | R | [LLM] |
| 007e8d58 | dword_7E8D58 | R | [LLM] |
| 007e8e48 | ElementCount | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00591c60 | sub_591C60 | [LLM] |
| 005aceb0 | sub_5ACEB0 | [LLM] |
| 005af100 | sub_5AF100 | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005be9e2 | FileCloseWithLock [structural] | [LLM] |
| 005bea90 | _fopen | [LLM] |
| 005beec8 | _sprintf | [LLM] |
| 005c0803 | __strupr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s\%s`
- `Illegal mesh file name %s`
- `Could not locate mesh file %s`
- `Error loading animation file %s`
- `Error loading animation file %s`
- `ANM`
