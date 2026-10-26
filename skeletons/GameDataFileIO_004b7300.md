## GameDataFileIO_004b7300 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C0) | 0x8 | R | — | [LLM] |
| this | 0x6C0 | RW | 0 | [LLM] |
| this | 0x6C4 | RW | 0 | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | RW | 0 | [LLM] |
| this | 0x6E4 | R | — | [LLM] |
| this | 0x700 | RW | 2 | [LLM] |
| this | 0x704 | R | — | [LLM] |
| this | 0xD28 | RW | 0 | [LLM] |
| this | 0xF1C | RW | — | [LLM] |
| this | 0xF20 | RW | — | [LLM] |
| this | 0xF24 | RW | 0 | [LLM] |
| this | 0xF28 | RW | 0 | [LLM] |
| this | 0xF2C | RW | 0 | [LLM] |
| this | 0xF30 | R | — | [LLM] |
| this | 0xF78 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6CC: [LLM: once/conditional? does external poke survive?]
- this 0x700: [LLM: once/conditional? does external poke survive?]
- this 0xD28: [LLM: once/conditional? does external poke survive?]
- this 0xF1C: [LLM: once/conditional? does external poke survive?]
- this 0xF20: [LLM: once/conditional? does external poke survive?]
- this 0xF24: [LLM: once/conditional? does external poke survive?]
- this 0xF28: [LLM: once/conditional? does external poke survive?]
- this 0xF2C: [LLM: once/conditional? does external poke survive?]
- this 0xF78: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce608 | dword_7CE608 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b5e50 | sub_4B5E50 | [LLM] |
| 004b5f60 | LinkedBufferTransfer | [LLM] |
| 004b6c90 | ModelSceneFileLoader | [LLM] |
| 004b7500 | sub_4B7500 | [LLM] |
| 004b8010 | FileSettingExistenceCheck | [LLM] |
| 004b86e0 | AngleClampWrap | [LLM] |
| 004b9830 | sub_4B9830 | [LLM] |
| 004bb3d0 | NodeDataFree | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566940 | sub_566940 | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6E4 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
