## CameraViewSystem_00408e20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x20)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x10) | 0x0 | R | — | [LLM] |
| *(this+0x10) | 0x40 | RW | — | [LLM] |
| *(this+0x10) | 0x44 | RW | — | [LLM] |
| *(this+0x14) | 0x0 | R | — | [LLM] |
| *(this+0x14) | 0x40 | RW | — | [LLM] |
| *(this+0x14) | 0x44 | RW | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x40 | RW | — | [LLM] |
| *(this+0x18) | 0x44 | RW | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x40 | RW | — | [LLM] |
| *(this+0x1C) | 0x44 | RW | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x24) | 0x40 | RW | — | [LLM] |
| *(this+0x24) | 0x44 | RW | — | [LLM] |
| *(this+0x28) | 0x40 | RW | — | [LLM] |
| *(this+0x28) | 0x44 | RW | — | [LLM] |
| *(this+0x2C) | 0x40 | RW | — | [LLM] |
| *(this+0x2C) | 0x44 | RW | — | [LLM] |
| *(this+0x30) | 0x40 | RW | — | [LLM] |
| *(this+0x30) | 0x44 | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x10) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x10) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x14) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x14) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x18) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x18) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x24) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x24) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x28) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x28) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x2C) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x2C) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x30) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x30) 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be888 | aSwingman | R | [LLM] |
| 005be894 | aCockpit_0 | R | [LLM] |
| 005be89c | aTvcockpit | R | [LLM] |
| 005be8a8 | aNosecam | R | [LLM] |
| 005be910 | aLocalcam | R | [LLM] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408870 | CameraPositionDefinitions | [LLM] |
| 00456080 | ShortComputation_6080 | [LLM] |
| 00456170 | F_3DSoundEmitter | [LLM] |
| 004562a0 | ShortComputation_62a0 | [LLM] |
| 004562f0 | sub_4562F0 | [LLM] |
| 00457000 | sub_457000 | [LLM] |
| 00542520 | DoubleFieldGetter | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 005881c0 | __alloca_probe | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
