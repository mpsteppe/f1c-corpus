## MultiplayerPasswordValidation_0046dd30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x1C | R | — | [LLM] |
| *(this+0x40) | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xE4 | RW | 1082130432 → 4.0f | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6c58 | aClientPassword | R | ClientPassword [DERIVED] |
| 005c6c70 | aMultiClientPas | R | MultiClientPasswordEntryString [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd850 | byte_7CD850 | R | MultiClientPassword [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 004615f0 | BitFlagTestAt0x6E | [LLM] |
| 00462c00 | SendJoinRequest | [LLM] |
| 00489940 | FieldGetter | [LLM] |
| 00489950 | UIScreenTextAccessor_9950 | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 004988d0 | sub_4988D0 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
