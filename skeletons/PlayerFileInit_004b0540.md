## PlayerFileInit_004b0540 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCopyFileCheckDispatch (004b04e0), PlayerFile_Setup (004b1870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | RW | 1 | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1F00 | RW | — | [LLM] |
| this | 0x1F78 | R | — | [LLM] |
| this | 0x2ED8 | R | — | [LLM] |
| this | 0x2F08 | R | — | [LLM] |
| this | 0x2F8C | RW | 33 | [LLM] |

**Written-by note (persistence):**
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x1F00: [LLM: once/conditional? does external poke survive?]
- this 0x2F8C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d8 | GetFileAttributesA | R | [LLM] |
| 005c329c | dword_5C329C | W | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007cb710 | byte_7CB710 | R | EnvironmentFlags [DERIVED] (also: ` — Env flag (bit 0 = wet) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415730 | ShortComputation_5730 | [LLM] |
| 0042bc10 | ScoringGateCheck | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 00432e70 | AutoLoadEntryListLoader | [LLM] |
| 004a1d10 | LinkedListWalker | [LLM] |
| 004ae750 | sub_4AE750 | [LLM] |
| 004b0720 | F_5StepInit | [LLM] |
| 004b0ef0 | sub_4B0EF0 | [LLM] |
| 004c5690 | SceneDataParser | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00568620 | sub_568620 | [LLM] |
| 00568910 | sub_568910 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F00 | > | 0 | [LLM] |
| this | 0x1F78 | == | 5 | [LLM] |
| this | 0x2F8C | < | 34 | [LLM] |
| this | 0x2F8C | < | 33 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
