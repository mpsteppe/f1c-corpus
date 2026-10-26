## SessionScoringUpdate_004643c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x1B770) | 0x0 | R | — | [LLM] |
| obj | 0x28 | RW | 0 | [LLM] |
| obj | 0x29 | R | — | [LLM] |
| obj | 0x37C | RW | — | [LLM] |
| obj | 0x384 | RW | — | [LLM] |
| obj | 0x388 | RW | — | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | R | — | [LLM] |
| obj | 0x1B770 | RW | — | [LLM] |
| obj | 0x1B774 | RW | — | [LLM] |
| obj | 0x1B778 | RW | 0 | [LLM] |
| obj | 0x1B77C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x28: [LLM: once/conditional? does external poke survive?]
- obj 0x37C: [LLM: once/conditional? does external poke survive?]
- obj 0x384: [LLM: once/conditional? does external poke survive?]
- obj 0x388: [LLM: once/conditional? does external poke survive?]
- obj 0x1B770: [LLM: once/conditional? does external poke survive?]
- obj 0x1B774: [LLM: once/conditional? does external poke survive?]
- obj 0x1B778: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c7e0 | CollisionContactBufferTimestepUpdate | [LLM] |
| 0045d4e0 | StringLengthCheckDispatch | [LLM] |
| 0045fc50 | NetCommPlayerSlotSync | [LLM] |
| 00460380 | ClientGridDisplayTimer | [LLM] |
| 00460470 | SendServerOKRequest | [LLM] |
| 00460cb0 | ClearPlayerSlots | [LLM] |
| 00460dd0 | CollisionContactIteration | [LLM] |
| 00460e90 | ServerOpenTrackSignal | [LLM] |
| 004612e0 | TrackOpeningProgressTimer | [LLM] |
| 00462370 | StructFieldReadAt0x3e14 | [LLM] |
| 00464740 | LinkedListNodeRemoval | [LLM] |
| 004a0490 | sub_4A0490 | [LLM] |
| 004a0d30 | GlobalStateSetter | [LLM] |
| 004a0db0 | sub_4A0DB0 | [LLM] |
| 004a0df0 | SessionStateDispatch | [LLM] |
| 0057a900 | SingleDelegationCall_a900 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x1B770 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
