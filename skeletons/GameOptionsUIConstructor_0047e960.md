## GameOptionsUIConstructor_0047e960 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0xF0 | RW | 18446744073709551615 | [LLM] |
| this | 0xF4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047eafc | jpt_47E9F7 | R | [LLM] |
| 0047eb10 | byte_47EB10 | R | [LLM] |
| 005a6c78 | off_5A6C78 | R | [LLM] |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] (also: ` — UI/text handle) |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] (also: ` — UI/text handle (near VehicleCount) |
| 005c32cc | aDisallowed | R | DisallowedString [DERIVED] |
| 005c6e58 | aSelectedSeason | R | [LLM] |
| 005c6e68 | aTimeScaled | R | [LLM] |
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] |
| 005c6fac | aX7 | R | [LLM] |
| 005c6fb0 | aX6 | R | [LLM] |
| 005c6fb4 | aX5 | R | [LLM] |
| 005c6fb8 | aX4 | R | [LLM] |
| 005c6fbc | aX3 | R | [LLM] |
| 005c6fc0 | aX2 | R | [LLM] |
| 005c70e0 | aAllowed | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00488b00 | ConstructorInitVTable | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
