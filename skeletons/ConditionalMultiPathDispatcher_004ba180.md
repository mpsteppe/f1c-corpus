## ConditionalMultiPathDispatcher_004ba180 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xF80 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0xF80: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b8bd0 | KeyPriorityChain | [LLM] |
| 004b8c40 | sub_4B8C40 | [LLM] |
| 004b9a00 | PackedFlagRead_9a00 | [LLM] |
| 004b9e40 | PitServiceSteeringAnimationStep | [LLM] |
| 004c8dc0 | GuardedVirtualCall | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
