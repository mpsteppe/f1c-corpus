## SynchronizeWithServer_00464290 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | RW | — | [LLM] |
| obj | 0x14 | RW | 1 | [LLM] |
| obj | 0x28 | RW | 1 | [LLM] |
| obj | 0x380 | RW | 0 | [LLM] |
| obj | 0x388 | RW | 0 | [LLM] |
| obj | 0x390 | RW | 1008981770 → 0.01f | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | R | — | [LLM] |
| obj | 0x1B790 | R | — | [LLM] |
| obj | 0x1B791 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x10: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x28: [LLM: once/conditional? does external poke survive?]
- obj 0x380: [LLM: once/conditional? does external poke survive?]
- obj 0x388: [LLM: once/conditional? does external poke survive?]
- obj 0x390: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0a0 | flt_59F0A0 | R | MulticastTimeout [DERIVED] |
| 0059f0b8 | flt_59F0B8 | R | NetSyncTimeout [DERIVED] (also: ` — float constants (timeout/default) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6634 | aEnteringSynchr | R | EnteringSyncString [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007d105c | byte_7D105C | R | NetworkSyncFlag [DERIVED] (also: ` — session flag) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c8b0 | ArrayInitializationLoop | [LLM] |
| 0045f390 | RunCollisionDetectionLoop | [LLM] |
| 00460c60 | ArrayInitWithSentinelInLoop | [LLM] |
| 00460cb0 | ClearPlayerSlots | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004fffa0 | ThunkWithStructInitSubCalls | [LLM] |
| 0057a570 | ByteFieldSetterAtOffset0x5d | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3FC4 | == | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
