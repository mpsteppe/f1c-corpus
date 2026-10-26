## sub_4CDA20_004cda20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** StringCopyFileCheckDispatch [structural] (004cd9c0), sub_4CEA30 (004cea30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x5744)+0x0) | 0x10 | R | — | [LLM] |
| *(this+0x5744) | 0x0 | R | — | [LLM] |
| this | 0x114 | RW | 1 | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x2568 | RW | 1 | [LLM] |
| this | 0x2570 | R | — | [LLM] |
| this | 0x2574 | R | — | [LLM] |
| this | 0x25EC | R | — | [LLM] |
| this | 0x3A14 | R | — | [LLM] |
| this | 0x3A98 | RW | 41 | [LLM] |
| this | 0x3AA0 | R | — | [LLM] |
| this | 0x3AA4 | R | — | [LLM] |
| this | 0x5744 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x114: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2568: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3A98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50d8 | GetFileAttributesA | R | [LLM] |
| 005fd340 | NumOfElements | W | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 006292d0 | byte_6292D0 | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0075cba8 | dword_75CBA8 | R | [LLM] |
| 0075e8f0 | dword_75E8F0 | R | [LLM] |
| 00762f00 | byte_762F00 | R | [LLM] |
| 00764d70 | dword_764D70 | R | [LLM] |
| 00767898 | flt_767898 | R | [LLM] |
| 007d6a30 | byte_7D6A30 | R | [LLM] |
| 007d6b78 | byte_7D6B78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419110 | sub_419110 | [LLM] |
| 0042dba0 | sub_42DBA0 | [LLM] |
| 0042dc40 | BuildActiveVehiclePointerArray [structural] | [LLM] |
| 00435c20 | AutoLoadEntryListLoader [structural] | [LLM] |
| 004634f0 | sub_4634F0 | [LLM] |
| 004bc410 | LinkedListWalker [structural] | [LLM] |
| 004cb410 | sub_4CB410 | [LLM] |
| 004cd760 | sub_4CD760 | [LLM] |
| 004ce0f0 | sub_4CE0F0 | [LLM] |
| 004e58f0 | sub_4E58F0 | [LLM] |
| 004e8d60 | sub_4E8D60 | [LLM] |
| 004efde0 | sub_4EFDE0 | [LLM] |
| 0057a080 | ZeroInitSmallStruct [exact] | [LLM] |
| 0057a0a0 | sub_57A0A0 | [LLM] |
| 0057a2f0 | AudioStreamOpen [structural] | [LLM] |
| 0057b040 | sub_57B040 | [LLM] |
| 0057b340 | sub_57B340 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x25EC | == | 5 | [LLM] |
| this | 0x3A98 | < | 41 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
